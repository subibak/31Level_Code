
#include "Define_Header.h"

float Fc_rpm = 100, La_rpm = 0, Lb_rpm = 0;


void LPF_Parameter(void)
{
	La_rpm = (2 - PI2 * Fc_rpm * OUTERLOOP_SAMPLING_TIME) / (2 + PI2 * Fc_rpm * OUTERLOOP_SAMPLING_TIME);
	Lb_rpm = PI2 * Fc_rpm * OUTERLOOP_SAMPLING_TIME / (2 + PI2 * Fc_rpm * OUTERLOOP_SAMPLING_TIME);

}
