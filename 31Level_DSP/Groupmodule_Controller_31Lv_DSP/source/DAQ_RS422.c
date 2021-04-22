/*
 * DAQ_RS422.c
 *
 *  Created on: 2018. 07. 04.
 *      Author: Subi
 */


#include "Define_Header.h"


int test_tx_cnt = 1;

Uint16 TEST_RX[38] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
Uint16 TEST_TX[20] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
Uint16 DAQ_TX[20] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
Uint16 fault = 0;

Uint16 RX_DATA = 0;
Uint16 RX_ACCESS_INDEX = 0;

void DAQ_RS422_TXRX(void)
{
    static Uint16 TX_loop_cnt = 0;

    /////////////////////////Test for Data Transmission to HMI vis RS422//////////////////////////

    /*
        for(i=0; i < 6; i++)
        {
            theta_test[i] += PI2 * TIMEBASE1_SAMPLING_TIME * freq_test[i];
            if(theta_test[i] >= PI2)      theta_test[i] -= PI2;
            else if(theta_test[i] < 0)   theta_test[i] += PI2;

            sine_test[i] = sin(theta_test[i]);

        }

    */
        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        // Processing Speed of RX is about
        // 0.0096 MHz -> 104.166 us (signal extension 11000 counts), it takes 1041.666.. us sending 10 bits(start, stop 1 bit, data 8 bits), TX_LOOP_MAX 100(10 ms)
        // takes 39.584 ms sending 380 bits
        // RX_CLK 0.192 MHz -> 27.124 us (signal extension 2800 counts)
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
        // 0.115200 MHz -> 8.6805 us (signal extension 900 counts), it takes 5.4253472.. us sending 10 bits(start, stop 1 bit, data 8 bits), TX_LOOP_MAX 100(10 ms)
        // takes 0.207 ms sending 380 bits
        // RX_CLK 2.304 MHz -> 0.4340277 us (signal extension 50 counts)
        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        // 0.9216 MHz -> 1.085069 us (signal extension 110 counts), it takes 10.850692.. us sending 10 bits(start, stop 1 bit, data 8 bits), TX_LOOP_MAX 100(10 ms)
        // takes 0.412 ms sending 380 bits
        // RX_CLK 18.432 MHz -> 0.05425 us (signal extension 7 counts)
        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        if (TX_loop_cnt++ >= TX_LOOP_MAX)//TX_LOOP_MAX
        {
           *RS422_RX_AUX_SET = 0x00;
           *RS422_RX_SET = 0x00;

           TEST_RX[0] = *RS422_RX_READ00;
           TEST_RX[1] = *RS422_RX_READ01;
           TEST_RX[2] = *RS422_RX_READ02;
           TEST_RX[3] = *RS422_RX_READ03;
           TEST_RX[4] = *RS422_RX_READ04;
           TEST_RX[5] = *RS422_RX_READ05;
           TEST_RX[6] = *RS422_RX_READ06;
           TEST_RX[7] = *RS422_RX_READ07;
           TEST_RX[8] = *RS422_RX_READ08;
           TEST_RX[9] = *RS422_RX_READ09;

           TEST_RX[10] = *RS422_RX_READ10;
           TEST_RX[11] = *RS422_RX_READ11;
           TEST_RX[12] = *RS422_RX_READ12;
           TEST_RX[13] = *RS422_RX_READ13;
           TEST_RX[14] = *RS422_RX_READ14;
           TEST_RX[15] = *RS422_RX_READ15;
           TEST_RX[16] = *RS422_RX_READ16;
           TEST_RX[17] = *RS422_RX_READ17;
           TEST_RX[18] = *RS422_RX_READ18;
           TEST_RX[19] = *RS422_RX_READ19;

           TEST_RX[20] = *RS422_RX_READ20;
           TEST_RX[21] = *RS422_RX_READ21;
           TEST_RX[22] = *RS422_RX_READ22;
           TEST_RX[23] = *RS422_RX_READ23;
           TEST_RX[24] = *RS422_RX_READ24;
           TEST_RX[25] = *RS422_RX_READ25;
           TEST_RX[26] = *RS422_RX_READ26;
           TEST_RX[27] = *RS422_RX_READ27;
           TEST_RX[28] = *RS422_RX_READ28;
           TEST_RX[29] = *RS422_RX_READ29;

           TEST_RX[30] = *RS422_RX_READ30;
           TEST_RX[31] = *RS422_RX_READ31;
           TEST_RX[32] = *RS422_RX_READ32;
           TEST_RX[33] = *RS422_RX_READ33;
           TEST_RX[34] = *RS422_RX_READ34;
           TEST_RX[35] = *RS422_RX_READ35;
           TEST_RX[36] = *RS422_RX_READ36;
           TEST_RX[37] = *RS422_RX_READ37;

           DELAY_US(30);

            *RS422_TX_NUM = Group_number;

            *RS422_TX_FAULT = fault;
            *RS422_TX_TEMP00 = TEST_TX[0];
            *RS422_TX_TEMP01 = TEST_TX[1];
            *RS422_TX_TEMP02 = TEST_TX[2];
            *RS422_TX_TEMP03 = TEST_TX[3];
            *RS422_TX_TEMP04 = TEST_TX[4];
            *RS422_TX_TEMP05 = TEST_TX[5];
            *RS422_TX_TEMP06 = TEST_TX[6];
            *RS422_TX_TEMP07 = TEST_TX[7];
            *RS422_TX_TEMP08 = TEST_TX[8];
            *RS422_TX_TEMP09 = TEST_TX[9];
            *RS422_TX_TEMP10 = TEST_TX[10];
            *RS422_TX_TEMP11 = TEST_TX[11];

            *RS422_TX_VOL00 = TEST_TX[12];
            *RS422_TX_VOL01 = TEST_TX[13];
            *RS422_TX_VOL02 = TEST_TX[14];
            *RS422_TX_VOL03 = TEST_TX[15];
            *RS422_TX_VOL04 = TEST_TX[16];
            *RS422_TX_VOL05 = test_tx_cnt;

            *RS422_TX_REGISTER = 0x00;
            DELAY_US(2);
    //// These are required to use UART_TX code(FPGA source)
    /*
            *RX422_TX_REGISTER = 0x00;
            DELAY_US(2);
            *RX422_TX_LOAD      = 0x00;
            DELAY_US(1);
            *RX422_TX_BYTEREADY = 0x00;
            DELAY_US(1);
            *RX422_TX_TBYTE     = 0x00;
    */
    ///////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////
            if(test_tx_cnt++ == 8)
                test_tx_cnt = 1;

            *RS422_TX_AUX_SET = 0x00;
            *RS422_TX_SET = 0x00;
            TX_loop_cnt = 0;
        }

    return;
}

void DAQ_RS422(float VSM[], float SM_Temp[], Uint16 G_Num, Uint16 SM_Fault)
{
    static Uint16 DAQ_RS422_CNT = 0;

   if(1)
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
               *RS422_RX_AUX_SET = 0x00;               // This is the reset of the stack pointer of RX_BUFFER for checking the received data in loopback
               *RS422_RX_SET = 0x00;                   // and the reset of RS422 operation
               *RS422_TX_AUX_SET = 0x00;
               *RS422_TX_SET = 0x00;
           }

           DAQ_RS422_CNT += 1;
       }
       else if(DAQ_RS422_CNT == 668)
       {
           *RS422_TX_TEMP00 = (long)(100 * SM_Temp[0]);
           *RS422_TX_TEMP01 = (long)(100 * SM_Temp[1]);
           *RS422_TX_TEMP02 = (long)(100 * SM_Temp[2]);
           *RS422_TX_TEMP03 = (long)(100 * SM_Temp[3]);
           *RS422_TX_TEMP04 = (long)(100 * SM_Temp[4]);
           *RS422_TX_TEMP05 = (long)(100 * SM_Temp[5]);
           *RS422_TX_TEMP06 = (long)(100 * SM_Temp[6]);
           *RS422_TX_TEMP07 = (long)(100 * SM_Temp[7]);
           *RS422_TX_TEMP08 = (long)(100 * SM_Temp[8]);
           *RS422_TX_TEMP09 = (long)(100 * SM_Temp[9]);
           *RS422_TX_TEMP10 = (long)(100 * SM_Temp[10]);
           *RS422_TX_TEMP11 = (long)(100 * SM_Temp[11]);
           *RS422_TX_NUM = G_Num;
           *RS422_TX_FAULT = SM_Fault;

           DAQ_RS422_CNT += 1;

       }
       else if(DAQ_RS422_CNT >= (DAQ_RS422_MAX-1))  DAQ_RS422_CNT = 0;
       else                                         DAQ_RS422_CNT += 1;


   }

   *RS422_RX_MEM_CALL = RX_ACCESS_INDEX;
   RX_DATA = *RS422_RX_MEM_STORE;
   return;
}

