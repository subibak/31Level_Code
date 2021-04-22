// Slave Define_Xintf_Addr.h

#ifndef DEFINE_XINTF_ADDR_H_
#define DEFINE_XINTF_ADDR_H_

//	PAGE1 ADDRESS RANGE	: 0x400000H ~ 0x7FFFFFH
//	PAGE2 ADDRESS RANGE : 0x800000H ~ 0xBFFFFFH
//	XINTF_ZONE0 ADDRESS RANGE : 0x004000 ~ 0x004FFF
//	XINTF_ZONE6 ADDRESS RANGE : 0x100000 ~ 0x1FFFFF
//	XINTF_ZONE7 ADDRESS RANGE : 0x200000 ~ 0x2FFFFF


#define XINTF_ZONE0		0x004000
#define XINTF_ZONE6		0x100000
#define XINTF_ZONE7		0x200000

#define XINT1CR_ADDR						((volatile int *)(0x007070))	//XINT1 configuration register
#define XINT2CR_ADDR						((volatile int *)(0x007071))	//XINT2 configuration register
#define XINT3CR_ADDR						((volatile int *)(0x007072))	//XINT3 configuration register
#define XINT4CR_ADDR						((volatile int *)(0x007073))	//XINT4 configuration register
#define XINT5CR_ADDR						((volatile int *)(0x007074))	//XINT5 configuration register
#define XINT6CR_ADDR						((volatile int *)(0x007075))	//XINT6 configuration register
#define XINT7CR_ADDR						((volatile int *)(0x007076))	//XINT7 configuration register
#define XNMICR_ADDR							((volatile int *)(0x007077))	//XNMI configuration register
#define XINT1CTR_ADDR						((volatile int *)(0x007078))	//XINT1 counter register
#define XINT2CTR_ADDR						((volatile int *)(0x007079))	//XINT1 counter register
#define XNMICTR_ADDR						((volatile int *)(0x00707F))	//XNMI counter register

/*** PAGE0 ADDRESS RANGE : 0x004000 ~ 0x005000 ***/

// ZONE 0

#define CLEAR_DATA      ((volatile int *)(0x004010))

#define LED_WR_ADDR		((volatile int *)(0x004020))

// DAC (8CH 주소 할당)
#define DAC_A1_WR			((volatile int *)(0x004630))
#define DAC_A2_WR			((volatile int *)(0x004640))
#define DAC_A3_WR			((volatile int *)(0x004650))
#define DAC_A4_WR			((volatile int *)(0x004660))
#define DAC_A5_WR			((volatile int *)(0x004670))
#define DAC_A6_WR			((volatile int *)(0x004680))
#define DAC_A7_WR			((volatile int *)(0x004690))
#define DAC_A8_WR			((volatile int *)(0x0046A0))
#define DAC_GEN				((volatile int *)(0x0046B0))

// ADC
#define ADC_ALL_CS_ON_ADDR		((volatile int *)(0x004740))
#define ADC_ALL_CS_OFF_ADDR		((volatile int *)(0x004A70))

#define ADC_ALL_CV_ON_ADDR		((volatile int *)(0x004750))
#define ADC_ALL_CV_OFFADDR		((volatile int *)(0x004A80))

#define ADC_ALL_CS2_ON_ADDR      ((volatile int *)(0x004B20))
#define ADC_ALL_CS2_OFF_ADDR     ((volatile int *)(0x004B30))

#define ADC_ALL_CV2_ON_ADDR      ((volatile int *)(0x004B40))
#define ADC_ALL_CV2_OFFADDR      ((volatile int *)(0x004B50))

#define ADC_ALL_CS3_ON_ADDR      ((volatile int *)(0x004B60))
#define ADC_ALL_CS3_OFF_ADDR     ((volatile int *)(0x004B70))

#define ADC_ALL_CV3_ON_ADDR      ((volatile int *)(0x004B80))
#define ADC_ALL_CV3_OFFADDR      ((volatile int *)(0x004B90))

#define ADC_ALL_RD_ADDR		((volatile int *)(0x004770))
#define ADC_ALL_WR_ADDR 	((volatile int *)(0x004760))
#define ADC_A_CS_ADDR		((volatile int *)(0x004050))
#define ADC_B_CS_ADDR		((volatile int *)(0x004060))
#define ADC_C_CS_ADDR		((volatile int *)(0x004070))
#define ADC_A_CV_ADDR		((volatile int *)(0x0040B0))
#define ADC_B_CV_ADDR		((volatile int *)(0x0040C0))
#define ADC_C_CV_ADDR		((volatile int *)(0x0040D0))
#define ADC_A_RD_ADDR		((volatile int *)(0x004110))
#define ADC_B_RD_ADDR		((volatile int *)(0x004120))
#define ADC_C_RD_ADDR		((volatile int *)(0x004130))
#define ADC_A_WR_ADDR		((volatile int *)(0x004170))
#define ADC_B_WR_ADDR		((volatile int *)(0x004180))
#define ADC_C_WR_ADDR		((volatile int *)(0x004190))

#define ADC_D_WR_ADDR		((volatile int *)(0x004800))
#define ADC_E_WR_ADDR		((volatile int *)(0x004810))
#define ADC_F_WR_ADDR		((volatile int *)(0x004820))
#define ADC_G_WR_ADDR		((volatile int *)(0x004830))
#define ADC_H_WR_ADDR		((volatile int *)(0x004840))
#define ADC_I_WR_ADDR		((volatile int *)(0x004850))
#define ADC_J_WR_ADDR		((volatile int *)(0x004860))
#define ADC_K_WR_ADDR		((volatile int *)(0x0049F0))

#define ADC_D_RD_ADDR		((volatile int *)(0x004870))
#define ADC_E_RD_ADDR		((volatile int *)(0x004880))
#define ADC_F_RD_ADDR		((volatile int *)(0x004B00))
#define ADC_G_RD_ADDR		((volatile int *)(0x0048A0))
#define ADC_H_RD_ADDR		((volatile int *)(0x0048B0))
#define ADC_I_RD_ADDR		((volatile int *)(0x0048C0))
#define ADC_J_RD_ADDR		((volatile int *)(0x0048D0))
#define ADC_K_RD_ADDR		                    ((volatile int *)(0x0049E0))

#define CONVERTER_EN							    ((volatile int *)(0x004290))
#define FPGA_CARRIER_ON_ADDRESS				    ((volatile int *)(0x0042D0))


#define LOAD_PWM_UPPER_INVERTERA			    ((volatile int *)(0x0042C0))
#define LOAD_NLC_UPPER_INVERTERA			    ((volatile int *)(0x004A00))

#define LOAD_PWM_LOWER_INVERTERA			    ((volatile int *)(0x004480))
#define LOAD_NLC_LOWER_INVERTERA			    ((volatile int *)(0x004A10))


#define LOAD_PWM_UPPER_INVERTERB				((volatile int *)(0x0046C0))
#define LOAD_NLC_UPPER_INVERTERB			    ((volatile int *)(0x004A20))

#define LOAD_PWM_LOWER_INVERTERB				((volatile int *)(0x0046D0))
#define LOAD_NLC_LOWER_INVERTERB			    ((volatile int *)(0x004A30))


#define LOAD_PWM_UPPER_INVERTERC				((volatile int *)(0x0046E0))
#define LOAD_NLC_UPPER_INVERTERC			    ((volatile int *)(0x004A40))

#define LOAD_PWM_LOWER_INVERTERC				((volatile int *)(0x0046F0))
#define LOAD_NLC_LOWER_INVERTERC			    ((volatile int *)(0x004A50))

#define FPGA_Upper_Arm_Cur_SignA                ((volatile int *)(0x004370))
#define FPGA_lower_Arm_Cur_SignA                ((volatile int *)(0x004380))
#define FPGA_Upper_Arm_Cur_SignB                ((volatile int *)(0x004510))
#define FPGA_lower_Arm_Cur_SignB                ((volatile int *)(0x004550))
#define FPGA_Upper_Arm_Cur_SignC                ((volatile int *)(0x004560))
#define FPGA_lower_Arm_Cur_SignC                ((volatile int *)(0x004570))


//#define LOAD_PWM_UPPER_STATUS_ADDR			    ((volatile int *)(0x0042E0))
//#define LOAD_PWM_LOWER_STATUS_ADDR			    ((volatile int *)(0x004490))
//#define LOAD_PWM_UPPER_STATUS_ADDRB             ((volatile int *)(0x0043A0))
//#define LOAD_PWM_UPPER_STATUS_ADDRC             ((volatile int *)(0x0043B0))
//#define LOAD_PWM_LOWER_STATUS_ADDRB             ((volatile int *)(0x0043C0))
//#define LOAD_PWM_LOWER_STATUS_ADDRC             ((volatile int *)(0x0043D0))



// using address to 0x004570
// DO NOT USE 0X004600~0046F0,  0X004800~0048F0  IT'S USED FOR DAC

/*** PAGE6 ADDRESS RANGE : 0x100000 ~ 0x1F0FFF ***/

// ZONE 6

#define FPGA_upper_ref_A1                      ((volatile int *)(0x100B10))
#define FPGA_upper_ref_A2                      ((volatile int *)(0x100B20))
#define FPGA_upper_ref_A3                      ((volatile int *)(0x100B30))
#define FPGA_upper_ref_A4                      ((volatile int *)(0x100B40))

#define FPGA_lower_ref_A1                      ((volatile int *)(0x100B50))
#define FPGA_lower_ref_A2                      ((volatile int *)(0x100B60))
#define FPGA_lower_ref_A3                      ((volatile int *)(0x100B70))
#define FPGA_lower_ref_A4                      ((volatile int *)(0x100B80))

#define FPGA_upper_ref_B1                      ((volatile int *)(0x100C10))
#define FPGA_upper_ref_B2                      ((volatile int *)(0x100C20))
#define FPGA_upper_ref_B3                      ((volatile int *)(0x100C30))
#define FPGA_upper_ref_B4                      ((volatile int *)(0x100C40))

#define FPGA_lower_ref_B1                      ((volatile int *)(0x100C50))
#define FPGA_lower_ref_B2                      ((volatile int *)(0x100C60))
#define FPGA_lower_ref_B3                      ((volatile int *)(0x100C70))
#define FPGA_lower_ref_B4                      ((volatile int *)(0x100C80))

#define FPGA_upper_ref_C1                      ((volatile int *)(0x100D10))
#define FPGA_upper_ref_C2                      ((volatile int *)(0x100D20))
#define FPGA_upper_ref_C3                      ((volatile int *)(0x100D30))
#define FPGA_upper_ref_C4                      ((volatile int *)(0x100D40))

#define FPGA_lower_ref_C1                      ((volatile int *)(0x100D50))
#define FPGA_lower_ref_C2                      ((volatile int *)(0x100D60))
#define FPGA_lower_ref_C3                      ((volatile int *)(0x100D70))
#define FPGA_lower_ref_C4                      ((volatile int *)(0x100D80))

//#define Sorting_Start                            ((volatile int *)(0x100D90))
/*** PAGE7 ADDRESS RANGE : 0x200000 ~ 0x2F0FFF ***/

// ZONE 7
#endif /* DEFINE_XINTF_ADDR_H_ */
