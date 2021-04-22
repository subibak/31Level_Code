/*
 * FPGA_QEP.c
 *
 *  Created on: 2019. 6. 24.
 *      Author: HJHeo
 */

#include "Define_Header.h"
#include "Define_FPGA.h"

#ifdef CPU1
// Predefine
//// Predefine : QPE Module Selection.
#define M1QEPRegs						FpgaCs2Regs.QEP0

// External Value
extern S_STV M1Samp;
extern S_PRM M1Para;
extern S_THT M1Theta_Sens;
extern S_SPD M1Speed_Sens;

void Init_FPGA_QEP(void)
{
	M1QEPRegs.QEPCTRL.bit.RESET = 1U;								// 15		: RESET		; 0(Normal Mode), 1(Reset Mode).

	M1QEPRegs.DECCTRL.all = DECCTRL_QSRC_Encoder					// 15		: QSRC		; 0(Direction Count), 1(Encoder), 2(BLDC).
							| DECCTRL_XCR_2xCLK						// 12		: XCR		; 0(x2), 1(x1)
							| DECCTRL_SWAP_CAA_DBBNormal			// 11		: SWAP		; 0(CAA, DBB Normal), 1(CAA, DBB Swapped).
							| DECCTRL_QCAAP_CAANormal				// 10		: QCAAP		; 0(CAA Normal), 1(CAA Inverted).
							| DECCTRL_QDBBP_DBBNormal				// 9		: QDBBP		; 0(DBB Normal), 1(DBB Inverted).
							| DECCTRL_QIZCP_IZCNormal;				// 8		: QIZCP		; 0(IZC Normal), 1(IZC Inverted).
	M1QEPRegs.QEPCTRL.all = QEPCTRL_RESET_ResetMode					// 15		: RESET		; 0(Normal Mode), 1(Reset Mode).
							| QEPCTRL_PCRM_Index					// 12		: PCRM		; 0(Index), 1(Max Count).
							| QEPCTRL_SEI_REdge;					// 10		: SEI		; 0(Clear at Rising Edge), 1(Clear at Rising Edge with CW or Falling Edge with CCW).

	M1QEPRegs.QPOSINIT = 0U;										// 15:0		:
	M1QEPRegs.QPOSMAX = ((Uint16)M1Theta_Sens.COUNT.PPR - 1U);		// 15:0		:

	M1QEPRegs.QEPCTRL.bit.RESET = 0U;								// 15		: RESET		; 0(Normal Mode), 1(Reset Mode).

	return;
}

void M1Position_Read(void)
{
	float f_Temp;

	// Position & Direction Read.
	M1Theta_Sens.COUNT.now = BOUND((float)M1QEPRegs.QPOSCNT, M1Theta_Sens.COUNT.PPR, 0.0F);
	M1Theta_Sens.COUNT.dir = M1QEPRegs.QEPSTS.bit.DIR;

	// Mechanical Angle Calculation.
	f_Temp = M1Theta_Sens.COUNT.now * M1Theta_Sens.COUNT.INV_PPR;
	M1Theta_Sens.m_now = MPY2PIF32(f_Temp);

	// Electrical Angle Calculation.
	f_Temp *= M1Para.Pole_Pairs;
	M1Theta_Sens.e_now = MPY2PIF32(f_Temp - (float)((int)f_Temp)) - M1Theta_Sens.e_offset;
	M1Theta_Sens.e_now = SEMI_MOD(M1Theta_Sens.e_now, PI2);

	// Trigonometric Calculation.
	M1Theta_Sens.e_sin = SINF32(M1Theta_Sens.e_now);
	M1Theta_Sens.e_cos = COSF32(M1Theta_Sens.e_now);

	return;
}

void M1Speed_Cal(void)
{
	float f_M_data;

	// M Data Sampling.
	f_M_data = M1Theta_Sens.COUNT.now - M1Theta_Sens.COUNT.old;
	M1Theta_Sens.COUNT.old = M1Theta_Sens.COUNT.now;

	// Speed Calculation
	if ((M1Theta_Sens.COUNT.dir == 0U) && (f_M_data < 0)) {
		M1Speed_Sens.RPM.now = (f_M_data + M1Theta_Sens.COUNT.PPR) * M1Theta_Sens.COUNT.INV_PPR * M1Samp.OUTERLOOP.FREQ * 60.0F;
	} else if ((M1Theta_Sens.COUNT.dir == 1U) && (f_M_data > 0)) {
		M1Speed_Sens.RPM.now = (f_M_data - M1Theta_Sens.COUNT.PPR) * M1Theta_Sens.COUNT.INV_PPR * M1Samp.OUTERLOOP.FREQ * 60.0F;
	} else {
		M1Speed_Sens.RPM.now = f_M_data * M1Theta_Sens.COUNT.INV_PPR * M1Samp.OUTERLOOP.FREQ * 60.0F;
	}

	// Low Pass Filter.
	LPF(M1Speed_Sens.RPM);

	// Angle Speed Calculation.
	M1Speed_Sens.Wm.low = M1Speed_Sens.RPM.low * NUM_PI2_DEN_60;
	M1Speed_Sens.We.low = M1Speed_Sens.Wm.low * M1Para.Pole_Pairs;

	return;
}

#endif
