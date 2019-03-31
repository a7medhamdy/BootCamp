

/**
 * main.c
 */
#include "TM4C123GH6PM.h"

void main(void)
{

    SYSCTL->RCGCGPIO|= 0x20;
    GPIOF->DIR = 0x0E;
    GPIOF->DEN = 0x0E;

    SysTick->LOAD = 15999999;

    SysTick->CTRL = 5;
    while (1)
    {
        if ((SysTick->CTRL&(1<<16)))
        {
            GPIOF->DATA^= 0x0e;
        }
        else
        {
            /*Do nothing*/
        }
    }

}
