/*
 * Define_Sensor.h
 *
 *  Created on: 2018. 12. 17.
 *      Author: subi
 */

#ifndef INCLUDES_AM572X_C66_DEFINE_SENSOR_H_
#define INCLUDES_AM572X_C66_DEFINE_SENSOR_H_

#define V_AC_MAX                            560     // AC line-line peak voltage
#define V_DC_MAX                            2000
#define I_AC_MAC                            50
#define I_ARM_MAX                           50

extern float V_AB, V_BC, V_CA;
extern float V_AS_pri, V_BS_pri, V_CS_pri, V_AS_sec, V_BS_sec, V_CS_sec ;
extern float V_DC;
extern float I_AS, I_BS, I_CS;
extern float I_RS, I_SS, I_TS;
extern float I_DC;
extern float I_AU, I_BU, I_CU;
extern float I_AL, I_BL, I_CL;
extern float I_AO, I_BO, I_CO;

//low pass filter parameters
extern float Vdc_low, Idc_sensor_low, Vdc_old, Twc_Vdc, Tcl, I_DC_old;

extern void Sensor_Outside(void);
extern void Sensor_Inside(void);
#endif /* INCLUDES_AM572X_C66_DEFINE_SENSOR_H_ */
