/*
 * LED1.c
 *
 *  Created on: 2016. 7. 25.
 *      Author: Kwanghae
 */

#include "Define_Header.h"
#include "Define_LED1.h"

#define LED_Time                    1000


Uint16 LED_Loop_cnt = 0, LEDcase =0;

void LED1(void)
{

	if(LED_Loop_cnt++ > LED_Time)
	{
		LED_Loop_cnt = 0;
		switch(LEDcase)
		{
		case 0:
			        LED0_ON  ; LEDcase=1; break;

		case 1:
					LED1_ON  ; LEDcase=2; break;

		case 2:
					LED2_ON  ; LEDcase=3; break;

		case 3:
					LED3_ON  ; LEDcase=4; break;

		case 4:
			        LED0_OFF ; LEDcase=5; break;

		case 5:
					LED1_OFF ; LEDcase=6; break;

		case 6:
					LED2_OFF ; LEDcase=7; break;

		case 7:
					LED3_OFF ; LEDcase=0; break;

		}
	}

	return;
}


