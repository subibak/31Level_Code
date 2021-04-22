/*
 * Define_Fault.h
 *
 *  Created on: 2019. 1. 9.
 *      Author: subi
 */

#ifndef INCLUDES_DEFINE_FAULT_H_
#define INCLUDES_DEFINE_FAULT_H_

extern Uint16 Flag_fault;
extern Uint16 Fault_register1;
extern Uint16 Fault_register2;
extern Uint16 Fault_register3;
extern Uint16 Fault_register4;
extern Uint16 Fault_register5;
extern Uint16 Fault_register6;
extern Uint16 Fault_register7;

extern float I_ARM_oC;
extern float I_LINE_OC;
extern float fault_test;

extern void fault(void);

#endif /* INCLUDES_DEFINE_FAULT_H_ */
