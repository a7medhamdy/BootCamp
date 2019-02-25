/*
 * scheduler.c
 *
 * Created: 2/23/2019 3:54:15 PM
 *  Author: AVE-LAP-039
 */ 

#include "timer.h"
#include "Types.h"
#include "tasks.h"
#include "scheduler.h"


/*global variable changed by more than function (program scope)*/
volatile uint8 flag = INITIAL;

volatile uint32 index = ZERO;




/****************** scheduler_Add_Task() *********************
*Parameters:
*			I/P: Pointer to function
*			O/P: NOTHING
*			I/O: NOTHING
*Return: Nothing
*Description: This Function extend the array with the new task
**************************************************************/

uint8 scheduler_Add_Task(void(*ptr)(void))
{
	uint8 ret = TRUE;
	if (index < MAX_TASK_NUMBER)
	{
		Tasks_Arr[index].ptr_func=ptr;
		index++;
		ret = TRUE;
	}
	else
	{
		ret = FALSE;
	}
	return ret;
}

/********************** schedulerInitt() *********************
*Parameters:
*			I/P: Tasks Number, Array of Periodicities
*			O/P: NOTHING
*			I/O: NOTHING
*Return: Nothing
*Description: This Function set the periodicity of each task
			  and calculate the remaining ticks
**************************************************************/

void schedulerInit(uint32 Task_Num,uint32 *arr)
{
	uint32 i = ZERO;
	for (i=ZERO;i<Task_Num;i++)
	{
		Tasks_Arr[i].Task_Periodicity = arr[i];
		Tasks_Arr[i].Remaining_Ticks = Tasks_Arr[i].Task_Periodicity;
	}
}

/******************** schedulerStart() ***********************
*Parameters:
*			I/P: NOTHING
*			O/P: NOTHING
*			I/O: NOTHING
*Return: Nothing
*Description: This Function Starts the OS scheduler 
**************************************************************/

void schedulerStart()
{
	timer_init();
	set_call_back(set_flag);
	while(TRUE)
	{
		if(flag==ONE)
		{
			flag=ZERO;
			/*Call the TCC Scheduler*/
			TTC_Scheduler();
		}
	}
}

/********************* TTC_Scheduler() ************************
*Parameters:
*			I/P: NOTHING
*			O/P: NOTHING
*			I/O: NOTHING
*Return: Nothing
*Description: This Function has the Algorithm that choose which
			  task to be executed
**************************************************************/
void TTC_Scheduler(void)
{
	uint8 i = ZERO;
	for (i = ZERO; i<index;i++)
	{
		Tasks_Arr[i].Remaining_Ticks--;
		if(Tasks_Arr[i].Remaining_Ticks==ZERO)
		{
			Tasks_Arr[i].ptr_func();
			Tasks_Arr[i].Remaining_Ticks = Tasks_Arr[i].Task_Periodicity;
			
		}
	}
}

/*********************** set_flag () **************************
*Parameters:
*			I/P: NOTHING
*			O/P: NOTHING
*			I/O: NOTHING
*Return: Nothing
*Description: This Function Set flag to High When After 
			  ISR execution
**************************************************************/
void set_flag(void)
{
	flag = ONE;
}