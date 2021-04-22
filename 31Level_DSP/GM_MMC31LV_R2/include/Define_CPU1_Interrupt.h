/*
 * Define_CPU1_Interrupt.h
 *
 *  Created on: 2020. 10. 10.
 *      Author: subi
 */

#ifndef INCLUDE_DEFINE_CPU1_INTERRUPT_H_
#define INCLUDE_DEFINE_CPU1_INTERRUPT_H_

#ifdef CPU1
// extern variable
extern int l, m, k, i, j, t;
extern int Number_SM;
extern int D_Number_SM;
extern int H_Number_SM;
extern Uint16 Group_number;

// extern function
interrupt void ISR_ePWM1_CPU1_MMC_OP(void);
#endif

#endif /* INCLUDE_DEFINE_CPU1_INTERRUPT_H_ */
