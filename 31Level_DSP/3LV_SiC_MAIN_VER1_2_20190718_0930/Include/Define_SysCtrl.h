/*
 * Define_SysCtrl.h
 *
 *  Created on: 2019. 6. 21.
 *      Author: HJHeo
 */

#ifndef INCLUDE_DEFINE_SYSCTRL_H_
#define INCLUDE_DEFINE_SYSCTRL_H_

#ifdef __cplusplus
extern "C" {
#endif

// Prototype Define
//// Prototype Define : WatchDog
extern void DisableDog(void);
extern void InitStartDog(void);
extern void ResetDog(void);

#ifdef CPU1
//// CPU1 Prototype Define : PLL
extern void Init_PLL(Uint16);
extern void Init_CPUHost(void);
#endif

//// Prototype Define : Peripheral Clock
extern void Init_PeripheralClocks(void);

#ifdef CPU1
// Predefine Value
//// CPU1 Predefine Value : Init_PLL Input Value
#define PLL_CPU1HOSTLESS			0x0000
//#define PLL_CPU2HOST				0x0001
#define PLL_CPU1HOST				0x0002
#endif

#ifdef __cplusplus
}
#endif

#endif /* INCLUDE_DEFINE_SYSCTRL_H_ */
