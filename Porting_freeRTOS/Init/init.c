/*
 * init.c
 *
 *  Created on: Mar 13, 2019
 *      Author: AVE-LAP-039
 */


#include <stdbool.h>
#include <stdint.h>
#include "FreeRTOS.h"
#include "task.h"
#include "Includes/LEDS.h"
#include "Includes/init.h"
#include "Includes/switch.h"


/************************************************************************/
/* Function: init_task                                                  */
/* @param: void pointer                                                 */
/* return: void                                                         */
/* Description: Task to initialize board                                */
/************************************************************************/
void init_task(void *p)
{
    while(1)
    {
        /*call button init function*/
        Button_init();
        /*call led init function*/
        LEDs_init();
        /*suspend the init task*/
        vTaskSuspend(NULL);
    }
}


