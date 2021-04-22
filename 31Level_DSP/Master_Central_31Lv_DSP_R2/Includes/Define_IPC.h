/*
 * Define_IPC.h
 *
 *  Created on: 2019. 1. 8.
 *      Author: MP2C
 */

#ifndef INCLUDES_DEFINE_IPC_H_
#define INCLUDES_DEFINE_IPC_H_

#ifdef __cpluscplus
extern "C" {
#endif

#define IPC_FLAG_SET    1U
#define IPC_FLAG_CLEAR  0U
#define IPC_STATUS_HIGH 1U
#define IPC_STATUS_LOW  0U

extern void IPC_DSP_WR(void);
extern void IPC_DSP_RD(void);

#ifdef __cplusplus
}
#endif


#endif /* INCLUDES_DEFINE_IPC_H_ */
