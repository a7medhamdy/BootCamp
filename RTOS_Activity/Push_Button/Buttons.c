/*
 * Buttons.c
 *
 *  Created on: Mar 13, 2019
 *      Author: AVE-LAP-039
 */
#include <stdint.h>
#include <stdbool.h>
#include "Includes/Button.h"
#include "inc/hw_types.h"
#include "driverlib/debug.h"
#include "driverlib/fpu.h"
#include "driverlib/gpio.h"
#include "driverlib/pin_map.h"
#include "driverlib/rom.h"
#include "driverlib/sysctl.h"
#include "driverlib/uart.h"
#include "utils/uartstdio.h"
#include "inc/hw_memmap.h"
#include "driverlib/ssi.h"
#include "Includes/bitwise_operation.h"


void Button_init(void)
{

       SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);
       while(!SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOF));
       GPIOPinTypeGPIOInput(GPIO_PORTF_BASE,GPIO_PIN_4);
       GPIOPadConfigSet(GPIO_PORTF_BASE ,GPIO_PIN_4,GPIO_STRENGTH_4MA,GPIO_PIN_TYPE_STD_WPU);
}



void Button_Task()
{
    if(GPIOPinRead(GPIO_PORTF_BASE, GPIO_PIN_4) == 1)
    {


    }
}



