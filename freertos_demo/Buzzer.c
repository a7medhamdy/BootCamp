/*
 * Buzzer.c
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
#include "LEDS.h"
#include <stdbool.h>
#include <stdint.h>
#include "inc/hw_memmap.h"
#include "inc/hw_types.h"
#include "driverlib/gpio.h"
#include "driverlib/rom.h"
#include "drivers/rgb.h"
#include "drivers/buttons.h"
#include "utils/uartstdio.h"
#include "led_task.h"
#include "priorities.h"
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "semphr.h"
#include "inc/hw_memmap.h"
#include "driverlib/debug.h"
#include "driverlib/gpio.h"
#include "driverlib/sysctl.h"
#include "LEDS.h"
#include "Buzzer.h"
#include "init.h"


#define BUZZER_DELAY        10


void Buzzer_init(void)
{
    // Enable the GPIO port that is used for the on-board LED.
    //
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOD);

    // Enable the GPIO pin for the LED (PF3).  Set the direction as output, and
    // enable the GPIO pin for digital function.
    //
    GPIOPinTypeGPIOOutput(GPIO_PORTD_BASE, GPIO_PIN_3);

}

void Buzzer_Task(void *Pvparameter)
{

   // portTickType ui32WakeTime;
    uint32_t ui32LEDToggleDelay;
   // uint8_t i8Message;

    //
    // Initialize the LED Toggle Delay to default value.
    //
    ui32LEDToggleDelay = BUZZER_DELAY;


    while(1)
    {
        if (!GPIOPinRead(GPIO_PORTD_BASE, GPIO_PIN_3))
        {
            GPIOPinWrite(GPIO_PORTD_BASE, GPIO_PIN_3, GPIO_PIN_3);
        }
        else if (GPIOPinRead(GPIO_PORTD_BASE, GPIO_PIN_3))
        {
            GPIOPinWrite(GPIO_PORTD_BASE, GPIO_PIN_3, 0x0);
        }
        vTaskDelay(ui32LEDToggleDelay );
    }

}
