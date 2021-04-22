/*
 * Define_Header.h
 *
 *  Created on: 2018. 11. 6.
 *      Author: HJHeo
 */

#ifndef DEFINE_HEADER_H_
#define DEFINE_HEADER_H_

#ifdef __cplusplus
extern "C" {
#endif

// Include Files
#include "math.h"
#include "AM572x_C66\AM572x_C66_device.h"
#include "Define_CtrlModule.h"
#include "Define_GPIO.h"
#include "Define_GPMC.h"
#include "Define_IntCtrl.h"
#include "Define_Interrupt.h"
#include "Define_LED.h"
#include "Define_PRCM.h"
#include "Define_Timer.h"
#include "Define_Struct.h"
#include "Define_device.h"
#include "Define_ADC.h"
#include "Define_DAC.h"
#include "Define_McSPI.h"
#include "Define_Sensor.h"
#include "Define_IPC.h"
#include "Define_Mailbox.h"
#include "Define_MMC_Control.h"
#include "Define_D_IO.h"
#include "Define_Fault.h"
#include "Define_Filter.h"

//Parameter Define
#define ABS(x)                          (x >= 0 ? x : -(x))
#define SGN(x)                          (x >= 0 ? 1 : -1)
#define BOUND(val, max)                 ((val > max) ? max : ((val < -max) ? -max : val))
#define BOUND1(val, max)                ((val > max) ? max : ((val < 0) ? 0 : val))
#define LPF1(val_low, val, val_old, TWc)((2 - TWc)*val_low + TWc*(val + val_old)) / (2 + TWc);\
                                        val_old = val

#define BRF(Val_low, Val_low_old,Val_low_old_old, Val, Val_old, Val_old_old, Tc,Q)  (1/(1 +Tc/Q + Tc*Tc))*((2 + Tc/Q)*Val_low_old -Val_low_old_old + (1 +Tc*Tc)*Val - 2*Val_old +Val_old_old);\
                Val_old_old =Val_old, Val_old = Val, Val_low_old_old = Val_low_old, Val_low_old = Val_low

#define PI                              3.1415926535897932384626433832795F
#define PI2                             6.283185307179586476925286766559F
#define PI2_1THIRD                      2.094395102F
#define PI2_2THIRD                      4.188790204F
#define SQRT2                           1.4142135623730950488016887242097F
#define SQRT3                           1.7320508075688772935274463415059F
#define INV_SQRT2                       0.7071067812F
#define INV_SQRT3                       0.57735026918962576450914878050196F
#define INV_3                           0.33333333333333333333333333333333F
#define INV_60                          0.01666666666666666666666666666667F
#define INV_PI2                         0.15915494309189533576888376337251F

#define OUTERLOOP_SAMPLING_TIME         1e-3
#define TIMEBASE1_SAMPLING_TIME         200e-6F     // 10e-6F / 12.5e-6F / 20e-6F / 50e-6F / 100e-6F
#define INV_TIMEBASE1_SAMPLING_TIME     5e3F  // 100e3F / 80e3F / 50e3F  / 20e3F  / 10e3F
#define FREQ_GRID                       60
#define PRE_MC_TIMER_TIME               25000       // 25000 : 5s
#define MAIN_MC_TIMER_TIME              50000       // 50000 : 10s
#define ECAT_DAQ_EN_MAX                 50000       // 15000000 : 30s
#define GPMC_START_TIMER                5

#ifdef __cplusplus
}
#endif

#endif /* DEFINE_HEADER_H_ */
