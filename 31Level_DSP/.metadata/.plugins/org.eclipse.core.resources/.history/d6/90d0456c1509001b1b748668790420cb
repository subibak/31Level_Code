/*
 * ePWM.c
 *
 *  Created on: 2015. 8. 18.
 *      Author: cjs9426
 */


#include "Define_Header.h"
#include "Define_ePWM.h"

#define SET1_ACTV_HIGHLOW			DB_ACTV_LOC
#define SET2_ACTV_HIGHLOW			DB_ACTV_LOC
#define SET3_ACTV_HIGHLOW			DB_ACTV_LOC

void Init_Epwm(void)
{
	//-------------------------------------------------------------------------------------------------//
	//--------------------------------------------ePWM Set1--------------------------------------------//
	//-------------------------------------------------------------------------------------------------//
	// Emulation Mode
	EPwm1Regs.TBCTL.bit.FREE_SOFT = EMUMODE_FREE;				// Free Run
	EPwm2Regs.TBCTL.bit.FREE_SOFT = EMUMODE_FREE;
	EPwm3Regs.TBCTL.bit.FREE_SOFT = EMUMODE_FREE;

	// Clock Pre-scale											// TBCLK = SYSCLKOUT / (EPWMCLKDIV x CLKDIV x HSPCLKDIV)
	EALLOW;
	ClkCfgRegs.PERCLKDIVSEL.bit.EPWMCLKDIV = EPWM_CLK_DIV1;		// /1
	EDIS;
	EPwm1Regs.TBCTL.bit.CLKDIV = TB_DIV1;						// /1
	EPwm2Regs.TBCTL.bit.CLKDIV = TB_DIV1;
	EPwm3Regs.TBCTL.bit.CLKDIV = TB_DIV1;
	EPwm1Regs.TBCTL.bit.HSPCLKDIV = TB_HSPDIV1;					// /1
	EPwm2Regs.TBCTL.bit.HSPCLKDIV = TB_HSPDIV1;
	EPwm3Regs.TBCTL.bit.HSPCLKDIV = TB_HSPDIV1;

	// Time base clock
	EPwm1Regs.TBCTL.bit.PRDLD = TB_IMMEDIATE;					// Disable Shadow mode
	EPwm2Regs.TBCTL.bit.PRDLD = TB_IMMEDIATE;
	EPwm3Regs.TBCTL.bit.PRDLD = TB_IMMEDIATE;
	EPwm1Regs.TBCTL.bit.PHSEN = TB_DISABLE;						// Do not load TBCTR from TBPHS
	EPwm2Regs.TBCTL.bit.PHSEN = TB_DISABLE;
	EPwm3Regs.TBCTL.bit.PHSEN = TB_DISABLE;
	EPwm1Regs.TBCTL.bit.CTRMODE = TB_COUNT_UPDOWN;				// Up-down count mode
	EPwm2Regs.TBCTL.bit.CTRMODE = TB_COUNT_UPDOWN;
	EPwm3Regs.TBCTL.bit.CTRMODE = TB_COUNT_UPDOWN;
	EPwm1Regs.TBPRD = TIMEBASE1_PERIOD;									// Period(10[kHz] = 200[MHz]/(2*10000))
	EPwm2Regs.TBPRD = TIMEBASE1_PERIOD;
	EPwm3Regs.TBPRD = TIMEBASE1_PERIOD;

	// Compare Register
	EPwm1Regs.CMPCTL.bit.SHDWAMODE = CC_SHADOW;				// disable Shadow mode for CMPA
	EPwm2Regs.CMPCTL.bit.SHDWAMODE = CC_SHADOW;
	EPwm3Regs.CMPCTL.bit.SHDWAMODE = CC_SHADOW;
	EPwm1Regs.CMPCTL.bit.LOADAMODE = CC_CTR_ZERO;				//
	EPwm2Regs.CMPCTL.bit.LOADAMODE = CC_CTR_ZERO;
	EPwm3Regs.CMPCTL.bit.LOADAMODE = CC_CTR_ZERO;
	EPwm1Regs.CMPA.bit.CMPA = TIMEBASE1_PERIOD_HALF;								// Compare A register
	EPwm2Regs.CMPA.bit.CMPA = TIMEBASE1_PERIOD_HALF;
	EPwm3Regs.CMPA.bit.CMPA = TIMEBASE1_PERIOD_HALF;

	// Action Qualifier
	EPwm1Regs.AQCTLA.bit.CAU = AQ_CLEAR;						//
	EPwm2Regs.AQCTLA.bit.CAU = AQ_CLEAR;
	EPwm3Regs.AQCTLA.bit.CAU = AQ_CLEAR;
	EPwm1Regs.AQCTLA.bit.CAD = AQ_SET;							//
	EPwm2Regs.AQCTLA.bit.CAD = AQ_SET;
	EPwm3Regs.AQCTLA.bit.CAD = AQ_SET;

	// Dead Band
	EPwm1Regs.DBCTL.bit.HALFCYCLE = DB_HALF_DISABLE;			// dead band counters are clocked at TBCLK rate
	EPwm2Regs.DBCTL.bit.HALFCYCLE = DB_HALF_DISABLE;
	EPwm3Regs.DBCTL.bit.HALFCYCLE = DB_HALF_DISABLE;
	EPwm1Regs.DBCTL.bit.DEDB_MODE = DB_MODE_SINGLE;				// Add RED, FED to source selected by S4, S5 switch
	EPwm2Regs.DBCTL.bit.DEDB_MODE = DB_MODE_SINGLE;
	EPwm3Regs.DBCTL.bit.DEDB_MODE = DB_MODE_SINGLE;
	EPwm1Regs.DBCTL.bit.OUTSWAP = DB_OUTSWAP_DISABLE;			// OUTA = A path, OUTB = B path
	EPwm2Regs.DBCTL.bit.OUTSWAP = DB_OUTSWAP_DISABLE;
	EPwm3Regs.DBCTL.bit.OUTSWAP = DB_OUTSWAP_DISABLE;
	EPwm1Regs.DBCTL.bit.SHDWDBFEDMODE = DB_IMMEDIATE;			// Immediate mode in Falling edge
	EPwm2Regs.DBCTL.bit.SHDWDBFEDMODE = DB_IMMEDIATE;
	EPwm3Regs.DBCTL.bit.SHDWDBFEDMODE = DB_IMMEDIATE;
	EPwm1Regs.DBCTL.bit.SHDWDBREDMODE = DB_IMMEDIATE;			// Immediate mode in Rising edge
	EPwm2Regs.DBCTL.bit.SHDWDBREDMODE = DB_IMMEDIATE;
	EPwm3Regs.DBCTL.bit.SHDWDBREDMODE = DB_IMMEDIATE;
	EPwm1Regs.DBCTL.bit.IN_MODE = DBA_ALL;						// EPWMxA In is the source for FED, RED
	EPwm2Regs.DBCTL.bit.IN_MODE = DBA_ALL;
	EPwm3Regs.DBCTL.bit.IN_MODE = DBA_ALL;
	EPwm1Regs.DBCTL.bit.POLSEL = SET1_ACTV_HIGHLOW;					// Invert DBFED output
	EPwm2Regs.DBCTL.bit.POLSEL = SET1_ACTV_HIGHLOW;
	EPwm3Regs.DBCTL.bit.POLSEL = SET1_ACTV_HIGHLOW;
	EPwm1Regs.DBCTL.bit.OUT_MODE = DB_FULL_ENABLE;
	EPwm2Regs.DBCTL.bit.OUT_MODE = DB_FULL_ENABLE;
	EPwm3Regs.DBCTL.bit.OUT_MODE = DB_FULL_ENABLE;
	EPwm1Regs.DBREDHR.bit.DBREDHR = 0x0;							// Dead Band Rising Edge Delay High Resolution bits
	EPwm2Regs.DBREDHR.bit.DBREDHR = 0x0;
	EPwm3Regs.DBREDHR.bit.DBREDHR = 0x0;
	EPwm1Regs.DBRED = PWM1_DB_PERIOD;										// Rising edge delay value : 3.3us
	EPwm2Regs.DBRED = PWM1_DB_PERIOD;
	EPwm3Regs.DBRED = PWM1_DB_PERIOD;
	EPwm1Regs.DBFEDHR.bit.DBFEDHR = 0x0;							// Dead Band falling Edge Delay High Resolution bits
	EPwm2Regs.DBFEDHR.bit.DBFEDHR = 0x0;
	EPwm3Regs.DBFEDHR.bit.DBFEDHR = 0x0;
	EPwm1Regs.DBFED = PWM1_DB_PERIOD;										// falling edge delay value : 3.3us
	EPwm2Regs.DBFED = PWM1_DB_PERIOD;
	EPwm3Regs.DBFED = PWM1_DB_PERIOD;

	// Event trigger
	EPwm1Regs.ETSEL.bit.INTSEL = 1;								// Enable event time-base counter equal to zero
	EPwm1Regs.ETPS.bit.INTPSSEL = 0;							// Select ETPS registers to determine frequency of event
	EPwm1Regs.ETPS.bit.INTPRD = 1;								// Generate an interrupt on the first event INTCNT
	EPwm1Regs.ETSEL.bit.INTEN = 1;								// Enable ePWM interrupt

	EPwm1Regs.ETSEL.bit.SOCASEL = EPWMSOC_ZERO;
	EPwm1Regs.ETPS.bit.SOCPSSEL = SOC_PRESCALE_CNT;
	EPwm1Regs.ETPS.bit.SOCAPRD = SOC_PRD_FST;
	EPwm1Regs.ETSEL.bit.SOCAEN = EPWMSOC_ENABLE;

	// Sync
	EPwm1Regs.TBCTL.bit.SYNCOSEL = 1;							// Enable EPWMxSYNCO signal
	EPwm2Regs.TBCTL.bit.SYNCOSEL = 3;							// Disable EPWMxSYNCO signal
	EPwm3Regs.TBCTL.bit.SYNCOSEL = 3;

	// Chopping
	EPwm1Regs.PCCTL.bit.CHPEN = 0;								// Disable PWM chopping function
	EPwm2Regs.PCCTL.bit.CHPEN = 0;
	EPwm3Regs.PCCTL.bit.CHPEN = 0;

	// High resolution period
	EPwm1Regs.HRPCTL.bit.HRPE = 0;								// High resolution period feature disabled
	EPwm2Regs.HRPCTL.bit.HRPE = 0;
	EPwm3Regs.HRPCTL.bit.HRPE = 0;

	// One Shot Load mode
	EPwm1Regs.GLDCTL.bit.OSHTMODE = 0;							// One shot load mode disabled
	EPwm2Regs.GLDCTL.bit.OSHTMODE = 0;
	EPwm3Regs.GLDCTL.bit.OSHTMODE = 0;


	//-------------------------------------------------------------------------------------------------//
	//--------------------------------------------ePWM Set2--------------------------------------------//
	//-------------------------------------------------------------------------------------------------//

	// Emulation Mode
	EPwm4Regs.TBCTL.bit.FREE_SOFT = EMUMODE_FREE;			// Free Run
	EPwm5Regs.TBCTL.bit.FREE_SOFT = EMUMODE_FREE;
	EPwm6Regs.TBCTL.bit.FREE_SOFT = EMUMODE_FREE;

	// Clock Pre-scale
	EPwm4Regs.TBCTL.bit.CLKDIV = TB_DIV1;				// Time Base Clock Pre-scale
	EPwm5Regs.TBCTL.bit.CLKDIV = TB_DIV1;
	EPwm6Regs.TBCTL.bit.CLKDIV = TB_DIV1;
	EPwm4Regs.TBCTL.bit.HSPCLKDIV = TB_HSPDIV1;			// High Speed Time Base Clock Pre-Scale
	EPwm5Regs.TBCTL.bit.HSPCLKDIV = TB_HSPDIV1;
	EPwm6Regs.TBCTL.bit.HSPCLKDIV = TB_HSPDIV1;

	// Time base clock
	EPwm4Regs.TBCTL.bit.PRDLD = TB_IMMEDIATE;				// Disable Shadow mode
	EPwm5Regs.TBCTL.bit.PRDLD = TB_IMMEDIATE;
	EPwm6Regs.TBCTL.bit.PRDLD = TB_IMMEDIATE;
	EPwm4Regs.TBCTL.bit.PHSEN = TB_DISABLE;				// Do not load TBCTR from TBPHS
	EPwm5Regs.TBCTL.bit.PHSEN = TB_DISABLE;
	EPwm6Regs.TBCTL.bit.PHSEN = TB_DISABLE;
	EPwm4Regs.TBCTL.bit.CTRMODE = TB_COUNT_UPDOWN;			// Up-down count mode
	EPwm5Regs.TBCTL.bit.CTRMODE = TB_COUNT_UPDOWN;
	EPwm6Regs.TBCTL.bit.CTRMODE = TB_COUNT_UPDOWN;
	EPwm4Regs.TBPRD = TIMEBASE1_PERIOD;					// Period(10[kHz] = 200[MHz]/(2*10000)
	EPwm5Regs.TBPRD = TIMEBASE1_PERIOD;
	EPwm6Regs.TBPRD = TIMEBASE1_PERIOD;

	// Compare Register
	EPwm4Regs.CMPCTL.bit.SHDWAMODE = CC_SHADOW;			// disable Shadow mode for CMPA
	EPwm5Regs.CMPCTL.bit.SHDWAMODE = CC_SHADOW;
	EPwm6Regs.CMPCTL.bit.SHDWAMODE = CC_SHADOW;
	EPwm4Regs.CMPCTL.bit.LOADAMODE = CC_CTR_ZERO;				//
	EPwm5Regs.CMPCTL.bit.LOADAMODE = CC_CTR_ZERO;
	EPwm6Regs.CMPCTL.bit.LOADAMODE = CC_CTR_ZERO;
	EPwm4Regs.CMPA.bit.CMPA = TIMEBASE1_PERIOD_HALF;				// Compare A register
	EPwm5Regs.CMPA.bit.CMPA = TIMEBASE1_PERIOD_HALF;
	EPwm6Regs.CMPA.bit.CMPA = TIMEBASE1_PERIOD_HALF;

	// Action Qualifier
	EPwm4Regs.AQCTLA.bit.CAU = AQ_CLEAR;						//
	EPwm5Regs.AQCTLA.bit.CAU = AQ_CLEAR;
	EPwm6Regs.AQCTLA.bit.CAU = AQ_CLEAR;
	EPwm4Regs.AQCTLA.bit.CAD = AQ_SET;							//
	EPwm5Regs.AQCTLA.bit.CAD = AQ_SET;
	EPwm6Regs.AQCTLA.bit.CAD = AQ_SET;

	// Dead Band
	EPwm4Regs.DBCTL.bit.HALFCYCLE = DB_HALF_DISABLE;			// dead band counters are clocked at TBCLK rate
	EPwm5Regs.DBCTL.bit.HALFCYCLE = DB_HALF_DISABLE;
	EPwm6Regs.DBCTL.bit.HALFCYCLE = DB_HALF_DISABLE;
	EPwm4Regs.DBCTL.bit.DEDB_MODE = DB_MODE_SINGLE;			// Add RED, FED to source selected by S4, S5 switch
	EPwm5Regs.DBCTL.bit.DEDB_MODE = DB_MODE_SINGLE;
	EPwm6Regs.DBCTL.bit.DEDB_MODE = DB_MODE_SINGLE;
	EPwm4Regs.DBCTL.bit.OUTSWAP = DB_OUTSWAP_DISABLE;			// OUTA = A path, OUTB = B path
	EPwm5Regs.DBCTL.bit.OUTSWAP = DB_OUTSWAP_DISABLE;
	EPwm6Regs.DBCTL.bit.OUTSWAP = DB_OUTSWAP_DISABLE;
	EPwm4Regs.DBCTL.bit.SHDWDBFEDMODE = DB_IMMEDIATE;		// Immediate mode in Falling edge
	EPwm5Regs.DBCTL.bit.SHDWDBFEDMODE = DB_IMMEDIATE;
	EPwm6Regs.DBCTL.bit.SHDWDBFEDMODE = DB_IMMEDIATE;
	EPwm4Regs.DBCTL.bit.SHDWDBREDMODE = DB_IMMEDIATE;		// Immediate mode in Rising edge
	EPwm5Regs.DBCTL.bit.SHDWDBREDMODE = DB_IMMEDIATE;
	EPwm6Regs.DBCTL.bit.SHDWDBREDMODE = DB_IMMEDIATE;
	EPwm4Regs.DBCTL.bit.IN_MODE = DBA_ALL;			// EPWMxA In is the source for FED, RED
	EPwm5Regs.DBCTL.bit.IN_MODE = DBA_ALL;
	EPwm6Regs.DBCTL.bit.IN_MODE = DBA_ALL;
	EPwm4Regs.DBCTL.bit.POLSEL = SET1_ACTV_HIGHLOW;				// Invert DBFED output
	EPwm5Regs.DBCTL.bit.POLSEL = SET1_ACTV_HIGHLOW;
	EPwm6Regs.DBCTL.bit.POLSEL = SET1_ACTV_HIGHLOW;
	EPwm4Regs.DBCTL.bit.OUT_MODE = DB_FULL_ENABLE;
	EPwm5Regs.DBCTL.bit.OUT_MODE = DB_FULL_ENABLE;
	EPwm6Regs.DBCTL.bit.OUT_MODE = DB_FULL_ENABLE;
	EPwm4Regs.DBREDHR.bit.DBREDHR = 0x0;			// Dead Band Rising Edge Delay High Resolution bits
	EPwm5Regs.DBREDHR.bit.DBREDHR = 0x0;
	EPwm6Regs.DBREDHR.bit.DBREDHR = 0x0;
	EPwm4Regs.DBRED = PWM1_DB_PERIOD;						// Rising edge delay value : 3us
	EPwm5Regs.DBRED = PWM1_DB_PERIOD;
	EPwm6Regs.DBRED = PWM1_DB_PERIOD;
	EPwm4Regs.DBFEDHR.bit.DBFEDHR = 0x0;			// Dead Band falling Edge Delay High Resolution bits
	EPwm5Regs.DBFEDHR.bit.DBFEDHR = 0x0;
	EPwm6Regs.DBFEDHR.bit.DBFEDHR = 0x0;
	EPwm4Regs.DBFED = PWM1_DB_PERIOD;						// falling edge delay value : 3us
	EPwm5Regs.DBFED = PWM1_DB_PERIOD;
	EPwm6Regs.DBFED = PWM1_DB_PERIOD;

	// Sync
	EPwm4Regs.TBCTL.bit.SYNCOSEL = 3;			// Disable EPWMxSYNCO signal
	EPwm5Regs.TBCTL.bit.SYNCOSEL = 3;
	EPwm6Regs.TBCTL.bit.SYNCOSEL = 3;
	TrigRegs.SYNCSELECT.bit.EPWM7SYNCIN = 0;

	// Chopping
	EPwm4Regs.PCCTL.bit.CHPEN = 0;				// Disable PWM chopping function
	EPwm5Regs.PCCTL.bit.CHPEN = 0;
	EPwm6Regs.PCCTL.bit.CHPEN = 0;

	// High resolution period
	EPwm4Regs.HRPCTL.bit.HRPE = 0;				// High resolution period feature disabled
	EPwm5Regs.HRPCTL.bit.HRPE = 0;
	EPwm6Regs.HRPCTL.bit.HRPE = 0;

	// One Shot Load mode
	EPwm4Regs.GLDCTL.bit.OSHTMODE = 0;			// One shot load mode disabled
	EPwm5Regs.GLDCTL.bit.OSHTMODE = 0;
	EPwm6Regs.GLDCTL.bit.OSHTMODE = 0;

	return;
}

void Start_PWM(void)
{
	EALLOW;
	CpuSysRegs.PCLKCR0.bit.GTBCLKSYNC = 1;
	//CpuSysRegs.PCLKCR0.bit.TBCLKSYNC = 1;
	EDIS;

	return;
}

void PWM1_out(float Nas_ref, float Nbs_ref, float Ncs_ref)
{
	int CMPa = 0, CMPb = 0, CMPc = 0;

	CMPa = (int)(Nas_ref * TIMEBASE1_PERIOD_HALF);
	CMPb = (int)(Nbs_ref * TIMEBASE1_PERIOD_HALF);
	CMPc = (int)(Ncs_ref * TIMEBASE1_PERIOD_HALF);


	EPwm1Regs.CMPA.bit.CMPA = BOUND(CMPa, TIMEBASE1_PERIOD_HALF) + TIMEBASE1_PERIOD_HALF;
	EPwm2Regs.CMPA.bit.CMPA = BOUND(CMPb, TIMEBASE1_PERIOD_HALF) + TIMEBASE1_PERIOD_HALF;
	EPwm3Regs.CMPA.bit.CMPA = BOUND(CMPc, TIMEBASE1_PERIOD_HALF) + TIMEBASE1_PERIOD_HALF;

	return;
}

void PWM2_out(float Nas_ref, float Nbs_ref, float Ncs_ref)
{
	int CMPa = 0, CMPb = 0, CMPc = 0;

	CMPa = (int)(Nas_ref * TIMEBASE1_PERIOD_HALF);
	CMPb = (int)(Nbs_ref * TIMEBASE1_PERIOD_HALF);
	CMPc = (int)(Ncs_ref * TIMEBASE1_PERIOD_HALF);

	EPwm4Regs.CMPA.bit.CMPA = BOUND(CMPa, TIMEBASE2_PERIOD_HALF) + TIMEBASE2_PERIOD_HALF;
	EPwm5Regs.CMPA.bit.CMPA = BOUND(CMPb, TIMEBASE2_PERIOD_HALF) + TIMEBASE2_PERIOD_HALF;
	EPwm6Regs.CMPA.bit.CMPA = BOUND(CMPc, TIMEBASE2_PERIOD_HALF) + TIMEBASE2_PERIOD_HALF;

	return;
}

