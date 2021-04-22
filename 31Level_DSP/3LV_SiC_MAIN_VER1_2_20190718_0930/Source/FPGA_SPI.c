/*
 * FPGA_SPI.c
 *
 *  Created on: 2019. 6. 24.
 *      Author: HJHeo
 */

#include "Define_Header.h"
#include "Define_FPGA.h"

#ifdef CPU1

extern Uint16 dac_temp[1][4];

void Init_FPGA_SPI(void)
{
	// ---------------------------------------- SPI0 ---------------------------------------- //
	// SPI0 Set Configuration Mode.
	FpgaCs2Regs.SPI0.CFG.bit.SWRESET = 1;					// 15	: SWRESET	; 0(Normal Mode), 1(Configuration Mode).

	// SPI0 Setting.
	FpgaCs2Regs.SPI0.CFG.all = SPICFG_SWRESET_ResetMode		// 15	: SWRESET	; 0(Normal Mode), 1(Configuration Mode).
							| SPICFG_LPB_LoopBackDisable	// 10	: LPB		; 0(Normal Mode), 1(LoopBack Mode).
							| SPICFG_TALK_TxEnable			// 9	: TALK		; 0(TX Disable), 1(TX Enable).
							| SPICFG_CLK_PHA_Delayed		// 5	: CLK_PHA	; 0(Normal), 1(Delayed).
							| SPICFG_CLK_POL_ACTVHigh		// 4	: CLK_POL	; 0(Active High), 1(Active Low);
							| SPICFG_CHAR_Length(16);		// 3-0	: CHAR		; 0(1-bit), 1(2-bit), 2(3-bit), ..., 15(16-bit).

	FpgaCs2Regs.SPI0.BRR = 9;								// 15-0	: BRR		; SPICLK = EMIF1CLK / (BRR + 1).
															//					; 10[MHz] = 100[MHz] / (9 + 1).

	FpgaCs2Regs.SPI0.CSC.all = SPICSC_CS3POL_CS3ACTVHigh	// 11	: CS3POL	; 0(Active High), 1(Active Low).
							| SPICSC_CS2POL_CS2ACTVHigh		// 10	: CS2POL	; 0(Active High), 1(Active Low).
							| SPICSC_CS1POL_CS1ACTVHigh		// 9	: CS1POL	; 0(Active High), 1(Active Low).
							| SPICSC_CS0POL_CS0ACTVLow		// 8	: CS0POL	; 0(Active High), 1(Active Low).
							| SPICSC_CSSET1_CS3Disable		// 7	: SE1_CS3EN	; 0(Disable), 1(Enable).
							| SPICSC_CSSET1_CS2Enable		// 6	: SE1_CS2EN	; 0(Disable), 1(Enable).
							| SPICSC_CSSET1_CS1Disable		// 5	: SE1_CS1EN	; 0(Disable), 1(Enable).
							| SPICSC_CSSET1_CS0Enable		// 4	: SE1_CS0EN	; 0(Disable), 1(Enable).
							| SPICSC_CSSET0_CS3Disable		// 3	: SE0_CS3EN	; 0(Disable), 1(Enable).
							| SPICSC_CSSET0_CS2Disable		// 2	: SE0_CS2EN	; 0(Disable), 1(Enable).
							| SPICSC_CSSET0_CS1Enable		// 1	: SE0_CS1EN	; 0(Disable), 1(Enable).
							| SPICSC_CSSET0_CS0Enable;		// 0	: SE0_CS0EN	; 0(Disable), 1(Enable).

	FpgaCs2Regs.SPI0.DLY.all = 1;							// 4-0	: DELAY		; 0(No Delay), 1(1 SPICLK Delay), 2(2 SPICLK Delay), ...,31(31 SPICLK Delay).

	// SPI0 Set Normal Mode.
	FpgaCs2Regs.SPI0.CFG.bit.SWRESET = 0;					// 15	: SWRESET	; 0(Normal Mode), 1(Configuration Mode).

	// ---------------------------------------- SPI1 ---------------------------------------- //
	// SPI0 Set Configuration Mode.
	FpgaCs2Regs.SPI1.CFG.bit.SWRESET = 1;					// 15	: SWRESET	; 0(Normal Mode), 1(Configuration Mode).

	// SPI0 Setting.
	FpgaCs2Regs.SPI1.CFG.all = SPICFG_SWRESET_ResetMode		// 15	: SWRESET	; 0(Normal Mode), 1(Configuration Mode).
							| SPICFG_LPB_LoopBackDisable	// 10	: LPB		; 0(Normal Mode), 1(LoopBack Mode).
							| SPICFG_TALK_TxEnable			// 9	: TALK		; 0(TX Disable), 1(TX Enable).
							| SPICFG_CLK_PHA_Normal			// 5	: CLK_PHA	; 0(Normal), 1(Delayed).
							| SPICFG_CLK_POL_ACTVLow		// 4	: CLK_POL	; 0(Active High), 1(Active Low);
							| SPICFG_CHAR_Length(8);		// 3-0	: CHAR		; 0(1-bit), 1(2-bit), 2(3-bit), ..., 15(16-bit).

	FpgaCs2Regs.SPI1.BRR = 9;								// 15-0	: BRR		; SPICLK = EMIF1CLK / (BRR + 1).
															//					; 10[MHz] = 100[MHz] / (9 + 1).

	FpgaCs2Regs.SPI1.CSC.all = SPICSC_CS3POL_CS3ACTVHigh	// 11	: CS3POL	; 0(Active High), 1(Active Low).
							| SPICSC_CS2POL_CS2ACTVHigh		// 10	: CS2POL	; 0(Active High), 1(Active Low).
							| SPICSC_CS1POL_CS1ACTVLow		// 9	: CS1POL	; 0(Active High), 1(Active Low).
							| SPICSC_CS0POL_CS0ACTVLow		// 8	: CS0POL	; 0(Active High), 1(Active Low).
							| SPICSC_CSSET1_CS3Disable		// 7	: SE1_CS3EN	; 0(Disable), 1(Enable).
							| SPICSC_CSSET1_CS2Disable		// 6	: SE1_CS2EN	; 0(Disable), 1(Enable).
							| SPICSC_CSSET1_CS1Enable		// 5	: SE1_CS1EN	; 0(Disable), 1(Enable).
							| SPICSC_CSSET1_CS0Disable		// 4	: SE1_CS0EN	; 0(Disable), 1(Enable).
							| SPICSC_CSSET0_CS3Disable		// 3	: SE0_CS3EN	; 0(Disable), 1(Enable).
							| SPICSC_CSSET0_CS2Disable		// 2	: SE0_CS2EN	; 0(Disable), 1(Enable).
							| SPICSC_CSSET0_CS1Disable		// 1	: SE0_CS1EN	; 0(Disable), 1(Enable).
							| SPICSC_CSSET0_CS0Enable;		// 0	: SE0_CS0EN	; 0(Disable), 1(Enable).

	FpgaCs2Regs.SPI1.DLY.all = 1;							// 4-0	: DELAY		; 0(No Delay), 1(1 SPICLK Delay), 2(2 SPICLK Delay), ...,31(31 SPICLK Delay).

	// SPI0 Set Normal Mode.
	FpgaCs2Regs.SPI1.CFG.bit.SWRESET = 0;					// 15	: SWRESET	; 0(Normal Mode), 1(Configuration Mode).

	return;
}

void FPGA_SPI_TX(void)
{
#if (CPU2_BOOT_ENABLE)
	while(IpcRegs.IPCSTS.bit.IPC28 == 0);
	IpcRegs.IPCACK.all = IPCxxx_IPC28;
#endif

	FpgaCs2Regs.SPI0.CSSET0_DAT0 = dac_temp[0][0];
	FpgaCs2Regs.SPI0.CSSET0_DAT1 = dac_temp[0][1];
	FpgaCs2Regs.SPI0.CSSET0_DAT2 = dac_temp[0][2];
	FpgaCs2Regs.SPI0.CSSET0_DAT3 = dac_temp[0][3];

	return;
}

#endif
