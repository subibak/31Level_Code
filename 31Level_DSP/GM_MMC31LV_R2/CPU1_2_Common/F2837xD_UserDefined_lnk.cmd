/*
 * F2837xD_UserDefined_lnk_cpu1.cmd
 *
 *   Edited on: 2020. 10. 10.
 *      Author: subi
 */

 #define UserDefined_GS6_BASE		0x012000		//RAMGS6 0x012000(length = 0x001000)

 #define DspLed_OFFSET				0x000002		//DSP_LED Varaible Offset
 #define DspLedCase_LENGTH			0x000001		//DSP_LED_case Length
 #define DspLedCnt_LENGTH			0x000001		//DSP_LED_cnt Length

 SECTIONS
 {
	DspLedCaseFile			> UserDefined_GS6_BASE + DspLedCase_LENGTH
	DspLedCntFile			> UserDefined_GS6_BASE + DspLedCase_LENGTH + DspLedCnt_LENGTH
 }
