/*
 * Define_Basetypes.h
 *
 *  Created on: 2018. 8. 27.
 *      Author: subi
 */

#ifndef DEFINE_BASETYPES_H_
#define DEFINE_BASETYPES_H_

#ifdef __cplusplus
extern "C" {
#endif
// Include header files
#include "F2837xD/F2837xD_device.h"

// Interrupt.c
extern int l, m, k, i, j, t;
extern int Number_SM;
extern int D_Number_SM;
extern int H_Number_SM;
extern Uint16 Group_number;

//LED.C
extern int LED_case;



#ifdef __cplusplus
}
#endif

#endif /* DEFINE_BASETYPES_H_ */
