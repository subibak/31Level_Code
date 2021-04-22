/*
 * Define_DAC.h
 *
 *  Created on: 2017. 4. 24.
 *      Author: Seung Hwan
 *  Revised on: 2018.06.19.
 *      Author: Subi
 */

#ifndef DEFINE_DAC_H_
#define DEFINE_DAC_H_

#ifdef __cplusplus
extern "C" {
#endif

#define DAC_MID					8191
#define DAC_RNG					8192
#define DAC_EFF					0x3FFF

#define DA(num)						(da##num.type == 0 ? *(float *)da##num.out : (float)(*(int *)da##num.out))

#define DAC_RESOLUTION			4096

typedef struct{
	void	*out;
	float	rng;
	float	mid;
	Uint16	type;
} S_DA;

typedef struct{
	float out;
	float rng;
	float mid;
	Uint16 type;
} inter_DA;

#define DAC1					((volatile inter_DA *)(0xC000))
#define DAC2					((volatile inter_DA *)(0xD000))
#define DAC3					((volatile inter_DA *)(0xE000))
#define DAC4					((volatile inter_DA *)(0xF000))
#define DAC5					((volatile inter_DA *)(0x10000))
#define DAC6					((volatile inter_DA *)(0x11000))
#define DAC7					((volatile inter_DA *)(0x12000))
#define DAC8                    ((volatile inter_DA *)(0x13000))

#ifdef __cplusplus
extern "C" {
#endif

#endif /* INCLUDE_DEFINE_DAC_H_ */
