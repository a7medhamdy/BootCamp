

/**
 * main.c
 */

#include <stdbool.h>
#include <stdint.h>
#include "FreeRTOS.h"
#include "task.h"
#include "Includes/init.h"
#include "Includes/LEDS.h"
#include "Includes/switch.h"


int main(void)
{
    /*Creating the init task*/
    xTaskCreate( init_task, (const portCHAR *)"INIT", 128, NULL,
                    tskIDLE_PRIORITY + 10, NULL);
    /*Creating the Led task*/
    xTaskCreate(LED1_Task, (const portCHAR *)"LED1", 128, NULL,
                        tskIDLE_PRIORITY + 8, NULL);
    /*Creating the switch task*/
    xTaskCreate(Button_Task, (const portCHAR *)"switch", 128, NULL,
                            tskIDLE_PRIORITY + 9, NULL);
    /*start scheduler*/
    vTaskStartScheduler();

	return 0;
}
