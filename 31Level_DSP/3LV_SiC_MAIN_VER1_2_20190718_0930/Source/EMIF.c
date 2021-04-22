/*
 * EMIF.c
 *
 *  Created on: 2019. 6. 24.
 *      Author: HJHeo
 */

#include "Define_Header.h"
#include "Define_EMIF.h"

//************************************ CPU1 & CPU2 ************************************//
void Init_EMIF1(Uint16 host)
{
	EALLOW;

	// EMIF Host Define.
	Emif1ConfigRegs.EMIF1MSEL.all = EMIF1MSEL_KEY_MatchedKey			// 31-4	: KEY			; 0x93A5CE7(Valid Key).
								| (Uint32)host;							// 1-0	: MSEL_EMIF1	; 0, 3(Unfixed Host CPU1), 1(Fixed Host CPU1), 2(Fixed Host CPU2).

	// Asynchronous EMIF
	//// Asynchronous EMIF : Wait Configuration.
	Emif1Regs.ASYNC_WCCR.all = ASYNC_WCCR_WP0_EMxWAIT_WaitForLow		// 28	: WP0			; 0(Wait for Low EMxWAIT), 1(Wait for High EMxWAIT).
							| ASYNC_WCCR_MAX_EXT_WAIT_Val(0);			// 7-0	: MAX_EXT_WAIT	; (MAX_EXT_WAIT + 1) * 16 EMIFxCLK.

	//// Asynchronous EMIF : CS2.
	////// Asynchronous EMIF : CS2 - Pin Function.
	Emif1Regs.ASYNC_CS2_CR.all = ASYNC_CSx_CR_SS_ChipSelectMode			// 31	: SS			; 0(Chip Select Mode), 1(Select Strobe Mode).
							| ASYNC_CSx_CR_EW_EMxWAITDis				// 30	: EW			; 0(EMxWAIT Disable), 1(EMxWAIT Enable).
	////// Asynchronous EMIF : CS2 - Write Timing.
							| ASYNC_CSx_CR_W_SETUP_Clock(2)				// 29-26: W_SETUP		; (W_SETUP + 1) * EMIFxCLK.
							| ASYNC_CSx_CR_W_STROBE_Clock(3)			// 25-20: W_STROBE		; (W_STROBE + 1) * EMIFxCLK.
							| ASYNC_CSx_CR_W_HOLD_Clock(2)				// 19-17: W_HOLD		; (W_HOLD + 1) * EMIFxCLK.
	////// Asynchronous EMIF : CS2 - Read Timing.
							| ASYNC_CSx_CR_R_SETUP_Clock(2)				// 16-13: R_SETUP		; (R_SETUP + 1) * EMIFxCLK.
							| ASYNC_CSx_CR_R_STROBE_Clock(3)			// 12-7	: R_STROBE		; (R_STROBE + 1) * EMIFxCLK.
							| ASYNC_CSx_CR_R_HOLD_Clock(2)				// 6-4	: R_HOLD		; (R_HOLD + 1) * EMIFxCLK.
	////// Asynchronous EMIF : CS2 - Access to Access Delay Timing.
							| ASYNC_CSx_CR_TA_AcctoAccDelayClock(2)		// 3-2	: TA			; (TA + 1) * EMIFxCLK.
	////// Asynchronous EMIF : CS2 - Data Length.
							| ASYNC_CSx_CR_ASIZE_16bitMode;				// 1-0	: ASIZE			; 0(8bit Mode), 1(16bit Mode), 2(32bit Mode).

	//// Asynchronous EMIF : CS3.
	////// Asynchronous EMIF : CS3 - Pin Function.
	Emif1Regs.ASYNC_CS3_CR.all = ASYNC_CSx_CR_SS_ChipSelectMode			// 31	: SS			; 0(Chip Select Mode), 1(Select Strobe Mode).
							| ASYNC_CSx_CR_EW_EMxWAITDis				// 30	: EW			; 0(EMxWAIT Disable), 1(EMxWAIT Enable).
	////// Asynchronous EMIF : CS3 - Write Timing.
							| ASYNC_CSx_CR_W_SETUP_Clock(2)				// 29-26: W_SETUP		; (W_SETUP + 1) * EMIFxCLK.
							| ASYNC_CSx_CR_W_STROBE_Clock(3)			// 25-20: W_STROBE		; (W_STROBE + 1) * EMIFxCLK.
							| ASYNC_CSx_CR_W_HOLD_Clock(2)				// 19-17: W_HOLD		; (W_HOLD + 1) * EMIFxCLK.
	////// Asynchronous EMIF : CS3 - Read Timing.
							| ASYNC_CSx_CR_R_SETUP_Clock(2)				// 16-13: R_SETUP		; (R_SETUP + 1) * EMIFxCLK.
							| ASYNC_CSx_CR_R_STROBE_Clock(3)			// 12-7	: R_STROBE		; (R_STROBE + 1) * EMIFxCLK.
							| ASYNC_CSx_CR_R_HOLD_Clock(2)				// 6-4	: R_HOLD		; (R_HOLD + 1) * EMIFxCLK.
	////// Asynchronous EMIF : CS3 - Access to Access Delay Timing.
							| ASYNC_CSx_CR_TA_AcctoAccDelayClock(2)		// 3-2	: TA			; (TA + 1) * EMIFxCLK.
	////// Asynchronous EMIF : CS3 - Data Length.
							| ASYNC_CSx_CR_ASIZE_16bitMode;				// 1-0	: ASIZE			; 0(8bit Mode), 1(16bit Mode), 2(32bit Mode).

	//// Asynchronous EMIF : CS4.
	////// Asynchronous EMIF : CS4 - Pin Function.
	Emif1Regs.ASYNC_CS4_CR.all = ASYNC_CSx_CR_SS_ChipSelectMode			// 31	: SS			; 0(Chip Select Mode), 1(Select Strobe Mode).
							| ASYNC_CSx_CR_EW_EMxWAITDis				// 30	: EW			; 0(EMxWAIT Disable), 1(EMxWAIT Enable).
	////// Asynchronous EMIF : CS4 - Write Timing.
							| ASYNC_CSx_CR_W_SETUP_Clock(2)				// 29-26: W_SETUP		; (W_SETUP + 1) * EMIFxCLK.
							| ASYNC_CSx_CR_W_STROBE_Clock(3)			// 25-20: W_STROBE		; (W_STROBE + 1) * EMIFxCLK.
							| ASYNC_CSx_CR_W_HOLD_Clock(2)				// 19-17: W_HOLD		; (W_HOLD + 1) * EMIFxCLK.
	////// Asynchronous EMIF : CS4 - Read Timing.
							| ASYNC_CSx_CR_R_SETUP_Clock(2)				// 16-13: R_SETUP		; (R_SETUP + 1) * EMIFxCLK.
							| ASYNC_CSx_CR_R_STROBE_Clock(3)			// 12-7	: R_STROBE		; (R_STROBE + 1) * EMIFxCLK.
							| ASYNC_CSx_CR_R_HOLD_Clock(2)				// 6-4	: R_HOLD		; (R_HOLD + 1) * EMIFxCLK.
	////// Asynchronous EMIF : CS4 - Access to Access Delay Timing.
							| ASYNC_CSx_CR_TA_AcctoAccDelayClock(2)		// 3-2	: TA			; (TA + 1) * EMIFxCLK.
	////// Asynchronous EMIF : CS4 - Data Length.
							| ASYNC_CSx_CR_ASIZE_16bitMode;				// 1-0	: ASIZE			; 0(8bit Mode), 1(16bit Mode), 2(32bit Mode).

	EDIS;

	return;
}

//**************************************** CPU2 ****************************************//
#ifdef CPU1
void Init_EMIF2(void)
{

	return;
}
#endif
