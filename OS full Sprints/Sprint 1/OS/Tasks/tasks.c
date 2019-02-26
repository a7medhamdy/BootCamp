/*
 * tasks.c
 *
 * Created: 2/23/2019 3:55:28 PM
 *  Author: AVE-LAP-039
 */ 
#include "tasks.h"
#include "Types.h"
#include "DIO.h"

/*Declaration of array of pointers to function*/
void(*ptr[TASKS_NUMBER])(void);

/*Initialze the array of pointers to function by the addresses of tasks*/
void(*Tasks_Arr[TASKS_NUMBER])(void)= {Led0_Task,Led1_Task,Led2_Task,Led3_Task};
	


/*********************** Led0_Task() *************************
*Parameters:
*			I/P: NOTHING
*			O/P: NOTHING
*			I/O: NOTHING
*Return: Nothing
*Description: Function to Set LED0
**************************************************************/
void Led0_Task()
{
	static uint16 counter = INITIAL;
	if (counter == PERIODICITY_0)
	{
		DIO_WritePin(LED1,LOW);
		DIO_WritePin(LED2,LOW);
		DIO_WritePin(LED3,LOW);
		DIO_WritePin(LED0,HIGH);
		
		counter = INITIAL;
	}
	
	else 
	{
		counter ++;
	}
}

/*********************** Led1_Task() *************************
*Parameters:
*			I/P: NOTHING
*			O/P: NOTHING
*			I/O: NOTHING
*Return: Nothing
*Description: Function to Set LED1
**************************************************************/
void Led1_Task()
{
	static uint16 counter= INITIAL;
	if (counter == PERIODICITY_1)
	{
		DIO_WritePin(LED0,LOW);
		DIO_WritePin(LED2,LOW);
		DIO_WritePin(LED3,LOW);
		DIO_WritePin(LED1,HIGH);
		counter = INITIAL;
	}
	else
	{
		counter++;
	}
}

/*********************** Led2_Task() *************************
*Parameters:
*			I/P: NOTHING
*			O/P: NOTHING
*			I/O: NOTHING
*Return: Nothing
*Description: Function to Set LED2
**************************************************************/
void Led2_Task()
{
	static uint16 counter=INITIAL;
	if (counter == PERIODICITY_2)
	{
		DIO_WritePin(LED0,LOW);
		DIO_WritePin(LED1,LOW);
		DIO_WritePin(LED3,LOW);
		DIO_WritePin(LED2,HIGH);
		counter = INITIAL;
	}
	else
	{
		counter++;
	}
}

/*********************** Led3_Task() *************************
*Parameters:
*			I/P: NOTHING
*			O/P: NOTHING
*			I/O: NOTHING
*Return: Nothing
*Description: Function to Set LED3
**************************************************************/
void Led3_Task()
{
	static uint16 counter=INITIAL;
	if (counter == PERIODICITY_3)
	{
		DIO_WritePin(LED3,HIGH);
		DIO_WritePin(LED0,LOW);
		DIO_WritePin(LED1,LOW);
		DIO_WritePin(LED2,LOW);
		counter = INITIAL;
	}
	else
	{
		counter++;
	}

}