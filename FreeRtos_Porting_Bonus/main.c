

/**
 * main.c
 */
#include <stdbool.h>
#include <stdint.h>
#include "inc/hw_memmap.h"
#include "inc/hw_types.h"
#include "driverlib/gpio.h"
#include "driverlib/pin_map.h"
#include "driverlib/rom.h"
#include "driverlib/sysctl.h"
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "semphr.h"
#include "event_groups.h"
#include "My_Tasks.h"

/*****************************************************************************/
/*****************************************************************************/
/**This hook is called by FreeRTOS when an stack overflow error is detected.**/
/*****************************************************************************/
/*****************************************************************************/
void vApplicationStackOverflowHook(xTaskHandle *pxTask, char *pcTaskName)
{
    /*
     This function can not return, so loop forever.  Interrupts are disabled
     on entry to this function, so no processor interrupts will interrupt
     this loop.
    */
    while(1)
    {
    }
}

int main(void)
{
    /*Set the clocking to run at 50 MHz from the PLL.*/
    ROM_SysCtlClockSet(SYSCTL_SYSDIV_4 | SYSCTL_USE_PLL | SYSCTL_XTAL_16MHZ |
                           SYSCTL_OSC_MAIN);

    /* Attempt to create the event group. */
    xBtnEventGroup = xEventGroupCreate();

    /* Was the event group created successfully? */
    if( xBtnEventGroup == NULL )
    {
        /* The event group was not created because there was insufficient
        FreeRTOS heap available. */
    }
    else
    {
        /* The event group was created. */
        /* Create Tasks */
        xTaskCreate(TaskInit,"Init_Task",100,NULL,4,NULL);
        xTaskCreate(Led_Task,"Led_Task",100,NULL,2,NULL);
        xTaskCreate(Btn1_Task,"Btn1_Task",100,NULL,2,NULL);
        xTaskCreate(Btn2_Task,"Btn2_Task",100,NULL,2,NULL);
        xTaskCreate(Lcd_Task,"Lcd_Task",configMINIMAL_STACK_SIZE,NULL,2,NULL);
        /* Start Schedular */
        vTaskStartScheduler();
    }


    while(1)
        {
        }
    return 0;
}
