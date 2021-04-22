/*
 * Define_IPC.h
 *
 *  Created on: 2019. 6. 24.
 *      Author: HJHeo
 */

#ifndef INCLUDE_DEFINE_IPC_H_
#define INCLUDE_DEFINE_IPC_H_

#ifdef __cplusplus
extern "C" {
#endif

#ifdef CPU1
// CPU1 Prototype Define
//// CPU1 Prototype Define : IPC
extern Uint16 IPCBootCPU2(Uint32);
#endif

// Prototype Define
//// Prototype Define : IPC Command
extern void IPCWrite32bitProtect(Uint32, Uint32);

// Predefine
//// Predefine : Function Return Value.
#ifndef STATUS_PASS
#define STATUS_PASS				0x0000
#endif

#ifndef STATUS_FAIL
#define STATUS_FAIL				0x0001
#endif

#ifdef __cplusplus
}
#endif

#endif /* INCLUDE_DEFINE_IPC_H_ */
