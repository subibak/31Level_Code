/*
 * eQEP.c
 *
 *  Created on: 2012. 8. 18.
 *      Author: HJHeo
 */

#include "Define_Header.h"
#include "Define_eQEP.h"

#define ENC_PPR						14400
#define INV_ENC_PPR					6.9444444444e-5L

// Parameter
float Pole_Pairs = 3;

// Position
float pst_data = 0, pst_data_old = 0;
float theta_m = 0, theta_e = 0;

// Speed
Uint16 dir_data = 0;
float m_data = 0;
float rpm_m = 0, rpm_m_low = 0, rpm_m_old = 0;
float Wm_low = 0, We_low = 0;

void Init_QEP(void)
{
	//-------------------------------------------------------------------------------------------------//
	//-----------------------------------------eQEP3 [Encoder]-----------------------------------------//
	//-------------------------------------------------------------------------------------------------//
	// Emulation Mode
	EQep3Regs.QEPCTL.bit.FREE_SOFT = EMUMODE_FREE;

	// Signal Modify
	EQep3Regs.QDECCTL.bit.QAP = EQEPNX_NORMAL;
	EQep3Regs.QDECCTL.bit.QBP = EQEPNX_NORMAL;
	EQep3Regs.QDECCTL.bit.QIP = EQEPNX_NORMAL;
	EQep3Regs.QDECCTL.bit.SWAP = EQEPAB_SWAPPED;

	// Position Counter
	EQep3Regs.QDECCTL.bit.QSRC = PST_QUAD;				// Quadrature Mode
	EQep3Regs.QEPCTL.bit.PCRM = PST_RESET_INDEX;		// Cleared by Index Event
	EQep3Regs.QPOSMAX = (ENC_PPR-1);					// PPR : 14400
	EQep3Regs.QEPCTL.bit.QPEN = PST_ENABLE;				// Position Counter Enable

	// Unit Timer
	EQep3Regs.QEPCTL.bit.UTE = UNIT_DISABLE;			// Unit Timer Enable.

	// Capture Unit
	EQep3Regs.QCAPCTL.bit.CEN = CAPT_DISABLE;			// Capture Unit Disable.

	// QEPn Position Compare
	EQep3Regs.QPOSCTL.bit.PCE = COMP_DISABLE;			// Compare Unit Disable.

	// QEPn Watch dog
	EQep3Regs.QEPCTL.bit.WDE = WATCH_DISABLE;			// QEP3 Watch Dog Disable.

	// Synchronization
	EQep3Regs.QDECCTL.bit.SOEN = SYNCH_DISABLE;			// Synch Out Disable.

	return;
}


void Position(void)
{
	float PST_temp = 0;

	pst_data = (float)EQep3Regs.QPOSCNT;

	PST_temp = pst_data * INV_ENC_PPR;
	theta_m = PI2 * PST_temp;

	PST_temp *= Pole_Pairs;
	theta_e = PI2 * (PST_temp - (float)((int)PST_temp));

	return;
}

void M_Method(void)
{
	if (Flag_Out_Loop)
	{
		// M data sampling
		m_data = pst_data - pst_data_old;
		pst_data_old = pst_data;

		// Direction data sampling
		dir_data = (Uint16)EQep3Regs.QEPSTS.bit.QDF;

		// Speed Calculation
		if ((dir_data == 0x1) && (m_data < 0))
			rpm_m = (m_data + ENC_PPR) * INV_ENC_PPR * INV_OUTERLOOP_SAMPLING_TIME * 60;
		else if ((dir_data == 0x0) && (m_data > 0))
			rpm_m = (m_data - ENC_PPR) * INV_ENC_PPR * INV_OUTERLOOP_SAMPLING_TIME * 60;
		else
			rpm_m = m_data * INV_ENC_PPR * INV_OUTERLOOP_SAMPLING_TIME * 60;

		// LPF
		rpm_m_low = La_rpm * rpm_m_low + Lb_rpm * (rpm_m + rpm_m_old);
		rpm_m_old = rpm_m;

		// Additional Calculation
		Wm_low = rpm_m_low * PI2 * INV_60;
		We_low = Wm_low * Pole_Pairs;
	}

	return;
}

