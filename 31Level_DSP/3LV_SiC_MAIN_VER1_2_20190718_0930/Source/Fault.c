/*
 * Fault.c
 *
 *  Created on: 2019. 6. 27.
 *      Author: HJHeo
 */

#include "Define_Header.h"
#include "Define_Fault.h"

#ifdef CPU1
// Predefine
//// Predefine : Sensed Value.
#define MxIp							M1Ip
#define MxSpeed_Sens					M1Speed_Sens

//// Predefine : Control Value
#define MxCont							M1Cont
#define MxFlag							M1Flag

//// Predefine : Fault Value.
#define MxFault_Level					M1Fault_Level
#define MxFault_Register				M1Fault_Register

// External Value
extern S_FTP M1Ip;
extern S_SPD M1Speed_Sens;

extern S_FTL M1Fault_Level;
extern U_FTR M1Fault_Register;

extern S_MTC M1Cont;
extern S_FLG M1Flag;
#endif

#ifdef CPU2
// Predefine
//// Predefine : Sensed Value.
#define MxIp							M2Ip
#define MxSpeed_Sens					M2Speed_Sens

//// Predefine : Control Value
#define MxCont							M2Cont
#define MxFlag							M2Flag

//// Predefine : Fault Value.
#define MxFault_Level					M2Fault_Level
#define MxFault_Register				M2Fault_Register

// External Value
extern S_FTP M2Ip;
extern S_SPD M2Speed_Sens;

extern S_FTL M2Fault_Level;
extern U_FTR M2Fault_Register;

extern S_MTC M2Cont;
extern S_FLG M2Flag;
#endif

void Fault(void)
{
	// Current Fault
	//// Current Fault : A-Phase
	if (FABS(MxIp.a) > MxFault_Level.Ioc) {
		MxFault_Register.bit.OC_A = 1U;
	}

	//// Current Fault : B-Phase
	if (FABS(MxIp.b) > MxFault_Level.Ioc) {
		MxFault_Register.bit.OC_B = 1U;
	}

	//// Current Fault : B-Phase
	if (FABS(MxIp.c) > MxFault_Level.Ioc) {
		MxFault_Register.bit.OC_C = 1U;
	}

	// Speed Fault
	if ((FABS(MxSpeed_Sens.RPM.low) > MxFault_Level.RPMos) && (MxCont.Flag.all > 1U)) {
		MxFault_Register.bit.OS = 1U;
	}

	if (MxFault_Register.all > 0) {
		MxFlag.Inverter = 0U;
	}

	return;
}
