/*
 * OS.c
 *
 * Created: 2/23/2019 3:35:18 PM
 * Author : AVE-LAP-039
 */ 

#include <avr/io.h>
#include "Types.h"
#include "DIO.h"
#include "tasks.h"
#include "scheduler.h"
#include "timer.h"

#define Task_Num 4

int main(void)
{
	/*Set the Port initialization*/
	Init_Tasks	();
	
	
	/*Initialize The scheduler*/
	schedulerInit(Task_Num);
	
	Tasks Task0;
	Tasks Task1;
	Tasks Task2;
	Tasks Task3;
	
	Task0.ptr_func = Led0_Task;
	Task0.Task_Periodicity = 1000;
	Task0.Remaining_Ticks  = 1000;
	Task0.Piriority = 1;
	
	Task1.ptr_func = Led1_Task;
	Task1.Task_Periodicity = 2000;
	Task1.Remaining_Ticks  = 2000;
	Task1.Piriority = 0;
	
	Task2.ptr_func = Led2_Task;
	Task2.Task_Periodicity = 3000;
	Task2.Remaining_Ticks  = 3000;
	Task2.Piriority = 3;
	
	Task3.ptr_func = Led3_Task;
	Task3.Task_Periodicity = 4000;
	Task3.Remaining_Ticks  = 4000;
	Task3.Piriority = 4;
	
		
    /*Initialize The scheduler by Periodicities*/
	
	
	if (scheduler_Add_Task(&Task0))
	{
		/*Task is added*/
	}
	else
	{
		/*No place to add Task*/
	}
	scheduler_Add_Task(&Task1);
	scheduler_Add_Task(&Task2);
	scheduler_Add_Task(&Task3);

	/*Start the OS scheduler*/
	schedulerStart();
	
	
}

