// Slave ADC

#include "Define_Header.h"
#include "Define_ePWM.h"

#define OFFSET_COUNT			10000
#define INV_OFFSET_COUNT		1.e-4F
#define ADC_RESOLUTION			4.8828125e-4F

// ADC 12채널 할당
int AIN_CH1 = 0, AIN_CH2 = 0, AIN_CH3 = 0, AIN_CH4 = 0;
int AIN_CH5 = 0, AIN_CH6 = 0, AIN_CH7 = 0, AIN_CH8 = 0;
int AIN_CH9 = 0, AIN_CH10 = 0, AIN_CH11 = 0,  AIN_CH12 = 0;
int AIN_CH13 = 0, AIN_CH14 = 0, AIN_CH15 = 0, AIN_CH16 = 0;
int AIN_CH17 = 0, AIN_CH18 = 0, AIN_CH19 = 0, AIN_CH20 = 0;
int AIN_CH21 = 0, AIN_CH22 = 0, AIN_CH23 = 0, AIN_CH24 = 0;
int AIN_CH25 = 0, AIN_CH26 = 0, AIN_CH27 = 0, AIN_CH28 = 0;
int AIN_CH29 = 0, AIN_CH30 = 0, AIN_CH31 = 0, AIN_CH32 = 0;
int AIN_CH33 = 0, AIN_CH34 = 0, AIN_CH35 = 0, AIN_CH36 = 0;
int AIN_CH37 = 0, AIN_CH38 = 0, AIN_CH39 = 0, AIN_CH40 = 0;
int AIN_CH41 = 0, AIN_CH42 = 0, AIN_CH43 = 0, AIN_CH44 = 0;

//float Sub_Voltage_Sensor=0;

float I_Upper_offset = 0, I_Lower_offset = 0;
float offset_sum_A = 0, offset_sum_B = 0, offset_sum_C = 0, offset_sum_D = 0;
float offset_sum_E = 0, offset_sum_F = 0, offset_sum_G = 0, offset_sum_H = 0;
float offset_sum_I = 0, offset_sum_J = 0;


float offset_sum_au0=0, offset_sum_au1=0, offset_sum_au2=0, offset_sum_au3=0;
float offset_sum_al0=0, offset_sum_al1=0, offset_sum_al2=0, offset_sum_al3=0;
float offset_sum_bu0=0, offset_sum_bu1=0, offset_sum_bu2=0, offset_sum_bu3=0;
float offset_sum_bl0=0, offset_sum_bl1=0, offset_sum_bl2=0, offset_sum_bl3=0;
float offset_sum_cu0=0, offset_sum_cu1=0, offset_sum_cu2=0, offset_sum_cu3=0;
float offset_sum_cl0=0, offset_sum_cl1=0, offset_sum_cl2=0, offset_sum_cl3=0;
float offset_sum_Vdc=0, offset_sum_Vrs=0, offset_sum_Vst=0, offset_sum_Vtr=0;


// ADC CS 신호 할당
void Init_ADC(void)
{
	*ADC_ALL_CS_ON_ADDR = 0X0;
	DELAY_US(1);
	*ADC_ALL_WR_ADDR = 0xf;
	*ADC_ALL_CS_OFF_ADDR = 0x0;

    *ADC_ALL_CS2_ON_ADDR = 0X0;
    DELAY_US(1);
    *ADC_ALL_WR_ADDR = 0xf;
    *ADC_ALL_CS2_OFF_ADDR = 0x0;

    *ADC_ALL_CS3_ON_ADDR = 0X0;
    DELAY_US(1);
    *ADC_ALL_WR_ADDR = 0xf;
    *ADC_ALL_CS3_OFF_ADDR = 0x0;
	return;
}

// ADC 변환 신호 할당
void ADC(void)
{
	// Conversion Start
	// Master

	*ADC_ALL_CV_ON_ADDR = 0X0;
	*ADC_ALL_CV2_ON_ADDR = 0X0;
	*ADC_ALL_CV3_ON_ADDR = 0X0;

	DELAY_US(0.05);

	*ADC_ALL_CV_OFFADDR = 0X0;
	*ADC_ALL_CV2_OFFADDR = 0X0;
	*ADC_ALL_CV3_OFFADDR = 0X0;
	return;
}

// ADC 변환 데이터 불러오기
void ADC_Read(void)
{
		*ADC_ALL_CS_ON_ADDR = 0x0;			// ADC1 Chip Selection.

		// 1번째 모듈
		DELAY_US(0.05);
		AIN_CH1 = *ADC_A_RD_ADDR;		// ADC1 Data1 Read.

		DELAY_US(0.05);
		AIN_CH2 = *ADC_A_RD_ADDR;		// ADC1 Data2 Read.

		DELAY_US(0.05);
		AIN_CH3 = *ADC_A_RD_ADDR;		// ADC1 Data3 Read.

		DELAY_US(0.05);
		AIN_CH4 = *ADC_A_RD_ADDR;		// ADC1 Data4 Read.

		// 2번째 모듈
		DELAY_US(0.05);
		AIN_CH5 = *ADC_B_RD_ADDR;       // ADC2 Data1 Read.

		DELAY_US(0.05);
		AIN_CH6 = *ADC_B_RD_ADDR;       // ADC2 Data2 Read.

		DELAY_US(0.05);
		AIN_CH7 = *ADC_B_RD_ADDR;       // ADC2 Data3 Read.

		DELAY_US(0.05);
		AIN_CH8 = *ADC_B_RD_ADDR;       // ADC2 Data4 Read.

		// 3번째 모듈 C Upper
		DELAY_US(0.05);
		AIN_CH9 = *ADC_C_RD_ADDR;       // ADC3 Data1 Read.

		DELAY_US(0.05);
		AIN_CH10 = *ADC_C_RD_ADDR;      // ADC3 Data2 Read.

		DELAY_US(0.05);
		AIN_CH11 = *ADC_C_RD_ADDR;      // ADC3 Data3 Read.

		DELAY_US(0.05);
		AIN_CH12 = *ADC_C_RD_ADDR;      // ADC3 Data4 Read.

		*ADC_ALL_CS_OFF_ADDR = 0x0;          // ADC1 Chip Selection.

		DELAY_US(0.05);

		*ADC_ALL_CS2_ON_ADDR = 0x0;          // ADC1 Chip Selection.

		// ADC_4
		DELAY_US(0.05);
		AIN_CH13 = *ADC_D_RD_ADDR;       // ADC3 Data1 Read.
		DELAY_US(0.05);
		AIN_CH14 = *ADC_D_RD_ADDR;      // ADC3 Data2 Read.

		DELAY_US(0.05);
		AIN_CH15 = *ADC_D_RD_ADDR;      // ADC3 Data3 Read.

		DELAY_US(0.05);
		AIN_CH16 = *ADC_D_RD_ADDR;      // ADC3 Data4 Read.


		// ADC_5
		DELAY_US(0.05);
		AIN_CH17 = *ADC_E_RD_ADDR;       // ADC3 Data1 Read.

		DELAY_US(0.05);
		AIN_CH18 = *ADC_E_RD_ADDR;      // ADC3 Data2 Read.

		DELAY_US(0.05);
		AIN_CH19 = *ADC_E_RD_ADDR;      // ADC3 Data3 Read.

		DELAY_US(0.05);
		AIN_CH20 = *ADC_E_RD_ADDR;      // ADC3 Data4 Read.

	// ADC_6  C_upper
		DELAY_US(0.05);
		AIN_CH21 = *ADC_F_RD_ADDR;       // ADC3 Data1 Read.

		DELAY_US(0.05);
		AIN_CH22 = *ADC_F_RD_ADDR;      // ADC3 Data2 Read.

		DELAY_US(0.05);
		AIN_CH23 = *ADC_F_RD_ADDR;      // ADC3 Data3 Read.

		DELAY_US(0.05);
		AIN_CH24 = *ADC_F_RD_ADDR;      // ADC3 Data4 Read.

		*ADC_ALL_CS2_OFF_ADDR = 0x0;          // ADC1 Chip Selection.

		DELAY_US(0.05);

		*ADC_ALL_CS3_ON_ADDR = 0x0;          // ADC1 Chip Selection.

		// ADC_7
		DELAY_US(0.05);
		AIN_CH25 = *ADC_G_RD_ADDR;       // ADC3 Data1 Read.

		DELAY_US(0.05);
		AIN_CH26 = *ADC_G_RD_ADDR;      // ADC3 Data2 Read.

		DELAY_US(0.05);
		AIN_CH27 = *ADC_G_RD_ADDR;      // ADC3 Data3 Read.

		DELAY_US(0.05);
		AIN_CH28 = *ADC_G_RD_ADDR;      // ADC3 Data4 Read.

		//ADC_8
		DELAY_US(0.05);
		AIN_CH29 = *ADC_H_RD_ADDR;       // ADC3 Data1 Read.

		DELAY_US(0.05);
		AIN_CH30 = *ADC_H_RD_ADDR;      // ADC3 Data2 Read.

		DELAY_US(0.05);
		AIN_CH31 = *ADC_H_RD_ADDR;      // ADC3 Data3 Read.

		DELAY_US(0.05);
		AIN_CH32 = *ADC_H_RD_ADDR;      // ADC3 Data4 Read.

		// ADC_9
		DELAY_US(0.05);
		AIN_CH33 = *ADC_I_RD_ADDR;       // ADC3 Data1 Read.

		DELAY_US(0.05);
		AIN_CH34 = *ADC_I_RD_ADDR;      // ADC3 Data2 Read.

		DELAY_US(0.05);
		AIN_CH35 = *ADC_I_RD_ADDR;      // ADC3 Data3 Read.

		DELAY_US(0.05);
		AIN_CH36 = *ADC_I_RD_ADDR;      // ADC3 Data4 Read.

		// ADC_10
		DELAY_US(0.05);
		AIN_CH37 = *ADC_J_RD_ADDR;       // ADC3 Data1 Read.

		DELAY_US(0.05);
		AIN_CH38 = *ADC_J_RD_ADDR;      // ADC3 Data2 Read.

		DELAY_US(0.05);
		AIN_CH39 = *ADC_J_RD_ADDR;      // ADC3 Data3 Read.

		DELAY_US(0.05);
		AIN_CH40 = *ADC_J_RD_ADDR;      // ADC3 Data4 Read.

		// ADC_11
		DELAY_US(0.05);
		AIN_CH41 = *ADC_K_RD_ADDR;       // ADC3 Data1 Read.

		DELAY_US(0.05);
		AIN_CH42 = *ADC_K_RD_ADDR;      // ADC3 Data2 Read.

		DELAY_US(0.05);
		AIN_CH43 = *ADC_K_RD_ADDR;      // ADC3 Data3 Read.

		DELAY_US(0.05);
		AIN_CH44 = *ADC_K_RD_ADDR;      // ADC3 Data4 Read.

		*ADC_ALL_CS3_OFF_ADDR = 0x0;
		return;


}

interrupt void ADC_Offset(void)
{
	static int offset_cnt = 0;

	ADC();
	DELAY_US(7);
	ADC_Read();

	// 전류 측정
	Current_Sensor();
	// 전압 측정
	Voltage_Sensor();

	offset_sum_I += I_au;
	offset_sum_J += I_al;

	offset_sum_A += I_bu;
	offset_sum_B += I_bl;

	offset_sum_C += I_cu;
	offset_sum_D += I_cl;

	offset_sum_E += I_as;
	offset_sum_F += I_bs;
	offset_sum_G += I_cs;
	//offset_sum_H += Idc_sensor;



	//offset_sum_au0 += Va_SM_U[0];
	//offset_sum_au1 += Va_SM_U[1];
	//offset_sum_au2 += Va_SM_U[2];
	//offset_sum_au3 += Va_SM_U[3];

	//offset_sum_al0 += Va_SM_L[0];
	//offset_sum_al1 += Va_SM_L[1];
	//offset_sum_al2 += Va_SM_L[2];
	//offset_sum_al3 += Va_SM_L[3];

	//offset_sum_bu0 += Vb_SM_U[0];
	//offset_sum_bu1 += Vb_SM_U[1];
	//offset_sum_bu2 += Vb_SM_U[2];
	//offset_sum_bu3 += Vb_SM_U[3];

	//offset_sum_bl0 += Vb_SM_L[0];
	//offset_sum_bl1 += Vb_SM_L[1];
	//offset_sum_bl2 += Vb_SM_L[2];
	//offset_sum_bl3 += Vb_SM_L[3];

	//offset_sum_cu0 += Vc_SM_U[0];
	//offset_sum_cu1 += Vc_SM_U[1];
	//offset_sum_cu2 += Vc_SM_U[2];
	//offset_sum_cu3 += Vc_SM_U[3];

	//offset_sum_cl0 += Vc_SM_L[0];
	//offset_sum_cl1 += Vc_SM_L[1];
	//offset_sum_cl2 += Vc_SM_L[2];
	//offset_sum_cl3 += Vc_SM_L[3];

	/*
	offset_sum_au[4] += Va_SM_U[4];
	offset_sum_al[4] += Va_SM_L[4];
	offset_sum_bu[4] += Vb_SM_U[4];
	offset_sum_bl[4] += Vb_SM_L[4];
	offset_sum_cu[4] += Vc_SM_U[4];
	offset_sum_cl[4] += Vc_SM_L[4];
*/

	//offset_sum_Vdc += Vdc_sensor;
	offset_sum_Vrs += V_RS;
	offset_sum_Vst += V_ST;
	offset_sum_Vtr += V_TR;

	if (offset_cnt++ >= OFFSET_COUNT)
	{
		I_au_offset = offset_sum_I * INV_OFFSET_COUNT;
		I_al_offset = offset_sum_J * INV_OFFSET_COUNT;

		I_bu_offset = offset_sum_A * INV_OFFSET_COUNT;
		I_bl_offset = offset_sum_B * INV_OFFSET_COUNT;

		I_cu_offset = offset_sum_C * INV_OFFSET_COUNT;
	    I_cl_offset = offset_sum_D * INV_OFFSET_COUNT;

	    I_as_offset = offset_sum_E * INV_OFFSET_COUNT;
	    I_bs_offset = offset_sum_F * INV_OFFSET_COUNT;
	    I_cs_offset = offset_sum_G * INV_OFFSET_COUNT;
	    //I_dc_offset = offset_sum_H * INV_OFFSET_COUNT;
/*
	    Va_SM_U_offset[4] = offset_sum_au[4] * INV_OFFSET_COUNT;
	    Va_SM_L_offset[4] = offset_sum_al[4] * INV_OFFSET_COUNT;
	    Vb_SM_U_offset[4] = offset_sum_bu[4] * INV_OFFSET_COUNT;
	    Vb_SM_L_offset[4] = offset_sum_bl[4] * INV_OFFSET_COUNT;
	    Vc_SM_U_offset[4] = offset_sum_cu[4] * INV_OFFSET_COUNT;
	    Vc_SM_L_offset[4] = offset_sum_cl[4] * INV_OFFSET_COUNT;

*/

	   // Va_SM_U_offset0 = offset_sum_au0 * INV_OFFSET_COUNT;
	    //Va_SM_U_offset1 = offset_sum_au1 * INV_OFFSET_COUNT;
	    //Va_SM_U_offset2 = offset_sum_au2 * INV_OFFSET_COUNT;
	    //Va_SM_U_offset3 = offset_sum_au3 * INV_OFFSET_COUNT;

	    //Va_SM_L_offset0 = offset_sum_al0 * INV_OFFSET_COUNT;
	    //Va_SM_L_offset1 = offset_sum_al1 * INV_OFFSET_COUNT;
	    //Va_SM_L_offset2 = offset_sum_al2 * INV_OFFSET_COUNT;
	    //Va_SM_L_offset3 = offset_sum_al3 * INV_OFFSET_COUNT;

	    //Vb_SM_U_offset0 = offset_sum_bu0 * INV_OFFSET_COUNT;
	    //Vb_SM_U_offset1 = offset_sum_bu1 * INV_OFFSET_COUNT;
	    //Vb_SM_U_offset2 = offset_sum_bu2 * INV_OFFSET_COUNT;
	    //Vb_SM_U_offset3 = offset_sum_bu3 * INV_OFFSET_COUNT;

	    //Vb_SM_L_offset0 = offset_sum_bl0 * INV_OFFSET_COUNT;
	    //Vb_SM_L_offset1 = offset_sum_bl1 * INV_OFFSET_COUNT;
	    //Vb_SM_L_offset2 = offset_sum_bl2 * INV_OFFSET_COUNT;
	    //Vb_SM_L_offset3 = offset_sum_bl3 * INV_OFFSET_COUNT;

	    //Vc_SM_U_offset0 = offset_sum_cl0 * INV_OFFSET_COUNT;
	    //Vc_SM_U_offset1 = offset_sum_cl1 * INV_OFFSET_COUNT;
	    //Vc_SM_U_offset2 = offset_sum_cl2 * INV_OFFSET_COUNT;
	   // Vc_SM_U_offset3 = offset_sum_cl3 * INV_OFFSET_COUNT;

	   // Vc_SM_L_offset0 = offset_sum_cu0 * INV_OFFSET_COUNT;
	    //Vc_SM_L_offset1 = offset_sum_cu1 * INV_OFFSET_COUNT;
	   // Vc_SM_L_offset2 = offset_sum_cu2 * INV_OFFSET_COUNT;
	   // Vc_SM_L_offset3 = offset_sum_cu3 * INV_OFFSET_COUNT;

	   // Vdc_offset = offset_sum_Vdc * INV_OFFSET_COUNT;
	    V_RS_offset = offset_sum_Vrs * INV_OFFSET_COUNT;
	    V_ST_offset = offset_sum_Vst * INV_OFFSET_COUNT;
	    V_TR_offset = offset_sum_Vtr * INV_OFFSET_COUNT;

		EALLOW;
		PieVectTable.EPWM1_INT = &Interrupt;
		EDIS;
	}

	// Master 측과의 동기화를 위한 인터럽트 처리 방식

	EPwm1Regs.ETCLR.bit.INT = 1;			// ePWM1 Interrupt Clear
	PieCtrlRegs.PIEACK.all = PIEACK_GROUP3;	// ePWM1 PIE Interrupt Clear
}
