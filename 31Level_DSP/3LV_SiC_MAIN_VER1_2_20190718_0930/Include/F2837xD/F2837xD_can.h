//###########################################################################
//
// FILE:    F2837xD_can.h
//
// TITLE:   F2837xD Device CAN Register Definitions.
//
//###########################################################################
// $TI Release: F2837xD Support Library v210 (Patch) $
// $Release Date: March 3 2017 $
// $Copyright: Copyright (C) 2014-2017 Texas Instruments Incorporated -
//             http://www.ti.com/ ALL RIGHTS RESERVED $
//###########################################################################

#ifndef __F2837xD_CAN_H__
#define __F2837xD_CAN_H__

#ifdef __cplusplus
extern "C" {
#endif


//---------------------------------------------------------------------------
// CAN Individual Register Bit Definitions:

struct CAN_CTL_BITS {                  // bits description
    bp_16 Init:1;                      // 0 Initialization
    bp_16 IE0:1;                       // 1 Interrupt line 0 Enable Disabled
    bp_16 SIE:1;                       // 2 Status Change Interrupt Enable Disabled
    bp_16 EIE:1;                       // 3 Error Interrupt Enable Disabled
    bp_16 rsvd1:1;                     // 4 Reserved
    bp_16 DAR:1;                       // 5 Disable Automatic Retransmission
    bp_16 CCE:1;                       // 6 Configuration Change Enable
    bp_16 Test:1;                      // 7 Test Mode Enable
    bp_16 IDS:1;                       // 8 Interruption Debug Support Enable
    bp_16 ABO:1;                       // 9 Auto-Bus-On Enable
    bp_16 PMD:4;                       // 13:10 Parity on/off
    bp_16 rsvd2:1;                     // 14 Reserved
    bp_16 SWR:1;                       // 15 SW Reset Enable
    bp_32 INITDBG:1;                   // 16 Debug Mode Status
    bp_32 IE1:1;                       // 17 Interrupt line 1 Enable Disabled
    bp_32 rsvd3:1;                     // 18 Reserved
    bp_32 rsvd4:1;                     // 19 Reserved
    bp_32 rsvd5:1;                     // 20 Reserved
    bp_32 rsvd6:3;                     // 23:21 Reserved
    bp_32 PDR:1;                       // 24 Power Down Request Mode
    bp_32 WUBA:1;                      // 25 Wake Up on Bus Activity
    bp_32 rsvd7:6;                     // 31:26 Reserved
};

union CAN_CTL_REG {
    bp_32  all;
    struct  CAN_CTL_BITS  bit;
};

// CAN_CTL Register
//// CAN_CTL Register : Byte Value
#define CAN_CTL_IE1_INT1En								0x00020000UL				//
#define CAN_CTL_IE1_INT1Dis								0x00000000UL				//

#define CAN_CTL_SWR_SWReset								0x00008000UL				//

#define CAN_CTL_PMD_ParityOff							0x00001400UL				//
#define CAN_CTL_PMD_ParityOn							0x00000000UL				//

#define CAN_CTL_ABO_AutoBusOnEn							0x00000200UL				//
#define CAN_CTL_ABO_AutoBusOnDis						0x00000000UL				//

#define CAN_CTL_IDS_SoftEnterDebugMode					0x00000100UL				//
#define CAN_CTL_IDS_ImmediatlyEnterDebugMode			0x00000000UL				//

#define CAN_CTL_TEST_TestMode							0x00000080UL				//
#define CAN_CTL_TEST_NormalMode							0x00000000UL				//

#define CAN_CTL_CCE_ConfigUnlock						0x00000040UL				//
#define CAN_CTL_CCE_ConfigLock							0x00000000UL				//

#define CAN_CTL_DAR_AutoReTXDis							0x00000020UL				//
#define CAN_CTL_DAR_AutoReTXEn							0x00000000UL				//

#define CAN_CTL_EIE_ErrorIntEn							0x00000008UL				//
#define CAN_CTL_EIE_ErrorIntDis							0x00000000UL				//

#define CAN_CTL_SIE_StatusChangeINT0En					0x00000004UL				//
#define CAN_CTL_SIE_StatusChangeINT0Dis					0x00000000UL				//

#define CAN_CTL_IE0_INT0En								0x00000002UL				//
#define CAN_CTL_IE0_INT0Dis								0x00000000UL				//

#define CAN_CTL_INIT_InitMode							0x00000001UL				//
#define CAN_CTL_INIT_NormalMode							0x00000000UL				//

struct CAN_ES_BITS {                   // bits description
    bp_16 LEC:3;                       // 2:0 Last Error Code
    bp_16 TxOk:1;                      // 3 Transmission status
    bp_16 RxOk:1;                      // 4 Reception status
    bp_16 EPass:1;                     // 5 Error Passive State
    bp_16 EWarn:1;                     // 6 Warning State
    bp_16 BOff:1;                      // 7 Bus-Off State
    bp_16 PER:1;                       // 8 Parity Error Detected
    bp_16 WakeUpPnd:1;                 // 9 Wake Up Pending
    bp_16 PDA:1;                       // 10 Power down mode acknowledge
    bp_16 rsvd1:5;                     // 15:11 Reserved
    bp_32 rsvd2:16;                    // 31:16 Reserved
};

union CAN_ES_REG {
    bp_32  all;
    struct  CAN_ES_BITS  bit;
};

struct CAN_ERRC_BITS {                 // bits description
    bp_16 TEC:8;                       // 7:0 Transmit Error Counter
    bp_16 REC:7;                       // 14:8 Receive Error Counter
    bp_16 RP:1;                        // 15 Receive Error Passive
    bp_32 rsvd1:16;                    // 31:16 Reserved
};

union CAN_ERRC_REG {
    bp_32  all;
    struct  CAN_ERRC_BITS  bit;
};

struct CAN_BTR_BITS {                  // bits description
    bp_16 BRP:6;                       // 5:0 Baud Rate Prescaler
    bp_16 SJW:2;                       // 7:6 Synchronization Jump Width
    bp_16 TSEG1:4;                     // 11:8 Time segment
    bp_16 TSEG2:3;                     // 14:12 Time segment
    bp_16 rsvd1:1;                     // 15 Reserved
    bp_32 BRPE:4;                      // 19:16 Baud Rate Prescaler Extension
    bp_32 rsvd2:12;                    // 31:20 Reserved
};

union CAN_BTR_REG {
    bp_32  all;
    struct  CAN_BTR_BITS  bit;
};

// CAN_BTR Register
//// CAN_BTR Register : Byte Value
//#define CAN_BTR_BRPE
#define CAN_BTR_BRPE_Value(val)							(((Uint32)val & 0x0000000FUL) << 16)	//
#define CAN_BTR_TSEG2_Value(val)						(((Uint32)val & 0x00000007UL) << 12)	//
#define CAN_BTR_TSEG1_Value(val)						(((Uint32)val & 0x0000000FUL) << 8)		//
#define CAN_BTR_SJW_Value(val)							(((Uint32)val & 0x00000003UL) << 6)		//
#define CAN_BTR_BRP_Value(val)							 ((Uint32)val & 0x0000003FUL)			//

struct CAN_INT_BITS {                  // bits description
    bp_16 INT0ID:16;                   // 15:0 Interrupt Identifier
    bp_32 INT1ID:8;                    // 23:16 Interrupt 1 Identifier
    bp_32 rsvd1:8;                     // 31:24 Reserved
};

union CAN_INT_REG {
    bp_32  all;
    struct  CAN_INT_BITS  bit;
};

struct CAN_TEST_BITS {                 // bits description
    bp_16 rsvd1:3;                     // 2:0 Reserved
    bp_16 SILENT:1;                    // 3 Silent Mode
    bp_16 LBACK:1;                     // 4 Loopback Mode
    bp_16 TX:2;                        // 6:5 CANTX Pin Control
    bp_16 RX:1;                        // 7 CANRX Pin Status
    bp_16 EXL:1;                       // 8 External Loopback Mode
    bp_16 RDA:1;                       // 9 RAM Direct Access Enable:
    bp_16 rsvd2:6;                     // 15:10 Reserved
    bp_32 rsvd3:16;                    // 31:16 Reserved
};

union CAN_TEST_REG {
    bp_32  all;
    struct  CAN_TEST_BITS  bit;
};

// CAN_TEST Register
//// CAN_TESET Register : Byte Value
#define CAN_TEST_RDA_RAMDirectTestMode					0x00000200UL				//
#define CAN_TEST_RDA_NormalMode							0x00000000UL				//

#define CAN_TEST_EXL_ExternalLoopTestMode				0x00000100UL				//
#define CAN_TEST_EXL_NormalMode							0x00000000UL				//

#define CAN_TEST_TX_NormalMode							0x00000000UL				//

#define CAN_TEST_LBACK_LoopBackMode						0x00000010UL				//
#define CAN_TEST_LBACK_NormalMode						0x00000000UL				//

#define CAN_TEST_SILENT_RXOnlyMode						0x00000008UL				//
#define CAN_TEST_SILENT_NormalMode						0x00000000UL				//

struct CAN_PERR_BITS {                 // bits description
    bp_16 MSG_NUM:8;                   // 7:0 Message Number
    bp_16 WORD_NUM:3;                  // 10:8 Word Number
    bp_16 rsvd1:5;                     // 15:11 Reserved
    bp_32 rsvd2:16;                    // 31:16 Reserved
};

union CAN_PERR_REG {
    bp_32  all;
    struct  CAN_PERR_BITS  bit;
};

struct CAN_REL_BITS {                  // bits description
    bp_16 DAY:8;                       // 7:0 Day
    bp_16 MON:8;                       // 15:8 Month
    bp_32 YEAR:4;                      // 19:16 Year
    bp_32 SUBSTEP:4;                   // 23:20 Substep
    bp_32 STEP:4;                      // 27:24 Step
    bp_32 REL:4;                       // 31:28 Release
};

union CAN_REL_REG {
    bp_32  all;
    struct  CAN_REL_BITS  bit;
};

struct CAN_RAM_INIT_BITS {             // bits description
    bp_16 KEY0:1;                      // 0 KEY0
    bp_16 KEY1:1;                      // 1 KEY1
    bp_16 KEY2:1;                      // 2 KEY2
    bp_16 KEY3:1;                      // 3 KEY3
    bp_16 CAN_RAM_INIT:1;              // 4 Initialize CAN Mailbox RAM
    bp_16 RAM_INIT_DONE:1;             // 5 CAN RAM initialization complete
    bp_16 rsvd1:10;                    // 15:6 Reserved
    bp_32 rsvd2:16;                    // 31:16 Reserved
};

union CAN_RAM_INIT_REG {
    bp_32  all;
    struct  CAN_RAM_INIT_BITS  bit;
};

struct CAN_GLB_INT_EN_BITS {           // bits description
    bp_16 GLBINT0_EN:1;                // 0 Global Interrupt Enable for  CAN INT0
    bp_16 GLBINT1_EN:1;                // 1 Global Interrupt Enable for  CAN INT1
    bp_16 rsvd1:14;                    // 15:2 Reserved
    bp_32 rsvd2:16;                    // 31:16 Reserved
};

union CAN_GLB_INT_EN_REG {
    bp_32  all;
    struct  CAN_GLB_INT_EN_BITS  bit;
};

struct CAN_GLB_INT_FLG_BITS {          // bits description
    bp_16 Name:1;                      // 0 Global Interrupt Flag for CAN INT0
    bp_16 INT1_FLG:1;                  // 1 Global Interrupt Flag for CAN INT1
    bp_16 rsvd1:14;                    // 15:2 Reserved
    bp_32 rsvd2:16;                    // 31:16 Reserved
};

union CAN_GLB_INT_FLG_REG {
    bp_32  all;
    struct  CAN_GLB_INT_FLG_BITS  bit;
};

struct CAN_GLB_INT_CLR_BITS {          // bits description
    bp_16 INT0_FLG_CLR:1;              // 0 Global Interrupt flag clear for CAN INT0
    bp_16 INT1_FLG_CLR:1;              // 1 Global Interrupt flag  clear for CAN INT1
    bp_16 rsvd1:14;                    // 15:2 Reserved
    bp_32 rsvd2:16;                    // 31:16 Reserved
};

union CAN_GLB_INT_CLR_REG {
    bp_32  all;
    struct  CAN_GLB_INT_CLR_BITS  bit;
};

struct CAN_TXRQ_X_BITS {               // bits description
    bp_16 TxRqstReg1:2;                // 1:0 Transmit Request Register 1
    bp_16 TxRqstReg2:2;                // 3:2 Transmit Request Register 2
    bp_16 rsvd1:12;                    // 15:4 Reserved
    bp_32 rsvd2:16;                    // 31:16 Reserved
};

union CAN_TXRQ_X_REG {
    bp_32  all;
    struct  CAN_TXRQ_X_BITS  bit;
};

struct CAN_NDAT_X_BITS {               // bits description
    bp_16 NewDatReg1:2;                // 1:0 New Data Register 1
    bp_16 NewDatReg2:2;                // 3:2 New Data Register 2
    bp_16 rsvd1:12;                    // 15:4 Reserved
    bp_32 rsvd2:16;                    // 31:16 Reserved
};

union CAN_NDAT_X_REG {
    bp_32  all;
    struct  CAN_NDAT_X_BITS  bit;
};

struct CAN_IPEN_X_BITS {               // bits description
    bp_16 IntPndReg1:2;                // 1:0 Interrupt Pending Register 1
    bp_16 IntPndReg2:2;                // 3:2 Interrupt Pending Register 2
    bp_16 rsvd1:12;                    // 15:4 Reserved
    bp_32 rsvd2:16;                    // 31:16 Reserved
};

union CAN_IPEN_X_REG {
    bp_32  all;
    struct  CAN_IPEN_X_BITS  bit;
};

struct CAN_MVAL_X_BITS {               // bits description
    bp_16 MsgValReg1:2;                // 1:0 Message Valid Register 1
    bp_16 MsgValReg2:2;                // 3:2 Message Valid Register 2
    bp_16 rsvd1:12;                    // 15:4 Reserved
    bp_32 rsvd2:16;                    // 31:16 Reserved
};

union CAN_MVAL_X_REG {
    bp_32  all;
    struct  CAN_MVAL_X_BITS  bit;
};

struct CAN_IF1CMD_BITS {               // bits description
    bp_16 MSG_NUM:8;                   // 7:0 Message Number
    bp_16 rsvd1:6;                     // 13:8 Reserved
    bp_16 rsvd2:1;                     // 14 Reserved
    bp_16 Busy:1;                      // 15 Busy Flag
    bp_32 DATA_B:1;                    // 16 Access Data Bytes 4-7
    bp_32 DATA_A:1;                    // 17 Access Data Bytes 0-3
    bp_32 TXRQST:1;                    // 18 Access Transmission Request Bit
    bp_32 ClrIntPnd:1;                 // 19 Clear Interrupt Pending Bit
    bp_32 Control:1;                   // 20 Access Control Bits
    bp_32 Arb:1;                       // 21 Access Arbitration Bits
    bp_32 Mask:1;                      // 22 Access Mask Bits
    bp_32 DIR:1;                       // 23 Write/Read Direction
    bp_32 rsvd3:8;                     // 31:24 Reserved
};

union CAN_IF1CMD_REG {
    bp_32  all;
    struct  CAN_IF1CMD_BITS  bit;
};

// CAN_IFxCMD Register
//// CAN_IFxCMD Register : Byte Value
#define CAN_IFxCMD_DIR_Write							0x00800000UL				//
#define CAN_IFxCMD_DIR_Read								0x00000000UL				//

#define CAN_IFxCMD_MASK_RW_MASKRegUpdate				0x00400000UL				//
#define CAN_IFxCMD_MASK_RW_MASKRegRemain				0x00000000UL				//

#define CAN_IFxCMD_ARB_RW_ARBRegUpdate					0x00200000UL				//
#define CAN_IFxCMD_ARB_RW_ARBRegRemain					0x00000000UL				//

#define CAN_IFxCMD_CONTROL_RW_MCTLRegUpdate				0x00100000UL				//
#define CAN_IFxCMD_CONTROL_RW_MCTLRegRemain				0x00000000UL				//

#define CAN_IFxCMD_CLRINTPND_R_INTPNDBitClear			0x00080000UL				//

#define CAN_IFxCMD_TXRQST_R_NEWDATABitClear				0x00040000UL				//
#define CAN_IFxCMD_TXRQST_W_TXRQSTnNEWDATBitByCONTROL	0x00000000UL				//
#define CAN_IFxCMD_TXRQST_W_TXRQSTnNEWDATBitSet			0x00040000UL				//

#define CAN_IFxCMD_DATA_RW_DATARegUpdate				0x00020000UL				//
#define CAN_IFxCMD_DATA_RW_DATARegRemain				0x00000000UL				//

#define CAN_IFxCMD_DATB_RW_DATBRegUpdate				0x00010000UL				//
#define CAN_IFxCMD_DATB_RW_DATBRegRemain				0x00000000UL				//

#define CAN_IFxCMD_BUSY_BUSYFlag						0x00008000UL				//

#define CAN_IFxCMD_MSG_NUM(val)							((Uint32)val & 0x000000FFUL)//

struct CAN_IF1MSK_BITS {               // bits description
    bp_32 Msk:29;                      // 28:0 Identifier Mask
    bp_32 rsvd1:1;                     // 29 Reserved
    bp_32 MDir:1;                      // 30 Mask Message Direction
    bp_32 MXtd:1;                      // 31 Mask Extended Identifier
};

union CAN_IF1MSK_REG {
    bp_32  all;
    struct  CAN_IF1MSK_BITS  bit;
};

// CAN_IFxMSK Register
//// CAN_IFxMSK Register : Byte Value
#define CAN_IFxMSK_MXTD_IDENonMasked					0x80000000UL				//
#define CAN_IFxMSK_MXTD_IDEMasked						0x00000000UL				//

#define CAN_IFxMSK_MDIR_DIRNonMasked					0x40000000UL				//
#define CAN_IFxMSK_MDIR_DIRMasked						0x00000000UL				//

#define CAN_IFxMSK_MSK_Standard_11BitMasked				0x0FFFFFFFUL				//
#define CAN_IFxMSK_MSK_Standard_10BitMasked				0x17FFFFFFUL				//
#define CAN_IFxMSK_MSK_Standard_9BitMasked				0x1BFFFFFFUL				//
#define CAN_IFxMSK_MSK_Standard_8BitMasked				0x1DFFFFFFUL				//
#define CAN_IFxMSK_MSK_Standard_7BitMasked				0x1EFFFFFFUL				//
#define CAN_IFxMSK_MSK_Standard_6BitMasked				0x1F7FFFFFUL				//
#define CAN_IFxMSK_MSK_Standard_5BitMasked				0x1FBFFFFFUL				//
#define CAN_IFxMSK_MSK_Standard_4BitMasked				0x1FDFFFFFUL				//
#define CAN_IFxMSK_MSK_Standard_3BitMasked				0x1FEFFFFFUL				//
#define CAN_IFxMSK_MSK_Standard_2BitMasked				0x1FF7FFFFUL				//
#define CAN_IFxMSK_MSK_Standard_1BitMasked				0x1FFBFFFFUL				//

#define CAN_IFxMSK_MSK_Extended_29BitMasked				0x0FFFFFFFUL				//
#define CAN_IFxMSK_MSK_Extended_28BitMasked				0x17FFFFFFUL				//
#define CAN_IFxMSK_MSK_Extended_27BitMasked				0x1BFFFFFFUL				//
#define CAN_IFxMSK_MSK_Extended_26BitMasked				0x1DFFFFFFUL				//
#define CAN_IFxMSK_MSK_Extended_25BitMasked				0x1EFFFFFFUL				//
#define CAN_IFxMSK_MSK_Extended_24BitMasked				0x1F7FFFFFUL				//
#define CAN_IFxMSK_MSK_Extended_23BitMasked				0x1FBFFFFFUL				//
#define CAN_IFxMSK_MSK_Extended_22BitMasked				0x1FDFFFFFUL				//
#define CAN_IFxMSK_MSK_Extended_21BitMasked				0x1FEFFFFFUL				//
#define CAN_IFxMSK_MSK_Extended_20BitMasked				0x1FF7FFFFUL				//
#define CAN_IFxMSK_MSK_Extended_19BitMasked				0x1FFBFFFFUL				//
#define CAN_IFxMSK_MSK_Extended_18BitMasked				0x1FFDFFFFUL				//
#define CAN_IFxMSK_MSK_Extended_17BitMasked				0x1FFEFFFFUL				//
#define CAN_IFxMSK_MSK_Extended_16BitMasked				0x1FFF7FFFUL				//
#define CAN_IFxMSK_MSK_Extended_15BitMasked				0x1FFFBFFFUL				//
#define CAN_IFxMSK_MSK_Extended_14BitMasked				0x1FFFDFFFUL				//
#define CAN_IFxMSK_MSK_Extended_13BitMasked				0x1FFFEFFFUL				//
#define CAN_IFxMSK_MSK_Extended_12BitMasked				0x1FFFF7FFUL				//
#define CAN_IFxMSK_MSK_Extended_11BitMasked				0x1FFFFBFFUL				//
#define CAN_IFxMSK_MSK_Extended_10BitMasked				0x1FFFFDFFUL				//
#define CAN_IFxMSK_MSK_Extended_9BitMasked				0x1FFFFEFFUL				//
#define CAN_IFxMSK_MSK_Extended_8BitMasked				0x1FFFFF7FUL				//
#define CAN_IFxMSK_MSK_Extended_7BitMasked				0x1FFFFFBFUL				//
#define CAN_IFxMSK_MSK_Extended_6BitMasked				0x1FFFFFDFUL				//
#define CAN_IFxMSK_MSK_Extended_5BitMasked				0x1FFFFFEFUL				//
#define CAN_IFxMSK_MSK_Extended_4BitMasked				0x1FFFFFF7UL				//
#define CAN_IFxMSK_MSK_Extended_3BitMasked				0x1FFFFFFBUL				//
#define CAN_IFxMSK_MSK_Extended_2BitMasked				0x1FFFFFFDUL				//
#define CAN_IFxMSK_MSK_Extended_1BitMasked				0x1FFFFFFEUL				//

//// CAN_IFxMSK Register : Quick Value
#define CAN_IFxMSK_MSK_AllNonMasked						0x1FFFFFFFUL				//
#define CAN_IFxMSK_MSK_AllMasked						0x00000000UL				//

struct CAN_IF1ARB_BITS {               // bits description
    bp_32 ID:29;                       // 28:0 `
    bp_32 Dir:1;                       // 29 Message Direction
    bp_32 Xtd:1;                       // 30 Extended Identifier
    bp_32 MsgVal:1;                    // 31 Message Valid
};

union CAN_IF1ARB_REG {
    bp_32  all;
    struct  CAN_IF1ARB_BITS  bit;
};

// CAN_IFxARB Register
//// CAN_IFxARB Register : Byte Value
#define CAN_IFxARB_MSGVAL_MSGBoxEn						0x80000000UL				//
#define CAN_IFxARB_MSGVAL_MSGBoxDis						0x00000000UL				//

#define CAN_IFxARB_XTD_Extended							0x40000000UL				//
#define CAN_IFxARB_XTD_Standard							0x00000000UL				//

#define CAN_IFxARB_DIR_TX_DataFrame						0x20000000UL				//
#define CAN_IFxARB_DIR_TX_RemoteFrame					0x00000000UL				//
#define CAN_IFxARB_DIR_RX_RemoteFrame					0x20000000UL				//
#define CAN_IFxARB_DIR_RX_DataFrame						0x00000000UL				//

#define CAN_IFxARB_StandardID(val)						(((Uint32)val & 0x000007FFUL) << 18)	//
#define CAN_IFxARB_ExtendedID(val)						 ((Uint32)val & 0x1FFFFFFFUL)			//

struct CAN_IF1MCTL_BITS {              // bits description
    bp_16 DLC:4;                       // 3:0 Data length code
    bp_16 rsvd1:3;                     // 6:4 Reserved
    bp_16 EoB:1;                       // 7 End of Block
    bp_16 TxRqst:1;                    // 8 Transmit Request
    bp_16 RmtEn:1;                     // 9 Remote Enable
    bp_16 RxIE:1;                      // 10 Receive Interrupt Enable
    bp_16 TxIE:1;                      // 11 Transmit Interrupt Enable
    bp_16 UMask:1;                     // 12 Use Acceptance Mask
    bp_16 IntPnd:1;                    // 13 Interrupt Pending
    bp_16 MsgLst:1;                    // 14 Message Lost
    bp_16 NewDat:1;                    // 15 New Data
    bp_32 rsvd2:16;                    // 31:16 Reserved
};

union CAN_IF1MCTL_REG {
    bp_32  all;
    struct  CAN_IF1MCTL_BITS  bit;
};

// CAN_IFxMCTL Register
//// CAN_IFxMCTL Register : Byte Value
#define CAN_IFxMCTL_NEWDATA_NewData						0x00008000UL				//
#define CAN_IFxMCTL_NEWDATA_TransceivedData				0x00000000UL				//

#define CAN_IFxMCTL_MSGLST_R_DataOverWriten				0x00004000UL				//

#define CAN_IFxMCTL_INTPND_IntSource					0x00002000UL				//

#define CAN_IFxMCTL_UMASK_MSKRegUsed					0x00001000UL				//
#define CAN_IFxMCTL_UMASK_MSKRegIgnore					0x00000000UL				//

#define CAN_IFxMCTL_TXIE_TXCompleteIntEn				0x00000800UL				//
#define CAN_IFxMCTL_TXIE_TXCompleteIntDis				0x00000000UL				//

#define CAN_IFxMCTL_RXIE_RXCompleteIntEn				0x00000400UL				//
#define CAN_IFxMCTL_RXIE_RXCompleteIntDis				0x00000000UL				//

#define CAN_IFxMCTL_RMTEN_RemoteEn						0x00000200UL				//
#define CAN_IFxMCTL_RMTEN_RemoteDis						0x00000000UL				//

#define CAN_IFxMCTL_TXRQST_TXRequest					0x00000100UL				//

#define CAN_IFxMCTL_EOB_LastMSGinFIFO					0x00000080UL				//

#define CAN_IFxMCTL_DLC_DataLength(val)					((Uint32)val & 0x0000000FUL)//

struct CAN_IF1DATA_BITS {              // bits description
    bp_16 Data_0:8;                    // 7:0 Data Byte 0
    bp_16 Data_1:8;                    // 15:8 Data Byte 1
    bp_32 Data_2:8;                    // 23:16 Data Byte 2
    bp_32 Data_3:8;                    // 31:24 Data Byte 3
};

union CAN_IF1DATA_REG {
    bp_32  all;
    struct  CAN_IF1DATA_BITS  bit;
};

struct CAN_IF1DATB_BITS {              // bits description
    bp_16 Data_4:8;                    // 7:0 Data Byte 4
    bp_16 Data_5:8;                    // 15:8 Data Byte 5
    bp_32 Data_6:8;                    // 23:16 Data Byte 6
    bp_32 Data_7:8;                    // 31:24 Data Byte 7
};

union CAN_IF1DATB_REG {
    bp_32  all;
    struct  CAN_IF1DATB_BITS  bit;
};

struct CAN_IF2CMD_BITS {               // bits description
    bp_16 MSG_NUM:8;                   // 7:0 Message Number
    bp_16 rsvd1:6;                     // 13:8 Reserved
    bp_16 rsvd2:1;                     // 14 Reserved
    bp_16 Busy:1;                      // 15 Busy Flag
    bp_32 DATA_B:1;                    // 16 Access Data Bytes 4-7
    bp_32 DATA_A:1;                    // 17 Access Data Bytes 0-3
    bp_32 TxRqst:1;                    // 18 Access Transmission Request Bit
    bp_32 ClrIntPnd:1;                 // 19 Clear Interrupt Pending Bit
    bp_32 Control:1;                   // 20 Access Control Bits
    bp_32 Arb:1;                       // 21 Access Arbitration Bits
    bp_32 Mask:1;                      // 22 Access Mask Bits
    bp_32 DIR:1;                       // 23 Write/Read Direction
    bp_32 rsvd3:8;                     // 31:24 Reserved
};

union CAN_IF2CMD_REG {
    bp_32  all;
    struct  CAN_IF2CMD_BITS  bit;
};

struct CAN_IF2MSK_BITS {               // bits description
    bp_32 Msk:29;                      // 28:0 Identifier Mask
    bp_32 rsvd1:1;                     // 29 Reserved
    bp_32 MDir:1;                      // 30 Mask Message Direction
    bp_32 MXtd:1;                      // 31 Mask Extended Identifier
};

union CAN_IF2MSK_REG {
    bp_32  all;
    struct  CAN_IF2MSK_BITS  bit;
};

struct CAN_IF2ARB_BITS {               // bits description
    bp_32 ID:29;                       // 28:0 Message  Identifier
    bp_32 Dir:1;                       // 29 Message Direction
    bp_32 Xtd:1;                       // 30 Extended Identifier
    bp_32 MsgVal:1;                    // 31 Message Valid
};

union CAN_IF2ARB_REG {
    bp_32  all;
    struct  CAN_IF2ARB_BITS  bit;
};

struct CAN_IF2MCTL_BITS {              // bits description
    bp_16 DLC:4;                       // 3:0 Data length code
    bp_16 rsvd1:3;                     // 6:4 Reserved
    bp_16 EoB:1;                       // 7 End of Block
    bp_16 TxRqst:1;                    // 8 Transmit Request
    bp_16 RmtEn:1;                     // 9 Remote Enable
    bp_16 RxIE:1;                      // 10 Receive Interrupt Enable
    bp_16 TxIE:1;                      // 11 Transmit Interrupt Enable
    bp_16 UMask:1;                     // 12 Use Acceptance Mask
    bp_16 IntPnd:1;                    // 13 Interrupt Pending
    bp_16 MsgLst:1;                    // 14 Message Lost
    bp_16 NewDat:1;                    // 15 New Data
    bp_32 rsvd2:16;                    // 31:16 Reserved
};

union CAN_IF2MCTL_REG {
    bp_32  all;
    struct  CAN_IF2MCTL_BITS  bit;
};

struct CAN_IF2DATA_BITS {              // bits description
    bp_16 Data_0:8;                    // 7:0 Data Byte 0
    bp_16 Data_1:8;                    // 15:8 Data Byte 1
    bp_32 Data_2:8;                    // 23:16 Data Byte 2
    bp_32 Data_3:8;                    // 31:24 Data Byte 3
};

union CAN_IF2DATA_REG {
    bp_32  all;
    struct  CAN_IF2DATA_BITS  bit;
};

struct CAN_IF2DATB_BITS {              // bits description
    bp_16 Data_4:8;                    // 7:0 Data Byte 4
    bp_16 Data_5:8;                    // 15:8 Data Byte 5
    bp_32 Data_6:8;                    // 23:16 Data Byte 6
    bp_32 Data_7:8;                    // 31:24 Data Byte 7
};

union CAN_IF2DATB_REG {
    bp_32  all;
    struct  CAN_IF2DATB_BITS  bit;
};

struct CAN_IF3OBS_BITS {               // bits description
    bp_16 Mask:1;                      // 0 Mask data read observation
    bp_16 Arb:1;                       // 1 Arbitration data read observation
    bp_16 Ctrl:1;                      // 2 Ctrl read observation
    bp_16 Data_A:1;                    // 3 Data A read observation
    bp_16 Data_B:1;                    // 4 Data B read observation
    bp_16 rsvd1:3;                     // 7:5 Reserved
    bp_16 IF3SM:1;                     // 8 IF3 Status of Mask data read access
    bp_16 IF3SA:1;                     // 9 IF3 Status of Arbitration data read access
    bp_16 IF3SC:1;                     // 10 IF3 Status of Control bits read access
    bp_16 IF3SDA:1;                    // 11 IF3 Status of Data A read access
    bp_16 IF3SDB:1;                    // 12 IF3 Status of Data B read access
    bp_16 rsvd2:2;                     // 14:13 Reserved
    bp_16 IF3Upd:1;                    // 15 IF3 Update Data
    bp_32 rsvd3:16;                    // 31:16 Reserved
};

union CAN_IF3OBS_REG {
    bp_32  all;
    struct  CAN_IF3OBS_BITS  bit;
};

struct CAN_IF3MSK_BITS {               // bits description
    bp_32 Msk:29;                      // 28:0 Mask
    bp_32 rsvd1:1;                     // 29 Reserved
    bp_32 MDir:1;                      // 30 Mask Message Direction
    bp_32 MXtd:1;                      // 31 Mask Extended Identifier
};

union CAN_IF3MSK_REG {
    bp_32  all;
    struct  CAN_IF3MSK_BITS  bit;
};

struct CAN_IF3ARB_BITS {               // bits description
    bp_32 ID:29;                       // 28:0 Message  Identifier
    bp_32 Dir:1;                       // 29 Message Direction
    bp_32 Xtd:1;                       // 30 Extended Identifier
    bp_32 MsgVal:1;                    // 31 Message Valid
};

union CAN_IF3ARB_REG {
    bp_32  all;
    struct  CAN_IF3ARB_BITS  bit;
};

struct CAN_IF3MCTL_BITS {              // bits description
    bp_16 DLC:4;                       // 3:0 Data length code
    bp_16 rsvd1:3;                     // 6:4 Reserved
    bp_16 EoB:1;                       // 7 End of Block
    bp_16 TxRqst:1;                    // 8 Transmit Request
    bp_16 RmtEn:1;                     // 9 Remote Enable
    bp_16 RxIE:1;                      // 10 Receive Interrupt Enable
    bp_16 TxIE:1;                      // 11 Transmit Interrupt Enable
    bp_16 UMask:1;                     // 12 Use Acceptance Mask
    bp_16 IntPnd:1;                    // 13 Interrupt Pending
    bp_16 MsgLst:1;                    // 14 Message Lost
    bp_16 NewDat:1;                    // 15 New Data
    bp_32 rsvd2:16;                    // 31:16 Reserved
};

union CAN_IF3MCTL_REG {
    bp_32  all;
    struct  CAN_IF3MCTL_BITS  bit;
};

struct CAN_IF3DATA_BITS {              // bits description
    bp_16 Data_0:8;                    // 7:0 Data Byte 0
    bp_16 Data_1:8;                    // 15:8 Data Byte 1
    bp_32 Data_2:8;                    // 23:16 Data Byte 2
    bp_32 Data_3:8;                    // 31:24 Data Byte 3
};

union CAN_IF3DATA_REG {
    bp_32  all;
    struct  CAN_IF3DATA_BITS  bit;
};

struct CAN_IF3DATB_BITS {              // bits description
    bp_16 Data_4:8;                    // 7:0 Data Byte 4
    bp_16 Data_5:8;                    // 15:8 Data Byte 5
    bp_32 Data_6:8;                    // 23:16 Data Byte 6
    bp_32 Data_7:8;                    // 31:24 Data Byte 7
};

union CAN_IF3DATB_REG {
    bp_32  all;
    struct  CAN_IF3DATB_BITS  bit;
};

struct CAN_REGS {
    union   CAN_CTL_REG                      CAN_CTL;                      // CAN Control Register
    union   CAN_ES_REG                       CAN_ES;                       // Error and Status Register
    union   CAN_ERRC_REG                     CAN_ERRC;                     // Error Counter Register
    union   CAN_BTR_REG                      CAN_BTR;                      // Bit Timing Register
    union   CAN_INT_REG                      CAN_INT;                      // Interrupt Register
    union   CAN_TEST_REG                     CAN_TEST;                     // Test Register
    uint32_t                                 rsvd1[2];                     // Reserved
    union   CAN_PERR_REG                     CAN_PERR;                     // CAN Parity Error Code Register
    union   CAN_REL_REG                      CAN_REL;                      // CAN Core Release Register
    uint32_t                                 rsvd2[14];                    // Reserved
    union   CAN_RAM_INIT_REG                 CAN_RAM_INIT;                 // CAN RAM Initialization Register
    uint32_t                                 rsvd3[6];                     // Reserved
    union   CAN_GLB_INT_EN_REG               CAN_GLB_INT_EN;               // CAN Global Interrupt Enable Register
    union   CAN_GLB_INT_FLG_REG              CAN_GLB_INT_FLG;              // CAN Global Interrupt Flag Register
    union   CAN_GLB_INT_CLR_REG              CAN_GLB_INT_CLR;              // CAN Global Interrupt Clear Register
    uint32_t                                 rsvd4[18];                    // Reserved
    bp_32                                    CAN_ABOTR;                    // Auto-Bus-On Time Register
    union   CAN_TXRQ_X_REG                   CAN_TXRQ_X;                   // CAN Transmission Request X Register
    bp_32                                    CAN_TXRQ_21;                  // CAN Transmission Request 2_1 Register
    uint32_t                                 rsvd5[6];                     // Reserved
    union   CAN_NDAT_X_REG                   CAN_NDAT_X;                   // CAN New Data X Register
    bp_32                                    CAN_NDAT_21;                  // CAN New Data 2_1 Register
    uint32_t                                 rsvd6[6];                     // Reserved
    union   CAN_IPEN_X_REG                   CAN_IPEN_X;                   // CAN Interrupt Pending X Register
    bp_32                                    CAN_IPEN_21;                  // CAN Interrupt Pending 2_1 Register
    uint32_t                                 rsvd7[6];                     // Reserved
    union   CAN_MVAL_X_REG                   CAN_MVAL_X;                   // CAN Message Valid X Register
    bp_32                                    CAN_MVAL_21;                  // CAN Message Valid 2_1 Register
    uint32_t                                 rsvd8[8];                     // Reserved
    bp_32                                    CAN_IP_MUX21;                 // CAN Interrupt Multiplexer 2_1 Register
    uint32_t                                 rsvd9[18];                    // Reserved
    union   CAN_IF1CMD_REG                   CAN_IF1CMD;                   //  IF1 Command Register
    union   CAN_IF1MSK_REG                   CAN_IF1MSK;                   // IF1 Mask Register
    union   CAN_IF1ARB_REG                   CAN_IF1ARB;                   // IF1 Arbitration Register
    union   CAN_IF1MCTL_REG                  CAN_IF1MCTL;                  // IF1 Message Control Register
    union   CAN_IF1DATA_REG                  CAN_IF1DATA;                  //  IF1 Data A Register
    union   CAN_IF1DATB_REG                  CAN_IF1DATB;                  //  IF1 Data B Register
    uint32_t                                 rsvd10[4];                    // Reserved
    union   CAN_IF2CMD_REG                   CAN_IF2CMD;                   // IF2 Command Register
    union   CAN_IF2MSK_REG                   CAN_IF2MSK;                   // IF2 Mask Register
    union   CAN_IF2ARB_REG                   CAN_IF2ARB;                   //  IF2 Arbitration Register
    union   CAN_IF2MCTL_REG                  CAN_IF2MCTL;                  //  IF2 Message Control Register
    union   CAN_IF2DATA_REG                  CAN_IF2DATA;                  // IF2 Data A Register
    union   CAN_IF2DATB_REG                  CAN_IF2DATB;                  // IF2 Data B Register
    uint32_t                                 rsvd11[4];                    // Reserved
    union   CAN_IF3OBS_REG                   CAN_IF3OBS;                   // IF3 Observation Register
    union   CAN_IF3MSK_REG                   CAN_IF3MSK;                   // IF3 Mask Register
    union   CAN_IF3ARB_REG                   CAN_IF3ARB;                   // IF3 Arbitration Register
    union   CAN_IF3MCTL_REG                  CAN_IF3MCTL;                  // IF3 Message Control Register
    union   CAN_IF3DATA_REG                  CAN_IF3DATA;                  // IF3 Data A Register
    union   CAN_IF3DATB_REG                  CAN_IF3DATB;                  // IF3 Data B Register
    uint32_t                                 rsvd12[4];                    // Reserved
    bp_32                                    CAN_IF3UPD;                   //  IF3 Update Enable Register
};

//---------------------------------------------------------------------------
// CAN External References & Function Declarations:
//
#ifdef CPU1
extern volatile struct CAN_REGS CanaRegs;
extern volatile struct CAN_REGS CanbRegs;
#endif
#ifdef CPU2
extern volatile struct CAN_REGS CanaRegs;
extern volatile struct CAN_REGS CanbRegs;
#endif
#ifdef __cplusplus
}
#endif                                  /* extern "C" */

#endif

//===========================================================================
// End of file.
//===========================================================================
