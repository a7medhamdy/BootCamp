/*
 * Button.c
 *
 *  Created on: Mar 13, 2019
 *      Author: AVE-LAP-071
 */
#include "FreeRTOS.h"
#include "event_groups.h"
#include "../Includes/Button.h"
#include "../Includes/CommonNumbers.h"
#include "inc/hw_memmap.h"
#include "inc/hw_types.h"
#include "inc/hw_gpio.h"

#include "task.h"
#include "queue.h"
#include "semphr.h"
#include "Includes/Button.h"
#include "Includes/CommonNumbers.h"
#include "event_groups.h"

#define BIT_0                ( 1 << 0 )
#define BIT_1                ( 1 << 1 )
#define BUTTON_1             0x01
#define LOW                  0
#define BUTTON_ONE_MESSAGE   1
#define DEBOUNCING1_OK        5
#define DEBOUNCING2_OK        5
#define BUTTON1_WASNT_PRESSED 1
#define BUTTON_ONE_DELAY     5

/*global variables*/
static volatile uint8_t count1 = LOW;
static volatile uint8_t count2 = LOW;
static volatile uint8_t check1 = LOW;
static volatile uint8_t check2 = LOW;

/*creat queue handler*/
QueueHandle_t xQueu;

/************************************************************************/
/* Function: Button_Init                                                */
/* @param: void                                                         */
/* return: void                                                         */
/* Description: This function initialize buttons pins                   */
/************************************************************************/

void Button_Init()
{
    /* Enable the GPIO port for keypad Columns.                             */
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);
    /* Check if the peripheral access is enabled.                           */
    while (!SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOF))
        ;

    /* Ports Directions                           */
    GPIOPinTypeGPIOInput(GPIO_PORTF_BASE, GPIO_PIN_0);
    GPIOPinTypeGPIOInput(GPIO_PORTF_BASE, GPIO_PIN_4);

    /* Enable Button 0                           */
    HWREG(GPIO_PORTF_BASE+GPIO_O_LOCK) = GPIO_LOCK_KEY;
    HWREG(GPIO_PORTF_BASE+GPIO_O_CR) |= BUTTON_1;

    /* Enable Pull Up                           */
    GPIOPadConfigSet(GPIO_PORTF_BASE, GPIO_PIN_4, GPIO_STRENGTH_2MA,
                     GPIO_PIN_TYPE_STD_WPU);
    GPIOPadConfigSet(GPIO_PORTF_BASE, GPIO_PIN_0, GPIO_STRENGTH_2MA,
                     GPIO_PIN_TYPE_STD_WPU);

}


/************************************************************************/
/* Function: Button1_read                                               */
/* @param: void                                                         */
/* return: uint32                                                       */
/* Description: This function read the value of button one              */
/*              and return its status                                   */
/************************************************************************/
uint32_t Button1_read()
{
    volatile uint32_t value_1 = NUM_0;

    /* Check if Button ONE is Pressed*/
    if (!GPIOPinRead(GPIO_PORTF_BASE, GPIO_PIN_4))
    {
        /* Set value equal to one*/
        value_1 = NUM_1;
    }
    /*return value of button ONE*/
    return value_1;
}

/************************************************************************/
/* Function: Button2_read                                               */
/* @param: void                                                         */
/* return: uint32                                                       */
/* Description: This function read the value of button two              */
/*              and return its status                                   */
/************************************************************************/
uint32_t Button2_read()
{
    volatile uint32_t value_2 = NUM_0;

    /* Check if Button two is Pressed*/
    if (!GPIOPinRead(GPIO_PORTF_BASE, GPIO_PIN_0))
    {
        /* Set value equal to one*/
        value_2 = NUM_2;
    }
    /*return value of button two*/
    return value_2;
}

/************************************************************************/
/* Function: Button1Task                                                */
/* @param: void pointer                                                 */
/* return: void                                                         */
/* Description: This task read the status of button one and             */
/*              check the debouncing, If it is pressed send message     */
/*              on the queue                                            */
/************************************************************************/
void Button1Task(void *pvParameters)
{

    uint8_t Button1Flag = LOW;
    while (1)
    {
        /*check the button status*/
        if (Button1_read())
        {
            /*increment the debouncing counter*/
            count1++;
            /*check if the button is pressed more than 25 ms and it wasn't pressed before*/
            if (count1 == DEBOUNCING1_OK && check1 == BUTTON1_WASNT_PRESSED)
            {
                /*creat unique message for button one pressed*/
                Button1Flag = BUTTON_ONE_MESSAGE;
                /*apply the message to the queue*/
                xQueueSendToBack(xQueu, &Button1Flag, 10);
                /*make all flag equal zero*/
                count1 = LOW;
                check1 = LOW;
            }

        }
        else
        {
            /*last status of button one wasn't pressed*/
            check1 = BUTTON1_WASNT_PRESSED;
            count1 = LOW;
        }
        /*make the task comes every 5 ms*/
        vTaskDelay(BUTTON_ONE_DELAY);

    }

}

/************************************************************************/
/* Function: Button2Task                                                */
/* @param: void pointer                                                 */
/* return: void                                                         */
/* Description: This task read the status of button two and             */
/*              check the debouncing, If it is pressed send message     */
/*              on the queue                                            */
/************************************************************************/
void Button2Task(void *pvParameters)
{
    uint8_t Button2Flag = 0;

    while (1)
    {
        /*check the button status*/
        if (Button2_read())
        {
            /*increment the debouncing counter*/
            count2++;
            /*check if the button is pressed more than 25 ms and it wasn't pressed before*/
            if (count2 == DEBOUNCING2_OK && check2 == 1)
            {
                /*creat unique message for button two pressed*/
                Button2Flag = 2;
                /*apply the message to the queue*/
                xQueueSendToBack(xQueu, &Button2Flag, 10);
                /*make all flag equal zero*/
                count2 = 0;
                check2 = 0;
            }

        }
        else
        {
            /*last status of button two wasn't pressed*/
            check2 = 1;
            count2 = 0;
        }
        /*make the task comes every 5 ms*/
        vTaskDelay(5);
    }

}
