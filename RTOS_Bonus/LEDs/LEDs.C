/*
 * LEDs.C
 *
 *  Created on: Mar 13, 2019
 *      Author: AVE-LAP-039
 */
#include <stdint.h>
#include <stdbool.h>
#include "FreeRTOS.h"
#include "task.h"
#include "hw_memmap.h"
#include "driverlib/gpio.h"
#include "driverlib/sysctl.h"
#include "Includes/LEDS.h"

#define FALSE                    0
#define TRUE                     1
#define LED1_TOGGLE_DELAY        50

volatile uint8_t flag = FALSE;

/************************************************************************/
/* Function: LEDs_init                                                  */
/* @param: void                                                         */
/* return: void                                                         */
/* Description: Initialize Led1 pins direction                          */
/************************************************************************/
void LEDs_init(void)
{
    // Enable the GPIO port that is used for the on-board LED.
    //
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);

    // Enable the GPIO pin for the LED (PF3).  Set the direction as output, and
    // enable the GPIO pin for digital function.
    //
    GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE, GPIO_PIN_1);

}

/************************************************************************/
/* Function: LED1_Task                                                  */
/* @param: void                                                         */
/* return: void                                                         */
/* Description: Task to set led on                                      */
/************************************************************************/
void LED1_Task(void *Pvparameter)
{


    while(1)
    {
        /*check flag if it is high or not*/
        if (flag == 1)
        {
            /*if flag is high set led on*/
                GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_1, GPIO_PIN_1);

        }
        else if(flag ==FALSE)
        {
            /*if flag is low set led off*/
            GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_1, FALSE);
        }
        /*set task periodicity*/
        vTaskDelay(LED1_TOGGLE_DELAY);
    }


}


