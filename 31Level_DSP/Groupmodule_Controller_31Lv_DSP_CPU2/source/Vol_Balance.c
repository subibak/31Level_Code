/*
 * Vol_Balance.c
 *
 *  Created on: 2018. 8. 22.
 *      Author: subi
 */
#include "Define_Header.h"


float SM_VOLTAGE_NEW[6] = {0,0,0,0,0,0};
int SM_INDEX_NEW[6] = {1,2,3,4,5,6};

float voltage_temp=0;
int index_temp=0;

void Bubble_sort(int NUM_SM, float VSM[])
{
    //NUM_SM 결정할 것
    for(k = 0; k < NUM_SM; k++)
    {
       SM_VOLTAGE_NEW[k] = VSM[k];
       SM_INDEX_NEW[k] = k + 1;
    }

    // Ascending order
    for(i = 0; i < NUM_SM - 1; i++)
    {
        for(j = 0; j < NUM_SM - 1 - i; j++)
        {
        //upper phase_a submodule sorting
            if(SM_VOLTAGE_NEW[j] > SM_VOLTAGE_NEW[j+1])
            {
                voltage_temp = SM_VOLTAGE_NEW[j];
                SM_VOLTAGE_NEW[j] =SM_VOLTAGE_NEW[j+1];
                SM_VOLTAGE_NEW[j+1] = voltage_temp;

                index_temp =  SM_INDEX_NEW[j];
                SM_INDEX_NEW[j] = SM_INDEX_NEW[j+1];
                SM_INDEX_NEW[j+1] = index_temp;
            }
        }
    }

    return;

}
