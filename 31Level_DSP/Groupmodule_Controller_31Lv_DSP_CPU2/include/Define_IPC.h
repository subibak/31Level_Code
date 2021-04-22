/*
 * Define_IPC.h
 *
 *  Created on: 2019. 1. 14.
 *      Author: subi
 */

#ifndef INCLUDE_DEFINE_IPC_H_
#define INCLUDE_DEFINE_IPC_H_

#ifdef __cplusplus
extern "C" {
#endif

extern void IPC_DSP2_Temp_TX(void);
extern void IPC_DSP2_Temp_RX(void);

extern void IPC_DSP2_EtherCAT_TX(void);
extern void IPC_DSP2_EtherCAT_RX(void);

#ifdef __cplusplus
}
#endif

#endif /* INCLUDE_DEFINE_IPC_H_ */
