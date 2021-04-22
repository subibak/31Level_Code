//###########################################################################
//
// FILE:    F2837xD_emif.h
//
// TITLE:   F2837xD Device EMIF Register Definitions.
//
//###########################################################################
// $TI Release: F2837xD Support Library v210 $
// $Release Date: Tue Nov  1 14:46:15 CDT 2016 $
// $Copyright: Copyright (C) 2013-2016 Texas Instruments Incorporated -
//             http://www.ti.com/ ALL RIGHTS RESERVED $
//###########################################################################

#ifndef __F2837xD_EMIF_H__
#define __F2837xD_EMIF_H__

#ifdef __cplusplus
extern "C" {
#endif


//---------------------------------------------------------------------------
// EMIF Individual Register Bit Definitions:

struct RCSR_BITS {                      // bits description
    Uint16 MINOR_REVISION:8;            // 7:0 Minor Revision. 
    Uint16 MAJOR_REVISION:8;            // 15:8 Major Revision. 
    Uint16 MODULE_ID:14;                // 29:16 EMIF module ID.
    Uint16 FR:1;                        // 30 EMIF is running in full rate or half rate.
    Uint16 BE:1;                        // 31 EMIF endian mode.
};

union RCSR_REG {
    Uint32  all;
    struct  RCSR_BITS  bit;
};

struct ASYNC_WCCR_BITS {                // bits description
    Uint16 MAX_EXT_WAIT:8;              // 7:0 Maximum Extended Wait cycles.
    Uint16 rsvd1:8;                     // 15:8 Reserved
    Uint16 rsvd2:2;                     // 17:16 Reserved
    Uint16 rsvd3:2;                     // 19:18 Reserved
    Uint16 rsvd4:2;                     // 21:20 Reserved
    Uint16 rsvd5:2;                     // 23:22 Reserved
    Uint16 rsvd6:4;                     // 27:24 Reserved
    Uint16 WP0:1;                       // 28  Polarity for EMxWAIT.
    Uint16 rsvd7:1;                     // 29 Reserved
    Uint16 rsvd8:1;                     // 30 Reserved
    Uint16 rsvd9:1;                     // 31 Reserved
};

union ASYNC_WCCR_REG {
    Uint32  all;
    struct  ASYNC_WCCR_BITS  bit;
};

// ASYNC_WCCR Register
//// ASYNC_WCCR Register : Byte Value
#define ASYNC_WCCR_WP0_EMxWAIT_WaitForLow				0x00000000UL					// Wait if EMxWAIT Port is Low.
#define ASYNC_WCCR_WP0_EMxWAIT_WiatForHigh				0x10000000UL					// Wait if EMxWAIT Port is High.

#define ASYNC_WCCR_MAX_EXT_WAIT_EMIFxCLK(num)			(((num - 1) >> 4) & 0x000000FFUL)	// The EMIFx Will Wait for (MAX_EXT_WAIT + 1) * 16 Clock Cycle Before an Extended Asynchronous Cycle is Terminated.
#define ASYNC_WCCR_MAX_EXT_WAIT_Val(val)				(val & 0x000000FFUL)				// The EMIFx Will Wait for (MAX_EXT_WAIT + 1) * 16 Clock Cycle Before an Extended Asynchronous Cycle is Terminated.

struct SDRAM_CR_BITS {                  // bits description
    Uint16 PAGESIGE:3;                  // 2:0 Page Size.
    Uint16 rsvd1:1;                     // 3 Reserved
    Uint16 IBANK:3;                     // 6:4 Internal Bank setup of SDRAM devices.
    Uint16 rsvd2:1;                     // 7 Reserved
    Uint16 BIT_11_9_LOCK:1;             // 8 Bits 11 to 9 are writable only if this bit is set.
    Uint16 CL:3;                        // 11:9 CAS Latency.
    Uint16 rsvd3:1;                     // 12 Reserved
    Uint16 rsvd4:1;                     // 13 Reserved
    Uint16 NM:1;                        // 14 Narrow Mode.
    Uint16 rsvd5:1;                     // 15 Reserved
    Uint16 rsvd6:1;                     // 16 Reserved
    Uint16 rsvd7:2;                     // 18:17 Reserved
    Uint16 rsvd8:1;                     // 19 Reserved
    Uint16 rsvd9:3;                     // 22:20 Reserved
    Uint16 rsvd10:3;                    // 25:23 Reserved
    Uint16 rsvd11:3;                    // 28:26 Reserved
    Uint16 PDWR:1;                      // 29 Perform refreshes during Power Down.
    Uint16 PD:1;                        // 30 Power Down.
    Uint16 SR:1;                        // 31 Self Refresh.
};

union SDRAM_CR_REG {
    Uint32  all;
    struct  SDRAM_CR_BITS  bit;
};

// SDRAM_CR Register
//// SDRAM_CR Register : Byte Value
#define SDRAM_CR_SR_PD_NormalMode						0x00000000UL					// SDRAM is Operated in Normal Mode.
#define SDRAM_CR_SR_PD_PowerDownMode					0x40000000UL					// SDRAM is Operated in Power Down Mode. In This Mode, the Data in SDRAM could be Lost.
#define SDRAM_CR_SR_PD_SelfRefreshMode					0x80000000UL					// SDRAM is Operated in Self Refresh Mode. In This Mode, It is Possible to reduce the Power Consumption with Remaining Data in SDRAM.

#define SDRAM_CR_PDWR_ManualRefresh						0x00000000UL					// When SDRAM is in Power Down Mode, User Refresh the SDRAM if the Data in SDRAM is wanted to Remain.
#define SDRAM_CR_PDWR_AutoRefresh						0x20000000UL					// When SDRAM is in Power Down Mode, EMIFx Module Refresh the SDRAM Automatically.

#define SDRAM_CR_NM_32bitMode							0x00000000UL					// 32bit SDRAM Data Length.
#define SDRAM_CR_NM_16bitMode							0x00004000UL					// 16bit SDRAM Data Length.

#define SDRAM_CR_CL_2EMIFxCLK							0x00000400UL					// 2EMIFxCLK Delay After CAS Signal.
#define SDRAM_CR_CL_3EMIFxCLK							0x00000600UL					// 3EMIFxCLK Delay After CAS Signal.

#define SDRAM_CR_CLLOCK_EALLOW							0x00000100UL					// CL bits of SDRAM_CR can be Written.

#define SDRAM_CR_IBANK_1Bank							0x00000000UL					// 1 Bank SDRAM Devices.
#define SDRAM_CR_IBANK_2Bank							0x00000010UL					// 2 Bank SDRAM Devices.
#define SDRAM_CR_IBANK_3Bank							0x00000020UL					// 3 Bank SDRAM Devices.

#define SDRAM_CR_PAGESIGE_8ColumnAddr					0x00000000UL					// 8 Column Address Bits for 256 Word Pages.
#define SDRAM_CR_PAGESIGE_9ColumnAddr					0x00000001UL					// 9 Column Address Bits for 512 Word Pages.
#define SDRAM_CR_PAGESIGE_10ColumnAddr					0x00000002UL					// 10 Column Address Bits for 1,024 Word Pages.
#define SDRAM_CR_PAGESIGE_11ColumnAddr					0x00000003UL					// 11 Column Address Bits for 2,048 Word Pages.

struct SDRAM_RCR_BITS {                 // bits description
    Uint16 REFRESH_RATE:13;             // 12:0 Refresh Rate.
    Uint16 rsvd1:3;                     // 15:13 Reserved
    Uint16 rsvd2:3;                     // 18:16 Reserved
    Uint16 rsvd3:13;                    // 31:19 Reserved
};

union SDRAM_RCR_REG {
    Uint32  all;
    struct  SDRAM_RCR_BITS  bit;
};

// SDRAM_RCR Register
//// SDRAM_RCR Register : Byte Value
#define SDRAM_RCR_REFRESH_RATE_Val(val)					(val & 0x00001FFFUL)			// SDRAM Refresh Rate = EMIF_RATE / REFRESH_RATE. When FR bit of RCSR is 1(Full Rate), EMIF_RATE = EMIFxCLK. When FR bit of RCSR is 0(Half Rate), EMIF_RATE = EMIFxCLK / 2.
																						// REFRESH_RATE < 0x0020 will Causes it to be Loaded with (2 * t_rfc) + 1 Value from SDRAM Timing Register.

struct ASYNC_CS2_CR_BITS {              // bits description
    Uint16 ASIZE:2;                     // 1:0 Asynchronous Memory Size.
    Uint16 TA:2;                        // 3:2 Turn Around cycles.
    Uint16 R_HOLD:3;                    // 6:4 Read Strobe Hold cycles.
    Uint16 R_STROBE:6;                  // 12:7 Read Strobe Duration cycles.
    Uint32 R_SETUP:4;                   // 16:13 Read Strobe Setup cycles.
    Uint16 W_HOLD:3;                    // 19:17 Write Strobe Hold cycles.
    Uint16 W_STROBE:6;                  // 25:20 Write Strobe Duration cycles.
    Uint16 W_SETUP:4;                   // 29:26 Write Strobe Setup cycles.
    Uint16 EW:1;                        // 30 Extend Wait mode.
    Uint16 SS:1;                        // 31 Select Strobe mode.
};

union ASYNC_CS2_CR_REG {
    Uint32  all;
    struct  ASYNC_CS2_CR_BITS  bit;
};

struct ASYNC_CS3_CR_BITS {              // bits description
    Uint16 ASIZE:2;                     // 1:0 Asynchronous Memory Size.
    Uint16 TA:2;                        // 3:2 Turn Around cycles.
    Uint16 R_HOLD:3;                    // 6:4 Read Strobe Hold cycles.
    Uint16 R_STROBE:6;                  // 12:7 Read Strobe Duration cycles.
    Uint32 R_SETUP:4;                   // 16:13 Read Strobe Setup cycles.
    Uint16 W_HOLD:3;                    // 19:17 Write Strobe Hold cycles.
    Uint16 W_STROBE:6;                  // 25:20 Write Strobe Duration cycles.
    Uint16 W_SETUP:4;                   // 29:26 Write Strobe Setup cycles.
    Uint16 EW:1;                        // 30 Extend Wait mode.
    Uint16 SS:1;                        // 31 Select Strobe mode.
};

union ASYNC_CS3_CR_REG {
    Uint32  all;
    struct  ASYNC_CS3_CR_BITS  bit;
};

struct ASYNC_CS4_CR_BITS {              // bits description
    Uint16 ASIZE:2;                     // 1:0 Asynchronous Memory Size.
    Uint16 TA:2;                        // 3:2 Turn Around cycles.
    Uint16 R_HOLD:3;                    // 6:4 Read Strobe Hold cycles.
    Uint16 R_STROBE:6;                  // 12:7 Read Strobe Duration cycles.
    Uint32 R_SETUP:4;                   // 16:13 Read Strobe Setup cycles.
    Uint16 W_HOLD:3;                    // 19:17 Write Strobe Hold cycles.
    Uint16 W_STROBE:6;                  // 25:20 Write Strobe Duration cycles.
    Uint16 W_SETUP:4;                   // 29:26 Write Strobe Setup cycles.
    Uint16 EW:1;                        // 30 Extend Wait mode.
    Uint16 SS:1;                        // 31 Select Strobe mode.
};

union ASYNC_CS4_CR_REG {
    Uint32  all;
    struct  ASYNC_CS4_CR_BITS  bit;
};

// ASYNC_CSx_CR Register
//// ASYNC_CSx_CR Register : Byte Value
#define ASYNC_CSx_CR_SS_ChipSelectMode					0x00000000UL								// /CS[x] pin is Active for SETUP/STROBE/HOLD Cycles.
#define ASYNC_CSx_CR_SS_SelectStrobeMode				0x80000000UL								// /CS[x] pin is only Active for STROBE Cycle.

#define ASYNC_CSx_CR_EW_EMxWAITDis						0x00000000UL								// EMxWAIT Pin and Extended Asynchronous Cycle are not Used.
#define ASYNC_CSx_CR_EW_EMxWAITEn						0x40000000UL								// EMxWAIT Pin and Extended Asynchronous Cycle are Used.

#define ASYNC_CSx_CR_W_SETUP_Clock(clk)					((((Uint32)clk - 1) & 0x0000000FUL) << 26)	// Number of EMIFxCLK for SETUP Cycle with Write Operation.
#define ASYNC_CSx_CR_W_STROBE_Clock(clk)				((((Uint32)clk - 1) & 0x0000003FUL) << 20)	// Number of EMIFxCLK for STROBE Cycle with Write Operation.
#define ASYNC_CSx_CR_W_HOLD_Clock(clk)					((((Uint32)clk - 1) & 0x00000007UL) << 17)	// Number of EMIFxCLK for HOLD Cycle with Write Operation.

#define ASYNC_CSx_CR_R_SETUP_Clock(clk)					((((Uint32)clk - 1) & 0x0000000FUL) << 13)	// Number of EMIFxCLK for SETUP Cycle with Read Operation.
#define ASYNC_CSx_CR_R_STROBE_Clock(clk)				((((Uint32)clk - 1) & 0x0000003FUL) << 7)	// Number of EMIFxCLK for STROBE Cycle with Read Operation.
#define ASYNC_CSx_CR_R_HOLD_Clock(clk)					((((Uint32)clk - 1) & 0x00000007UL) << 4)	// Number of EMIFxCLK for HOLD Cycle with Read Operation.

#define ASYNC_CSx_CR_TA_AcctoAccDelayClock(clk)			((((Uint32)clk - 1) & 0x00000003UL) << 2)	// Number of EMIFxCLK Between the End of One Async. Access and the Start of One Async. Access. This Delay is not Incurred Between a Read/Write Followed by a Read/Write to the Same Chip Select.

#define ASYNC_CSx_CR_ASIZE_8bitMode						0x00000000UL								// 8bit Data Length.
#define ASYNC_CSx_CR_ASIZE_16bitMode					0x00000001UL								// 16bit Data Length.
#define ASYNC_CSx_CR_ASIZE_32bitMode					0x00000002UL								// 32bit Data Length.

struct SDRAM_TR_BITS {                  // bits description
    Uint16 rsvd1:4;                     // 3:0 Reserved
    Uint16 T_RRD:3;                     // 6:4 Activate to Activate timing for different bank.
    Uint16 rsvd2:1;                     // 7 Reserved
    Uint16 T_RC:4;                      // 11:8 Activate to Activate timing .
    Uint16 T_RAS:4;                     // 15:12 Activate to Precharge timing.
    Uint16 T_WR:3;                      // 18:16 Last Write to Precharge timing.
    Uint16 rsvd3:1;                     // 19 Reserved
    Uint16 T_RCD:3;                     // 22:20 Activate to Read/Write timing.
    Uint16 rsvd4:1;                     // 23 Reserved
    Uint16 T_RP:3;                      // 26:24 Precharge to Activate/Refresh timing.
    Uint16 T_RFC:5;                     // 31:27 Refresh/Load Mode to Refresh/Activate timing
};

union SDRAM_TR_REG {
    Uint32  all;
    struct  SDRAM_TR_BITS  bit;
};

// SDRAM_TR Register
//// SDRAM_TR Register : Byte Value
#define SDRAM_TR_T_RFC_Clock(clk)						(((clk - 1) & 0x0000001FUL) << 27)	//
#define SDRAM_TR_T_RP_Clock(clk)						(((clk - 1) & 0x00000007UL) << 24)	//
#define SDRAM_TR_T_RCD_Clock(clk)						(((clk - 1) & 0x00000007UL) << 20)	//
#define SDRAM_TR_T_WR_Clock(clk)						(((clk - 1) & 0x00000007UL) << 16)	//
#define SDRAM_TR_T_RAS_Clock(clk)						(((clk - 1) & 0x0000000FUL) << 12)	//
#define SDRAM_TR_T_RC_Clock(clk)						(((clk - 1) & 0x0000000FUL) << 8)	//
#define SDRAM_TR_T_RRD_Clock(clk)						(((clk - 1) & 0x00000007UL) << 4)	//

struct SDR_EXT_TMNG_BITS {              // bits description
    Uint16 T_XS:5;                      // 4:0 Self Refresh exit to new command timing.
    Uint16 rsvd1:11;                    // 15:5 Reserved
    Uint16 rsvd2:16;                    // 31:16 Reserved
};

union SDR_EXT_TMNG_REG {
    Uint32  all;
    struct  SDR_EXT_TMNG_BITS  bit;
};

// SDR_EXT_TMNG Register
//// SDR_EXT_TMNG Register : Byte Value
#define SDR_EXT_TMNG_T_XS_Clock(clk)					((clk - 1) & 0x0000001FUL)		//

struct INT_RAW_BITS {                   // bits description
    Uint16 AT:1;                        // 0 Asynchronous Timeout.
    Uint16 LT:1;                        // 1 Line Trap.
    Uint16 WR:4;                        // 5:2 Wait Rise.
    Uint16 rsvd1:10;                    // 15:6 Reserved
    Uint16 rsvd2:16;                    // 31:16 Reserved
};

union INT_RAW_REG {
    Uint32  all;
    struct  INT_RAW_BITS  bit;
};

struct INT_MSK_BITS {                   // bits description
    Uint16 AT_MASKED:1;                 // 0 Asynchronous Timeout.
    Uint16 LT_MASKED:1;                 // 1 Line Trap.
    Uint16 WR_MASKED:4;                 // 5:2 Wait Rise.
    Uint16 rsvd1:10;                    // 15:6 Reserved
    Uint16 rsvd2:16;                    // 31:16 Reserved
};

union INT_MSK_REG {
    Uint32  all;
    struct  INT_MSK_BITS  bit;
};

// INT_RAW/INT_MSK Register
//// INT_RAW/INT_MSK Register : Byte Value
#define INT_RAW_MSK_WR0_EMxWAITINTClear					0x00000004UL					// Clear the Interrupt Generated by the Rising Edge of EMxWAIT. !!!!! (EMxWAIT0 or EMxWAIT of CS0 ?) !!!!!
#define INT_RAW_MSK_WR1_EMxWAITINTClear					0x00000008UL					// Clear the Interrupt Generated by the Rising Edge of EMxWAIT. !!!!! (EMxWAIT1 or EMxWAIT of CS1 ?) !!!!!
#define INT_RAW_MSK_WR2_EMxWAITINTClear					0x00000010UL					// Clear the Interrupt Generated by the Rising Edge of EMxWAIT. !!!!! (EMxWAIT2 or EMxWAIT of CS2 ?) !!!!!
#define INT_RAW_MSK_WR3_EMxWAITINTClear					0x00000020UL					// Clear the Interrupt Generated by the Rising Edge of EMxWAIT. !!!!! (EMxWAIT3 or EMxWAIT of CS3 ?) !!!!!

#define INT_RAW_MSK_LT_InvalidAddrINTClear				0x00000002UL					// Clear the Interrupt Generated by Illegal Memory Access Type or Invalid Cache Line Size.

#define INT_RAW_MSK_AT_AsynchTimeOutINTClear			0x00000001UL					// Clear the Interrupt Generated by Extended Asynchronous Memory Access Cycle Over the Maximum Cycle Defined by MAX_EXT_WAIT of ASYNC_WCCR.

struct INT_MSK_SET_BITS {               // bits description
    Uint16 AT_MASK_SET:1;               // 0 Asynchronous Timeout.
    Uint16 LT_MASK_SET:1;               // 1 Line Trap.
    Uint16 WR_MASK_SET:4;               // 5:2 Wait Rise.
    Uint16 rsvd1:10;                    // 15:6 Reserved
    Uint16 rsvd2:16;                    // 31:16 Reserved
};

union INT_MSK_SET_REG {
    Uint32  all;
    struct  INT_MSK_SET_BITS  bit;
};

// INT_MSK_SET Register
//// INT_MSK_SET Register : Byte Value
#define INT_MSK_SET_WR0_EMxWAITINTEn					0x00000004UL					// WR[0] Interrupt Enable.
#define INT_MSK_SET_WR1_EMxWAITINTEn					0x00000008UL					// WR[1] Interrupt Enable.
#define INT_MSK_SET_WR2_EMxWAITINTEn					0x00000010UL					// WR[2] Interrupt Enable.
#define INT_MSK_SET_WR3_EMxWAITINTEn					0x00000020UL					// WR[3] Interrupt Enable.

#define INT_MSK_SET_LT_InvalidAddrINTEn					0x00000002UL					// LT Interrupt Enable.

#define INT_MSK_SET_AT_AsynchTimeOutINTEn				0x00000001UL					// AT Interrupt Enable.

struct INT_MSK_CLR_BITS {               // bits description
    Uint16 AT_MASK_CLR:1;               // 0 Asynchronous Timeout.
    Uint16 LT_MASK_CLR:1;               // 1 Line Trap.
    Uint16 WR_MASK_CLR:4;               // 5:2 Wait Rise.
    Uint16 rsvd1:10;                    // 15:6 Reserved
    Uint16 rsvd2:16;                    // 31:16 Reserved
};

union INT_MSK_CLR_REG {
    Uint32  all;
    struct  INT_MSK_CLR_BITS  bit;
};

// INT_MSK_CLR Register
//// INT_MSK_CLR Register : Byte Value
#define INT_MSK_CLR_WR0_EMxWAITINTEn					0x00000004UL					// WR[0] Interrupt Disable.
#define INT_MSK_CLR_WR1_EMxWAITINTEn					0x00000008UL					// WR[1] Interrupt Disable.
#define INT_MSK_CLR_WR2_EMxWAITINTEn					0x00000010UL					// WR[2] Interrupt Disable.
#define INT_MSK_CLR_WR3_EMxWAITINTEn					0x00000020UL					// WR[3] Interrupt Disable.

#define INT_MSK_CLR_LT_InvalidAddrINTEn					0x00000002UL					// LT Interrupt Disable.

#define INT_MSK_CLR_AT_AsynchTimeOutINTEn				0x00000001UL					// AT Interrupt Disable.

struct EMIF_REGS {
    union   RCSR_REG                         RCSR;                         // Revision Code and Status Register
    union   ASYNC_WCCR_REG                   ASYNC_WCCR;                   // Async Wait Cycle Config Register
    union   SDRAM_CR_REG                     SDRAM_CR;                     // SDRAM (EMxCS0n) Config Register
    union   SDRAM_RCR_REG                    SDRAM_RCR;                    // SDRAM Refresh Control Register
    union   ASYNC_CS2_CR_REG                 ASYNC_CS2_CR;                 // Async 1 (EMxCS2n) Config Register
    union   ASYNC_CS3_CR_REG                 ASYNC_CS3_CR;                 // Async 2 (EMxCS3n) Config Register
    union   ASYNC_CS4_CR_REG                 ASYNC_CS4_CR;                 // Async 3 (EMxCS4n) Config Register
    Uint16                                   rsvd1[2];                     // Reserved
    union   SDRAM_TR_REG                     SDRAM_TR;                     // SDRAM Timing Register
    Uint16                                   rsvd2[6];                     // Reserved
    Uint32                                   TOTAL_SDRAM_AR;               // Total SDRAM Accesses Register
    Uint32                                   TOTAL_SDRAM_ACTR;             // Total SDRAM Activate Register
    Uint16                                   rsvd3[2];                     // Reserved
    union   SDR_EXT_TMNG_REG                 SDR_EXT_TMNG;                 // SDRAM SR/PD Exit Timing Register
    union   INT_RAW_REG                      INT_RAW;                      // Interrupt Raw Register
    union   INT_MSK_REG                      INT_MSK;                      // Interrupt Masked Register
    union   INT_MSK_SET_REG                  INT_MSK_SET;                  // Interrupt Mask Set Register
    union   INT_MSK_CLR_REG                  INT_MSK_CLR;                  // Interrupt Mask Clear Register
    Uint16                                   rsvd4[72];                    // Reserved
};

//---------------------------------------------------------------------------
// EMIF External References & Function Declarations:
//
#ifdef CPU1
extern volatile struct EMIF_REGS Emif1Regs;
extern volatile struct EMIF_REGS Emif2Regs;
#endif

#ifdef CPU2
extern volatile struct EMIF_REGS Emif1Regs;
#endif

#ifdef __cplusplus
}
#endif                                  /* extern "C" */

#endif

//===========================================================================
// End of file.
//===========================================================================
