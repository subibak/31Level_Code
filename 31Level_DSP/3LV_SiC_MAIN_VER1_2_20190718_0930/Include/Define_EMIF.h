/*
 * Define_EMIF.h
 *
 *  Created on: 2019. 6. 24.
 *      Author: HJHeo
 */

#ifndef INCLUDE_DEFINE_EMIF_H_
#define INCLUDE_DEFINE_EMIF_H_

#ifdef __cplusplus
extern "C" {
#endif

// Prototype Define
//// Prototype Define : EMIF1
extern void Init_EMIF1(Uint16);

#ifdef CPU1
// CPU1 Prototype Define
//// CPU1 Prototype Define : EMIF2
extern void Init_EMIF2(void);
#endif

// Predefine
//// Predefine : Init_EMIF1 Input Value
#define EMIF1_CPU1HOSTLESS		0x0000
#define EMIF1_CPU1HOST			0x0001
#define EMIF1_CPU2HOST			0x0002

#ifdef __cplusplus
}
#endif

#endif /* INCLUDE_DEFINE_EMIF_H_ */
