/*
 * Define_LED.h
 *
 *  Created on: 2015. 8. 18.
 *      Author: cjs9426
 */

#ifndef PMSM_CONTROL_CPU1_INCLUDE_DEFINE_LED_H_
#define PMSM_CONTROL_CPU1_INCLUDE_DEFINE_LED_H_

#define DSP_LED_TIME    500

#define LED0_OFF 		GpioDataRegs.GPESET.bit.GPIO141 = 1
#define LED1_OFF 		GpioDataRegs.GPESET.bit.GPIO140 = 1
#define LED2_OFF 		GpioDataRegs.GPESET.bit.GPIO139 = 1
#define LED3_OFF 		GpioDataRegs.GPESET.bit.GPIO138 = 1

#define LED0_ON 		GpioDataRegs.GPECLEAR.bit.GPIO141 = 1
#define LED1_ON 		GpioDataRegs.GPECLEAR.bit.GPIO140 = 1
#define LED2_ON 		GpioDataRegs.GPECLEAR.bit.GPIO139 = 1
#define LED3_ON 		GpioDataRegs.GPECLEAR.bit.GPIO138 = 1

//extern variable
extern Uint16 DSP_LED_case1;
extern Uint16 DSP_LED_cnt1;

//extern function
extern void LED_DSP(void);

#endif
