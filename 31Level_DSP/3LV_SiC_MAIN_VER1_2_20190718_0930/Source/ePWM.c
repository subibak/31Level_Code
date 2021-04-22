/*
 * ePWM.c
 *
 *  Created on: 2019. 6. 24.
 *      Author: HJHeo
 */

#include "Define_Header.h"
#include "Define_ePWM.h"

#ifdef CPU1
// Predefine
//// Predefine : The Number of Used Modules and Module Indexes.
#define PWM_MAX					1					// The Number of Used Modules.
#define PWM_PHASE_A				0					// A-Phase Index.

//// Predefine : Sampling Time Value
#define MxSamp					M1Samp				// Sampling Time Value.

// Variable
//// Variable : ePWM Registers
volatile struct EPWM_REGS *EPWM[PWM_MAX] = {&EPwm1Regs};

// External Variable
//// External Variable : Sampling Time Value.
extern S_STV M1Samp;
#endif

#ifdef CPU2
// Predefine
//// Predefine : The Number of Used Modules and Module Indexes.
#define PWM_MAX					1					// The Number of Used Modules.
#define PWM_PHASE_A				0					// A-Phase Index.

//// Predefine : Sampling Time Value
#define MxSamp					M2Samp				// Sampling Time Value.

// Variable
//// Variable : ePWM Registers
volatile struct EPWM_REGS *EPWM[PWM_MAX] = {&EPwm4Regs};

// External Variable
//// External Variable : Sampling Time Value.
extern S_STV M2Samp;
#endif

void Init_ePWM(void)
{
	Uint16 ui_Index;

	// PWM Module Initializing Except Event Triggers.
	for (ui_Index = 0; ui_Index < PWM_MAX; ui_Index++)
	{
		//// Time-Base Initializing.
		EPWM[ui_Index]->TBCTL.all = TBCTL_FREESOFT_FreeRun				// 15-14: FREESOFT		; 00(Stop After Next Counting), 01(Stop After Counting PRD or ZERO), 1x(Free Run).
								| TBCTL_PHSDIR_UpCountAfterSync			// 13	: PHSDIR		; 0(Down Count After Sync. Event), 1(Up Count After Sync. Event).
								| TBCTL_CLKDIV_DIV1						// 12-10: CLKDIV		; 0b000(/1), 0b001(/2), 0b010(/4), 0b011(/8), ..., 0b111(/128).
								| TBCTL_HSPCLKDIV_DIV1					// 9-7	: HSPCLKDIV		; 0b000(/1), 0b001(/2), 0b010(/4), 0b011(/6), ..., 0b111(/14).
								| TBCTL_SYNCOSEL_SYNCOSELX				// 5-4	: SYNCOSEL		; 00(EPWMxSYNC), 01(Count ZERO), 10(Count COMPB), 11(Determined by TBCTL2[SYNCOSELX]).
								| TBCTL_PRDLD_ShadowEnable				// 3	: PRDLD			; 0(Period Shadow Enable), 1(Period Shadow Disable).
								| TBCTL_PHSEN_PhaseDisable				// 2	: PHSEN			; 0(Phase Register Disables), 1(Phase Register Enables).
								| TBCTL_CTRMODE_UpDownCountMode;		// 1-0	: CTRMODE		; 00(Up Count), 01(Down Count), 10(UpDown Count), 11(Freeze).
		EPWM[ui_Index]->TBCTL2.all = TBCTL2_PRDLDSYNC_LoadZero			// 15-14: PRDLDSYNC		; 00(TBPRD is Loaded When TBCTR = 0), 01(TBPRD is Loaded When TBCTR = 0 and When SYNC Occurs), 10(TBPRD is Loaded When SYNC Occurs).
								| TBCTL2_SYNCOSELX_Disable				// 13-12: SYNCOSELX		; 00(Disable EPWMxSYNCO), 01(Count CMPC), 10(Count CMPD).
								| TBCTL2_OSHTSYNCMODE_OneShotDisable;	// 6	: OSHTSYNCMODE	; 0(One-Shot Sync Mode Disable), 1(One-Shot Sync Mode Enable).

		EPWM[ui_Index]->TBPRD = MxSamp.TIMEBASE.PERIOD;					// 15-0	: TBPRD			; F_int = F_tb / (2 * PERIOD)
																		//						; 10[kHz] = 100[MHz] / (2 * 5000)

		//// Global Load Initializing.
		EALLOW;

		EPWM[ui_Index]->GLDCTL.all = GLDCTL_GLDPRD_1stEVT				// 9-7	: GLDPRD		; 0(Disable), 001 ~ 111(1st ~ 7th Event Generate Load Strobe Signal).
								| GLDCTL_OSHTMODE_ContinueMode			// 5	: OSHMODE		; 0(Continuous Load Mode), 1(One Shot Load Mode, When GLDCTL2[OSHTLD] is Set, Load Strobe Signal is Generated).
								| GLDCTL_GLDMODE_LoadZeroPeriod			// 4-1	: GLDMODE		; 0000(Load On Counter = Zero), 0001(Load On Counter = Period), 0010(Load On Counter = Zero or Counter = Period), 0011(Load On SYNCEVT), 0100(Load On Counter = Zero or SYNCEVT), 0101(Load On Counter = Period or SYNCEVT), 0110(Load On Counter = Zero or Counter = Period or SYNCEVT), 1111(GLBCTL2[GFRCLD]).
								| GLDCTL_GLD_GlobalShadowEnable;		// 0	: GLD			; 0(Individual Shadow Mode is Used), 1(Global Shadow Mode is Used).
		EPWM[ui_Index]->GLDCFG.all = GLDCFG_AQCSFRC_LocalLoad			// 10	: AQCSFRC		; 0(Use Local Reload), 1(Use Global Reload).
								| GLDCFG_AQCTLB_AQCTLB2_LocalLoad		// 9	: AQCTLB_AQCTLB2; 0(Use Local Reload), 1(Use Global Reload).
								| GLDCFG_AQCTLA_AQCTLA2_LocalLoad		// 8	: AQCTLA_AQCTLA2; 0(Use Local Reload), 1(Use Global Reload).
								| GLDCFG_DBCTL_LocalLoad				// 7	: DBCTL			; 0(Use Local Reload), 1(Use Global Reload).
								| GLDCFG_DBFED_DBFEDHR_LocalLoad		// 6	: DBFED_DBFEDHR	; 0(Use Local Reload), 1(Use Global Reload).
								| GLDCFG_DBRED_DBREDHR_LocalLoad		// 5	: DBRED_DBREFHR	; 0(Use Local Reload), 1(Use Global Reload).
								| GLDCFG_CMPD_LocalLoad					// 4	: CMPD			; 0(Use Local Reload), 1(Use Global Reload).
								| GLDCFG_CMPC_LocalLoad					// 3	: CMPC			; 0(Use Local Reload), 1(Use Global Reload).
								| GLDCFG_CMPB_CMPBHR_LocalLoad			// 2	: CMPB			; 0(Use Local Reload), 1(Use Global Reload).
								| GLDCFG_CMPA_CMPAHR_LocalLoad			// 1	: CMPA			; 0(Use Local Reload), 1(Use Global Reload).
								| GLDCFG_TBPRD_TBPRDHR_GlobalLoad;		// 0	: TBPRD_TBPRDHR	; 0(Use Local Reload), 1(Use Global Reload).
		EDIS;
	}

	// Event Triggers Initializing
	//// Event Triggers Initializing : A Phase
	////// Event Triggers Initializing : A Phase - SOCB Enable/Event
	EPWM[PWM_PHASE_A]->ETSEL.all = ETSEL_SOCBEN_SOCBDisable				// 15	: SOCBEN		; 0(Disable), 1(Enable).
								| ETSEL_SOCBSEL_EventZero				// 14-12: SOCBSEL		; 000(DCBECT1.SOC), 001(Counter = Zero), 010(Counter = Period), 011(Counter = Zero or Counter = Period), 100(Counter = CMPA/CMPC on UP), 101(Counter = CMPA/CMPC on Down), 110(Counter = CMPB/CMPD on UP), 111(Counter = CMPB/CMPD on Down).
								| ETSEL_SOCBSELCMP_SOCBByCMPAB			// 5	: SOCBSELCMP	; 0(CMPA and CMPB), 1(CMPC and CMPD).
	////// Event Triggers Initializing : A Phase - SOCA Enable/Event
								| ETSEL_SOCAEN_SOCADisable				// 11	: SOCAEN		; 0(Disable), 1(Enable).
								| ETSEL_SOCASEL_EventZero				// 10-8	: SOCASEL		; 000(DCAECT1.SOC), 001(Counter = Zero), 010(Counter = Period), 011(Counter = Zero or Counter = Period), 100(Counter = CMPA/CMPC on UP), 101(Counter = CMPA/CMPC on Down), 110(Counter = CMPB/CMPD on UP), 111(Counter = CMPB/CMPD on Down).
								| ETSEL_SOCASELCMP_SOCAByCMPAB			// 4	: SOCASELCMP	; 0(CMPA and CMPB), 1(CMPC and CMPD).
	////// Event Triggers Initializing : A Phase - INT Enable/Event
								| ETSEL_INTEN_InterruptEnable			// 3	: INTEN			; 0(Disable), 1(Enable).
								| ETSEL_INTSEL_EventZero				// 2-0	: INTSEL		; 001(Counter = Zero), 010(Counter = Period), 011(Counter = Zero or Counter = Period), 100(Counter = CMPA/CMPC on UP), 101(Counter = CMPA/CMPC on Down), 110(Counter = CMPB/CMPD on UP), 111(Counter = CMPB/CMPD on Down).
								| ETSEL_INTSELCMP_InterruptByCMPAB;		// 6	: INTSELCMP		; 0(CMPA and CMPB), 1(CMPC and CMPD).

	////// Event Triggers Initializing : A Phase - SOC A/B Pre-scale
	EPWM[PWM_PHASE_A]->ETPS.all = ETPS_SOCPSSEL_SOCxPRDUsed				//
								| ETPS_SOCBPRD_SOCBDisable				//
								| ETPS_SOCAPRD_SOCADisable				//
	////// Event Triggers Initializing : A Phase - SOC A/B Pre-scale
								| ETPS_INTPSSEL_INTPRDUsed				//
								| ETPS_INTPRD_INTFirstEvent;			//

	return;
}

#ifdef CPU1
void Start_ePWM(void)
{
	EALLOW;
	CpuSysRegs.PCLKCR0.all |= PCLKCR0_GTBCLKSYNC_PWMGlobalCLKEn;		// 19	: GTBCLKSYNC	; Start Time Base of All PWM Module.
	EDIS;

	return;
}
#endif
