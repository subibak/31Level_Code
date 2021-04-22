/*
 * Define_Sensor.h
 *
 *  Created on: 2019. 1. 14.
 *      Author: subi
 */

#ifndef INCLUDE_DEFINE_SENSOR_H_
#define INCLUDE_DEFINE_SENSOR_H_

// Sensor.c
extern float V_SM[6];
extern float V_SM_SUM;
extern float V_SMt[6];
extern float Vol_Temp[12];
extern float Temp[12];
extern float Arm_Cur_A, Arm_Cur_B;
extern float SM_VOL_MAX;
extern float TEMP_MAX;
extern float CUR_MAX;

extern float SM_Vol_offset[6];
extern float Arm_Cur_A_offset, Arm_Cur_B_offset;
extern float Arm_Cur_A_offset_origin, Arm_Cur_B_offset_origin;

extern float offset_sum_SM_Vol[6];
extern float offset_sum_Arm_Cur_A, offset_sum_Arm_Cur_B;

extern Uint16 Arm_Cur_Sign;
extern int Upper_Arm_Cur_Sign, Lower_Arm_Cur_Sign;


#endif /* INCLUDE_DEFINE_SENSOR_H_ */
