/*
 * Define_DAC.h
 *
 *  Created on: 2018. 12. 13.
 *      Author: subi
 */

#ifndef INCLUDES_DEFINE_DAC_H_
#define INCLUDES_DEFINE_DAC_H_

#ifdef __cplusplus
extern "C" {
#endif

#define DAC_MID                 8191
#define DAC_RNG                 8192
#define DAC_EFF                 0x00003FFF

#define DA(num)                 (da##num.type == 0 ? *(float *)da##num.out : (float)(*(short *)da##num.out))

#define DAC_LOAD_HIGH           GPIO7Regs.GPIO_SETDATAOUT.all  = GPIO_GPIO16
#define DAC_LOAD_LOW            GPIO7Regs.GPIO_CLEARDATAOUT.all = GPIO_GPIO16


typedef struct{
    void    *out;
    float   rng;
    float   mid;
    Uint16  type;
} S_DA;

extern void DAC(void);
extern void DAC_out(Uint16 ch, Uint32 data);

#ifdef __cplusplus
}
#endif

#endif /* INCLUDES_DEFINE_DAC_H_ */
