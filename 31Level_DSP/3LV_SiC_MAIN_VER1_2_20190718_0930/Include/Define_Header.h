/*
 * Define_Header.h
 *
 *  Created on: 2019. 6. 21.
 *      Author: HJHeo
 */

#ifndef INCLUDE_DEFINE_HEADER_H_
#define INCLUDE_DEFINE_HEADER_H_

#ifdef __cplusplus
extern "C" {
#endif

// Include Files
#include <math.h>
#include "F2837xD\F2837xD_device.h"
#include "Define_Struct.h"
#include "Define_TMU.h"

// Predefine Value
//// Predefine Value : CPU2
#define CPU2_BOOT_ENABLE		1
#define CPU2_FLASH_BOOT			0
#if (!CPU2_BOOT_ENABLE && CPU2_FLASH_BOOT)
	#error "You must set the CPU2_BOOT_ENABLE to 1 for CPU2 FLASH Boot"
#endif

#ifdef CPU1
// GPIO Output Define
//// GPIO Output Define : LED
#define LED0_ON					GpioDataRegs.GPECLEAR.all |= GPExxx_GPIO141
#define LED1_ON					GpioDataRegs.GPECLEAR.all |= GPExxx_GPIO140
#define LED0_OFF				GpioDataRegs.GPESET.all |= GPExxx_GPIO141
#define LED1_OFF				GpioDataRegs.GPESET.all |= GPExxx_GPIO140

//// GPIO Output Define : XF
#define XF1_ON					GpioDataRegs.GPESET.all |= GPExxx_GPIO144
#define XF1_OFF					GpioDataRegs.GPECLEAR.all |= GPExxx_GPIO144

//// FPGA GPIO Output Define : PWM
#define PWM1_ON					FpgaCs2Regs.GP1.CLEAR.all = GPxxx_GPIO0 | GPxxx_GPIO1
#define PWM1_OFF				FpgaCs2Regs.GP1.SET.all = GPxxx_GPIO0 | GPxxx_GPIO1
#define PWM2_ON					FpgaCs2Regs.GP1.CLEAR.all = GPxxx_GPIO2 | GPxxx_GPIO3
#define PWM2_OFF				FpgaCs2Regs.GP1.SET.all = GPxxx_GPIO2 | GPxxx_GPIO3
#endif

#ifdef CPU2
// GPIO Output Define
//// GPIO Output Define : LED
#define LED2_ON					GpioDataRegs.GPECLEAR.all |= GPExxx_GPIO139
#define LED3_ON					GpioDataRegs.GPECLEAR.all |= GPExxx_GPIO138
#define LED2_OFF				GpioDataRegs.GPESET.all |= GPExxx_GPIO139
#define LED3_OFF				GpioDataRegs.GPESET.all |= GPExxx_GPIO138

//// GPIO Output Define : XF
#define XF2_ON					GpioDataRegs.GPESET.all |= GPExxx_GPIO134
#define XF2_OFF					GpioDataRegs.GPECLEAR.all |= GPExxx_GPIO134
#endif

// Math
//// Math : Define Value.
#define NUM_PI2_DEN_60			0.10471975511965977461542144610932F
#define NUM_1_DEN_3				0.33333333333333333333333333333333F
#define NUM_1_DEN_SQRT3			0.57735026918962576450914878050196F
#define SQRT3					1.7320508075688772935274463415059F
#define PI2						6.283185307179586476925286766559F

//// Math : In-line Function.
#define LO_BOUND(val, min)		((val) < (min) ? (min) : (val))
#define BOUND(val, max, min)	((val) > (max) ? (max) : ((val) < (min) ? (min) : (val)))
#define FABS(val)				((val) >= 0.0F ? (val) : -(val))
#define FSIGN(val)				((val) >= 0.0F ? 1.0F : -1.0F)
#define LPF(val)				val.low = val.La * val.low + val.Lb * (val.now + val.old);	\
								val.old = val.now
#define SEMI_MOD(val, max)		((val) >= (max) ? ((val) - (max)) : ((val) < 0 ? ((val) + (max)) : (val)))


#ifdef __cplusplus
}
#endif

#endif /* INCLUDE_DEFINE_HEADER_H_ */
