/*
 * AM572x_C66_device.h
 *
 *  Created on: 2018. 11. 6.
 *      Author: HJHeo
 */

#ifndef AM572X_C66_DEVICE_H_
#define AM572X_C66_DEVICE_H_

// Common CPU Definitions.
extern __cregister volatile unsigned int CSR;
extern __cregister volatile unsigned int ICR;
extern __cregister volatile unsigned int IER;
extern __cregister volatile unsigned int IFR;
extern __cregister volatile unsigned int ISTP;
extern __cregister volatile unsigned int TSR;
extern __cregister volatile unsigned int TSCL;

// Interrupt
#define M_RST					0x00000001
#define M_NMI					0x00000002
#define M_INT4					0x00000010
#define M_INT5					0x00000020
#define M_INT6					0x00000040
#define M_INT7					0x00000080
#define M_INT8					0x00000100
#define M_INT9					0x00000200
#define M_INT10					0x00000400
#define M_INT11					0x00000800
#define M_INT12					0x00001000
#define M_INT13					0x00002000
#define M_INT14					0x00004000
#define M_INT15					0x00008000

// Basic Data Types Define.
#ifndef DSPC66_DATA_TYPES
#define DSPC66_DATA_TYPES
typedef	signed 		char		int8;
typedef 			short		int16;
typedef				int			int32;
typedef				long		int64;

typedef unsigned	char		Uint8;
typedef unsigned	short		Uint16;
typedef unsigned	int			Uint32;
typedef unsigned	long		Uint64;
#endif

// Include Files.
#include "AM572x_C66_CM_CORE_AON__IPU.h"
#include "AM572x_C66_DSP_ICFG.h"

#include "AM572x_C66_CTRL_MODULE_CORE.h"

#include "AM572x_C66_PRCM_L4CFG_CM_CORE_AON__DSP1.h"
#include "AM572x_C66_PRCM_L4CFG_CM_CORE__CORE.h"
#include "AM572x_C66_PRCM_L4CFG_CM_CORE__L4PER.h"

#include "AM572x_C66_Timer.h"
#include "AM572x_C66_GPIO.h"
#include "AM572x_C66_GPMC.h"

#include "AM572x_C66_McSPI.h"
#include "AM572x_C66_IPC.h"
#include "AM572x_C66_Mailbox.h"

#endif /* AM572X_C66_DEVICE_H_ */
