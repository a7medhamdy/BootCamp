/*
 * scheduler.c
 *
 * Created: 2/23/2019 3:54:15 PM
 *  Author: AVE-LAP-039
 */ 

#include "timer.h"
#include "scheduler.h"
#include "Types.h"

/*global variable changed by more than function (program scope)*/
volatile uint8 flag = INITIAL;

/*predefined array called which contains our tasks*/
extern void(*Tasks_Arr[TASKS_NUMBER])(void);


/***************** schedulerInit_AndStart() ******************
*Parameters:
*			I/P: NOTHING
*			O/P: NOTHING
*			I/O: NOTHING
*Return: Nothing
*Description: Function to initialize the scheduler by initialize 
			  timer1 and make flag = 0 when one tick occured
**************************************************************/
void schedulerInit_AndStart()
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
	for (i = ZERO; i<TASKS_NUMBER;i++)
	{
		(Tasks_Arr[i])();
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