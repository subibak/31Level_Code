//###########################################################################
//
// FILE:    F2837xD_epwm.h
//
// TITLE:   F2837xD Device EPWM Register Definitions.
//
//###########################################################################
// $TI Release: F2837xD Support Library v210 $
// $Release Date: Tue Nov  1 14:46:15 CDT 2016 $
// $Copyright: Copyright (C) 2013-2016 Texas Instruments Incorporated -
//             http://www.ti.com/ ALL RIGHTS RESERVED $
//###########################################################################

#ifndef __F2837xD_EPWM_H__
#define __F2837xD_EPWM_H__

#ifdef __cplusplus
extern "C" {
#endif


//---------------------------------------------------------------------------
// EPWM Individual Register Bit Definitions:

struct TBCTL_BITS {                     // bits description
    Uint16 CTRMODE:2;                   // 1:0 Counter Mode
    Uint16 PHSEN:1;                     // 2 Phase Load Enable
    Uint16 PRDLD:1;                     // 3 Active Period Load
    Uint16 SYNCOSEL:2;                  // 5:4 Sync Output Select
    Uint16 SWFSYNC:1;                   // 6 Software Force Sync Pulse
    Uint16 HSPCLKDIV:3;                 // 9:7 High Speed TBCLK Pre-scaler
    Uint16 CLKDIV:3;                    // 12:10 Time Base Clock Pre-scaler
    Uint16 PHSDIR:1;                    // 13 Phase Direction Bit
    Uint16 FREE_SOFT:2;                 // 15:14 Emulation Mode Bits
};

union TBCTL_REG {
    Uint16  all;
    struct  TBCTL_BITS  bit;
};

// TBCTL Register
//// TBCTL Register : Byte Value
#define TBCTL_FREESOFT_FreeRun								0x8000						// Free Run
#define TBCTL_FREESOFT_SoftStop								0x4000						// Stop When Counter Complete a Whole Cycle.
#define TBCTL_FREESOFT_Immediately							0x0000						// Stop After the Next Time-Base Counter Increment or Decrement.

#define TBCTL_PHSDIR_UpCountAfterSync						0x2000						// Counter Up After the Synchronization Event.
#define TBCTL_PHSDIR_DownCountAfterSync						0x0000						// Counter Down After the Synchronization Event.

#define TBCTL_CLKDIV_DIV128									0x1C00						// TBCLK = EPWMCLK / (HSPCLKDIV x CLKDIV)
#define TBCTL_CLKDIV_DIV64									0x1800
#define TBCTL_CLKDIV_DIV32									0x1400
#define TBCTL_CLKDIV_DIV16									0x1000
#define TBCTL_CLKDIV_DIV8									0x0C00
#define TBCTL_CLKDIV_DIV4									0x0800
#define TBCTL_CLKDIV_DIV2									0x0400
#define TBCTL_CLKDIV_DIV1									0x0000

#define TBCTL_HSPCLKDIV_DIV14								0x0380
#define TBCTL_HSPCLKDIV_DIV12								0x0300
#define TBCTL_HSPCLKDIV_DIV10								0x0280
#define TBCTL_HSPCLKDIV_DIV8								0x0200
#define TBCTL_HSPCLKDIV_DIV6								0x0180
#define TBCTL_HSPCLKDIV_DIV4								0x0100
#define TBCTL_HSPCLKDIV_DIV2								0x0080
#define TBCTL_HSPCLKDIV_DIV1								0x0000

#define TBCTL_SWFSYNC_SyncPulseGen							0x0040						// Forces A One-Time Synchronization Pulse to be Generated.

#define TBCTL_SYNCOSEL_SYNCOSELX							0x0030						// EPWMxSYNCO is Defined by TBCTL2[SYNCOSELX].
#define TBCTL_SYNCOSEL_CountCMPB							0x0020						// Time-Base Counter Equal to Counter-Compare B
#define TBCTL_SYNCOSEL_CountZero							0x0010						// Time-Base Counter Equal to Zero.
#define TBCTL_SYNCOSEL_EPWMxSYNC							0x0000						// EPWMxSYNCI or SWFSYNC

#define TBCTL_PRDLD_ShadowDisable							0x0008						// TBPRD Register Immediate Mode
#define TBCTL_PRDLD_ShadowEnable							0x0000						// TBPRD Register Shadow Mode

#define TBCTL_PHSEN_PhaseEnable								0x0004						// Allow Counter to be Loaded from the Phase Register.
#define TBCTL_PHSEN_PhaseDisable							0x0000						// Do not Load the Time-Base Counter from the Time-Base Phase Register.

#define TBCTL_CTRMODE_Freeze								0x0003						// Freeze Counter Operation
#define TBCTL_CTRMODE_UpDownCountMode						0x0002						// Up-Down Counter Mode
#define TBCTL_CTRMODE_DownCountMode							0x0001						// Down Counter Mode
#define TBCTL_CTRMODE_UpCountMode							0x0000						// Up Counter Mode

struct TBCTL2_BITS {                    // bits description
    Uint16 rsvd1:5;                     // 4:0 Reserved
    Uint16 SELFCLRTRREM:1;              // 5 Self clear Translator reminder
    Uint16 OSHTSYNCMODE:1;              // 6 One shot sync mode
    Uint16 OSHTSYNC:1;                  // 7 One shot sync
    Uint16 rsvd2:4;                     // 11:8 Reserved
    Uint16 SYNCOSELX:2;                 // 13:12 Syncout selection
    Uint16 PRDLDSYNC:2;                 // 15:14 PRD Shadow to Active Load on SYNC Event
};

union TBCTL2_REG {
    Uint16  all;
    struct  TBCTL2_BITS  bit;
};

// TBCTL2 Register
//// TBCTL2 Register : Byte Value
#define TBCTL2_PRDLDSYNC_LoadZero							0x0000						// Shadow to Active Load of TBPRD Occurs Only When TBCTR = 0.
#define TBCTL2_PRDLDSYNC_LoadZeroAndSYNC					0x4000						// Shadow to Active Load of TBPRD Occurs Both When TBCTR = 0 and When SYNC Occurs.
#define TBCTL2_PRDLDSYNC_SYNC								0x8000						// Shadow to Active Load of TBPRD Occurs Only When SYNC is Received.

#define TBCTL2_SYNCOSELX_Disable							0x0000						// Disable EPWMxSYNCO Sync Signal.
#define TBCTL2_SYNCOSELX_CountCMPC							0x1000						// EPWMxSYNCO = CMPC
#define TBCTL2_SYNCOSELX_CountCMPD							0x2000						// EPWMxSYNCO = CMPD

#define TBCTL2_OSHTSYNC_OneShotSync							0x0080						// Allow One Sync Pulse to Propagate.

#define TBCTL2_OSHTSYNCMODE_OneShotDisable					0x0000						// One-shot Sync Mode Disabled.
#define TBCTL2_OSHTSYNCMODE_OneShotEnable					0x0040						// One-shot Sync Mode Enabled.

struct TBSTS_BITS {                     // bits description
    Uint16 CTRDIR:1;                    // 0 Counter Direction Status
    Uint16 SYNCI:1;                     // 1 External Input Sync Status
    Uint16 CTRMAX:1;                    // 2 Counter Max Latched Status
    Uint16 rsvd1:13;                    // 15:3 Reserved
};

union TBSTS_REG {
    Uint16  all;
    struct  TBSTS_BITS  bit;
};

struct CMPCTL_BITS {                    // bits description
    Uint16 LOADAMODE:2;                 // 1:0 Active Compare A Load
    Uint16 LOADBMODE:2;                 // 3:2 Active Compare B Load
    Uint16 SHDWAMODE:1;                 // 4 Compare A Register Block Operating Mode
    Uint16 rsvd1:1;                     // 5 Reserved
    Uint16 SHDWBMODE:1;                 // 6 Compare B Register Block Operating Mode
    Uint16 rsvd2:1;                     // 7 Reserved
    Uint16 SHDWAFULL:1;                 // 8 Compare A Shadow Register Full Status
    Uint16 SHDWBFULL:1;                 // 9 Compare B Shadow Register Full Status
    Uint16 LOADASYNC:2;                 // 11:10 Active Compare A Load on SYNC
    Uint16 LOADBSYNC:2;                 // 13:12 Active Compare B Load on SYNC
    Uint16 rsvd3:2;                     // 15:14 Reserved
};

union CMPCTL_REG {
    Uint16  all;
    struct  CMPCTL_BITS  bit;
};

// CMPCTL Register
//// CMPCTL Register : Byte Value
#define CMPCTL_LOADBSYNC_SYNC								0x2000						// Shadow to Active Load of CMPB:COMPBHR Occurs Only When A SYNC is Received.
#define CMPCTL_LOADBSYNC_LOADBMODEAndSYNC					0x1000						// Shadow to Active Load of CMPB:COMPBHR Occurs Both According to LOADBMODE and When SYNC Occurs.
#define CMPCTL_LOADBSYNC_LOADBMODE							0x0000						// Shadow to Active Load of CMPB:COMPBHR Occurs According to LOADBMODE.

#define CMPCTL_LOADASYNC_SYNC								0x0800						// Shadow to Active Load of CMPA:COMPAHR Occurs Only When A SYNC is Received.
#define CMPCTL_LOADASYNC_LOADAMODEAndSYNC					0x0400						// Shadow to Active Load of CMPA:COMPAHR Occurs Both According to LOADAMODE and When SYNC Occurs.
#define CMPCTL_LOADASYNC_LOADAMODE							0x0000						// Shadow to Active Load of CMPA:COMPAHR Occurs According to LOADAMODE.

#define CMPCTL_SHDWBMODE_ShadowDisable						0x0040						// Immediate Mode.
#define CMPCTL_SHDWBMODE_ShadowEnable						0x0000						// Shadow Mode.

#define CMPCTL_SHDWAMODE_ShadowDisable						0x0010						// Immediate Mode.
#define CMPCTL_SHDWAMODE_ShadowEnable						0x0000						// Shadow Mode.

#define CMPCTL_LOADBMODE_Disable							0x000C						// Freeze(No Load Possible).
#define CMPCTL_LOADBMODE_LoadZeroPeriod						0x0008						// Load On CTR = Zero or CTR = PRD.
#define CMPCTL_LOADBMODE_LoadPeriod							0x0004						// Load On CTR = PRD.
#define CMPCTL_LOADBMODE_LoadZero							0x0000						// Load On CTR = Zero.

#define CMPCTL_LOADAMODE_Disable							0x0003						// Freeze(No Load Possible).
#define CMPCTL_LOADAMODE_LoadZeroPeriod						0x0002						// Load On CTR = Zero or CTR = PRD.
#define CMPCTL_LOADAMODE_LoadPeriod							0x0001						// Load On CTR = PRD.
#define CMPCTL_LOADAMODE_LoadZero							0x0000						// Load On CTR = Zero.

struct CMPCTL2_BITS {                   // bits description
    Uint16 LOADCMODE:2;                 // 1:0 Active Compare C Load
    Uint16 LOADDMODE:2;                 // 3:2 Active Compare D load
    Uint16 SHDWCMODE:1;                 // 4 Compare C Block Operating Mode
    Uint16 rsvd1:1;                     // 5 Reserved
    Uint16 SHDWDMODE:1;                 // 6 Compare D Block Operating Mode
    Uint16 rsvd2:3;                     // 9:7 Reserved
    Uint16 LOADCSYNC:2;                 // 11:10 Active Compare C Load on SYNC
    Uint16 LOADDSYNC:2;                 // 13:12 Active Compare D Load on SYNC
    Uint16 rsvd3:2;                     // 15:14 Reserved
};

union CMPCTL2_REG {
    Uint16  all;
    struct  CMPCTL2_BITS  bit;
};

// CMPCTL2 Register
//// CMPCTL2 Register : Byte Value
#define CMPCTL2_LOADDSYNC_SYNC								0x2000						// Shadow to Active Load of CMPB:COMPBHR Occurs Only When A SYNC is Received.
#define CMPCTL2_LOADDSYNC_LOADDMODEAndSYNC					0x1000						// Shadow to Active Load of CMPB:COMPBHR Occurs Both According to LOADBMODE and When SYNC Occurs.
#define CMPCTL2_LOADDSYNC_LOADDMODE							0x0000						// Shadow to Active Load of CMPB:COMPBHR Occurs According to LOADBMODE.

#define CMPCTL2_LOADCSYNC_SYNC								0x0800						// Shadow to Active Load of CMPA:COMPAHR Occurs Only When A SYNC is Received.
#define CMPCTL2_LOADCSYNC_LOADCMODEAndSYNC					0x0400						// Shadow to Active Load of CMPA:COMPAHR Occurs Both According to LOADAMODE and When SYNC Occurs.
#define CMPCTL2_LOADCSYNC_LOADCMODE							0x0000						// Shadow to Active Load of CMPA:COMPAHR Occurs According to LOADAMODE.

#define CMPCTL2_SHDWDMODE_ShadowDisable						0x0040						// Immediate Mode.
#define CMPCTL2_SHDWDMODE_ShadowEnable						0x0000						// Shadow Mode.

#define CMPCTL2_SHDWCMODE_ShadowDisable						0x0010						// Immediate Mode.
#define CMPCTL2_SHDWCMODE_ShadowEnable						0x0000						// Shadow Mode.

#define CMPCTL2_LOADDMODE_Disable							0x000C						// Freeze(No Load Possible).
#define CMPCTL2_LOADDMODE_LoadZeroPeriod					0x0008						// Load On CTR = Zero or CTR = PRD.
#define CMPCTL2_LOADDMODE_LoadPeriod						0x0004						// Load On CTR = PRD.
#define CMPCTL2_LOADDMODE_LoadZero							0x0000						// Load On CTR = Zero.

#define CMPCTL2_LOADCMODE_Disable							0x0003						// Freeze(No Load Possible).
#define CMPCTL2_LOADCMODE_LoadZeroPeriod					0x0002						// Load On CTR = Zero or CTR = PRD.
#define CMPCTL2_LOADCMODE_LoadPeriod						0x0001						// Load On CTR = PRD.
#define CMPCTL2_LOADCMODE_LoadZero							0x0000						// Load On CTR = Zero.

struct DBCTL_BITS {                     // bits description
    Uint16 OUT_MODE:2;                  // 1:0 Dead Band Output Mode Control
    Uint16 POLSEL:2;                    // 3:2 Polarity Select Control
    Uint16 IN_MODE:2;                   // 5:4 Dead Band Input Select Mode Control
    Uint16 LOADREDMODE:2;               // 7:6 Active DBRED Load Mode
    Uint16 LOADFEDMODE:2;               // 9:8 Active DBFED Load Mode
    Uint16 SHDWDBREDMODE:1;             // 10 DBRED Block Operating Mode
    Uint16 SHDWDBFEDMODE:1;             // 11 DBFED Block Operating Mode
    Uint16 OUTSWAP:2;                   // 13:12 Dead Band Output Swap Control
    Uint16 DEDB_MODE:1;                 // 14 Dead Band Dual-Edge B Mode Control
    Uint16 HALFCYCLE:1;                 // 15 Half Cycle Clocking Enable
};

union DBCTL_REG {
    Uint16  all;
    struct  DBCTL_BITS  bit;
};

// DBCTL Register
//// DBCTL Register : Byte Value
#define DBCTL_HALFCYCLE_2TBCLK								0x8000						// Dead Band Counters are Clocked at TBCLK x 2.
#define DBCTL_HALFCYCLE_TBCLK								0x0000						// Dead Band Counters are Clocked at TBCLK Rate.

#define DBCTL_DEDB_MODE_REDFEDCascaded						0x4000						// RED Source is Defined by INMODE. FED Source is Output of RED. Only FED Output is available. RED Output is not Used for A or B-PATH.
#define DBCTL_DEDB_MODE_REDFEDNormal						0x0000						// RED and FED Sources are Defined by INMODE.

#define DBCTL_OUTSWAP_ABSwapped								0x3000						// OUT-A = B-PATH, OUT-B = A-PATH
#define DBCTL_OUTSWAP_AOutput								0x2000						// OUT-A = A-PATH, OUT-B = A-PATH
#define DBCTL_OUTSWAP_BOutput								0x1000						// OUT-A = B-PATH, OUT-B = B-PATH
#define DBCTL_OUTSWAP_ABNormal								0x0000						// OUT-A = A-PATH, OUT-B = B-PATH

#define DBCTL_SHDWDBFEDMODE_ShadowEnable					0x0800						// Shadow Mode.
#define DBCTL_SHDWDBFEDMODE_ShadowDisable					0x0000						// Immediate Mode.

#define DBCTL_SHDWDBREDMODE_ShadowEnable					0x0400						// Shadow Mode.
#define DBCTL_SHDWDBREDMODE_ShadowDisable					0x0000						// Immediate Mode.

#define DBCTL_LOADFEDMODE_Disable							0x0300						// Freeze(No Load Possible).
#define DBCTL_LOADFEDMODE_LoadZeroPeriod					0x0200						// Load On Counter = Zero or Counter = Period.
#define DBCTL_LOADFEDMODE_LoadPeriod						0x0100						// Load On Counter = Period.
#define DBCTL_LOADFEDMODE_LoadZero							0x0000						// Load On Counter = Zero.

#define DBCTL_LOADREDMODE_Disable							0x00C0						// Freeze(No Load Possible).
#define DBCTL_LOADREDMODE_LoadZeroPeriod					0x0080						// Load On Counter = Zero or Counter = Period.
#define DBCTL_LOADREDMODE_LoadPeriod						0x0040						// Load On Counter = Period.
#define DBCTL_LOADREDMODE_LoadZero							0x0000						// Load On Counter = Zero.

#define DBCTL_INMODE_BBoth									0x0030						// EPWMxB IN - Rising and Falling Edge Delay.
#define DBCTL_INMODE_ARising_BFalling						0x0020						// EPWMxA IN - Rising Edge Delay, EPWMxB IN - Falling Edge Delay.
#define DBCTL_INMODE_AFalling_BRising						0x0010						// EPWMxB IN - Rising Edge Delay, EPWMxA IN - Falling Edge Delay.
#define DBCTL_INMODE_ABoth									0x0000						// EPWMxA IN - Rising and Falling Edge Delay.

#define DBCTL_POLSEL_ACTVHigh								0x0008						// Active High Complementary (AHC) Mode. EPWMxB is Inverted.
#define DBCTL_POLSEL_ACTVLow								0x0004						// Active Low Complementary (ALC) Mode. EPWMxA is Inverted.
#define DBCTL_POLSEL_ABInvert								0x000C						// Active Low (AL) Mode. Both EPWMxA and EPWMxB are Inverted.
#define DBCTL_POLSEL_ABypass_BInvert						0x0008						// Active High Complementary (AHC) Mode. EPWMxB is Inverted.
#define DBCTL_POLSEL_AInvert_BBypass						0x0004						// Active Low Complementary (ALC) Mode. EPWMxA is Inverted.
#define DBCTL_POLSEL_ABBypass								0x0000						// Active High (AH) Mode. Neither EPWMAxA nor EPWMxB is Inverted.

#define DBCTL_OUTMODE_DBABEnable							0x0003						// DBM is Fully Enabled.
#define DBCTL_OUTMODE_DBAEnable								0x0002						// A-Path = RED, B-Path = IN-B.
#define DBCTL_OUTMODE_DBBEnable								0x0001						// A-Path = IN-A, B-Path = FED.
#define DBCTL_OUTMODE_DBABDisable							0x0000						// DBM is Fully Disabled or By-Passed. POLSEL and IN-MODE Have No Effect.

struct DBCTL2_BITS {                    // bits description
    Uint16 LOADDBCTLMODE:2;             // 1:0 DBCTL Load from Shadow Mode Select
    Uint16 SHDWDBCTLMODE:1;             // 2 DBCTL Load mode Select
    Uint16 rsvd1:13;                    // 15:3 Reserved
};

union DBCTL2_REG {
    Uint16  all;
    struct  DBCTL2_BITS  bit;
};

// DBCTL2 Register
//// DBCTL2 Register : Byte Value
#define DBCTL2_SHDWDBCTLMODE_ShadowEnable					0x0004						// Shadow Mode.
#define DBCTL2_SHDWDBCTLMODE_ShadowDisable					0x0000						// Immediate Mode.

#define DBCTL2_LOADDBCTLMODE_Disable						0x0003						// Freeze(No Load Possible).
#define DBCTL2_LOADDBCTLMODE_LoadZeroPeriod					0x0002						// Load On Either Counter = Zero or Counter = Period.
#define DBCTL2_LOADDBCTLMODE_LoadPeriod						0x0001						// Load On Counter = Period.
#define DBCTL2_LOADDBCTLMODE_LoadZero						0x0000						// Load On Counter = Zero.


struct AQCTL_BITS {                     // bits description
    Uint16 LDAQAMODE:2;                 // 1:0 Action Qualifier A Load Select
    Uint16 LDAQBMODE:2;                 // 3:2 Action Qualifier B Load Select
    Uint16 SHDWAQAMODE:1;               // 4 Action Qualifer A Operating Mode
    Uint16 rsvd1:1;                     // 5 Reserved
    Uint16 SHDWAQBMODE:1;               // 6 Action Qualifier B Operating Mode
    Uint16 rsvd2:1;                     // 7 Reserved
    Uint16 LDAQASYNC:2;                 // 9:8 AQCTLA Register Load on SYNC
    Uint16 LDAQBSYNC:2;                 // 11:10 AQCTLB Register Load on SYNC
    Uint16 rsvd3:4;                     // 15:12 Reserved
};

union AQCTL_REG {
    Uint16  all;
    struct  AQCTL_BITS  bit;
};

// AQCTL Register
//// AQCTL Register : Byte Value
#define AQCTL_LDAQBSYNC_SYNC								0x0800						// Shadow to Active Load of AQCTLB Occurs Only When A SYNC is Received.
#define AQCTL_LDAQBSYNC_LDAQBMODEAndSYNC					0x0400						// Shadow to Active Load of AQCTLB Occurs Both According to LDAQBMODE and When SYNC Occurs.
#define AQCTL_LDAQBSYNC_LDAQBMODE							0x0000						// Shadow to Active Load of AQCTLB Occurs According to LDAQBMODE.

#define AQCTL_LDAQASYNC_SYNC								0x0200						// Shadow to Active Load of AQCTLA Occurs Only When A SYNC is Received.
#define AQCTL_LDAQASYNC_LDAQAMODEAndSYNC					0x0100						// Shadow to Active Load of AQCTLA Occurs Both According to LDAQBMODE and When SYNC Occurs.
#define AQCTL_LDAQASYNC_LDAQAMODE							0x0000						// Shadow to Active Load of AQCTLA Occurs According to LDAQBMODE.

#define AQCTL_SHDWAQBMODE_ShadowEnable						0x0040						// Shadow Mode.
#define AQCTL_SHDWAQBMODE_ShadowDisable						0x0000						// Immediate Mode.

#define AQCTL_SHDWAQAMODE_ShadowEnable						0x0010						// Shadow Mode.
#define AQCTL_SHDWAQAMODE_ShadowDisable						0x0000						// Immediate Mode.

#define AQCTL_LDAQBMODE_Disable								0x000C						// Freeze(No Load Possible).
#define AQCTL_LDAQBMODE_LoadZeroPeriod						0x0008						// Load On Either CTR = Zero or CTR = PRD.
#define AQCTL_LDAQBMODE_LoadPeriod							0x0004						// Load On CTR = PRD.
#define AQCTL_LDAQBMODE_LoadZero							0x0000						// Load On CTR = Zero.

#define AQCTL_LDAQAMODE_Disable								0x0003						// Freeze(No Load Possible).
#define AQCTL_LDAQAMODE_LoadZeroPeriod						0x0002						// Load On Either CTR = Zero or CTR = PRD.
#define AQCTL_LDAQAMODE_LoadPeriod							0x0001						// Load On CTR = PRD.
#define AQCTL_LDAQAMODE_LoadZero							0x0000						// Load On CTR = Zero.

struct AQTSRCSEL_BITS {                 // bits description
    Uint16 T1SEL:4;                     // 3:0 T1 Event Source Select Bits
    Uint16 T2SEL:4;                     // 7:4 T2 Event Source Select Bits
    Uint16 rsvd1:8;                     // 15:8 Reserved
};

union AQTSRCSEL_REG {
    Uint16  all;
    struct  AQTSRCSEL_BITS  bit;
};

// AQTSRCSEL Register
//// AQTSRCSEL Register : Byte Value
#define AQTSRCSEL_T2SEL_EPWMxSYNCI							0x0070
#define AQTSRCSEL_T2SEL_TZ3									0x0060
#define AQTSRCSEL_T2SEL_TZ2									0x0050
#define AQTSRCSEL_T2SEL_TZ1									0x0040
#define AQTSRCSEL_T2SEL_DCBEVT2								0x0030
#define AQTSRCSEL_T2SEL_DCBEVT1								0x0020
#define AQTSRCSEL_T2SEL_DCAEVT2								0x0010
#define AQTSRCSEL_T2SEL_DCAEVT1								0x0000

#define AQTSRCSEL_T1SEL_EPWMxSYNCI							0x0007
#define AQTSRCSEL_T1SEL_TZ3									0x0006
#define AQTSRCSEL_T1SEL_TZ2									0x0005
#define AQTSRCSEL_T1SEL_TZ1									0x0004
#define AQTSRCSEL_T1SEL_DCBEVT2								0x0003
#define AQTSRCSEL_T1SEL_DCBEVT1								0x0002
#define AQTSRCSEL_T1SEL_DCAEVT2								0x0001
#define AQTSRCSEL_T1SEL_DCAEVT1								0x0000

struct PCCTL_BITS {                     // bits description
    Uint16 CHPEN:1;                     // 0 PWM chopping enable
    Uint16 OSHTWTH:4;                   // 4:1 One-shot pulse width
    Uint16 CHPFREQ:3;                   // 7:5 Chopping clock frequency
    Uint16 CHPDUTY:3;                   // 10:8 Chopping clock Duty cycle
    Uint16 rsvd1:5;                     // 15:11 Reserved
};

union PCCTL_REG {
    Uint16  all;
    struct  PCCTL_BITS  bit;
};

// PCCTL Register
//// PCCTL Register : Byte Value
#define PCCTL_CHPDUTY_87P5Percent							0x0600						// Duty = 1/8 (12.5%).
#define PCCTL_CHPDUTY_75P0Percent							0x0500						// Duty = 2/8 (25.0%).
#define PCCTL_CHPDUTY_62P5Percent							0x0400						// Duty = 3/8 (37.5%).
#define PCCTL_CHPDUTY_50P0Percent							0x0300						// Duty = 4/8 (50.0%).
#define PCCTL_CHPDUTY_37P5Percent							0x0200						// Duty = 5/8 (62.5%).
#define PCCTL_CHPDUTY_25P0Percent							0x0100						// Duty = 6/8 (75.0%).
#define PCCTL_CHPDUTY_12P5Percent							0x0000						// Duty = 7/8 (87.5%).

#define PCCTL_CHPFREQ_DIV64									0x00E0						// CHPCLK = TBCLK / 64.
#define PCCTL_CHPFREQ_DIV56									0x00C0						// CHPCLK = TBCLK / 56.
#define PCCTL_CHPFREQ_DIV48									0x00A0						// CHPCLK = TBCLK / 48.
#define PCCTL_CHPFREQ_DIV40									0x0080						// CHPCLK = TBCLK / 40.
#define PCCTL_CHPFREQ_DIV32									0x0060						// CHPCLK = TBCLK / 32.
#define PCCTL_CHPFREQ_DIV24									0x0040						// CHPCLK = TBCLK / 24.
#define PCCTL_CHPFREQ_DIV16									0x0020						// CHPCLK = TBCLK / 16.
#define PCCTL_CHPFREQ_DIV8									0x0000						// CHPCLK = TBCLK / 8.

#define PCCTL_OSHTWTH_128TBCLK								0x001E						// One-Shot Pulse Width = 16 x TBCLK / 8.
#define PCCTL_OSHTWTH_120TBCLK								0x001C						// One-Shot Pulse Width = 15 x TBCLK / 8.
#define PCCTL_OSHTWTH_112TBCLK								0x001A						// One-Shot Pulse Width = 14 x TBCLK / 8.
#define PCCTL_OSHTWTH_104TBCLK								0x0018						// One-Shot Pulse Width = 13 x TBCLK / 8.
#define PCCTL_OSHTWTH_96TBCLK								0x0016						// One-Shot Pulse Width = 12 x TBCLK / 8.
#define PCCTL_OSHTWTH_88TBCLK								0x0014						// One-Shot Pulse Width = 11 x TBCLK / 8.
#define PCCTL_OSHTWTH_80TBCLK								0x0012						// One-Shot Pulse Width = 10 x TBCLK / 8.
#define PCCTL_OSHTWTH_72TBCLK								0x0010						// One-Shot Pulse Width = 9 x TBCLK / 8.
#define PCCTL_OSHTWTH_64TBCLK								0x000E						// One-Shot Pulse Width = 8 x TBCLK / 8.
#define PCCTL_OSHTWTH_56TBCLK								0x000C						// One-Shot Pulse Width = 7 x TBCLK / 8.
#define PCCTL_OSHTWTH_48TBCLK								0x000A						// One-Shot Pulse Width = 6 x TBCLK / 8.
#define PCCTL_OSHTWTH_40TBCLK								0x0008						// One-Shot Pulse Width = 5 x TBCLK / 8.
#define PCCTL_OSHTWTH_32TBCLK								0x0006						// One-Shot Pulse Width = 4 x TBCLK / 8.
#define PCCTL_OSHTWTH_24TBCLK								0x0004						// One-Shot Pulse Width = 3 x TBCLK / 8.
#define PCCTL_OSHTWTH_16TBCLK								0x0002						// One-Shot Pulse Width = 2 x TBCLK / 8.
#define PCCTL_OSHTWTH_8TBCLK								0x0000						// One-Shot Pulse Width = 1 x TBCLK / 8.

#define PCCTL_CHPEN_Enable									0x0001						// Enable Chopping Function.
#define PCCTL_CHPEN_Disable									0x0000						// Disable PWM Chopping Function.

struct HRCNFG_BITS {                    // bits description
    Uint16 EDGMODE:2;                   // 1:0 ePWMxA Edge Mode Select Bits
    Uint16 CTLMODE:1;                   // 2 ePWMxA Control Mode Select Bits
    Uint16 HRLOAD:2;                    // 4:3 ePWMxA Shadow Mode Select Bits
    Uint16 SELOUTB:1;                   // 5 EPWMB Output Selection Bit
    Uint16 AUTOCONV:1;                  // 6 Autoconversion Bit
    Uint16 SWAPAB:1;                    // 7 Swap EPWMA and EPWMB Outputs Bit
    Uint16 EDGMODEB:2;                  // 9:8 ePWMxB Edge Mode Select Bits
    Uint16 CTLMODEB:1;                  // 10 ePWMxB Control Mode Select Bits
    Uint16 HRLOADB:2;                   // 12:11 ePWMxB Shadow Mode Select Bits
    Uint16 rsvd1:1;                     // 13 Reserved
    Uint16 rsvd2:2;                     // 15:14 Reserved
};

union HRCNFG_REG {
    Uint16  all;
    struct  HRCNFG_BITS  bit;
};

struct HRPWR_BITS {                     // bits description
    Uint16 rsvd1:2;                     // 1:0 Reserved
    Uint16 rsvd2:1;                     // 2 Reserved
    Uint16 rsvd3:1;                     // 3 Reserved
    Uint16 rsvd4:1;                     // 4 Reserved
    Uint16 rsvd5:1;                     // 5 Reserved
    Uint16 rsvd6:4;                     // 9:6 Reserved
    Uint16 rsvd7:5;                     // 14:10 Reserved
    Uint16 CALPWRON:1;                  // 15 Calibration Power On
};

union HRPWR_REG {
    Uint16  all;
    struct  HRPWR_BITS  bit;
};

struct HRMSTEP_BITS {                   // bits description
    Uint16 HRMSTEP:8;                   // 7:0 High Resolution Micro Step Value
    Uint16 rsvd1:8;                     // 15:8 Reserved
};

union HRMSTEP_REG {
    Uint16  all;
    struct  HRMSTEP_BITS  bit;
};

struct HRCNFG2_BITS {                   // bits description
    Uint16 EDGMODEDB:2;                 // 1:0 Dead-Band Edge-Mode Select Bits
    Uint16 CTLMODEDBRED:2;              // 3:2 DBRED Control Mode Select Bits
    Uint16 CTLMODEDBFED:2;              // 5:4 DBFED Control Mode Select Bits
    Uint16 rsvd1:8;                     // 13:6 Reserved
    Uint16 rsvd2:1;                     // 14 Reserved
    Uint16 rsvd3:1;                     // 15 Reserved
};

union HRCNFG2_REG {
    Uint16  all;
    struct  HRCNFG2_BITS  bit;
};

struct HRPCTL_BITS {                    // bits description
    Uint16 HRPE:1;                      // 0 High Resolution Period Enable
    Uint16 PWMSYNCSEL:1;                // 1 PWMSYNC Source Select 
    Uint16 TBPHSHRLOADE:1;              // 2 TBPHSHR Load Enable 
    Uint16 rsvd1:1;                     // 3 Reserved
    Uint16 PWMSYNCSELX:3;               // 6:4 PWMSYNCX Source Select Bit: 
    Uint16 rsvd2:9;                     // 15:7 Reserved
};

union HRPCTL_REG {
    Uint16  all;
    struct  HRPCTL_BITS  bit;
};

struct TRREM_BITS {                     // bits description
    Uint16 TRREM:11;                    // 10:0 Translator Remainder Bits
    Uint16 rsvd1:5;                     // 15:11 Reserved
};

union TRREM_REG {
    Uint16  all;
    struct  TRREM_BITS  bit;
};

struct GLDCTL_BITS {                    // bits description
    Uint16 GLD:1;                       // 0 Global Shadow to Active load event control
    Uint16 GLDMODE:4;                   // 4:1 Shadow to Active Global Load Pulse Selection
    Uint16 OSHTMODE:1;                  // 5 One Shot Load mode control bit
    Uint16 rsvd1:1;                     // 6 Reserved
    Uint16 GLDPRD:3;                    // 9:7 Global Reload Strobe Period Select Register
    Uint16 GLDCNT:3;                    // 12:10 Global Reload Strobe Counter Register
    Uint16 rsvd2:3;                     // 15:13 Reserved
};

union GLDCTL_REG {
    Uint16  all;
    struct  GLDCTL_BITS  bit;
};

// GLDCTL Register
//// GLDCTL Register : Byte Value
#define GLDCTL_GLDPRD_7thEVT								0x0380						// Generate Strobe On GLDCNT = 1.
#define GLDCTL_GLDPRD_6thEVT								0x0300						// Generate Strobe On GLDCNT = 1.
#define GLDCTL_GLDPRD_5thEVT								0x0280						// Generate Strobe On GLDCNT = 1.
#define GLDCTL_GLDPRD_4thEVT								0x0200						// Generate Strobe On GLDCNT = 1.
#define GLDCTL_GLDPRD_3rdEVT								0x0180						// Generate Strobe On GLDCNT = 1.
#define GLDCTL_GLDPRD_2ndEVT								0x0100						// Generate Strobe On GLDCNT = 1.
#define GLDCTL_GLDPRD_1stEVT								0x0080						// Generate Strobe On GLDCNT = 1.
#define GLDCTL_GLDPRD_Disable								0x0000						// Disable Counter.

#define GLDCTL_OSHTMODE_OneShotMode							0x0020						// One Shot Mode is Active. All Load Strobes are Blocked Until GLDCTL2[OSHTLD] is Written with 1.
#define GLDCTL_OSHTMODE_ContinueMode						0x0000						// One Shot Mode is Disable and Shadow to Active Loading Happens Continuously on All the Chosen Load Strobes.

#define GLDCTL_GLDMODE_GLDCTL2_GFRCLD						0x001E						// Load On GLDCTL2[GFRCLD] Write.
#define GLDCTL_GLDMODE_SYNCEVTAndLoadZeroPeriod				0x000C						// Load On SYNCEVT or Counter = Zero or Counter = Period.
#define GLDCTL_GLDMODE_SYNCEVTAndLoadPeriod					0x000A						// Load On SYNCEVT or Counter = Period.
#define GLDCTL_GLDMODE_SYNCEVTAndLoadZero					0x0008						// Load On SYNCEVT or Counter = Zero.
#define GLDCTL_GLDMODE_SYNCEVT								0x0006						// Load On SYNCEVT Which is Logical OR of DCAEVT1.SYNC, DCBEVT1.SYNC, EPWMxSYNCI and TBCTL[SWFSYNC].
#define GLDCTL_GLDMODE_LoadZeroPeriod						0x0004						// Load On Either Counter = 0 or Counter = Period.
#define GLDCTL_GLDMODE_LoadPeriod							0x0002						// Load On Counter = Period.
#define GLDCTL_GLDMODE_LoadZero								0x0000						// Load On Counter = Zero.

#define GLDCTL_GLD_GlobalShadowEnable						0x0001						// The Shadow to Active Reload Events are Defined by GLDCTL[GLDMODE]. All The Shadow Registers Used Same Reload Pulse From Shadow to Active Reloading. Individual LOADMODEs are Ignored.
#define GLDCTL_GLD_IndividualShadowEnable					0x0000						// Shadow to Active Reload for All Shadowed Registers Happens as Per the Individual Reload Control Bits Specified.

struct GLDCFG_BITS {                    // bits description
    Uint16 TBPRD_TBPRDHR:1;             // 0 Global load event configuration for TBPRD:TBPRDHR 
    Uint16 CMPA_CMPAHR:1;               // 1 Global load event configuration for CMPA:CMPAHR 
    Uint16 CMPB_CMPBHR:1;               // 2 Global load event configuration for CMPB:CMPBHR 
    Uint16 CMPC:1;                      // 3 Global load event configuration for CMPC 
    Uint16 CMPD:1;                      // 4 Global load event configuration for CMPD 
    Uint16 DBRED_DBREDHR:1;             // 5 Global load event configuration for DBRED:DBREDHR 
    Uint16 DBFED_DBFEDHR:1;             // 6 Global load event configuration for DBFED:DBFEDHR
    Uint16 DBCTL:1;                     // 7 Global load event configuration for DBCTL
    Uint16 AQCTLA_AQCTLA2:1;            // 8 Global load event configuration for AQCTLA/A2 
    Uint16 AQCTLB_AQCTLB2:1;            // 9 Global load event configuration for AQCTLB/B2 
    Uint16 AQCSFRC:1;                   // 10 Global load event configuration for AQCSFRC 
    Uint16 rsvd1:5;                     // 15:11 Reserved
};

union GLDCFG_REG {
    Uint16  all;
    struct  GLDCFG_BITS  bit;
};

// GLDCFG Register
//// GLDCFG Register : Byte Value
#define GLDCFG_AQCSFRC_GlobalLoad							0x0400						// Registers Use Global Reload Configuration If This Bit is Set and GLDCTL[GLD] = 1.
#define GLDCFG_AQCSFRC_LocalLoad							0x0000						// Registers Use Local Reload Configuration Even If GLDCTL[GLD] = 1.

#define GLDCFG_AQCTLB_AQCTLB2_GlobalLoad					0x0200						// Registers Use Global Reload Configuration If This Bit is Set and GLDCTL[GLD] = 1.
#define GLDCFG_AQCTLB_AQCTLB2_LocalLoad						0x0000						// Registers Use Local Reload Configuration Even If GLDCTL[GLD] = 1.

#define GLDCFG_AQCTLA_AQCTLA2_GlobalLoad					0x0100						// Registers Use Global Reload Configuration If This Bit is Set and GLDCTL[GLD] = 1.
#define GLDCFG_AQCTLA_AQCTLA2_LocalLoad						0x0000						// Registers Use Local Reload Configuration Even If GLDCTL[GLD] = 1.

#define GLDCFG_DBCTL_GlobalLoad								0x0080						// Registers Use Global Reload Configuration If This Bit is Set and GLDCTL[GLD] = 1.
#define GLDCFG_DBCTL_LocalLoad								0x0000						// Registers Use Local Reload Configuration Even If GLDCTL[GLD] = 1.

#define GLDCFG_DBFED_DBFEDHR_GlobalLoad						0x0040						// Registers Use Global Reload Configuration If This Bit is Set and GLDCTL[GLD] = 1.
#define GLDCFG_DBFED_DBFEDHR_LocalLoad						0x0000						// Registers Use Local Reload Configuration Even If GLDCTL[GLD] = 1.

#define GLDCFG_DBRED_DBREDHR_GlobalLoad						0x0020						// Registers Use Global Reload Configuration If This Bit is Set and GLDCTL[GLD] = 1.
#define GLDCFG_DBRED_DBREDHR_LocalLoad						0x0000						// Registers Use Local Reload Configuration Even If GLDCTL[GLD] = 1.

#define GLDCFG_CMPD_GlobalLoad								0x0010						// Registers Use Global Reload Configuration If This Bit is Set and GLDCTL[GLD] = 1.
#define GLDCFG_CMPD_LocalLoad								0x0000						// Registers Use Local Reload Configuration Even If GLDCTL[GLD] = 1.

#define GLDCFG_CMPC_GlobalLoad								0x0008						// Registers Use Global Reload Configuration If This Bit is Set and GLDCTL[GLD] = 1.
#define GLDCFG_CMPC_LocalLoad								0x0000						// Registers Use Local Reload Configuration Even If GLDCTL[GLD] = 1.

#define GLDCFG_CMPB_CMPBHR_GlobalLoad						0x0004						// Registers Use Global Reload Configuration If This Bit is Set and GLDCTL[GLD] = 1.
#define GLDCFG_CMPB_CMPBHR_LocalLoad						0x0000						// Registers Use Local Reload Configuration Even If GLDCTL[GLD] = 1.

#define GLDCFG_CMPA_CMPAHR_GlobalLoad						0x0002						// Registers Use Global Reload Configuration If This Bit is Set and GLDCTL[GLD] = 1.
#define GLDCFG_CMPA_CMPAHR_LocalLoad						0x0000						// Registers Use Local Reload Configuration Even If GLDCTL[GLD] = 1.

#define GLDCFG_TBPRD_TBPRDHR_GlobalLoad						0x0001						// Registers Use Global Reload Configuration If This Bit is Set and GLDCTL[GLD] = 1.
#define GLDCFG_TBPRD_TBPRDHR_LocalLoad						0x0000						// Registers Use Local Reload Configuration Even If GLDCTL[GLD] = 1.

struct EPWMXLINK_BITS {                 // bits description
    Uint16 TBPRDLINK:4;                 // 3:0 TBPRD:TBPRDHR  Link 
    Uint16 CMPALINK:4;                  // 7:4 CMPA:CMPAHR Link 
    Uint16 CMPBLINK:4;                  // 11:8 CMPB:CMPBHR Link
    Uint16 CMPCLINK:4;                  // 15:12 CMPC Link
    Uint16 CMPDLINK:4;                  // 19:16 CMPD Link
    Uint16 rsvd1:8;                     // 27:20 Reserved
    Uint16 GLDCTL2LINK:4;               // 31:28 GLDCTL2 Link
};

union EPWMXLINK_REG {
    Uint32  all;
    struct  EPWMXLINK_BITS  bit;
};

// EPWMXLINK Register
//// EPWMXLINK Register : Byte Value
#define EPWMXLINK_GLDCTL2LINK_WithEPWM12					0xB0000000UL				// ePWM12
#define EPWMXLINK_GLDCTL2LINK_WithEPWM11					0xA0000000UL				// ePWM11
#define EPWMXLINK_GLDCTL2LINK_WithEPWM10					0x90000000UL				// ePWM10
#define EPWMXLINK_GLDCTL2LINK_WithEPWM9						0x80000000UL				// ePWM9
#define EPWMXLINK_GLDCTL2LINK_WithEPWM8						0x70000000UL				// ePWM8
#define EPWMXLINK_GLDCTL2LINK_WithEPWM7						0x60000000UL				// ePWM7
#define EPWMXLINK_GLDCTL2LINK_WithEPWM6						0x50000000UL				// ePWM6
#define EPWMXLINK_GLDCTL2LINK_WithEPWM5						0x40000000UL				// ePWM5
#define EPWMXLINK_GLDCTL2LINK_WithEPWM4						0x30000000UL				// ePWM4
#define EPWMXLINK_GLDCTL2LINK_WithEPWM3						0x20000000UL				// ePWM3
#define EPWMXLINK_GLDCTL2LINK_WithEPWM2						0x10000000UL				// ePWM2
#define EPWMXLINK_GLDCTL2LINK_WithEPWM1						0x00000000UL				// ePWM1

#define EPWMXLINK_CMPDLINK_WithEPWM12						0x000B0000UL				// ePWM12
#define EPWMXLINK_CMPDLINK_WithEPWM11						0x000A0000UL				// ePWM11
#define EPWMXLINK_CMPDLINK_WithEPWM10						0x00090000UL				// ePWM10
#define EPWMXLINK_CMPDLINK_WithEPWM9						0x00080000UL				// ePWM9
#define EPWMXLINK_CMPDLINK_WithEPWM8						0x00070000UL				// ePWM8
#define EPWMXLINK_CMPDLINK_WithEPWM7						0x00060000UL				// ePWM7
#define EPWMXLINK_CMPDLINK_WithEPWM6						0x00050000UL				// ePWM6
#define EPWMXLINK_CMPDLINK_WithEPWM5						0x00040000UL				// ePWM5
#define EPWMXLINK_CMPDLINK_WithEPWM4						0x00030000UL				// ePWM4
#define EPWMXLINK_CMPDLINK_WithEPWM3						0x00020000UL				// ePWM3
#define EPWMXLINK_CMPDLINK_WithEPWM2						0x00010000UL				// ePWM2
#define EPWMXLINK_CMPDLINK_WithEPWM1						0x00000000UL				// ePWM1

#define EPWMXLINK_CMPCLINK_WithEPWM12						0x0000B000UL				// ePWM12
#define EPWMXLINK_CMPCLINK_WithEPWM11						0x0000A000UL				// ePWM11
#define EPWMXLINK_CMPCLINK_WithEPWM10						0x00009000UL				// ePWM10
#define EPWMXLINK_CMPCLINK_WithEPWM9						0x00008000UL				// ePWM9
#define EPWMXLINK_CMPCLINK_WithEPWM8						0x00007000UL				// ePWM8
#define EPWMXLINK_CMPCLINK_WithEPWM7						0x00006000UL				// ePWM7
#define EPWMXLINK_CMPCLINK_WithEPWM6						0x00005000UL				// ePWM6
#define EPWMXLINK_CMPCLINK_WithEPWM5						0x00004000UL				// ePWM5
#define EPWMXLINK_CMPCLINK_WithEPWM4						0x00003000UL				// ePWM4
#define EPWMXLINK_CMPCLINK_WithEPWM3						0x00002000UL				// ePWM3
#define EPWMXLINK_CMPCLINK_WithEPWM2						0x00001000UL				// ePWM2
#define EPWMXLINK_CMPCLINK_WithEPWM1						0x00000000UL				// ePWM1

#define EPWMXLINK_CMPBLINK_WithEPWM12						0x00000B00UL				// ePWM12
#define EPWMXLINK_CMPBLINK_WithEPWM11						0x00000A00UL				// ePWM11
#define EPWMXLINK_CMPBLINK_WithEPWM10						0x00000900UL				// ePWM10
#define EPWMXLINK_CMPBLINK_WithEPWM9						0x00000800UL				// ePWM9
#define EPWMXLINK_CMPBLINK_WithEPWM8						0x00000700UL				// ePWM8
#define EPWMXLINK_CMPBLINK_WithEPWM7						0x00000600UL				// ePWM7
#define EPWMXLINK_CMPBLINK_WithEPWM6						0x00000500UL				// ePWM6
#define EPWMXLINK_CMPBLINK_WithEPWM5						0x00000400UL				// ePWM5
#define EPWMXLINK_CMPBLINK_WithEPWM4						0x00000300UL				// ePWM4
#define EPWMXLINK_CMPBLINK_WithEPWM3						0x00000200UL				// ePWM3
#define EPWMXLINK_CMPBLINK_WithEPWM2						0x00000100UL				// ePWM2
#define EPWMXLINK_CMPBLINK_WithEPWM1						0x00000000UL				// ePWM1

#define EPWMXLINK_CMPALINK_WithEPWM12						0x000000B0UL				// ePWM12
#define EPWMXLINK_CMPALINK_WithEPWM11						0x000000A0UL				// ePWM11
#define EPWMXLINK_CMPALINK_WithEPWM10						0x00000090UL				// ePWM10
#define EPWMXLINK_CMPALINK_WithEPWM9						0x00000080UL				// ePWM9
#define EPWMXLINK_CMPALINK_WithEPWM8						0x00000070UL				// ePWM8
#define EPWMXLINK_CMPALINK_WithEPWM7						0x00000060UL				// ePWM7
#define EPWMXLINK_CMPALINK_WithEPWM6						0x00000050UL				// ePWM6
#define EPWMXLINK_CMPALINK_WithEPWM5						0x00000040UL				// ePWM5
#define EPWMXLINK_CMPALINK_WithEPWM4						0x00000030UL				// ePWM4
#define EPWMXLINK_CMPALINK_WithEPWM3						0x00000020UL				// ePWM3
#define EPWMXLINK_CMPALINK_WithEPWM2						0x00000010UL				// ePWM2
#define EPWMXLINK_CMPALINK_WithEPWM1						0x00000000UL				// ePWM1

#define EPWMXLINK_TBPRDLINK_WithEPWM12						0x0000000BUL				// ePWM12
#define EPWMXLINK_TBPRDLINK_WithEPWM11						0x0000000AUL				// ePWM11
#define EPWMXLINK_TBPRDLINK_WithEPWM10						0x00000009UL				// ePWM10
#define EPWMXLINK_TBPRDLINK_WithEPWM9						0x00000008UL				// ePWM9
#define EPWMXLINK_TBPRDLINK_WithEPWM8						0x00000007UL				// ePWM8
#define EPWMXLINK_TBPRDLINK_WithEPWM7						0x00000006UL				// ePWM7
#define EPWMXLINK_TBPRDLINK_WithEPWM6						0x00000005UL				// ePWM6
#define EPWMXLINK_TBPRDLINK_WithEPWM5						0x00000004UL				// ePWM5
#define EPWMXLINK_TBPRDLINK_WithEPWM4						0x00000003UL				// ePWM4
#define EPWMXLINK_TBPRDLINK_WithEPWM3						0x00000002UL				// ePWM3
#define EPWMXLINK_TBPRDLINK_WithEPWM2						0x00000001UL				// ePWM2
#define EPWMXLINK_TBPRDLINK_WithEPWM1						0x00000000UL				// ePWM1

struct AQCTLA_BITS {                    // bits description
    Uint16 ZRO:2;                       // 1:0 Action Counter = Zero
    Uint16 PRD:2;                       // 3:2 Action Counter = Period
    Uint16 CAU:2;                       // 5:4 Action Counter = Compare A Up
    Uint16 CAD:2;                       // 7:6 Action Counter = Compare A Down
    Uint16 CBU:2;                       // 9:8 Action Counter = Compare B Up
    Uint16 CBD:2;                       // 11:10 Action Counter = Compare B Down
    Uint16 rsvd1:4;                     // 15:12 Reserved
};

union AQCTLA_REG {
    Uint16  all;
    struct  AQCTLA_BITS  bit;
};

// AQCTLx Register
//// AQCTLx Register : Byte Value
#define AQCTLx_CBD_Toggle									0x0C00
#define AQCTLx_CBD_Set										0x0800
#define AQCTLx_CBD_Clear									0x0400
#define AQCTLx_CBD_DoNothing								0x0000

#define AQCTLx_CBU_Toggle									0x0300
#define AQCTLx_CBU_Set										0x0200
#define AQCTLx_CBU_Clear									0x0100
#define AQCTLx_CBU_DoNothing								0x0000

#define AQCTLx_CAD_Toggle									0x00C0
#define AQCTLx_CAD_Set										0x0080
#define AQCTLx_CAD_Clear									0x0040
#define AQCTLx_CAD_DoNothing								0x0000

#define AQCTLx_CAU_Toggle									0x0030
#define AQCTLx_CAU_Set										0x0020
#define AQCTLx_CAU_Clear									0x0010
#define AQCTLx_CAU_DoNothing								0x0000

#define AQCTLx_PRD_Toggle									0x000C
#define AQCTLx_PRD_Set										0x0008
#define AQCTLx_PRD_Clear									0x0004
#define AQCTLx_PRD_DoNothing								0x0000

#define AQCTLx_ZRO_Toggle									0x0003
#define AQCTLx_ZRO_Set										0x0002
#define AQCTLx_ZRO_Clear									0x0001
#define AQCTLx_ZRO_DoNothing								0x0000

struct AQCTLA2_BITS {                   // bits description
    Uint16 T1U:2;                       // 1:0 Action when event occurs on T1 in UP-Count
    Uint16 T1D:2;                       // 3:2 Action when event occurs on T1 in DOWN-Count
    Uint16 T2U:2;                       // 5:4 Action when event occurs on T2 in UP-Count
    Uint16 T2D:2;                       // 7:6 Action when event occurs on T2 in DOWN-Count
    Uint16 rsvd1:8;                     // 15:8 Reserved
};

union AQCTLA2_REG {
    Uint16  all;
    struct  AQCTLA2_BITS  bit;
};

// AQCTLx2 Register
//// AQCTLx2 Register : Byte Value
#define AQCTLx2_T2D_Toggle									0x00C0
#define AQCTLx2_T2D_Set										0x0080
#define AQCTLx2_T2D_Clear									0x0040
#define AQCTLx2_T2D_DoNothing								0x0000

#define AQCTLx2_T2U_Toggle									0x0030
#define AQCTLx2_T2U_Set										0x0020
#define AQCTLx2_T2U_Clear									0x0010
#define AQCTLx2_T2U_DoNothing								0x0000

#define AQCTLx2_T1D_Toggle									0x000C
#define AQCTLx2_T1D_Set										0x0008
#define AQCTLx2_T1D_Clear									0x0004
#define AQCTLx2_T1D_DoNothing								0x0000

#define AQCTLx2_T1U_Toggle									0x0003
#define AQCTLx2_T1U_Set										0x0002
#define AQCTLx2_T1U_Clear									0x0001
#define AQCTLx2_T1U_DoNothing								0x0000

struct AQCTLB_BITS {                    // bits description
    Uint16 ZRO:2;                       // 1:0 Action Counter = Zero
    Uint16 PRD:2;                       // 3:2 Action Counter = Period
    Uint16 CAU:2;                       // 5:4 Action Counter = Compare A Up
    Uint16 CAD:2;                       // 7:6 Action Counter = Compare A Down
    Uint16 CBU:2;                       // 9:8 Action Counter = Compare B Up
    Uint16 CBD:2;                       // 11:10 Action Counter = Compare B Down
    Uint16 rsvd1:4;                     // 15:12 Reserved
};

union AQCTLB_REG {
    Uint16  all;
    struct  AQCTLB_BITS  bit;
};

struct AQCTLB2_BITS {                   // bits description
    Uint16 T1U:2;                       // 1:0 Action when event occurs on T1 in UP-Count
    Uint16 T1D:2;                       // 3:2 Action when event occurs on T1 in DOWN-Count
    Uint16 T2U:2;                       // 5:4 Action when event occurs on T2 in UP-Count
    Uint16 T2D:2;                       // 7:6 Action when event occurs on T2 in DOWN-Count
    Uint16 rsvd1:8;                     // 15:8 Reserved
};

union AQCTLB2_REG {
    Uint16  all;
    struct  AQCTLB2_BITS  bit;
};

struct AQSFRC_BITS {                    // bits description
    Uint16 ACTSFA:2;                    // 1:0 Action when One-time SW Force A Invoked
    Uint16 OTSFA:1;                     // 2 One-time SW Force A Output
    Uint16 ACTSFB:2;                    // 4:3 Action when One-time SW Force B Invoked
    Uint16 OTSFB:1;                     // 5 One-time SW Force A Output
    Uint16 RLDCSF:2;                    // 7:6 Reload from Shadow Options
    Uint16 rsvd1:8;                     // 15:8 Reserved
};

union AQSFRC_REG {
    Uint16  all;
    struct  AQSFRC_BITS  bit;
};

struct AQCSFRC_BITS {                   // bits description
    Uint16 CSFA:2;                      // 1:0 Continuous Software Force on output A
    Uint16 CSFB:2;                      // 3:2 Continuous Software Force on output B
    Uint16 rsvd1:12;                    // 15:4 Reserved
};

union AQCSFRC_REG {
    Uint16  all;
    struct  AQCSFRC_BITS  bit;
};

struct DBREDHR_BITS {                   // bits description
    Uint16 rsvd1:1;                     // 0 Reserved
    Uint16 rsvd2:7;                     // 7:1 Reserved
    Uint16 rsvd3:1;                     // 8 Reserved
    Uint16 DBREDHR:7;                   // 15:9 DBREDHR High Resolution Bits
};

union DBREDHR_REG {
    Uint16  all;
    struct  DBREDHR_BITS  bit;
};

struct DBRED_BITS {                     // bits description
    Uint16 DBRED:14;                    // 13:0 Rising edge delay value
    Uint16 rsvd1:2;                     // 15:14 Reserved
};

union DBRED_REG {
    Uint16  all;
    struct  DBRED_BITS  bit;
};

struct DBFEDHR_BITS {                   // bits description
    Uint16 rsvd1:1;                     // 0 Reserved
    Uint16 rsvd2:7;                     // 7:1 Reserved
    Uint16 rsvd3:1;                     // 8 Reserved
    Uint16 DBFEDHR:7;                   // 15:9 DBFEDHR High Resolution Bits
};

union DBFEDHR_REG {
    Uint16  all;
    struct  DBFEDHR_BITS  bit;
};

struct DBFED_BITS {                     // bits description
    Uint16 DBFED:14;                    // 13:0 Falling edge delay value
    Uint16 rsvd1:2;                     // 15:14 Reserved
};

union DBFED_REG {
    Uint16  all;
    struct  DBFED_BITS  bit;
};

struct TBPHS_BITS {                     // bits description
    Uint16 TBPHSHR:16;                  // 15:0 Extension Register for HRPWM Phase (8-bits) 
    Uint16 TBPHS:16;                    // 31:16 Phase Offset Register
};

union TBPHS_REG {
    Uint32  all;
    struct  TBPHS_BITS  bit;
};

struct CMPA_BITS {                      // bits description
    Uint16 CMPAHR:16;                   // 15:0 Compare A HRPWM Extension Register
    Uint16 CMPA:16;                     // 31:16 Compare A Register
};

union CMPA_REG {
    Uint32  all;
    struct  CMPA_BITS  bit;
};

struct CMPB_BITS {                      // bits description
    Uint16 CMPBHR:16;                   // 15:0 Compare B High Resolution Bits
    Uint16 CMPB:16;                     // 31:16 Compare B Register
};

union CMPB_REG {
    Uint32  all;
    struct  CMPB_BITS  bit;
};

struct GLDCTL2_BITS {                   // bits description
    Uint16 OSHTLD:1;                    // 0 Enable reload event in one shot mode 
    Uint16 GFRCLD:1;                    // 1 Force reload event in one shot mode 
    Uint16 rsvd1:14;                    // 15:2 Reserved
};

union GLDCTL2_REG {
    Uint16  all;
    struct  GLDCTL2_BITS  bit;
};

struct TZSEL_BITS {                     // bits description
    Uint16 CBC1:1;                      // 0 TZ1 CBC select
    Uint16 CBC2:1;                      // 1 TZ2 CBC select
    Uint16 CBC3:1;                      // 2 TZ3 CBC select
    Uint16 CBC4:1;                      // 3 TZ4 CBC select
    Uint16 CBC5:1;                      // 4 TZ5 CBC select
    Uint16 CBC6:1;                      // 5 TZ6 CBC select
    Uint16 DCAEVT2:1;                   // 6 DCAEVT2 CBC select
    Uint16 DCBEVT2:1;                   // 7 DCBEVT2 CBC select
    Uint16 OSHT1:1;                     // 8 One-shot TZ1 select
    Uint16 OSHT2:1;                     // 9 One-shot TZ2 select
    Uint16 OSHT3:1;                     // 10 One-shot TZ3 select
    Uint16 OSHT4:1;                     // 11 One-shot TZ4 select
    Uint16 OSHT5:1;                     // 12 One-shot TZ5 select
    Uint16 OSHT6:1;                     // 13 One-shot TZ6 select
    Uint16 DCAEVT1:1;                   // 14 One-shot DCAEVT1 select
    Uint16 DCBEVT1:1;                   // 15 One-shot DCBEVT1 select
};

union TZSEL_REG {
    Uint16  all;
    struct  TZSEL_BITS  bit;
};

struct TZDCSEL_BITS {                   // bits description
    Uint16 DCAEVT1:3;                   // 2:0 Digital Compare Output A Event 1
    Uint16 DCAEVT2:3;                   // 5:3 Digital Compare Output A Event 2
    Uint16 DCBEVT1:3;                   // 8:6 Digital Compare Output B Event 1
    Uint16 DCBEVT2:3;                   // 11:9 Digital Compare Output B Event 2
    Uint16 rsvd1:4;                     // 15:12 Reserved
};

union TZDCSEL_REG {
    Uint16  all;
    struct  TZDCSEL_BITS  bit;
};

struct TZCTL_BITS {                     // bits description
    Uint16 TZA:2;                       // 1:0 TZ1 to TZ6 Trip Action On EPWMxA
    Uint16 TZB:2;                       // 3:2 TZ1 to TZ6 Trip Action On EPWMxB
    Uint16 DCAEVT1:2;                   // 5:4 EPWMxA action on DCAEVT1
    Uint16 DCAEVT2:2;                   // 7:6 EPWMxA action on DCAEVT2
    Uint16 DCBEVT1:2;                   // 9:8 EPWMxB action on DCBEVT1
    Uint16 DCBEVT2:2;                   // 11:10 EPWMxB action on DCBEVT2
    Uint16 rsvd1:4;                     // 15:12 Reserved
};

union TZCTL_REG {
    Uint16  all;
    struct  TZCTL_BITS  bit;
};

struct TZCTL2_BITS {                    // bits description
    Uint16 TZAU:3;                      // 2:0 Trip Action On EPWMxA while Count direction is UP
    Uint16 TZAD:3;                      // 5:3 Trip Action On EPWMxA while Count direction is DOWN
    Uint16 TZBU:3;                      // 8:6 Trip Action On EPWMxB while Count direction is UP
    Uint16 TZBD:3;                      // 11:9 Trip Action On EPWMxB while Count direction is DOWN
    Uint16 rsvd1:3;                     // 14:12 Reserved
    Uint16 ETZE:1;                      // 15 TZCTL2 Enable
};

union TZCTL2_REG {
    Uint16  all;
    struct  TZCTL2_BITS  bit;
};

struct TZCTLDCA_BITS {                  // bits description
    Uint16 DCAEVT1U:3;                  // 2:0 DCAEVT1 Action On EPWMxA while Count direction is UP
    Uint16 DCAEVT1D:3;                  // 5:3 DCAEVT1 Action On EPWMxA while Count direction is DOWN
    Uint16 DCAEVT2U:3;                  // 8:6 DCAEVT2 Action On EPWMxA while Count direction is UP
    Uint16 DCAEVT2D:3;                  // 11:9 DCAEVT2 Action On EPWMxA while Count direction is DOWN
    Uint16 rsvd1:4;                     // 15:12 Reserved
};

union TZCTLDCA_REG {
    Uint16  all;
    struct  TZCTLDCA_BITS  bit;
};

struct TZCTLDCB_BITS {                  // bits description
    Uint16 DCBEVT1U:3;                  // 2:0 DCBEVT1 Action On EPWMxA while Count direction is UP
    Uint16 DCBEVT1D:3;                  // 5:3 DCBEVT1 Action On EPWMxA while Count direction is DOWN
    Uint16 DCBEVT2U:3;                  // 8:6 DCBEVT2 Action On EPWMxA while Count direction is UP
    Uint16 DCBEVT2D:3;                  // 11:9 DCBEVT2 Action On EPWMxA while Count direction is DOWN
    Uint16 rsvd1:4;                     // 15:12 Reserved
};

union TZCTLDCB_REG {
    Uint16  all;
    struct  TZCTLDCB_BITS  bit;
};

struct TZEINT_BITS {                    // bits description
    Uint16 rsvd1:1;                     // 0 Reserved
    Uint16 CBC:1;                       // 1 Trip Zones Cycle By Cycle Int Enable
    Uint16 OST:1;                       // 2 Trip Zones One Shot Int Enable
    Uint16 DCAEVT1:1;                   // 3 Digital Compare A Event 1 Int Enable
    Uint16 DCAEVT2:1;                   // 4 Digital Compare A Event 2 Int Enable
    Uint16 DCBEVT1:1;                   // 5 Digital Compare B Event 1 Int Enable
    Uint16 DCBEVT2:1;                   // 6 Digital Compare B Event 2 Int Enable
    Uint16 rsvd2:9;                     // 15:7 Reserved
};

union TZEINT_REG {
    Uint16  all;
    struct  TZEINT_BITS  bit;
};

struct TZFLG_BITS {                     // bits description
    Uint16 INT:1;                       // 0 Global Int Status Flag
    Uint16 CBC:1;                       // 1 Trip Zones Cycle By Cycle Flag
    Uint16 OST:1;                       // 2 Trip Zones One Shot Flag
    Uint16 DCAEVT1:1;                   // 3 Digital Compare A Event 1 Flag
    Uint16 DCAEVT2:1;                   // 4 Digital Compare A Event 2 Flag
    Uint16 DCBEVT1:1;                   // 5 Digital Compare B Event 1 Flag
    Uint16 DCBEVT2:1;                   // 6 Digital Compare B Event 2 Flag
    Uint16 rsvd1:9;                     // 15:7 Reserved
};

union TZFLG_REG {
    Uint16  all;
    struct  TZFLG_BITS  bit;
};

struct TZCBCFLG_BITS {                  // bits description
    Uint16 CBC1:1;                      // 0 Latched Status Flag for CBC1 Trip Latch
    Uint16 CBC2:1;                      // 1 Latched Status Flag for CBC2 Trip Latch
    Uint16 CBC3:1;                      // 2 Latched Status Flag for CBC3 Trip Latch
    Uint16 CBC4:1;                      // 3 Latched Status Flag for CBC4 Trip Latch
    Uint16 CBC5:1;                      // 4 Latched Status Flag for CBC5 Trip Latch
    Uint16 CBC6:1;                      // 5 Latched Status Flag for CBC6 Trip Latch
    Uint16 DCAEVT2:1;                   // 6 Latched Status Flag for Digital Compare Output A Event 2
    Uint16 DCBEVT2:1;                   // 7 Latched Status Flag for Digital Compare Output B Event 2
    Uint16 rsvd1:8;                     // 15:8 Reserved
};

union TZCBCFLG_REG {
    Uint16  all;
    struct  TZCBCFLG_BITS  bit;
};

struct TZOSTFLG_BITS {                  // bits description
    Uint16 OST1:1;                      // 0 Latched Status Flag for OST1 Trip Latch
    Uint16 OST2:1;                      // 1 Latched Status Flag for OST2 Trip Latch
    Uint16 OST3:1;                      // 2 Latched Status Flag for OST3 Trip Latch
    Uint16 OST4:1;                      // 3 Latched Status Flag for OST4 Trip Latch
    Uint16 OST5:1;                      // 4 Latched Status Flag for OST5 Trip Latch
    Uint16 OST6:1;                      // 5 Latched Status Flag for OST6 Trip Latch
    Uint16 DCAEVT1:1;                   // 6 Latched Status Flag for Digital Compare Output A Event 1
    Uint16 DCBEVT1:1;                   // 7 Latched Status Flag for Digital Compare Output B Event 1
    Uint16 rsvd1:8;                     // 15:8 Reserved
};

union TZOSTFLG_REG {
    Uint16  all;
    struct  TZOSTFLG_BITS  bit;
};

struct TZCLR_BITS {                     // bits description
    Uint16 INT:1;                       // 0 Global Interrupt Clear Flag
    Uint16 CBC:1;                       // 1 Cycle-By-Cycle Flag Clear
    Uint16 OST:1;                       // 2 One-Shot Flag Clear
    Uint16 DCAEVT1:1;                   // 3 DCAVET1 Flag Clear
    Uint16 DCAEVT2:1;                   // 4 DCAEVT2 Flag Clear
    Uint16 DCBEVT1:1;                   // 5 DCBEVT1 Flag Clear
    Uint16 DCBEVT2:1;                   // 6 DCBEVT2 Flag Clear
    Uint16 rsvd1:7;                     // 13:7 Reserved
    Uint16 CBCPULSE:2;                  // 15:14 Clear Pulse for CBC Trip Latch
};

union TZCLR_REG {
    Uint16  all;
    struct  TZCLR_BITS  bit;
};

struct TZCBCCLR_BITS {                  // bits description
    Uint16 CBC1:1;                      // 0 Clear Flag for Cycle-By-Cycle (CBC1) Trip Latch
    Uint16 CBC2:1;                      // 1 Clear Flag for Cycle-By-Cycle (CBC2) Trip Latch
    Uint16 CBC3:1;                      // 2 Clear Flag for Cycle-By-Cycle (CBC3) Trip Latch
    Uint16 CBC4:1;                      // 3 Clear Flag for Cycle-By-Cycle (CBC4) Trip Latch
    Uint16 CBC5:1;                      // 4 Clear Flag for Cycle-By-Cycle (CBC5) Trip Latch
    Uint16 CBC6:1;                      // 5 Clear Flag for Cycle-By-Cycle (CBC6) Trip Latch
    Uint16 DCAEVT2:1;                   // 6 Clear Flag forDCAEVT2 selected for CBC
    Uint16 DCBEVT2:1;                   // 7 Clear Flag for DCBEVT2 selected for CBC
    Uint16 rsvd1:8;                     // 15:8 Reserved
};

union TZCBCCLR_REG {
    Uint16  all;
    struct  TZCBCCLR_BITS  bit;
};

struct TZOSTCLR_BITS {                  // bits description
    Uint16 OST1:1;                      // 0 Clear Flag for Oneshot (OST1) Trip Latch
    Uint16 OST2:1;                      // 1 Clear Flag for Oneshot (OST2) Trip Latch
    Uint16 OST3:1;                      // 2 Clear Flag for Oneshot (OST3) Trip Latch
    Uint16 OST4:1;                      // 3 Clear Flag for Oneshot (OST4) Trip Latch
    Uint16 OST5:1;                      // 4 Clear Flag for Oneshot (OST5) Trip Latch
    Uint16 OST6:1;                      // 5 Clear Flag for Oneshot (OST6) Trip Latch
    Uint16 DCAEVT1:1;                   // 6 Clear Flag for DCAEVT1 selected for OST
    Uint16 DCBEVT1:1;                   // 7 Clear Flag for DCBEVT1 selected for OST
    Uint16 rsvd1:8;                     // 15:8 Reserved
};

union TZOSTCLR_REG {
    Uint16  all;
    struct  TZOSTCLR_BITS  bit;
};

struct TZFRC_BITS {                     // bits description
    Uint16 rsvd1:1;                     // 0 Reserved
    Uint16 CBC:1;                       // 1 Force Trip Zones Cycle By Cycle Event
    Uint16 OST:1;                       // 2 Force Trip Zones One Shot Event
    Uint16 DCAEVT1:1;                   // 3 Force Digital Compare A Event 1 
    Uint16 DCAEVT2:1;                   // 4 Force Digital Compare A Event 2 
    Uint16 DCBEVT1:1;                   // 5 Force Digital Compare B Event 1 
    Uint16 DCBEVT2:1;                   // 6 Force Digital Compare B Event 2 
    Uint16 rsvd2:9;                     // 15:7 Reserved
};

union TZFRC_REG {
    Uint16  all;
    struct  TZFRC_BITS  bit;
};

struct ETSEL_BITS {                     // bits description
    Uint16 INTSEL:3;                    // 2:0 EPWMxINTn Select
    Uint16 INTEN:1;                     // 3 EPWMxINTn Enable
    Uint16 SOCASELCMP:1;                // 4 EPWMxSOCA Compare Select
    Uint16 SOCBSELCMP:1;                // 5 EPWMxSOCB Compare Select
    Uint16 INTSELCMP:1;                 // 6 EPWMxINT Compare Select
    Uint16 rsvd1:1;                     // 7 Reserved
    Uint16 SOCASEL:3;                   // 10:8 Start of Conversion A Select
    Uint16 SOCAEN:1;                    // 11 Start of Conversion A Enable
    Uint16 SOCBSEL:3;                   // 14:12 Start of Conversion B Select
    Uint16 SOCBEN:1;                    // 15 Start of Conversion B Enable
};

union ETSEL_REG {
    Uint16  all;
    struct  ETSEL_BITS  bit;
};

// ETSEL Register
//// ETSEL Register : Byte Value
#define ETSEL_SOCBEN_SOCBEnable								0x8000
#define ETSEL_SOCBEN_SOCBDisable							0x0000

#define ETSEL_SOCBSEL_EventCMPBDDown						0x7000
#define ETSEL_SOCBSEL_EventCMPBDUp							0x6000
#define ETSEL_SOCBSEL_EventCMPACDown						0x5000
#define ETSEL_SOCBSEL_EventCMPACUp							0x4000
#define ETSEL_SOCBSEL_EventZeroPeriod						0x3000
#define ETSEL_SOCBSEL_EventPeriod							0x2000
#define ETSEL_SOCBSEL_EventZero								0x1000
#define ETSEL_SOCBSEL_EventDCBEVT1_SOC						0x0000

#define ETSEL_SOCAEN_SOCAEnable								0x0800
#define ETSEL_SOCAEN_SOCADisable							0x0000

#define ETSEL_SOCASEL_EventCMPBDDown						0x0700
#define ETSEL_SOCASEL_EventCMPBDUp							0x0600
#define ETSEL_SOCASEL_EventCMPACDown						0x0500
#define ETSEL_SOCASEL_EventCMPACUp							0x0400
#define ETSEL_SOCASEL_EventZeroPeriod						0x0300
#define ETSEL_SOCASEL_EventPeriod							0x0200
#define ETSEL_SOCASEL_EventZero								0x0100
#define ETSEL_SOCASEL_EventDCAEVT1_SOC						0x0000

#define ETSEL_INTSELCMP_InterruptByCMPCD					0x0040
#define ETSEL_INTSELCMP_InterruptByCMPAB					0x0000

#define ETSEL_SOCBSELCMP_SOCBByCMPCD						0x0020
#define ETSEL_SOCBSELCMP_SOCBByCMPAB						0x0000

#define ETSEL_SOCASELCMP_SOCAByCMPCD						0x0010
#define ETSEL_SOCASELCMP_SOCAByCMPAB						0x0000

#define ETSEL_INTEN_InterruptEnable							0x0008
#define ETSEL_INTEN_InterruptDisable						0x0000

#define ETSEL_INTSEL_EventCMPBDDown							0x0007
#define ETSEL_INTSEL_EventCMPBDUp							0x0006
#define ETSEL_INTSEL_EventCMPACDown							0x0005
#define ETSEL_INTSEL_EventCMPACUp							0x0004
#define ETSEL_INTSEL_EventZeroPeriod						0x0003
#define ETSEL_INTSEL_EventPeriod							0x0002
#define ETSEL_INTSEL_EventZero								0x0001

struct ETPS_BITS {                      // bits description
    Uint16 INTPRD:2;                    // 1:0 EPWMxINTn Period Select
    Uint16 INTCNT:2;                    // 3:2 EPWMxINTn Counter Register
    Uint16 INTPSSEL:1;                  // 4 EPWMxINTn Pre-Scale Selection Bits
    Uint16 SOCPSSEL:1;                  // 5 EPWMxSOC A/B  Pre-Scale Selection Bits
    Uint16 rsvd1:2;                     // 7:6 Reserved
    Uint16 SOCAPRD:2;                   // 9:8 EPWMxSOCA Period Select
    Uint16 SOCACNT:2;                   // 11:10 EPWMxSOCA Counter Register
    Uint16 SOCBPRD:2;                   // 13:12 EPWMxSOCB Period Select
    Uint16 SOCBCNT:2;                   // 15:14 EPWMxSOCB Counter
};

union ETPS_REG {
    Uint16  all;
    struct  ETPS_BITS  bit;
};

// ETPS Register
//// ETPS Register : Byte Value
#define ETPS_SOCBPRD_SOCBThirdEvent							0x3000
#define ETPS_SOCBPRD_SOCBSecondEvent						0x2000
#define ETPS_SOCBPRD_SOCBFirstEvent							0x1000
#define ETPS_SOCBPRD_SOCBDisable							0x0000

#define ETPS_SOCAPRD_SOCAThirdEvent							0x0300
#define ETPS_SOCAPRD_SOCASecondEvent						0x0200
#define ETPS_SOCAPRD_SOCAFirstEvent							0x0100
#define ETPS_SOCAPRD_SOCADisable							0x0000

#define ETPS_SOCPSSEL_SOCxPRD2Used							0x0020
#define ETPS_SOCPSSEL_SOCxPRDUsed							0x0000

#define ETPS_INTPSSEL_INTPRD2Used							0x0010
#define ETPS_INTPSSEL_INTPRDUsed							0x0000

#define ETPS_INTPRD_INTThirdEvent							0x0003
#define ETPS_INTPRD_INTSecondEvent							0x0002
#define ETPS_INTPRD_INTFirstEvent							0x0001
#define ETPS_INTPRD_INTDisable								0x0000

struct ETFLG_BITS {                     // bits description
    Uint16 INT:1;                       // 0 EPWMxINTn Flag
    Uint16 rsvd1:1;                     // 1 Reserved
    Uint16 SOCA:1;                      // 2 EPWMxSOCA Flag
    Uint16 SOCB:1;                      // 3 EPWMxSOCB Flag
    Uint16 rsvd2:12;                    // 15:4 Reserved
};

union ETFLG_REG {
    Uint16  all;
    struct  ETFLG_BITS  bit;
};

struct ETCLR_BITS {                     // bits description
    Uint16 INT:1;                       // 0 EPWMxINTn Clear
    Uint16 rsvd1:1;                     // 1 Reserved
    Uint16 SOCA:1;                      // 2 EPWMxSOCA Clear
    Uint16 SOCB:1;                      // 3 EPWMxSOCB Clear
    Uint16 rsvd2:12;                    // 15:4 Reserved
};

union ETCLR_REG {
    Uint16  all;
    struct  ETCLR_BITS  bit;
};

// ETCLR Register
//// ETCLR Register : Byte Value
#define ETCLR_SOCB_SOCBFlagClear							0x0008						// Clears the ETFLG[SOCB] Flag bit.
#define ETCLR_SOCA_SOCAFlagClear							0x0004						// Clears the ETFLG[SOCA] Flag bit.
#define ETCLR_INT_INTFlagClear								0x0001						// Clears the ETFLG[INT] Flag bit and Enable Further Interrupt Pulses to be Generated.

struct ETFRC_BITS {                     // bits description
    Uint16 INT:1;                       // 0 EPWMxINTn Force
    Uint16 rsvd1:1;                     // 1 Reserved
    Uint16 SOCA:1;                      // 2 EPWMxSOCA Force
    Uint16 SOCB:1;                      // 3 EPWMxSOCB Force
    Uint16 rsvd2:12;                    // 15:4 Reserved
};

union ETFRC_REG {
    Uint16  all;
    struct  ETFRC_BITS  bit;
};

struct ETINTPS_BITS {                   // bits description
    Uint16 INTPRD2:4;                   // 3:0 EPWMxINTn Period Select
    Uint16 INTCNT2:4;                   // 7:4 EPWMxINTn Counter Register
    Uint16 rsvd1:8;                     // 15:8 Reserved
};

union ETINTPS_REG {
    Uint16  all;
    struct  ETINTPS_BITS  bit;
};

// ETINTPS Register
//// ETINTPS Register : Byte Value
#define ETINTPS_INTPRD2_INT15thEvent						0x000F
#define ETINTPS_INTPRD2_INT14thEvent						0x000E
#define ETINTPS_INTPRD2_INT13thEvent						0x000D
#define ETINTPS_INTPRD2_INT12thEvent						0x000C
#define ETINTPS_INTPRD2_INT11thEvent						0x000B
#define ETINTPS_INTPRD2_INT10thEvent						0x000A
#define ETINTPS_INTPRD2_INT9thEvent							0x0009
#define ETINTPS_INTPRD2_INT8thEvent							0x0008
#define ETINTPS_INTPRD2_INT7thEvent							0x0007
#define ETINTPS_INTPRD2_INT6thEvent							0x0006
#define ETINTPS_INTPRD2_INT5thEvent							0x0005
#define ETINTPS_INTPRD2_INT4thEvent							0x0004
#define ETINTPS_INTPRD2_INT3rdEvent							0x0003
#define ETINTPS_INTPRD2_INT2ndEvent							0x0002
#define ETINTPS_INTPRD2_INT1stEvent							0x0001
#define ETINTPS_INTPRD2_INTDisable							0x0000

struct ETSOCPS_BITS {                   // bits description
    Uint16 SOCAPRD2:4;                  // 3:0 EPWMxSOCA Period Select
    Uint16 SOCACNT2:4;                  // 7:4 EPWMxSOCA Counter Register
    Uint16 SOCBPRD2:4;                  // 11:8 EPWMxSOCB Period Select
    Uint16 SOCBCNT2:4;                  // 15:12 EPWMxSOCB Counter Register
};

union ETSOCPS_REG {
    Uint16  all;
    struct  ETSOCPS_BITS  bit;
};

// ETSOCPS Register
//// ETSOCPS Register : Byte Value
#define ETSOCPS_SOCBPRD2_SOCB15thEvent						0x0F00
#define ETSOCPS_SOCBPRD2_SOCB14thEvent						0x0E00
#define ETSOCPS_SOCBPRD2_SOCB13thEvent						0x0D00
#define ETSOCPS_SOCBPRD2_SOCB12thEvent						0x0C00
#define ETSOCPS_SOCBPRD2_SOCB11thEvent						0x0B00
#define ETSOCPS_SOCBPRD2_SOCB10thEvent						0x0A00
#define ETSOCPS_SOCBPRD2_SOCB9thEvent						0x0900
#define ETSOCPS_SOCBPRD2_SOCB8thEvent						0x0800
#define ETSOCPS_SOCBPRD2_SOCB7thEvent						0x0700
#define ETSOCPS_SOCBPRD2_SOCB6thEvent						0x0600
#define ETSOCPS_SOCBPRD2_SOCB5thEvent						0x0500
#define ETSOCPS_SOCBPRD2_SOCB4thEvent						0x0400
#define ETSOCPS_SOCBPRD2_SOCB3rdEvent						0x0300
#define ETSOCPS_SOCBPRD2_SOCB2ndEvent						0x0200
#define ETSOCPS_SOCBPRD2_SOCB1stEvent						0x0100
#define ETSOCPS_SOCBPRD2_SOCBDisable						0x0000

#define ETSOCPS_SOCAPRD2_SOCA15thEvent						0x000F
#define ETSOCPS_SOCAPRD2_SOCA14thEvent						0x000E
#define ETSOCPS_SOCAPRD2_SOCA13thEvent						0x000D
#define ETSOCPS_SOCAPRD2_SOCA12thEvent						0x000C
#define ETSOCPS_SOCAPRD2_SOCA11thEvent						0x000B
#define ETSOCPS_SOCAPRD2_SOCA10thEvent						0x000A
#define ETSOCPS_SOCAPRD2_SOCA9thEvent						0x0009
#define ETSOCPS_SOCAPRD2_SOCA8thEvent						0x0008
#define ETSOCPS_SOCAPRD2_SOCA7thEvent						0x0007
#define ETSOCPS_SOCAPRD2_SOCA6thEvent						0x0006
#define ETSOCPS_SOCAPRD2_SOCA5thEvent						0x0005
#define ETSOCPS_SOCAPRD2_SOCA4thEvent						0x0004
#define ETSOCPS_SOCAPRD2_SOCA3rdEvent						0x0003
#define ETSOCPS_SOCAPRD2_SOCA2ndEvent						0x0002
#define ETSOCPS_SOCAPRD2_SOCA1stEvent						0x0001
#define ETSOCPS_SOCAPRD2_SOCADisable						0x0000

struct ETCNTINITCTL_BITS {              // bits description
    Uint16 rsvd1:10;                    // 9:0 Reserved
    Uint16 INTINITFRC:1;                // 10 EPWMxINT Counter Initialization Force
    Uint16 SOCAINITFRC:1;               // 11 EPWMxSOCA Counter Initialization Force
    Uint16 SOCBINITFRC:1;               // 12 EPWMxSOCB Counter Initialization Force
    Uint16 INTINITEN:1;                 // 13 EPWMxINT Counter Initialization Enable
    Uint16 SOCAINITEN:1;                // 14 EPWMxSOCA Counter Initialization Enable
    Uint16 SOCBINITEN:1;                // 15 EPWMxSOCB Counter Initialization Enable
};

union ETCNTINITCTL_REG {
    Uint16  all;
    struct  ETCNTINITCTL_BITS  bit;
};

struct ETCNTINIT_BITS {                 // bits description
    Uint16 INTINIT:4;                   // 3:0 EPWMxINT Counter Initialization Bits
    Uint16 SOCAINIT:4;                  // 7:4 EPWMxSOCA Counter Initialization Bits
    Uint16 SOCBINIT:4;                  // 11:8 EPWMxSOCB Counter Initialization Bits
    Uint16 rsvd1:4;                     // 15:12 Reserved
};

union ETCNTINIT_REG {
    Uint16  all;
    struct  ETCNTINIT_BITS  bit;
};

struct DCTRIPSEL_BITS {                 // bits description
    Uint16 DCAHCOMPSEL:4;               // 3:0 Digital Compare A High COMP Input Select 
    Uint16 DCALCOMPSEL:4;               // 7:4 Digital Compare A Low COMP Input Select 
    Uint16 DCBHCOMPSEL:4;               // 11:8 Digital Compare B High COMP Input Select
    Uint16 DCBLCOMPSEL:4;               // 15:12 Digital Compare B Low COMP Input Select
};

union DCTRIPSEL_REG {
    Uint16  all;
    struct  DCTRIPSEL_BITS  bit;
};

struct DCACTL_BITS {                    // bits description
    Uint16 EVT1SRCSEL:1;                // 0 DCAEVT1 Source Signal
    Uint16 EVT1FRCSYNCSEL:1;            // 1 DCAEVT1 Force Sync Signal
    Uint16 EVT1SOCE:1;                  // 2 DCAEVT1 SOC Enable
    Uint16 EVT1SYNCE:1;                 // 3 DCAEVT1 SYNC Enable
    Uint16 rsvd1:4;                     // 7:4 Reserved
    Uint16 EVT2SRCSEL:1;                // 8 DCAEVT2 Source Signal
    Uint16 EVT2FRCSYNCSEL:1;            // 9 DCAEVT2 Force Sync Signal
    Uint16 rsvd2:6;                     // 15:10 Reserved
};

union DCACTL_REG {
    Uint16  all;
    struct  DCACTL_BITS  bit;
};

struct DCBCTL_BITS {                    // bits description
    Uint16 EVT1SRCSEL:1;                // 0 DCBEVT1 Source Signal
    Uint16 EVT1FRCSYNCSEL:1;            // 1 DCBEVT1 Force Sync Signal
    Uint16 EVT1SOCE:1;                  // 2 DCBEVT1 SOC Enable
    Uint16 EVT1SYNCE:1;                 // 3 DCBEVT1 SYNC Enable
    Uint16 rsvd1:4;                     // 7:4 Reserved
    Uint16 EVT2SRCSEL:1;                // 8 DCBEVT2 Source Signal
    Uint16 EVT2FRCSYNCSEL:1;            // 9 DCBEVT2 Force Sync Signal
    Uint16 rsvd2:6;                     // 15:10 Reserved
};

union DCBCTL_REG {
    Uint16  all;
    struct  DCBCTL_BITS  bit;
};

struct DCFCTL_BITS {                    // bits description
    Uint16 SRCSEL:2;                    // 1:0 Filter Block Signal Source Select
    Uint16 BLANKE:1;                    // 2 Blanking Enable/Disable
    Uint16 BLANKINV:1;                  // 3 Blanking Window Inversion
    Uint16 PULSESEL:2;                  // 5:4 Pulse Select for Blanking & Capture Alignment
    Uint16 rsvd1:1;                     // 6 Reserved
    Uint16 rsvd2:1;                     // 7 Reserved
    Uint16 rsvd3:2;                     // 9:8 Reserved
    Uint16 rsvd4:3;                     // 12:10 Reserved
    Uint16 rsvd5:3;                     // 15:13 Reserved
};

union DCFCTL_REG {
    Uint16  all;
    struct  DCFCTL_BITS  bit;
};

struct DCCAPCTL_BITS {                  // bits description
    Uint16 CAPE:1;                      // 0 Counter Capture Enable
    Uint16 SHDWMODE:1;                  // 1 Counter Capture Mode
    Uint16 rsvd1:11;                    // 12:2 Reserved
    Uint16 CAPSTS:1;                    // 13 Latched Status Flag for Capture Event
    Uint16 CAPCLR:1;                    // 14 DC Capture Latched Status Clear Flag
    Uint16 CAPMODE:1;                   // 15 Counter Capture Mode
};

union DCCAPCTL_REG {
    Uint16  all;
    struct  DCCAPCTL_BITS  bit;
};

struct DCAHTRIPSEL_BITS {               // bits description
    Uint16 TRIPINPUT1:1;                // 0 Trip Input 1 Select to DCAH Mux
    Uint16 TRIPINPUT2:1;                // 1 Trip Input 2 Select to DCAH Mux
    Uint16 TRIPINPUT3:1;                // 2 Trip Input 3 Select to DCAH Mux
    Uint16 TRIPINPUT4:1;                // 3 Trip Input 4 Select to DCAH Mux
    Uint16 TRIPINPUT5:1;                // 4 Trip Input 5 Select to DCAH Mux
    Uint16 TRIPINPUT6:1;                // 5 Trip Input 6 Select to DCAH Mux
    Uint16 TRIPINPUT7:1;                // 6 Trip Input 7 Select to DCAH Mux
    Uint16 TRIPINPUT8:1;                // 7 Trip Input 8 Select to DCAH Mux
    Uint16 TRIPINPUT9:1;                // 8 Trip Input 9 Select to DCAH Mux
    Uint16 TRIPINPUT10:1;               // 9 Trip Input 10 Select to DCAH Mux
    Uint16 TRIPINPUT11:1;               // 10 Trip Input 11 Select to DCAH Mux
    Uint16 TRIPINPUT12:1;               // 11 Trip Input 12 Select to DCAH Mux
    Uint16 rsvd1:1;                     // 12 Reserved
    Uint16 TRIPINPUT14:1;               // 13 Trip Input 14 Select to DCAH Mux
    Uint16 TRIPINPUT15:1;               // 14 Trip Input 15 Select to DCAH Mux
    Uint16 rsvd2:1;                     // 15 Reserved
};

union DCAHTRIPSEL_REG {
    Uint16  all;
    struct  DCAHTRIPSEL_BITS  bit;
};

struct DCALTRIPSEL_BITS {               // bits description
    Uint16 TRIPINPUT1:1;                // 0 Trip Input 1 Select to DCAL Mux
    Uint16 TRIPINPUT2:1;                // 1 Trip Input 2 Select to DCAL Mux
    Uint16 TRIPINPUT3:1;                // 2 Trip Input 3 Select to DCAL Mux
    Uint16 TRIPINPUT4:1;                // 3 Trip Input 4 Select to DCAL Mux
    Uint16 TRIPINPUT5:1;                // 4 Trip Input 5 Select to DCAL Mux
    Uint16 TRIPINPUT6:1;                // 5 Trip Input 6 Select to DCAL Mux
    Uint16 TRIPINPUT7:1;                // 6 Trip Input 7 Select to DCAL Mux
    Uint16 TRIPINPUT8:1;                // 7 Trip Input 8 Select to DCAL Mux
    Uint16 TRIPINPUT9:1;                // 8 Trip Input 9 Select to DCAL Mux
    Uint16 TRIPINPUT10:1;               // 9 Trip Input 10 Select to DCAL Mux
    Uint16 TRIPINPUT11:1;               // 10 Trip Input 11 Select to DCAL Mux
    Uint16 TRIPINPUT12:1;               // 11 Trip Input 12 Select to DCAL Mux
    Uint16 rsvd1:1;                     // 12 Reserved
    Uint16 TRIPINPUT14:1;               // 13 Trip Input 14 Select to DCAL Mux
    Uint16 TRIPINPUT15:1;               // 14 Trip Input 15 Select to DCAL Mux
    Uint16 rsvd2:1;                     // 15 Reserved
};

union DCALTRIPSEL_REG {
    Uint16  all;
    struct  DCALTRIPSEL_BITS  bit;
};

struct DCBHTRIPSEL_BITS {               // bits description
    Uint16 TRIPINPUT1:1;                // 0 Trip Input 1 Select to DCBH Mux
    Uint16 TRIPINPUT2:1;                // 1 Trip Input 2 Select to DCBH Mux
    Uint16 TRIPINPUT3:1;                // 2 Trip Input 3 Select to DCBH Mux
    Uint16 TRIPINPUT4:1;                // 3 Trip Input 4 Select to DCBH Mux
    Uint16 TRIPINPUT5:1;                // 4 Trip Input 5 Select to DCBH Mux
    Uint16 TRIPINPUT6:1;                // 5 Trip Input 6 Select to DCBH Mux
    Uint16 TRIPINPUT7:1;                // 6 Trip Input 7 Select to DCBH Mux
    Uint16 TRIPINPUT8:1;                // 7 Trip Input 8 Select to DCBH Mux
    Uint16 TRIPINPUT9:1;                // 8 Trip Input 9 Select to DCBH Mux
    Uint16 TRIPINPUT10:1;               // 9 Trip Input 10 Select to DCBH Mux
    Uint16 TRIPINPUT11:1;               // 10 Trip Input 11 Select to DCBH Mux
    Uint16 TRIPINPUT12:1;               // 11 Trip Input 12 Select to DCBH Mux
    Uint16 rsvd1:1;                     // 12 Reserved
    Uint16 TRIPINPUT14:1;               // 13 Trip Input 14 Select to DCBH Mux
    Uint16 TRIPINPUT15:1;               // 14 Trip Input 15 Select to DCBH Mux
    Uint16 rsvd2:1;                     // 15 Reserved
};

union DCBHTRIPSEL_REG {
    Uint16  all;
    struct  DCBHTRIPSEL_BITS  bit;
};

struct DCBLTRIPSEL_BITS {               // bits description
    Uint16 TRIPINPUT1:1;                // 0 Trip Input 1 Select to DCBL Mux
    Uint16 TRIPINPUT2:1;                // 1 Trip Input 2 Select to DCBL Mux
    Uint16 TRIPINPUT3:1;                // 2 Trip Input 3 Select to DCBL Mux
    Uint16 TRIPINPUT4:1;                // 3 Trip Input 4 Select to DCBL Mux
    Uint16 TRIPINPUT5:1;                // 4 Trip Input 5 Select to DCBL Mux
    Uint16 TRIPINPUT6:1;                // 5 Trip Input 6 Select to DCBL Mux
    Uint16 TRIPINPUT7:1;                // 6 Trip Input 7 Select to DCBL Mux
    Uint16 TRIPINPUT8:1;                // 7 Trip Input 8 Select to DCBL Mux
    Uint16 TRIPINPUT9:1;                // 8 Trip Input 9 Select to DCBL Mux
    Uint16 TRIPINPUT10:1;               // 9 Trip Input 10 Select to DCBL Mux
    Uint16 TRIPINPUT11:1;               // 10 Trip Input 11 Select to DCBL Mux
    Uint16 TRIPINPUT12:1;               // 11 Trip Input 12 Select to DCBL Mux
    Uint16 rsvd1:1;                     // 12 Reserved
    Uint16 TRIPINPUT14:1;               // 13 Trip Input 14 Select to DCBL Mux
    Uint16 TRIPINPUT15:1;               // 14 Trip Input 15 Select to DCBL Mux
    Uint16 rsvd2:1;                     // 15 Reserved
};

union DCBLTRIPSEL_REG {
    Uint16  all;
    struct  DCBLTRIPSEL_BITS  bit;
};

struct EPWM_REGS {
    union   TBCTL_REG                        TBCTL;                        // Time Base Control Register
    union   TBCTL2_REG                       TBCTL2;                       // Time Base Control Register 2
    Uint16                                   rsvd1[2];                     // Reserved
    Uint16                                   TBCTR;                        // Time Base Counter Register
    union   TBSTS_REG                        TBSTS;                        // Time Base Status Register
    Uint16                                   rsvd2[2];                     // Reserved
    union   CMPCTL_REG                       CMPCTL;                       // Counter Compare Control Register
    union   CMPCTL2_REG                      CMPCTL2;                      // Counter Compare Control Register 2
    Uint16                                   rsvd3[2];                     // Reserved
    union   DBCTL_REG                        DBCTL;                        // Dead-Band Generator Control Register
    union   DBCTL2_REG                       DBCTL2;                       // Dead-Band Generator Control Register 2
    Uint16                                   rsvd4[2];                     // Reserved
    union   AQCTL_REG                        AQCTL;                        // Action Qualifier Control Register
    union   AQTSRCSEL_REG                    AQTSRCSEL;                    // Action Qualifier Trigger Event Source Select Register
    Uint16                                   rsvd5[2];                     // Reserved
    union   PCCTL_REG                        PCCTL;                        // PWM Chopper Control Register
    Uint16                                   rsvd6[11];                    // Reserved
    union   HRCNFG_REG                       HRCNFG;                       // HRPWM Configuration Register
    union   HRPWR_REG                        HRPWR;                        // HRPWM Power Register
    Uint16                                   rsvd7[4];                     // Reserved
    union   HRMSTEP_REG                      HRMSTEP;                      // HRPWM MEP Step Register
    union   HRCNFG2_REG                      HRCNFG2;                      // HRPWM Configuration 2 Register
    Uint16                                   rsvd8[5];                     // Reserved
    union   HRPCTL_REG                       HRPCTL;                       // High Resolution Period Control Register 
    union   TRREM_REG                        TRREM;                        // Translator High Resolution Remainder Register
    Uint16                                   rsvd9[5];                     // Reserved
    union   GLDCTL_REG                       GLDCTL;                       // Global PWM Load Control Register
    union   GLDCFG_REG                       GLDCFG;                       // Global PWM Load Config Register 
    Uint16                                   rsvd10[2];                    // Reserved
    union   EPWMXLINK_REG                    EPWMXLINK;                    // EPWMx Link Register
    Uint16                                   rsvd11[6];                    // Reserved
    union   AQCTLA_REG                       AQCTLA;                       // Action Qualifier Control Register For Output A 
    union   AQCTLA2_REG                      AQCTLA2;                      // Additional Action Qualifier Control Register For Output A 
    union   AQCTLB_REG                       AQCTLB;                       // Action Qualifier Control Register For Output B 
    union   AQCTLB2_REG                      AQCTLB2;                      // Additional Action Qualifier Control Register For Output B 
    Uint16                                   rsvd12[3];                    // Reserved
    union   AQSFRC_REG                       AQSFRC;                       // Action Qualifier Software Force Register
    Uint16                                   rsvd13;                       // Reserved
    union   AQCSFRC_REG                      AQCSFRC;                      // Action Qualifier Continuous S/W Force Register 
    Uint16                                   rsvd14[6];                    // Reserved
    union   DBREDHR_REG                      DBREDHR;                      // Dead-Band Generator Rising Edge Delay High Resolution Mirror Register 
    union   DBRED_REG                        DBRED;                        // Dead-Band Generator Rising Edge Delay High Resolution Mirror Register 
    union   DBFEDHR_REG                      DBFEDHR;                      // Dead-Band Generator Falling Edge Delay High Resolution Register 
    union   DBFED_REG                        DBFED;                        // Dead-Band Generator Falling Edge Delay Count Register
    Uint16                                   rsvd15[12];                   // Reserved
    union   TBPHS_REG                        TBPHS;                        // Time Base Phase High
    Uint16                                   TBPRDHR;                      // Time Base Period High Resolution Register 
    Uint16                                   TBPRD;                        // Time Base Period Register 
    Uint16                                   rsvd16[6];                    // Reserved
    union   CMPA_REG                         CMPA;                         // Counter Compare A Register 
    union   CMPB_REG                         CMPB;                         // Compare B Register 
    Uint16                                   rsvd17;                       // Reserved
    Uint16                                   CMPC;                         // Counter Compare C Register
    Uint16                                   rsvd18;                       // Reserved
    Uint16                                   CMPD;                         // Counter Compare D Register
    Uint16                                   rsvd19[2];                    // Reserved
    union   GLDCTL2_REG                      GLDCTL2;                      // Global PWM Load Control Register 2
    Uint16                                   rsvd20[11];                   // Reserved
    union   TZSEL_REG                        TZSEL;                        // Trip Zone Select Register 
    Uint16                                   rsvd21;                       // Reserved
    union   TZDCSEL_REG                      TZDCSEL;                      // Trip Zone Digital Comparator Select Register
    Uint16                                   rsvd22;                       // Reserved
    union   TZCTL_REG                        TZCTL;                        // Trip Zone Control Register
    union   TZCTL2_REG                       TZCTL2;                       // Additional Trip Zone Control Register
    union   TZCTLDCA_REG                     TZCTLDCA;                     // Trip Zone Control Register Digital Compare A 
    union   TZCTLDCB_REG                     TZCTLDCB;                     // Trip Zone Control Register Digital Compare B 
    Uint16                                   rsvd23[5];                    // Reserved
    union   TZEINT_REG                       TZEINT;                       // Trip Zone Enable Interrupt Register
    Uint16                                   rsvd24[5];                    // Reserved
    union   TZFLG_REG                        TZFLG;                        // Trip Zone Flag Register
    union   TZCBCFLG_REG                     TZCBCFLG;                     // Trip Zone CBC Flag Register
    union   TZOSTFLG_REG                     TZOSTFLG;                     // Trip Zone OST Flag Register
    Uint16                                   rsvd25;                       // Reserved
    union   TZCLR_REG                        TZCLR;                        // Trip Zone Clear Register
    union   TZCBCCLR_REG                     TZCBCCLR;                     // Trip Zone CBC Clear Register
    union   TZOSTCLR_REG                     TZOSTCLR;                     // Trip Zone OST Clear Register
    Uint16                                   rsvd26;                       // Reserved
    union   TZFRC_REG                        TZFRC;                        // Trip Zone Force Register
    Uint16                                   rsvd27[8];                    // Reserved
    union   ETSEL_REG                        ETSEL;                        // Event Trigger Selection Register
    Uint16                                   rsvd28;                       // Reserved
    union   ETPS_REG                         ETPS;                         // Event Trigger Pre-Scale Register
    Uint16                                   rsvd29;                       // Reserved
    union   ETFLG_REG                        ETFLG;                        // Event Trigger Flag Register
    Uint16                                   rsvd30;                       // Reserved
    union   ETCLR_REG                        ETCLR;                        // Event Trigger Clear Register
    Uint16                                   rsvd31;                       // Reserved
    union   ETFRC_REG                        ETFRC;                        // Event Trigger Force Register
    Uint16                                   rsvd32;                       // Reserved
    union   ETINTPS_REG                      ETINTPS;                      // Event-Trigger Interrupt Pre-Scale Register
    Uint16                                   rsvd33;                       // Reserved
    union   ETSOCPS_REG                      ETSOCPS;                      // Event-Trigger SOC Pre-Scale Register
    Uint16                                   rsvd34;                       // Reserved
    union   ETCNTINITCTL_REG                 ETCNTINITCTL;                 // Event-Trigger Counter Initialization Control Register
    Uint16                                   rsvd35;                       // Reserved
    union   ETCNTINIT_REG                    ETCNTINIT;                    // Event-Trigger Counter Initialization Register
    Uint16                                   rsvd36[11];                   // Reserved
    union   DCTRIPSEL_REG                    DCTRIPSEL;                    // Digital Compare Trip Select Register
    Uint16                                   rsvd37[2];                    // Reserved
    union   DCACTL_REG                       DCACTL;                       // Digital Compare A Control Register
    union   DCBCTL_REG                       DCBCTL;                       // Digital Compare B Control Register
    Uint16                                   rsvd38[2];                    // Reserved
    union   DCFCTL_REG                       DCFCTL;                       // Digital Compare Filter Control Register
    union   DCCAPCTL_REG                     DCCAPCTL;                     // Digital Compare Capture Control Register
    Uint16                                   DCFOFFSET;                    // Digital Compare Filter Offset Register 
    Uint16                                   DCFOFFSETCNT;                 // Digital Compare Filter Offset Counter Register
    Uint16                                   DCFWINDOW;                    // Digital Compare Filter Window Register
    Uint16                                   DCFWINDOWCNT;                 // Digital Compare Filter Window Counter Register
    Uint16                                   rsvd39[2];                    // Reserved
    Uint16                                   DCCAP;                        // Digital Compare Counter Capture Register 
    Uint16                                   rsvd40[2];                    // Reserved
    union   DCAHTRIPSEL_REG                  DCAHTRIPSEL;                  // Digital Compare AH Trip Select 
    union   DCALTRIPSEL_REG                  DCALTRIPSEL;                  // Digital Compare AL Trip Select 
    union   DCBHTRIPSEL_REG                  DCBHTRIPSEL;                  // Digital Compare BH Trip Select 
    union   DCBLTRIPSEL_REG                  DCBLTRIPSEL;                  // Digital Compare BL Trip Select 
    Uint16                                   rsvd41[42];                   // Reserved
};

//---------------------------------------------------------------------------
// EPWM External References & Function Declarations:
//
#ifdef CPU1
extern volatile struct EPWM_REGS EPwm1Regs;
extern volatile struct EPWM_REGS EPwm2Regs;
extern volatile struct EPWM_REGS EPwm3Regs;
extern volatile struct EPWM_REGS EPwm4Regs;
extern volatile struct EPWM_REGS EPwm5Regs;
extern volatile struct EPWM_REGS EPwm6Regs;
extern volatile struct EPWM_REGS EPwm7Regs;
extern volatile struct EPWM_REGS EPwm8Regs;
extern volatile struct EPWM_REGS EPwm9Regs;
extern volatile struct EPWM_REGS EPwm10Regs;
extern volatile struct EPWM_REGS EPwm11Regs;
extern volatile struct EPWM_REGS EPwm12Regs;
#endif
#ifdef CPU2
extern volatile struct EPWM_REGS EPwm1Regs;
extern volatile struct EPWM_REGS EPwm2Regs;
extern volatile struct EPWM_REGS EPwm3Regs;
extern volatile struct EPWM_REGS EPwm4Regs;
extern volatile struct EPWM_REGS EPwm5Regs;
extern volatile struct EPWM_REGS EPwm6Regs;
extern volatile struct EPWM_REGS EPwm7Regs;
extern volatile struct EPWM_REGS EPwm8Regs;
extern volatile struct EPWM_REGS EPwm9Regs;
extern volatile struct EPWM_REGS EPwm10Regs;
extern volatile struct EPWM_REGS EPwm11Regs;
extern volatile struct EPWM_REGS EPwm12Regs;
#endif
#ifdef __cplusplus
}
#endif                                  /* extern "C" */

#endif

//===========================================================================
// End of file.
//===========================================================================
