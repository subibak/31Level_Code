/*
 * Control.c
 *
 *  Created on: 2019. 6. 27.
 *      Author: HJHeo
 */

#include "Define_Header.h"
#include "Define_Control.h"

#ifdef CPU1
// Predefine
//// Predefine : Control Value
#define MxSamp				M1Samp
#define MxPara				M1Para
#define MxCont				M1Cont
#define MxFlag				M1Flag

//// Predefine : Control Gain
#define MxKs				M1Ks
#define MxKc				M1Kc

//// Predefine : Angle(Theta) Value
#define MxTheta_Cont		M1Theta_Sens

//// Predefine : Speed Value
#define MxSpeed_Cont		M1Speed_Sens
#define MxRPM_ref			M1RPM_ref
#define MxWm_ref			M1Wm_ref
#define MxWm_err			M1Wm_err

//// Predefine : Current Value
#define MxIe_ref_anti		M1Ie_ref_anti
#define MxIe_ref_integ		M1Ie_ref_integ
#define MxIe_ref_prop		M1Ie_ref_prop
#define MxIe_ref_ul			M1Ie_ref_ul
#define MxIe_ref			M1Ie_ref
#define MxIe_err			M1Ie_err

#define MxIp				M1Ip
#define MxIs				M1Is
#define MxIe				M1Ie

//// Predefine : Voltage Value
#define MxVe_ref_anti		M1Ve_ref_anti
#define MxVe_ref_integ		M1Ve_ref_integ
#define MxVe_ref_prop		M1Ve_ref_prop
#define MxVe_ref			M1Ve_ref
#define MxVs_ref			M1Vs_ref
#define MxVp_ref			M1Vp_ref

#define MxVs				M1Vs
#define MxVe				M1Ve

// External Value
//// External Value : Control Value
extern S_STV M1Samp;
extern S_PRM M1Para;
extern S_MTC M1Cont;
extern S_FLG M1Flag;

//// External Value : Control Gain.
extern S_PIC M1Ks;
extern S_DQPIC M1Kc;
extern float M1Koff;

//// External Value : Angle(Theta) Value.
extern S_THT M1Theta_Sens;

//// External Value : Speed Value.
extern S_SPD M1Speed_Sens;
extern float M1RPM_ref, M1Wm_ref, M1Wm_err;

//// External Value : Current Value.
extern float M1Ie_ref_anti, M1Ie_ref_integ, M1Ie_ref_prop, M1Ie_ref_ul;
extern S_FDQ M1Ie_ref, M1Ie_err;

extern S_FTP M1Ip;
extern S_FDQ M1Is, M1Ie;

//// External Value : Voltage Value.
extern S_FDQ M1Ve_ref_anti, M1Ve_ref_integ, M1Ve_ref_prop;
extern S_FDQ M1Ve_ref, M1Vs_ref;
extern S_FTP M1Vp_ref;
extern S_FDQ M1Vs, M1Ve;
#endif

#ifdef CPU2
// Predefine
//// Predefine : Control Value
#define MxSamp				M2Samp
#define MxPara				M2Para
#define MxCont				M2Cont
#define MxFlag				M2Flag

//// Predefine : Control Gain
#define MxKs				M2Ks
#define MxKc				M2Kc

//// Predefine : Angle(Theta) Value
#define MxTheta_Cont		M2Theta_Sens

//// Predefine : Speed Value
#define MxSpeed_Cont		M2Speed_Sens
#define MxRPM_ref			M2RPM_ref
#define MxWm_ref			M2Wm_ref
#define MxWm_err			M2Wm_err

//// Predefine : Current Value
#define MxIe_ref_anti		M2Ie_ref_anti
#define MxIe_ref_integ		M2Ie_ref_integ
#define MxIe_ref_prop		M2Ie_ref_prop
#define MxIe_ref_ul			M2Ie_ref_ul
#define MxIe_ref			M2Ie_ref
#define MxIe_err			M2Ie_err

#define MxIp				M2Ip
#define MxIs				M2Is
#define MxIe				M2Ie

//// Predefine : Voltage Value
#define MxVe_ref_anti		M2Ve_ref_anti
#define MxVe_ref_integ		M2Ve_ref_integ
#define MxVe_ref_prop		M2Ve_ref_prop
#define MxVe_ref			M2Ve_ref
#define MxVs_ref			M2Vs_ref
#define MxVp_ref			M2Vp_ref

#define MxVs				M2Vs
#define MxVe				M2Ve

// External Value
//// External Value : Control Value
extern S_STV M2Samp;
extern S_PRM M2Para;
extern S_MTC M2Cont;
extern S_FLG M2Flag;

//// External Value : Control Gain.
extern S_PDC M2Kpll;
extern S_PIC M2Ks;
extern S_DQPIC M2Kc;

//// External Value : Angle(Theta) Value.
extern S_THT M2Theta_Sens;

//// External Value : Speed Value.
extern S_SPD M2Speed_Sens;
extern float M2RPM_ref, M2Wm_ref, M2Wm_err;

//// External Value : Current Value.
extern float M2Ie_ref_anti, M2Ie_ref_integ, M2Ie_ref_prop, M2Ie_ref_ul;
extern S_FDQ M2Ie_ref, M2Ie_err;

extern S_FTP M2Ip;
extern S_FDQ M2Is, M2Ie;

//// External Value : Voltage Value.
extern S_FDQ M2Ve_ref_anti, M2Ve_ref_integ, M2Ve_ref_prop;
extern S_FDQ M2Ve_ref, M2Vs_ref;
extern S_FTP M2Vp_ref;
extern S_FDQ M2Vs, M2Ve;
#endif

void Motor_Cont(void)
{
	Uint16 ui_Mode = 0U;

	// ABC to DQS Conversion.
	MxIs.d = (2.0F * MxIp.a - MxIp.b - MxIp.c) * NUM_1_DEN_3;
	MxIs.q = (MxIp.b - MxIp.c) * NUM_1_DEN_SQRT3;

	// DQS to DQE Conversion.
	MxIe.d = MxTheta_Cont.e_cos * MxIs.d + MxTheta_Cont.e_sin * MxIs.q;
	MxIe.q = MxTheta_Cont.e_cos * MxIs.q - MxTheta_Cont.e_sin * MxIs.d;

	ui_Mode = (MxFlag.Inverter << 15) | MxCont.Flag.all;
	switch (ui_Mode) {
	case MODE_VF:
	case MODE_VF_INV:		// VF Control.
		// Reference Input.
		MxVe_ref.d = MxCont.VF_V.Vde_ref;
		MxVe_ref.q = MxCont.VF_V.Vqe_ref;

		// Controller.
		//// Controller : Imaginary Angle Generation.
		MxCont.VF_V.Theta += MPY2PIF32(MxCont.VF_V.Freq) * MxSamp.TIMEBASE.TIME;
		MxCont.VF_V.Theta = SEMI_MOD(MxCont.VF_V.Theta, PI2);

		//// Controller : Triangular Value Calculation.
		MxTheta_Cont.e_sin = SINF32(MxCont.VF_V.Theta);
		MxTheta_Cont.e_cos = COSF32(MxCont.VF_V.Theta);

		// DQE to ABC Conversion.
		Vdqe2dqs();
		Vdqs2abc();
		break;
	case MODE_ALIGN_INV:	// Align Control.
		// Reference Input.
		MxVs_ref.d = MxCont.Align.Vds_ref;
		MxVs_ref.q = 0.0F;

		// DQS to ABC Conversion.
		Vdqs2abc();

		// Offset Angle Compensation.
		MxTheta_Cont.e_offset += MxTheta_Cont.e_now;
		MxTheta_Cont.e_offset = SEMI_MOD(MxTheta_Cont.e_offset, PI2);
		break;
	case MODE_V:
	case MODE_V_INV:		// V Control.
		// Reference Input.
		MxVe_ref.d = MxCont.VF_V.Vde_ref;
		MxVe_ref.q = MxCont.VF_V.Vqe_ref;

		// DQE to ABC Conversion.
		Vdqe2dqs();
		Vdqs2abc();
		break;
	case MODE_CURRENT_INV:	// Current Control.
		// Reference Input.
		MxIe_ref.d = MxCont.Current.Ide_ref;
		MxIe_ref.q = MxCont.Current.Iqe_ref;

		// Controller.
		Current_Cont();

		// DQE to ABC Conversion.
		Vdqe2dqs();
		Vdqs2abc();
		break;
	case MODE_SPEED_INV:	// Speed Control.
		// Reference Input.
		MxRPM_ref = MxCont.Speed.rpm_ref;

		// Controller.
		Speed_Cont();
		Current_Cont();

		// DQE to ABC Conversion.
		Vdqe2dqs();
		Vdqs2abc();
		break;
	default:
		Reset_Cont();
		break;
	}

	return;
}

void Vdqe2dqs(void)
{
	MxVs_ref.d = MxTheta_Cont.e_cos * MxVe_ref.d - MxTheta_Cont.e_sin * MxVe_ref.q;
	MxVs_ref.q = MxTheta_Cont.e_cos * MxVe_ref.q + MxTheta_Cont.e_sin * MxVe_ref.d;

	return;
}

void Vdqs2abc(void)
{
	MxVp_ref.a = MxVs_ref.d;
	MxVp_ref.b = -0.5F * (MxVs_ref.d - SQRT3 * MxVs_ref.q);
	MxVp_ref.c = -0.5F * (MxVs_ref.d + SQRT3 * MxVs_ref.q);

	return;
}

void Vabc2dqe(void)
{
	// ABC to DQS Conversion.
	MxVs.d = (2.0F * MxVp_ref.a - MxVp_ref.b - MxVp_ref.c) * NUM_1_DEN_3;
	MxVs.q = (MxVp_ref.b - MxVp_ref.c) * NUM_1_DEN_SQRT3;

	// DQS to DQE Conversion.
	MxVe.d = MxTheta_Cont.e_cos * MxVs.d + MxTheta_Cont.e_sin * MxVs.q;
	MxVe.q = MxTheta_Cont.e_cos * MxVs.q - MxTheta_Cont.e_sin * MxVs.d;

	return;
}

void Current_Cont(void)
{
	// DQ-Axis Current Control.
	MxIe_err.d = MxIe_ref.d - MxIe.d;
	MxIe_err.q = MxIe_ref.q - MxIe.q;

	MxVe_ref_anti.d = MxKc.a.d * (MxVe_ref.d - MxVe.d);
	MxVe_ref_anti.q = MxKc.a.q * (MxVe_ref.q - MxVe.q);

	MxVe_ref_integ.d += MxKc.i.d * MxSamp.TIMEBASE.TIME * (MxIe_err.d - MxVe_ref_anti.d);
	MxVe_ref_integ.q += MxKc.i.q * MxSamp.TIMEBASE.TIME * (MxIe_err.q - MxVe_ref_anti.q);
	MxVe_ref_prop.d = MxKc.p.d * MxIe_err.d;
	MxVe_ref_prop.q = MxKc.p.q * MxIe_err.q;
	MxVe_ref.d = MxVe_ref_integ.d + MxVe_ref_prop.d;
	MxVe_ref.q = MxVe_ref_integ.q + MxVe_ref_prop.q;

//	MxVe_ref.d -= MxPara.Ls.d * MxSpeed_Cont.We.low * MxIe.q;
//	MxVe_ref.q += MxPara.Ls.q * MxSpeed_Cont.We.low * MxIe.d + MxPara.Ke * MxSpeed_Cont.Wm.low;
	MxVe_ref.q += MxPara.Ke * MxSpeed_Cont.Wm.low;

	return;
}

void Speed_Cont(void)
{
	if (MxFlag.OuterLoop == 1U) {
		MxWm_ref = MxRPM_ref * NUM_PI2_DEN_60;

		MxWm_err = MxWm_ref - MxSpeed_Cont.Wm.low;

		MxIe_ref_anti = MxKs.a * (MxIe_ref_ul - MxIe_ref.q);
		MxIe_ref_integ += MxKs.i * MxSamp.OUTERLOOP.TIME * (MxWm_err - MxIe_ref_anti);
		MxIe_ref_prop = MxKs.p * MxWm_err;
		MxIe_ref_ul = MxIe_ref_integ + MxIe_ref_prop;

		MxIe_ref.d = 0.0F;
		MxIe_ref.q = BOUND(MxIe_ref_ul, MxCont.Speed.Iqe_max, -MxCont.Speed.Iqe_max);
	}

	return;
}

void Reset_Cont(void)
{
	// PWM Off.
	MxFlag.Inverter = 0U;

	// Speed Value.
	//// Speed Value : Reference Value.
	MxRPM_ref = 0.0F;
	MxWm_ref = 0.0F;

	//// Speed Value : Controller Value.
	MxWm_err = 0.0F;
	MxIe_ref_anti = 0.0F;
	MxIe_ref_integ = 0.0F;
	MxIe_ref_prop = 0.0F;
	MxIe_ref_ul = 0.0F;

	// Current Value.
	//// Current Value : Reference Value.
	MxIe_ref.d = 0.0F;
	MxIe_ref.q = 0.0F;

	//// Current Value : Controller Value.
	MxIe_err.d = 0.0F;
	MxIe_err.q = 0.0F;
	MxVe_ref_anti.d = 0.0F;
	MxVe_ref_anti.q = 0.0F;
	MxVe_ref_integ.d = 0.0F;
	MxVe_ref_integ.q = 0.0F;
	MxVe_ref_prop.d = 0.0F;
	MxVe_ref_prop.q = 0.0F;

	// Voltage Value
	//// Voltage Value : Reference Value.
	MxVe_ref.d = 0.0F;
	MxVe_ref.q = 0.0F;
	MxVs_ref.d = 0.0F;
	MxVs_ref.q = 0.0F;

	//// Voltage Value : Three-Phase Value.
	MxVp_ref.a = 0.0F;
	MxVp_ref.b = 0.0F;
	MxVp_ref.c = 0.0F;

	return;
}
