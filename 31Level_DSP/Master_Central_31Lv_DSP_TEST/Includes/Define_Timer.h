/*
 * Define_Timer.h
 *
 *  Created on: 2018. 11. 6.
 *      Author: HJHeo
 */

#ifndef DEFINE_TIMER_H_
#define DEFINE_TIMER_H_

#ifdef __cplusplus
extern "C" {
#endif

#define TIMER_NS_CLK           50   //50 ns * 1e9

// Prototype Define
extern void Init_Timer(void);
extern void Start_Timer(void);

extern void Ecat_Time_Compen(void);

#ifdef __cplusplus
}
#endif

#endif /* DEFINE_TIMER_H_ */
