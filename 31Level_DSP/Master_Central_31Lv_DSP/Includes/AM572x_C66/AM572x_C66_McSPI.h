/*
 * AM572x_C66_McSPI.h
 *
 *  Created on: 2018. 12. 13.
 *      Author: subi
 */

#ifndef INCLUDES_AM572X_C66_AM572X_C66_MCSPI_H_
#define INCLUDES_AM572X_C66_AM572X_C66_MCSPI_H_

#ifdef __cplusplus
extern "C" {
#endif


struct MCSPI_HL_REV_BITS {
    Uint32  REVISION;
};

union MCSPI_HL_REV_REG {
    Uint32                                  all;
    struct MCSPI_HL_REV_BITS                bit;
};

struct MCSPI_HL_HWINFO_BITS {
    Uint32  USEFIFO:1;
    Uint32  FFNBYTE:5;
    Uint32  RETMODE:1;
    Uint32  rsvd:25;
};

union MCSPI_HL_HWINFO_REG {
    Uint32                                  all;
    struct MCSPI_HL_HWINFO_BITS             bit;
};

struct MCSPI_HL_SYSCONFIG_BITS {
    Uint32  SOFTRESET:1;
    Uint32  FREEEMU:1;
    Uint32  IDLEMODE:2;
    Uint32  rsvd:28;
};

union MCSPI_HL_SYSCONFIG_REG {
    Uint32                                  all;
    struct MCSPI_HL_SYSCONFIG_BITS          bit;
};

struct MCSPI_REVISION_BITS {
    Uint32  REVISION:8;
    Uint32  rsvd:24;
};

union MCSPI_REVISION_REG {
    Uint32                                  all;
    struct MCSPI_REVISION_BITS              bit;
};

struct MCSPI_SYSCONFIG_BITS {
    Uint32  AUTOIDLE:1;
    Uint32  SOFTRESET:1;
    Uint32  ENAWAKEUP:1;
    Uint32  SIDLEMODE:2;
    Uint32  rsvd0:3;
    Uint32  CLOCKACTIVITY:2;
    Uint32  rsvd1:12;
};

union MCSPI_SYSCONFIG_REG {
    Uint32                                  all;
    struct MCSPI_SYSCONFIG_BITS             bit;
};

struct MCSPI_SYSSTATUS_BITS {
    Uint32  RESETDONE:1;
    Uint32  rsvd:31;
};

union  MCSPI_SYSSTATUS_REG {
    Uint32                                  all;
    struct MCSPI_SYSSTATUS_BITS             bit;
};

struct MCSPI_IRQSTATUS_BITS {
    Uint32  TX0_EMPTY:1;
    Uint32  TX0_UNDERFLOW:1;
    Uint32  RX0_FULL:1;
    Uint32  RX0_OVERFLOW:1;
    Uint32  TX1_EMPTY:1;
    Uint32  TX1_UNDERFLOW:1;
    Uint32  RX1_FULL:1;
    Uint32  rsvd0:1;
    Uint32  TX2_EMPTY:1;
    Uint32  TX2_UNDERFLOW:1;
    Uint32  RX2_FULL:1;
    Uint32  rsvd1:1;
    Uint32  TX3_EMPTY:1;
    Uint32  TX3_UNDERFLOW:1;
    Uint32  RX3_FULL:1;
    Uint32  rsvd2:1;
    Uint32  WKS:1;
    Uint32  EOW:1;
    Uint32  rsvd:14;
};

union MCSPI_IRQSTATUS_REG {
    Uint32                                  all;
    struct MCSPI_IRQSTATUS_BITS             bit;
};

struct MCSPI_IRQENABLE_BITS {
    Uint32  TX0_EMPTY_ENABLE:1;
    Uint32  TX0_UNDERFLOW_ENABLE:1;
    Uint32  RX0_FULL_ENABLE:1;
    Uint32  RX0_OVERFLOW_ENABLE:1;
    Uint32  TX1_EMPTY_ENABLE:1;
    Uint32  TX1_UNDERFLOW_ENABLE:1;
    Uint32  RX1_FULL_ENABLE:1;
    Uint32  rsvd0:1;
    Uint32  TX2_EMPTY_ENABLE:1;
    Uint32  TX2_UNDERFLOW_ENABLE:1;
    Uint32  RX2_FULL_ENABLE:1;
    Uint32  rsvd1:1;
    Uint32  TX3_EMPTY_ENABLE:1;
    Uint32  TX3_UNDERFLOW_ENABLE:1;
    Uint32  RX3_FULL_ENABLE:1;
    Uint32  rsvd2:1;
    Uint32  WKE:1;
    Uint32  EOW_ENABLE:1;
    Uint32  rsvd3:14;
};

union MCSPI_IRQENABLE_REG {
    Uint32                                  all;
    struct MCSPI_IRQENABLE_BITS             bit;
};

struct MCSPI_WAKEUPENABLE_BITS {
    Uint32  WKEN:1;
    Uint32  rsvd:31;
};

union  MCSPI_WAKEUPENABLE_REG {
    Uint32                                  all;
    struct MCSPI_WAKEUPENABLE_BITS          bit;
};

struct MCSPI_SYST_BITS {
    Uint32  SPIEN_0:1;
    Uint32  SPIEN_1:1;
    Uint32  SPIEN_2:1;
    Uint32  SPIEN_3:1;
    Uint32  SPIDAT_0:1;
    Uint32  SPIDAT_1:1;
    Uint32  SPICLK:1;
    Uint32  WAKD:1;
    Uint32  SPIDATDIR0:1;
    Uint32  SPIDATDIR1:1;
    Uint32  SPIENDIR:1;
    Uint32  SSB:1;
    Uint32  rsvd:20;
};

union MCSPI_SYST_REG {
    Uint32                                  all;
    struct MCSPI_SYST_BITS                  bit;
};

struct MCSPI_MODULCTRL_BITS {
    Uint32  SINGLE:1;
    Uint32  PIN34:1;
    Uint32  MS:1;
    Uint32  SYSTEM_TEST:1;
    Uint32  INITDLY:3;
    Uint32  MOA:1;
    Uint32  FDAA:1;
    Uint32  rsvd:23;
};

union  MCSPI_MODULCTRL_REG {
    Uint32                                  all;
    struct MCSPI_MODULCTRL_BITS             bit;
};
struct MCSPI_CHxCONF_BITS {
    Uint32  PHA:1;
    Uint32  POL:1;
    Uint32  CLKD:4;
    Uint32  EPOL:1;
    Uint32  WL:5;
    Uint32  TRM:2;
    Uint32  DMAW:1;
    Uint32  DMAR:1;
    Uint32  DPE0:1;
    Uint32  DPE1:1;
    Uint32  IS:1;
    Uint32  TURBO:1;
    Uint32  FORCE:1;
    Uint32  SPIENSLV:2;
    Uint32  SBE:1;
    Uint32  SBPOL:1;
    Uint32  TCS0:2;
    Uint32  FFEW:1;
    Uint32  FFER:1;
    Uint32  CLKG:1;
    Uint32  rsvd:2;
};

union MCSPI_CHxCONF_REG {
    Uint32                                  all;
    struct MCSPI_CHxCONF_BITS               bit;
};

struct MCSPI_CHxSTAT_BITS {
    Uint32  RXS:1;
    Uint32  TXS:1;
    Uint32  EOT:1;
    Uint32  TXFFE:1;
    Uint32  TXFFF:1;
    Uint32  RXFFE:1;
    Uint32  RXFFF:1;
    Uint32  rsvd:25;
};

union MCSPI_CHxSTAT_REG {
    Uint32                                  all;
    struct MCSPI_CHxSTAT_BITS               bit;
};

struct MCSPI_CHxCTRL_BITS {
    Uint32  EN:1;
    Uint32  rsvd0:7;
    Uint32  EXTCLK:8;
    Uint32  rsvd1:16;
};

union MCSPI_CHxCTRL_REG {
    Uint32                                  all;
    struct MCSPI_CHxCTRL_BITS               bit;
};

struct MCSPI_TXx_BITS {
    Uint32  TDATA;
};

union MCSPI_TXx_REG {
    Uint32                                  all;
    struct MCSPI_TXx_BITS                   bit;
};

struct MCSPI_RXx_BITS {
    Uint32  RDATA;
};

union MCSPI_RXx_REG {
    Uint32                                  all;
    struct MCSPI_RXx_BITS                   bit;
};

struct MCSPI_XFERLEVEL_BITS {
    Uint32  AEL:8;
    Uint32  AFL:8;
    Uint32  WCNT:16;
};

union  MCSPI_XFERLEVEL_REG {
    Uint32                                  all;
    struct MCSPI_XFERLEVEL_BITS             bit;
};

struct MCSPI_DAFTX_BITS {
    Uint32  DAFTDATA;
};

union MCSPI_DAFTX_REG {
    Uint32                                  all;
    struct MCSPI_DAFTX_BITS                 bit;
};

struct MCSPI_DAFRX_BITS {
    Uint32  DAFRDATA;
};

union MCSPI_DAFRX_REG {
    Uint32                                  all;
    struct MCSPI_DAFRX_BITS                 bit;
};

struct McSPI_REG {
    union MCSPI_HL_REV_REG                 MCSPI_HL_REV;            // 0x4809A000
    union MCSPI_HL_HWINFO_REG              MCSPI_HL_HWINFO;         // 0x4809A004
    Uint32                                 rsvd0[2];                // 0x4809A008
    union MCSPI_HL_SYSCONFIG_REG           MCSPI_HL_SYSCONFIG;      // 0x4809A010
    Uint32                                 rsvd1[59];               // 0x4809A014
    union MCSPI_REVISION_REG               MCSPI_REVISION;          // 0x4809A100
    Uint32                                 rsvd2[3];                // 0x4809A104
    union MCSPI_SYSCONFIG_REG              MCSPI_SYSCONFIG;         // 0x4809A110
    union MCSPI_SYSSTATUS_REG              MCSPI_SYSSTATUS;         // 0x4809A114
    union MCSPI_IRQSTATUS_REG              MCSPI_IRQSTATUS;         // 0x4809A118
    union MCSPI_IRQENABLE_REG              MCSPI_IRQENABLE;         // 0x4809A11C
    union MCSPI_WAKEUPENABLE_REG           MCSPI_WAKEUPENABLE;      // 0x4809A120
    union MCSPI_SYST_REG                   MCSPI_SYST;              // 0x4809A124
    union MCSPI_MODULCTRL_REG              MCSPI_MODULCTRL;         // 0x4809A128
    union MCSPI_CHxCONF_REG                MCSPI_CH0CONF;           // 0x4809A12C
    union MCSPI_CHxSTAT_REG                MCSPI_CH0STAT;           // 0x4809A130
    union MCSPI_CHxCTRL_REG                MCSPI_CH0CTRL;           // 0x4809A134
    union MCSPI_TXx_REG                    MCSPI_TX0;               // 0x4809A138
    union MCSPI_RXx_REG                    MCSPI_RX0;               // 0x4809A13C
    union MCSPI_CHxCONF_REG                MCSPI_CH1CONF;           // 0x4809A140
    union MCSPI_CHxSTAT_REG                MCSPI_CH1STAT;           // 0x4809A144
    union MCSPI_CHxCTRL_REG                MCSPI_CH1CTRL;           // 0x4809A148
    union MCSPI_TXx_REG                    MCSPI_TX1;               // 0x4809A14C
    union MCSPI_RXx_REG                    MCSPI_RX1;               // 0x4809A150
    union MCSPI_CHxCONF_REG                MCSPI_CH2CONF;           // 0x4809A154
    union MCSPI_CHxSTAT_REG                MCSPI_CH2STAT;           // 0x4809A158
    union MCSPI_CHxCTRL_REG                MCSPI_CH2CTRL;           // 0x4809A15C
    union MCSPI_TXx_REG                    MCSPI_TX2;               // 0x4809A160
    union MCSPI_RXx_REG                    MCSPI_RX2;               // 0x4809A164
    union MCSPI_CHxCONF_REG                MCSPI_CH3CONF;           // 0x4809A168
    union MCSPI_CHxSTAT_REG                MCSPI_CH3STAT;           // 0x4809A16C
    union MCSPI_CHxCTRL_REG                MCSPI_CH3CTRL;           // 0x4809A170
    union MCSPI_TXx_REG                    MCSPI_TX3;               // 0x4809A174
    union MCSPI_RXx_REG                    MCSPI_RX3;               // 0x4809A178
    union MCSPI_XFERLEVEL_REG              MCSPI_XFERLEVEL;         // 0x4809A17C
    union MCSPI_DAFTX_REG                  MCSPI_DAFTX;             // 0x4809A180
    Uint32                                 rsvd3[7];                // 0x4809A184
    union MCSPI_DAFRX_REG                  MCSPI_DAFRX;             // 0x4809A1A0
};

extern volatile struct McSPI_REG    McSPI2Regs;

#ifdef __cplusplus
}
#endif


#endif /* INCLUDES_AM572X_C66_AM572X_C66_MCSPI_H_ */
