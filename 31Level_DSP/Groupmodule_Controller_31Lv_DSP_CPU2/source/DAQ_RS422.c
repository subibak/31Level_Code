/*
 * DAQ_RS422.c
 *
 *  Created on: 2018. 07. 04.
 *      Author: Subi
 */

/////////////////////////Test for Data Transmission to HMI vis RS422//////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Processing Speed of RX is about
// 0.0096 MHz -> 104.166 us (signal extension 11000 counts), it takes 1041.666.. us sending 10 bits(start, stop 1 bit, data 8 bits), TX_LOOP_MAX 100(10 ms)
// takes 39.584 ms sending 380 bits
// RX_CLK 0.192 MHz -> 5.208 us (signal extension 530 counts)
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 0.0576 MHz -> 17.361 us  (signal extension 1800  counts), it takes 17.3611 .. us sending 10 bits(start, stop 1 bit, data 8 bits), TX_LOOP_MAX 100(10 ms)
// takes 6.59718 ms sending 380 bits
// RX_CLK 1.152 MHz -> 0.8685 us (signal extension 100 counts)
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 1.8432 MHz -> 0.54253472 us (signal extension 60 counts), it takes 5.4253472.. us sending 10 bits(start, stop 1 bit, data 8 bits), TX_LOOP_MAX 100(10 ms)
// takes 0.207 ms sending 380 bits
// RX_CLK 36.864 MHz -> 0.0271 us (signal extension 4 counts)
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 0.115200 MHz -> 8.6805 us (signal extension 900 counts), it takes 86.805.. us sending 10 bits(start, stop 1 bit, data 8 bits), TX_LOOP_MAX 100(10 ms)
// takes 3.271 ms sending 380 bits
// RX_CLK 2.304 MHz -> 0.4340277 us (signal extension 50 counts)
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 0.9216 MHz -> 1.085069 us (signal extension 110 counts), it takes 10.850692.. us sending 10 bits(start, stop 1 bit, data 8 bits), TX_LOOP_MAX 100(10 ms)
// takes 0.412 ms sending 380 bits
// RX_CLK 18.432 MHz -> 0.05425 us (signal extension 7 counts)
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "Define_Header.h"


int test_tx_cnt = 1;

Uint16 TEST_RX[38] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
Uint16 TEST_TX[20] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
Uint16 DAQ_TX[20] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
Uint16 fault = 0;
Uint16 EX_DATA[10];
Uint16 RX_DATA = 0;
Uint16 RX_ACCESS_INDEX = 0;

void DAQ_RS422(float VSM[], float SM_Temp[], Uint16 G_Num, Uint16 SM_Fault)
{
   static Uint16 DAQ_RS422_CNT = 0;
   static Uint32 cRIO_Load_CNT = 0;

   if(Dsp2EcatMaster.Operation.bit.DAQ_READY == 1)                  // cRIO_LOAD_CNT is the loading time of cRIO program on RAM
    {
       if(DAQ_RS422_CNT < 668)
       {
           *DAQ_CNT = DAQ_RS422_CNT;

           *RS422_TX_VOL00 = (Uint16)(100 * VSM[0]);
           *RS422_TX_VOL01 = (Uint16)(100 * VSM[1]);
           *RS422_TX_VOL02 = (Uint16)(100 * VSM[2]);
           *RS422_TX_VOL03 = (Uint16)(100 * VSM[3]);
           *RS422_TX_VOL04 = (Uint16)(100 * VSM[4]);
           *RS422_TX_VOL05 = (Uint16)(100 * VSM[5]);

           if(DAQ_RS422_CNT == 334)
           {
               *RS422_RX_AUX_SET = 0;               // This is the reset of the stack pointer of RX_BUFFER for checking the received data in loopback
               *RS422_RX_SET = 0;                   // and the reset of RS422 operation
               *RS422_TX_AUX_SET = 0;
               *RS422_TX_SET = 0;
           }

           DAQ_RS422_CNT += 1;
       }
       else if(DAQ_RS422_CNT == 668)
       {
           *RS422_TX_TEMP00 = (int16)(100 * SM_Temp[0]);
           *RS422_TX_TEMP01 = (int16)(100 * SM_Temp[1]);
           *RS422_TX_TEMP02 = (int16)(100 * SM_Temp[2]);
           *RS422_TX_TEMP03 = (int16)(100 * SM_Temp[3]);
           *RS422_TX_TEMP04 = (int16)(100 * SM_Temp[4]);
           *RS422_TX_TEMP05 = (int16)(100 * SM_Temp[5]);
           *RS422_TX_TEMP06 = (int16)(100 * SM_Temp[6]);
           *RS422_TX_TEMP07 = (int16)(100 * SM_Temp[7]);
           *RS422_TX_TEMP08 = (int16)(100 * SM_Temp[8]);
           *RS422_TX_TEMP09 = (int16)(100 * SM_Temp[9]);
           *RS422_TX_TEMP10 = (int16)(100 * SM_Temp[10]);
           *RS422_TX_TEMP11 = (int16)(100 * SM_Temp[11]);

           *RS422_TX_NUM = G_Num;
           *RS422_TX_FAULT = SM_Fault;

           *RS422_TX_EX1 = EX_DATA[0];                                   //TX STATUS
           *RS422_TX_EX2 = EX_DATA[1];
           *RS422_TX_EX3 = EX_DATA[2];
           *RS422_TX_EX4 = EX_DATA[3];
           *RS422_TX_EX5 = EX_DATA[4];
           *RS422_TX_EX6 = EX_DATA[5];
           *RS422_TX_EX7 = EX_DATA[6];
           *RS422_TX_EX8 = EX_DATA[7];


           DAQ_RS422_CNT += 1;

           FlagFault.bit.Communication = 0x00;

       }
       else if(DAQ_RS422_CNT >= (DAQ_RS422_MAX-1))  DAQ_RS422_CNT = 0;
       else                                         DAQ_RS422_CNT += 1;


   }
   else cRIO_Load_CNT += 1;

   RX_DATA = *RS422_RX_MEM_STORE;

   return;
}

