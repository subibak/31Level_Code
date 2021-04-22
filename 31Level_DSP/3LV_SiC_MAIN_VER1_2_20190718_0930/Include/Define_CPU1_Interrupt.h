/*
 * Define_CPU1_Interrupt.h
 *
 *  Created on: 2019. 6. 24.
 *      Author: HJHeo
 */

#ifndef INCLUDE_DEFINE_CPU1_INTERRUPT_H_
#define INCLUDE_DEFINE_CPU1_INTERRUPT_H_

#ifdef __cplusplus
extern "C" {
#endif

#ifdef CPU1
// CPU1 Prototype Define
//// CPU1 Prototype Define : Interrupt
extern interrupt void ISR_CPU1_EPWM1_MAIN(void);
extern interrupt void ISR_CPU1_EPWM1_OFFSET(void);
#endif

#ifdef __cplusplus
}
#endif

#endif /* INCLUDE_DEFINE_CPU1_INTERRUPT_H_ */
