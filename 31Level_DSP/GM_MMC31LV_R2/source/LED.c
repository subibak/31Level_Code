/*
 * LED.c
 *
 *  Created on: 2020. 10. 10.
 *      Author: subi
 */

#include "Define_Header.h"

#pragma DATA_SECTION(DSP_LED_case1,"DspLedCaseFile");
Uint16 DSP_LED_case1 = 0;

#pragma DATA_SECTION(DSP_LED_cnt1,"DspLedCntFile");
Uint16 DSP_LED_cnt1  = 0;

Uint16 DSP_LED_case = 0;
Uint16 DSP_LED_cnt  = 0;

void LED_DSP(void)
{
    if(++DSP_LED_cnt > DSP_LED_TIME)
    {
        switch(DSP_LED_case)
        {
#ifdef CPU1
            case 0: LED0_ON;    DSP_LED_case++;     break;
            case 1: LED1_ON;    DSP_LED_case++;     break;
            case 4: LED0_OFF;   DSP_LED_case++;     break;
            case 5: LED1_OFF;   DSP_LED_case++;     break;
            case 2:             DSP_LED_case++;     break;
            case 3:             DSP_LED_case++;     break;
            case 6:             DSP_LED_case++;     break;
            case 7:             DSP_LED_case = 0;   break;
            default :               break;
#endif
#ifdef CPU2
            case 0:             DSP_LED_case++;     break;
            case 1:             DSP_LED_case++;     break;
            case 4:             DSP_LED_case++;     break;
            case 5:             DSP_LED_case++;     break;
            case 2: LED2_ON;    DSP_LED_case++;     break;
            case 3: LED3_ON;    DSP_LED_case++;     break;
            case 6: LED2_OFF;   DSP_LED_case++;     break;
            case 7: LED3_OFF;   DSP_LED_case = 0;   break;
            default :               break;
#endif
        }

        DSP_LED_cnt = 0;
    }

    return;
}

