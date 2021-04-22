/*
 * Define_Interrupt.h
 *
 *  Created on: 2018. 11. 6.
 *      Author: HJHeo
 */

#ifndef DEFINE_INTERRUPT_H_
#define DEFINE_INTERRUPT_H_

#ifdef __cplusplus
extern "C" {
#endif

//Variable Define
extern Uint32 ISR_TABLE[16][8];
extern Uint16 Flag_Out_Loop;
extern Uint32 Measure_case;
// Prototype Define
extern interrupt void ISR_DSPTimer(void);
extern void USERISR_SET(Uint32 *, void *);

#ifdef __cplusplus
}
#endif

#endif /* DEFINE_INTERRUPT_H_ */
