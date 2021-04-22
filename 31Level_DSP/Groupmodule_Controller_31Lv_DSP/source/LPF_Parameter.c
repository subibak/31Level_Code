/*
 * LPF_Parameter.c
 *
 *  Created on: 2015. 8. 18.
 *      Author: cjs9426
 */


#include "Define_Header.h"

float Fc_rpm = 100, La_rpm = 0, Lb_rpm = 0;

float VM1de_delta = 0, VM1de_pre = 0, VM1de_lpf =0;
void LPF_Parameter(void)
{
	La_rpm = __divf32(2 - PI2 * Fc_rpm * OUTERLOOP_SAMPLING_TIME, 2 + PI2 * Fc_rpm * OUTERLOOP_SAMPLING_TIME);
	Lb_rpm = __divf32(PI2 * Fc_rpm * OUTERLOOP_SAMPLING_TIME, 2 + PI2 * Fc_rpm * OUTERLOOP_SAMPLING_TIME);
}

