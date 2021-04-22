/*
 * Fault.c
 *
 *  Created on: 2019. 1. 9.
 *      Author: subi
 */

#include "Define_Header.h"
#include "Define_Sensor.h"

float I_ARM_oC=30;
float I_LINE_OC=30;
float V_DC_oV = 2000;

Uint16 Fault_register1 = 0;
Uint16 Fault_register2 = 0;
Uint16 Fault_register3 = 0;
Uint16 Fault_register4 = 0;
Uint16 Fault_register5 = 0;
Uint16 Fault_register6 = 0;
Uint16 Fault_register7 = 0;
Uint16 Fault_register8 = 0;
Uint16 Fault_register9 = 0;
Uint16 Flag_fault = 0;

Uint32 SM_info_AU[5] = {0, 0, 0, 0, 0};    //information received from the leg master controller about SM fault
Uint32 SM_info_BU[5] = {0, 0, 0, 0, 0};
Uint32 SM_info_CU[5] = {0, 0, 0, 0, 0};
Uint32 SM_info_AL[5] = {0, 0, 0, 0, 0};
Uint32 SM_info_BL[5] = {0, 0, 0, 0, 0};
Uint32 SM_info_CL[5] = {0, 0, 0, 0, 0};

Uint16 m;

void fault(void)
{
//Arm Current fault condition

    if (ABS(I_AS) > I_LINE_OC)
        Fault_register1 |= 0x01;
    if (ABS(I_BS) > I_LINE_OC)
        Fault_register1 |= 0x02;
    if (ABS(I_CS) > I_LINE_OC)
        Fault_register1 |= 0x04;

    if (ABS(I_AU) > I_ARM_oC)
        Fault_register2 |= 0x01;
    if (ABS(I_BU) > I_ARM_oC)
        Fault_register2 |= 0x02;
    if (ABS(I_CU) > I_ARM_oC)
        Fault_register2 |= 0x04;

    if (ABS(I_AL) > I_ARM_oC)
        Fault_register3 |= 0x01;
    if (ABS(I_BL) > I_ARM_oC)
        Fault_register3 |= 0x02;
    if (ABS(I_CL) > I_ARM_oC)
        Fault_register3 |= 0x04;

//    if(SmFaultA.bit.COM_VOL.all !=0)
//        Fault_register4 |= 0x01;
//    if(SmFaultA.bit.TEMPERATURE !=0)
//        Fault_register4 |= 0x02;
//    if(SmFaultA.bit.COM_VOL.all !=0)
//        Fault_register4 |= 0x04;
//
//    if(SmFaultB.bit.COM_VOL.all !=0)
//        Fault_register5 |= 0x01;
//    if(SmFaultB.bit.TEMPERATURE !=0)
//        Fault_register5 |= 0x02;
//    if(SmFaultB.bit.COM_VOL.all !=0)
//        Fault_register5 |= 0x04;
//
//    if(SmFaultC.bit.COM_VOL.all !=0)
//        Fault_register6 |= 0x01;
//    if(SmFaultC.bit.TEMPERATURE !=0)
//        Fault_register6 |= 0x02;
//    if(SmFaultC.bit.COM_VOL.all !=0)
//        Fault_register6 |= 0x04;

    if(Vdc_low >= V_DC_oV)
        Fault_register7 |= 0x01;

    if (Fault_register1|Fault_register2|Fault_register3|Fault_register4|Fault_register5|Fault_register6|Fault_register7> 0)
        Flag_fault = 1;

    return;
}


