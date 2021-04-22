/*
 * CPU1_Interrupt.c
 *
 *  Created on: 2019. 6. 26.
 *      Author: HJHeo
 */

#include "Define_Header.h"
#include "Define_CPU1_Interrupt.h"
#include "Define_FPGA.h"
#include "Define_Sensor.h"
#include "Define_Fault.h"
#include "Define_Control.h"
#include "Define_NSFOPWM.h"
#include "Define_LED.h"
#include "Define_DAC.h"

// Variables
//// Variables : Sampling Time Value
#pragma DATA_SECTION(M1Samp,			"M1SampFile");

#ifdef CPU1
// 100[kHz]
S_STV M1Samp = {{500U, 10e-6F, 100e3F},											// MxSamp = {TIMEBASE.{PERIOD, TIME, FREQ},
				{500U, 250U, 10e-6F, 100e3F},									//			 PWM.{PERIOD, PERIOD_HALF, TIME, FREQ},
				{100U, 1e-3F, 1e3F},											//			 OUTERLLOP.{PERIOD, TIME, FREQ},
				{30U, 0.3e-6F},													//			 DEADTIME.{PERIOD, TIME}
				{10000UL, 0.0001F}};											//			 OFFSET.{COUNT_MAX, INV_COUNT_MAX}}
#else
S_STV M1Samp;
#endif

//// Variables : Motor Parameter
#pragma DATA_SECTION(M1Para,			"M1ParaFile");

#ifdef CPU1
S_PRM M1Para = {{436.7e-3F, 436.7e-3F}, {3.532e-3F, 3.532e-3F}, 0.0F, 4.0F};	// MxPara = {Rs.{d, q}, Ls.{d, q}, Ke, Pole_Pairs}
#else
S_PRM M1Para;
#endif

//// Variables : Control Value
#pragma DATA_SECTION(M1Cont,			"M1ContFile");

#ifdef CPU1
S_MTC M1Cont = {0U,																// MxCont = {Flag,
				{0.0F, 3.7F, 4.0F, 0.0F},										//			 VF_V.	{Vde_ref, Vqe_ref, Freq, Theta},
				{3.5F},															//			 Align.	{Vds_ref},
				{0.0F, 4.0F},													//			 Curr.	{Ide_ref, Iqe_ref},
				{500.0F, 20.0F}};												//			 Speed.	{rpm_ref, Iqe_max}}
#else
S_MTC M1Cont;
#endif

//// Variables : Control Gain
#pragma DATA_SECTION(M1Ks,				"M1KsFile");
#pragma DATA_SECTION(M1Kc,				"M1KcFile");
#pragma DATA_SECTION(M1Koff,			"M1KoffFile");

#ifdef CPU1
S_PIC M1Ks = {4.0F, 200.0F, 0.4F};												// MxKs = {p, i, a}
S_DQPIC M1Kc = {{15.0F, 15.0F}, {2000.0F, 2000.0F}, {0.06667F, 0.06667F}};		// MxKc = {p.{d, q}, i.{d, q}, a.{d, q}}
float M1Koff = 0.0F;															// MxKoff
#else
S_PIC M1Ks;
S_DQPIC M1Kc;
float M1Koff;
#endif

//// Variables : Angle Value
#pragma DATA_SECTION(M1Theta_Sens, 		"M1Theta_SensFile");

#ifdef CPU1
S_THT M1Theta_Sens = {0.0F, 0.0F, 0.0F, 0.0F, 0.0F,								// MxTheta_Sens = {m_now, e_now, e_offset, e_sin, e_cos,
					  {0.0F, 0.0F, 0U, 8000.0F, 0.000125F}};					//				   COUNT.{now, old, dir, PPR, INV_PPR}}
#else
S_THT M1Theta_Sens;
#endif

//// Variables : Speed Value
#pragma DATA_SECTION(M1RPM_ref, 		"M1RPM_refFile");
#pragma DATA_SECTION(M1Wm_ref, 			"M1Wm_refFile");
#pragma DATA_SECTION(M1Wm_err, 			"M1Wm_errFile");
#pragma DATA_SECTION(M1Speed_Sens, 		"M1Speed_SensFile");

#ifdef CPU1
float M1RPM_ref = 0.0F;															// MxRPM_ref
float M1Wm_ref = 0.0F;															// MxWm_ref
float M1Wm_err = 0.0F;															// MxWm_err
S_SPD M1Speed_Sens = {{0.0F, 0.0F, 0.0F, 0.0F, 0.0F},							// MxSpeed_Sens = {RPM.{now, old, low, La, Lb},
					  {0.0F},													//				   Wm.{low},
					  {0.0F}};													//				   We.{low}}
#else
float M1RPM_ref;
float M1Wm_ref;
float M1Wm_err;
S_SPD M1Speed_Sens;
#endif

//// Variables : Current Value
#pragma DATA_SECTION(M1Ie_ref_prop, 	"M1Ie_ref_propFile");
#pragma DATA_SECTION(M1Ie_ref_integ, 	"M1Ie_ref_integFile");
#pragma DATA_SECTION(M1Ie_ref_anti, 	"M1Ie_ref_antiFile");
#pragma DATA_SECTION(M1Ie_ref_ul, 		"M1Ie_ref_ulFile");
#pragma DATA_SECTION(M1Ie_ref, 			"M1Ie_refFile");
#pragma DATA_SECTION(M1Ie_err, 			"M1Ie_errFile");

#pragma DATA_SECTION(M1Ip,				"M1IpFile");
#pragma DATA_SECTION(M1Ip_sum,			"M1Ip_sumFile");
#pragma DATA_SECTION(M1Ip_offset,		"M1Ip_offsetFile");
#pragma DATA_SECTION(M1Is,				"M1IsFile");
#pragma DATA_SECTION(M1Ie,				"M1IeFile");

#ifdef CPU1
float M1Ie_ref_prop = 0.0F;														//
float M1Ie_ref_integ = 0.0F;													//
float M1Ie_ref_anti = 0.0F;														//
float M1Ie_ref_ul = 0.0F;														//
S_FDQ M1Ie_ref = {0.0F, 0.0F};													// MxIe_ref = {d, q}
S_FDQ M1Ie_err = {0.0F, 0.0F};													// MxIe_err = {d, q}

S_FTP M1Ip = {0.0F, 0.0F, 0.0F};												// MxIp = {a, b, c}
S_FTP M1Ip_sum = {0.0F, 0.0F, 0.0F};											// MxIp_sum = {a, b, c}
S_FTP M1Ip_offset = {0.0F, 0.0F, 0.0F};											// MxIp_offset = {a, b, c}
S_FDQ M1Is = {0.0F, 0.0F};														// MxIs = {d, q}
S_FDQ M1Ie = {0.0F, 0.0F};														// MxIe = {d, q}
#else
float M1Ie_ref_prop;
float M1Ie_ref_integ;
float M1Ie_ref_anti;
float M1Ie_ref_ul;
S_FDQ M1Ie_ref;
S_FDQ M1Ie_err;

S_FTP M1Ip;
S_FTP M1Ip_sum;
S_FTP M1Ip_offset;
S_FDQ M1Is;
S_FDQ M1Ie;
#endif

//// Variables : Voltage Value
#pragma DATA_SECTION(M1Ve_ref_prop, 	"M1Ve_ref_propFile");
#pragma DATA_SECTION(M1Ve_ref_integ, 	"M1Ve_ref_integFile");
#pragma DATA_SECTION(M1Ve_ref_anti, 	"M1Ve_ref_antiFile");
#pragma DATA_SECTION(M1Ve_ref, 			"M1Ve_refFile");
#pragma DATA_SECTION(M1Vs_ref, 			"M1Vs_refFile");
#pragma DATA_SECTION(M1Vp_ref, 			"M1Vp_refFile");
#pragma DATA_SECTION(M1Vn_ref,			"M1Vn_refFile");

#pragma DATA_SECTION(M1Vs, 				"M1VsFile");
#pragma DATA_SECTION(M1Ve,				"M1VeFile");

#ifdef CPU1
S_FDQ M1Ve_ref_prop = {0.0F, 0.0F};												// MxVe_ref_prop = {d, q}
S_FDQ M1Ve_ref_integ = {0.0F, 0.0F};											// MxVe_ref_integ = {d, q}
S_FDQ M1Ve_ref_anti = {0.0F, 0.0F};												// MxVe_ref_anti = {d, q}
S_FDQ M1Ve_ref = {0.0F, 0.0F};													// MxVe_ref = {d, q}
S_FDQ M1Vs_ref = {0.0F, 0.0F};													// MxVs_ref = {d, q}
S_FTP M1Vp_ref = {0.0F, 0.0F, 0.0F};											// MxVp_ref = {a, b, c}
S_FPL M1Vn_ref = {0.0F, 0.0F, 0.0F, 0.0F};										// MxVn_ref = {a, b, c, s}

S_FDQ M1Vs = {0.0F, 0.0F};														// MxVs = {d, q}
S_FDQ M1Ve = {0.0F, 0.0F};														// MxVe = {d, q}
#else
S_FDQ M1Ve_ref_prop;
S_FDQ M1Ve_ref_integ;
S_FDQ M1Ve_ref_anti;
S_FDQ M1Ve_ref;
S_FDQ M1Vs_ref;
S_FTP M1Vp_ref;
S_FPL M1Vn_ref;

S_FDQ M1Vs;
S_FDQ M1Ve;
#endif

//// Variables : Normalized Value
#pragma DATA_SECTION(M1Np_ref,			"M1Np_refFile");
#pragma DATA_SECTION(M1Nn_ref,			"M1Nn_refFile");
#pragma DATA_SECTION(M1CMPu,			"M1CMPuFile");
#pragma DATA_SECTION(M1CMPl,			"M1CMPlFile");

#ifdef CPU1
S_FTP M1Np_ref = {0.0F, 0.0F, 0.0F};											// MxNp_ref = {a, b, c}
S_FPL M1Nn_ref = {0.0F, 0.0F, 0.0F, 0.0F};										// MxNn_ref = {a, b, c, s}
S_UTP M1CMPu = {0.0F, 0.0F, 0.0F};												// MxCMPu = {a, b, c}
S_UTP M1CMPl = {0.0F, 0.0F, 0.0F};												// MxCMPl = {a, b, c}
#else
S_FTP M1Np_ref;
S_FTP M1Nn_ref;
S_UTP M1CMPu;
S_UTP M1CMPl;
#endif

//// Variables : Counters and Flags
#pragma DATA_SECTION(M1Count,			"M1CountFile");
#pragma DATA_SECTION(M1Flag, 			"M1FlagFile");

#ifdef CPU1
S_CNT M1Count = {1UL, 1U};														// MxCount = {Offset, OuterLoop}
S_FLG M1Flag = {0U, 0U, 0U};													// MxFlag = {Inverter, OuterLoop, OM}
#else
S_CNT M1Count;
S_FLG M1Flag;
#endif

//// Variables : Fault
#pragma DATA_SECTION(M1Fault_Register,	"M1Fault_RegisterFile");
#pragma DATA_SECTION(M1Fault_Level,		"M1Fault_LevelFile");

#ifdef CPU1
U_FTR M1Fault_Register = {0U};													// MxFault_Register = {all}
S_FTL M1Fault_Level = {23.0F, 3000.0F, 0.0F, 200.0F};							// MxFault_Level = {Ioc, RPMos, VDCuv, VDCov}
#else
U_FTR M1Fault_Register;
S_FTL M1Fault_Level;
#endif

//// Variables : CPU1 to CPU2 Communication
#pragma DATA_SECTION(M1toM2Vp_data,		"M1toM2Vp_dataFile");
#pragma DATA_SECTION(M1toM2Vn_data,		"M1toM2Vn_dataFile");
#pragma DATA_SECTION(M1toM2Ip_data,		"M1toM2Ip_dataFile");
#pragma DATA_SECTION(M1toM2El_data,		"M1toM2El_dataFile");

#ifdef CPU1
Uint16 M1toM2Vp_data = 0.0F;													// M1toM2Vp_data
Uint16 M1toM2Vn_data = 0.0F;													// M1toM2Vn_data
S_UTP M1toM2Ip_data = {0U, 0U, 0U};												// M1toM2Ip_data = {a, b, c}
S_ULL M1toM2El_data = {0U, 0U, 0U};												// M1toM2El_data = {ab, bc, ca}
#else
Uint16 M1toM2Vp_data;
Uint16 M1toM2Vn_data;
S_UTP M1toM2Ip_data;
S_ULL M1toM2El_data;
#endif

// External Value
//// External Value : DAC
extern S_DAC da1, da2, da3, da4;
extern float da1_invrng, da2_invrng, da3_invrng, da4_invrng;

//// External Value : M2
extern S_FLG M2Flag;

#ifdef CPU1

interrupt void ISR_CPU1_EPWM1_MAIN(void)
{
	XF1_ON;

	// Current Sampling.																				// CPU1 Only			CPU1 & CPU2
	FpgaCs2Regs.ADC0.SWSOC.all = ADCSWSOC_SWSOC_CHAllSOC;												// [ns]				// [ns]
	FpgaCs2Regs.ADC1.SWSOC.all = ADCSWSOC_SWSOC_CHAllSOC;												// [ns]				// [ns]
																											// 190[ns]				// 275[ns]

#if (CPU2_BOOT_ENABLE)
	// Data Read for CPU2
	M1toM2Vp_data = FpgaCs2Regs.ADC0.CH1RESULT;															// -[ns]				// [ns]
	M1toM2Vn_data = FpgaCs2Regs.ADC0.CH4RESULT;															// -[ns]				// [ns]
																											// -[ns]				// [ns]

	M1toM2Ip_data.a = FpgaCs2Regs.ADC0.CH0RESULT;														// -[ns]				// [ns]
	M1toM2Ip_data.b = FpgaCs2Regs.ADC1.CH5RESULT;														// -[ns]				// [ns]
	M1toM2Ip_data.c = FpgaCs2Regs.ADC1.CH6RESULT;														// -[ns]				// [ns]
	IpcRegs.IPCSET.bit.IPC29 = 1U;																		// -[ns]				// [ns]
																											// -[ns]				// [ns]
																												// -[ns]				// 720[ns]
#endif

	// Position Read.
	M1Position_Read();																					// 835[ns]				// 820[ns]

	// OuterLoop Counter.
	if (M1Count.OuterLoop++ >= M1Samp.OUTERLOOP.PERIOD) {
		//// OuterLoop Counter : Counter Clear and Flag Set.
		M1Count.OuterLoop = 1U;

		//// OuterLoop Counter : Speed Calculation.
		M1Speed_Cal();																					// 420[ns]				// [ns]
	} else {
		//// OuterLoop Counter : Slow Operation.
		switch (M1Count.OuterLoop) {
		case 2: M1Flag.OuterLoop = 1U;				break;
		case 3: M1Flag.OuterLoop = 0U;				break;
#if (!CPU2_BOOT_ENABLE)
		case 4: da1_invrng = DIVF32(1.0F, da1.rng);	break;
		case 5: da2_invrng = DIVF32(1.0F, da2.rng);	break;
		case 6: da3_invrng = DIVF32(1.0F, da3.rng);	break;
		case 7: da4_invrng = DIVF32(1.0F, da4.rng);	break;
#endif
		}
	}
																											// 590[ns]				// 590[ns]
	// Current & Voltage Conversion.
#if (!CPU2_BOOT_ENABLE)
	Vdc_Sensor(FpgaCs2Regs.ADC0.CH1RESULT, FpgaCs2Regs.ADC0.CH4RESULT);									// 950[ns]				// -[ns]
#endif
	Current_Sensor(FpgaCs2Regs.ADC0.CH5RESULT, FpgaCs2Regs.ADC0.CH6RESULT, FpgaCs2Regs.ADC0.CH7RESULT);	// 515[ns]				// 520[ns]

	// Fault.
	Fault();																							// 560[ns]				// 560[ns]

	// Motor Control.
	Motor_Cont();																						// [ns] ~ [ns]
	NSFOPWM();																							// 2,340[ns]			// 2,340[ns]

	// ETC.
	LED();																								// 120[ns]				// 115[ns]
	FPGA_LED();																							// 120[ns]				// 115[ns]

	// PWM Output.
	LV3Out_FPGA_PWM();																					// 720[ns]				// 1,475[ns]

	// DAC.
#if (!CPU2_BOOT_ENABLE)
	DAC();																								// 880[ns]				// -[ns]
#endif
	FPGA_SPI_TX();																						// 490[ns]				// 715[ns]

	// Inverter Enable.
	//// Inverter Enable : M1
	if (M1Flag.Inverter == 1U) {
		PWM1_ON;
	} else {
		PWM1_OFF;
	}
																											// 170[ns]

#if (CPU2_BOOT_ENABLE)
	//// Inverter Enable : M2
	if (M2Flag.Inverter == 1U) {
		PWM2_ON;
	} else {
		PWM2_OFF;
	}
#endif

	// Interrupt Clear.
	EPwm1Regs.ETCLR.all |= ETCLR_INT_INTFlagClear;				// ePWM1 Interrupt Clear.
	PieCtrlRegs.PIEACK.all |= PIEACK_GROUP3;					// ePWM1 PIE Interrupt Clear.
																// with DAC								// 9,530[ns]			// 8,820[ns]

	XF1_OFF;
}

interrupt void ISR_CPU1_EPWM1_OFFSET(void)
{
	// Current Sampling.
	FpgaCs2Regs.ADC0.SWSOC.all = ADCSWSOC_SWSOC_CHAllSOC;
	FpgaCs2Regs.ADC1.SWSOC.all = ADCSWSOC_SWSOC_CHAllSOC;

#if (CPU2_BOOT_ENABLE)
	// Data Read for CPU2
	M1toM2Ip_data.a = FpgaCs2Regs.ADC1.CH5RESULT;
	M1toM2Ip_data.b = FpgaCs2Regs.ADC1.CH6RESULT;
	M1toM2Ip_data.c = FpgaCs2Regs.ADC1.CH7RESULT;
	IpcRegs.IPCSET.bit.IPC29 = 1U;								// Send Flag for Announcing CPU1 Read M2 Current Data.
#endif

	// Current Data Conversion.
	Current_Sensor(FpgaCs2Regs.ADC0.CH5RESULT, FpgaCs2Regs.ADC0.CH6RESULT, FpgaCs2Regs.ADC0.CH7RESULT);

	// Current Sum.
	M1Ip_sum.a += M1Ip.a;
	M1Ip_sum.b += M1Ip.b;
	M1Ip_sum.c += M1Ip.c;

	// Offset Calculation.
	if (M1Count.Offset++ >= M1Samp.OFFSET.COUNT_MAX) {
		M1Ip_offset.a = M1Ip_sum.a * M1Samp.OFFSET.INV_COUNT_MAX;
		M1Ip_offset.b = M1Ip_sum.b * M1Samp.OFFSET.INV_COUNT_MAX;
		M1Ip_offset.c = M1Ip_sum.c * M1Samp.OFFSET.INV_COUNT_MAX;

		EALLOW;
		PieVectTable.EPWM1_INT = &ISR_CPU1_EPWM1_MAIN;
		EDIS;
	}

	// Interrupt Clear.
	EPwm1Regs.ETCLR.all |= ETCLR_INT_INTFlagClear;				// ePWM1 Interrupt Clear.
	PieCtrlRegs.PIEACK.all |= PIEACK_GROUP3;					// ePWM1 PIE Interrupt Clear.
}

#endif
