/*
 * LED.c
 *
 *  Created on: 2019. 7. 1.
 *      Author: HJHeo
 */

#include "Define_Header.h"
#include "Define_LED.h"

// Predefine
//// Predefine : LED Time
#define LEDCOUNT_MAX			1000				// 100[us] x 1000 = 100[ms]

#ifdef CPU1
// CPU1 Predefine
//// CPU1 Predefine : GPIO
#define CPUx_LED0_ON			LED0_ON
#define CPUx_LED0_OFF			LED0_OFF
#define CPUx_LED1_ON			LED1_ON
#define CPUx_LED1_OFF			LED1_OFF
#endif

#ifdef CPU2
// CPU1 Predefine
//// CPU1 Predefine : GPIO
#define CPUx_LED0_ON			LED2_ON
#define CPUx_LED0_OFF			LED2_OFF
#define CPUx_LED1_ON			LED3_ON
#define CPUx_LED1_OFF			LED3_OFF
#endif

void LED(void)
{
	static Uint16 LEDCount = 1, LEDCase = 0;

	if (LEDCount++ > LEDCOUNT_MAX)
	{
		switch (LEDCase)
		{
		case 0:	CPUx_LED0_ON;	LEDCase++;	break;
		case 1:	CPUx_LED1_ON;	LEDCase++;	break;
		case 2:	CPUx_LED0_OFF;	LEDCase++;	break;
		default:CPUx_LED1_OFF;	LEDCase = 0;break;
		}

		LEDCount = 1;
	}

	return;
}
