/*
 * tasks.c
 *
 * Created: 2/23/2019 3:55:28 PM
 *  Author: AVE-LAP-039
 */ 
#include "tasks.h"
#include "Types.h"
#include "DIO.h"
#include "scheduler.h"


void(*ptr[MAX_TASK_NUMBER])(void);


/*********************** Init_Tasks() *************************
*Parameters:
*			I/P: NOTHING
*			O/P: NOTHING
*			I/O: NOTHING
*Return: Nothing
*Description: Function to Set LED0
**************************************************************/
void Init_Tasks(void)
{
		DIO_SetPinDirection(LED0,HIGH);
		DIO_SetPinDirection(LED1,HIGH);
		DIO_SetPinDirection(LED2,HIGH);
		DIO_SetPinDirection(LED3,HIGH);
		DIO_SetPinDirection(BUTTON0,LOW);
}



/*********************** Led0_Task() *************************
*Parameters:
*			I/P: NOTHING
*			O/P: NOTHING
*			I/O: NOTHING
*Return: Nothing
*Description: Function to Set LED0
**************************************************************/
void Led0_Task(void)
{
		if(DIO_ReadPin(LED0))
		{
			DIO_WritePin(LED0,LOW);
		}
		else
		{
			DIO_WritePin(LED0,HIGH);
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

		if(DIO_ReadPin(LED1))
		{
			DIO_WritePin(LED1,LOW);
		}
		else
		{
			DIO_WritePin(LED1,HIGH);
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
	if(DIO_ReadPin(LED2))
	{
		DIO_WritePin(LED2,LOW);
	}
	else
	{
		DIO_WritePin(LED2,HIGH);
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
	if(DIO_ReadPin(LED3))
	{
		DIO_WritePin(LED3,LOW);
	}
	else
	{
		DIO_WritePin(LED3,HIGH);
	}
}

