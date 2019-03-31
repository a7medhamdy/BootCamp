/*
 * My_Tasks.c
 *
 *  Created on: Mar 18, 2019
 *      Author: AVE-LAP-062
 */

#include <stdbool.h>
#include <stdint.h>
#include "inc/hw_memmap.h"
#include "inc/hw_types.h"
#include "driverlib/gpio.h"
#include "driverlib/rom.h"
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "semphr.h"
#include "event_groups.h"
#include "driverlib/sysctl.h"
#include "driverlib/debug.h"
#include "Leds.h"
#include "Btn.h"
#include "Lcd.h"

static uint8_t SBtn1State = 0 ;
static uint8_t SBtn2State = 0 ;
static uint8_t LedTaskPeriodicity = 100 ;
static uint8_t BtnTaskPeriodicity = 10 ;
static uint32_t Lcd_Periodicity = 200 ;

EventGroupHandle_t xBtnEventGroup;

#define BIT_0   ( 1 << 0 )
#define BIT_4   ( 1 << 4 )

uint8_t *Messages[4] = {"Led1 is on","Led2 is on ","Button1 Pressed","Button2 Pressed"};

/*******************************************************************/
/* TaskInit                                                        */
/* Parameters : N/A                                                */
/* I/p : N/A                                                       */
/* O/p : N/A                                                       */
/* Return : N/a                                                    */
/* Task that init modules                                          */
/*******************************************************************/
void TaskInit(void *pvParameters)
{
    while(1)
    {
        Leds_Init();
        Btns_Init();
        LCD_INIT();
        vTaskSuspend(NULL);
     }
}

/*******************************************************************/
/* Led_Task                                                        */
/* Parameters : N/A                                                */
/* I/p : N/A                                                       */
/* O/p : N/A                                                       */
/* Return : N/a                                                    */
/* Task that switch leds                                           */
/*******************************************************************/
void Led_Task(void *pvParameters)
{
    EventBits_t uxBits;
    const TickType_t xTicksToWait = 100 / portTICK_PERIOD_MS;

    while(1)
    {
        /* Wait a maximum of 100ms for either bit 0 or bit 4 to be set within
        the event group.  Clear the bits before exiting. */
        uxBits = xEventGroupWaitBits(
                  xBtnEventGroup,   /* The event group being tested. */
                  BIT_0 | BIT_4, /* The bits within the event group to wait for. */
                  pdTRUE,        /* BIT_0 & BIT_4 should be cleared before returning. */
                  pdFALSE,       /* Don't wait for both bits, either bit will do. */
                  xTicksToWait );/* Wait a maximum of 100ms for either bit to be set. */

        if( ( uxBits & BIT_0 ) != 0 )
        {
            Led1_Switch(LED1_ON);
        }
        else if( ( uxBits & BIT_4 ) != 0 )
        {
            Led1_Switch(LED1_ON);
        }
        else
        {
            Led1_Switch(LED1_OFF);
        }

        vTaskDelay(LedTaskPeriodicity);
    }
}

/*******************************************************************/
/* Btn1_Task                                                        */
/* Parameters : N/A                                                */
/* I/p : N/A                                                       */
/* O/p : N/A                                                       */
/* Return : N/a                                                    */
/* Task that read btn1                                             */
/*******************************************************************/
void Btn1_Task(void *pvParameters)
{
    while(1)
    {
        uint32_t Btn1_State ;
        /* Read BTN1 */
        Btn1_State = Btn1_Read();

        if(Btn1_State == BTN1_ON){
            //SBtn1State = 1 ;
            xEventGroupSetBits(xBtnEventGroup, BIT_4);
        }

        vTaskDelay(BtnTaskPeriodicity);
    }

}

/*******************************************************************/
/* Btn2_Task                                                        */
/* Parameters : N/A                                                */
/* I/p : N/A                                                       */
/* O/p : N/A                                                       */
/* Return : N/a                                                    */
/* Task that read btn2                                             */
/*******************************************************************/
void Btn2_Task(void *pvParameters)
{
    while(1)
    {
        uint32_t Btn2_State ;
        /* Read BTN1 */
        Btn2_State = Btn2_Read();

        if(Btn2_State == BTN1_ON){
            xEventGroupSetBits(xBtnEventGroup, BIT_0);
        }


        vTaskDelay(BtnTaskPeriodicity);
    }
}

/*******************************************************************/
/* Lcd_Task                                                        */
/* Parameters : N/A                                                */
/* I/p : N/A                                                       */
/* O/p : N/A                                                       */
/* Return : N/a                                                    */
/* Task that writes on lcd                                         */
/*******************************************************************/
void Lcd_Task(void *pvParameters)
{
    EventBits_t uxBits;
    const TickType_t xTicksToWait = 100 / portTICK_PERIOD_MS;

    while(1)
    {
        /* Wait a maximum of 100ms for either bit 0 or bit 4 to be set within
        the event group.  Clear the bits before exiting. */
        uxBits = xEventGroupWaitBits(
                  xBtnEventGroup,   /* The event group being tested. */
                  BIT_0 | BIT_4, /* The bits within the event group to wait for. */
                  pdTRUE,        /* BIT_0 & BIT_4 should be cleared before returning. */
                  pdFALSE,       /* Don't wait for both bits, either bit will do. */
                  xTicksToWait );/* Wait a maximum of 100ms for either bit to be set. */

        if( ( uxBits & BIT_0 ) != 0 )
        {
            LCD_sendString_RowCol(Messages[0],1,1);
            LCD_sendString_RowCol(Messages[2],2,1);
        }
        else if( ( uxBits & BIT_4 ) != 0 )
        {
            LCD_sendString_RowCol(Messages[1],1,1);
            LCD_sendString_RowCol(Messages[3],2,1);
        }
        else
        {
            LCD_Clear();
        }

        vTaskDelay(Lcd_Periodicity);
    }
}
