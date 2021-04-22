/*
 * Define_GPMC.h
 *
 *  Created on: 2018. 11. 6.
 *      Author: HJHeo
 *  Revised on: 2018. 11. 22.
 *      Author: subi
 *
 */

#ifndef DEFINE_GPMC_H_
#define DEFINE_GPMC_H_

#ifdef __cplusplus
extern "C" {
#endif

#define GPMC_BE0n            GPIO2Regs.GPIO_DATAIN.bit.IO26
#define GPMC_BE1n            GPIO2Regs.GPIO_DATAIN.bit.IO27
#define GPMC_A12             GPIO2Regs.GPIO_DATAIN.bit.IO2
#define GPMC_BE0n_ON         GPIO2Regs.GPIO_SETDATAOUT.all    = GPIO_GPIO26
#define GPMC_BE0n_OFF        GPIO2Regs.GPIO_CLEARDATAOUT.all  = GPIO_GPIO26
#define GPMC_BE1n_ON         GPIO2Regs.GPIO_SETDATAOUT.all    = GPIO_GPIO27
#define GPMC_BE1n_OFF        GPIO2Regs.GPIO_CLEARDATAOUT.all  = GPIO_GPIO27
#define GPMC_A12_ON          GPIO2Regs.GPIO_SETDATAOUT.all    = GPIO_GPIO2
#define GPMC_A12_OFF         GPIO2Regs.GPIO_CLEARDATAOUT.all  = GPIO_GPIO2
//Address Define for FPGA communication for CS0 and CS3
//CS0
// 0x 00(6-bit base address with 4-bit mask filed address concurrently)
// available address range : a12~a1,  12bit(a0 is not allowed in 16bit non multiplexed async mode)
#define LED_FPGA_EN_CS0                     *((volatile Uint16 *)(0x14000000))           //
#define ADC_ALL_CVn_ON                      *((volatile Uint16 *)(0x14000002))          //
#define ADC_ALL_CVn_OFF                     *((volatile Uint16 *)(0x14000004))          //
#define ADC_ALL_WRn_ON                      *((volatile Uint16 *)(0x14000006))          //
#define ADC_ALL_WRn_OFF                     *((volatile Uint16 *)(0x14000008))          //
#define ADC_ALL_CSn_ON                      *((volatile Uint16 *)(0x1400000A))          //
#define ADC_ALL_CSn_OFF                     *((volatile Uint16 *)(0x1400000C))          //

#define ADC0_CSn_ON                         *((volatile Uint16 *)(0x1400000E))          //
#define ADC0_CSn_OFF                        *((volatile Uint16 *)(0x14000010))          //
#define ADC1_CSn_ON                         *((volatile Uint16 *)(0x14000012))          //
#define ADC1_CSn_OFF                        *((volatile Uint16 *)(0x14000014))          //
#define ADC2_CSn_ON                         *((volatile Uint16 *)(0x14000016))          //
#define ADC2_CSn_OFF                        *((volatile Uint16 *)(0x14000018))          //
#define ADC3_CSn_ON                         *((volatile Uint16 *)(0x1400001A))          //
#define ADC3_CSn_OFF                        *((volatile Uint16 *)(0x1400001C))          //

#define ADC0_RDn                            *((volatile Uint16 *)(0x1400001E))          //
#define ADC1_RDn                            *((volatile Uint16 *)(0x14000020))          //
#define ADC2_RDn                            *((volatile Uint16 *)(0x14000022))          //
#define ADC3_RDn                            *((volatile Uint16 *)(0x14000024))          //

#define ADC0_RDn_ON                         *((volatile Uint16 *)(0x14000026))          //
#define ADC0_RDn_OFF                        *((volatile Uint16 *)(0x14000028))          //
#define ADC1_RDn_ON                         *((volatile Uint16 *)(0x1400002A))          //
#define ADC1_RDn_OFF                        *((volatile Uint16 *)(0x1400002C))          //
#define ADC2_RDn_ON                         *((volatile Uint16 *)(0x1400002E))          //
#define ADC2_RDn_OFF                        *((volatile Uint16 *)(0x14000030))          //
#define ADC3_RDn_ON                         *((volatile Uint16 *)(0x14000032))          //
#define ADC3_RDn_OFF                        *((volatile Uint16 *)(0x14000034))          //

//////////////////////////////////////////////////////////////////////////////////////////
//Central -> Leg Master Data
//////////////////////////////////////////////////////////////////////////////////////////
//Common
#define CenLeg_Com_STATUS                   *((volatile Uint16 *)(0x17000000))
#define CenLeg_Com_SM_VOL_UNDER_LIMIT       *((volatile Uint16 *)(0x17000002))
#define CenLeg_Com_SM_VOL_OVER_LIMIT        *((volatile Uint16 *)(0x17000004))
#define CenLeg_Com_SM_TEMP_LIMIT            *((volatile Uint16 *)(0x17000006))
#define CenLeg_Com_SLAVE_OP_MODE            *((volatile Uint16 *)(0x17000008))
#define CenLeg_Com_FLASH_MSB                *((volatile Uint16 *)(0x1700000A))
#define CenLeg_Com_FLASH_LSB                *((volatile Uint16 *)(0x1700000C))

#define CenLeg_Com_ECAT_START               *((volatile Uint16 *)(0x1700000E))
#define CenLeg_WR_READY                     *((volatile Uint16 *)(0x17000010))
#define CenLeg_Com_DIFF_TIME_LSB            *((volatile Uint16 *)(0x17000012))
#define CenLeg_Com_DIFF_TIME_MSB            *((volatile Uint16 *)(0x17000014))
//////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////LEG_A///////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////
//LEG_A Operation data
#define CenLeg_OP_DATA_A_UPPER              *((volatile Uint16 *)(0x17000050))
#define CenLeg_OP_DATA_A_LOWER              *((volatile Uint16 *)(0x17000052))
//LEG_A Bypass(Relay, IGBT)
#define CenLeg_BYPASS_Group_AU1             *((volatile Uint16 *)(0x17000054))
#define CenLeg_BYPASS_Group_AU2             *((volatile Uint16 *)(0x17000056))
#define CenLeg_BYPASS_Group_AU3             *((volatile Uint16 *)(0x17000058))
#define CenLeg_BYPASS_Group_AU4             *((volatile Uint16 *)(0x1700005A))
#define CenLeg_BYPASS_Group_AU5             *((volatile Uint16 *)(0x1700005C))
#define CenLeg_BYPASS_Group_AL1             *((volatile Uint16 *)(0x1700005E))
#define CenLeg_BYPASS_Group_AL2             *((volatile Uint16 *)(0x17000060))
#define CenLeg_BYPASS_Group_AL3             *((volatile Uint16 *)(0x17000062))
#define CenLeg_BYPASS_Group_AL4             *((volatile Uint16 *)(0x17000064))
#define CenLeg_BYPASS_Group_AL5             *((volatile Uint16 *)(0x17000066))
//LEG_A REFERENCE
//#define CenLeg_REF_Group_AU1                *((volatile Uint16 *)(0x17000068))
//#define CenLeg_REF_Group_AU2                *((volatile Uint16 *)(0x1700006A))
//#define CenLeg_REF_Group_AU3                *((volatile Uint16 *)(0x1700006C))
//#define CenLeg_REF_Group_AU4                *((volatile Uint16 *)(0x1700006E))
//#define CenLeg_REF_Group_AU5                *((volatile Uint16 *)(0x17000070))
//#define CenLeg_REF_Group_AL1                *((volatile Uint16 *)(0x17000072))
//#define CenLeg_REF_Group_AL2                *((volatile Uint16 *)(0x17000074))
//#define CenLeg_REF_Group_AL3                *((volatile Uint16 *)(0x17000076))
//#define CenLeg_REF_Group_AL4                *((volatile Uint16 *)(0x17000078))
//#define CenLeg_REF_Group_AL5                *((volatile Uint16 *)(0x1700007A))

#define CenLeg_REF_AU_LSB                   *((volatile Uint16 *)(0x17000068))
#define CenLeg_REF_AU_MSB                   *((volatile Uint16 *)(0x1700006A))
#define CenLeg_REF_AL_LSB                   *((volatile Uint16 *)(0x1700006C))
#define CenLeg_REF_AL_MSB                   *((volatile Uint16 *)(0x1700006E))
//////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////LEG_B///////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////
//LEG_B Operation data
#define CenLeg_OP_DATA_B_UPPER              *((volatile Uint16 *)(0x170000A0))
#define CenLeg_OP_DATA_B_LOWER              *((volatile Uint16 *)(0x170000A2))
//LEG_B Bypass(Relay, IGBT)
#define CenLeg_BYPASS_Group_BU1             *((volatile Uint16 *)(0x170000A4))
#define CenLeg_BYPASS_Group_BU2             *((volatile Uint16 *)(0x170000A6))
#define CenLeg_BYPASS_Group_BU3             *((volatile Uint16 *)(0x170000A8))
#define CenLeg_BYPASS_Group_BU4             *((volatile Uint16 *)(0x170000AA))
#define CenLeg_BYPASS_Group_BU5             *((volatile Uint16 *)(0x170000AC))
#define CenLeg_BYPASS_Group_BL1             *((volatile Uint16 *)(0x170000AE))
#define CenLeg_BYPASS_Group_BL2             *((volatile Uint16 *)(0x170000B0))
#define CenLeg_BYPASS_Group_BL3             *((volatile Uint16 *)(0x170000B2))
#define CenLeg_BYPASS_Group_BL4             *((volatile Uint16 *)(0x170000B4))
#define CenLeg_BYPASS_Group_BL5             *((volatile Uint16 *)(0x170000B6))
//LEG_B REFERENCE
//#define CenLeg_REF_Group_BU1                *((volatile Uint16 *)(0x170000B8))
//#define CenLeg_REF_Group_BU2                *((volatile Uint16 *)(0x170000BA))
//#define CenLeg_REF_Group_BU3                *((volatile Uint16 *)(0x170000BC))
//#define CenLeg_REF_Group_BU4                *((volatile Uint16 *)(0x170000BE))
//#define CenLeg_REF_Group_BU5                *((volatile Uint16 *)(0x170000C0))
//#define CenLeg_REF_Group_BL1                *((volatile Uint16 *)(0x170000C2))
//#define CenLeg_REF_Group_BL2                *((volatile Uint16 *)(0x170000C4))
//#define CenLeg_REF_Group_BL3                *((volatile Uint16 *)(0x170000C6))
//#define CenLeg_REF_Group_BL4                *((volatile Uint16 *)(0x170000C8))
//#define CenLeg_REF_Group_BL5                *((volatile Uint16 *)(0x170000CA))

#define CenLeg_REF_BU_LSB                   *((volatile Uint16 *)(0x170000B8))
#define CenLeg_REF_BU_MSB                   *((volatile Uint16 *)(0x170000BA))
#define CenLeg_REF_BL_LSB                   *((volatile Uint16 *)(0x170000BC))
#define CenLeg_REF_BL_MSB                   *((volatile Uint16 *)(0x170000BE))
//////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////LEG_C///////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////
//LEG_C Operation data
#define CenLeg_OP_DATA_C_UPPER              *((volatile Uint16 *)(0x170000F0))
#define CenLeg_OP_DATA_C_LOWER              *((volatile Uint16 *)(0x170000F2))
//LEG_C Bypass(Relay, IGBT)
#define CenLeg_BYPASS_Group_CU1             *((volatile Uint16 *)(0x170000F4))
#define CenLeg_BYPASS_Group_CU2             *((volatile Uint16 *)(0x170000F6))
#define CenLeg_BYPASS_Group_CU3             *((volatile Uint16 *)(0x170000F8))
#define CenLeg_BYPASS_Group_CU4             *((volatile Uint16 *)(0x170000FA))
#define CenLeg_BYPASS_Group_CU5             *((volatile Uint16 *)(0x170000FC))
#define CenLeg_BYPASS_Group_CL1             *((volatile Uint16 *)(0x170000FE))
#define CenLeg_BYPASS_Group_CL2             *((volatile Uint16 *)(0x17000100))
#define CenLeg_BYPASS_Group_CL3             *((volatile Uint16 *)(0x17000102))
#define CenLeg_BYPASS_Group_CL4             *((volatile Uint16 *)(0x17000104))
#define CenLeg_BYPASS_Group_CL5             *((volatile Uint16 *)(0x17000106))
//LEG_C REFERENCE
//#define CenLeg_REF_Group_CU1                *((volatile Uint16 *)(0x17000108))
//#define CenLeg_REF_Group_CU2                *((volatile Uint16 *)(0x1700010A))
//#define CenLeg_REF_Group_CU3                *((volatile Uint16 *)(0x1700010C))
//#define CenLeg_REF_Group_CU4                *((volatile Uint16 *)(0x1700010E))
//#define CenLeg_REF_Group_CU5                *((volatile Uint16 *)(0x17000110))
//#define CenLeg_REF_Group_CL1                *((volatile Uint16 *)(0x17000112))
//#define CenLeg_REF_Group_CL2                *((volatile Uint16 *)(0x17000114))
//#define CenLeg_REF_Group_CL3                *((volatile Uint16 *)(0x17000116))
//#define CenLeg_REF_Group_CL4                *((volatile Uint16 *)(0x17000118))
//#define CenLeg_REF_Group_CL5                *((volatile Uint16 *)(0x1700011A))

#define CenLeg_REF_CU_LSB                   *((volatile Uint16 *)(0x17000108))
#define CenLeg_REF_CU_MSB                   *((volatile Uint16 *)(0x1700010A))
#define CenLeg_REF_CL_LSB                   *((volatile Uint16 *)(0x1700010C))
#define CenLeg_REF_CL_MSB                   *((volatile Uint16 *)(0x1700010E))
//////////////////////////////////////////////////////////////////////////////////////////
//Leg -> Central Master Data
//////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////LEG_A///////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////
//LEG_A SM_GROUP_SUM
#define SM_SUM_GROUP_AU1_LSB                *((volatile Uint16 *)(0x17000640))
#define SM_SUM_GROUP_AU1_MSB                *((volatile Uint16 *)(0x17000642))
#define SM_SUM_GROUP_AU2_LSB                *((volatile Uint16 *)(0x17000644))
#define SM_SUM_GROUP_AU2_MSB                *((volatile Uint16 *)(0x17000646))
#define SM_SUM_GROUP_AU3_LSB                *((volatile Uint16 *)(0x17000648))
#define SM_SUM_GROUP_AU3_MSB                *((volatile Uint16 *)(0x1700064A))
#define SM_SUM_GROUP_AU4_LSB                *((volatile Uint16 *)(0x1700064C))
#define SM_SUM_GROUP_AU4_MSB                *((volatile Uint16 *)(0x1700064E))
#define SM_SUM_GROUP_AU5_LSB                *((volatile Uint16 *)(0x17000650))
#define SM_SUM_GROUP_AU5_MSB                *((volatile Uint16 *)(0x17000652))
#define SM_SUM_GROUP_AL1_LSB                *((volatile Uint16 *)(0x17000654))
#define SM_SUM_GROUP_AL1_MSB                *((volatile Uint16 *)(0x17000656))
#define SM_SUM_GROUP_AL2_LSB                *((volatile Uint16 *)(0x17000658))
#define SM_SUM_GROUP_AL2_MSB                *((volatile Uint16 *)(0x1700065A))
#define SM_SUM_GROUP_AL3_LSB                *((volatile Uint16 *)(0x1700065C))
#define SM_SUM_GROUP_AL3_MSB                *((volatile Uint16 *)(0x1700065E))
#define SM_SUM_GROUP_AL4_LSB                *((volatile Uint16 *)(0x17000660))
#define SM_SUM_GROUP_AL4_MSB                *((volatile Uint16 *)(0x17000662))
#define SM_SUM_GROUP_AL5_LSB                *((volatile Uint16 *)(0x17000664))
#define SM_SUM_GROUP_AL5_MSB                *((volatile Uint16 *)(0x17000666))

#define SM_SUM_GROUP_AU_LSB                 *((volatile Uint16 *)(0x17000640))
#define SM_SUM_GROUP_AU_MSB                 *((volatile Uint16 *)(0x17000642))
#define SM_SUM_GROUP_AL_LSB                 *((volatile Uint16 *)(0x17000644))
#define SM_SUM_GROUP_AL_MSB                 *((volatile Uint16 *)(0x17000646))

#define SM_FAULT_A_COM                      *((volatile Uint16 *)(0x17000668))
#define SM_FAULT_A_VOL                      *((volatile Uint16 *)(0x1700066A))
#define SM_FAULT_A_TEM                      *((volatile Uint16 *)(0x1700066C))

#define ECAT_READY_L1                       *((volatile Uint16 *)(0x1700066E))

//////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////LEG_B///////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////
//LEG_B SM_GROUP_SUM
#define SM_SUM_GROUP_BU1_LSB                *((volatile Uint16 *)(0x17000690))
#define SM_SUM_GROUP_BU1_MSB                *((volatile Uint16 *)(0x17000692))
#define SM_SUM_GROUP_BU2_LSB                *((volatile Uint16 *)(0x17000694))
#define SM_SUM_GROUP_BU2_MSB                *((volatile Uint16 *)(0x17000696))
#define SM_SUM_GROUP_BU3_LSB                *((volatile Uint16 *)(0x17000698))
#define SM_SUM_GROUP_BU3_MSB                *((volatile Uint16 *)(0x1700069A))
#define SM_SUM_GROUP_BU4_LSB                *((volatile Uint16 *)(0x1700069C))
#define SM_SUM_GROUP_BU4_MSB                *((volatile Uint16 *)(0x1700069E))
#define SM_SUM_GROUP_BU5_LSB                *((volatile Uint16 *)(0x170006A0))
#define SM_SUM_GROUP_BU5_MSB                *((volatile Uint16 *)(0x170006A2))
#define SM_SUM_GROUP_BL1_LSB                *((volatile Uint16 *)(0x170006A4))
#define SM_SUM_GROUP_BL1_MSB                *((volatile Uint16 *)(0x170006A6))
#define SM_SUM_GROUP_BL2_LSB                *((volatile Uint16 *)(0x170006A8))
#define SM_SUM_GROUP_BL2_MSB                *((volatile Uint16 *)(0x170006AA))
#define SM_SUM_GROUP_BL3_LSB                *((volatile Uint16 *)(0x170006AC))
#define SM_SUM_GROUP_BL3_MSB                *((volatile Uint16 *)(0x170006AE))
#define SM_SUM_GROUP_BL4_LSB                *((volatile Uint16 *)(0x170006B0))
#define SM_SUM_GROUP_BL4_MSB                *((volatile Uint16 *)(0x170006B2))
#define SM_SUM_GROUP_BL5_LSB                *((volatile Uint16 *)(0x170006B4))
#define SM_SUM_GROUP_BL5_MSB                *((volatile Uint16 *)(0x170006B6))

#define SM_SUM_GROUP_BU_LSB                 *((volatile Uint16 *)(0x17000690))
#define SM_SUM_GROUP_BU_MSB                 *((volatile Uint16 *)(0x17000692))
#define SM_SUM_GROUP_BL_LSB                 *((volatile Uint16 *)(0x17000694))
#define SM_SUM_GROUP_BL_MSB                 *((volatile Uint16 *)(0x17000696))

#define SM_FAULT_B_COM                      *((volatile Uint16 *)(0x170006B8))
#define SM_FAULT_B_VOL                      *((volatile Uint16 *)(0x170006BA))
#define SM_FAULT_B_TEM                      *((volatile Uint16 *)(0x170006BC))

#define ECAT_READY_L2                       *((volatile Uint16 *)(0x170006BE))
//////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////LEG_C///////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////
//LEG_C SM_GROUP_SUM
#define SM_SUM_GROUP_CU1_LSB                *((volatile Uint16 *)(0x170006E0))
#define SM_SUM_GROUP_CU1_MSB                *((volatile Uint16 *)(0x170006E2))
#define SM_SUM_GROUP_CU2_LSB                *((volatile Uint16 *)(0x170006E4))
#define SM_SUM_GROUP_CU2_MSB                *((volatile Uint16 *)(0x170006E6))
#define SM_SUM_GROUP_CU3_LSB                *((volatile Uint16 *)(0x170006E8))
#define SM_SUM_GROUP_CU3_MSB                *((volatile Uint16 *)(0x170006EA))
#define SM_SUM_GROUP_CU4_LSB                *((volatile Uint16 *)(0x170006EC))
#define SM_SUM_GROUP_CU4_MSB                *((volatile Uint16 *)(0x170006EE))
#define SM_SUM_GROUP_CU5_LSB                *((volatile Uint16 *)(0x170006F0))
#define SM_SUM_GROUP_CU5_MSB                *((volatile Uint16 *)(0x170006F2))
#define SM_SUM_GROUP_CL1_LSB                *((volatile Uint16 *)(0x170006F4))
#define SM_SUM_GROUP_CL1_MSB                *((volatile Uint16 *)(0x170006F6))
#define SM_SUM_GROUP_CL2_LSB                *((volatile Uint16 *)(0x170006F8))
#define SM_SUM_GROUP_CL2_MSB                *((volatile Uint16 *)(0x170006FA))
#define SM_SUM_GROUP_CL3_LSB                *((volatile Uint16 *)(0x170006FC))
#define SM_SUM_GROUP_CL3_MSB                *((volatile Uint16 *)(0x170006FE))
#define SM_SUM_GROUP_CL4_LSB                *((volatile Uint16 *)(0x17000700))
#define SM_SUM_GROUP_CL4_MSB                *((volatile Uint16 *)(0x17000702))
#define SM_SUM_GROUP_CL5_LSB                *((volatile Uint16 *)(0x17000704))
#define SM_SUM_GROUP_CL5_MSB                *((volatile Uint16 *)(0x17000706))

#define SM_SUM_GROUP_CU_LSB                 *((volatile Uint16 *)(0x170006E0))
#define SM_SUM_GROUP_CU_MSB                 *((volatile Uint16 *)(0x170006E2))
#define SM_SUM_GROUP_CL_LSB                 *((volatile Uint16 *)(0x170006E4))
#define SM_SUM_GROUP_CL_MSB                 *((volatile Uint16 *)(0x170006E6))


#define SM_FAULT_C_COM                      *((volatile Uint16 *)(0x17000708))
#define SM_FAULT_C_VOL                      *((volatile Uint16 *)(0x1700070A))
#define SM_FAULT_C_TEM                      *((volatile Uint16 *)(0x1700070C))

#define ECAT_READY_L3                       *((volatile Uint16 *)(0x1700070E))

//variables
extern Uint16 Flag_GPMC_BE1n;
extern Uint16 Flag_EcatReady;
extern Uint32 Flag_Ecat_DAQ_EN_CNT;
extern Uint16 STATUS_ECAT_READY_L1;
extern Uint16 STATUS_ECAT_READY_L2;
extern Uint16 STATUS_ECAT_READY_L3;

// Prototype Define
extern void Init_GPMC(void);
extern void GPMC_Central_Leg(void);
extern void GPMC_Leg_Central(void);
extern void GPMC_EtherCAT(void);
extern void Para_Init(void);

#ifdef __cplusplus
}
#endif

#endif /* DEFINE_GPMC_H_ */
