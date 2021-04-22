/*
 * AM572x_C66_MMC_Controller.h
 *
 *  Created on: 2019. 1. 20.
 *      Author: MP2C
 */

#ifndef INCLUDES_AM572X_C66_AM572X_C66_MMC_CONTROLLER_H_
#define INCLUDES_AM572X_C66_AM572X_C66_MMC_CONTROLLER_H_

#ifdef __cplusplus
extern "C" {
#endif

// Structure
struct Mode_Info_BITS{
    Uint32      HMI_status:2;
    Uint32      OP_Mode:4;
    Uint32      Valve_Location:2;
    Uint32      Valve_type:2;
    Uint32      Control_Method:2;
    Uint32      Switching_Method:2;
    Uint32      Panel_Mode:2;
    Uint32      Order_Method:2;
    Uint32      Flag_Pre_MC:1;
    Uint32      Flag_Main_MC:1;
    Uint32      Flag_UPS:1;
    Uint32      Flag_Controller:9;
    Uint32      rsvd:2;
};

union Mode_Info_DATA {
    struct  Mode_Info_BITS       bit;
    Uint32                       all;
};

extern union Mode_Info_DATA Mode_Info;
extern union Mode_Info_DATA Mode_Info_old;

#ifdef __cplusplus
}
#endif


#endif /* INCLUDES_AM572X_C66_AM572X_C66_MMC_CONTROLLER_H_ */
