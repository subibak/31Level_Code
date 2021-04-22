/*
 * CPU2_Interrupt.c
 *
 *  Created on: 2019. 6. 26.
 *      Author: HJHeo
 */

#include "Define_Header.h"
#include "Define_CPU2_Interrupt.h"
#include "Define_Sensor.h"
#include "Define_Fault.h"
#include "Define_Control.h"
#include "Define_NSFOPWM.h"
#include "Define_DAC.h"
#include "Define_LED.h"

// Variables
//// Variables : Sampling Time Value
#pragma DATA_SECTION(M2Samp,					"M2SampFile");
#ifdef CPU2
// 100[kHz]
S_STV M2Samp = {{500U, 10e-6F, 100e3F},											// MxSamp = {TIMEBASE.{PERIOD, TIME, FREQ},
				{500U, 250U, 10e-6F, 100e3F},									//			 PWM.{PERIOD, PERIOD_HALF, TIME, FREQ},
				{100U, 1e-3F, 1e3F},											//			 OUTERLLOP.{PERIOD, TIME, FREQ},
				{30U, 0.3e-6F},													//			 DEADTIME.{PERIOD, TIME}
				{10000UL, 0.0001F}};											//			 OFFSET.{COUNT_MAX, INV_COUNT_MAX}}
#else
S_STV M2Samp;
#endif

//// Variables : Motor Parameter
#pragma DATA_SECTION(M2Para,			"M2ParaFile");

#ifdef CPU2
S_PRM M2Para = {{436.7e-3F, 436.7e-3F}, {3.532e-3F, 3.532e-3F}, 0.0F, 4.0F};	// MxPara = {Rs.{d, q}, Ls.{d, q}, Ke, Pole_Pairs}
#else
S_PRM M2Para;
#endif

//// Variables : Control Value
#pragma DATA_SECTION(M2Cont,			"M2ContFile");

#ifdef CPU2
S_MTC M2Cont = {0U,																// MxCont = {Flag,
				{0.0F, 3.7F, 4.0F, 0.0F},										//			 VF_V.	{Vde_ref, Vqe_ref, Freq, Theta},
				{3.5F},															//			 Align.	{Vds_ref},
				{0.0F, 4.0F},													//			 Curr.	{Ide_ref, Iqe_ref},
				{500.0F, 20.0F}};												//			 Speed.	{rpm_ref, Iqe_max}}
#else
S_MTC M2Cont;
#endif

//// Variables : Control Gain
#pragma DATA_SECTION(M2Ks,				"M2KsFile");
#pragma DATA_SECTION(M2Kc,				"M2KcFile");
#pragma DATA_SECTION(M2Koff,			"M2KoffFile");

#ifdef CPU2
S_PIC M2Ks = {4.0F, 200.0F, 0.4F};												// MxKs = {p, i, a}
S_DQPIC M2Kc = {{15.0F, 15.0F}, {2000.0F, 2000.0F}, {0.06667F, 0.06667F}};		// MxKc = {p.{d, q}, i.{d, q}, a.{d, q}}
float M2Koff = 0.0F;															// MxKoff
#else
S_PIC M2Ks;
S_DQPIC M2Kc;
float M2Koff;
#endif

//// Variables : Angle Value
#pragma DATA_SECTION(M2Theta_Sens, 		"M2Theta_SensFile");

#ifdef CPU2
S_THT M2Theta_Sens = {0.0F, 0.0F, 0.0F, 0.0F, 0.0F,								// MxTheta_Sens = {m_now, e_now, e_offset, e_sin, e_cos,
					  {0.0F, 0.0F, 0U, 8000.0F, 0.000125F}};					//				   COUNT.{now, old, dir, PPR, INV_PPR}}
#else
S_THT M2Theta_Sens;
#endif

//// Variables : Speed Value
#pragma DATA_SECTION(M2RPM_ref, 		"M2RPM_refFile");
#pragma DATA_SECTION(M2Wm_ref, 			"M2Wm_refFile");
#pragma DATA_SECTION(M2Wm_err, 			"M2Wm_errFile");
#pragma DATA_SECTION(M2Speed_Sens, 		"M2Speed_SensFile");

#ifdef CPU2
float M2RPM_ref = 0.0F;															// MxRPM_ref
float M2Wm_ref = 0.0F;															// MxWm_ref
float M2Wm_err = 0.0F;															// MxWm_err
S_SPD M2Speed_Sens = {{0.0F, 0.0F, 0.0F, 0.0F, 0.0F},							// MxSpeed_Sens = {RPM.{now, old, low, La, Lb},
					  {0.0F},													//				   Wm.{low},
					  {0.0F}};													//				   We.{low}}
#else
float M2RPM_ref;
float M2Wm_ref;
float M2Wm_err;
S_SPD M2Speed_Sens;
#endif

//// Variables : Current Value
#pragma DATA_SECTION(M2Ie_ref_prop, 	"M2Ie_ref_propFile");
#pragma DATA_SECTION(M2Ie_ref_integ, 	"M2Ie_ref_integFile");
#pragma DATA_SECTION(M2Ie_ref_anti, 	"M2Ie_ref_antiFile");
#pragma DATA_SECTION(M2Ie_ref_ul, 		"M2Ie_ref_ulFile");
#pragma DATA_SECTION(M2Ie_ref, 			"M2Ie_refFile");
#pragma DATA_SECTION(M2Ie_err, 			"M2Ie_errFile");

#pragma DATA_SECTION(M2Ip,				"M2IpFile");
#pragma DATA_SECTION(M2Ip_sum,			"M2Ip_sumFile");
#pragma DATA_SECTION(M2Ip_offset,		"M2Ip_offsetFile");
#pragma DATA_SECTION(M2Is,				"M2IsFile");
#pragma DATA_SECTION(M2Ie,				"M2IeFile");

#ifdef CPU2
float M2Ie_ref_prop = 0.0F;														//
float M2Ie_ref_integ = 0.0F;													//
float M2Ie_ref_anti = 0.0F;														//
float M2Ie_ref_ul = 0.0F;														//
S_FDQ M2Ie_ref = {0.0F, 0.0F};													// MxIe_ref = {d, q}
S_FDQ M2Ie_err = {0.0F, 0.0F};													// MxIe_err = {d, q}

S_FTP M2Ip = {0.0F, 0.0F, 0.0F};												// MxIp = {a, b, c}
S_FTP M2Ip_sum = {0.0F, 0.0F, 0.0F};											// MxIp_sum = {a, b, c}
S_FTP M2Ip_offset = {0.0F, 0.0F, 0.0F};											// MxIp_offset = {a, b, c}
S_FDQ M2Is = {0.0F, 0.0F};														// MxIs = {d, q}
S_FDQ M2Ie = {0.0F, 0.0F};														// MxIe = {d, q}
#else
float M2Ie_ref_prop;
float M2Ie_ref_integ;
float M2Ie_ref_anti;
float M2Ie_ref_ul;
S_FDQ M2Ie_ref;
S_FDQ M2Ie_err;

S_FTP M2Ip;
S_FTP M2Ip_sum;
S_FTP M2Ip_offset;
S_FDQ M2Is;
S_FDQ M2Ie;
#endif

//// Variables : Voltage Value
#pragma DATA_SECTION(M2Ve_ref_prop, 	"M2Ve_ref_propFile");
#pragma DATA_SECTION(M2Ve_ref_integ, 	"M2Ve_ref_integFile");
#pragma DATA_SECTION(M2Ve_ref_anti, 	"M2Ve_ref_antiFile");
#pragma DATA_SECTION(M2Ve_ref, 			"M2Ve_refFile");
#pragma DATA_SECTION(M2Vs_ref, 			"M2Vs_refFile");
#pragma DATA_SECTION(M2Vp_ref, 			"M2Vp_refFile");
#pragma DATA_SECTION(M2Vn_ref,			"M2Vn_refFile");

#pragma DATA_SECTION(M2Vs, 				"M2VsFile");
#pragma DATA_SECTION(M2Ve,				"M2VeFile");

#ifdef CPU2
S_FDQ M2Ve_ref_prop = {0.0F, 0.0F};												// MxVe_ref_prop = {d, q}
S_FDQ M2Ve_ref_integ = {0.0F, 0.0F};											// MxVe_ref_integ = {d, q}
S_FDQ M2Ve_ref_anti = {0.0F, 0.0F};												// MxVe_ref_anti = {d, q}
S_FDQ M2Ve_ref = {0.0F, 0.0F};													// MxVe_ref = {d, q}
S_FDQ M2Vs_ref = {0.0F, 0.0F};													// MxVs_ref = {d, q}
S_FTP M2Vp_ref = {0.0F, 0.0F, 0.0F};											// MxVp_ref = {a, b, c}
S_FPL M2Vn_ref = {0.0F, 0.0F, 0.0F, 0.0F};										// MxVn_ref = {a, b, c, s}

S_FDQ M2Vs = {0.0F, 0.0F};														// MxVs = {d, q}
S_FDQ M2Ve = {0.0F, 0.0F};														// MxVe = {d, q}
#else
S_FDQ M2Ve_ref_prop;
S_FDQ M2Ve_ref_integ;
S_FDQ M2Ve_ref_anti;
S_FDQ M2Ve_ref;
S_FDQ M2Vs_ref;
S_FTP M2Vp_ref;
S_FPL M2Vn_ref;

S_FDQ M2Vs;
S_FDQ M2Ve;
#endif

//// Variables : Normalized Value
#pragma DATA_SECTION(M2Np_ref,			"M2Np_refFile");
#pragma DATA_SECTION(M2Nn_ref,			"M2Nn_refFile");
#pragma DATA_SECTION(M2CMPu,			"M2CMPuFile");
#pragma DATA_SECTION(M2CMPl,			"M2CMPlFile");

#ifdef CPU2
S_FTP M2Np_ref = {0.0F, 0.0F, 0.0F};											// MxNp_ref = {a, b, c}
S_FPL M2Nn_ref = {0.0F, 0.0F, 0.0F, 0.0F};										// MxNn_ref = {a, b, c, s}
S_UTP M2CMPu = {0.0F, 0.0F, 0.0F};												// MxCMPu = {a, b, c}
S_UTP M2CMPl = {0.0F, 0.0F, 0.0F};												// MxCMPl = {a, b, c}
#else
S_FTP M2Np_ref;
S_FPL M2Nn_ref;
S_UTP M2CMPu;
S_UTP M2CMPl;
#endif

//// Variables : Counters and Flags
#pragma DATA_SECTION(M2Count,			"M2CountFile");
#pragma DATA_SECTION(M2Flag,			"M2FlagFile");

#ifdef CPU2
S_CNT M2Count = {1UL, 1U};														// MxCount = {Offset, OuterLoop}
S_FLG M2Flag = {0U, 0U, 0U};													// MxFlag = {Inverter, OuterLoop, OM}
#else
S_CNT M2Count;
S_FLG M2Flag;
#endif

//// Variables : Fault
#pragma DATA_SECTION(M2Fault_Register,	"M2Fault_RegisterFile");
#pragma DATA_SECTION(M2Fault_Level,		"M2Fault_LevelFile");

#ifdef CPU2
U_FTR M2Fault_Register = {0U};													// MxFault_Register = {all}
S_FTL M2Fault_Level = {23.0F, 3000.0F, 0.0F, 200.0F};							// MxFault_Level = {Ioc, RPMos, VDCuv, VDCov}
#else
U_FTR M2Fault_Register;
S_FTL M2Fault_Level;
#endif

// External Value
//// External Value : M1 Value
extern S_THT M1Theta_Sens;
extern S_SPD M1Speed_Sens;
//// External Value : CPU1 to CPU2 Communication.
extern Uint16 M1toM2Vp_data, M1toM2Vn_data;
extern S_UTP M1toM2Ip_data;
extern S_ULL M1toM2El_data;
//// External Value : DAC
extern S_DAC da1, da2, da3, da4;
extern float da1_invrng, da2_invrng, da3_invrng, da4_invrng;

#ifdef CPU2
interrupt void ISR_CPU2_EPWM4_MAIN(void)
{
	float f_Temp;

	// OuterLoop Counter.
	if (M2Count.OuterLoop++ >= M2Samp.OUTERLOOP.PERIOD) {
		//// OuterLoop Counter : Counter Clear and Flag Set.
		M2Count.OuterLoop = 1U;
	} else {
		//// OuterLoop Counter : Slow Operation.
		switch (M2Count.OuterLoop) {
		case 2: M2Flag.OuterLoop = 1U;				break;
		case 3: M2Flag.OuterLoop = 0U;				break;
		case 4: da1_invrng = DIVF32(1.0F, da1.rng);	break;
		case 5: da2_invrng = DIVF32(1.0F, da2.rng);	break;
		case 6: da3_invrng = DIVF32(1.0F, da3.rng);	break;
		case 7: da4_invrng = DIVF32(1.0F, da4.rng);	break;
		}
	}
																										// 355[ns]

	// Current & Voltage Conversion.
	//// Current & Voltage Conversion : Wait ADC Result Data.
	while(IpcRegs.IPCSTS.bit.IPC29 == 0);
	IpcRegs.IPCACK.all = IPCxxx_IPC29;
																										// 1,000[ns]


	//// Current & Voltage Conversion : Data Conversion.
	Vdc_Sensor(M1toM2Vp_data, M1toM2Vn_data);															// 1,005[ns]
	Current_Sensor(M1toM2Ip_data.a, M1toM2Ip_data.b, M1toM2Ip_data.c);									// 350[ns]

	// Fault.
	Fault();																							// 600[ns]

	// Angle & Speed Read.
	//// Angle & Speed Read : Mechanical Angle Calculation.
	f_Temp = (M1Theta_Sens.COUNT.PPR - BOUND(M1Theta_Sens.COUNT.now, M1Theta_Sens.COUNT.PPR, 0.0F)) * M1Theta_Sens.COUNT.INV_PPR;
	M2Theta_Sens.m_now = MPY2PIF32(f_Temp);

	//// Angle & Speed Read : Electrical Angle Calculation.
	f_Temp *= M2Para.Pole_Pairs;
	M2Theta_Sens.e_now = MPY2PIF32(f_Temp - (float)((int)f_Temp)) - M2Theta_Sens.e_offset;
	M2Theta_Sens.e_now = SEMI_MOD(M2Theta_Sens.e_now, PI2);

	//// Angle & Speed Read : Trigonometric Calculation.
	M2Theta_Sens.e_sin = SINF32(M2Theta_Sens.e_now);
	M2Theta_Sens.e_cos = COSF32(M2Theta_Sens.e_now);

	//// Angle & Speed Read : Speed Read.
	M2Speed_Sens.RPM.low = -M1Speed_Sens.RPM.low;
	M2Speed_Sens.Wm.low = -M1Speed_Sens.Wm.low;
	M2Speed_Sens.We.low = -M1Speed_Sens.We.low;

	// Motor Control.
	Motor_Cont();
	NSFOPWM();																							// 2,255[ns]

	// Request PWM Output to CPU1.
	IpcRegs.IPCSET.bit.IPC30 = 1U;

	// DAC.
	DAC();																								// 975[ns]

	// Request DAC Output to CPU1.
	IpcRegs.IPCSET.bit.IPC28 = 1U;

	// ETC.
	XF2_ON;
	LED();																								// 120[ns]
	XF2_OFF;

	// Interrupt Clear.
	EPwm4Regs.ETCLR.all |= ETCLR_INT_INTFlagClear;				// ePWM4 Interrupt Clear.
	PieCtrlRegs.PIEACK.all |= PIEACK_GROUP3;					// ePWM4 PIE Interrupt Clear.
																										// 8,660[ns]
}

interrupt void ISR_CPU2_EPWM4_OFFSET(void)
{
	// Wait ADC Result Data.
	while(IpcRegs.IPCSTS.bit.IPC29 == 0);						// Wait Until CPU1 Read M2 Current Data.
	IpcRegs.IPCACK.all = IPCxxx_IPC29;							// Flag Clear.

	// Current Data Conversion.
	Current_Sensor(M1toM2Ip_data.a, M1toM2Ip_data.b, M1toM2Ip_data.c);

	// Current Sum.
	M2Ip_sum.a += M2Ip.a;
	M2Ip_sum.b += M2Ip.b;
	M2Ip_sum.c += M2Ip.c;

	// Offset Calculation.
	if (M2Count.Offset++ >= M2Samp.OFFSET.COUNT_MAX) {
		M2Ip_offset.a = M2Ip_sum.a * M2Samp.OFFSET.INV_COUNT_MAX;
		M2Ip_offset.b = M2Ip_sum.b * M2Samp.OFFSET.INV_COUNT_MAX;
		M2Ip_offset.c = M2Ip_sum.c * M2Samp.OFFSET.INV_COUNT_MAX;

		EALLOW;
		PieVectTable.EPWM4_INT = &ISR_CPU2_EPWM4_MAIN;
		EDIS;
	}

	// Interrupt Clear.
	EPwm4Regs.ETCLR.all |= ETCLR_INT_INTFlagClear;				// ePWM4 Interrupt Clear.
	PieCtrlRegs.PIEACK.all |= PIEACK_GROUP3;					// ePWM4 PIE Interrupt Clear.
}
#endif
