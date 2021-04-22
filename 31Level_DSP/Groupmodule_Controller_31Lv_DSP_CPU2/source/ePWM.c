/*
 * ePWM.c
 *
 *  Created on: 2015. 8. 18.
 *      Author: cjs9426
 */


#include "Define_Header.h"

#define SET1_ACTV_HIGHLOW           DB_ACTV_LOC
#define SET2_ACTV_HIGHLOW           DB_ACTV_LOC
#define SET3_ACTV_HIGHLOW           DB_ACTV_LOC

void Init_Epwm(void)
{

    EALLOW;
#ifdef CPU1
    //ePWM1
    // Emulation Mode
    EPwm1Regs.TBCTL.bit.FREE_SOFT = EMUMODE_FREE;               // Free Run
    // Clock Pre-scale                                          // TBCLK = SYSCLKOUT / (EPWMCLKDIV x CLKDIV x HSPCLKDIV)
    ClkCfgRegs.PERCLKDIVSEL.bit.EPWMCLKDIV = EPWM_CLK_DIV1;     // /1
    EDIS;
    EPwm1Regs.TBCTL.bit.CLKDIV = TB_DIV1;                       // /1
    EPwm1Regs.TBCTL.bit.HSPCLKDIV = TB_HSPDIV1;                 // /1

    // Time base clock
    EPwm1Regs.TBCTL.bit.PRDLD = TB_IMMEDIATE;                   // Disable Shadow mode
    EPwm1Regs.TBCTL.bit.PHSEN = TB_DISABLE;                     // Do not load TBCTR from TBPHS
    EPwm1Regs.TBCTL.bit.CTRMODE = TB_COUNT_UPDOWN;              // Up-down count mode
    EPwm1Regs.TBPRD = TIMEBASE1_PERIOD;                         // Period(10[kHz] = 200[MHz]/(2*10000))

    // Compare Register
    EPwm1Regs.CMPCTL.bit.SHDWAMODE = CC_SHADOW;                 // disable Shadow mode for CMPA
    EPwm1Regs.CMPCTL.bit.LOADAMODE = CC_CTR_ZERO;               //
    EPwm1Regs.CMPA.bit.CMPA = TIMEBASE1_PERIOD_HALF;            // Compare A register

    // Action Qualifier
    EPwm1Regs.AQCTLA.bit.CAU = AQ_CLEAR;                        //
    EPwm1Regs.AQCTLA.bit.CAD = AQ_SET;                          //

    // Dead Band
    EPwm1Regs.DBCTL.bit.HALFCYCLE = DB_HALF_DISABLE;            // dead band counters are clocked at TBCLK rate
    EPwm1Regs.DBCTL.bit.DEDB_MODE = DB_MODE_SINGLE;             // Add RED, FED to source selected by S4, S5 switch
    EPwm1Regs.DBCTL.bit.OUTSWAP = DB_OUTSWAP_DISABLE;           // OUTA = A path, OUTB = B path
    EPwm1Regs.DBCTL.bit.SHDWDBFEDMODE = DB_IMMEDIATE;           // Immediate mode in Falling edge
    EPwm1Regs.DBCTL.bit.SHDWDBREDMODE = DB_IMMEDIATE;           // Immediate mode in Rising edge
    EPwm1Regs.DBCTL.bit.IN_MODE = DBA_ALL;                      // EPWMxA In is the source for FED, RED
    EPwm1Regs.DBCTL.bit.POLSEL = SET1_ACTV_HIGHLOW;             // Invert DBFED output
    EPwm1Regs.DBCTL.bit.OUT_MODE = DB_FULL_ENABLE;
    EPwm1Regs.DBREDHR.bit.DBREDHR = 0x0;                        // Dead Band Rising Edge Delay High Resolution bits
    EPwm1Regs.DBRED = PWM1_DB_PERIOD;                           // Rising edge delay value : 3.3us
    EPwm1Regs.DBFEDHR.bit.DBFEDHR = 0x0;                        // Dead Band falling Edge Delay High Resolution bits
    EPwm1Regs.DBFED = PWM1_DB_PERIOD;                           // falling edge delay value : 3.3us

    // Event trigger
    EPwm1Regs.ETSEL.bit.INTSEL = 1;                             // Enable event time-base counter equal to zero
    EPwm1Regs.ETPS.bit.INTPSSEL = 0;                            // Select ETPS registers to determine frequency of event
    EPwm1Regs.ETPS.bit.INTPRD = 1;                              // Generate an interrupt on the first event INTCNT
    EPwm1Regs.ETSEL.bit.INTEN = 1;                              // Enable ePWM interrupt

    // Sync
    EPwm1Regs.TBCTL.bit.SYNCOSEL = 1;                           // Enable EPWMxSYNCO signal

    // Chopping
    EPwm1Regs.PCCTL.bit.CHPEN = 0;                              // Disable PWM chopping function

    // High resolution period
    EPwm1Regs.HRPCTL.bit.HRPE = 0;                              // High resolution period feature disabled

    // One Shot Load mode
    EPwm1Regs.GLDCTL.bit.OSHTMODE = 0;

    //Synchronization with FPGA using ADCSOC_A of ePWM4
    SyncSocRegs.SYNCSOCLOCK.bit.ADCSOCOUTSELECT = 0;
    SyncSocRegs.ADCSOCSELECT.bit.PWM4SOCAEN = 1;
    OutputXbarRegs.OUTPUTLOCK.bit = 0X00000000;                          // Locks the configuration for OUTPUT-XBAR.
    OutputXbarRegs.OUTPUT3MUX0TO15CFG.bit.MUX13 = 1;            // Select Bits for OUTPUT3 Mux13:01 : Select .1 input for Mux13 = ADCSOCA)
    OutputXbarRegs.OUTPUT3MUXENABLE.bit.MUX13 = 1;              // Selects the output latch to drive OUTPUT5 for OUTPUT-XBAR
    OutputXbarRegs.OUTPUTLATCH.bit.OUTPUT5 = 1;                 // Records the OUTPUT5 of OUTPUT-XBAR. : Respective output is triggered
    OutputXbarRegs.OUTPUTLATCHFRC.bit.OUTPUT5 = 1;              // Sets the Output-Latch for OUTPUT5 of OUTPUT-XBAR.
    OutputXbarRegs.OUTPUTLATCHCLR.bit.OUTPUT5 = 0;              // Clears the Output-Latch for OUTPUT5 of OUTPUT-XBAR. 0 has no effect
    OutputXbarRegs.OUTPUTLATCHENABLE.bit.OUTPUT5 = 1;           // selects the output latch to drive OUTPUT5 for OUTPUT-XBAR 1: Output Latch is selected to drive the respective output
    OutputXbarRegs.OUTPUTINV.bit.OUTPUT5 = 1;                   // Selects polarity for OUTPUT5 of OUTPUT-XBAR. 1: drives active-low output

#endif

#ifdef CPU2
    // ePWM4
    // Emulation Mode
    EPwm4Regs.TBCTL.bit.FREE_SOFT = EMUMODE_FREE;               // Free Run

    // Clock Pre-scale
    EPwm4Regs.TBCTL.bit.CLKDIV = TB_DIV1;                       // Time Base Clock Pre-scale
    EPwm4Regs.TBCTL.bit.HSPCLKDIV = TB_HSPDIV1;                 // High Speed Time Base Clock Pre-Scale

    // Time base clock
    EPwm4Regs.TBCTL.bit.PRDLD = TB_IMMEDIATE;                   // Disable Shadow mode
    EPwm4Regs.TBCTL.bit.PHSEN = TB_DISABLE;                     // Do not load TBCTR from TBPHS
    EPwm4Regs.TBCTL.bit.CTRMODE = TB_COUNT_UPDOWN;              // Up-down count mode
    EPwm4Regs.TBPRD = TIMEBASE1_PERIOD;                         // Period(10[kHz] = 200[MHz]/(2*10000)

    // Compare Register
    EPwm4Regs.CMPCTL.bit.SHDWAMODE = CC_SHADOW;                 // disable Shadow mode for CMPA
    EPwm4Regs.CMPCTL.bit.LOADAMODE = CC_CTR_ZERO;               //
    EPwm4Regs.CMPA.bit.CMPA = TIMEBASE1_PERIOD_HALF;            // Compare A register

    // Action Qualifier
    EPwm4Regs.AQCTLA.bit.CAU = AQ_CLEAR;                        //
    EPwm4Regs.AQCTLA.bit.CAD = AQ_SET;                          //

    // Dead Band
    EPwm4Regs.DBCTL.bit.HALFCYCLE = DB_HALF_DISABLE;            // dead band counters are clocked at TBCLK rate
    EPwm4Regs.DBCTL.bit.DEDB_MODE = DB_MODE_SINGLE;             // Add RED, FED to source selected by S4, S5 switch
    EPwm4Regs.DBCTL.bit.OUTSWAP = DB_OUTSWAP_DISABLE;           // OUTA = A path, OUTB = B path
    EPwm4Regs.DBCTL.bit.SHDWDBFEDMODE = DB_IMMEDIATE;           // Immediate mode in Falling edge
    EPwm4Regs.DBCTL.bit.SHDWDBREDMODE = DB_IMMEDIATE;           // Immediate mode in Rising edge
    EPwm4Regs.DBCTL.bit.IN_MODE = DBA_ALL;                      // EPWMxA In is the source for FED, RED
    EPwm4Regs.DBCTL.bit.POLSEL = SET1_ACTV_HIGHLOW;             // Invert DBFED output
    EPwm4Regs.DBCTL.bit.OUT_MODE = DB_FULL_ENABLE;
    EPwm4Regs.DBREDHR.bit.DBREDHR = 0x0;                        // Dead Band Rising Edge Delay High Resolution bits
    EPwm4Regs.DBRED = PWM1_DB_PERIOD;                           // Rising edge delay value : 3us
    EPwm4Regs.DBFEDHR.bit.DBFEDHR = 0x0;                        // Dead Band falling Edge Delay High Resolution bits
    EPwm4Regs.DBFED = PWM1_DB_PERIOD;                           // falling edge delay value : 3us

    // Event trigger
    EPwm4Regs.ETSEL.bit.INTSEL = 1;                             // Enable event time-base counter equal to zero
    EPwm4Regs.ETPS.bit.INTPSSEL = 0;                            // Select ETPS registers to determine frequency of event
    EPwm4Regs.ETPS.bit.INTPRD = 1;                              // Generate an interrupt on the first event INTCNT
    EPwm4Regs.ETSEL.bit.INTEN = 1;                              // Enable ePWM interrupt

    EPwm4Regs.ETSEL.bit.SOCASEL = EPWMSOC_ZERO;
    EPwm4Regs.ETPS.bit.SOCPSSEL = SOC_PRESCALE_CNT;
    EPwm4Regs.ETPS.bit.SOCAPRD = SOC_PRD_FST;
    EPwm4Regs.ETSEL.bit.SOCAEN = EPWMSOC_ENABLE;

    // Sync
    EPwm4Regs.TBCTL.bit.SYNCOSEL = 1;                           // Disable EPWMxSYNCO signal

    // Chopping
    EPwm4Regs.PCCTL.bit.CHPEN = 0;                              // Disable PWM chopping function

    // High resolution period
    EPwm4Regs.HRPCTL.bit.HRPE = 0;                              // High resolution period feature disabled

    // One Shot Load mode
    EPwm4Regs.GLDCTL.bit.OSHTMODE = 0;                          // One shot load mode disabled

#endif
    EDIS;
    return;
}

#ifdef CPU1

void Start_PWM(void)
{
    EALLOW;
    CpuSysRegs.PCLKCR0.bit.GTBCLKSYNC = 1;
//    CpuSysRegs.PCLKCR0.bit.TBCLKSYNC  = 1;
    EDIS;

    return;
}

#endif
