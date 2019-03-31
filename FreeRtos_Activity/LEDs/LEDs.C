/*
 * LEDs.C
 *
 *  Created on: Mar 13, 2019
 *      Author: AVE-LAP-039
 */
#include <stdint.h>
#include <stdbool.h>
#include "inc/hw_memmap.h"
#include "driverlib/debug.h"
#include "driverlib/gpio.h"
#include "driverlib/sysctl.h"
#include "Includes/LEDS.h"


void LEDs_init(void)
{
    // Enable the GPIO port that is used for the on-board LED.
    //
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);

    // Enable the GPIO pin for the LED (PF3).  Set the direction as output, and
    // enable the GPIO pin for digital function.
    //
    GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE, GPIO_PIN_1);
    GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE, GPIO_PIN_2);

}

void LED1_Toggle(void)
{


    if (GPIOPinRead(GPIO_PORTF_BASE,  GPIO_PIN_1))
    {
        GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_1, 0x0);
    }

    else if(!GPIOPinRead(GPIO_PORTF_BASE,  GPIO_PIN_1))
    {
        GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_1, GPIO_PIN_1);
    }

    else
    {
        /*Nothing to do*/
    }

}


void LED2_Toggle(void)
{
        if (!GPIOPinRead(GPIO_PORTF_BASE,  GPIO_PIN_2))
        {
            GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_2, GPIO_PIN_2);

        }

        else if(GPIOPinRead(GPIO_PORTF_BASE,  GPIO_PIN_2))
        {
            GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_2, 0x0);
        }

        else
        {
            /*Nothing to do*/
        }
}
