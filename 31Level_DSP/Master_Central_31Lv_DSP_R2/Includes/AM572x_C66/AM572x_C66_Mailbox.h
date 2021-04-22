/*
 * AM572x_C66_Mailbox.h
 *
 *  Created on: 2019. 1. 9.
 *      Author: subi
 */

#ifndef INCLUDES_AM572X_C66_AM572X_C66_MAILBOX_H_
#define INCLUDES_AM572X_C66_AM572X_C66_MAILBOX_H_

#ifdef __cplusplus
extern "C" {
#endif

struct MAILBOX_REVISION_REG {
    Uint32               REVISION;
};

struct MAILBOX_SYSCONFIG_BITS {
    Uint32                  SOFTRESET:1;
    Uint32                  rsvd1:1;
    Uint32                  SIDLEMODE:2;
    Uint32                  rsvd2:28;
};

union MAILBOX_SYSCONFIG_REG {
    struct MAILBOX_SYSCONFIG_BITS               bit;
    Uint32                                      all;
};

struct MAILBOX_MESSAGE_m_REG {
    Uint32                  MESSAGEVALUEMBM;
};

struct MAILBOX_FIFOSTATUS_m_BITS {
    Uint32                  FIFOFULLMBM:1;
    Uint32                  rsvd:31;
};

union MAILBOX_FIFOSTATUS_m_REG {
    struct MAILBOX_FIFOSTATUS_m_BITS            bit;
    Uint32                                      all;
};

struct MAILBOX_MSGSTATUS_m_BITS {
    Uint32                  NBOFMSGMBM:2;
    Uint32                  rsvd:30;
};

union MAILBOX_MSGSTATUS_m_REG {
    struct MAILBOX_MSGSTATUS_m_BITS             bit;
    Uint32                                      all;
};

struct MAILBOX_IRQSTATUS_RAW_u_BITS {
    Uint32                  NEWMSGSTATUSUUMB0:1;
    Uint32                  NOTFULLSTATUSUUMB0:1;
    Uint32                  NEWMSGSTATUSUUMB1:1;
    Uint32                  NOTFULLSTATUSUUMB1:1;
    Uint32                  NEWMSGSTATUSUUMB2:1;
    Uint32                  NOTFULLSTATUSUUMB2:1;
    Uint32                  NEWMSGSTATUSUUMB3:1;
    Uint32                  NOTFULLSTATUSUUMB3:1;
    Uint32                  NEWMSGSTATUSUUMB4:1;
    Uint32                  NOTFULLSTATUSUUMB4:1;
    Uint32                  NEWMSGSTATUSUUMB5:1;
    Uint32                  NOTFULLSTATUSUUMB5:1;
    Uint32                  NEWMSGSTATUSUUMB6:1;
    Uint32                  NOTFULLSTATUSUUMB6:1;
    Uint32                  NEWMSGSTATUSUUMB7:1;
    Uint32                  NOTFULLSTATUSUUMB7:1;
    Uint32                  NEWMSGSTATUSUUMB8:1;
    Uint32                  NOTFULLSTATUSUUMB8:1;
    Uint32                  NEWMSGSTATUSUUMB9:1;
    Uint32                  NOTFULLSTATUSUUMB9:1;
    Uint32                  NEWMSGSTATUSUUMB10:1;
    Uint32                  NOTFULLSTATUSUUMB10:1;
    Uint32                  NEWMSGSTATUSUUMB11:1;
    Uint32                  NOTFULLSTATUSUUMB11:1;
    Uint32                  NEWMSGSTATUSUUMB12:1;
    Uint32                  NOTFULLSTATUSUUMB12:1;
    Uint32                  NEWMSGSTATUSUUMB13:1;
    Uint32                  NOTFULLSTATUSUUMB13:1;
    Uint32                  NEWMSGSTATUSUUMB14:1;
    Uint32                  NOTFULLSTATUSUUMB14:1;
    Uint32                  NEWMSGSTATUSUUMB15:1;
    Uint32                  NOTFULLSTATUSUUMB15:1;
};

union MAILBOX_IRQSTATUS_RAW_u_REG {
    struct MAILBOX_IRQSTATUS_RAW_u_BITS         bit;
    Uint32                                      all;
};

struct MAILBOX_IRQSTATUS_CLR_u_BITS {
    Uint32                  NEWMSGSTATUSENUUMB0:1;
    Uint32                  NOTFULLSTATUSENUUMB0:1;
    Uint32                  NEWMSGSTATUSENUUMB1:1;
    Uint32                  NOTFULLSTATUSENUUMB1:1;
    Uint32                  NEWMSGSTATUSENUUMB2:1;
    Uint32                  NOTFULLSTATUSENUUMB2:1;
    Uint32                  NEWMSGSTATUSENUUMB3:1;
    Uint32                  NOTFULLSTATUSENUUMB3:1;
    Uint32                  NEWMSGSTATUSENUUMB4:1;
    Uint32                  NOTFULLSTATUSENUUMB4:1;
    Uint32                  NEWMSGSTATUSENUUMB5:1;
    Uint32                  NOTFULLSTATUSENUUMB5:1;
    Uint32                  NEWMSGSTATUSENUUMB6:1;
    Uint32                  NOTFULLSTATUSENUUMB6:1;
    Uint32                  NEWMSGSTATUSENUUMB7:1;
    Uint32                  NOTFULLSTATUSENUUMB7:1;
    Uint32                  NEWMSGSTATUSENUUMB8:1;
    Uint32                  NOTFULLSTATUSENUUMB8:1;
    Uint32                  NEWMSGSTATUSENUUMB9:1;
    Uint32                  NOTFULLSTATUSENUUMB9:1;
    Uint32                  NEWMSGSTATUSENUUMB10:1;
    Uint32                  NOTFULLSTATUSENUUMB10:1;
    Uint32                  NEWMSGSTATUSENUUMB11:1;
    Uint32                  NOTFULLSTATUSENUUMB11:1;
    Uint32                  NEWMSGSTATUSENUUMB12:1;
    Uint32                  NOTFULLSTATUSENUUMB12:1;
    Uint32                  NEWMSGSTATUSENUUMB13:1;
    Uint32                  NOTFULLSTATUSENUUMB13:1;
    Uint32                  NEWMSGSTATUSENUUMB14:1;
    Uint32                  NOTFULLSTATUSENUUMB14:1;
    Uint32                  NEWMSGSTATUSENUUMB15:1;
    Uint32                  NOTFULLSTATUSENUUMB15:1;
};

union MAILBOX_IRQSTATUS_CLR_u_REG {
    struct MAILBOX_IRQSTATUS_CLR_u_BITS         bit;
    Uint32                                      all;
};

struct MAILBOX_IRQENABLE_SET_u_BITS {
    Uint32                  NEWMSGENABLEUUMB0:1;
    Uint32                  NOTFULLENABLEUUMB0:1;
    Uint32                  NEWMSGENABLEUUMB1:1;
    Uint32                  NOTFULLENABLEUUMB1:1;
    Uint32                  NEWMSGENABLEUUMB2:1;
    Uint32                  NOTFULLENABLEUUMB2:1;
    Uint32                  NEWMSGENABLEUUMB3:1;
    Uint32                  NOTFULLENABLEUUMB3:1;
    Uint32                  NEWMSGENABLEUUMB4:1;
    Uint32                  NOTFULLENABLEUUMB4:1;
    Uint32                  NEWMSGENABLEUUMB5:1;
    Uint32                  NOTFULLENABLEUUMB5:1;
    Uint32                  NEWMSGENABLEUUMB6:1;
    Uint32                  NOTFULLENABLEUUMB6:1;
    Uint32                  NEWMSGENABLEUUMB7:1;
    Uint32                  NOTFULLENABLEUUMB7:1;
    Uint32                  NEWMSGENABLEUUMB8:1;
    Uint32                  NOTFULLENABLEUUMB8:1;
    Uint32                  NEWMSGENABLEUUMB9:1;
    Uint32                  NOTFULLENABLEUUMB9:1;
    Uint32                  NEWMSGENABLEUUMB10:1;
    Uint32                  NOTFULLENABLEUUMB10:1;
    Uint32                  NEWMSGENABLEUUMB11:1;
    Uint32                  NOTFULLENABLEUUMB11:1;
    Uint32                  NEWMSGENABLEUUMB12:1;
    Uint32                  NOTFULLENABLEUUMB12:1;
    Uint32                  NEWMSGENABLEUUMB13:1;
    Uint32                  NOTFULLENABLEUUMB13:1;
    Uint32                  NEWMSGENABLEUUMB14:1;
    Uint32                  NOTFULLENABLEUUMB14:1;
    Uint32                  NEWMSGENABLEUUMB15:1;
    Uint32                  NOTFULLENABLEUUMB15:1;
};

union MAILBOX_IRQENABLE_SET_u_REG {
    struct MAILBOX_IRQENABLE_SET_u_BITS         bit;
    Uint32                                      all;
};

struct MAILBOX_IRQENABLE_CLR_u_BITS {
    Uint32                  NEWMSGENABLEUUMB0:1;
    Uint32                  NOTFULLENABLEUUMB0:1;
    Uint32                  NEWMSGENABLEUUMB1:1;
    Uint32                  NOTFULLENABLEUUMB1:1;
    Uint32                  NEWMSGENABLEUUMB2:1;
    Uint32                  NOTFULLENABLEUUMB2:1;
    Uint32                  NEWMSGENABLEUUMB3:1;
    Uint32                  NOTFULLENABLEUUMB3:1;
    Uint32                  NEWMSGENABLEUUMB4:1;
    Uint32                  NOTFULLENABLEUUMB4:1;
    Uint32                  NEWMSGENABLEUUMB5:1;
    Uint32                  NOTFULLENABLEUUMB5:1;
    Uint32                  NEWMSGENABLEUUMB6:1;
    Uint32                  NOTFULLENABLEUUMB6:1;
    Uint32                  NEWMSGENABLEUUMB7:1;
    Uint32                  NOTFULLENABLEUUMB7:1;
    Uint32                  NEWMSGENABLEUUMB8:1;
    Uint32                  NOTFULLENABLEUUMB8:1;
    Uint32                  NEWMSGENABLEUUMB9:1;
    Uint32                  NOTFULLENABLEUUMB9:1;
    Uint32                  NEWMSGENABLEUUMB10:1;
    Uint32                  NOTFULLENABLEUUMB10:1;
    Uint32                  NEWMSGENABLEUUMB11:1;
    Uint32                  NOTFULLENABLEUUMB11:1;
    Uint32                  NEWMSGENABLEUUMB12:1;
    Uint32                  NOTFULLENABLEUUMB12:1;
    Uint32                  NEWMSGENABLEUUMB13:1;
    Uint32                  NOTFULLENABLEUUMB13:1;
    Uint32                  NEWMSGENABLEUUMB14:1;
    Uint32                  NOTFULLENABLEUUMB14:1;
    Uint32                  NEWMSGENABLEUUMB15:1;
    Uint32                  NOTFULLENABLEUUMB15:1;
};

union MAILBOX_IRQENABLE_CLR_u_REG {
    struct MAILBOX_IRQENABLE_CLR_u_BITS         bit;
    Uint32                                      all;
};

struct MAILBOX_IRQ_EOI_BITS {
    Uint32                  EOIVAL:2;
    Uint32                  rsvd:30;
};

union MAILBOX_IRQ_EOI_REG {
    struct MAILBOX_IRQ_EOI_BITS                 bit;
    Uint32                                      all;
};

struct MAILBOX_REGS  {
    struct MAILBOX_REVISION_REG                 MAILBOX_REVISION;                   // 0x0000 0000
    Uint32                                      rsvd0[3];                           // 0x0000 0004
    union MAILBOX_SYSCONFIG_REG                 MAILBOX_SYSCONFIG;                  // 0x0000 0010
    Uint32                                      rsvd1[11];                          // 0x0000 0014
    struct MAILBOX_MESSAGE_m_REG                MAILBOX_MESSAGE_0;                  // 0x0000 0040
    struct MAILBOX_MESSAGE_m_REG                MAILBOX_MESSAGE_1;                  // 0x0000 0044
    struct MAILBOX_MESSAGE_m_REG                MAILBOX_MESSAGE_2;                  // 0x0000 0048
    struct MAILBOX_MESSAGE_m_REG                MAILBOX_MESSAGE_3;                  // 0x0000 004C
    struct MAILBOX_MESSAGE_m_REG                MAILBOX_MESSAGE_4;                  // 0x0000 0050
    struct MAILBOX_MESSAGE_m_REG                MAILBOX_MESSAGE_5;                  // 0x0000 0054
    struct MAILBOX_MESSAGE_m_REG                MAILBOX_MESSAGE_6;                  // 0x0000 0058
    struct MAILBOX_MESSAGE_m_REG                MAILBOX_MESSAGE_7;                  // 0x0000 005C
    struct MAILBOX_MESSAGE_m_REG                MAILBOX_MESSAGE_8;                  // 0x0000 0060
    struct MAILBOX_MESSAGE_m_REG                MAILBOX_MESSAGE_9;                  // 0x0000 0064
    struct MAILBOX_MESSAGE_m_REG                MAILBOX_MESSAGE_10;                 // 0x0000 0068
    struct MAILBOX_MESSAGE_m_REG                MAILBOX_MESSAGE_11;                 // 0x0000 006C
    Uint32                                      rsvd2[4];                           // 0x0000 0070
    union MAILBOX_FIFOSTATUS_m_REG              MAILBOX_FIFOSTATUS_0;               // 0x0000 0080
    union MAILBOX_FIFOSTATUS_m_REG              MAILBOX_FIFOSTATUS_1;               // 0x0000 0084
    union MAILBOX_FIFOSTATUS_m_REG              MAILBOX_FIFOSTATUS_2;               // 0x0000 0088
    union MAILBOX_FIFOSTATUS_m_REG              MAILBOX_FIFOSTATUS_3;               // 0x0000 008C
    union MAILBOX_FIFOSTATUS_m_REG              MAILBOX_FIFOSTATUS_4;               // 0x0000 0090
    union MAILBOX_FIFOSTATUS_m_REG              MAILBOX_FIFOSTATUS_5;               // 0x0000 0094
    union MAILBOX_FIFOSTATUS_m_REG              MAILBOX_FIFOSTATUS_6;               // 0x0000 0098
    union MAILBOX_FIFOSTATUS_m_REG              MAILBOX_FIFOSTATUS_7;               // 0x0000 009C
    union MAILBOX_FIFOSTATUS_m_REG              MAILBOX_FIFOSTATUS_8;               // 0x0000 00A0
    union MAILBOX_FIFOSTATUS_m_REG              MAILBOX_FIFOSTATUS_9;               // 0x0000 00A4
    union MAILBOX_FIFOSTATUS_m_REG              MAILBOX_FIFOSTATUS_10;              // 0x0000 00A8
    union MAILBOX_FIFOSTATUS_m_REG              MAILBOX_FIFOSTATUS_11;              // 0x0000 00AC
    Uint32                                      rsvd3[4];                           // 0x0000 00B0
    union MAILBOX_MSGSTATUS_m_REG               MAILBOX_MSGSTATUS_0;                // 0x0000 00C0
    union MAILBOX_MSGSTATUS_m_REG               MAILBOX_MSGSTATUS_1;                // 0x0000 00C4
    union MAILBOX_MSGSTATUS_m_REG               MAILBOX_MSGSTATUS_2;                // 0x0000 00C8
    union MAILBOX_MSGSTATUS_m_REG               MAILBOX_MSGSTATUS_3;                // 0x0000 00CC
    union MAILBOX_MSGSTATUS_m_REG               MAILBOX_MSGSTATUS_4;                // 0x0000 00D0
    union MAILBOX_MSGSTATUS_m_REG               MAILBOX_MSGSTATUS_5;                // 0x0000 00D4
    union MAILBOX_MSGSTATUS_m_REG               MAILBOX_MSGSTATUS_6;                // 0x0000 00D8
    union MAILBOX_MSGSTATUS_m_REG               MAILBOX_MSGSTATUS_7;                // 0x0000 00DC
    union MAILBOX_MSGSTATUS_m_REG               MAILBOX_MSGSTATUS_8;                // 0x0000 00E0
    union MAILBOX_MSGSTATUS_m_REG               MAILBOX_MSGSTATUS_9;                // 0x0000 00E4
    union MAILBOX_MSGSTATUS_m_REG               MAILBOX_MSGSTATUS_10;               // 0x0000 00E8
    union MAILBOX_MSGSTATUS_m_REG               MAILBOX_MSGSTATUS_11;               // 0x0000 00EC
    Uint32                                      rsvd4[4];                           // 0x0000 00F0
    union MAILBOX_IRQSTATUS_RAW_u_REG           MAILBOX_IRQSTATUS_RAW_0;            // 0x0000 0100
    union MAILBOX_IRQSTATUS_CLR_u_REG           MAILBOX_IRQSTATUS_CLR_0;            // 0x0000 0104
    union MAILBOX_IRQENABLE_SET_u_REG           MAILBOX_IRQENABLE_SET_0;            // 0x0000 0108
    union MAILBOX_IRQENABLE_CLR_u_REG           MAILBOX_IRQENABLE_CLR_0;            // 0x0000 010C
    union MAILBOX_IRQSTATUS_RAW_u_REG           MAILBOX_IRQSTATUS_RAW_1;            // 0x0000 0110
    union MAILBOX_IRQSTATUS_CLR_u_REG           MAILBOX_IRQSTATUS_CLR_1;            // 0x0000 0114
    union MAILBOX_IRQENABLE_SET_u_REG           MAILBOX_IRQENABLE_SET_1;            // 0x0000 0118
    union MAILBOX_IRQENABLE_CLR_u_REG           MAILBOX_IRQENABLE_CLR_1;            // 0x0000 011C
    union MAILBOX_IRQSTATUS_RAW_u_REG           MAILBOX_IRQSTATUS_RAW_2;            // 0x0000 0120
    union MAILBOX_IRQSTATUS_CLR_u_REG           MAILBOX_IRQSTATUS_CLR_2;            // 0x0000 0124
    union MAILBOX_IRQENABLE_SET_u_REG           MAILBOX_IRQENABLE_SET_2;            // 0x0000 0128
    union MAILBOX_IRQENABLE_CLR_u_REG           MAILBOX_IRQENABLE_CLR_2;            // 0x0000 012C
    union MAILBOX_IRQSTATUS_RAW_u_REG           MAILBOX_IRQSTATUS_RAW_3;            // 0x0000 0130
    union MAILBOX_IRQSTATUS_CLR_u_REG           MAILBOX_IRQSTATUS_CLR_3;            // 0x0000 0134
    union MAILBOX_IRQENABLE_SET_u_REG           MAILBOX_IRQENABLE_SET_3;            // 0x0000 0138
    union MAILBOX_IRQENABLE_CLR_u_REG           MAILBOX_IRQENABLE_CLR_3;            // 0x0000 013C
    union MAILBOX_IRQ_EOI_REG                   MAILBOX_IRQ_EOI;                    // 0x0000 0140
};

extern volatile struct MAILBOX_REGS             MAILBOX2Regs;
extern volatile struct MAILBOX_REGS             MAILBOX3Regs;
extern volatile struct MAILBOX_REGS             MAILBOX4Regs;
extern volatile struct MAILBOX_REGS             MAILBOX5Regs;
extern volatile struct MAILBOX_REGS             MAILBOX6Regs;
extern volatile struct MAILBOX_REGS             MAILBOX7Regs;

union TRANSFER_DATA{
    Uint32      all_U;
    float       all_F;
};

extern union TRANSFER_DATA V_AS_sec_T;
extern union TRANSFER_DATA V_BS_sec_T;
extern union TRANSFER_DATA V_CS_sec_T;
extern union TRANSFER_DATA I_AS_T;
extern union TRANSFER_DATA I_BS_T;
extern union TRANSFER_DATA I_CS_T;
extern union TRANSFER_DATA I_AU_T;
extern union TRANSFER_DATA I_AL_T;
extern union TRANSFER_DATA I_BU_T;
extern union TRANSFER_DATA I_BL_T;
extern union TRANSFER_DATA I_CU_T;
extern union TRANSFER_DATA I_CL_T;
extern union TRANSFER_DATA V_DC_T;
extern union TRANSFER_DATA I_DC_T;

struct STATUS_BITS {
    Uint32                                  HMI:2;
    Uint32                                  OP_MODE:4;
    Uint32                                  Valave_Loca:2;
    Uint32                                  Valave_type:2;
    Uint32                                  Control_Method:2;
    Uint32                                  Switching_Method:2;
    Uint32                                  Panel_Mode:2;
    Uint32                                  Order_Mode:2;
    Uint32                                  Flag_Pre_MC:1;
    Uint32                                  Flag_Main_MC:1;
    Uint32                                  rsvd0:1;
    Uint32                                  Flag_Controller:9;
    Uint32                                  rsvd1:2;
};

union STATUS_DATA {
    struct STATUS_BITS                      bit;
    Uint32                                  all;
};

union STATUS_DATA                           STATUS;

struct HMI_TO_CENTRAL_MASTER {
    Uint32                                  STATUS;
    float                                   DATA1;
    float                                   DATA2;
    float                                   DATA3;
    float                                   DATA4;
    float                                   DATA5;
    float                                   DATA6;
    float                                   DATA7;
    float                                   DATA8;
    float                                   DATA9;
    float                                   DATA10;
    float                                   DATA11;
    float                                   DATA12;
    float                                   DATA13;
    float                                   DATA14;
    float                                   DATA15;
    float                                   DATA16;
    float                                   DATA17;
    float                                   DATA18;
    float                                   DATA19;
    float                                   DATA20;
    float                                   DATA21;
    float                                   DATA22;
    float                                   DATA23;
    float                                   DATA24;
    float                                   DATA26;
    Uint16                                  DATA27;
    Uint16                                  DATA28;
    Uint16                                  DATA29;
    Uint16                                  DATA30;
    Uint16                                  DATA31;
    Uint16                                  DATA32;
    Uint16                                  DATA33;
    Uint16                                  DATA34;
    Uint16                                  DATA35;
    Uint32                                  DATA36;
    Uint32                                  DATA37;
    Uint32                                  DATA38;
    Uint32                                  DATA39;
    Uint32                                  DATA40;
    Uint32                                  DATA41;
    Uint32                                  DATA42;
    Uint32                                  DATA43;
    Uint32                                  DATA44;
    Uint32                                  DATA45;
};

extern struct HMI_TO_CENTRAL_MASTER HmiCen;

#ifdef __cplusplus
}
#endif


#endif /* INCLUDES_AM572X_C66_AM572X_C66_MAILBOX_H_ */
