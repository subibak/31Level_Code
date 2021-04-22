/*
 * Define.Fault.h
 *
 *  Created on: 2018. 9. 29.
 *      Author: subi
 */

#ifndef INCLUDE_DEFINE_FAULT_H_
#define INCLUDE_DEFINE_FAULT_H_

#ifdef __cplusplus
extern "C" {
#endif

extern float SM_VOL_UNDER_Limit;
extern float SM_VOL_OVER_LIMIT;
extern float TEMP_LIMIT;

struct Flag_Fault_BITS {
    Uint32  Communication:8;
    Uint32  V_SM1:1;
    Uint32  V_SM2:1;
    Uint32  V_SM3:1;
    Uint32  V_SM4:1;
    Uint32  V_SM5:1;
    Uint32  V_SM6:1;
    Uint32  rsvd0:2;
    Uint32  TEMP1:1;
    Uint32  TEMP2:1;
    Uint32  TEMP3:1;
    Uint32  TEMP4:1;
    Uint32  TEMP5:1;
    Uint32  TEMP6:1;
    Uint32  TEMP7:1;
    Uint32  TEMP8:1;
    Uint32  TEMP9:1;
    Uint32  TEMP10:1;
    Uint32  TEMP11:1;
    Uint32  TEMP12:1;
    Uint32  rsvd1:4;
};

union Flag_Fault_DATA {
    struct Flag_Fault_BITS  bit;
    Uint32                  all;
};

extern union Flag_Fault_DATA FlagFault;

#ifdef __cplusplus
}
#endif

#endif /* INCLUDE_DEFINE_FAULT_H_ */
