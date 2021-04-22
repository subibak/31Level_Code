/*
 * Define_LED.h
 *
 *  Created on: 2015. 8. 18.
 *      Author: cjs9426
 */

#ifndef PMSM_CONTROL_CPU1_INCLUDE_DEFINE_LED_H_
#define PMSM_CONTROL_CPU1_INCLUDE_DEFINE_LED_H_

#ifdef __cplusplus
extern "C" {
#endif

#define LED0_OFF 		GpioDataRegs.GPESET.bit.GPIO141 = 1
#define LED1_OFF 		GpioDataRegs.GPESET.bit.GPIO140 = 1
#define LED2_OFF 		GpioDataRegs.GPESET.bit.GPIO139 = 1
#define LED3_OFF 		GpioDataRegs.GPESET.bit.GPIO138 = 1

#define LED0_ON 		GpioDataRegs.GPECLEAR.bit.GPIO141 = 1
#define LED1_ON 		GpioDataRegs.GPECLEAR.bit.GPIO140 = 1
#define LED2_ON 		GpioDataRegs.GPECLEAR.bit.GPIO139 = 1
#define LED3_ON 		GpioDataRegs.GPECLEAR.bit.GPIO138 = 1


#ifdef __cplusplus
}
#endif

#endif
