/*
 * Define_IntCtrl.h
 *
 *  Created on: 2018. 11. 6.
 *      Author: HJHeo
 */

#ifndef DEFINE_INTCTRL_H_
#define DEFINE_INTCTRL_H_

#ifdef __cplusplus
extern "C" {
#endif

// Prototype Define
extern void Init_Interrupt(void);
extern void USERISR_RSTSET(Uint32*, void*);
extern void USERISR_SET(Uint32*, void*);
extern interrupt void ISR_Reset(void);
extern interrupt void ISR_DefaultNMI(void);
extern interrupt void ISR_Default5(void);
extern interrupt void ISR_Default6(void);
extern interrupt void ISR_Default7(void);
extern interrupt void ISR_Default8(void);
extern interrupt void ISR_Default9(void);
extern interrupt void ISR_Default10(void);
extern interrupt void ISR_Default11(void);
extern interrupt void ISR_Default12(void);
extern interrupt void ISR_Default13(void);
extern interrupt void ISR_Default14(void);
extern interrupt void ISR_Default15(void);

#ifdef __cplusplus
}
#endif

#endif /* DEFINE_INTCTRL_H_ */
