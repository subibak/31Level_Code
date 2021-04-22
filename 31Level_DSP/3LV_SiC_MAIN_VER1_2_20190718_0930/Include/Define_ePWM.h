/*
 * Define_ePWM.h
 *
 *  Created on: 2019. 6. 24.
 *      Author: HJHeo
 */

#ifndef INCLUDE_DEFINE_EPWM_H_
#define INCLUDE_DEFINE_EPWM_H_

#ifdef __cplusplus
extern "C" {
#endif

// Prototype Define
//// Prototype Define : ePWM Module
extern void Init_ePWM(void);

#ifdef CPU1
// CPU1 Prototype Define
//// CPU1 Prototype Define : ePWM Module
extern void Start_ePWM(void);
#endif

#ifdef __cplusplus
}
#endif

#endif /* INCLUDE_DEFINE_EPWM_H_ */
