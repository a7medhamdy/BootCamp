/*
 * SysTick_delay.c
 *
 *  Created on: Mar 13, 2019
 *      Author: AVE-LAP-039
 */




#include "Includes/TM4C123GH6PM.h"
#include <stdint.h>
#include "Includes/SysTick.h"


void SysTick_Delay(uint32_t delay)
{
    SysTick->LOAD = (delay * MS_1);

       SysTick->CTRL = SYSTICK_CTRL;
       while(!(SysTick->CTRL&SYSTICK_SHIFT));
}



