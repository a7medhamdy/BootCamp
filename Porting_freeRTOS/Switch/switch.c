/*
 * switch.c
 *
 *  Created on: Mar 18, 2019
 *      Author: AVE-LAP-039
 */


#include <stdint.h>
#include <stdbool.h>
#include "inc/hw_types.h"
#include "inc/hw_memmap.h"
#include "inc/hw_gpio.h"
#include "driverlib/debug.h"
#include "driverlib/gpio.h"
#include "driverlib/sysctl.h"
#include "Includes/switch.h"
#include "FreeRTOS.h"
#include "task.h"
#include "driverlib/fpu.h"
#include "driverlib/pin_map.h"
#include "event_groups.h"


#define FALSE                0
#define TRUE                 1
#define DEBOUNCING_OK        5
#define SWITCH_DELAY         50
#define BIT_0   ( 1 << 0 )
#define BIT_4   ( 1 << 4 )
volatile uint8_t count = 0;
volatile uint8_t count2 = 0;
extern volatile uint8_t flag;
EventGroupHandle_t xCreatedEventGroup_button;

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

       /*initialize button 0*/
       HWREG(GPIO_PORTF_BASE+GPIO_O_LOCK) = GPIO_LOCK_KEY;
       HWREG(GPIO_PORTF_BASE+GPIO_O_CR) |= 0x01;
       GPIOPinTypeGPIOInput(GPIO_PORTF_BASE,GPIO_PIN_0);
       GPIOPadConfigSet(GPIO_PORTF_BASE ,GPIO_PIN_0,GPIO_STRENGTH_4MA,GPIO_PIN_TYPE_STD_WPU);
}


/************************************************************************/
/* Function: Button_Task                                                */
/* @param: void pointer                                                 */
/* return: void                                                         */
/* Description: button task                                             */
/************************************************************************/
void Button1_Task()
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
                xEventGroupSetBits(xCreatedEventGroup_button, BIT_4);
            }
       }
       /*Set the task periodicity*/
       vTaskDelay(SWITCH_DELAY);
    }
}


void Button2_Task()
{
    while (1){
        /*Read the button status*/
       if(GPIOPinRead(GPIO_PORTF_BASE,GPIO_PIN_0))
       {
           /*if button is not pressed set flag to 0*/
           flag = FALSE;
           count2 = TRUE;
       }
       else
       {
           /*if button is pressed check the debouncing*/
            count2++;
            if (count2 == DEBOUNCING_OK)
            {
                /*if debouncing is ok set the flag to high*/
                xEventGroupSetBits(xCreatedEventGroup_button, BIT_0);
            }
       }
       /*Set the task periodicity*/
       vTaskDelay(SWITCH_DELAY);
    }
}



