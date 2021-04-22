/*
 * Define_DAC.h
 *
 *  Created on: 2012. 8. 14.
 *      Author: HJHeo
 */

#ifndef DEFINE_DAC_H_
#define DEFINE_DAC_H_

#ifdef __cplusplus
extern "C" {
#endif

#if (DAC8420)
	#define DAC_MID				2047
	#define DAC_RNG				2048
	#define DAC_EFF				0x1FFF
#elif (DAC8803)
	#define DAC_MID				8191
	#define DAC_RNG				8192
	#define DAC_EFF				0x3FFF
#endif

#define DA(num)					(da##num.type == 0 ? *(float *)da##num.out : (float)(*(int *)da##num.out))

#define HI_LOAD					GpioDataRegs.GPBSET.bit.GPIO49 = 1
#define LO_LOAD					GpioDataRegs.GPBCLEAR.bit.GPIO49 = 1

typedef struct{
	void	*out;
	float	rng;
	float	mid;
	Uint16	type;
} S_DA;

#ifdef __cplusplus
extern "C" {
#endif

#endif /* DEFINE_DAC_H_ */
