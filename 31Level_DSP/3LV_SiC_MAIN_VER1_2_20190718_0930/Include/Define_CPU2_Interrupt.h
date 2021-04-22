/*
 * Define_CPU2_Interrupt.h
 *
 *  Created on: 2019. 6. 24.
 *      Author: HJHeo
 */

#ifndef INCLUDE_DEFINE_CPU2_INTERRUPT_H_
#define INCLUDE_DEFINE_CPU2_INTERRUPT_H_

#ifdef __cplusplus
extern "C" {
#endif

#ifdef CPU2
// CPU2 Prototype Define
//// CPU2 Prototype Define : Interrupt
extern interrupt void ISR_CPU2_EPWM4_MAIN(void);
extern interrupt void ISR_CPU2_EPWM4_OFFSET(void);
#endif

#ifdef __cplusplus
}
#endif

#endif /* INCLUDE_DEFINE_CPU2_INTERRUPT_H_ */
