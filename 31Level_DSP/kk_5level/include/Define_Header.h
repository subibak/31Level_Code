/*
 * Define_Header.h
 *
 *  Created on: 2012. 8. 8.
 *      Author: HJHeo
 */

#ifndef DEFINE_HEADER_H_
#define DEFINE_HEADER_H_

#include "DSP2834x_Device.h"			// DSP2834x Register & Data Type Define.(Supported by TI)
#include "Define_SysCtrl.h"				// System Clock Define.
#include "Define_Prototypes.h"			// Define Extern Function(ProtoTypes).
#include "Define_Basetypes.h"			// Externed Variable.
#include "Define_Xintf_Addr.h"			// External Interface Address

#include <math.h>

#define ABS(x)							(x >= 0 ? x : -(x))
#define SGN(x)							(x >= 0 ? 1 : -1)
#define BOUND(val, max)					((val > max) ? max : ((val < -max) ? -max : val))
#define LPF1(val_low, val, val_old, TWc)((2 - TWc)*val_low + TWc*(val + val_old)) / (2 + TWc);\
                                        val_old = val
#define XF1_ON							GpioDataRegs.GPASET.bit.GPIO20 = 1
#define XF1_OFF							GpioDataRegs.GPACLEAR.bit.GPIO20 = 1

#define XF2_ON							GpioDataRegs.GPBSET.bit.GPIO53 = 1
#define XF2_OFF							GpioDataRegs.GPBCLEAR.bit.GPIO53 = 1

#define PI								3.141592654F
#define PI2								6.283185308F
#define PI2_1THIRD						2.094395102F
#define PI2_2THIRD						4.188790204F
#define SQRT2							1.414213562F
#define SQRT3							1.732050808F
#define INV_SQRT2						0.7071067812F
#define INV_SQRT3						0.5773502692F
#define INV_3							0.3333333333F
#define INV_60							0.01666666667F
#define INV_PI2							0.15915494309189533576888376337251

#define TIMER0_PERIOD					45000													// Watch Cat (SYSCLKOUT(300[MHz]) / 45000 = 6.667[kHz])

#define FREQ_GRID						60

#define TIMEBASE1_SAMPLING_TIME			100e-6F
#define INV_TIMEBASE1_SAMPLING_TIME		10e3F
#define TIMEBASE1_PERIOD				15000													// Switching & Current Control (SYSCLKOUT(300[MHz]) / 2 / 15000 = 10[kHZ])
#define TIMEBASE2_PERIOD				15000
#define TIMEBASE3_PERIOD				15000
#define TIMEBASE1_PERIOD_HALF			7500
#define TIMEBASE2_PERIOD_HALF			7500
#define TIMEBASE3_PERIOD_HALF			7500
#define PWM1_DB_TIME					3.333333333e-6F
#define PWM2_DB_TIME					3.333333333e-6F
#define PWM3_DB_TIME					3.333333333e-6F
#define PWM1_DB_PERIOD					1000													// 3.333[us] = 3.333[ns] x 1000
#define PWM2_DB_PERIOD					1000
#define PWM3_DB_PERIOD					1000

#define INT_LOOP_MAX					10
#define INT_CARRIER_LOOP_MAX			10
#define OUTERLOOP_SAMPLING_TIME			1e-3F													// Speed & Voltage Control
#define INV_OUTERLOOP_SAMPLING_TIME		1e3F

// pwm_test.c
#define MAX_CNT_CARRRIER1			3750

#define SM_cap                      2200e-6F


#define BRF(Val_low, Val_low_old,Val_low_old_old, Val, Val_old, Val_old_old, Tc,Q)	(1/(1 +Tc/Q + Tc*Tc))*((2 + Tc/Q)*Val_low_old -Val_low_old_old + (1 +Tc*Tc)*Val - 2*Val_old +Val_old_old);\
	        	Val_old_old =Val_old, Val_old = Val, Val_low_old_old = Val_low_old, Val_low_old = Val_low
//(1/(4 +(2*Tc + Tc*Tc)))*((8 - 2*Tc*Tc)*Val_low_old +(2*Tc/Q -Tc*Tc -4)*Val_low_old_old + (4 +Tc*Tc)*Val + (2*Tc*Tc-8)*Val_old + (4+Tc*Tc)*Val_old_old)
//
#define LPF(Val_low, Val, Tcl)  (1/(1 +Tcl))*(Val_low + Tcl*Val);

//
#define NUM_SM						4
#define NEXT_SAMPLING_GATING_ON			GpioDataRegs.GPBSET.bit.GPIO56     = 1
#define NEXT_SAMPLING_GATING_OFF		GpioDataRegs.GPBCLEAR.bit.GPIO56   = 0

#define PWM_ON							GpioDataRegs.GPBCLEAR.bit.GPIO58   = 1
#define PWM_OFF							GpioDataRegs.GPBSET.bit.GPIO58     = 1
#endif /* DEFINE_HEADER_H_ */

