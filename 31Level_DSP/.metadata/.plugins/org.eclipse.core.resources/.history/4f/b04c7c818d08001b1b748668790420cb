/*
 * Define_SysCtrl.h
 *
 *  Created on: 2015. 8. 13.
 *      Author: cjs9426
 */

#ifndef DEFINE_SYSCTRL_H_
#define DEFINE_SYSCTRL_H_

#ifdef __cplusplus
extern "C" {
#endif

#define CPU_RATE 5.000000L

extern void F28x_usDelay(long LoopCount);
// DO NOT MODIFY THIS LINE.
#define DELAY_US(A)  F28x_usDelay(((((long double) A * 1000.0L) / (long double)CPU_RATE) - 9.0L) / 5.0L)

#ifdef __cplusplus
}
#endif /* extern "C" */

#endif /* DEFINE_SYSCTRL_H_ */
