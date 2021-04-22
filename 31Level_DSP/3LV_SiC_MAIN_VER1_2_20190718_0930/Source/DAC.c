/*
 * DAC.c
 *
 *  Created on: 2019. 6. 27.
 *      Author: HJHeo
 */

#include "Define_Header.h"
#include "Define_DAC.h"

#if ((defined(CPU1) && (!CPU2_BOOT_ENABLE)) || defined(CPU2))
	// Variables.
	//// Variables : DAC.
	#ifdef CPU1
	#pragma DATA_SECTION(da_sel,		"M1da_selFile");
	#pragma DATA_SECTION(da_rng,		"M1da_rngFile");

	#pragma DATA_SECTION(da1,			"M1da1File");
	#pragma DATA_SECTION(da2,			"M1da2File");
	#pragma DATA_SECTION(da3,			"M1da3File");
	#pragma DATA_SECTION(da4,			"M1da4File");

	#pragma DATA_SECTION(da1_invrng,	"M1da1_invrngFile");
	#pragma DATA_SECTION(da2_invrng,	"M1da2_invrngFile");
	#pragma DATA_SECTION(da3_invrng,	"M1da3_invrngFile");
	#pragma DATA_SECTION(da4_invrng,	"M1da4_invrngFile");

	#pragma DATA_SECTION(dac_temp,		"M1dac_tempFile");
	#endif

	#ifdef CPU2
	#pragma DATA_SECTION(da_sel,		"M2da_selFile");
	#pragma DATA_SECTION(da_rng,		"M2da_rngFile");

	#pragma DATA_SECTION(da1,			"M2da1File");
	#pragma DATA_SECTION(da2,			"M2da2File");
	#pragma DATA_SECTION(da3,			"M2da3File");
	#pragma DATA_SECTION(da4,			"M2da4File");

	#pragma DATA_SECTION(da1_invrng,	"M2da1_invrngFile");
	#pragma DATA_SECTION(da2_invrng,	"M2da2_invrngFile");
	#pragma DATA_SECTION(da3_invrng,	"M2da3_invrngFile");
	#pragma DATA_SECTION(da4_invrng,	"M2da4_invrngFile");

	#pragma DATA_SECTION(dac_temp,		"M2dac_tempFile");
	#endif

// Variables.
//// PreStored DAC.
Uint16 da_sel = 0;
float da_rng = 7.0F;

//// Variables : DAC.
S_DAC da1, da2, da3, da4;

//// Variables : DAC Temporary Value.
float da1_invrng, da2_invrng, da3_invrng, da4_invrng;
Uint16 dac_temp[1][4] = {{0U, 0U, 0U, 0U}};
#else
#pragma DATA_SECTION(da_sel,		"M2da_selFile");
#pragma DATA_SECTION(da_rng,		"M2da_rngFile");

#pragma DATA_SECTION(da1,			"M2da1File");
#pragma DATA_SECTION(da2,			"M2da2File");
#pragma DATA_SECTION(da3,			"M2da3File");
#pragma DATA_SECTION(da4,			"M2da4File");

#pragma DATA_SECTION(da1_invrng,	"M2da1_invrngFile");
#pragma DATA_SECTION(da2_invrng,	"M2da2_invrngFile");
#pragma DATA_SECTION(da3_invrng,	"M2da3_invrngFile");
#pragma DATA_SECTION(da4_invrng,	"M2da4_invrngFile");

#pragma DATA_SECTION(dac_temp,		"M2dac_tempFile");

// Variables.
//// PreStored DAC.
Uint16 da_sel;
float da_rng;

//// Variables : DAC.
S_DAC da1, da2, da3, da4;

//// Variables : DAC Temporary Value.
float da1_invrng, da2_invrng, da3_invrng, da4_invrng;
Uint16 dac_temp[1][4];
#endif


#if ((defined(CPU1) && (!CPU2_BOOT_ENABLE)) || defined(CPU2))

// External Value.
//// External Value : M1 Value.
extern S_MTC M1Cont, M2Cont;
extern S_THT M1Theta_Sens, M2Theta_Sens;
extern S_SPD M1Speed_Sens;
extern float M1RPM_ref;
extern S_FTP M1Ip, M2Ip;
extern S_FDQ M1Ie_ref, M1Ie, M2Ie_ref, M2Ie;
extern S_FTP M1Vp_ref, M2Vp_ref;

void DAC(void)
{
	switch (da_sel) {
	case 1:	da1.out = &M1Vp_ref.a;			da1.rng = da_rng;		da1.mid = 0.0F;		da1.type = 0U;
			da2.out = &M1Vp_ref.b;			da2.rng = da_rng;		da2.mid = 0.0F;		da2.type = 0U;
			da3.out = &M1Vp_ref.c;			da3.rng = da_rng;		da3.mid = 0.0F;		da3.type = 0U;
			da4.out = &M1Cont.VF_V.Theta;	da4.rng = 7.0F;			da4.mid = 0.0F;		da4.type = 0U;		da_sel = 0U;	break;
	case 2:	da1.out = &M1Ip.a;				da1.rng = da_rng;		da1.mid = 0.0F;		da1.type = 0U;
			da2.out = &M1Ip.b;				da2.rng = da_rng;		da2.mid = 0.0F;		da2.type = 0U;
			da3.out = &M1Ip.c;				da3.rng = da_rng;		da3.mid = 0.0F;		da3.type = 0U;
			da4.out = &M1Cont.VF_V.Theta;	da4.rng = 7.0F;			da4.mid = 0.0F;		da4.type = 0U;		da_sel = 0U;	break;
	case 3:	da1.out = &M1Ip.a;				da1.rng = da_rng;		da1.mid = 0.0F;		da1.type = 0U;
			da2.out = &M1Ip.b;				da2.rng = da_rng;		da2.mid = 0.0F;		da2.type = 0U;
			da3.out = &M1Theta_Sens.e_now;	da3.rng = 7.0F;			da3.mid = 0.0F;		da3.type = 0U;
			da4.out = &M1Cont.VF_V.Theta;	da4.rng = 7.0F;			da4.mid = 0.0F;		da4.type = 0U;		da_sel = 0U;	break;
	case 4:	da1.out = &M1Ie.d;				da1.rng = da_rng;		da1.mid = 0.0F;		da1.type = 0U;
			da2.out = &M1Ie_ref.d;			da2.rng = da_rng;		da2.mid = 0.0F;		da2.type = 0U;
			da3.out = &M1Ie.q;				da3.rng = da_rng;		da3.mid = 0.0F;		da3.type = 0U;
			da4.out = &M1Ie_ref.q;			da4.rng = da_rng;		da4.mid = 0.0F;		da4.type = 0U;		da_sel = 0U;	break;
	case 5:	da1.out = &M1Speed_Sens.RPM.low;da1.rng = da_rng;		da1.mid = 0.0F;		da1.type = 0U;
			da2.out = &M1RPM_ref;			da2.rng = da_rng;		da2.mid = 0.0F;		da2.type = 0U;
			da3.out = &M1Ie.q;				da3.rng = 25.0F;		da3.mid = 0.0F;		da3.type = 0U;
			da4.out = &M1Ie_ref.q;			da4.rng = 25.0F;		da4.mid = 0.0F;		da4.type = 0U;		da_sel = 0U;	break;

	case 11:da1.out = &M2Vp_ref.a;			da1.rng = da_rng;		da1.mid = 0.0F;		da1.type = 0U;
			da2.out = &M2Vp_ref.b;			da2.rng = da_rng;		da2.mid = 0.0F;		da2.type = 0U;
			da3.out = &M2Vp_ref.c;			da3.rng = da_rng;		da3.mid = 0.0F;		da3.type = 0U;
			da4.out = &M2Cont.VF_V.Theta;	da4.rng = 7.0F;			da4.mid = 0.0F;		da4.type = 0U;		da_sel = 0U;	break;
	case 12:da1.out = &M2Ip.a;				da1.rng = da_rng;		da1.mid = 0.0F;		da1.type = 0U;
			da2.out = &M2Ip.b;				da2.rng = da_rng;		da2.mid = 0.0F;		da2.type = 0U;
			da3.out = &M2Ip.c;				da3.rng = da_rng;		da3.mid = 0.0F;		da3.type = 0U;
			da4.out = &M2Cont.VF_V.Theta;	da4.rng = 7.0F;			da4.mid = 0.0F;		da4.type = 0U;		da_sel = 0U;	break;
	case 13:da1.out = &M2Ip.a;				da1.rng = da_rng;		da1.mid = 0.0F;		da1.type = 0U;
			da2.out = &M2Ip.b;				da2.rng = da_rng;		da2.mid = 0.0F;		da2.type = 0U;
			da3.out = &M2Theta_Sens.e_now;	da3.rng = 7.0F;			da3.mid = 0.0F;		da3.type = 0U;
			da4.out = &M2Cont.VF_V.Theta;	da4.rng = 7.0F;			da4.mid = 0.0F;		da4.type = 0U;		da_sel = 0U;	break;
	case 14:da1.out = &M2Ie.d;				da1.rng = da_rng;		da1.mid = 0.0F;		da1.type = 0U;
			da2.out = &M2Ie_ref.d;			da2.rng = da_rng;		da2.mid = 0.0F;		da2.type = 0U;
			da3.out = &M2Ie.q;				da3.rng = da_rng;		da3.mid = 0.0F;		da3.type = 0U;
			da4.out = &M2Ie_ref.q;			da4.rng = da_rng;		da4.mid = 0.0F;		da4.type = 0U;		da_sel = 0U;	break;
	}

	dac_temp[0][0] = 0x0000 | ((Uint16)(((DA(1) - da1.mid) * da1_invrng * DAC_RNG) + DAC_MID) & DAC_EFF);
	dac_temp[0][1] = 0x4000 | ((Uint16)(((DA(2) - da2.mid) * da2_invrng * DAC_RNG) + DAC_MID) & DAC_EFF);
	dac_temp[0][2] = 0x8000 | ((Uint16)(((DA(3) - da3.mid) * da3_invrng * DAC_RNG) + DAC_MID) & DAC_EFF);
	dac_temp[0][3] = 0xC000 | ((Uint16)(((DA(4) - da4.mid) * da4_invrng * DAC_RNG) + DAC_MID) & DAC_EFF);
}
#endif
