/*
 * Define_Struct.h
 *
 *  Created on: 2018. 9. 7.
 *      Author: subi
 */

#ifndef INCLUDE_DEFINE_STRUCT_H_
#define INCLUDE_DEFINE_STRUCT_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "F2837xD/F2837xD_device.h"

struct Bypass_BITS{
    Uint16 RELAYA1:1;
    Uint16 RELAYA2:1;
    Uint16 RELAYA3:1;
    Uint16 RELAYB1:1;
    Uint16 RELAYB2:1;
    Uint16 RELAYB3:1;
    Uint16 IGBTA1:1;
    Uint16 IGBTA2:1;
    Uint16 IGBTA3:1;
    Uint16 IGBTB1:1;
    Uint16 IGBTB2:1;
    Uint16 IGBTB3:1;
};

typedef union _BYPASS_ {
    Uint16 all;
    struct Bypass_BITS bit;
}BYPASS;


#ifdef __cplusplus
}
#endif /* extern "C" */

#endif /* INCLUDE_DEFINE_STRUCT_H_ */
