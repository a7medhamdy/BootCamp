

/**
 * main.c
 */
#include "Includes/LEDs.h"
#include "Includes/LCD.h"
#include "Includes/Buzzer.h"
#include "Includes/SysTick.h"
#include <stdbool.h>
#include <stdint.h>
#include "inc/hw_memmap.h"
#include "inc/hw_types.h"
#include "driverlib/gpio.h"
#include "driverlib/rom.h"
//#include "drivers/rgb.h"
#include "drivers/buttons.h"
#include "utils/uartstdio.h"
#include "led_task.h"
#include "priorities.h"
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "semphr.h"


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
#include "led_task.h"
#include "switch_task.h"
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "semphr.h"



volatile uint8_t LED1_flag = 0;
volatile uint8_t LED2_flag = 0;
volatile uint8_t LCD_flag = 0;


void main(void)
{
    LEDs_init();
    LCD_init();
    Buzzer_init();


    xTaskCreate( LED1_Toggle,
                             const char * const pcName,
                             configSTACK_DEPTH_TYPE usStackDepth,
                             void *pvParameters,
                             UBaseType_t uxPriority,
                             TaskHandle_t *pxCreatedTask
                           );
    xTaskCreate(LED1_Toggle, (const portCHAR *)"LED", 128 , NULL,
                0U  + 1, NULL) != 1)
}


