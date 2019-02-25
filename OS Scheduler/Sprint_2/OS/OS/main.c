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
	/*Port initialization*/
	DIO_SetPinDirection(LED0,HIGH);
	DIO_SetPinDirection(LED1,HIGH);
	DIO_SetPinDirection(LED2,HIGH);
	DIO_SetPinDirection(LED3,HIGH);
	
	uint32 Periodicity_1 = 1000;
	uint32 Periodicity_2 = 2000;
	uint32 Periodicity_3 = 3000;
	uint32 Periodicity_4 = 4000;
	/*initialize array of Periodicities */
	uint32 arr_Periodicity[Task_Num]={Periodicity_1,Periodicity_2,Periodicity_3,Periodicity_4};
		
    /*Initialize The scheduler by Periodicities*/
	schedulerInit(Task_Num,arr_Periodicity);
	
	if (scheduler_Add_Task(Led0_Task))
	{
		/*Task is added*/
	}
	else
	{
		/*No place to add Task*/
	}
	scheduler_Add_Task(Led1_Task);
	scheduler_Add_Task(Led2_Task);
	scheduler_Add_Task(Led3_Task);

	/*Start the OS scheduler*/
	schedulerStart();
	
	
}

