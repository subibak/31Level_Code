/*
 * NSFOPWM.c
 *
 *  Created on: 2019. 7. 3.
 *      Author: HJHeo
 */

#include "Define_Header.h"
#include "Define_NSFOPWM.h"
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

#define MxVs							M1Vs
#define MxVe							M1Ve

#define MxNp_ref						M1Np_ref
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

extern S_FDQ M1Vs, M1Ve;

extern S_FTP M1Np_ref;
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

#define MxVs							M2Vs
#define MxVe							M2Ve

#define MxNp_ref						M2Np_ref
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

extern S_FDQ M2Vs, M2Ve;

extern S_FTP M2Np_ref;
extern S_FPL M2Nn_ref;

extern S_UTP M2CMPu, M2CMPl;
#endif

extern S_VDC Vdc;

void NSFOPWM(void)
{
	float f_MxVdca, f_MxVdcb, f_MxVdcc;
	float f_MxNmax, f_MxNmin, f_MxNamp;
	float f_MxKom = 1.0F;
	float f_MxNoff, f_MxNmar;
	int i_MxCMPa, i_MxCMPb, i_MxCMPc;

	// Normalization.
	//// Normalization : DC-Link Voltage Selection and Normalization.
	if (MxVp_ref.a >= 0.0F) {
		f_MxVdca = Vdc.p.low;
		MxNp_ref.a = MxVp_ref.a * Vdc.p.INV_low;
	} else {
		f_MxVdca = Vdc.n.low;
		MxNp_ref.a = MxVp_ref.a * Vdc.n.INV_low;
	}

	if (MxVp_ref.b >= 0.0F) {
		f_MxVdcb = Vdc.p.low;
		MxNp_ref.b = MxVp_ref.b * Vdc.p.INV_low;
	} else {
		f_MxVdcb = Vdc.n.low;
		MxNp_ref.b = MxVp_ref.b * Vdc.n.INV_low;
	}

	if (MxVp_ref.c >= 0.0F) {
		f_MxVdcc = Vdc.p.low;
		MxNp_ref.c = MxVp_ref.c * Vdc.p.INV_low;
	} else {
		f_MxVdcc = Vdc.n.low;
		MxNp_ref.c = MxVp_ref.c * Vdc.n.INV_low;
	}

	// Sorting.
	if (MxNp_ref.a > MxNp_ref.b) {
		f_MxNmax = MxNp_ref.a;
		f_MxNmin = MxNp_ref.b;
	} else {
		f_MxNmax = MxNp_ref.b;
		f_MxNmin = MxNp_ref.a;
	}

	if (MxNp_ref.c > f_MxNmax) {
		f_MxNmax = MxNp_ref.c;
	}
	if (MxNp_ref.c < f_MxNmin) {
		f_MxNmin = MxNp_ref.c;
	}

	// SFOPWM with Over Modulation.
	MxNn_ref.s = -0.5F * (f_MxNmax + f_MxNmin);
	f_MxNamp = f_MxNmax - f_MxNmin;
	if (f_MxNamp > 2.0F) {
		// Flag for Over Modulation.
		MxFlag.OM = 1U;

		// Reference Modify.
		f_MxKom = DIVF32(2.0F, f_MxNamp);
		f_MxNamp = 2.0F;

		MxNp_ref.a *= f_MxKom;
		MxNp_ref.b *= f_MxKom;
		MxNp_ref.c *= f_MxKom;
		MxNn_ref.s *= f_MxKom;

		// Anti-WindUp
		//// Anti-WindUp : Phase Voltage.
		MxVp_ref.a = MxNp_ref.a * f_MxVdca;
		MxVp_ref.b = MxNp_ref.b * f_MxVdcb;
		MxVp_ref.c = MxNp_ref.c * f_MxVdcc;

		//// Anti-WindUp : ABC to DQE Conversion.
		Vabc2dqe();
	} else {
		// Flag for Over Modulation.
		MxFlag.OM = 0U;

		// Anti-WindUp.
		//// Anti-WindUp : DQS.
		MxVs.d = MxVs_ref.d;
		MxVs.q = MxVs_ref.q;

		//// Anti-WindUp : DQE.
		MxVe.d = MxVe_ref.d;
		MxVe.q = MxVe_ref.q;
	}

	// Offset Normalized Offset Voltage
	f_MxNoff = MxKoff * Vdc.diff.low * Vdc.dc.INV_low * FSIGN(MxVe.d * MxIe.d + MxVe.q * MxIe.q);
	f_MxNmar = 1.0F - 0.5F * f_MxNamp;
	MxNn_ref.s += BOUND(f_MxNoff, f_MxNmar, -f_MxNmar);

	// Normalized Pole Voltage.
	MxNn_ref.a = MxNp_ref.a + MxNn_ref.s;
	MxNn_ref.b = MxNp_ref.b + MxNn_ref.s;
	MxNn_ref.c = MxNp_ref.c + MxNn_ref.s;

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
