/*
 * FPGA_PWM.c
 *
 *  Created on: 2018. 11. 19.
 *      Author: HJHeo
 */

#include "Define_Header.h"
#include "Define_FPGA.h"

#ifdef CPU1

// Predefine.
//// Predefine : The Number of Used Modules and Module Indexes.
#define	M1PWM_MAX				6										// The Number of Used Modules.
#define M1PWM_PHASE_AT			0										// A-Phase Top Index.
#define M1PWM_PHASE_AB			1										// A-Phase Bottom Index.
#define M1PWM_PHASE_BT			2										// B-Phase Top Index.
#define M1PWM_PHASE_BB			3										// B-Phase Bottom Index.
#define M1PWM_PHASE_CT			4										// C-Phase Top Index.
#define M1PWM_PHASE_CB			5										// C-Phase Bottom Index.

#define M2PWM_MAX				6										// The Number of Used Modules.
#define M2PWM_PHASE_AT			0										// A-Phase Top Index.
#define M2PWM_PHASE_AB			1										// A-Phase Bottom Index.
#define M2PWM_PHASE_BT			2										// B-Phase Top Index.
#define M2PWM_PHASE_BB			3										// B-Phase Bottom Index.
#define M2PWM_PHASE_CT			4										// C-Phase Top Index.
#define M2PWM_PHASE_CB			5										// C-Phase Bottom Index.

//// Predefine : Control Value
#define GR0Samp					M1Samp
#define GR0Nn_ref				M1Nn_ref

#define GR1Samp					M2Samp
#define GR1Nn_ref				M2Nn_ref

// Variable
//// Variable : FPGA PWM Register.
volatile struct FPGA_PWM_REGS	*M1PWM[M1PWM_MAX] = {&FpgaCs2Regs.PWM0, &FpgaCs2Regs.PWM1,
													 &FpgaCs2Regs.PWM2, &FpgaCs2Regs.PWM3,
													 &FpgaCs2Regs.PWM4, &FpgaCs2Regs.PWM5};
volatile struct FPGA_PWM_REGS	*M2PWM[M2PWM_MAX] = {&FpgaCs2Regs.PWM6, &FpgaCs2Regs.PWM7,
													 &FpgaCs2Regs.PWM8, &FpgaCs2Regs.PWM9,
													 &FpgaCs2Regs.PWM10, &FpgaCs2Regs.PWM11};

// External Variable
//// External Variable : Sampling Time Value.
extern S_STV M1Samp, M2Samp;
extern S_FTP M1Nn_ref, M2Nn_ref;
extern S_UTP M1CMPu, M1CMPl;
extern S_UTP M2CMPu, M2CMPl;

void Init_FPGA_PWM(void)
{
	Uint16 ui_index;

	// Master PWM Clock Disable for PWM Synch.
	FpgaCs2Regs.PWMCLK.MSTCTRL.all = MSTCTRL_MSTCLKEN_MSTCLKDis;		// 15	: MSTCLKEN	; 0(All PWMCLK Disable), 1(All PWMCLK Enable).

	// Each PWM Module Clock Source.
	FpgaCs2Regs.PWMCLK.CLKSRC1.all = CLKSRC1_PWM11SRC_EMIFxCLK			// 13-12: PWM11SRC	; 0(Non-CLK), 1(EMIF1CLK), 2(2.4EMIF1CLK), 3(3.0EMIF1CLK).
									| CLKSRC1_PWM10SRC_EMIFxCLK			// 11-10: PWM10SRC	; 0(Non-CLK), 1(EMIF1CLK), 2(2.4EMIF1CLK), 3(3.0EMIF1CLK).
									| CLKSRC1_PWM9SRC_EMIFxCLK			// 9-8	: PWM9SRC	; 0(Non-CLK), 1(EMIF1CLK), 2(2.4EMIF1CLK), 3(3.0EMIF1CLK).
									| CLKSRC1_PWM8SRC_EMIFxCLK			// 5-4	: PWM8SRC	; 0(Non-CLK), 1(EMIF1CLK), 2(2.4EMIF1CLK), 3(3.0EMIF1CLK).
									| CLKSRC1_PWM7SRC_EMIFxCLK			// 3-2	: PWM7SRC	; 0(Non-CLK), 1(EMIF1CLK), 2(2.4EMIF1CLK), 3(3.0EMIF1CLK).
									| CLKSRC1_PWM6SRC_EMIFxCLK;			// 1-0	: PWM6SRC	; 0(Non-CLK), 1(EMIF1CLK), 2(2.4EMIF1CLK), 3(3.0EMIF1CLK).
	FpgaCs2Regs.PWMCLK.CLKSRC0.all = CLKSRC0_PWM5SRC_EMIFxCLK			// 13-12: PWM5SRC	; 0(Non-CLK), 1(EMIF1CLK), 2(2.4EMIF1CLK), 3(3.0EMIF1CLK).
									| CLKSRC0_PWM4SRC_EMIFxCLK			// 11-10: PWM4SRC	; 0(Non-CLK), 1(EMIF1CLK), 2(2.4EMIF1CLK), 3(3.0EMIF1CLK).
									| CLKSRC0_PWM3SRC_EMIFxCLK			// 9-8	: PWM3SRC	; 0(Non-CLK), 1(EMIF1CLK), 2(2.4EMIF1CLK), 3(3.0EMIF1CLK).
									| CLKSRC0_PWM2SRC_EMIFxCLK	    	// 5-4	: PWM2SRC	; 0(Non-CLK), 1(EMIF1CLK), 2(2.4EMIF1CLK), 3(3.0EMIF1CLK).
									| CLKSRC0_PWM1SRC_EMIFxCLK			// 3-2	: PWM1SRC	; 0(Non-CLK), 1(EMIF1CLK), 2(2.4EMIF1CLK), 3(3.0EMIF1CLK).
									| CLKSRC0_PWM0SRC_EMIFxCLK;	    	// 1-0	: PWM0SRC	; 0(Non-CLK), 1(EMIF1CLK), 2(2.4EMIF1CLK), 3(3.0EMIF1CLK).

	// PWMx Setting.
	for (ui_index = 0; ui_index < M1PWM_MAX; ui_index++) {
		// PWMx Disable for PWM Setting.
		M1PWM[ui_index]->TBCTRL.bit.RESET = 1;							// 15	: RESET		; 0(Normal Mode), 1(Reset Mode).
		M2PWM[ui_index]->TBCTRL.bit.RESET = 1;							// 15	: RESET		; 0(Normal Mode), 1(Reset Mode).

		// PWMx Time-Base.
		M1PWM[ui_index]->TBCTRL.all = TBCTRL_RESET_ResetMode			// 15	: RESET		; 0(Normal Mode), 1(Reset Mode).
									| TBCTRL_PRDLOADMODE_Zero			// 13-12: PRDLDMODE	; 0(Shadow Disable), 1(Load at Zero).
									| TBCTRL_PHSEN_PHSDis				// 10	: PHSEN		; 0(Phase Disable), (Phase Enable).
									| TBCTRL_PHSDIR_UpCount				// 9	: PHSDIR	; 0(Up Count), 1(Down Count).
									| TBCTRL_DIR_UpCount				// 8	: DIR		; 0(Up Count), 1(Down Count).
									| TBCTRL_PREDIV_DIV(0);				// 7-0	: PREDIV	; PWMCLK = SRCCLK / (PREDIV + 1) / 2.
		M2PWM[ui_index]->TBCTRL.all = TBCTRL_RESET_ResetMode			// 15	: RESET		; 0(Normal Mode), 1(Reset Mode).
									| TBCTRL_PRDLOADMODE_Zero			// 13-12: PRDLDMODE	; 0(Shadow Disable), 1(Load at Zero).
									| TBCTRL_PHSEN_PHSDis				// 10	: PHSEN		; 0(Phase Disable), (Phase Enable).
									| TBCTRL_PHSDIR_UpCount				// 9	: PHSDIR	; 0(Up Count), 1(Down Count).
									| TBCTRL_DIR_UpCount				// 8	: DIR		; 0(Up Count), 1(Down Count).
									| TBCTRL_PREDIV_DIV(0);				// 7-0	: PREDIV	; PWMCLK = SRCCLK / (PREDIV + 1) / 2.

		M1PWM[ui_index]->TBCNT = 0;										// 15-0	: TBCNT		; 0x0000 ~ 0xFFFF
		M1PWM[ui_index]->TBPRD = M1Samp.PWM.PERIOD;						// 15-0	: TBPRD		; SWCLK = TBCLK / TBPRD / 2.
		M2PWM[ui_index]->TBCNT = 0;										// 15-0	: TBCNT		; 0x0000 ~ 0xFFFF
		M2PWM[ui_index]->TBPRD = M2Samp.PWM.PERIOD;						// 15-0	: TBPRD		; SWCLK = TBCLK / TBPRD / 2.
																		//					; 10[kHz] = 300[MHz] / 15000 / 2.

		// PWMx Comparator.
		M1PWM[ui_index]->CMPCTRL.all = CMPCTRL_CMPDLOADMODE_Hold		// 13-12: CMPDLDMODE; 0(Shadow Disable), 1(Load at Zero), 2(Load at Period), 3(Load at Zero or Period).
									| CMPCTRL_CMPCLOADMODE_ZeroPeriod	// 9-8	: CMPCLDMODE; 0(Shadow Disable), 1(Load at Zero), 2(Load at Period), 3(Load at Zero or Period).
									| CMPCTRL_CMPBLOADMODE_ZeroPeriod	// 5-4	: CMPBLDMODE; 0(Shadow Disable), 1(Load at Zero), 2(Load at Period), 3(Load at Zero or Period).
									| CMPCTRL_CMPALOADMODE_ZeroPeriod;	// 1-0	: CMPALDMODE; 0(Shadow Disable), 1(Load at Zero), 2(Load at Period), 3(Load at Zero or Period).
		M2PWM[ui_index]->CMPCTRL.all = CMPCTRL_CMPDLOADMODE_Hold		// 13-12: CMPDLDMODE; 0(Shadow Disable), 1(Load at Zero), 2(Load at Period), 3(Load at Zero or Period).
									| CMPCTRL_CMPCLOADMODE_ZeroPeriod	// 9-8	: CMPCLDMODE; 0(Shadow Disable), 1(Load at Zero), 2(Load at Period), 3(Load at Zero or Period).
									| CMPCTRL_CMPBLOADMODE_ZeroPeriod	// 5-4	: CMPBLDMODE; 0(Shadow Disable), 1(Load at Zero), 2(Load at Period), 3(Load at Zero or Period).
									| CMPCTRL_CMPALOADMODE_ZeroPeriod;	// 1-0	: CMPALDMODE; 0(Shadow Disable), 1(Load at Zero), 2(Load at Period), 3(Load at Zero or Period).

		M1PWM[ui_index]->CMPA = M1Samp.PWM.PERIOD_HALF;					// 15-0	: CMPA		; Comparator A.
		M2PWM[ui_index]->CMPA = M2Samp.PWM.PERIOD_HALF;					// 15-0	: CMPA		; Comparator A.

		// PWMx Action Qualifier.
		M1PWM[ui_index]->AQCTRL0.all = AQCTRLx_AQLOADMODE_ZeroPeriod	// 15-14: AQLDMODE	; 0(Shadow Disable), 1(Load at Zero), 2(Load at Period), 3(Load at Zero or Period).
									| AQCTRLx_CBD_Nothing				// 11-10: CBD		; 0(Nothing), 1(Clear), 2(Set), 3(Toggle).
									| AQCTRLx_CBU_Nothing				// 9-8	: CBU		; 0(Nothing), 1(Clear), 2(Set), 3(Toggle).
									| AQCTRLx_CAD_Set					// 7-6	: CAD		; 0(Nothing), 1(Clear), 2(Set), 3(Toggle).
									| AQCTRLx_CAU_Clear					// 5-4	: CAU		; 0(Nothing), 1(Clear), 2(Set), 3(Toggle).
									| AQCTRLx_PRD_Nothing				// 3-2	: PRD		; 0(Nothing), 1(Clear), 2(Set), 3(Toggle).
									| AQCTRLx_ZRO_Nothing;				// 1-0	: ZRO		; 0(Nothing), 1(Clear), 2(Set), 3(Toggle).
		M1PWM[ui_index]->AQCTRL1.all = AQCTRLx_AQLOADMODE_ZeroPeriod	// 15-14: AQLDMODE	; 0(Shadow Disable), 1(Load at Zero), 2(Load at Period), 3(Load at Zero or Period).
									| AQCTRLx_CBD_Nothing				// 11-10: CBD		; 0(Nothing), 1(Clear), 2(Set), 3(Toggle).
									| AQCTRLx_CBU_Nothing				// 9-8	: CBU		; 0(Nothing), 1(Clear), 2(Set), 3(Toggle).
									| AQCTRLx_CAD_Nothing				// 7-6	: CAD		; 0(Nothing), 1(Clear), 2(Set), 3(Toggle).
									| AQCTRLx_CAU_Nothing				// 5-4	: CAU		; 0(Nothing), 1(Clear), 2(Set), 3(Toggle).
									| AQCTRLx_PRD_Nothing				// 3-2	: PRD		; 0(Nothing), 1(Clear), 2(Set), 3(Toggle).
									| AQCTRLx_ZRO_Nothing;				// 1-0	: ZRO		; 0(Nothing), 1(Clear), 2(Set), 3(Toggle).
		M2PWM[ui_index]->AQCTRL0.all = AQCTRLx_AQLOADMODE_ZeroPeriod	// 15-14: AQLDMODE	; 0(Shadow Disable), 1(Load at Zero), 2(Load at Period), 3(Load at Zero or Period).
									| AQCTRLx_CBD_Nothing				// 11-10: CBD		; 0(Nothing), 1(Clear), 2(Set), 3(Toggle).
									| AQCTRLx_CBU_Nothing				// 9-8	: CBU		; 0(Nothing), 1(Clear), 2(Set), 3(Toggle).
									| AQCTRLx_CAD_Set					// 7-6	: CAD		; 0(Nothing), 1(Clear), 2(Set), 3(Toggle).
									| AQCTRLx_CAU_Clear					// 5-4	: CAU		; 0(Nothing), 1(Clear), 2(Set), 3(Toggle).
									| AQCTRLx_PRD_Nothing				// 3-2	: PRD		; 0(Nothing), 1(Clear), 2(Set), 3(Toggle).
									| AQCTRLx_ZRO_Nothing;				// 1-0	: ZRO		; 0(Nothing), 1(Clear), 2(Set), 3(Toggle).
		M2PWM[ui_index]->AQCTRL1.all = AQCTRLx_AQLOADMODE_ZeroPeriod	// 15-14: AQLDMODE	; 0(Shadow Disable), 1(Load at Zero), 2(Load at Period), 3(Load at Zero or Period).
									| AQCTRLx_CBD_Nothing				// 11-10: CBD		; 0(Nothing), 1(Clear), 2(Set), 3(Toggle).
									| AQCTRLx_CBU_Nothing				// 9-8	: CBU		; 0(Nothing), 1(Clear), 2(Set), 3(Toggle).
									| AQCTRLx_CAD_Nothing				// 7-6	: CAD		; 0(Nothing), 1(Clear), 2(Set), 3(Toggle).
									| AQCTRLx_CAU_Nothing				// 5-4	: CAU		; 0(Nothing), 1(Clear), 2(Set), 3(Toggle).
									| AQCTRLx_PRD_Nothing				// 3-2	: PRD		; 0(Nothing), 1(Clear), 2(Set), 3(Toggle).
									| AQCTRLx_ZRO_Nothing;				// 1-0	: ZRO		; 0(Nothing), 1(Clear), 2(Set), 3(Toggle).

		// PWMx Dead-Time.
		M1PWM[ui_index]->DTCTRL.all = DTCTRL_REDIN_PWM0					// 0	: REDIN		; 0(PWM0), 1(PWM1).
									| DTCTRL_FEDIN_PWM0					// 1	: FEDIN		; 0(PWM0), 1(PWM1).
									| DTCTRL_HLINE_RED					// 4	: HLINE		; 0(RED), 1(FED).
									| DTCTRL_HINV_Normal				// 5	: HINV		; 0(Normal), 1(Invert).
									| DTCTRL_HEN_En						// 6	: HEN		; 0(Disable), 1(Enable).
									| DTCTRL_HDISSTS_Low				// 7	: HDISSTS	; 0(Low at HEN Disable), 1(High at HEN Disable).
									| DTCTRL_LLINE_FED					// 8	: LLINE		; 0(RED), 1(FED).
									| DTCTRL_LINV_Invert				// 9	: LINV		; 0(Normal), 1(Invert).
									| DTCTRL_LEN_En						// 10	: LEN		; 0(Disable), 1(Enable).
									| DTCTRL_LDISSTS_Low				// 11	: LDISSTS	; 0(Low at HEN Disable), 1(High at HEN Disable).
									| DTCTRL_DTLOADMODE_ZeroPeriod;		// 13-12: DTLDMODE	; 0(Shadow Disable), 1(Load at Zero), 2(Load at Period), 3(Load at Zero or Period).
		M2PWM[ui_index]->DTCTRL.all = DTCTRL_REDIN_PWM0					// 0	: REDIN		; 0(PWM0), 1(PWM1).
									| DTCTRL_FEDIN_PWM0					// 1	: FEDIN		; 0(PWM0), 1(PWM1).
									| DTCTRL_HLINE_RED					// 4	: HLINE		; 0(RED), 1(FED).
									| DTCTRL_HINV_Normal				// 5	: HINV		; 0(Normal), 1(Invert).
									| DTCTRL_HEN_En						// 6	: HEN		; 0(Disable), 1(Enable).
									| DTCTRL_HDISSTS_Low				// 7	: HDISSTS	; 0(Low at HEN Disable), 1(High at HEN Disable).
									| DTCTRL_LLINE_FED					// 8	: LLINE		; 0(RED), 1(FED).
									| DTCTRL_LINV_Invert				// 9	: LINV		; 0(Normal), 1(Invert).
									| DTCTRL_LEN_En						// 10	: LEN		; 0(Disable), 1(Enable).
									| DTCTRL_LDISSTS_Low				// 11	: LDISSTS	; 0(Low at HEN Disable), 1(High at HEN Disable).
									| DTCTRL_DTLOADMODE_ZeroPeriod;		// 13-12: DTLDMODE	; 0(Shadow Disable), 1(Load at Zero), 2(Load at Period), 3(Load at Zero or Period).

		M1PWM[ui_index]->REDPRD = M1Samp.DEADTIME.PERIOD;				// 15-0	: REDPRD	; Rising Edge Dead-Time.
		M1PWM[ui_index]->FEDPRD = M1Samp.DEADTIME.PERIOD;				// 15-0 : FEDPRD	; Falling Edge Dead-Time.
		M2PWM[ui_index]->REDPRD = M2Samp.DEADTIME.PERIOD;				// 15-0	: REDPRD	; Rising Edge Dead-Time.
		M2PWM[ui_index]->FEDPRD = M2Samp.DEADTIME.PERIOD;				// 15-0 : FEDPRD	; Falling Edge Dead-Time.

		// PWMx Enable for Normal Operation.
		M1PWM[ui_index]->TBCTRL.bit.RESET = 0;							// 15	: RESET		; 0(Normal Mode), 1(Reset Mode).
		M2PWM[ui_index]->TBCTRL.bit.RESET = 0;							// 15	: RESET		; 0(Normal Mode), 1(Reset Mode).
	}

	// Event Trigger.
	M1PWM[M1PWM_PHASE_AT]->ETCTRL.all = ETCTRL_ETLOADMODE_ZeroPeriod	// 15-14: ETLDMODE	; 0(Shadow Disable), 1(Load at Zero), 2(Load at Period), 3(Load at Zero or Period).
										| ETCTRL_SOCDSRC_None			// 11-9	: SOCDSRC	; 0(Non), 1(Zero), 2(Period), 3(CCU), 4(CCD), 5(CDU), 6(CDD).
										| ETCTRL_SOCCSRC_None			// 8-6	: SOCCSRC	; 0(Non), 1(Zero), 2(Period), 3(CCU), 4(CCD), 5(CDU), 6(CDD).
										| ETCTRL_SOCBSRC_None			// 5-3	: SOCBSRC	; 0(Non), 1(Zero), 2(Period), 3(CCU), 4(CCD), 5(CDU), 6(CDD).
										| ETCTRL_SOCASRC_None;			// 2-0	: SOCASRC	; 0(Non), 1(Zero), 2(Period), 3(CCU), 4(CCD), 5(CDU), 6(CDD).
	M2PWM[M2PWM_PHASE_AT]->ETCTRL.all = ETCTRL_ETLOADMODE_ZeroPeriod	// 15-14: ETLDMODE	; 0(Shadow Disable), 1(Load at Zero), 2(Load at Period), 3(Load at Zero or Period).
										| ETCTRL_SOCDSRC_None			// 11-9	: SOCDSRC	; 0(Non), 1(Zero), 2(Period), 3(CCU), 4(CCD), 5(CDU), 6(CDD).
										| ETCTRL_SOCCSRC_None			// 8-6	: SOCCSRC	; 0(Non), 1(Zero), 2(Period), 3(CCU), 4(CCD), 5(CDU), 6(CDD).
										| ETCTRL_SOCBSRC_None			// 5-3	: SOCBSRC	; 0(Non), 1(Zero), 2(Period), 3(CCU), 4(CCD), 5(CDU), 6(CDD).
										| ETCTRL_SOCASRC_None;			// 2-0	: SOCASRC	; 0(Non), 1(Zero), 2(Period), 3(CCU), 4(CCD), 5(CDU), 6(CDD).

	return;
}

void Start_FPGA_PWM(void)
{
	// Each PWM Module Clock Source Enable.
	FpgaCs2Regs.PWMCLK.PWMEN.all = PWMEN_PWM3GREN_CLKEn					// 15	: PWM3GREN	; 1(PWM9 ~ 11 Enable).
								| PWMEN_PWM2GREN_CLKEn					// 14	: PWM2GREN	; 1(PWM6 ~ 8 Enable).
								| PWMEN_PWM1GREN_CLKEn					// 13	: PWM1GREN	; 1(PWM3 ~ 5 Enable).
								| PWMEN_PWM0GREN_CLKEn;					// 12	: PWM0GREN	; 1(PWM0 ~ 2 Enable).

	FpgaCs2Regs.PWMCLK.MSTCTRL.all = MSTCTRL_MSTCLKEN_MSTCLKEn;			// 15	: MSTCLKEN	; 0(All PWMCLK Disable), 1(All PWMCLK Enable).

	return;
}

void LV3Out_FPGA_PWM(void)
{
	FpgaCs2Regs.PWM0.CMPA = M1CMPu.a;
	FpgaCs2Regs.PWM1.CMPA = M1CMPl.a;
	FpgaCs2Regs.PWM2.CMPA = M1CMPu.b;
	FpgaCs2Regs.PWM3.CMPA = M1CMPl.b;
	FpgaCs2Regs.PWM4.CMPA = M1CMPu.c;
	FpgaCs2Regs.PWM5.CMPA = M1CMPl.c;

#if (CPU2_BOOT_ENABLE)
	while(IpcRegs.IPCSTS.bit.IPC30 == 0);
	IpcRegs.IPCACK.all = IPCxxx_IPC30;

	FpgaCs2Regs.PWM6.CMPA = M2CMPu.a;
	FpgaCs2Regs.PWM7.CMPA = M2CMPl.a;
	FpgaCs2Regs.PWM8.CMPA = M2CMPu.b;
	FpgaCs2Regs.PWM9.CMPA = M2CMPl.b;
	FpgaCs2Regs.PWM10.CMPA = M2CMPu.c;
	FpgaCs2Regs.PWM11.CMPA = M2CMPl.c;
#endif

	return;
}

#endif
