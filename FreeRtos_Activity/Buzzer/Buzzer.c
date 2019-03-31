/*
 * Buzzer.c
 *
 *  Created on: Mar 13, 2019
 *      Author: AVE-LAP-039
 */

#include "Includes/Buzzer.h"
#include <stdint.h>
#include <stdbool.h>
#include "inc/hw_memmap.h"
#include "driverlib/debug.h"
#include "driverlib/gpio.h"
#include "driverlib/sysctl.h"
#include "Includes/LEDS.h"


extern volatile uint8_t LED1_flag;
extern volatile uint8_t LED2_flag;
extern volatile uint8_t LCD_flag;

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

void Buzzer_sound(void)
{
    if (!GPIOPinRead(GPIO_PORTD_BASE, GPIO_PIN_3))
    {
        GPIOPinWrite(GPIO_PORTD_BASE, GPIO_PIN_3, GPIO_PIN_3);
    }
    else if (GPIOPinRead(GPIO_PORTD_BASE, GPIO_PIN_3))
    {
        GPIOPinWrite(GPIO_PORTD_BASE, GPIO_PIN_3, 0x0);
    }
    LED1_flag++;
    LED2_flag++;
    LCD_flag++;
}
