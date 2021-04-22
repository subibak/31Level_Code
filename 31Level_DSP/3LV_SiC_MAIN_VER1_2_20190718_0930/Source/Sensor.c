/*
 * Sensor.c
 *
 *  Created on: 2019. 6. 26.
 *      Author: HJHeo
 */

#include "Define_Header.h"
#include "Define_Sensor.h"

#ifdef CPU1
// Predefine
//// Predefine : ADC Spec.
#define ADC_OFFSET							2048

//// Predefine : Current Sensor Spec.
#define NUM_IA_MAX_DEN_ADC_RES				-0.0244140625F
#define NUM_IB_MAX_DEN_ADC_RES				-0.0244140625F
#define NUM_IC_MAX_DEN_ADC_RES				-0.0244140625F

//// Predefine : Voltage Sensor Spec.
//#define NUM_VP_MAX_DEN_ADC_RES				0.48828125F
#define NUM_VP_MAX_DEN_ADC_RES				0.50080128205128205128205128205128F
//#define NUM_VN_MAX_DEN_ADC_RES				0.48828125F
#define NUM_VN_MAX_DEN_ADC_RES				0.50646328181723887563530754071154F

//// Predefine : Control Value
#define MxIp								M1Ip
#define MxIp_offset							M1Ip_offset

// External Value
extern S_FTP M1Ip, M1Ip_offset;
#endif

#ifdef CPU2
// Predefine
//// Predefine : ADC Spec.
#define ADC_OFFSET							2048

//// Predefine : Current Sensor Spec.
#define NUM_IA_MAX_DEN_ADC_RES				-0.0244140625F
#define NUM_IB_MAX_DEN_ADC_RES				-0.0244140625F
#define NUM_IC_MAX_DEN_ADC_RES				-0.0244140625F

//// Predefine : Voltage Sensor Spec.
//#define NUM_VP_MAX_DEN_ADC_RES				0.48828125F
#define NUM_VP_MAX_DEN_ADC_RES				0.50437067451709534139035223633922F
//#define NUM_VN_MAX_DEN_ADC_RES				0.48828125F
#define NUM_VN_MAX_DEN_ADC_RES				0.50510111720285507396296679424847F

//// Predefine : Control Value
#define MxIp								M2Ip
#define MxIp_offset							M2Ip_offset

// External Value
extern S_FTP M2Ip, M2Ip_offset;
#endif

// Variables
#if ((defined(CPU1) && !CPU2_BOOT_ENABLE) || defined(CPU2))
	#ifdef CPU1
	#pragma DATA_SECTION(Vdc, 				"M1VdcFile");
	#endif
	#ifdef CPU2
	#pragma DATA_SECTION(Vdc, 				"M2VdcFile");
	#endif
S_VDC Vdc = {{0.0F, 0.0F},												// Vdc = {dc.	{low, INV_low},
			 {0.0F},													//		  diff.	{low},
#ifdef CPU1
			 {0.0F, 0.0F, 0.0F, 0.0F, 3.645F, 0.0F, 0.0F},				//		  p.	{now, old, low, INV_low, offset, La, Lb},
			 {0.0F, 0.0F, 0.0F, 0.0F, 3.052F, 0.0F, 0.0F},				//		  n.	{now, old, low, INV_low, offset, La, Lb},
#endif
#ifdef CPU2
			 {0.0F, 0.0F, 0.0F, 0.0F, 2.7712F, 0.0F, 0.0F},				//		  p.	{now, old, low, INV_low, offset, La, Lb},
			 {0.0F, 0.0F, 0.0F, 0.0F, 3.1353F, 0.0F, 0.0F},				//		  n.	{now, old, low, INV_low, offset, La, Lb},
#endif
			 {0U, {50.0F, 50.0F}}};										//		  IMG.	{Flag, Value.{p, n}}}
#else
#pragma DATA_SECTION(Vdc,					"M2VdcFile");
S_VDC Vdc;
#endif

#if ((defined(CPU1) && !CPU2_BOOT_ENABLE) || defined(CPU2))
void Vdc_Sensor(Uint16 VP_ADC_RST, Uint16 VN_ADC_RST)
{
	// Selection DC Voltage Between Image and Real Voltage Value.
	if (Vdc.IMG.Flag == 1U) {
		Vdc.p.now = Vdc.IMG.Value.p;
		Vdc.n.now = Vdc.IMG.Value.n;
	// Vdc Voltage Data Conversion.
	} else {
		Vdc.p.now = LO_BOUND((float)((int16)VP_ADC_RST - ADC_OFFSET) * NUM_VP_MAX_DEN_ADC_RES - Vdc.p.offset, 0.0F);
		Vdc.n.now = LO_BOUND((float)((int16)VN_ADC_RST - ADC_OFFSET) * NUM_VN_MAX_DEN_ADC_RES - Vdc.n.offset, 0.0F);
	}

	// Low Pass Filter for DC-Link Voltage.
	LPF(Vdc.p);
	LPF(Vdc.n);

	// Diff & Sum Voltage.
	Vdc.dc.low = Vdc.p.low + Vdc.n.low;
	Vdc.diff.low = Vdc.p.low - Vdc.n.low;

	// Inverse Value of DC-Link Voltage.
	Vdc.dc.INV_low = DIVF32(1.0F, Vdc.dc.low);
	Vdc.p.INV_low = DIVF32(1.0F, Vdc.p.low);
	Vdc.n.INV_low = DIVF32(1.0F, Vdc.n.low);

	return;
}
#endif

void Current_Sensor(Uint16 IA_ADC_RST, Uint16 IB_ADC_RST, Uint16 IC_ADC_RST)
{
	MxIp.a = (float)((int16)IA_ADC_RST - ADC_OFFSET) * NUM_IA_MAX_DEN_ADC_RES - MxIp_offset.a;
	MxIp.b = (float)((int16)IB_ADC_RST - ADC_OFFSET) * NUM_IB_MAX_DEN_ADC_RES - MxIp_offset.b;
	MxIp.c = (float)((int16)IC_ADC_RST - ADC_OFFSET) * NUM_IC_MAX_DEN_ADC_RES - MxIp_offset.c;

	return;
}
