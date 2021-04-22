/*
 * Sensor.c
 *
 *  Created on: 2018. 06. 19.
 *      Author: Subi
 */

#include "Define_Header.h"

//float Vol_Temp[12] = {0,0,0,0,0,0,0,0,0,0,0,0};



//void Temp_Calc(void)
//{
//    //NTCS0805E3153JMT model ---> -20 Celsius => 123,815 ohm   <=> This is the maximum value.
//    //So the maximum voltage, which would be measured by ADC, is 5V * 123815 / (1000 + 123815) = 4.9599 V
//    while((IpcRegs.IPCFLG.bit.IPC6 & 0x00F0) == IPCxxx_IPC6);
//    IpcRegs.IPCSET.all |= IPCxxx_IPC5;
//    for(t = 0; t < D_Number_SM; t++) Vol_Temp[t] = IPC_Temp_Vol[t].all;
//    IpcRegs.IPCSET.all = 0;
//
//    for(t = 0; t < D_Number_SM; t++)
//    {
//        //Calculation of NTC resistor from the measured voltage(Vol_Temp) - Voltage distribution
//        Rt_num[t] = Vol_Temp[t] * 1000;             // 1000 = 1kohm
//       Rt_denum[t] = (5 - Vol_Temp[t]);         // 5 = 5V_analog
//        Rt[t] = Rt_num[t] / Rt_denum[t];
//        //Calculation of the ration Rt / R25
//        Rt_R25C[t] = Rt[t] * Inv_R25;
//        //Calculation of the temperature in celsius
//        Temp[t] = 1 / (INV_TEMP_K_25C + INV_B_CONST * log(Rt_R25C[t])) - TEMP_K_0C;
//    }
//
//    while((IpcRegs.IPCFLG.bit.IPC7 & 0x00F0) == IPCxxx_IPC7);
//    IpcRegs.IPCSET.all |= IPCxxx_IPC4;
//    for(t = 0; t < D_Number_SM; t++) IPC_Temp_Cal[t].all = Temp[t];
//    IpcRegs.IPCSET.all = 0;
//}
