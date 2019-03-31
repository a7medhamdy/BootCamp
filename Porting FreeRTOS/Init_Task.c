/*
 * Init_Task.c
 *
 *  Created on: Mar 18, 2019
 *      Author: AVE-LAP-071
 */

#include <stdbool.h>
#include <stdint.h>
#include "inc/hw_memmap.h"
#include "inc/hw_types.h"
#include "driverlib/gpio.h"
#include "driverlib/rom.h"
#include "driverlib/sysctl.h"
#include "priorities.h"
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "semphr.h"
#include "Init_Task.h"
#include "Includes/LCD.h"
#include "Includes/Button.h"
#include "inc/hw_memmap.h"
#include "inc/hw_types.h"
#include "inc/hw_gpio.h"

//*****************************************************************************
//
// Initializes the tasks.
//
//*****************************************************************************
void
TaskInit(void *pvParameters)
{
    while(1)
    {

        Button_Init();
        LCD_init();

       vTaskSuspend(NULL);
    }

}
