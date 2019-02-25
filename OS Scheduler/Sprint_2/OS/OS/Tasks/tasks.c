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
		DIO_WritePin(LED1,LOW);
		DIO_WritePin(LED2,LOW);
		DIO_WritePin(LED3,LOW);
		DIO_WritePin(LED0,HIGH);
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
		DIO_WritePin(LED0,LOW);
		DIO_WritePin(LED2,LOW);
		DIO_WritePin(LED3,LOW);
		DIO_WritePin(LED1,HIGH);
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

	
		DIO_WritePin(LED2,HIGH);

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
		DIO_WritePin(LED0,LOW);
		DIO_WritePin(LED1,LOW);
		DIO_WritePin(LED2,LOW);
		DIO_WritePin(LED3,HIGH);
}