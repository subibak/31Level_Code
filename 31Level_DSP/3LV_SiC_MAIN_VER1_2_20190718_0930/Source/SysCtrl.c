/*
 * SysCtrl.c
 *
 *  Created on: 2019. 6. 21.
 *      Author: HJHeo
 */

#include "Define_Header.h"
#include "Define_SysCtrl.h"

//**************************************** WatchDog ****************************************//
void DisableDog(void)
{
	EALLOW;

	// WatchDog Disable.
	WdRegs.WDCR.all = WDCR_WDDIS_WDDis									// 6	: WDDIS			; 0(Enable), 1(Disable).
					| WDCR_WDCHK_WDCheckSum								// 5-3	: WDCHK			; 101(Allowed CheckSum Value).
					| WDCR_WDPS_DIV512;									// 2-0	: WDPS			; 0, 1(/512), 2(/1024), 3(/2048), ..., 7(/32768).

	EDIS;

	return;
}

void InitStartDog(void)
{
	EALLOW;

	// WatchDog Mode Selection.
	WdRegs.SCSR.all = SCSR_WDENINT_WDResetMode;							// 1	: WDENINT		; 0(Reset Mode), 1(Interrupt Mode).

	// WatchDog Enable.
	WdRegs.WDCR.all = WDCR_WDDIS_WDEn									// 6	: WDDIS			; 0(Enable), 1(Disable).
					| WDCR_WDCHK_WDCheckSum								// 5-3	: WDCHK			; 101(Allowed CheckSum Value).
					| WDCR_WDPS_DIV512;									// 2-0	: WDPS			; 0, 1(/512), 2(/1024), 3(/2048), ..., 7(/32768).

	// WathDog Enable Lock.
	WdRegs.SCSR.all |= SCSR_WDOVERRIDE_WDDISEDIS;						// 0	: WDOVERRIDE	; 1(Clear WDOVERRIDE, WDDIS Change Disable).

	EDIS;

	return;
}

void ResetDog(void)
{
	EALLOW;

	// Reset Key for WatchDog.
	WdRegs.WDKEY.all = 0x0055;
	WdRegs.WDKEY.all = 0x00AA;

	EDIS;

	return;
}

#ifdef CPU1
//**************************************** PLL ****************************************//
void Init_PLL(Uint16 host)
{
	// Clock Heritage( = : Same, - : Divided or Multiplied from Source)
	// OSCCLK - PLLRAWCLK - PLLSYSCLK = CPUx.CPUCLK
	//								  = CPUx.SYSCLK
	//								  = PERx.SYSCLK - EMIF2CLK
	//												- PWMxCLK
	//								  - LSPCLK		= PERx.LSPCLK
	//								  - EMIF1CLK

	Uint16 ui_temp;

	EALLOW;

	// PLL Host Define.
	ClkCfgRegs.CLKSEM.all = CLKSEM_KEY_MatchedKey						// 31-16: KEY			; 0xA5A5(Valid Key)
						| (Uint32)host;									// 1-0	: SEM			; 0, 3(Unfixed Host CPU1), 1(Fixed Host CPU2), 2(Fixed Host CPU1)

	// PLL Clock Source On.
	ClkCfgRegs.CLKSRCCTL1.all = CLKSRCCTL1_WDHALTI_CPU1WDStopInHALTMode	// 5	: WDHALTI		; 0(CPU1.WD Disabled in HALT Mode), 1(CPU1.WD Enabled in HALT Mode).
							| CLKSRCCTL1_XTALOFF_EXTOSCEn				// 4	: XTALOFF		; 0(EXTOSC On), 1(EXTOSC Off).
							| CLKSRCCTL1_INTOSC2OFF_INTOSC2En			// 3	: INTOSC2OFF	; 0(INTOSC2 On), 1(INTOSC2 Off).
							| CLKSRCCTL1_OSCCLKSRCSEL_EXTOSC;			// 1-0	: OSCCLKSRCSEL	; 0(INTOSC2), 1(EXTOSC), 2(INTOSC1).
	asm(" RPT #255 || NOP");

	// Unused Clock Source Off.
	ClkCfgRegs.CLKSRCCTL1.all |= CLKSRCCTL1_INTOSC2OFF_INTOSC2Dis;		// 3    : INTOSC2OFF    ; 0(INTOSC2 On), 1(INTOSC2 Off).

	// PLL Stop for Setting.
	//// PLL Stop for Setting : PLL Bypassed.
	ClkCfgRegs.SYSPLLCTL1.bit.PLLCLKEN = PLLCLKEN_PLLBypassed;			// 		: PLLCLKEN		; 0(PLL Bypassed), 1(PLL Used).
	asm(" RPT #255 || NOP");

	//// PLL Stop for Setting : Fastest Clock for Fast PLL Setting.
	ClkCfgRegs.SYSCLKDIVSEL.bit.PLLSYSCLKDIV = 0;						//		: PLLSYSCLKDIV	; 0(/1), 1(/2), 2(/4), ..., 63(/126).

	// PLL Setting and Lock(To Ensure a Successful PLL Start, Lock the PLL at Least Five Times.
	for(ui_temp = 0; ui_temp < 5; ui_temp++)
	{
		ClkCfgRegs.SYSPLLCTL1.bit.PLLEN = PLLEN_PLLDis;					//		: PLLEN			; 0(PLL Disabled), 1(PLL Enabled).
		asm(" RPT #255 || NOP");

		ClkCfgRegs.SYSPLLMULT.all = SYSPLLMULT_FMULT_0P00				// 9-8	: FMULT			; 0(0.00), 1(0.25), 2(0.50), 3(0.75)
								| SYSPLLMULT_IMULT_MULT(20);			// 6-0	: IMULT			; 0(1), 1(2), 2(3), ..., 126(127)
																		// PLLRAWCLK = OSCCLK x (IMULT + (FMULT x 0.25)), !!!!! 120[MHz] ~ 400[MHz] !!!!!
																		// 400[MHz] = 20[MHz] x (20 + (0 x 0.25))
		while (ClkCfgRegs.SYSPLLSTS.bit.LOCKS != 1);
	}

	// Temporary PLL Divider Setting									// Prevent for Current Increasing by Switching to PLL.
	ClkCfgRegs.SYSCLKDIVSEL.bit.PLLSYSCLKDIV = 2;						// 		: PLLSYSCLK		; 0(/1), 1(/2), 2(/4), ..., 63(/126).

	// PLL Start-Up
	DevCfgRegs.SYSDBGCTL.all = SYSDBGCTL_BIT_0_PLLStart;				// 0	: BIT_0			; 0(PLL Normal), 1(PLL Startup).

	while (ClkCfgRegs.X1CNT.bit.X1CNT < 0x3FF);							//		: X1CNT			; X1 Counter. Saturated with 0x3FF Value.
	ClkCfgRegs.SYSPLLCTL1.bit.PLLCLKEN = PLLCLKEN_PLLUsed;				// 		: PLLCLKEN		; 0(PLL Bypassed), 1(PLL Used).
	asm(" RPT #255 || NOP");

	DevCfgRegs.SYSDBGCTL.all = SYSDBGCTL_BIT_0_PLLNormal;				// 0	: BIT_0			; 0(PLL Normal), 1(PLL Startup).

	// PLL Divider Setting
	ClkCfgRegs.SYSCLKDIVSEL.bit.PLLSYSCLKDIV = 1;						// 		: PLLSYSCLK		; 0(/1), 1(/2), 2(/4), ..., 63(/126).
																		// PLLSYSCLK = PLLRAWCLK / 2 / PLLSYSDIV, !!!!! 2[MHz] ~ 200[MHz] !!!!!
																		// 200[MHz] = 400[MHz] / 2 / 1.

	EDIS;

	return;
}

//**************************************** Host Define ****************************************//
void Init_CPUHost(void)
{
	EALLOW;

	// EPWM Modules Host CPU Define.
	DevCfgRegs.CPUSEL0.all = CPUSEL0_EPWM1_CPU1Host						// CPU1		; CPU1 Interrupt Generator.
							| CPUSEL0_EPWM2_CPU1Host					//
							| CPUSEL0_EPWM3_CPU1Host					//
							| CPUSEL0_EPWM4_CPU2Host					//		CPU2; CPU2 Interrupt Generator.
							| CPUSEL0_EPWM5_CPU1Host					//
							| CPUSEL0_EPWM6_CPU1Host					//
							| CPUSEL0_EPWM7_CPU1Host					//
							| CPUSEL0_EPWM8_CPU1Host					//
							| CPUSEL0_EPWM9_CPU1Host					//
							| CPUSEL0_EPWM10_CPU1Host					//
							| CPUSEL0_EPWM11_CPU1Host					//
							| CPUSEL0_EPWM12_CPU1Host;					//

	// ECAP Modules Host CPU Define.
	DevCfgRegs.CPUSEL1.all = CPUSEL1_ECAP1_CPU1Host						//
							| CPUSEL1_ECAP2_CPU1Host					//
							| CPUSEL1_ECAP3_CPU1Host					//
							| CPUSEL1_ECAP4_CPU1Host					//
							| CPUSEL1_ECAP5_CPU1Host					//
							| CPUSEL1_ECAP6_CPU1Host;					//

	// EQEP Modules Host CPU Define.
	DevCfgRegs.CPUSEL2.all = CPUSEL2_EQEP1_CPU1Host						//
							| CPUSEL2_EQEP2_CPU1Host					//
							| CPUSEL2_EQEP3_CPU1Host;					//

	// SD Modules Host CPU Define.
	DevCfgRegs.CPUSEL4.all = CPUSEL4_SD1_CPU1Host						//
							| CPUSEL4_SD2_CPU1Host;						//

	// SCI Modules Host CPU Define.
	DevCfgRegs.CPUSEL5.all = CPUSEL5_SCI_A_CPU1Host						//
							| CPUSEL5_SCI_B_CPU1Host					//
							| CPUSEL5_SCI_C_CPU1Host					//
							| CPUSEL5_SCI_D_CPU1Host;					//

	// SPI Modules Host CPU Define.
	DevCfgRegs.CPUSEL6.all = CPUSEL6_SPI_A_CPU1Host						//
							| CPUSEL6_SPI_B_CPU1Host					//
							| CPUSEL6_SPI_C_CPU1Host;					//

	// I2C Modules Host CPU Define.
	DevCfgRegs.CPUSEL7.all = CPUSEL7_I2C_A_CPU1Host						//
							| CPUSEL7_I2C_B_CPU1Host;					//

	// CAN Modules Host CPU Define.
	DevCfgRegs.CPUSEL8.all = CPUSEL8_CAN_A_CPU1Host						//
							| CPUSEL8_CAN_B_CPU1Host;					//

	// McBSP Modules Host CPU Define.
	DevCfgRegs.CPUSEL9.all = CPUSEL9_McBSP_A_CPU1Host					//
							| CPUSEL9_McBSP_B_CPU1Host;					//

	// ADC Configuration Register Host CPU Define.
	DevCfgRegs.CPUSEL11.all = CPUSEL11_ADC_A_CFGREG_CPU1Host			//
							| CPUSEL11_ADC_B_CFGREG_CPU1Host			//
							| CPUSEL11_ADC_C_CFGREG_CPU1Host			//
							| CPUSEL11_ADC_D_CFGREG_CPU1Host;			//

	// CMPSS Modules Host CPU Define.
	DevCfgRegs.CPUSEL12.all = CPUSEL12_CMPSS1_CPU1Host					//
							| CPUSEL12_CMPSS2_CPU1Host					//
							| CPUSEL12_CMPSS3_CPU1Host					//
							| CPUSEL12_CMPSS4_CPU1Host					//
							| CPUSEL12_CMPSS5_CPU1Host					//
							| CPUSEL12_CMPSS6_CPU1Host					//
							| CPUSEL12_CMPSS7_CPU1Host					//
							| CPUSEL12_CMPSS8_CPU1Host;					//

	// DAC Modules Host CPU Define.
	DevCfgRegs.CPUSEL14.all = CPUSEL14_DAC_A_CPU1Host					//
							| CPUSEL14_DAC_B_CPU1Host					//
							| CPUSEL14_DAC_C_CPU1Host;					//

	DevCfgRegs.DEVCFGLOCK1.all = DEVCFGLOCK1_CPUSEL_AllLock;			// 14-0	: CPUSELx		; CPUSELx Registers are Locked.

	EDIS;

	return;
}
#endif

//**************************************** Peripheral Clock ****************************************//
void Init_PeripheralClocks(void)
{
	// Clock Heritage( = : Same, - : Divided or Multiplied from Source)
	// OSCCLK - PLLRAWCLK - PLLSYSCLK = CPUx.CPUCLK
	//								  = CPUx.SYSCLK
	//								  = PERx.SYSCLK - EMIF2CLK
	//												- PWMxCLK
	//								  - LSPCLK		= PERx.LSPCLK
	//								  - EMIF1CLK

	EALLOW;

#ifdef CPU1
	// Clock Speed Setting
	//// Clock Speed Setting : Low Speed Clock
	ClkCfgRegs.LOSPCP.all = LOSPCP_LSPCLKDIV_DIV2;						// 2-0	: LSPCLKDIV		; 0(/1), 1(/2), 2(/4), ..., 7(/14).
																		// LSPCLK = PLLSYSCLK / 2 / LSPCLKDIV. 		!!!!! 2[MHz] ~ 200[MHz] !!!!!
																		// 100[MHz] = 200[MHz] / 2 / 1
	//// Clock Speed Setting : Peripheral Clock
	ClkCfgRegs.PERCLKDIVSEL.all = PERCLKDIVSEL_EMIF2CLKDIV_DIV2			// 6	: EMIF2CLKDIV	; 0(/1), 1(/2).
																		// EMIF2CLK = PERx.SYSCLK / (EMIF2CLKDIV + 1)
																		// 100[MHz] = 200[MHz] / (1 + 1)
								| PERCLKDIVSEL_EMIF1CLKDIV_DIV2			// 4	: EMIF1CLKDIV	; 0(/1), 1(/2).
																		// EMIF1CLK = PLLSYSCLK / (EMIF1CLKDIV + 1)
																		// 100[MHz] = 200[MHz] / (1 + 1)
								| PERCLKDIVSEL_EPWMCLKDIV_DIV2;			// 1-0	: EPWMCLKDIV	; 0(/1), 1(/2).
																		// EPWMCLK = PLLSYSCLK / (EPWMCLKDIV + 1). 	!!!!!         ~ 100[MHz] !!!!!
																		// HRPWMCLK = EPWMCLK.					   	!!!!! 60[MHz] ~ 100[MHz] !!!!!
																		// 100[MHz] = 200[MHz] / 2 / 1
	//// Clock Speed Setting : CAN & AUXOSCCLK
	ClkCfgRegs.CLKSRCCTL2.all = CLKSRCCTL2_CANBBCLKSEL_PERxSYSCLK		// 5-4	: CANBBCLKSEL	; 0(PERx.SYSCLK), 1(XTAL), 2(AUXCLKIN)
								| CLKSRCCTL2_CANABCLKSEL_PERxSYSCLK		// 3-2	: CANABCLKSEL	; 0(PERx.SYSCLK), 1(XTAL), 2(AUXCLKIN)
								| CLKSRCCTL2_AUXOSCCLKSRCSEL_INTOSC2;	// 1-0	: AUXSOCCLKSRCSEL; 0(INTSOC2), 1(XTAL), 2(AUXCLKIN)

	//// Clock Speed Setting : XCLKOUT Clock
	ClkCfgRegs.CLKSRCCTL3.all = CLKSRCCTL3_XCLKOUTSEL_PLLSYSCLK;		// 2-0	: XCLKOUTSEL	; 0(PLLSYSCLK), 1(PLLRAWCLK), 2(CPU1.SYSCLK), 3(CPU2.SYSCLK), 4(AUXPLLRAWCLK), 5 (INTOSC1), 6(INTOSC2).
	ClkCfgRegs.XCLKOUTDIVSEL.all = XCLKOUTDIVSEL_XCLKOUTDIV_DIV4;		// 1-0	: XCLKOUTDIV	; 0(/1), 1(/2), 2(/4), 3(/8).																		// XCLKOUT = XCLKOUTSRC / 2 / XCLKOUTDIV. 	!!!!!          ~ 50[MHz]  !!!!!
#endif

	// Peripheral Clock Enable.
	CpuSysRegs.PCLKCR0.all = PCLKCR0_CPUTIME2_CLKDis					// 5	: CPUx	;
							| PCLKCR0_CPUTIME1_CLKDis					// 4	: CPUx	;
							| PCLKCR0_CPUTIME0_CLKDis					// 3	: CPUx	;
							| PCLKCR0_DMA_CLKDis						// 2	: CPUx	;
							| PCLKCR0_CLA1_CLKDis						// 0	: CPUx	;
							| PCLKCR0_TBCLKSYNC_PWMCPUCLKDis;			// 18	: CPUx	; Disable for TBCLK Synchronization of PWM Modules associated with Each CPU.
#ifdef CPU1
	CpuSysRegs.PCLKCR0.all |= PCLKCR0_GTBCLKSYNC_PWMGlobalCLKDis		// 19	: CPU1	; Disable for TBCLK Synchronization of All PWM Modules.
							| PCLKCR0_HRPWM_CLKDis;						// 16	: CPU1	;

	CpuSysRegs.PCLKCR1.all = PCLKCR1_EMIF2_CLKDis						// 1	: CPU1	;
							| PCLKCR1_EMIF1_CLKEn;						// 0	: CPU1	; FPGA Communication.
#endif

	CpuSysRegs.PCLKCR2.all = PCLKCR2_EPWM1_CLKEn						// 0	: A CPU	; CPU1 Interrupt Generation.
							| PCLKCR2_EPWM2_CLKDis						// 1	: A CPU	;
							| PCLKCR2_EPWM3_CLKDis						// 2	: A CPU	;
							| PCLKCR2_EPWM4_CLKEn						// 3	: A CPU	; CPU2 Interrupt Generation.
							| PCLKCR2_EPWM5_CLKDis						// 4	: A CPU	;
							| PCLKCR2_EPWM6_CLKDis						// 5	: A CPU	;
							| PCLKCR2_EPWM7_CLKDis						// 6	: A CPU	;
							| PCLKCR2_EPWM8_CLKDis						// 7	: A CPU	;
							| PCLKCR2_EPWM9_CLKDis						// 8	: A CPU ;
							| PCLKCR2_EPWM10_CLKDis						// 9	: A CPU	;
							| PCLKCR2_EPWM11_CLKDis						// 10	: A CPU	;
							| PCLKCR2_EPWM12_CLKDis;					// 11	: A CPU	;

	CpuSysRegs.PCLKCR3.all = PCLKCR3_ECAP1_CLKDis						// 0	: A CPU	;
							| PCLKCR3_ECAP2_CLKDis						// 1	: A CPU	;
							| PCLKCR3_ECAP3_CLKDis						// 2	: A CPU	;
							| PCLKCR3_ECAP4_CLKDis						// 3	: A CPU	;
							| PCLKCR3_ECAP5_CLKDis						// 4	: A CPU	;
							| PCLKCR3_ECAP6_CLKDis;						// 5	: A CPU	;

	CpuSysRegs.PCLKCR4.all = PCLKCR4_EQEP1_CLKDis						// 0	: A CPU	;
							| PCLKCR4_EQEP2_CLKDis						// 1	: A CPU	;
							| PCLKCR4_EQEP3_CLKDis;						// 2	: A CPU	;

	CpuSysRegs.PCLKCR6.all = PCLKCR6_SD1_CLKDis							// 0	: A CPU ;
							| PCLKCR6_SD2_CLKDis;						// 1	: A CPU	;

	CpuSysRegs.PCLKCR7.all = PCLKCR7_SCI_A_CLKDis						// 0	: A CPU	;
							| PCLKCR7_SCI_B_CLKDis						// 1	: A CPU	;
							| PCLKCR7_SCI_C_CLKDis						// 2	: A CPU	;
							| PCLKCR7_SCI_D_CLKDis;						// 3	: A CPU	;

	CpuSysRegs.PCLKCR8.all = PCLKCR8_SPI_A_CLKDis						// 0	: A CPU	;
							| PCLKCR8_SPI_B_CLKDis						// 1	: A CPU	;
							| PCLKCR8_SPI_C_CLKDis;						// 2	: A CPU	;

	CpuSysRegs.PCLKCR9.all = PCLKCR9_I2C_A_CLKDis						// 0	: A CPU	;
							| PCLKCR9_I2C_A_CLKDis;						// 1	: A CPU	;

	CpuSysRegs.PCLKCR10.all = PCLKCR9_I2C_A_CLKDis						// 0	: A CPU	;
							| PCLKCR10_CAN_B_CLKDis;					// 1	: A CPU	;

	CpuSysRegs.PCLKCR11.all =  PCLKCR11_McBSP_A_CLKDis					// 0	: A CPU	;
							| PCLKCR11_McBSP_B_CLKDis;					// 1	: A CPU ;
#ifdef CPU1
	CpuSysRegs.PCLKCR11.all |= PCLKCR11_USB_A_CLKDis;					// 16	: CPU1	;

	CpuSysRegs.PCLKCR12.all = PCLKCR12_UPP_A_CLKDis;					// 0	: CPU1	;
#endif

	CpuSysRegs.PCLKCR13.all = PCLKCR13_ADC_A_CLKDis						// 0	: A CPU	;
							| PCLKCR13_ADC_B_CLKDis						// 1	: A CPU	;
							| PCLKCR13_ADC_C_CLKDis						// 2	: A CPU	;
							| PCLKCR13_ADC_D_CLKDis;					// 3	: A CPU	;

	CpuSysRegs.PCLKCR14.all = PCLKCR14_CMPSS1_CLKDis					// 0	: A CPU	;
							| PCLKCR14_CMPSS2_CLKDis					// 1	: A CPU	;
							| PCLKCR14_CMPSS3_CLKDis					// 2	: A CPU	;
							| PCLKCR14_CMPSS4_CLKDis					// 3	: A CPU	;
							| PCLKCR14_CMPSS5_CLKDis					// 4	: A CPU	;
							| PCLKCR14_CMPSS6_CLKDis					// 5	: A CPU	;
							| PCLKCR14_CMPSS7_CLKDis					// 6	: A CPU	;
							| PCLKCR14_CMPSS8_CLKDis;					// 7	: A CPU	;

	CpuSysRegs.PCLKCR16.all = PCLKCR16_DAC_A_CLKDis						// 16	: A CPU	;
							| PCLKCR16_DAC_A_CLKDis						// 17	: A CPU	;
							| PCLKCR16_DAC_A_CLKDis;					// 18	: A CPU	;

	EDIS;

	return;
}
