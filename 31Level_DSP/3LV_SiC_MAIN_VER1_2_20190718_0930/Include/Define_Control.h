/*
 * Define_Control.h
 *
 *  Created on: 2019. 6. 27.
 *      Author: HJHeo
 */

#ifndef INCLUDE_DEFINE_CONTROL_H_
#define INCLUDE_DEFINE_CONTROL_H_

#ifdef __cplusplus
extern "C" {
#endif

// Prototype Define.

//// Prototype Define : Individual Function.
extern void Vdqe2dqs(void);
extern void Vdqs2abc(void);
extern void Vabc2dqe(void);
extern void Current_Cont(void);
extern void Reset_Cont(void);

//// Prototype Define : Control Function.
extern void Speed_Cont(void);
extern void Motor_Cont(void);

#ifdef __cplusplus
}
#endif

#endif /* INCLUDE_DEFINE_CONTROL_H_ */
