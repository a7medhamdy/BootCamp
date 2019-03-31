

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
#include "driverlib/uart.h"
#include "utils/uartstdio.h"
#include "priorities.h"
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "semphr.h"
#include "Init_Task.h"
#include "event_groups.h"
#include "Includes/Button.h"
#include "Includes/LCD.h"
#include "Includes/Button.h"



int main(void)
{


    /*Creat init task*/
    xTaskCreate(TaskInit, "TaskInit", 200, NULL,PRIORITY_TASKINIT_TASK, NULL);
    /*Creat button one task*/
    xTaskCreate(Button1Task,"Button1task", 128, NULL,PRIORITY_BUTTON1_TASK, NULL);
    /*Creat button two task*/
    xTaskCreate(Button2Task,"Button2task", 128, NULL,PRIORITY_BUTTON2_TASK, NULL);
    /*Creat LCD task*/
    xTaskCreate(LCDTask, "LCDtask", 200, NULL,PRIORITY_LCD_TASK, NULL);
    /*Creat Queue to communicate between tasks*/
    xQueu = xQueueCreate(10,sizeof(uint8_t));
    /*start scheduler*/
    vTaskStartScheduler();
	return 0;
}
