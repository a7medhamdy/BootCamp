/*
 * timer.c
 *
 * Created: 2/23/2019 4:33:08 PM
 *  Author: AVE-LAP-039
 */ 
#include "Types.h"
#include "Timer_cfg.h"
#include "Timer.h"
#include "DIO.h"
#include "BitwiseOperation.h"
#include "tasks.h"
#include <avr/interrupt.h>

/*Array of pointer to functions which containes Tasks*/
extern void(*ptr[MAX_TASK_NUMBER])(void);

/*Pointer to function which we use in call back function principle*/
void(*call_back)(void);


/*********************** timer_init() ************************
*Parameters:
*			I/P: NOTHING
*			O/P: NOTHING
*			I/O: NOTHING
*Return: Nothing
*Description: This function Initialize timer-1 by 1 ms
**************************************************************/

void timer_init()
{
	/*Timer1 CTC MODE (MODE-4)*/
	CLEAR_BIT(TCCR1A,WGM10);
	CLEAR_BIT(TCCR1A,WGM11);
	SET_BIT(TCCR1B,WGM12);
	CLEAR_BIT(TCCR1B,WGM13);
	
	/*set OCR = 16000*/
	OCR1AH = Compare_Value >> SHIFT_EIGHT;
	OCR1AL = Compare_Value & LOW_MASK;
	
	/*Set prescalar =1*/
	SET_BIT(TCCR1B,CS10);
	CLEAR_BIT(TCCR1B,CS11);
	CLEAR_BIT(TCCR1B,CS12);
	
	/*enable global interrupt */
	SET_BIT(SREG_INTERRUPT,I);
	
	/*set timer CTC flag */
	SET_BIT(TIMER_TIMSK,OCIE1A);
}


/******************** set_call_back() ************************
*Parameters:
*			I/P: Pointer To Function
*			O/P: NOTHING
*			I/O: NOTHING
*Return: Nothing
*Description: This function sets call back pointer to function
			  to equal the input pointer to function
**************************************************************/
void set_call_back(void(*ptr)(void))
{
	call_back=ptr;
}

/* The ISR of CTC INT of Timer-1 */
ISR(TIMER1_COMPA_vect)
{
		call_back();
}