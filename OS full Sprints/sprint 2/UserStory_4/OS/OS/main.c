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
	
	/*initialize structures data*/
	Tasks Task0 = {Led0_Task,2500,2500,1};
	Tasks Task1 = {Led1_Task,1500,1500,0};
	Tasks Task2 = {Led2_Task,2000,2000,2};
	Tasks Task3 = {Led3_Task,1000,1000,3};
	
		
	/*Check if there the task is added or not*/
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

