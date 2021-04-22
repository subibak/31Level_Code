/*
 * AM572x_C66_CM_CORE_AON__IPU.h
 *
 *  Created on: 2018. 12. 13.
 *      Author: subi
 */

#ifndef INCLUDES_AM572X_C66_AM572X_C66_CM_CORE_AON__IPU_H_
#define INCLUDES_AM572X_C66_AM572X_C66_CM_CORE_AON__IPU_H_

#ifdef __cplusplus
extern "C" {
#endif


// CM_IPU_TIMER_CLKCTRL Register.
//// CM_IPU_TIMER_CLKCTRL Register : Byte Value.
#define CM_IPU_TIMER_CLKCTRL_CLKSEL_SYSCLK1         0x00000000
#define CM_IPU_TIMER_CLKCTRL_CLKSEL_FUNC32KCLK      0x01000000
#define CM_IPU_TIMER_CLKCTRL_CLKSEL_SYSCLK2         0x02000000
#define CM_IPU_TIMER_CLKCTRL_CLKSEL_XREFCLK0        0X03000000
#define CM_IPU_TIMER_CLKCTRL_CLKSEL_XREFCLK1        0X04000000
#define CM_IPU_TIMER_CLKCTRL_CLKSEL_XREFCLK2        0X05000000
#define CM_IPU_TIMER_CLKCTRL_CLKSEL_XREFCLK3        0X06000000
#define CM_IPU_TIMER_CLKCTRL_CLKSEL_ABEGICLK        0X07000000
#define CM_IPU_TIMER_CLKCTRL_CLKSEL_VIDEO1DIVCLK    0X08000000
#define CM_IPU_TIMER_CLKCTRL_CLKSEL_VIDEO2DIVCLK    0X09000000
#define CM_IPU_TIMER_CLKCTRL_CLKSEL_HDMIDIVCLK      0X0A000000
#define CM_IPU_TIMER_CLKCTRL_CLKSEL_CLKOUTMUX0CLK   0X0B000000

#define CM_IPU_TIMER_CLKCTRL_IDLEST_FullFuncFlag    0X00000000
#define CM_IPU_TIMER_CLKCTRL_IDLEST_PerTransFlag    0X00010000
#define CM_IPU_TIMER_CLKCTRL_IDLEST_IdleModeFlag    0X00020000
#define CM_IPU_TIMER_CLKCTRL_IDELST_ModuleDisFlag   0X00030000

#define CM_IPU_TIMER_CLKCTRL_MODULEMODE_ModuleDis   0X00000000
#define CM_IPU_TIMER_CLKCTRL_MODULEMODE_ModuleEn    0X00000002

struct CM_IPU_TIMER_CLKCTRL_BITS {
    Uint32                              MODULEMODE:2;
    Uint32                              rsvd0:14;
    Uint32                              IDLEST:2;
    Uint32                              rsvd1:6;
    Uint32                              CLKSEL:4;
    Uint32                              rsvd2:4;
};

union CM_IPU_TIMER_CLKCTRL_REG {
    Uint32                              all;
    struct CM_IPU_TIMER_CLKCTRL_BITS    bit;
};

struct CM_CORE_AON__IPU_REGS {
    Uint32                              CM_IPU1_CLKSTCTRL;          //0x00000000
    Uint32                              CM_IPU1_STATICDEP;          //0x00000004
    Uint32                              CM_IPU1_DYNAMICDEP;         //0x00000008
    Uint32                              rsvd0[5];                   //0x0000000C
    Uint32                              CM_IPU1_IPU1_CLKCTRL;       //0x00000020
    Uint32                              rsvd1[7];                   //0x00000024
    Uint32                              CM_IPU_CLKSTCTRL;           //0x00000040
    Uint32                              rsvd2[3];                   //0x00000044
    Uint32                              CM_IPU_MCASP1_CLKCTRL;      //0x00000050
    Uint32                              rsvd3;                      //0x00000054
    union  CM_IPU_TIMER_CLKCTRL_REG     CM_IPU_TIMER5_CLKCTRL;      //0x00000058
    Uint32                              rsvd4;                      //0x0000005C
    Uint32                              CM_IPU_TIMER6_CLKCTRL;      //0x00000060
    Uint32                              rsvd5;                      //0x00000064
    Uint32                              CM_IPU_TIMER7_CLKCTRL;      //0x00000068
    Uint32                              rsvd6;                      //0x0000006C
    Uint32                              CM_IPU_TIMER8_CLKCTRL;      //0x00000070
    Uint32                              rsvd7;                      //0x00000074
    Uint32                              CM_IPU_I2C5_CLKCTRL;        //0x00000078
    Uint32                              rsvd8;                      //0x0000007C
    Uint32                              CM_IPU_UART6_CLKCTRL;       //0x00000080

};

extern volatile struct CM_CORE_AON__IPU_REGS    CM_CORE_AON__IPURegs;

#ifdef __cplusplus
}
#endif

#endif /* INCLUDES_AM572X_C66_AM572X_C66_CM_CORE_AON__IPU_H_ */
