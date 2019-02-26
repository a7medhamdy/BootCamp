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
#include "DIO.h"
#include <stdio.h>


/*global variables changed by more than function (program scope)*/
volatile uint8 flag = INITIAL;
volatile uint32 global_index = ZERO;
volatile uint32 task_num;

/*declaration of static function (file scope)*/
static void sorting ();
static void scheduler_Remove_Task ();

/****************** scheduler_Add_Task() *********************
*Parameters:
*			I/P: Pointer to function
*			O/P: NOTHING
*			I/O: NOTHING
*Return: Nothing
*Description: This Function extend the array with the new task
**************************************************************/

uint8 scheduler_Add_Task(Tasks *S_ptr)
{
	uint8 ret = TRUE;
	if (global_index < MAX_TASK_NUMBER)
	{
		Tasks_Arr[global_index].ptr_func = S_ptr->ptr_func;
		Tasks_Arr[global_index].Task_Periodicity = S_ptr->Task_Periodicity;
		Tasks_Arr[global_index].Remaining_Ticks = S_ptr->Remaining_Ticks;
		Tasks_Arr[global_index].Piriority = S_ptr->Piriority;
		
		global_index++;
		
		/*Sort the array*/
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

void schedulerInit(uint32 Task_Num)
{
	task_num = Task_Num;
	uint32 index_1 = INITIAL;
	for (index_1=INITIAL;index_1<Task_Num;index_1++)
	{
		Tasks_Arr[index_1].ptr_func = NULL;
		Tasks_Arr[index_1].Task_Periodicity = INITIAL;
		Tasks_Arr[index_1].Remaining_Ticks = INITIAL;
		Tasks_Arr[index_1].Piriority = INITIAL;
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
	/*Sort the array of task based on priorities*/
	sorting ();
	/*initialize the timer*/
	timer_init();
	/*call the set flag function based on ISR using call back mechanism*/
	set_call_back(set_flag);
	while(TRUE)
	{
		scheduler_Remove_Task();
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
	
	for (i = ZERO; i<global_index;i++)
	{
		Tasks_Arr[i].Remaining_Ticks--;
		if((Tasks_Arr[i].Remaining_Ticks==ZERO) && (Tasks_Arr[i].Piriority<NOT_AVAILABLE_PRIORITY))
		{
			
			Tasks_Arr[i].ptr_func();
			Tasks_Arr[i].Remaining_Ticks = Tasks_Arr[i].Task_Periodicity;
			
		}
		else
		{
			/*Nothing to do*/
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


/*********************** Sorting () **************************
*Parameters:
*			I/P: NOTHING
*			O/P: NOTHING
*			I/O: NOTHING
*Return: Nothing
*Description: This Function sort an array of structs
**************************************************************/
static void sorting ()
{
	uint32 counter1 = INITIAL, counter2 = INITIAL;
	Tasks temp;
	for(counter1 = INITIAL; counter1 < global_index; counter1++)
	{
		for (counter2 = ONE; counter2 < global_index; counter2++)
		{
			if (Tasks_Arr[counter2].Piriority < Tasks_Arr[counter2-ONE].Piriority)
			{
				temp = Tasks_Arr[counter2];
				Tasks_Arr[counter2] = Tasks_Arr[counter2-ONE];
				Tasks_Arr[counter2-ONE] = temp;
			}
			else
			{
				/*Nothing to do*/
			}
		}
	}
	
}

/***************** scheduler_Remove_Task () ******************
*Parameters:
*			I/P: NOTHING
*			O/P: NOTHING
*			I/O: NOTHING
*Return: Nothing
*Description: This Function remove task at run time
**************************************************************/

static void scheduler_Remove_Task ()
{
	if (DIO_ReadPin(BUTTON0))
	{
		
		 Tasks_Arr[global_index-ONE].Piriority = NOT_AVAILABLE_PRIORITY;
	}
	
}