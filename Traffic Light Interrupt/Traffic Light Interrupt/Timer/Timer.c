/*
 * Timer.c
 *
 * Created: 2/14/2019 9:31:54 AM
 *  Author: AVE-LAP-039
 */ 
#include "Timer.h"
#include "Timer_Cfg.h"
#include "Interrupt_cfg.h"
#include <avr/interrupt.h>
#include "BitwiseOperation.h"
#include "DIO.h"


volatile static uint32 counter =ZERO;
extern volatile uint8 flag;

/*declaration of Global intterupt enable function*/
void Enable_Global_Interrupt();

void Timer_Init()
{
	/*Set Timer MOde & prescaler*/
	TIMER_TCCR0 = TIMER_CONTROL_VALUE;
	/*Set Timer initial value*/
	TIMER_TCNT0 = TIMER_TCNT_VALUE;
	/*Set Timer out compare value*/
	TIMER_OCR0 = TIMER_OCR_VALUE;
	SET_BIT(TIMER_TIMSK,OCIE0);
	
	/*Ext INT INIT*/
	SET_BIT(GICR_INTERRUPT,INT2);
}

/*function to enable global interrupt*/
void Enable_Global_Interrupt()
{
	SET_BIT(SREG_INTERRUPT,SEVEN);
}

/*OCR interrupt service routine*/
ISR(TIMER0_COMP_vect)
{
	if(counter < ONE_MS)
	{
		counter++;
	}
	else
	{
		counter=ZERO;
		flag++;
	}
	Enable_Global_Interrupt();
}

/*External Interrupt ISR*/
ISR(INT2_vect)
{
		flag = FOUR;
		counter = ZERO;
		Enable_Global_Interrupt();
}