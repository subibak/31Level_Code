/*
 * SFOPWM.c
 *
 *  Created on: 2019. 7. 3.
 *      Author: HJHeo
 */

#include "Define_Header.h"
#include "Define_SFOPWM.h"
#include "Define_Control.h"

#ifdef CPU1
// Predefine
//// Predefine : Control Value
#define MxSamp							M1Samp
#define MxFlag							M1Flag

//// Predefine : Control Gain
#define MxKoff							M1Koff

//// Predefine : Current Value
#define MxIe							M1Ie

//// Predefine : Voltage Value
#define MxVe_ref						M1Ve_ref
#define MxVs_ref						M1Vs_ref
#define MxVp_ref						M1Vp_ref
#define MxVn_ref						M1Vn_ref

#define MxVs							M1Vs
#define MxVe							M1Ve

#define MxNn_ref						M1Nn_ref
#define MxCMPu							M1CMPu
#define MxCMPl							M1CMPl

// External Value
//// External Value : Control Value
extern S_STV M1Samp;
extern S_FLG M1Flag;

//// External Value : Control Gain
extern float M1Koff;

//// External Value : Current Value
extern S_FDQ M1Ie;

//// External Value : Voltage Value
extern S_FDQ M1Ve_ref, M1Vs_ref;
extern S_FTP M1Vp_ref;
extern S_FPL M1Vn_ref;

extern S_FDQ M1Vs, M1Ve;

extern S_FPL M1Nn_ref;

extern S_UTP M1CMPu, M1CMPl;
#endif

#ifdef CPU2
// Predefine
//// Predefine : Control Value
#define MxSamp							M2Samp
#define MxFlag							M2Flag

//// Predefine : Control Gain
#define MxKoff							M2Koff

//// Predefine : Current Value
#define MxIe							M2Ie

//// Predefine : Voltage Value
#define MxVe_ref						M2Ve_ref
#define MxVs_ref						M2Vs_ref
#define MxVp_ref						M2Vp_ref
#define MxVn_ref						M2Vn_ref

#define MxVs							M2Vs
#define MxVe							M2Ve

#define MxNn_ref						M2Nn_ref
#define MxCMPu							M2CMPu
#define MxCMPl							M2CMPl

// External Value
//// External Value : Control Value
extern S_STV M2Samp;
extern S_FLG M2Flag;

//// External Value : Control Gain
extern float M2Koff;

//// External Value : Current Value
extern S_FDQ M2Ie;

//// External Value : Voltage Value
extern S_FDQ M2Ve_ref, M2Vs_ref;
extern S_FTP M2Vp_ref;
extern S_FPL M2Vn_ref;

extern S_FDQ M2Vs, M2Ve;

extern S_FPL M2Nn_ref;

extern S_UTP M2CMPu, M2CMPl;
#endif

// External Value
extern S_VDC Vdc;

void SFOPWM(void)
{
	float f_MxVmax, f_MxVmin, f_MxVamp;
	float f_MxKom = 1.0F;
	float f_MxVoff, f_MxVmar;
	int i_MxCMPa, i_MxCMPb, i_MxCMPc;

	// Sorting.
	if (MxVp_ref.a >= MxVp_ref.b) {
		f_MxVmax = MxVp_ref.a;
		f_MxVmin = MxVp_ref.b;
	} else {
		f_MxVmax = MxVp_ref.b;
		f_MxVmin = MxVp_ref.a;
	}

	if (MxVp_ref.c > f_MxVmax) {
		f_MxVmax = MxVp_ref.c;
	}

	if (MxVp_ref.c < f_MxVmin) {
		f_MxVmin = MxVp_ref.c;
	}

	// SFOPWM with Over Modulation.
	MxVn_ref.s = -0.5F * (f_MxVmax + f_MxVmin);
	f_MxVamp = f_MxVmax - f_MxVmin;
	if (f_MxVamp > Vdc.dc.low) {
		// Flag for Over Modulation.
		MxFlag.OM = 1U;

		// Reference Modify.
		f_MxKom = DIVF32(Vdc.dc.low, f_MxVamp);
		f_MxVamp = Vdc.dc.low;

		MxVp_ref.a *= f_MxKom;
		MxVp_ref.b *= f_MxKom;
		MxVp_ref.c *= f_MxKom;
		MxVn_ref.s *= f_MxKom;

		// Anti-WindUp
		Vabc2dqe();
	} else {
		// Flag for Over Modulation.
		MxFlag.OM = 0U;

		// Anti-WindUp
		//// Anti-WindUp : DQS.
		MxVs.d = MxVs_ref.d;
		MxVs.q = MxVs_ref.q;

		//// Anti-WindUp : DQE.
		MxVe.d = MxVe_ref.d;
		MxVe.q = MxVe_ref.q;
	}

	// Offset Voltage
	f_MxVoff = MxKoff * Vdc.diff.low * FSIGN(MxVe.d * MxIe.d + MxVe.q * MxIe.q) + 0.5F * Vdc.diff.low;
	f_MxVmar = 0.5F * (Vdc.dc.low - f_MxVamp);
	MxVn_ref.s += BOUND(f_MxVoff, f_MxVmar, -f_MxVmar);

	// Pole Voltage.
	MxVn_ref.a = MxVp_ref.a + MxVn_ref.s;
	MxVn_ref.b = MxVp_ref.b + MxVn_ref.s;
	MxVn_ref.c = MxVp_ref.c + MxVn_ref.s;

	// Normalized Pole Voltage
	if (MxVn_ref.a >= 0.0F) {
		MxNn_ref.a = MxVn_ref.a * Vdc.p.INV_low;
	} else {
		MxNn_ref.a = MxVn_ref.a * Vdc.n.INV_low;
	}

	if (MxVn_ref.b >= 0.0F) {
		MxNn_ref.b = MxVn_ref.b * Vdc.p.INV_low;
	} else {
		MxNn_ref.b = MxVn_ref.b * Vdc.n.INV_low;
	}

	if (MxVn_ref.c >= 0.0F) {
		MxNn_ref.c = MxVn_ref.c * Vdc.p.INV_low;
	} else {
		MxNn_ref.c = MxVn_ref.c * Vdc.n.INV_low;
	}

	// Compare Value
	i_MxCMPa = (int16)(MxNn_ref.a * (float)MxSamp.PWM.PERIOD);
	i_MxCMPb = (int16)(MxNn_ref.b * (float)MxSamp.PWM.PERIOD);
	i_MxCMPc = (int16)(MxNn_ref.c * (float)MxSamp.PWM.PERIOD);

	MxCMPu.a = (Uint16)BOUND(i_MxCMPa, (int16)MxSamp.PWM.PERIOD, 0);
	MxCMPl.a = (Uint16)BOUND((int16)MxSamp.PWM.PERIOD + i_MxCMPa, (int16)MxSamp.PWM.PERIOD, 0);
	MxCMPu.b = (Uint16)BOUND(i_MxCMPb, (int16)MxSamp.PWM.PERIOD, 0);
	MxCMPl.b = (Uint16)BOUND((int16)MxSamp.PWM.PERIOD + i_MxCMPb, (int16)MxSamp.PWM.PERIOD, 0);
	MxCMPu.c = (Uint16)BOUND(i_MxCMPc, (int16)MxSamp.PWM.PERIOD, 0);
	MxCMPl.c = (Uint16)BOUND((int16)MxSamp.PWM.PERIOD + i_MxCMPc, (int16)MxSamp.PWM.PERIOD, 0);

	return;
}
