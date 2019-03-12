

/**
 * main.c
 */

#include "Includes/TM4C123GH6PM.h"
#include "Includes/types.h"
#include "Includes/Tasks.h"
#include "Includes/Scheduler.h"
#include "Includes/Systick.h"
#include <stdint.h>
#include <stdbool.h>
#include "Includes/UART.h"


#define Task_Num 1
void main(void)
{
    /*Interrupt comes every one second*/
    UART0_init();
    /*Initialize The scheduler only one task*/
   schedulerInit(Task_Num);

    /*Initialize task0*/
    Tasks Task1;
    Tasks Task2;
    Tasks Task3;


    Task1.ptr_func = UArt_Check_Task;
    Task1.Task_Periodicity = 1;
    Task1.Remaining_Ticks  = 1;
    Task1.Piriority = 1;


    Task2.ptr_func = K2S_Task;
    Task2.Task_Periodicity = 50;
    Task2.Remaining_Ticks  = 50;
    Task2.Piriority = 1;


    Task3.ptr_func = Debouncing_Task;
    Task3.Task_Periodicity = 5;
    Task3.Remaining_Ticks  = 5;
    Task3.Piriority = 1;
    /*Adding Our Tasks*/
    if (scheduler_Add_Task(&Task1))
    {
        /*Task is added*/
    }
    else
    {
        /*No place to add Task*/
    }

    /*Adding Our Tasks*/
    if (scheduler_Add_Task(&Task2))
    {
        /*Task is added*/
    }
    else
    {
        /*No place to add Task*/
    }
    /*Adding Our Tasks*/
    if (scheduler_Add_Task(&Task3))
    {
        /*Task is added*/
    }
    else
    {
        /*No place to add Task*/
    }

    schedulerStart();

}
