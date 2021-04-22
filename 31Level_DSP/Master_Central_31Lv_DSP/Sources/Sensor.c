/*
 * Sensor.c
 *
 *  Created on: 2018. 12. 17.
 *      Author: subi
 */


#include "Define_Header.h"
#include "Define_ADC.h"

float V_AB = 0, V_BC = 0, V_CA = 0;
float V_AS_pri = 0, V_BS_pri = 0, V_CS_pri = 0;
float V_AS_sec = 0, V_BS_sec = 0, V_CS_sec = 0;
float V_AB_sec = 0, V_BC_sec = 0, V_CA_sec = 0;
float V_DC = 0;
float I_AS = 0, I_BS = 0, I_CS = 0;
float I_RS = 0, I_SS = 0, I_TS = 0;
float I_DC = 0;
float I_AU = 0, I_BU = 0, I_CU = 0;
float I_AL = 0, I_BL = 0, I_CL = 0;
float I_AO = 0, I_BO = 0, I_CO = 0;
float I_T1 = 0, I_T2 = 0;

union TRANSFER_DATA V_AS_sec_T;
union TRANSFER_DATA V_BS_sec_T;
union TRANSFER_DATA V_CS_sec_T;
union TRANSFER_DATA I_AS_T;
union TRANSFER_DATA I_BS_T;
union TRANSFER_DATA I_CS_T;
union TRANSFER_DATA I_AU_T;
union TRANSFER_DATA I_AL_T;
union TRANSFER_DATA I_BU_T;
union TRANSFER_DATA I_BL_T;
union TRANSFER_DATA I_CU_T;
union TRANSFER_DATA I_CL_T;
union TRANSFER_DATA V_DC_T;
union TRANSFER_DATA I_DC_T;

float V_grid_max = 570;             //Grid maximum value plus some margin
float V_dc_max = 9743;             //2.2V output from sensor for 2200V and a gain of 4.5 is used in the amplifier
float I_sensor_max = 125;          //output voltage when current is 125A10V
float Trans_ratio = 2.85F;       //star-delta transformer

//low pass filter parameters
float Vdc_low = 0, Idc_sensor_low=0, Vdc_old =0, Twc_Vdc =0.03, Tcl =0.00628318, I_DC_old =0;

void Sensor_Outside(void)
{
    //AC line-to-line Voltage
    V_AB = (float)(AIN3_CH1 << 20 >> 20) * ADC_RESOLUTION * V_grid_max; //- V_AB_offset;
    V_BC = (float)(AIN3_CH2 << 20 >> 20) * ADC_RESOLUTION * V_grid_max; //- V_BC_offset;
    V_CA = (float)(AIN3_CH3 << 20 >> 20) * ADC_RESOLUTION * V_grid_max; //- V_CA_offset;
    //DC Voltage
    V_DC = (float)(AIN3_CH4 << 20 >> 20) * ADC_RESOLUTION * V_dc_max;
    //AC Current
    I_AS = (float)(AIN0_CH1 << 20 >> 20) * ADC_RESOLUTION * I_sensor_max- I_AS_offset;
    I_BS = (float)(AIN0_CH2 << 20 >> 20) * ADC_RESOLUTION * I_sensor_max- I_BS_offset;
    I_CS = (float)(AIN0_CH3 << 20 >> 20) * ADC_RESOLUTION * I_sensor_max- I_CS_offset;

 //   I_DC = (float)(AIN0_CH4 << 20 >> 20) * ADC_RESOLUTION * I_sensor_max;

    //AC phase voltage
    V_AS_pri = (V_AB - V_CA) * INV_3;
    V_BS_pri = (V_BC - V_AB) * INV_3;
    V_CS_pri = (V_CA - V_BC) * INV_3;

    //Secondary side
//    V_AS_sec =(V_AS_pri - V_CS_pri)*Trans_ratio*INV_SQRT3;          //transformer secondary voltage calculated from primary measured voltages
//    V_BS_sec =(V_BS_pri - V_AS_pri)*Trans_ratio*INV_SQRT3;          //consider 30 degree phase shift and turn ratio of the transformer
//    V_CS_sec =(V_CS_pri - V_BS_pri)*Trans_ratio*INV_SQRT3;
//    V_AB_sec =(V_AB - V_CA)*Trans_ratio*INV_SQRT3;          //transformer secondary voltage calculated from primary measured voltages
//    V_BC_sec =(V_BC - V_AB)*Trans_ratio*INV_SQRT3;          //consider 30 degree phase shift and turn ratio of the transformer
//    V_CA_sec =(V_CA - V_BC)*Trans_ratio*INV_SQRT3;
    V_AB_sec =(V_AB - V_BC)*Trans_ratio*INV_SQRT3;          //transformer secondary voltage calculated from primary measured voltages
    V_BC_sec =(V_BC - V_CA)*Trans_ratio*INV_SQRT3;          //consider 30 degree phase shift and turn ratio of the transformer
    V_CA_sec =(V_CA - V_AB)*Trans_ratio*INV_SQRT3;

    V_AS_sec  =(V_AB_sec - V_CA_sec)* INV_3;          //transformer secondary voltage calculated from primary measured voltages
    V_BS_sec  =(V_BC_sec - V_AB_sec)* INV_3;          //consider 30 degree phase shift and turn ratio of the transformer
    V_CS_sec  =(V_CA_sec - V_BC_sec)* INV_3;

    I_RS = -I_AS;
    I_SS = -I_BS;
    I_TS = -I_CS;

    Vdc_low = LPF1(Vdc_low, V_DC, Vdc_old, Twc_Vdc);

    V_AS_sec_T.all_F = V_AS_sec;
    V_BS_sec_T.all_F = V_BS_sec;
    V_CS_sec_T.all_F = V_CS_sec;

    V_DC_T.all_F = V_DC;

    I_AS_T.all_F = I_AS;
    I_BS_T.all_F = I_BS;
    I_CS_T.all_F = I_CS;
}

void Sensor_Inside(void)
{
    //Arm Current
    I_AU = (float)(AIN1_CH1 << 20 >> 20) * ADC_RESOLUTION * I_sensor_max - I_AU_offset;
    I_BU = (float)(AIN1_CH2 << 20 >> 20) * ADC_RESOLUTION * I_sensor_max - I_BU_offset;
    I_CU = (float)(AIN1_CH3 << 20 >> 20) * ADC_RESOLUTION * I_sensor_max - I_CU_offset;
    I_AL = (float)(AIN2_CH1 << 20 >> 20) * ADC_RESOLUTION * I_sensor_max - I_AL_offset;
    I_BL = (float)(AIN2_CH2 << 20 >> 20) * ADC_RESOLUTION * I_sensor_max - I_BL_offset;
    I_CL = (float)(AIN2_CH3 << 20 >> 20) * ADC_RESOLUTION * I_sensor_max - I_CL_offset;
    //Test for two left channels
//    I_T1 = (float)(AIN1_CH4 << 20 >> 20) * ADC_RESOLUTION * I_sensor_max;
//    I_T2 = (float)(AIN2_CH4 << 20 >> 20) * ADC_RESOLUTION * I_sensor_max;
    //Leg Current
    I_AO = (I_AU + I_AL) * 0.5;
    I_BO = (I_BU + I_BL) * 0.5;
    I_CO = (I_CU + I_CL) * 0.5;
    //Current Direction
    if(I_AU >= 0) CenLegOpData_Aupper.bit.Arm_current_Dir = 1;
    else          CenLegOpData_Aupper.bit.Arm_current_Dir = 0;

    if(I_AL >= 0) CenLegOpData_Alower.bit.Arm_current_Dir = 1;
    else          CenLegOpData_Alower.bit.Arm_current_Dir = 0;

    if(I_BU >= 0) CenLegOpData_Bupper.bit.Arm_current_Dir = 1;
    else          CenLegOpData_Bupper.bit.Arm_current_Dir = 0;

    if(I_BL >= 0) CenLegOpData_Blower.bit.Arm_current_Dir = 1;
    else          CenLegOpData_Blower.bit.Arm_current_Dir = 0;

    if(I_CU >= 0) CenLegOpData_Cupper.bit.Arm_current_Dir = 1;
    else          CenLegOpData_Cupper.bit.Arm_current_Dir = 0;

    if(I_CL >= 0) CenLegOpData_Clower.bit.Arm_current_Dir = 1;
    else          CenLegOpData_Clower.bit.Arm_current_Dir = 0;

    I_AU_T.all_F = I_AU;
    I_AL_T.all_F = I_AL;
    I_BU_T.all_F = I_BU;
    I_BL_T.all_F = I_BL;
    I_CU_T.all_F = I_CU;
    I_CL_T.all_F = I_CL;

}
