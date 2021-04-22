// Slave Sensor

#include "Define_Header.h"

#define ADC7864						TARGET

#if (ADC7864)
	#define ADC_RESOLUTION			4.8828125e-4F
#endif

#define Vsub_MAX				43//211
#define Vdc_MAX                 150
#define VArm_MAX                200//410
#define I_Upper_MAX				10//50
#define I_Lower_MAX				10//50
#define V_Line_MAX				310
#define I_MAX                   100
#define I_DC_MAX             	150/4

float V_Line_MAX1  = 315;
float Va_SM_U[4] = {0, 0, 0, 0};
float Va_SM_L[4] = {0, 0, 0, 0};
float Vb_SM_U[4] = {0, 0, 0, 0};
float Vb_SM_L[4] = {0, 0, 0, 0};
float Vc_SM_U[4] = {0, 0, 0, 0};
float Vc_SM_L[4] = {0, 0, 0, 0};
float Vdc_sensor = 0;
float Vdc_low = 0, Vdc_old = 0, Twc_Vdc = 0.1;
float VArm_upper=0, VArm_lower=0;
float Vdc =0, Vdc_test=100;
float Inv_Vdc = 0;
float I_au = 0, I_al = 0, I_bu = 0, I_bl = 0, I_cu = 0,I_cl = 0,I_ao = 0, I_bo = 0, I_co = 0, I_as = 0, I_bs = 0, I_cs = 0;
float V_RS = 0, V_ST = 0, V_TR = 0;
float Er = 0, Es = 0, Et = 0;
float I_dc_offset = 0, I_as_offset = 0, I_bs_offset = 0, I_cs_offset = 0, I_au_offset = 0, I_al_offset = 0, I_bu_offset = 0, I_bl_offset = 0, I_cu_offset = 0, I_cl_offset = 0;
float Idc_sensor = 0, Idc_sensor_low =0;
float V_RS_offset =0, V_ST_offset =0, V_TR_offset =0;
float Vdc_offset=0;
float I_rs = 0, I_ss = 0, I_ts = 0;

float Va_SM_U_offset0=0, Va_SM_U_offset1=0, Va_SM_U_offset2=0, Va_SM_U_offset3=0;
float Va_SM_L_offset0=0, Va_SM_L_offset1=0, Va_SM_L_offset2=0, Va_SM_L_offset3=0;
float Vb_SM_U_offset0=0, Vb_SM_U_offset1=0, Vb_SM_U_offset2=0, Vb_SM_U_offset3=0;
float Vb_SM_L_offset0=0, Vb_SM_L_offset1=0, Vb_SM_L_offset2=0, Vb_SM_L_offset3=0;
float Vc_SM_U_offset0=0, Vc_SM_U_offset1=0, Vc_SM_U_offset2=0, Vc_SM_U_offset3=0;
float Vc_SM_L_offset0=0, Vc_SM_L_offset1=0, Vc_SM_L_offset2=0, Vc_SM_L_offset3=0;


float SM_aU_VOLTAGE_NEW[4] = {0, 0, 0, 0};
float SM_aL_VOLTAGE_NEW[4] = {0, 0, 0, 0};
float SM_bU_VOLTAGE_NEW[4] = {0, 0, 0, 0};
float SM_bL_VOLTAGE_NEW[4] = {0, 0, 0, 0};
float SM_cU_VOLTAGE_NEW[4] = {0, 0, 0, 0};
float SM_cL_VOLTAGE_NEW[4] = {0, 0, 0, 0};

int SM_aU_INDEX_NEW[4] = {1, 2, 3, 4};
int SM_aL_INDEX_NEW[4] = {1, 2, 3, 4};
int SM_bU_INDEX_NEW[4] = {1, 2, 3, 4};
int SM_bL_INDEX_NEW[4] = {1, 2, 3, 4};
int SM_cU_INDEX_NEW[4] = {1, 2, 3, 4};
int SM_cL_INDEX_NEW[4] = {1, 2, 3, 4};

int Upper_Arm_Cur_SignA = 0;
int Lower_Arm_Cur_SignA = 0;
int Upper_Arm_Cur_SignB = 0;
int Lower_Arm_Cur_SignB = 0;
int Upper_Arm_Cur_SignC = 0;
int Lower_Arm_Cur_SignC = 0;

int k = 0, i = 0, j = 0;

int U_voltage_temp_a=0,  L_voltage_temp_a =0,  U_voltage_temp_b =0,  L_voltage_temp_b =0,  U_voltage_temp_c =0,  L_voltage_temp_c =0;
float U_index_temp_a=0, L_index_temp_a=0, U_index_temp_b=0, L_index_temp_b=0, U_index_temp_c=0,L_index_temp_c=0;
Uint16 SM_aU_INDEX=0, SM_aL_INDEX=0, SM_bU_INDEX=0, SM_bL_INDEX=0, SM_cU_INDEX=0, SM_cL_INDEX=0;

int cur_dir_test = 0;

// 각 서브모듈 커패시터 전압 측정
void Voltage_Sensor(void)
{
	// 상단 서브모듈 1 ~ 4 전압 측정
		Va_SM_U[0] = (float)(AIN_CH1 << 4 >> 4) * ADC_RESOLUTION * Vsub_MAX;// - Va_SM_U_offset0;
		Va_SM_U[1] = (float)(AIN_CH2 << 4 >> 4) * ADC_RESOLUTION * Vsub_MAX;// - Va_SM_U_offset1;
		Va_SM_U[2] = (float)(AIN_CH3 << 4 >> 4) * ADC_RESOLUTION * Vsub_MAX;// - Va_SM_U_offset2;
		Va_SM_U[3] = (float)(AIN_CH4 << 4 >> 4) * ADC_RESOLUTION * Vsub_MAX;// - Va_SM_U_offset3;

		// 하단 서브모듈 1 ~ 4 전압 측정
		Va_SM_L[0] = (float)(AIN_CH13 << 4 >> 4) * ADC_RESOLUTION * Vsub_MAX;// - Va_SM_L_offset0;
		Va_SM_L[1] = (float)(AIN_CH14 << 4 >> 4) * ADC_RESOLUTION * Vsub_MAX;// - Va_SM_L_offset1;
		Va_SM_L[2] = (float)(AIN_CH15 << 4 >> 4) * ADC_RESOLUTION * Vsub_MAX;// - Va_SM_L_offset2;
		Va_SM_L[3] = (float)(AIN_CH16 << 4 >> 4) * ADC_RESOLUTION * Vsub_MAX;// - Va_SM_L_offset3;

		// phase-B
		Vb_SM_U[0] = (float)(AIN_CH5 << 4 >> 4) * ADC_RESOLUTION * Vsub_MAX;// - Vb_SM_U_offset0;
		Vb_SM_U[1] = (float)(AIN_CH6 << 4 >> 4) * ADC_RESOLUTION * Vsub_MAX;// - Vb_SM_U_offset1;
		Vb_SM_U[2] = (float)(AIN_CH7 << 4 >> 4) * ADC_RESOLUTION * Vsub_MAX;// - Vb_SM_U_offset2;
		Vb_SM_U[3] = (float)(AIN_CH8 << 4 >> 4) * ADC_RESOLUTION * Vsub_MAX;// - Vb_SM_U_offset3;

		// 하단 서브모듈 1 ~ 4 전압 측정
		Vb_SM_L[0] = (float)(AIN_CH17 << 4 >> 4) * ADC_RESOLUTION * Vsub_MAX;// - Vb_SM_L_offset0;
		Vb_SM_L[1] = (float)(AIN_CH18 << 4 >> 4) * ADC_RESOLUTION * Vsub_MAX;// - Vb_SM_L_offset1;
		Vb_SM_L[2] = (float)(AIN_CH19 << 4 >> 4) * ADC_RESOLUTION * Vsub_MAX;// - Vb_SM_L_offset2;
		Vb_SM_L[3] = (float)(AIN_CH20 << 4 >> 4) * ADC_RESOLUTION * Vsub_MAX;// - Vb_SM_L_offset3;

		//phase_C
		// 상단 서브모듈 1 ~ 4 전압 측정
		Vc_SM_U[0] = (float)(AIN_CH9  << 4 >> 4) * ADC_RESOLUTION * Vsub_MAX;// - Vc_SM_U_offset0;
		Vc_SM_U[1] = (float)(AIN_CH10 << 4 >> 4) * ADC_RESOLUTION * Vsub_MAX;// - Vc_SM_U_offset1;
		Vc_SM_U[2] = (float)(AIN_CH11 << 4 >> 4) * ADC_RESOLUTION * Vsub_MAX;// - Vc_SM_U_offset2;
		Vc_SM_U[3] = (float)(AIN_CH12 << 4 >> 4) * ADC_RESOLUTION * Vsub_MAX;// - Vc_SM_U_offset3;

		// 하단 서브모듈 1 ~ 4 전압 측정
		Vc_SM_L[0] = (float)(AIN_CH21 << 4 >> 4) * ADC_RESOLUTION * Vsub_MAX;// - Vc_SM_L_offset0;
		Vc_SM_L[1] = (float)(AIN_CH22 << 4 >> 4) * ADC_RESOLUTION * Vsub_MAX;// - Vc_SM_L_offset1;
		Vc_SM_L[2] = (float)(AIN_CH23 << 4 >> 4) * ADC_RESOLUTION * Vsub_MAX;// - Vc_SM_L_offset2;
		Vc_SM_L[3] = (float)(AIN_CH24 << 4 >> 4) * ADC_RESOLUTION * Vsub_MAX;// - Vc_SM_L_offset3;

		//Vdc
		Vdc_sensor= (float)(AIN_CH25 << 4 >> 4) * ADC_RESOLUTION * Vdc_MAX;

		Vdc_low = LPF1(Vdc_low, Vdc_sensor, Vdc_old, Twc_Vdc);

		// ADC Channel #26 ~ #28
		V_RS = (float)(AIN_CH39<< 4 >> 4) * ADC_RESOLUTION * V_Line_MAX - V_RS_offset;
		V_ST = (float)(AIN_CH41<< 4 >> 4) * ADC_RESOLUTION * V_Line_MAX- V_ST_offset;
		V_TR = (float)(AIN_CH40<< 4 >> 4) * ADC_RESOLUTION * V_Line_MAX- V_TR_offset;

		Er = (V_RS - V_TR) * INV_3;
		Es = (V_ST - V_RS) * INV_3;
		Et = (V_TR - V_ST) * INV_3;

		return ;
}


void Current_Sensor(void)

{
	//
	//Idc_sensor = (float)(AIN_CH42<< 4 >> 4) * ADC_RESOLUTION * I_DC_MAX- I_dc_offset;

	// ADC Channel #29 ~ #31
	I_as = (float)(AIN_CH26 << 4 >> 4) * ADC_RESOLUTION * I_MAX - I_as_offset;
	I_bs = (float)(AIN_CH27 << 4 >> 4) * ADC_RESOLUTION * I_MAX - I_bs_offset;
	I_cs = (float)(AIN_CH28 << 4 >> 4) * ADC_RESOLUTION * I_MAX - I_cs_offset;
	//I_cs = -(I_as + I_bs);

	I_rs = -I_as;
	I_ss = -I_bs;
	I_ts = -I_cs;

	// ADC Channel #9 ~ #12

		I_au =((float)(AIN_CH37 << 4 >> 4)* ADC_RESOLUTION * I_MAX) - I_au_offset;
		//I_au = I_au/(1 + Kcom1)
		I_al = ((float)(AIN_CH35 << 4 >> 4)* ADC_RESOLUTION * I_MAX) - I_al_offset;
		//I_al = I_al/(1 - Kcom1)

		I_bu = ((float)(AIN_CH38 << 4 >> 4) * ADC_RESOLUTION * I_MAX) - I_bu_offset;
		//I_bu = I_bu/(1 + Kcom2)
		I_bl = ((float)(AIN_CH34 << 4 >> 4)* ADC_RESOLUTION * I_MAX) - I_bl_offset;
		//I_bl = I_bl/(1 - Kcom2)

		I_cu = ((float)(AIN_CH36 << 4 >> 4) * ADC_RESOLUTION * I_MAX) - I_cu_offset;
		//I_cu = I_cu/(1 + Kcom3)
		I_cl = ((float)(AIN_CH33 << 4 >> 4)* ADC_RESOLUTION * I_MAX) - I_cl_offset;
		//I_cl = I_cl/(1 - Kcom3)

		I_ao = 0.5*(I_au + I_al);
		I_bo = 0.5*(I_bu + I_bl);
		I_co = 0.5*(I_cu + I_cl);

		Idc_sensor =I_ao + I_bo + I_co;
	//Idc_sensor_low = LPF(Idc_sensor_low, Idc_sensor, Tcl)
	//I_as_cal = I_au - I_al;
	//I_bs_cal = I_bu - I_bl;
	//I_cs_cal = I_cu - I_cl;
	return;
}

void Balance(void)

 {

	// Current Direction Decision
	// Positive Direction : 1
	// Negative Direction : 0
/*
	if (I_au >= 0 )
		Upper_Arm_Cur_SignA = 1;
	else if (I_au < 0)
		Upper_Arm_Cur_SignA = 0;

	if (I_al >= 0)
		Lower_Arm_Cur_SignA = 1;
	else if (I_al < 0)
		Lower_Arm_Cur_SignA = 0;

	if (I_bu >= 0 )
		Upper_Arm_Cur_SignB = 1;
	else if (I_bu < 0)
		Upper_Arm_Cur_SignB = 0;

	if (I_bl>= 0)
		Lower_Arm_Cur_SignB = 1;
	else if (I_bl < 0)
		Lower_Arm_Cur_SignB = 0;

	if (I_cu >= 0 )
		Upper_Arm_Cur_SignC = 1;
	else if (I_cu < 0)
		Upper_Arm_Cur_SignC = 0;

	if (I_cl>= 0)
		Lower_Arm_Cur_SignC = 1;
	else if (I_cl < 0)
		Lower_Arm_Cur_SignC = 0;

    *FPGA_Upper_Arm_Cur_SignA = Upper_Arm_Cur_SignA;
     DELAY_US(0.1);
    *FPGA_lower_Arm_Cur_SignA = Lower_Arm_Cur_SignA;

     DELAY_US(0.1);
    *FPGA_Upper_Arm_Cur_SignB = Upper_Arm_Cur_SignB;
     DELAY_US(0.1);
    *FPGA_lower_Arm_Cur_SignB = Lower_Arm_Cur_SignB;

     DELAY_US(0.1);
    *FPGA_Upper_Arm_Cur_SignC = Upper_Arm_Cur_SignC;
     DELAY_US(0.1);
    *FPGA_lower_Arm_Cur_SignC = Lower_Arm_Cur_SignC;
*/
	Bubble_sort();
  }


void Bubble_sort(void)
{
	// 5레벨의 경우 각 암의 서브모듈 개수는 총 4개 = NUM_SM
	for(k = 0; k < NUM_SM; k++)
	{
		SM_aU_VOLTAGE_NEW[k] = Va_SM_U[k];
		SM_aL_VOLTAGE_NEW[k] = Va_SM_L[k];
		SM_aU_INDEX_NEW[k] = k + 1;
		SM_aL_INDEX_NEW[k] = k + 1;

		SM_bU_VOLTAGE_NEW[k] = Vb_SM_U[k];
		SM_bL_VOLTAGE_NEW[k] = Vb_SM_L[k];
		SM_bU_INDEX_NEW[k] = k + 1;
		SM_bL_INDEX_NEW[k] = k + 1;

		SM_cU_VOLTAGE_NEW[k] = Vc_SM_U[k];
		SM_cL_VOLTAGE_NEW[k] = Vc_SM_L[k];
		SM_cU_INDEX_NEW[k] = k + 1;
		SM_cL_INDEX_NEW[k] = k + 1;
	}

	// 오름차순으로 각 암 서브모듈 전압 정보 재배치
	for(i = 0; i < NUM_SM - 1; i++)

	{
		for(j = 0; j < NUM_SM - 1 - i; j++)

		{

		//upper phase_a submodule sorting
			if(SM_aU_VOLTAGE_NEW[j] > SM_aU_VOLTAGE_NEW[j+1])

			{
				U_voltage_temp_a = SM_aU_VOLTAGE_NEW[j];
				SM_aU_VOLTAGE_NEW[j] =SM_aU_VOLTAGE_NEW[j+1];
				SM_aU_VOLTAGE_NEW[j+1] = U_voltage_temp_a;

				U_index_temp_a =  SM_aU_INDEX_NEW[j];
				SM_aU_INDEX_NEW[j] = SM_aU_INDEX_NEW[j+1];
				SM_aU_INDEX_NEW[j+1] = U_index_temp_a;

			}

	   //lower phase_a submodule sorting
			if(SM_aL_VOLTAGE_NEW[j] > SM_aL_VOLTAGE_NEW[j+1])

			{
				L_voltage_temp_a = SM_aL_VOLTAGE_NEW[j];
				SM_aL_VOLTAGE_NEW[j] = SM_aL_VOLTAGE_NEW[j+1];
				SM_aL_VOLTAGE_NEW[j+1] = L_voltage_temp_a ;

				L_index_temp_a = SM_aL_INDEX_NEW[j];
				SM_aL_INDEX_NEW[j] = SM_aL_INDEX_NEW[j+1];
				SM_aL_INDEX_NEW[j+1] = L_index_temp_a;
			}

	 //upper phase_b submodule sorting
			if(SM_bU_VOLTAGE_NEW[j] > SM_bU_VOLTAGE_NEW[j+1])

			{
				U_voltage_temp_b = SM_bU_VOLTAGE_NEW[j];
				SM_bU_VOLTAGE_NEW[j] =SM_bU_VOLTAGE_NEW[j+1];
				SM_bU_VOLTAGE_NEW[j+1] = U_voltage_temp_b;

				U_index_temp_b =  SM_bU_INDEX_NEW[j];
				SM_bU_INDEX_NEW[j] = SM_bU_INDEX_NEW[j+1];
				SM_bU_INDEX_NEW[j+1] = U_index_temp_b;
			}

   //lower phase_b submodule sorting

			if(SM_bL_VOLTAGE_NEW[j] > SM_bL_VOLTAGE_NEW[j+1])

			{
				L_voltage_temp_b = SM_bL_VOLTAGE_NEW[j];
				SM_bL_VOLTAGE_NEW[j] = SM_bL_VOLTAGE_NEW[j+1];
				SM_bL_VOLTAGE_NEW[j+1] = L_voltage_temp_b ;

				L_index_temp_b = SM_bL_INDEX_NEW[j];
				SM_bL_INDEX_NEW[j] = SM_bL_INDEX_NEW[j+1];
				SM_bL_INDEX_NEW[j+1] = L_index_temp_b;
			}

	//upper phase_c submodule sorting
			if(SM_cU_VOLTAGE_NEW[j] > SM_cU_VOLTAGE_NEW[j+1])

			{
				U_voltage_temp_c = SM_cU_VOLTAGE_NEW[j];
				SM_cU_VOLTAGE_NEW[j] =SM_cU_VOLTAGE_NEW[j+1];
				SM_cU_VOLTAGE_NEW[j+1] = U_voltage_temp_c;

				U_index_temp_c =  SM_cU_INDEX_NEW[j];
				SM_cU_INDEX_NEW[j] = SM_cU_INDEX_NEW[j+1];
				SM_cU_INDEX_NEW[j+1] = U_index_temp_c;
			}

   //lower phase_c submodule sorting

			if(SM_cL_VOLTAGE_NEW[j] > SM_cL_VOLTAGE_NEW[j+1])

			{
				L_voltage_temp_c = SM_cL_VOLTAGE_NEW[j];
				SM_cL_VOLTAGE_NEW[j] = SM_cL_VOLTAGE_NEW[j+1];
				SM_cL_VOLTAGE_NEW[j+1] = L_voltage_temp_c ;

				L_index_temp_c = SM_cL_INDEX_NEW[j];
				SM_cL_INDEX_NEW[j] = SM_cL_INDEX_NEW[j+1];
				SM_cL_INDEX_NEW[j+1] = L_index_temp_c;
			}

		}
	}

	return;

}






