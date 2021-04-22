/*
 * Define_Address.h
 *
 *  Created on: 2017. 11. 9.
 *  Revised on: 2018. xx. x
 *      Author: dongyoun
 *              Subi
 */

#ifndef INCLUDE_DEFINE_ADDRESS_H_
#define INCLUDE_DEFINE_ADDRESS_H_

#ifdef __cplusplus
extern "C" {
#endif

// EMIF1
// cs0n 0x8000 0000 - 8FFF FFFF         // Data
//(Asynchronous memory access 2n, 3n, 4n)
// As the default values of ADDR in FPGA is 000 and FFF, do not use these effective addresses not to cause some malfunction.
// A0 takes on A1's bit and EM1BA1 takes A0's bit
// cs2n 0x0010 0000 - 002F FFFF			// Program + Data effective address FFF
// cs3n 0x0030 0000 - 0037 FFFF         // Program + Data
// cs4n 0x0038 0000 - 003D FFFF         // Program + Data

// EMIF2(EtherCAT)
// cs0n 0x9000 0000 - 91FF FFFF         // Data
// cs2n 0x0000 2000 - 0000 2FFF         // Program + Data

#define CLEAR_DATA     						((volatile int *)(0x00300110))			//0001 0001 0000

//LED address
#define LED_FPGA_EN         				((volatile int *)(0x00100001))			//0000 0000 0001

//RS422 address
#define RS422_TX_SET                        ((volatile int *)(0x00100002))          //0000 0000 0010
#define RS422_TX_NUM                        ((volatile int *)(0x00100004))          //0000 0000 0100
#define RS422_TX_FAULT                      ((volatile int *)(0x00100005))          //0000 0000 0101
#define RS422_TX_BYTEREADY                  ((volatile int *)(0x00100006))          //0000 0000 0101
#define RS422_TX_TBYTE                      ((volatile int *)(0x00100007))          //0000 0000 0101
#define RS422_TX_LOAD                       ((volatile int *)(0x00100009))          //0000 0000 0101

#define RS422_TX_REGISTER                   ((volatile int *)(0x00100008))          //0000 0000 1000
#define RS422_TX_AUX_SET                    ((volatile int *)(0x0010000B))          //0000 0000 1011

#define RS422_TX_TEMP00                     ((volatile int *)(0x00100050))          //0000 0101 0000
#define RS422_TX_TEMP01                     ((volatile int *)(0x00100051))          //0000 0101 0001
#define RS422_TX_TEMP02                     ((volatile int *)(0x00100052))          //0000 0101 0010
#define RS422_TX_TEMP03                     ((volatile int *)(0x00100053))          //0000 0101 0011
#define RS422_TX_TEMP04                     ((volatile int *)(0x00100054))          //0000 0101 0100
#define RS422_TX_TEMP05                     ((volatile int *)(0x00100055))          //0000 0101 0101
#define RS422_TX_TEMP06                     ((volatile int *)(0x00100056))          //0000 0101 0110
#define RS422_TX_TEMP07                     ((volatile int *)(0x00100057))          //0000 0101 0111
#define RS422_TX_TEMP08                     ((volatile int *)(0x00100058))          //0000 0101 1000
#define RS422_TX_TEMP09                     ((volatile int *)(0x00100059))          //0000 0101 1001
#define RS422_TX_TEMP10                     ((volatile int *)(0x0010005A))          //0000 0101 1010
#define RS422_TX_TEMP11                     ((volatile int *)(0x0010005B))          //0000 0101 1011

#define RS422_TX_VOL00                      ((volatile int *)(0x00100060))          //0000 0110 0000
#define RS422_TX_VOL01                      ((volatile int *)(0x00100061))          //0000 0110 0001
#define RS422_TX_VOL02                      ((volatile int *)(0x00100062))          //0000 0110 0010
#define RS422_TX_VOL03                      ((volatile int *)(0x00100063))          //0000 0110 0011
#define RS422_TX_VOL04                      ((volatile int *)(0x00100064))          //0000 0110 0100
#define RS422_TX_VOL05                      ((volatile int *)(0x00100065))          //0000 0110 0101

#define RS422_TX_EX1                        ((volatile int *)(0x00100066))          //0000 0110 0101
#define RS422_TX_EX2                        ((volatile int *)(0x00100067))          //0000 0110 0101
#define RS422_TX_EX3                        ((volatile int *)(0x00100068))          //0000 0110 0101
#define RS422_TX_EX4                        ((volatile int *)(0x00100069))          //0000 0110 0101
#define RS422_TX_EX5                        ((volatile int *)(0x0010006A))          //0000 0110 0101
#define RS422_TX_EX6                        ((volatile int *)(0x0010006B))          //0000 0110 0101
#define RS422_TX_EX7                        ((volatile int *)(0x0010006C))          //0000 0110 0101
#define RS422_TX_EX8                        ((volatile int *)(0x0010006D))          //0000 0110 0101
#define RS422_TX_EX9                        ((volatile int *)(0x00100166))          //0000 0110 0101
#define RS422_TX_EX10                       ((volatile int *)(0x00100167))          //0000 0110 0101
#define RS422_TX_EX11                       ((volatile int *)(0x00100168))          //0000 0110 0101
#define RS422_TX_EX12                       ((volatile int *)(0x00100169))          //0000 0110 0101
#define RS422_TX_EX13                       ((volatile int *)(0x0010016A))          //0000 0110 0101
#define RS422_TX_EX14                       ((volatile int *)(0x0010016B))          //0000 0110 0101
#define RS422_TX_EX15                       ((volatile int *)(0x0010016C))          //0000 0110 0101
#define RS422_TX_EX16                       ((volatile int *)(0x0010016D))          //0000 0110 0101



#define RS422_RX_SET                        ((volatile int *)(0x0010000C))          //0000 0000 1100
#define RS422_RX_READ00                     ((volatile int *)(0x00100020))          //0000 0010 0000
#define RS422_RX_READ01                     ((volatile int *)(0x00100021))          //0000 0010 0001
#define RS422_RX_READ02                     ((volatile int *)(0x00100022))          //0000 0010 0010
#define RS422_RX_READ03                     ((volatile int *)(0x00100023))          //0000 0010 0011
#define RS422_RX_READ04                     ((volatile int *)(0x00100024))          //0000 0010 0100
#define RS422_RX_READ05                     ((volatile int *)(0x00100025))          //0000 0010 0101
#define RS422_RX_READ06                     ((volatile int *)(0x00100026))          //0000 0010 0110
#define RS422_RX_READ07                     ((volatile int *)(0x00100027))          //0000 0010 0111
#define RS422_RX_READ08                     ((volatile int *)(0x00100028))          //0000 0010 1000
#define RS422_RX_READ09                     ((volatile int *)(0x00100029))          //0000 0010 1001

#define RS422_RX_READ10                     ((volatile int *)(0x0010002A))          //0000 0010 1010
#define RS422_RX_READ11                     ((volatile int *)(0x0010002B))          //0000 0010 1011
#define RS422_RX_READ12                     ((volatile int *)(0x0010002C))          //0000 0010 1100
#define RS422_RX_READ13                     ((volatile int *)(0x0010002D))          //0000 0010 1101
#define RS422_RX_READ14                     ((volatile int *)(0x0010002E))          //0000 0010 1110
#define RS422_RX_READ15                     ((volatile int *)(0x0010002F))          //0000 0010 1111
#define RS422_RX_READ16                     ((volatile int *)(0x00100030))          //0000 0011 0000
#define RS422_RX_READ17                     ((volatile int *)(0x00100031))          //0000 0011 0001
#define RS422_RX_READ18                     ((volatile int *)(0x00100032))          //0000 0011 0010
#define RS422_RX_READ19                     ((volatile int *)(0x00100033))          //0000 0011 0011

#define RS422_RX_READ20                     ((volatile int *)(0x00100080))          //0000 0010 0000
#define RS422_RX_READ21                     ((volatile int *)(0x00100081))          //0000 0010 0001
#define RS422_RX_READ22                     ((volatile int *)(0x00100082))          //0000 0010 0010
#define RS422_RX_READ23                     ((volatile int *)(0x00100083))          //0000 0010 0011
#define RS422_RX_READ24                     ((volatile int *)(0x00100084))          //0000 0010 0100
#define RS422_RX_READ25                     ((volatile int *)(0x00100085))          //0000 0010 0101
#define RS422_RX_READ26                     ((volatile int *)(0x00100086))          //0000 0010 0110
#define RS422_RX_READ27                     ((volatile int *)(0x00100087))          //0000 0010 0111
#define RS422_RX_READ28                     ((volatile int *)(0x00100088))          //0000 0010 1000
#define RS422_RX_READ29                     ((volatile int *)(0x00100089))          //0000 0010 1001

#define RS422_RX_READ30                     ((volatile int *)(0x0010008A))          //0000 0010 1010
#define RS422_RX_READ31                     ((volatile int *)(0x0010008B))          //0000 0010 1011
#define RS422_RX_READ32                     ((volatile int *)(0x0010008C))          //0000 0010 1100
#define RS422_RX_READ33                     ((volatile int *)(0x0010008D))          //0000 0010 1101
#define RS422_RX_READ34                     ((volatile int *)(0x0010008E))          //0000 0010 1110
#define RS422_RX_READ35                     ((volatile int *)(0x0010008F))          //0000 0010 1111
#define RS422_RX_READ36                     ((volatile int *)(0x00100090))          //0000 0011 0000
#define RS422_RX_READ37                     ((volatile int *)(0x00100091))          //0000 0011 0001
#define RS422_RX_READ38                     ((volatile int *)(0x00100092))          //0000 0011 0010
#define RS422_RX_READ39                     ((volatile int *)(0x00100093))          //0000 0011 0011

#define RS422_RX_MEM_CALL                   ((volatile int *)(0x00100095))
#define RS422_RX_MEM_STORE                  ((volatile int *)(0x00100096))
#define RS422_RX_LOAD_EN                    ((volatile int *)(0x00100034))          //0000 0011 0100
#define RS422_RX_STORE_EN                   ((volatile int *)(0x00100035))          //0000 0011 0101
#define RS422_RX_AUX_SET                    ((volatile int *)(0x00100036))          //0000 0000 1011
#define DAQ_CNT                             ((volatile int *)(0x00100037))          //0000 0000 1011

//ADC address
#define ADC_ALL_CVn_ON                      ((volatile int *)(0x00100040))          //0000 0011 0101
#define ADC_ALL_CVn_OFF                     ((volatile int *)(0x00100041))          //0000 0011 0101
#define ADC_ALL_WRn_ON                      ((volatile int *)(0x00100042))          //0000 0011 0101
#define ADC_ALL_WRn_OFF                     ((volatile int *)(0x00100043))          //0000 0011 0101
#define ADC_ALL_CSn_ON                      ((volatile int *)(0x00100044))          //0000 0011 0101
#define ADC_ALL_CSn_OFF                     ((volatile int *)(0x00100045))          //0000 0011 0101

#define ADC0_CSn_ON                         ((volatile int *)(0x00100046))          //0000 0011 0101
#define ADC0_CSn_OFF                        ((volatile int *)(0x00100047))          //0000 0011 0101
#define ADC1_CSn_ON                         ((volatile int *)(0x00100048))          //0000 0011 0101
#define ADC1_CSn_OFF                        ((volatile int *)(0x00100049))          //0000 0011 0101
#define ADC2_CSn_ON                         ((volatile int *)(0x0010004A))          //0000 0011 0101
#define ADC2_CSn_OFF                        ((volatile int *)(0x0010004B))          //0000 0011 0101
#define ADC3_CSn_ON                         ((volatile int *)(0x0010004C))          //0000 0011 0101
#define ADC3_CSn_OFF                        ((volatile int *)(0x0010004D))          //0000 0011 0101
#define ADC4_CSn_ON                         ((volatile int *)(0x0010004E))          //0000 0011 0101
#define ADC4_CSn_OFF                        ((volatile int *)(0x0010004F))          //0000 0011 0101

#define ADC0_RDn                            ((volatile int *)(0x00100070))          //0000 0011 0101
#define ADC1_RDn                            ((volatile int *)(0x00100071))          //0000 0011 0101
#define ADC2_RDn                            ((volatile int *)(0x00100072))          //0000 0011 0101
#define ADC3_RDn                            ((volatile int *)(0x00100073))          //0000 0011 0101
#define ADC4_RDn                            ((volatile int *)(0x00100074))          //0000 0011 0101

//GATING
#define CARRIER_INIT_LOAD                   ((volatile int *)(0x001000A0))          //0000 0011 0101
#define CARRIER_INIT_A1                     ((volatile int *)(0x001000A1))          //0000 0011 0101
#define CARRIER_INIT_A2                     ((volatile int *)(0x001000A2))          //0000 0011 0101
#define CARRIER_INIT_A3                     ((volatile int *)(0x001000A3))          //0000 0011 0101
#define CARRIER_INIT_B1                     ((volatile int *)(0x001000A4))          //0000 0011 0101
#define CARRIER_INIT_B2                     ((volatile int *)(0x001000A5))          //0000 0011 0101
#define CARRIER_INIT_B3                     ((volatile int *)(0x001000A6))          //0000 0011 0101
#define CARRIER_INIT_HALF                   ((volatile int *)(0x001000A7))          //0000 0011 0101

#define COMPARATOR_INIT_MAX                 ((volatile int *)(0x001000A8))          //0000 0011 0101
#define COMPARATOR_INIT_MIN                 ((volatile int *)(0x001000A9))          //0000 0011 0101
#define COMPARATOR_REF_A1                   ((volatile int *)(0x001000AA))          //0000 0011 0101
#define COMPARATOR_REF_A2                   ((volatile int *)(0x001000AB))          //0000 0011 0101
#define COMPARATOR_REF_A3                   ((volatile int *)(0x001000AC))          //0000 0011 0101
#define COMPARATOR_REF_B1                   ((volatile int *)(0x001000AD))          //0000 0011 0101
#define COMPARATOR_REF_B2                   ((volatile int *)(0x001000AE))          //0000 0011 0101
#define COMPARATOR_REF_B3                   ((volatile int *)(0x001000AF))          //0000 0011 0101
#define COMPARATOR_REF_LOAD                 ((volatile int *)(0x001000B0))          //0000 0011 0101

#define GATE_BUFFER_HW                      ((volatile int *)(0x001000B1))          //0000 0011 0101
#define GATE_BUFFER_SW                      ((volatile int *)(0x00100100))

//BYPASS.c
#define BYPASS_IGBT                         ((volatile int *)(0x001000C0))          //0000 0011 0101
#define BYPASS_RELAY                        ((volatile int *)(0x001000D0))          //0000 0011 0101

//FAN.c
#define VENT_FAN                            ((volatile int *)(0x001000E0))          //0000 0011 0101

//Fault.c
#define SM_FAULT                            ((volatile int *)(0x001000E1))

// DAC address(cs4n)
#define DAC_A1_WR          				    ((volatile int *)(0x00100112))			//0001 0001 0010
#define DAC_A2_WR           				((volatile int *)(0x00100124))			//0001 0010 0100
#define DAC_A3_WR           				((volatile int *)(0x00100136))			//0001 0011 0110
#define DAC_A4_WR           				((volatile int *)(0x00100148))			//0001 0100 1000
#define DAC_A5_WR           				((volatile int *)(0x0010015A))			//0001 0101 1010
#define DAC_A6_WR           				((volatile int *)(0x0010016C))			//0001 0110 1100
#define DAC_A7_WR           				((volatile int *)(0x0010017E))			//0001 0111 1110
#define DAC_A8_WR           				((volatile int *)(0x00100180))			//0001 1000 0000
#define DAC_GEN             				((volatile int *)(0x00100192))			//0001 1001 0010

#ifdef __cplusplus
}
#endif


#endif /* INCLUDE_DEFINE_ADDRESS_H_ */
