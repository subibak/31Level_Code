/*
 * Define_SCI.h
 *
 *  Created on: 2012. 9. 25.
 *      Author: HJHeo
 */

#ifndef DEFINE_SCI_H_
#define DEFINE_SCI_H_

#ifdef __cplusplus
extern "C" {
#endif

// ADD or IDLE Mode
#define MODE_IDLE			0x0
#define MODE_ADDR			0x1

// Parity
#define PARITY_ODD			0x0
#define PARITY_EVEN			0x1

// Parity Enable
#define PARITYEN_DISABLE	0x0
#define PARITYEN_ENABLE		0x1

// Character Length
#define SCICHAR_1BIT		0x0
#define SCICHAR_2BIT		0x1
#define SCICHAR_3BIT		0x2
#define SCICHAR_4BIT		0x3
#define SCICHAR_5BIT		0x4
#define SCICHAR_6BIT		0x5
#define SCICHAR_7BIT		0x6
#define SCICHAR_8BIT		0x7

// Stop Bits
#define STOPBITS_1BIT		0x0
#define STOPBITS_2BIT		0x1

// Transmitter Enable
#define TX_DISABLE			0x0
#define TX_ENABLE			0x1

// Receiver Enable
#define RX_DISABLE			0x0
#define RX_ENABLE			0x1

// SCI Reset
#define SCI_RESET			0x0
#define SCI_RESUME			0x1

// FIFO Enable
#define FIFO_DISABLE		0x0
#define FIFO_ENABLE			0x1

// FIFO Interrupt Enable
#define FIFO_INT_DISABLE	0x0
#define FIFO_INT_ENABLE		0x1

// FIFO Interrupt Clear
#define FIFO_INT_CLEAR		0x1

// FIFO Interrupt Level
#define FIFO_INT_0BYTE		0x00
#define FIFO_INT_1BYTE		0x01
#define FIFO_INT_2BYTE		0x02
#define FIFO_INT_3BYTE		0x03
#define FIFO_INT_4BYTE		0x04
#define FIFO_INT_5BYTE		0x05
#define FIFO_INT_6BYTE		0x06
#define FIFO_INT_7BYTE		0x07
#define FIFO_INT_8BYTE		0x08
#define FIFO_INT_9BYTE		0x09
#define FIFO_INT_10BYTE		0x0A
#define FIFO_INT_11BYTE		0x0B
#define FIFO_INT_12BYTE		0x0C
#define FIFO_INT_13BYTE		0x0D
#define FIFO_INT_14BYTE		0x0E
#define FIFO_INT_15BYTE		0x0F
#define FIFO_INT_16BYTE		0x10

// SCI Interrupt
#define SCI_INT_DISABLE		0x0
#define SCI_INT_ENABLE		0x1

// SCI Sleep Mode
#define SLEEP_DISABLE		0x0
#define SLEEP_ENABLE		0x1

// Emulation Mode
#define EMUL_NOT_FREE		0x0
#define EMUL_FREE			0x1

#define EMUL_IMMEDIATE		0x0
#define EMUL_SOFT			0x1

// Data Structure for RS-232
typedef union{
	struct{
		Uint64 VALUE:16;
		Uint64 COMM:16;
		Uint64 ADDR:8;
	} UINT;
	struct{
		Uint64 BYTE4:8;
		Uint64 BYTE3:8;
		Uint64 BYTE2:8;
		Uint64 BYTE1:8;
		Uint64 BYTE0:8;
	} BYTE;
	struct{
		Uint16 VALUE;
		union{
			Uint16 COMM;
			struct{
				Uint16 RX_CON_ADDR:2;
				Uint16 FLAG_RUN:1;
				Uint16 FLAG_ALIGN:1;
				Uint16 FLAG_CURRENT:1;
				Uint16 FLAG_SPEED:1;
				Uint16 FLAG_VOLTAGE:1;
				Uint16 FLAG_ALONE:1;
				Uint16 reserved:6;
				Uint16 DATA_REQ:1;
				Uint16 DSP_FAULT_REQ:1;
			} bit;
		} RX_COMM;
		union{
			Uint16 ADDR:8;
			struct{
				Uint16 RX_SET_ADDR:4;
				Uint16 RX_DSP_ADDR:4;
			} bit;
		}RX_ADDR;
	} bit;
}S_RS232_RX;

// Data Structure for RS-232
typedef union{
	struct{
		Uint64 VALUE:16;
		Uint64 COMM:16;
		Uint64 ADDR:8;
	} UINT;
	struct{
		Uint64 BYTE4:8;
		Uint64 BYTE3:8;
		Uint64 BYTE2:8;
		Uint64 BYTE1:8;
		Uint64 BYTE0:8;
	} BYTE;
}S_RS232_TX;


// Data Structure for CAN
typedef union{
	struct{
		Uint32 Low;
		Uint32 High;
	} UINT32;
	struct{
		Uint16 UINT0;
		Uint16 UINT1;
		Uint16 UINT2;
		Uint16 reserved;
	} UINT16;
	struct
	{
		Uint64 VALUE:16;
		Uint64 COMM:16;
		Uint64 ADDR_TO:8;
		Uint64 ADDR_FROM:8;
		Uint64 reserved:16;
	} bit;
}S_CAN;

// Address Define
#define SET_ALL_DSP_ALL		0xCF
#define SET_ALL_DSP_PNL		0x3F

#define SET_WG1_DSP_MAIN	0x9C
#define SET_WG1_DSP_VIRT	0x6C
#define SET_WG1_DSP_PNL		0x3C

#define SET_WG2_DSP_MAIN	0x99
#define SET_WG2_DSP_VIRT	0x69
#define SET_WG2_DSP_PNL		0x39

#define SET_PV_DSP_MAIN		0x96
#define SET_PV_DSP_VIRT		0x66
#define SET_PV_DSP_PNL		0x36

#define SET_ES_DSP_MAIN		0x93
#define SET_ES_DSP_VIRT		0x63
#define SET_ES_DSP_PNL		0x33

#define SET_ME_DSP_ME		SET_WG2_DSP_MAIN
#define SET_ME_DSP_OTHER	SET_WG2_DSP_VIRT
#define SET_ME_DSP_PNL		SET_WG2_DSP_PNL

// Rx Command Define
#define RX_CON_ADDR			0x0003
#define UINT_RX_INV			0x0001
#define UINT_RX_CONV		0x0002

#define FLAG_RX_RUN			0x0004

#define RX_COMM				0xFFF8
#define UINT_RX_ALIGN		0x0008
#define UINT_RX_CURRENT		0x0010
#define UINT_RX_SPEED		0x0020
#define UINT_RX_VOLTAGE		0x0040
#define UINT_RX_STAND		0x0080
#define UINT_RX_DATA_REQ	0x4000
#define UINT_DSP_FAULT_REQ	0x8000

// Value Define
#define CURRENT_GAIN		0.001F
#define INV_CURRENT_GAIN	1000.0F
#define CURRENT_OFFSET		32768

#define DC_VOLTAGE_GAIN		0.01F
#define INV_DC_VOLTAGE_GAIN	100.0F
#define DC_VOLTAGE_OFFSET	0

#define AC_VOLTAGE_GAIN		0.005F
#define INV_AC_VOLTAGE_GAIN	200.0F
#define AC_VOLTAGE_OFFSET	0

#define SPEED_GAIN			0.1F
#define INV_SPEED_GAIN		10.0F
#define SPEED_OFFSET		32768

// Tx Command Define
#define UINT_TX_INV			0x0001
#define UINT_TX_CONV		0x0002

#define UINT_TX_RUN			0x0004

#define UINT_TX_CONT_ALIGN	0x0008
#define UINT_TX_CONT_CURR	0x0010
#define UINT_TX_CONT_SPEED	0x0020
#define UINT_TX_CONT_VOLT	0x0040
#define UINT_TX_CONT_STAND	0x0080

#define UINT_TX_CURR		0x4000
#define UINT_TX_DC_VOLT		0x5000
#define UINT_TX_SPEED		0x6000
#define UINT_TX_AC_VOLT		0x7000

#define UINT_DSP_FAULT		0x8000

//
#define FLAG_RX_CAN_1		0x0001
#define FLAG_RX_CAN_2		0x0002
#define FLAG_RX_CAN_3		0x0004
#define FLAG_RX_CAN_4		0x0008
#define FLAG_RX_CAN_5		0x0010

#define FLAG_RX_RS232		0x0001

#define FLAG_RX_PROG		0x8000

#define FLAG_TX_DATA		0x0001
#define FLAG_TX_RS232		0x0002
#define FLAG_TX_CAN			0x0004
#define FLAG_TX_DSP			0x0008

#ifdef __cplusplus
}
#endif

#endif /* DEFINE_SCI_H_ */
