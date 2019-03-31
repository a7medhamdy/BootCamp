/*
 * switch.c
 *
 *  Created on: Mar 18, 2019
 *      Author: AVE-LAP-039
 */


#include <stdint.h>
#include <stdbool.h>
#include "inc/hw_memmap.h"
#include "driverlib/debug.h"
#include "driverlib/gpio.h"
#include "driverlib/sysctl.h"
#include "Includes/switch.h"
#include "FreeRTOS.h"
#include "task.h"

#define FALSE                0
#define TRUE                 1
#define DEBOUNCING_OK        5
#define SWITCH_DELAY         50

volatile uint8_t count = 0;
extern volatile uint8_t flag;

/************************************************************************/
/* Function: Button_init                                                */
/* @param: void pointer                                                 */
/* return: void                                                         */
/* Description: Task to initialize button                               */
/************************************************************************/
void Button_init(void)
{
        /*set clock to portF*/
       SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);
       while(!SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOF));
       /*set direction of switch as input*/
       GPIOPinTypeGPIOInput(GPIO_PORTF_BASE,GPIO_PIN_4);
       /*set pullup*/
       GPIOPadConfigSet(GPIO_PORTF_BASE ,GPIO_PIN_4,GPIO_STRENGTH_4MA,GPIO_PIN_TYPE_STD_WPU);
}


/************************************************************************/
/* Function: Button_Task                                                */
/* @param: void pointer                                                 */
/* return: void                                                         */
/* Description: button task                                             */
/************************************************************************/
void Button_Task()
{
    while (1){
        /*Read the button status*/
       if(GPIOPinRead(GPIO_PORTF_BASE,GPIO_PIN_4))
       {
           /*if button is not pressed set flag to 0*/
           flag = FALSE;
           count = TRUE;
       }
       else
       {
           /*if button is pressed check the debouncing*/
            count++;
            if (count == DEBOUNCING_OK)
            {
                /*if debouncing is ok set the flag to high*/
                flag = TRUE;
            }
       }
       /*Set the task periodicity*/
       vTaskDelay(SWITCH_DELAY);
    }
}
