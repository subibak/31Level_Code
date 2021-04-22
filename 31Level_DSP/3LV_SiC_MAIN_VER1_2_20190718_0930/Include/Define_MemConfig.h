/*
 * Define_MemConfig.h
 *
 *  Created on: 2019. 6. 22.
 *      Author: HJHeo
 */

#ifndef INCLUDE_DEFINE_MEMCONFIG_H_
#define INCLUDE_DEFINE_MEMCONFIG_H_

#ifdef __cplusplus
extern "C" {
#endif

// Prototype Define
//// Prototype Define : Local Memory Configure.
extern void Init_RAM(void);

#ifdef CPU1
//// Prototype Define : Global Share Memory Configure.
extern void Init_GSRAM(void);
#endif

#ifdef __cplusplus
}
#endif

#endif /* INCLUDE_DEFINE_MEMCONFIG_H_ */
