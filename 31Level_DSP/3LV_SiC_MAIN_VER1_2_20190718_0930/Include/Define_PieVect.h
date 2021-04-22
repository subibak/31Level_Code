/*
 * Define_PieVect.h
 *
 *  Created on: 2019. 6. 24.
 *      Author: HJHeo
 */

#ifndef INCLUDE_DEFINE_PIEVECT_H_
#define INCLUDE_DEFINE_PIEVECT_H_

#ifdef __cplusplus
extern "C" {
#endif

// Prototype Define
//// Prototype Define : Interrupt Vector Table Initializing
extern void Init_PieVectTable(void);
extern interrupt void ISR_Default(void);

#ifdef __cplusplus
}
#endif

#endif /* INCLUDE_DEFINE_PIEVECT_H_ */
