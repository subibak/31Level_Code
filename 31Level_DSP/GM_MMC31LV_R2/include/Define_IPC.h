/*
 * Define_IPC.h
 *
 *  Created on: 2019. 1. 14.
 *      Author: subi
 */

#ifndef INCLUDE_DEFINE_IPC_H_
#define INCLUDE_DEFINE_IPC_H_

extern void IPC_DSP1_Temp_TX(void);
extern void IPC_DSP1_Temp_RX(void);

extern void IPC_DSP1_EtherCAT_TX(void);
extern void IPC_DSP1_EtherCAT_RX(void);

extern void CPU_Msg_Read(Uint16 EtherCAT_Msg_RD[]);
extern void CPU_Msg_Write(Uint16 EtherCAT_Msg_WR[]);

#ifdef CPU1
// CPU1 Prototype Define
//// CPU1 Prototype Define : IPC
extern Uint16 IPCBootCPU2(Uint32);
extern void IPCWrite32bitProtect(Uint32, Uint32);

#endif

#endif /* INCLUDE_DEFINE_IPC_H_ */
