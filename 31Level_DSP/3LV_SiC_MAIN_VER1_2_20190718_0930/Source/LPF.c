/*
 * LPF.c
 *
 *  Created on: 2019. 6. 24.
 *      Author: HJHeo
 */

#include "Define_Header.h"
#include "Define_LPF.h"

#if ((defined(CPU1) && (!CPU2_BOOT_ENABLE)) || defined(CPU2))
#define Fc_Vdc					100.0F

extern S_VDC Vdc;
#endif

#ifdef CPU1
#define Fc_M1RPM					100.0F

#define MxSamp						M1Samp

extern S_STV M1Samp;
extern S_SPD M1Speed_Sens;
#endif

#ifdef CPU2
#define MxSamp						M2Samp

extern S_STV M2Samp;
#endif

void LPF_Parameter(void)
{
	// DC-Link Voltage.
#if ((defined(CPU1) && (!CPU2_BOOT_ENABLE)) || CPU2)
	Vdc.p.La = DIVF32(2.0F - MPY2PIF32(Fc_Vdc) * MxSamp.TIMEBASE.TIME, 2.0F + MPY2PIF32(Fc_Vdc) * MxSamp.TIMEBASE.TIME);
	Vdc.p.Lb = DIVF32(MPY2PIF32(Fc_Vdc) * MxSamp.TIMEBASE.TIME, 2.0F + MPY2PIF32(Fc_Vdc) * MxSamp.TIMEBASE.TIME);
	Vdc.n.La = Vdc.p.La;
	Vdc.n.Lb = Vdc.p.Lb;
#endif

#ifdef CPU1
	// M1 Motor Speed.
	M1Speed_Sens.RPM.La = DIVF32(2.0F - MPY2PIF32(Fc_M1RPM) * MxSamp.OUTERLOOP.TIME, 2.0F + MPY2PIF32(Fc_M1RPM) * MxSamp.OUTERLOOP.TIME);
	M1Speed_Sens.RPM.Lb = DIVF32(MPY2PIF32(Fc_M1RPM) * MxSamp.OUTERLOOP.TIME, 2.0F + MPY2PIF32(Fc_M1RPM) * MxSamp.OUTERLOOP.TIME);
#endif

	return;
}
