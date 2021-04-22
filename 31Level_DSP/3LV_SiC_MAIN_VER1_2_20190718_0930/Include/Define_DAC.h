/*
 * Define_DAC.h
 *
 *  Created on: 2019. 6. 27.
 *      Author: HJHeo
 */

#ifndef INCLUDE_DEFINE_DAC_H_
#define INCLUDE_DEFINE_DAC_H_

#ifdef __cplusplus
extern "C" {
#endif

// Prototype Define.
extern void DAC(void);

// Predefine.
//// Predefine : DAC Bit Range.
#define	DAC_MID				8192.0F
#define	DAC_RNG				8191.0F
#define	DAC_EFF				0x3FFFU

// In-Line Function.
//// In-Line Function : DAC Variable Type.
#define DA(num)				(da##num.type == 0 ? *(float *)da##num.out : (float)(*(int *)da##num.out))

// Structure Define.
typedef struct {
	void	*out;
	float	rng;
	float	mid;
	Uint16	type;
} S_DAC;

#ifdef __cplusplus
}
#endif

#endif /* INCLUDE_DEFINE_DAC_H_ */
