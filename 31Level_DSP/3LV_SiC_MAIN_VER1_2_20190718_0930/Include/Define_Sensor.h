/*
 * Define_Sensor.h
 *
 *  Created on: 2019. 6. 26.
 *      Author: HJHeo
 */

#ifndef INCLUDE_DEFINE_SENSOR_H_
#define INCLUDE_DEFINE_SENSOR_H_

#ifdef __cplusplus
extern "C" {
#endif

extern void Current_Sensor(Uint16, Uint16, Uint16);

#if ((defined(CPU1) && !CPU2_BOOT_ENABLE) || defined(CPU2))
extern void Vdc_Sensor(Uint16, Uint16);
#endif

#ifdef CPU2
extern void Voltage_Sensor(Uint16, Uint16);
#endif

#ifdef __cplusplus
}
#endif

#endif /* INCLUDE_DEFINE_SENSOR_H_ */
