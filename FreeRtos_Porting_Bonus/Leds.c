/*
 * Leds.c
 *
 *  Created on: Mar 13, 2019
 *      Author: AVE-LAP-062
 */

#include "Leds.h"

/*******************************************************************/
/* Leds_Init                                                       */
/* Parameters : N/A                                                */
/* I/p : N/A                                                       */
/* O/p : N/A                                                       */
/* Return : N/A                                                    */
/* Function that init leds                                         */
/*******************************************************************/
void Leds_Init(void)
{
    /* Set Leds peripheral clock (PORT F) */
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);
    while(!SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOF));

    /* Set leds pins to O/P */
    GPIOPinTypeGPIOOutput(LED1PORT, LED1PIN);
}

/*******************************************************************/
/* Led1_Switch                                                     */
/* Parameters : uint32 valu                                        */
/* I/p : N/A                                                       */
/* O/p : N/A                                                       */
/* Return : void                                                   */
/* Function that switch led1 state                                 */
/*******************************************************************/
void Led1_Switch(uint32_t Mode)
{
    if(Mode == LED1_HIGH)
    {
        GPIOPinWrite(LED1PORT, LED1PIN,LED1_HIGH);
    }
    else if(Mode == LED1_LOW)
    {
        GPIOPinWrite(LED1PORT, LED1PIN,LED1_LOW);
    }
    else
    {

    }
}


