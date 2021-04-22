// Slave Fault Code

#include "Define_Header.h"

Uint16 Fault_register1 = 0;
Uint16 Fault_register2 = 0;
Uint16 Fault_register3 = 0;
Uint16 Fault_register4 = 0;
Uint16 Fault_register5 = 0;
Uint16 Fault_register6 = 0;
Uint16 Fault_register7 = 0;
Uint16 Fault_register8 = 0;

Uint16 Fault_Init_Flag = 0;

float SM_OV = 47;  // Over-Shoot 전압 최대치 설정 : 120 [V]
float I_OC = 19;


void Fault(void)
{
	// Slave A/D로 실시간 서브모듈 전압 감지
	// Upper Sub-Module Over Voltage Detection
	// phase_A Upper Sub-Module Over Voltage Detection
		if (ABS(Va_SM_U[0]) > SM_OV)
			Fault_register1 |= 0x01;
		if (ABS(Va_SM_U[1]) > SM_OV)
			Fault_register1 |= 0x02;
		if (ABS(Va_SM_U[2]) > SM_OV)
			Fault_register1 |= 0x04;
		if (ABS(Va_SM_U[3]) > SM_OV)
			Fault_register1 |= 0x08;

		// phase_A Lower Sub-Module Over Voltage Detection
		if (ABS(Va_SM_L[0]) > SM_OV)
			Fault_register2 |= 0x01;
		if (ABS(Va_SM_L[1]) > SM_OV)
			Fault_register2 |= 0x02;
		if (ABS(Va_SM_L[2]) > SM_OV)
			Fault_register2 |= 0x04;
		if (ABS(Va_SM_L[3]) > SM_OV)
			Fault_register2 |= 0x08;

		// phase_B Upper Sub-Module Over Voltage Detection
		if (ABS(Vb_SM_U[0]) > SM_OV)
			Fault_register3 |= 0x01;
		if (ABS(Vb_SM_U[1]) > SM_OV)
			Fault_register3 |= 0x02;
		if (ABS(Vb_SM_U[2]) > SM_OV)
			Fault_register3 |= 0x04;
		if (ABS(Vb_SM_U[3]) > SM_OV)
			Fault_register3 |= 0x08;

		// phase_B Lower Sub-Module Over Voltage Detection
		if (ABS(Vb_SM_L[0]) > SM_OV)
			Fault_register4 |= 0x01;
		if (ABS(Vb_SM_L[1]) > SM_OV)
			Fault_register4 |= 0x02;
		if (ABS(Vb_SM_L[2]) > SM_OV)
			Fault_register4 |= 0x04;
		if (ABS(Vb_SM_L[3]) > SM_OV)
			Fault_register4 |= 0x08;

		// phase_C Upper Sub-Module Over Voltage Detection
		if (ABS(Vc_SM_U[0]) > SM_OV)
			Fault_register5 |= 0x01;
		if (ABS(Vc_SM_U[1]) > SM_OV)
			Fault_register5 |= 0x02;
		if (ABS(Vc_SM_U[2]) > SM_OV)
			Fault_register5 |= 0x04;
		if (ABS(Vc_SM_U[3]) > SM_OV)
			Fault_register5 |= 0x08;

		// phase_C Lower Sub-Module Over Voltage Detection
		if (ABS(Vc_SM_L[0]) > SM_OV)
			Fault_register6 |= 0x01;
		if (ABS(Vc_SM_L[1]) > SM_OV)
			Fault_register6 |= 0x02;
		if (ABS(Vc_SM_L[2]) > SM_OV)
			Fault_register6 |= 0x04;
		if (ABS(Vc_SM_L[3]) > SM_OV)
			Fault_register6 |= 0x08;

		if (ABS(IM1qe) > I_OC)
				Fault_register7 |= 0x01;
		if (ABS(I_as) > I_OC)
				Fault_register7 |= 0x02;
		if (ABS(I_bs) > I_OC)
				Fault_register7 |= 0x04;
		if (ABS(I_cs) > I_OC)
				Fault_register7 |= 0x08;

		if (ABS(I_au) > I_OC)
				Fault_register8 |= 0x01;
		if (ABS(I_al) > I_OC)
				Fault_register8 |= 0x02;
		if (ABS(I_bu) > I_OC)
				Fault_register8 |= 0x04;
		if (ABS(I_bl) > I_OC)
				Fault_register8 |= 0x08;
		if (ABS(I_cu) > I_OC)
				Fault_register8 |= 0x10;
		if (ABS(I_cl) > I_OC)
				Fault_register8 |= 0x20;


		if (Fault_register1 > 0)
		    Flag_MMC = 0;
		if (Fault_register2 > 0)
		    Flag_MMC = 0;
		if (Fault_register3 > 0)
		    Flag_MMC = 0;
		if (Fault_register4 > 0)
		    Flag_MMC = 0;
		if (Fault_register5 > 0)
		    Flag_MMC = 0;
		if (Fault_register6 > 0)
		    Flag_MMC = 0;
		if (Fault_register7 > 0)
		    Flag_MMC = 0;
		if (Fault_register8 > 0)
		    Flag_MMC = 0;

}
