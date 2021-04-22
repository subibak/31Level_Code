/*
 * SysCtrl.c
 *
 *  Created on: 2015. 8. 12.
 *      Author: cjs9426
 */


#include "Define_Header.h"

#ifdef CPU1
void Init_PLL(void)
{
	EALLOW;
	// PLL HOST
    ClkCfgRegs.CLKSEM.bit.KEY = 0xA5A5;
    ClkCfgRegs.CLKSEM.bit.SEM = 2;

	// Select clock source
	if(ClkCfgRegs.CLKSRCCTL1.bit.OSCCLKSRCSEL != 1)
	{
		ClkCfgRegs.CLKSRCCTL1.bit.XTALOFF = 0;
		ClkCfgRegs.CLKSRCCTL1.bit.OSCCLKSRCSEL = 1;			// Xtal
	}

	// Set multiplier
	if(ClkCfgRegs.SYSPLLMULT.bit.FMULT != 0 || ClkCfgRegs.SYSPLLMULT.bit.IMULT != 20)
	{
		ClkCfgRegs.SYSCLKDIVSEL.bit.PLLSYSCLKDIV = 63;			// Maximum value of system clock divider to reduce in-rush current

		ClkCfgRegs.SYSPLLMULT.bit.FMULT = 0;
		ClkCfgRegs.SYSPLLMULT.bit.IMULT = 20;					// Set multiplier

		while(ClkCfgRegs.SYSPLLSTS.bit.LOCKS != 1){
		}

		ClkCfgRegs.SYSPLLMULT.bit.FMULT = 0;
		ClkCfgRegs.SYSPLLMULT.bit.IMULT = 20;					// Set multiplier

		while(ClkCfgRegs.SYSPLLSTS.bit.LOCKS != 1){
		}
	}

    // PLL Start-Up
//	DevCfgRegs.SYSDBGCTL.all = 0x00000001;                              // 0    : BIT_0         ; 0(PLL Normal), 1(PLL Startup)

	// PLL clock enable
	ClkCfgRegs.SYSPLLCTL1.bit.PLLCLKEN = 1;

	// Change PLLSYSCLKDIV
	if(ClkCfgRegs.SYSCLKDIVSEL.bit.PLLSYSCLKDIV != 1)
	{
		ClkCfgRegs.SYSCLKDIVSEL.bit.PLLSYSCLKDIV = 40;
		DELAY_US(15);
		ClkCfgRegs.SYSCLKDIVSEL.bit.PLLSYSCLKDIV = 20;
		DELAY_US(15);
//		DevCfgRegs.SYSDBGCTL.all = 0;                              // 0    : BIT_0         ; 0(PLL Normal), 1(PLL Startup)
		ClkCfgRegs.SYSCLKDIVSEL.bit.PLLSYSCLKDIV = 1;
		DELAY_US(15);
	}

	EDIS;

	return;
}
#endif

void Init_PeripheralClocks(void)
{
    EALLOW;

    // Low Speed Clock
    ClkCfgRegs.LOSPCP.all = 0x0000;

    // Peripheral Clocks Enable         0 : Disable     1 : Enable
    //CLA
    CpuSysRegs.PCLKCR0.bit.CLA1 = 1;

    //DMA
    CpuSysRegs.PCLKCR0.bit.DMA = 1;

    //CPU timer
    CpuSysRegs.PCLKCR0.bit.CPUTIMER0 = 1;
    CpuSysRegs.PCLKCR0.bit.CPUTIMER1 = 0;
    CpuSysRegs.PCLKCR0.bit.CPUTIMER2 = 0;

    //External memory interface
    CpuSysRegs.PCLKCR1.bit.EMIF1 = 1;
    CpuSysRegs.PCLKCR1.bit.EMIF2 = 1;

    //ePWM
    CpuSysRegs.PCLKCR0.bit.HRPWM = 0;
    CpuSysRegs.PCLKCR0.bit.GTBCLKSYNC = 0;
    CpuSysRegs.PCLKCR0.bit.TBCLKSYNC = 0;
    CpuSysRegs.PCLKCR2.bit.EPWM1 = 0;
    CpuSysRegs.PCLKCR2.bit.EPWM2 = 0;
    CpuSysRegs.PCLKCR2.bit.EPWM3 = 0;
    CpuSysRegs.PCLKCR2.bit.EPWM4 = 0;
    CpuSysRegs.PCLKCR2.bit.EPWM5 = 0;
    CpuSysRegs.PCLKCR2.bit.EPWM6 = 0;
    CpuSysRegs.PCLKCR2.bit.EPWM7 = 0;
    CpuSysRegs.PCLKCR2.bit.EPWM8 = 0;
    CpuSysRegs.PCLKCR2.bit.EPWM9 = 0;
    CpuSysRegs.PCLKCR2.bit.EPWM10 = 0;
    CpuSysRegs.PCLKCR2.bit.EPWM11 = 0;
    CpuSysRegs.PCLKCR2.bit.EPWM12 = 0;

    //eCAP
    CpuSysRegs.PCLKCR3.bit.ECAP1 = 0;
    CpuSysRegs.PCLKCR3.bit.ECAP2 = 0;
    CpuSysRegs.PCLKCR3.bit.ECAP3 = 0;
    CpuSysRegs.PCLKCR3.bit.ECAP4 = 0;
    CpuSysRegs.PCLKCR3.bit.ECAP5 = 0;
    CpuSysRegs.PCLKCR3.bit.ECAP6 = 0;

    //eQEP
    CpuSysRegs.PCLKCR4.bit.EQEP1 = 0;
    CpuSysRegs.PCLKCR4.bit.EQEP2 = 0;
    CpuSysRegs.PCLKCR4.bit.EQEP3 = 0;

    //Sigma-Delta filter
    CpuSysRegs.PCLKCR6.bit.SD1 = 0;
    CpuSysRegs.PCLKCR6.bit.SD2 = 0;

    //SCI
    CpuSysRegs.PCLKCR7.bit.SCI_A = 0;
    CpuSysRegs.PCLKCR7.bit.SCI_B = 0;
    CpuSysRegs.PCLKCR7.bit.SCI_C = 0;
    CpuSysRegs.PCLKCR7.bit.SCI_D = 0;

    //SPI
    CpuSysRegs.PCLKCR8.bit.SPI_A = 0;
    CpuSysRegs.PCLKCR8.bit.SPI_B = 0;
    CpuSysRegs.PCLKCR8.bit.SPI_C = 0;

    //I2C
    CpuSysRegs.PCLKCR9.bit.I2C_A = 0;
    CpuSysRegs.PCLKCR9.bit.I2C_B = 0;

    //CAN
    CpuSysRegs.PCLKCR10.bit.CAN_A = 0;
    CpuSysRegs.PCLKCR10.bit.CAN_B = 0;

    //McBSP
    CpuSysRegs.PCLKCR11.bit.McBSP_A = 0;
    CpuSysRegs.PCLKCR11.bit.McBSP_B = 0;

    //Universal Parallel Port
    CpuSysRegs.PCLKCR11.bit.USB_A = 0;
    CpuSysRegs.PCLKCR12.bit.uPP_A = 0;

    //ADC
    CpuSysRegs.PCLKCR13.bit.ADC_A = 0;
    CpuSysRegs.PCLKCR13.bit.ADC_B = 0;
    CpuSysRegs.PCLKCR13.bit.ADC_C = 0;
    CpuSysRegs.PCLKCR13.bit.ADC_D = 0;

    //Comparator
    CpuSysRegs.PCLKCR14.bit.CMPSS1 = 0;
    CpuSysRegs.PCLKCR14.bit.CMPSS2 = 0;
    CpuSysRegs.PCLKCR14.bit.CMPSS3 = 0;
    CpuSysRegs.PCLKCR14.bit.CMPSS4 = 0;
    CpuSysRegs.PCLKCR14.bit.CMPSS5 = 0;
    CpuSysRegs.PCLKCR14.bit.CMPSS6 = 0;
    CpuSysRegs.PCLKCR14.bit.CMPSS7 = 0;
    CpuSysRegs.PCLKCR14.bit.CMPSS8 = 0;

    //DAC
    CpuSysRegs.PCLKCR16.bit.DAC_A = 0;
    CpuSysRegs.PCLKCR16.bit.DAC_B = 0;
    CpuSysRegs.PCLKCR16.bit.DAC_C = 0;

    EDIS;

    return;
}

void Init_PieCtrl(void)
{
	 // Disable Interrupts at the CPU level:
    DINT;

    // Disable the PIE
    PieCtrlRegs.PIECTRL.bit.ENPIE = 0;

	// Clear all PIEIER registers:
	PieCtrlRegs.PIEIER1.all = 0;
	PieCtrlRegs.PIEIER2.all = 0;
	PieCtrlRegs.PIEIER3.all = 0;
	PieCtrlRegs.PIEIER4.all = 0;
	PieCtrlRegs.PIEIER5.all = 0;
	PieCtrlRegs.PIEIER6.all = 0;
	PieCtrlRegs.PIEIER7.all = 0;
	PieCtrlRegs.PIEIER8.all = 0;
	PieCtrlRegs.PIEIER9.all = 0;
	PieCtrlRegs.PIEIER10.all = 0;
	PieCtrlRegs.PIEIER11.all = 0;
	PieCtrlRegs.PIEIER12.all = 0;

	// Clear all PIEIFR registers:
	PieCtrlRegs.PIEIFR1.all = 0;
	PieCtrlRegs.PIEIFR2.all = 0;
	PieCtrlRegs.PIEIFR3.all = 0;
	PieCtrlRegs.PIEIFR4.all = 0;
	PieCtrlRegs.PIEIFR5.all = 0;
	PieCtrlRegs.PIEIFR6.all = 0;
	PieCtrlRegs.PIEIFR7.all = 0;
	PieCtrlRegs.PIEIFR8.all = 0;
	PieCtrlRegs.PIEIFR9.all = 0;
	PieCtrlRegs.PIEIFR10.all = 0;
	PieCtrlRegs.PIEIFR11.all = 0;
	PieCtrlRegs.PIEIFR12.all = 0;

	// Clear all IER Register.
	IER = 0x0000;
    asm(" RPT #10 || NOP");                             // Wait 5 Cycles to Make Sure that Interrupt Reached the CPU IFR Register..


	// Clear all IFR Register.
	IFR = 0x0000;

	return;
}

void Init_PieVectTable(void)
{
	EALLOW;

	PieVectTable.PIE1_RESERVED_INT = &ISR_Default;
	PieVectTable.PIE2_RESERVED_INT = &ISR_Default;
	PieVectTable.PIE3_RESERVED_INT = &ISR_Default;
	PieVectTable.PIE4_RESERVED_INT = &ISR_Default;
	PieVectTable.PIE5_RESERVED_INT = &ISR_Default;
	PieVectTable.PIE6_RESERVED_INT = &ISR_Default;
	PieVectTable.PIE7_RESERVED_INT = &ISR_Default;
	PieVectTable.PIE8_RESERVED_INT = &ISR_Default;
	PieVectTable.PIE9_RESERVED_INT = &ISR_Default;
	PieVectTable.PIE10_RESERVED_INT = &ISR_Default;
	PieVectTable.PIE11_RESERVED_INT = &ISR_Default;
	PieVectTable.PIE12_RESERVED_INT = &ISR_Default;
	PieVectTable.PIE13_RESERVED_INT = &ISR_Default;

	PieVectTable.TIMER1_INT = &ISR_Default;						// CPU Timer 1 Interrupt
	PieVectTable.TIMER2_INT = &ISR_Default;						// CPU Timer 2 Interrupt
	PieVectTable.DATALOG_INT = &ISR_Default;					// Data logging Interrupt
	PieVectTable.RTOS_INT = &ISR_Default;						// RTOS Interrupt
	PieVectTable.EMU_INT = &ISR_Default;						// Emulation Interrupt
	PieVectTable.NMI_INT = &ISR_Default;						// Non-Maskable Interrupt
	PieVectTable.ILLEGAL_INT = &ISR_Default;					// Illegal Operation Trap
	PieVectTable.USER1_INT = &ISR_Default;						// User Defined Trap 1
	PieVectTable.USER2_INT = &ISR_Default;						// User Defined Trap 2
	PieVectTable.USER3_INT = &ISR_Default;						// User Defined Trap 3
	PieVectTable.USER4_INT = &ISR_Default;						// User Defined Trap 4
	PieVectTable.USER5_INT = &ISR_Default;						// User Defined Trap 5
	PieVectTable.USER6_INT = &ISR_Default;						// User Defined Trap 6
	PieVectTable.USER7_INT = &ISR_Default;						// User Defined Trap 7
	PieVectTable.USER8_INT = &ISR_Default;						// User Defined Trap 8
	PieVectTable.USER9_INT = &ISR_Default;						// User Defined Trap 9
	PieVectTable.USER10_INT = &ISR_Default;						// User Defined Trap 10
	PieVectTable.USER11_INT = &ISR_Default;						// User Defined Trap 11
	PieVectTable.USER12_INT = &ISR_Default;						// User Defined Trap 12

	PieVectTable.ADCA1_INT = &ISR_Default;						// 1.1 - ADCA Interrupt 1
	PieVectTable.ADCB1_INT = &ISR_Default;						// 1.2 - ADCB Interrupt 1
	PieVectTable.ADCC1_INT = &ISR_Default;						// 1.3 - ADCC Interrupt 1
	PieVectTable.XINT1_INT = &ISR_Default;						// 1.4 - XINT1 Interrupt
	PieVectTable.XINT2_INT = &ISR_Default;						// 1.5 - XINT2 Interrupt
	PieVectTable.ADCD1_INT = &ISR_Default;						// 1.6 - ADCD Interrupt 1
	PieVectTable.TIMER0_INT = &ISR_Default;						// 1.7 - Timer 0 Interrupt
	PieVectTable.WAKE_INT = &ISR_Default;						// 1.8 - Standby and Halt Wakeup Interrupt

	PieVectTable.EPWM1_TZ_INT = &ISR_Default;					// 2.1 - ePWM1 Trip Zone Interrupt
	PieVectTable.EPWM2_TZ_INT = &ISR_Default;					// 2.2 - ePWM2 Trip Zone Interrupt
	PieVectTable.EPWM3_TZ_INT = &ISR_Default;					// 2.3 - ePWM3 Trip Zone Interrupt
	PieVectTable.EPWM4_TZ_INT = &ISR_Default;					// 2.4 - ePWM4 Trip Zone Interrupt
	PieVectTable.EPWM5_TZ_INT = &ISR_Default;					// 2.5 - ePWM5 Trip Zone Interrupt
	PieVectTable.EPWM6_TZ_INT = &ISR_Default;					// 2.6 - ePWM6 Trip Zone Interrupt
	PieVectTable.EPWM7_TZ_INT = &ISR_Default;					// 2.7 - ePWM7 Trip Zone Interrupt
	PieVectTable.EPWM8_TZ_INT = &ISR_Default;					// 2.8 - ePWM8 Trip Zone Interrupt

	PieVectTable.EPWM1_INT = &ISR_Default;						// 3.1 - ePWM1 Interrupt
	PieVectTable.EPWM2_INT = &ISR_Default;						// 3.2 - ePWM2 Interrupt
	PieVectTable.EPWM3_INT = &ISR_Default;						// 3.3 - ePWM3 Interrupt
	PieVectTable.EPWM4_INT = &ISR_Default;						// 3.4 - ePWM4 Interrupt
	PieVectTable.EPWM5_INT = &ISR_Default;						// 3.5 - ePWM5 Interrupt
	PieVectTable.EPWM6_INT = &ISR_Default;						// 3.6 - ePWM6 Interrupt
	PieVectTable.EPWM7_INT = &ISR_Default;						// 3.7 - ePWM7 Interrupt
	PieVectTable.EPWM8_INT = &ISR_Default;						// 3.8 - ePWM8 Interrupt

	PieVectTable.ECAP1_INT = &ISR_Default;						// 4.1 - eCAP1 Interrupt
	PieVectTable.ECAP2_INT = &ISR_Default;						// 4.2 - eCAP2 Interrupt
	PieVectTable.ECAP3_INT = &ISR_Default;						// 4.3 - eCAP3 Interrupt
	PieVectTable.ECAP4_INT = &ISR_Default;						// 4.4 - eCAP4 Interrupt
	PieVectTable.ECAP5_INT = &ISR_Default;						// 4.5 - eCAP5 Interrupt
	PieVectTable.ECAP6_INT = &ISR_Default;						// 4.6 - eCAP6 Interrupt
	PieVectTable.PIE14_RESERVED_INT = &ISR_Default;				// 4.7 - Reserved
	PieVectTable.PIE15_RESERVED_INT = &ISR_Default;   			// 4.8 - Reserved

	PieVectTable.EQEP1_INT = &ISR_Default;						// 5.1 - eQEP1 Interrupt
	PieVectTable.EQEP2_INT = &ISR_Default;						// 5.2 - eQEP2 Interrupt
	PieVectTable.EQEP3_INT = &ISR_Default;						// 5.3 - eQEP3 Interrupt
	PieVectTable.PIE16_RESERVED_INT = &ISR_Default;				// 5.4 - Reserved
	PieVectTable.PIE17_RESERVED_INT = &ISR_Default;				// 5.5 - Reserved
	PieVectTable.PIE18_RESERVED_INT = &ISR_Default;				// 5.6 - Reserved
	PieVectTable.PIE19_RESERVED_INT = &ISR_Default;				// 5.7 - Reserved
	PieVectTable.PIE20_RESERVED_INT = &ISR_Default;				// 5.8 - Reserved

	PieVectTable.SPIA_RX_INT = &ISR_Default;					// 6.1 - SPIA Receive Interrupt
	PieVectTable.SPIA_TX_INT = &ISR_Default;					// 6.2 - SPIA Transmit Interrupt
	PieVectTable.SPIB_RX_INT = &ISR_Default;					// 6.3 - SPIB Receive Interrupt
	PieVectTable.SPIB_TX_INT = &ISR_Default;					// 6.4 - SPIB Transmit Interrupt
	PieVectTable.MCBSPA_RX_INT = &ISR_Default;					// 6.5 - McBSPA Receive Interrupt
	PieVectTable.MCBSPA_TX_INT = &ISR_Default;					// 6.6 - McBSPA Transmit Interrupt
	PieVectTable.MCBSPB_RX_INT = &ISR_Default;					// 6.7 - McBSPB Receive Interrupt
	PieVectTable.MCBSPB_TX_INT = &ISR_Default;					// 6.8 - McBSPB Transmit Interrupt

	PieVectTable.DMA_CH1_INT = &ISR_Default;					// 7.1 - DMA Channel 1 Interrupt
	PieVectTable.DMA_CH2_INT = &ISR_Default;					// 7.2 - DMA Channel 2 Interrupt
	PieVectTable.DMA_CH3_INT = &ISR_Default;					// 7.3 - DMA Channel 3 Interrupt
	PieVectTable.DMA_CH4_INT = &ISR_Default;					// 7.4 - DMA Channel 4 Interrupt
	PieVectTable.DMA_CH5_INT = &ISR_Default;					// 7.5 - DMA Channel 5 Interrupt
	PieVectTable.DMA_CH6_INT = &ISR_Default;					// 7.6 - DMA Channel 6 Interrupt
	PieVectTable.PIE21_RESERVED_INT = &ISR_Default;				// 7.7 - Reserved
	PieVectTable.PIE22_RESERVED_INT = &ISR_Default;				// 7.8 - Reserved

	PieVectTable.I2CA_INT = &ISR_Default;						// 8.1 - I2CA Interrupt 1
	PieVectTable.I2CA_FIFO_INT = &ISR_Default;					// 8.2 - I2CA Interrupt 2
	PieVectTable.I2CB_INT = &ISR_Default;						// 8.3 - I2CB Interrupt 1
	PieVectTable.I2CB_FIFO_INT = &ISR_Default;					// 8.4 - I2CB Interrupt 2
	PieVectTable.SCIC_RX_INT = &ISR_Default;					// 8.5 - SCIC Receive Interrupt
	PieVectTable.SCIC_TX_INT = &ISR_Default;					// 8.6 - SCIC Transmit Interrupt
	PieVectTable.SCID_RX_INT = &ISR_Default;					// 8.7 - SCID Receive Interrupt
	PieVectTable.SCID_TX_INT = &ISR_Default;					// 8.8 - SCID Transmit Interrupt

	PieVectTable.SCIA_RX_INT = &ISR_Default;					// 9.1 - SCIA Receive Interrupt
	PieVectTable.SCIA_TX_INT = &ISR_Default;					// 9.2 - SCIA Transmit Interrupt
	PieVectTable.SCIB_RX_INT = &ISR_Default;					// 9.3 - SCIB Receive Interrupt
	PieVectTable.SCIB_TX_INT = &ISR_Default;					// 9.4 - SCIB Transmit Interrupt
	PieVectTable.CANA_1_INT = &ISR_Default;						// 9.5 - CANA Interrupt 1
	PieVectTable.CANA_2_INT = &ISR_Default;						// 9.6 - CANA Interrupt 2
	PieVectTable.CANB_1_INT = &ISR_Default;						// 9.7 - CANB Interrupt 1
	PieVectTable.CANB_2_INT = &ISR_Default;						// 9.8 - CANB Interrupt 2

	PieVectTable.ADCA_EVT_INT = &ISR_Default;					// 10.1 - ADCA Event Interrupt
	PieVectTable.ADCA2_INT = &ISR_Default;						// 10.2 - ADCA Interrupt 2
	PieVectTable.ADCA3_INT = &ISR_Default;						// 10.3 - ADCA Interrupt 3
	PieVectTable.ADCA4_INT = &ISR_Default;						// 10.4 - ADCA Interrupt 4
	PieVectTable.ADCB_EVT_INT = &ISR_Default;					// 10.5 - ADCB Event Interrupt
	PieVectTable.ADCB2_INT = &ISR_Default;						// 10.6 - ADCB Interrupt 2
	PieVectTable.ADCB3_INT = &ISR_Default;						// 10.7 - ADCB Interrupt 3
	PieVectTable.ADCB4_INT = &ISR_Default;						// 10.8 - ADCB Interrupt 4

	PieVectTable.CLA1_1_INT = &ISR_Default;						// 11.1 - CLA1 Interrupt 1
	PieVectTable.CLA1_2_INT = &ISR_Default;						// 11.2 - CLA1 Interrupt 2
	PieVectTable.CLA1_3_INT = &ISR_Default;						// 11.3 - CLA1 Interrupt 3
	PieVectTable.CLA1_4_INT = &ISR_Default;						// 11.4 - CLA1 Interrupt 4
	PieVectTable.CLA1_5_INT = &ISR_Default;						// 11.5 - CLA1 Interrupt 5
	PieVectTable.CLA1_6_INT = &ISR_Default;						// 11.6 - CLA1 Interrupt 6
	PieVectTable.CLA1_7_INT = &ISR_Default;						// 11.7 - CLA1 Interrupt 7
	PieVectTable.CLA1_8_INT = &ISR_Default;						// 11.8 - CLA1 Interrupt 8

	PieVectTable.XINT3_INT = &ISR_Default;						// 12.1 - XINT3 Interrupt
	PieVectTable.XINT4_INT = &ISR_Default;						// 12.2 - XINT4 Interrupt
	PieVectTable.XINT5_INT = &ISR_Default;						// 12.3 - XINT5 Interrupt
	PieVectTable.PIE23_RESERVED_INT = &ISR_Default;				// 12.4 - Reserved
	PieVectTable.PIE24_RESERVED_INT = &ISR_Default;				// 12.5 - Reserved
	PieVectTable.VCU_INT = &ISR_Default;						// 12.6 - VCU Interrupt
	PieVectTable.FPU_OVERFLOW_INT = &ISR_Default;				// 12.7 - FPU Overflow Interrupt
	PieVectTable.FPU_UNDERFLOW_INT = &ISR_Default;				// 12.8 - FPU Underflow Interrupt

	PieVectTable.PIE25_RESERVED_INT = &ISR_Default;				// 1.9 - Reserved
	PieVectTable.PIE26_RESERVED_INT = &ISR_Default;				// 1.10 - Reserved
	PieVectTable.PIE27_RESERVED_INT = &ISR_Default;				// 1.11 - Reserved
	PieVectTable.PIE28_RESERVED_INT = &ISR_Default;				// 1.12 - Reserved
	PieVectTable.IPC0_INT = &ISR_Default;						// 1.13 - IPC Interrupt 0
	PieVectTable.IPC1_INT = &ISR_Default;						// 1.14 - IPC Interrupt 1
	PieVectTable.IPC2_INT = &ISR_Default;						// 1.15 - IPC Interrupt 2
	PieVectTable.IPC3_INT = &ISR_Default;						// 1.16 - IPC Interrupt 3

	PieVectTable.EPWM9_TZ_INT = &ISR_Default;					// 2.9 - ePWM9 Trip Zone Interrupt
	PieVectTable.EPWM10_TZ_INT = &ISR_Default;					// 2.10 - ePWM10 Trip Zone Interrupt
	PieVectTable.EPWM11_TZ_INT = &ISR_Default;					// 2.11 - ePWM11 Trip Zone Interrupt
	PieVectTable.EPWM12_TZ_INT = &ISR_Default;					// 2.12 - ePWM12 Trip Zone Interrupt
	PieVectTable.PIE29_RESERVED_INT = &ISR_Default;				// 2.13 - Reserved
	PieVectTable.PIE30_RESERVED_INT = &ISR_Default;				// 2.14 - Reserved
	PieVectTable.PIE31_RESERVED_INT = &ISR_Default;				// 2.15 - Reserved
	PieVectTable.PIE32_RESERVED_INT = &ISR_Default;				// 2.16 - Reserved

	PieVectTable.EPWM9_INT = &ISR_Default;						// 3.9 - ePWM9 Interrupt
	PieVectTable.EPWM10_INT = &ISR_Default;						// 3.10 - ePWM10 Interrupt
	PieVectTable.EPWM11_INT = &ISR_Default;						// 3.11 - ePWM11 Interrupt
	PieVectTable.EPWM12_INT = &ISR_Default;						// 3.12 - ePWM12 Interrupt
	PieVectTable.PIE33_RESERVED_INT = &ISR_Default;				// 3.13 - Reserved
	PieVectTable.PIE34_RESERVED_INT = &ISR_Default;				// 3.14 - Reserved
	PieVectTable.PIE35_RESERVED_INT = &ISR_Default;				// 3.15 - Reserved
	PieVectTable.PIE36_RESERVED_INT = &ISR_Default;				// 3.16 - Reserved

	PieVectTable.PIE37_RESERVED_INT = &ISR_Default;				// 4.9 - Reserved
	PieVectTable.PIE38_RESERVED_INT = &ISR_Default;				// 4.10 - Reserved
	PieVectTable.PIE39_RESERVED_INT = &ISR_Default;				// 4.11 - Reserved
	PieVectTable.PIE40_RESERVED_INT = &ISR_Default;				// 4.12 - Reserved
	PieVectTable.PIE41_RESERVED_INT = &ISR_Default;				// 4.13 - Reserved
	PieVectTable.PIE42_RESERVED_INT = &ISR_Default;				// 4.14 - Reserved
	PieVectTable.PIE43_RESERVED_INT = &ISR_Default;				// 4.15 - Reserved
	PieVectTable.PIE44_RESERVED_INT = &ISR_Default;				// 4.16 - Reserved

	PieVectTable.SD1_INT = &ISR_Default;						// 5.9 - SD1 Interrupt
	PieVectTable.SD2_INT = &ISR_Default;						// 5.10 - SD2 Interrupt
	PieVectTable.PIE45_RESERVED_INT = &ISR_Default;				// 5.11 - Reserved
	PieVectTable.PIE46_RESERVED_INT = &ISR_Default;				// 5.12 - Reserved
	PieVectTable.PIE47_RESERVED_INT = &ISR_Default;				// 5.13 - Reserved
	PieVectTable.PIE48_RESERVED_INT = &ISR_Default;				// 5.14 - Reserved
	PieVectTable.PIE49_RESERVED_INT = &ISR_Default;				// 5.15 - Reserved
	PieVectTable.PIE50_RESERVED_INT = &ISR_Default;				// 5.16 - Reserved

	PieVectTable.SPIC_RX_INT = &ISR_Default;					// 6.9 - SPIC Receive Interrupt
	PieVectTable.SPIC_TX_INT = &ISR_Default;					// 6.10 - SPIC Transmit Interrupt
	PieVectTable.PIE51_RESERVED_INT = &ISR_Default;				// 6.11 - Reserved
	PieVectTable.PIE52_RESERVED_INT = &ISR_Default;				// 6.12 - Reserved
	PieVectTable.PIE53_RESERVED_INT = &ISR_Default;				// 6.13 - Reserved
	PieVectTable.PIE54_RESERVED_INT = &ISR_Default;				// 6.14 - Reserved
	PieVectTable.PIE55_RESERVED_INT = &ISR_Default;				// 6.15 - Reserved
	PieVectTable.PIE56_RESERVED_INT = &ISR_Default;				// 6.16 - Reserved

	PieVectTable.PIE57_RESERVED_INT = &ISR_Default;				// 7.9 - Reserved
	PieVectTable.PIE58_RESERVED_INT = &ISR_Default;				// 7.10 - Reserved
	PieVectTable.PIE59_RESERVED_INT = &ISR_Default;				// 7.11 - Reserved
	PieVectTable.PIE60_RESERVED_INT = &ISR_Default;				// 7.12 - Reserved
	PieVectTable.PIE61_RESERVED_INT = &ISR_Default;				// 7.13 - Reserved
	PieVectTable.PIE62_RESERVED_INT = &ISR_Default;				// 7.14 - Reserved
	PieVectTable.PIE63_RESERVED_INT = &ISR_Default;				// 7.15 - Reserved
	PieVectTable.PIE64_RESERVED_INT = &ISR_Default;				// 7.16 - Reserved

	PieVectTable.PIE65_RESERVED_INT = &ISR_Default;				// 8.9 - Reserved
	PieVectTable.PIE66_RESERVED_INT = &ISR_Default;				// 8.10 - Reserved
	PieVectTable.PIE67_RESERVED_INT = &ISR_Default;				// 8.11 - Reserved
	PieVectTable.PIE68_RESERVED_INT = &ISR_Default;				// 8.12 - Reserved
	PieVectTable.PIE69_RESERVED_INT = &ISR_Default;				// 8.13 - Reserved
	PieVectTable.PIE70_RESERVED_INT = &ISR_Default;				// 8.14 - Reserved
	PieVectTable.UPPA_INT = &ISR_Default;						// 8.15 - uPPA Interrupt
	PieVectTable.PIE71_RESERVED_INT = &ISR_Default;				// 8.16 - Reserved

	PieVectTable.PIE72_RESERVED_INT = &ISR_Default;				// 9.9 - Reserved
	PieVectTable.PIE73_RESERVED_INT = &ISR_Default;				// 9.10 - Reserved
	PieVectTable.PIE74_RESERVED_INT = &ISR_Default;				// 9.11 - Reserved
	PieVectTable.PIE75_RESERVED_INT = &ISR_Default;				// 9.12 - Reserved
	PieVectTable.PIE76_RESERVED_INT = &ISR_Default;				// 9.13 - Reserved
	PieVectTable.PIE77_RESERVED_INT = &ISR_Default;				// 9.14 - Reserved
	PieVectTable.USBA_INT = &ISR_Default;						// 9.15 - USBA Interrupt
	PieVectTable.PIE78_RESERVED_INT = &ISR_Default;				// 9.16 - Reserved

	PieVectTable.ADCC_EVT_INT = &ISR_Default;					// 10.9 - ADCC Event Interrupt
	PieVectTable.ADCC2_INT = &ISR_Default;						// 10.10 - ADCC Interrupt 2
	PieVectTable.ADCC3_INT = &ISR_Default;						// 10.11 - ADCC Interrupt 3
	PieVectTable.ADCC4_INT = &ISR_Default;						// 10.12 - ADCC Interrupt 4
	PieVectTable.ADCD_EVT_INT = &ISR_Default;					// 10.13 - ADCD Event Interrupt
	PieVectTable.ADCD2_INT = &ISR_Default;						// 10.14 - ADCD Interrupt 2
	PieVectTable.ADCD3_INT = &ISR_Default;						// 10.15 - ADCD Interrupt 3
	PieVectTable.ADCD4_INT = &ISR_Default;						// 10.16 - ADCD Interrupt 4

	PieVectTable.PIE79_RESERVED_INT = &ISR_Default;				// 11.9 - Reserved
	PieVectTable.PIE80_RESERVED_INT = &ISR_Default;				// 11.10 - Reserved
	PieVectTable.PIE81_RESERVED_INT = &ISR_Default;				// 11.11 - Reserved
	PieVectTable.PIE82_RESERVED_INT = &ISR_Default;				// 11.12 - Reserved
	PieVectTable.PIE83_RESERVED_INT = &ISR_Default;				// 11.13 - Reserved
	PieVectTable.PIE84_RESERVED_INT = &ISR_Default;				// 11.14 - Reserved
	PieVectTable.PIE85_RESERVED_INT = &ISR_Default;				// 11.15 - Reserved
	PieVectTable.PIE86_RESERVED_INT = &ISR_Default;				// 11.16 - Reserved

	PieVectTable.EMIF_ERROR_INT = &ISR_Default;					// 12.9 - EMIF Error Interrupt
	PieVectTable.RAM_CORRECTABLE_ERROR_INT = &ISR_Default;		// 12.10 - RAM Correctable Error Interrupt
	PieVectTable.FLASH_CORRECTABLE_ERROR_INT = &ISR_Default;	// 12.11 - Flash Correctable Error Interrupt
	PieVectTable.RAM_ACCESS_VIOLATION_INT = &ISR_Default;		// 12.12 - RAM Access Violation Interrupt
	PieVectTable.SYS_PLL_SLIP_INT = &ISR_Default;				// 12.13 - System PLL Slip Interrupt
	PieVectTable.AUX_PLL_SLIP_INT = &ISR_Default;				// 12.14 - Auxiliary PLL Slip Interrupt
	PieVectTable.CLA_OVERFLOW_INT = &ISR_Default;				// 12.15 - CLA Overflow Interrupt
	PieVectTable.CLA_UNDERFLOW_INT = &ISR_Default;				// 12.16 - CLA Underflow Interrupt

	EDIS;

	// Enable the PIE Vector Table
	PieCtrlRegs.PIECTRL.bit.ENPIE = 1;			// 0(Disable), 1(Enable)

	return;
}

void Init_Mem(void)
{
	EALLOW;
	//Dx Memory Initialize(Common)
	MemCfgRegs.DxACCPROT0.all = 0x00000000;

	//LSx Memory Initialize(Common)
	MemCfgRegs.LSxMSEL.all = 0x00000000;
	MemCfgRegs.LSxACCPROT0.all = 0x00000000;
	MemCfgRegs.LSxACCPROT1.all = 0x00000000;
	MemCfgRegs.LSxCLAPGM.all = 0x00000000;

	//GSx Memory Initalized
	// Master core select	: 0(CPU1), 1(CPU2)
	MemCfgRegs.GSxMSEL.bit.MSEL_GS0 = 0;
	MemCfgRegs.GSxMSEL.bit.MSEL_GS1 = 0;
	MemCfgRegs.GSxMSEL.bit.MSEL_GS2 = 0;
	MemCfgRegs.GSxMSEL.bit.MSEL_GS3 = 0;
	MemCfgRegs.GSxMSEL.bit.MSEL_GS4 = 0;
	MemCfgRegs.GSxMSEL.bit.MSEL_GS5 = 0;
	MemCfgRegs.GSxMSEL.bit.MSEL_GS6 = 0;
	MemCfgRegs.GSxMSEL.bit.MSEL_GS7 = 0;
	MemCfgRegs.GSxMSEL.bit.MSEL_GS8 = 1;
	MemCfgRegs.GSxMSEL.bit.MSEL_GS9 = 1;
	MemCfgRegs.GSxMSEL.bit.MSEL_GS10 = 1;
	MemCfgRegs.GSxMSEL.bit.MSEL_GS11 = 1;
	MemCfgRegs.GSxMSEL.bit.MSEL_GS12 = 1;
	MemCfgRegs.GSxMSEL.bit.MSEL_GS13 = 1;
	MemCfgRegs.GSxMSEL.bit.MSEL_GS14 = 1;
	MemCfgRegs.GSxMSEL.bit.MSEL_GS15 = 1;

	//CPU1
#ifdef CPU1
    MemCfgRegs.GSxACCPROT3.bit.CPUWRPROT_GS12 = 1;
	MemCfgRegs.GSxACCPROT3.bit.CPUWRPROT_GS13 = 1;
	MemCfgRegs.GSxACCPROT3.bit.CPUWRPROT_GS14 = 1;
	MemCfgRegs.GSxACCPROT3.bit.CPUWRPROT_GS15 = 1;

	MemCfgRegs.GSxACCPROT3.bit.DMAWRPROT_GS12 = 1;
	MemCfgRegs.GSxACCPROT3.bit.DMAWRPROT_GS13 = 1;
	MemCfgRegs.GSxACCPROT3.bit.DMAWRPROT_GS14 = 1;
	MemCfgRegs.GSxACCPROT3.bit.DMAWRPROT_GS15 = 1;

	MemCfgRegs.GSxACCPROT3.bit.FETCHPROT_GS12 = 1;
	MemCfgRegs.GSxACCPROT3.bit.FETCHPROT_GS13 = 1;
	MemCfgRegs.GSxACCPROT3.bit.FETCHPROT_GS14 = 1;
	MemCfgRegs.GSxACCPROT3.bit.FETCHPROT_GS15 = 1;

	MemCfgRegs.GSxACCPROT2.bit.CPUWRPROT_GS11 = 1;
	MemCfgRegs.GSxACCPROT2.bit.CPUWRPROT_GS10 = 1;
	MemCfgRegs.GSxACCPROT2.bit.CPUWRPROT_GS9  = 1;
	MemCfgRegs.GSxACCPROT2.bit.CPUWRPROT_GS8  = 1;

	MemCfgRegs.GSxACCPROT2.bit.DMAWRPROT_GS11 = 1;
	MemCfgRegs.GSxACCPROT2.bit.DMAWRPROT_GS10 = 1;
	MemCfgRegs.GSxACCPROT2.bit.DMAWRPROT_GS9  = 1;
	MemCfgRegs.GSxACCPROT2.bit.DMAWRPROT_GS8  = 1;

	MemCfgRegs.GSxACCPROT2.bit.FETCHPROT_GS11 = 1;
	MemCfgRegs.GSxACCPROT2.bit.FETCHPROT_GS10 = 1;
	MemCfgRegs.GSxACCPROT2.bit.FETCHPROT_GS9  = 1;
	MemCfgRegs.GSxACCPROT2.bit.FETCHPROT_GS8  = 1;

    MemCfgRegs.GSxACCPROT1.bit.CPUWRPROT_GS7 = 0;
    MemCfgRegs.GSxACCPROT1.bit.CPUWRPROT_GS6 = 0;
    MemCfgRegs.GSxACCPROT1.bit.CPUWRPROT_GS5 = 0;
    MemCfgRegs.GSxACCPROT1.bit.CPUWRPROT_GS4 = 0;

    MemCfgRegs.GSxACCPROT1.bit.DMAWRPROT_GS7 = 0;
    MemCfgRegs.GSxACCPROT1.bit.DMAWRPROT_GS6 = 0;
    MemCfgRegs.GSxACCPROT1.bit.DMAWRPROT_GS5 = 0;
    MemCfgRegs.GSxACCPROT1.bit.DMAWRPROT_GS4 = 0;

    MemCfgRegs.GSxACCPROT1.bit.FETCHPROT_GS7 = 0;
    MemCfgRegs.GSxACCPROT1.bit.FETCHPROT_GS6 = 0;
    MemCfgRegs.GSxACCPROT1.bit.FETCHPROT_GS5 = 0;
    MemCfgRegs.GSxACCPROT1.bit.FETCHPROT_GS4 = 0;

    MemCfgRegs.GSxACCPROT0.bit.CPUWRPROT_GS3 = 0;
    MemCfgRegs.GSxACCPROT0.bit.CPUWRPROT_GS2 = 0;
    MemCfgRegs.GSxACCPROT0.bit.CPUWRPROT_GS1 = 0;
    MemCfgRegs.GSxACCPROT0.bit.CPUWRPROT_GS0 = 0;

    MemCfgRegs.GSxACCPROT0.bit.DMAWRPROT_GS3 = 0;
    MemCfgRegs.GSxACCPROT0.bit.DMAWRPROT_GS2 = 0;
    MemCfgRegs.GSxACCPROT0.bit.DMAWRPROT_GS1 = 0;
    MemCfgRegs.GSxACCPROT0.bit.DMAWRPROT_GS0 = 0;

    MemCfgRegs.GSxACCPROT0.bit.FETCHPROT_GS3 = 0;
    MemCfgRegs.GSxACCPROT0.bit.FETCHPROT_GS2 = 0;
    MemCfgRegs.GSxACCPROT0.bit.FETCHPROT_GS1 = 0;
    MemCfgRegs.GSxACCPROT0.bit.FETCHPROT_GS0 = 0;
#endif
    //CPU2
#ifdef CPU2
    MemCfgRegs.GSxACCPROT3.bit.CPUWRPROT_GS12 = 0;
    MemCfgRegs.GSxACCPROT3.bit.CPUWRPROT_GS13 = 0;
    MemCfgRegs.GSxACCPROT3.bit.CPUWRPROT_GS14 = 0;
    MemCfgRegs.GSxACCPROT3.bit.CPUWRPROT_GS15 = 0;

    MemCfgRegs.GSxACCPROT3.bit.DMAWRPROT_GS12 = 0;
    MemCfgRegs.GSxACCPROT3.bit.DMAWRPROT_GS13 = 0;
    MemCfgRegs.GSxACCPROT3.bit.DMAWRPROT_GS14 = 0;
    MemCfgRegs.GSxACCPROT3.bit.DMAWRPROT_GS15 = 0;

    MemCfgRegs.GSxACCPROT3.bit.FETCHPROT_GS12 = 0;
    MemCfgRegs.GSxACCPROT3.bit.FETCHPROT_GS13 = 0;
    MemCfgRegs.GSxACCPROT3.bit.FETCHPROT_GS14 = 0;
    MemCfgRegs.GSxACCPROT3.bit.FETCHPROT_GS15 = 0;

    MemCfgRegs.GSxACCPROT2.bit.CPUWRPROT_GS11 = 0;
    MemCfgRegs.GSxACCPROT2.bit.CPUWRPROT_GS10 = 0;
    MemCfgRegs.GSxACCPROT2.bit.CPUWRPROT_GS9  = 0;
    MemCfgRegs.GSxACCPROT2.bit.CPUWRPROT_GS8  = 0;

    MemCfgRegs.GSxACCPROT2.bit.DMAWRPROT_GS11 = 0;
    MemCfgRegs.GSxACCPROT2.bit.DMAWRPROT_GS10 = 0;
    MemCfgRegs.GSxACCPROT2.bit.DMAWRPROT_GS9  = 0;
    MemCfgRegs.GSxACCPROT2.bit.DMAWRPROT_GS8  = 0;

    MemCfgRegs.GSxACCPROT2.bit.FETCHPROT_GS11 = 0;
    MemCfgRegs.GSxACCPROT2.bit.FETCHPROT_GS10 = 0;
    MemCfgRegs.GSxACCPROT2.bit.FETCHPROT_GS9  = 0;
    MemCfgRegs.GSxACCPROT2.bit.FETCHPROT_GS8  = 0;

    MemCfgRegs.GSxACCPROT1.bit.CPUWRPROT_GS7 = 1;
    MemCfgRegs.GSxACCPROT1.bit.CPUWRPROT_GS6 = 1;
    MemCfgRegs.GSxACCPROT1.bit.CPUWRPROT_GS5 = 1;
    MemCfgRegs.GSxACCPROT1.bit.CPUWRPROT_GS4 = 1;

    MemCfgRegs.GSxACCPROT1.bit.DMAWRPROT_GS7 = 1;
    MemCfgRegs.GSxACCPROT1.bit.DMAWRPROT_GS6 = 1;
    MemCfgRegs.GSxACCPROT1.bit.DMAWRPROT_GS5 = 1;
    MemCfgRegs.GSxACCPROT1.bit.DMAWRPROT_GS4 = 1;

    MemCfgRegs.GSxACCPROT1.bit.FETCHPROT_GS7 = 1;
    MemCfgRegs.GSxACCPROT1.bit.FETCHPROT_GS6 = 1;
    MemCfgRegs.GSxACCPROT1.bit.FETCHPROT_GS5 = 1;
    MemCfgRegs.GSxACCPROT1.bit.FETCHPROT_GS4 = 1;

    MemCfgRegs.GSxACCPROT0.bit.CPUWRPROT_GS3 = 1;
    MemCfgRegs.GSxACCPROT0.bit.CPUWRPROT_GS2 = 1;
    MemCfgRegs.GSxACCPROT0.bit.CPUWRPROT_GS1 = 1;
    MemCfgRegs.GSxACCPROT0.bit.CPUWRPROT_GS0 = 1;

    MemCfgRegs.GSxACCPROT0.bit.DMAWRPROT_GS3 = 1;
    MemCfgRegs.GSxACCPROT0.bit.DMAWRPROT_GS2 = 1;
    MemCfgRegs.GSxACCPROT0.bit.DMAWRPROT_GS1 = 1;
    MemCfgRegs.GSxACCPROT0.bit.DMAWRPROT_GS0 = 1;

    MemCfgRegs.GSxACCPROT0.bit.FETCHPROT_GS3 = 1;
    MemCfgRegs.GSxACCPROT0.bit.FETCHPROT_GS2 = 1;
    MemCfgRegs.GSxACCPROT0.bit.FETCHPROT_GS1 = 1;
    MemCfgRegs.GSxACCPROT0.bit.FETCHPROT_GS0 = 1;
#endif
	EDIS;

	return;
}

void Start_PieCtrl(void)
{
	PieCtrlRegs.PIEIER3.bit.INTx1 = 1;
	IER |= M_INT3;

    // CPUx Master Interrupt Enable.
    EINT;                                               // Master Interrupt Enable.
    ERTM;                                               // Debug Interrupt Enable.
	return;
}

interrupt void ISR_Default(void)
{
	ESTOP0;										// Stop Emulation
	for(;;);
}

void Init_Flash(void)
{
	#ifdef _FLASH
	memcpy(&RamfuncsRunStart, &RamfuncsLoadStart, (size_t)&RamfuncsLoadSize);
	#endif

    EALLOW;

    //At reset bank and pump are in sleep
    //A Flash access will power up the bank and pump automatically
    //After a Flash access, bank and pump go to low power mode (configurable in FBFALLBACK/FPAC1 registers)-
    //if there is no further access to flash
    //Power up Flash bank and pump and this also sets the fall back mode of flash and pump as active
    Flash0CtrlRegs.FPAC1.bit.PMPPWR = 0x1;
    Flash0CtrlRegs.FBFALLBACK.bit.BNKPWR0 = 0x3;

    //Disable Cache and prefetch mechanism before changing wait states
    Flash0CtrlRegs.FRD_INTF_CTRL.bit.DATA_CACHE_EN = 0;
    Flash0CtrlRegs.FRD_INTF_CTRL.bit.PREFETCH_EN = 0;

    //Set waitstates according to frequency
    //                CAUTION
    //Minimum waitstates required for the flash operating
    //at a given CPU rate must be characterized by TI.
    //Refer to the datasheet for the latest information.
    #if CPU_FRQ_200MHZ
    Flash0CtrlRegs.FRDCNTL.bit.RWAIT = 0x3;
    #endif

    #if CPU_FRQ_150MHZ
    Flash0CtrlRegs.FRDCNTL.bit.RWAIT = 0x2;
    #endif

    #if CPU_FRQ_120MHZ
    Flash0CtrlRegs.FRDCNTL.bit.RWAIT = 0x2;
    #endif

    //Enable Cache and prefetch mechanism to improve performance
    //of code executed from Flash.
    Flash0CtrlRegs.FRD_INTF_CTRL.bit.DATA_CACHE_EN = 1;
    Flash0CtrlRegs.FRD_INTF_CTRL.bit.PREFETCH_EN = 1;

    //At reset, ECC is enabled
    //If it is disabled by application software and if application again wants to enable ECC
    Flash0EccRegs.ECC_ENABLE.bit.ENABLE = 0xA;

    EDIS;

    //Force a pipeline flush to ensure that the write to
    //the last register configured occurs before returning.

    __asm(" RPT #7 || NOP");

}
