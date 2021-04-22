/*
 * ePWM.c
 *
 *  Created on: 2015. 8. 18.
 *      Author: cjs9426
 *  Revised on: 2020. 10. 11.
 *     Reviser: subi
 */


#include "Define_Header.h"


void Init_Epwm(void)
{
#ifdef CPU1
    // Emulation Mode
    EPwm1Regs.TBCTL.bit.FREE_SOFT = EMUMODE_FREE;               // Free Run

    // Clock Pre-scale                                          // TBCLK = SYSCLKOUT / (EPWMCLKDIV x CLKDIV x HSPCLKDIV)
    EALLOW;
    ClkCfgRegs.PERCLKDIVSEL.bit.EPWMCLKDIV = EPWM_CLK_DIV1;     // /1
    EDIS;
    EPwm1Regs.TBCTL.bit.CLKDIV = TB_DIV1;                       // /1
    EPwm1Regs.TBCTL.bit.HSPCLKDIV = TB_HSPDIV1;                 // /1

    // Time base clock
    EPwm1Regs.TBCTL.bit.PRDLD = TB_IMMEDIATE;                   // Disable Shadow mode
    EPwm1Regs.TBCTL.bit.PHSEN = TB_DISABLE;                     // Do not load TBCTR from TBPHS
    EPwm1Regs.TBCTL.bit.CTRMODE = TB_COUNT_UPDOWN;              // Up-down count mode
    EPwm1Regs.TBPRD = TIMEBASE1_PERIOD_HALF;                    // Period(5[kHz] = 200[MHz]/(2*20000))

    // Compare Register
    EPwm1Regs.CMPCTL.bit.SHDWAMODE = CC_SHADOW;                 // disable Shadow mode for CMPA
    EPwm1Regs.CMPCTL.bit.LOADAMODE = CC_CTR_ZERO;
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

    EPwm1Regs.ETSEL.bit.SOCASEL = EPWMSOC_ZERO;
    EPwm1Regs.ETPS.bit.SOCPSSEL = SOC_PRESCALE_CNT;
    EPwm1Regs.ETPS.bit.SOCAPRD = SOC_PRD_FST;
    EPwm1Regs.ETSEL.bit.SOCAEN = EPWMSOC_DISABLE;

    // Sync
    EPwm1Regs.TBCTL.bit.SYNCOSEL = 0x1;                         // Enable EPWMxSYNCO signal (00: EPWMxSYNCI/SWFSYNC, 01 : CTR=zero, 10 : CTR=CMPB, 11 : EPWMxSYNCO defined by TBCTL2)

    // Chopping
    EPwm1Regs.PCCTL.bit.CHPEN = 0;                              // Disable PWM chopping function

    // High resolution period
    EPwm1Regs.HRPCTL.bit.HRPE = 0;                              // High resolution period feature disabled

    // One Shot Load mode
    EPwm1Regs.GLDCTL.bit.OSHTMODE = 0;                          // One shot load mode disabled


#endif

#ifdef CPU2
    // Emulation Mode
    EPwm2Regs.TBCTL.bit.FREE_SOFT = EMUMODE_FREE;               // Free Run

    // Clock Pre-scale                                          // TBCLK = SYSCLKOUT / (EPWMCLKDIV x CLKDIV x HSPCLKDIV)
    EALLOW;
    ClkCfgRegs.PERCLKDIVSEL.bit.EPWMCLKDIV = EPWM_CLK_DIV1;     // /1
    EDIS;
    EPwm2Regs.TBCTL.bit.CLKDIV = TB_DIV1;                       // /1
    EPwm2Regs.TBCTL.bit.HSPCLKDIV = TB_HSPDIV1;                 // /1

    // Time base clock
    EPwm2Regs.TBCTL.bit.PRDLD = TB_IMMEDIATE;                   // Disable Shadow mode
    EPwm2Regs.TBCTL.bit.PHSEN = TB_DISABLE;                     // Do not load TBCTR from TBPHS
    EPwm2Regs.TBCTL.bit.CTRMODE = TB_COUNT_UPDOWN;              // Up-down count mode
    EPwm2Regs.TBPRD = TIMEBASE1_PERIOD_HALF;                    // Period(5[kHz] = 200[MHz]/(2*20000))

    // Compare Register
    EPwm2Regs.CMPCTL.bit.SHDWAMODE = CC_SHADOW;                 // disable Shadow mode for CMPA
    EPwm2Regs.CMPCTL.bit.LOADAMODE = CC_CTR_ZERO;
    EPwm2Regs.CMPA.bit.CMPA = TIMEBASE1_PERIOD_HALF;            // Compare A register

    // Action Qualifier
    EPwm2Regs.AQCTLA.bit.CAU = AQ_CLEAR;                        //
    EPwm2Regs.AQCTLA.bit.CAD = AQ_SET;                          //

    // Dead Band
    EPwm2Regs.DBCTL.bit.HALFCYCLE = DB_HALF_DISABLE;            // dead band counters are clocked at TBCLK rate
    EPwm2Regs.DBCTL.bit.DEDB_MODE = DB_MODE_SINGLE;             // Add RED, FED to source selected by S4, S5 switch
    EPwm2Regs.DBCTL.bit.OUTSWAP = DB_OUTSWAP_DISABLE;           // OUTA = A path, OUTB = B path
    EPwm2Regs.DBCTL.bit.SHDWDBFEDMODE = DB_IMMEDIATE;           // Immediate mode in Falling edge
    EPwm2Regs.DBCTL.bit.SHDWDBREDMODE = DB_IMMEDIATE;           // Immediate mode in Rising edge
    EPwm2Regs.DBCTL.bit.IN_MODE = DBA_ALL;                      // EPWMxA In is the source for FED, RED
    EPwm2Regs.DBCTL.bit.POLSEL = SET1_ACTV_HIGHLOW;             // Invert DBFED output

    EPwm2Regs.DBCTL.bit.OUT_MODE = DB_FULL_ENABLE;
    EPwm2Regs.DBREDHR.bit.DBREDHR = 0x0;                        // Dead Band Rising Edge Delay High Resolution bits
    EPwm2Regs.DBRED = PWM1_DB_PERIOD;                           // Rising edge delay value : 3.3us
    EPwm2Regs.DBFEDHR.bit.DBFEDHR = 0x0;                        // Dead Band falling Edge Delay High Resolution bits
    EPwm2Regs.DBFED = PWM1_DB_PERIOD;                           // falling edge delay value : 3.3us

    // Event trigger
    EPwm2Regs.ETSEL.bit.INTSEL = 1;                             // Enable event time-base counter equal to zero
    EPwm2Regs.ETPS.bit.INTPSSEL = 0;                            // Select ETPS registers to determine frequency of event
    EPwm2Regs.ETPS.bit.INTPRD = 1;                              // Generate an interrupt on the first event INTCNT
    EPwm2Regs.ETSEL.bit.INTEN = 1;                              // Enable ePWM interrupt

    EPwm2Regs.ETSEL.bit.SOCASEL = EPWMSOC_ZERO;
    EPwm2Regs.ETPS.bit.SOCPSSEL = SOC_PRESCALE_CNT;
    EPwm2Regs.ETPS.bit.SOCAPRD = SOC_PRD_FST;
    EPwm2Regs.ETSEL.bit.SOCAEN = EPWMSOC_DISABLE;

    // Sync
    EPwm2Regs.TBCTL.bit.SYNCOSEL = 0;                           // Enable EPWMxSYNCO signal

    // Chopping
    EPwm2Regs.PCCTL.bit.CHPEN = 0;                              // Disable PWM chopping function

    // High resolution period
    EPwm2Regs.HRPCTL.bit.HRPE = 0;                              // High resolution period feature disabled

    // One Shot Load mode
    EPwm2Regs.GLDCTL.bit.OSHTMODE = 0;                          // One shot load mode disabled

    // Enable Synchronization with other ePWM module(ePWM1)
    EPwm2Regs.TBCTL.bit.PHSEN = 1;                              // Enable Sync-In
    EPwm2Regs.TBPHS.bit.TBPHS = 0x0000;                         // Loaded Phases
#endif

    return;
}

void Start_PWM(void)
{
#ifdef CPU1
    EALLOW;
    CpuSysRegs.PCLKCR0.bit.GTBCLKSYNC = 1;
//    CpuSysRegs.PCLKCR0.bit.TBCLKSYNC  = 1;
	EDIS;

	return;
#endif
}

