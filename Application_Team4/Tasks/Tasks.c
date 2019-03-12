/*
 * Tasks.c
 *
 *  Created on: Mar 12, 2019
 *      Author: Ahmed Hamdy
 */


#include "Includes/tasks.h"
#include "Includes/types.h"
#include "Includes/scheduler.h"
#include "Includes/TM4C123GH6PM.h"
#include "Includes/CommonNumbers.h"
#include "Includes/Keypad_cfg.h"
#include "Includes/CommonDefinations.h"
#include "Includes/Keypad.h"
#include "Includes/UART.h"


/* Global Debouncing Flag */
volatile uint8 Deb_Flag = NUM_0;
volatile uint8 Deb  = NUM_0;
volatile uint8 Data=ZERO;
extern uint8 uart_transmit_fifnish;
volatile uint8 k2s_flag = 0;


/*********************** UArt_Check_Task() *************************
*Parameters:
*           I/P: NOTHING
*           O/P: NOTHING
*           I/O: NOTHING
*Return: Nothing
*Description: Function to check UART send is done
**************************************************************/
void UArt_Check_Task(void)
{
   if (k2s_flag==ONE)
   {
       UART0_TransmitCheck();
       if(uart_transmit_fifnish==ONE)
       {
           k2s_flag=ZERO;
           uart_transmit_fifnish=ZERO;
       }
   }
}





/*********************** K2S_Task() *************************
*Parameters:
*           I/P: NOTHING
*           O/P: NOTHING
*           I/O: NOTHING
*Return: Nothing
*Description: Function to get keypad value and send it by UART
**************************************************************/
void K2S_Task(void)
{
    if (Deb_Flag==HIGH && uart_transmit_fifnish==ZERO)
    {

        Data=Keypad_Task();
        UART0_TransmitStart(Data);
        k2s_flag = ONE;

    }
}



/************************************************************************/
/* Function: Debouncing_Task                                             */
/* @param: void                                                         */
/* return: void                                                         */
/* Description: check for Debouncing                      */
/************************************************************************/
void Debouncing_Task(void)
{

    /* Check for value input read from the rows*/
    if(!GPIOPinRead(ROW_BASE_PORT, ROW1_PIN | ROW2_PIN | ROW3_PIN ))
    {

        Deb++;

        if(Deb>=NUM_5)
        {
            Deb_Flag=NUM_1;        /* Set the debouncing flag */
        }

    }
    else
    {
        Deb = ZERO;
        Deb_Flag= ZERO;     /* reset the debouncing flag */
    }

}



