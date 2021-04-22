/*
 * Define_Header.h
 *
 *  Created on: 2015. 08. 18.
 *      Author: cjs9426
 *  Revised on: 2018. 06. 19
 *      Author: Subi
 */


// The ¡°f¡± stands for float (to distinguish from the double alternatives). Note that this fits quite nicely
// with suffixing floating point literals with an f as in 1.5f.

#ifndef DEFINE_HEADER_H_
#define DEFINE_HEADER_H_

#include "Define_SysCtrl.h"
#include "Define_Struct.h"
#include "Define_Prototypes.h"
#include "Define_Basetypes.h"
#include "Define_LED.h"
#include "Define_Address.h"

#include <math.h>
#include "F2837xD/F2837xD_device.h"

#include "FPGA/FPGA_GPIO.h"

#define SIGN(x)							(x >= 0 ? 1 : -1)
#define ABS(x)							(x >= 0 ? x : -(x))
#define BOUND(val, max)					((val > max) ? max : ((val < -max) ? -max : val))
#define SEMI_BOUND(val, max, min)		((val > max) ? max : ((val < min) ? min : val))

#define XF1_ON                          GpioDataRegs.GPESET.bit.GPIO144 = 1
#define XF1_OFF                         GpioDataRegs.GPECLEAR.bit.GPIO144 = 1
#define XF2_ON							GpioDataRegs.GPESET.bit.GPIO134 = 1
#define XF2_OFF							GpioDataRegs.GPECLEAR.bit.GPIO134 = 1

#define PI								3.1415926535897932F
#define PI4_INV_3						4.1887902047863910F
#define PI2								6.2831853071795865F
#define SQRT2							1.4142135623730950F
#define SQRT3							1.7320508075688773F
#define INV_SQRT2						0.7071067811865475F
#define INV_SQRT3						0.5773502691896258F
#define INV_3							0.3333333333333333F
#define INV_PI2							0.1591549430918953F
#define INV_60							0.0166666666666667F
#define INV_360							0.0027777777777778F

#define ADC_OFFSET_COUNT            10000
#define ADC_INV_OFFSET_COUNT        1.e-4F
#define ADC_RESOLUTION              4.8828125e-4F   // 12bit

#define TIMEBASE1_SAMPLING_TIME			100e-6F		// 10e-6F / 12.5e-6F / 20e-6F / 50e-6F / 100e-6F
#define INV_TIMEBASE1_SAMPLING_TIME		10e3F		// 100e3F / 80e3F / 50e3F  / 20e3F  / 10e3F
#define TIMEBASE1_PERIOD				10000		//  1000  / 1250   /  2000  /  5000  /  10000		// Switching & Current Control (SYSCLKOUT(200[MHz]) / 2 / 10000 = 10[kHZ])
#define TIMEBASE1_PERIOD_HALF			5000		//   500  /  625	/  1000  /  2500  /  5000
#define TIMEBASE2_PERIOD_HALF			5000
#define PWM1_DB_TIME					3.3e-6F
#define PWM2_DB_TIME					3.3e-6F
#define PWM3_DB_TIME					3.3e-6F
#define PWM1_DB_PERIOD					660													// 3.3[us] = 5[ns] x 660
#define PWM2_DB_PERIOD					660
#define PWM3_DB_PERIOD					660

#define INT_LOOP_MAX					10
#define TX_LOOP_MAX                     10          // 10 = 1ms / 100 = 10ms / 1000 = 100ms
#define OUTERLOOP_SAMPLING_TIME			1e-3F		//  0.1e-3F  / 0.125e-3F / 0.2e-3F / 0.5e-3F / 1e-3F
#define INV_OUTERLOOP_SAMPLING_TIME		1e3F 		//    10e3F  / 8e3F    /   5e3F  /   2e3F  / 1e3F

#define TEMP_SLOPE                      -304.9545524F    // TEMP_MAX * slope = 10 * -30.49545524F
#define TEMP_INTERCEPT                   157.9743688F

#define TEMP_K_0C                       273.15F
#define INV_TEMP_K_25C                  3.354016435e-3F  // 1/298.15
#define INV_B_CONST                     2.702702703e-4F  // 1/3700    NTCS0805E3153JMT model
#define Inv_R25                         6.666666667e-5F  // 1/15kohm  NTCS0805E3153JMT model

#define MAX_NUM_SM                      6
#define MAX_CNT_CARRIER               5000
#define DAQ_RS422_MAX                 1250

#define EtherCAT1                         GpioDataRegs.GPESET.bit.GPIO154 = 1
#define EtherCAT2                         GpioDataRegs.GPECLEAR.bit.GPIO154 = 1
#define EtherCAT3                         GpioDataRegs.GPESET.bit.GPIO153 = 1
#define EtherCAT4                         GpioDataRegs.GPECLEAR.bit.GPIO153 = 1

#endif /* DEFINE_HEADER_H_ */
