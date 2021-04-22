/*
 * Define_LED1.h
 *
 *  Created on: 2016. 7. 25.
 *      Author: Kwanghae
 */

#ifndef DEFINE_LED1_H_
#define DEFINE_LED1_H_


#ifdef __cplusplus
extern "C" {
#endif
#define LED0_OFF                   GpioDataRegs.GPASET.bit.GPIO8=1
#define LED1_OFF                   GpioDataRegs.GPASET.bit.GPIO9=1
#define LED2_OFF                   GpioDataRegs.GPASET.bit.GPIO10=1
#define LED3_OFF                    GpioDataRegs.GPASET.bit.GPIO11=1

#define LED0_ON                    GpioDataRegs.GPACLEAR.bit.GPIO8=1
#define LED1_ON                    GpioDataRegs.GPACLEAR.bit.GPIO9=1
#define LED2_ON                     GpioDataRegs.GPACLEAR.bit.GPIO10=1
#define LED3_ON                    GpioDataRegs.GPACLEAR.bit.GPIO11=1



#endif /* INCLUDE_DEFINE_LED1_H_ */
