/*`````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````
 * main.c
 */

#include "Define_Header.h"

void main(void) {

	DisableDog();				// Disable WatchDog.

	Init_PLL();					// PLL Initializing(300[MHz])
	Init_PeripheralClocks();	// Peripheral Clock Enable/Disable.

	Init_PieCtrl();				// Interrupt Initializing.
	Init_PieVectTable();		// Interrupt Vector Table Initializing.

	Init_GPIO();				// Pin Function Selection.
	//Init_SPI();					// SPI Initializing.
	//Init_SCI();                 // SCI Initializing.
//	Init_CAN();					// CAN Initializing.

	Init_Xintf();				// External Interface Initializing.
	Init_ADC();					// ADC Initializing.

	//Init_QEP();					// QEP Initializing.
	Init_PWM();					// PWM Initializing.
	LPF_Parameter();			// Low Pass Parameter

	Start_PieCtrl();			// Interrupt Enable Start.
	Start_PWM();				// PWM Time Base Start.

	while(1);
}
