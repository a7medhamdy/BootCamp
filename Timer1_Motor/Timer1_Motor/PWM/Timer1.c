/*
 * Timer1.c
 *
 * Created: 2/21/2019 1:57:05 PM
 *  Author: AVE-LAP-039
 */ 

#include "Types.h"
#include "Timer1_cfg.h"
#include "Timer1.h"
#include "DIO.h"
#include "BitwiseOperation.h"

void Timer1_Init()
{
	/*Set Motors pins direction*/
	DIO_SetPinDirection(OC1A,HIGH);
	DIO_SetPinDirection(OC1B,HIGH);
	DIO_SetPinDirection(DIR_1A,HIGH);
	DIO_SetPinDirection(DIR_1B,HIGH);
	DIO_SetPinDirection(DIR_2A,HIGH);
	DIO_SetPinDirection(DIR_2B,HIGH);
	/*Set direction of motors*/
	DIO_WritePin(DIR_1A,HIGH);
	DIO_WritePin(DIR_2A,HIGH);
	DIO_WritePin(DIR_1B,LOW);
	DIO_WritePin(DIR_2B,LOW);
	
	#ifdef FAST_PWM
	/*Fast PWM (MODE-14)*/
	CLEAR_BIT(TCCR1A,WGM10);
	SET_BIT(TCCR1A,WGM11);
	SET_BIT(TCCR1B,WGM12);
	SET_BIT(TCCR1B,WGM13);
	

	
	/*Set Mode Inverting or Non Inverting*/
	#ifdef NON_INVERTING_MODE
	SET_BIT(TCCR1A,COM1A1);
	SET_BIT(TCCR1A,COM1B1);
	CLEAR_BIT(TCCR1A,COM1A0);
	CLEAR_BIT(TCCR1A,COM1B0);
	/*Set prescalar =1*/
	SET_BIT(TCCR1B,CS10);
	CLEAR_BIT(TCCR1B,CS11);
	CLEAR_BIT(TCCR1B,CS12);
	#endif
	#ifdef INVERTING_MODE
	SET_BIT(TCCR1A,COM1A1);
	SET_BIT(TCCR1A,COM1B1);
	SET_BIT(TCCR1A,COM1A0);
	SET_BIT(TCCR1A,COM1B0);
	/*Set prescalar =1*/
	SET_BIT(TCCR1B,CS10);
	CLEAR_BIT(TCCR1B,CS11);
	CLEAR_BIT(TCCR1B,CS12);
	
	#endif
	#endif
	#ifdef PHASE_CORRECT_PWM
	/*Fast Phase correct (MODE-10)*/
	CLEAR_BIT(TCCR1A,WGM10);
	SET_BIT(TCCR1A,WGM11);
	CLEAR_BIT(TCCR1B,WGM12);
	SET_BIT(TCCR1B,WGM13);
	#ifdef NON_INVERTING_MODE
	SET_BIT(TCCR1A,COM1A1);
	SET_BIT(TCCR1A,COM1B1);
	CLEAR_BIT(TCCR1A,COM1A0);
	CLEAR_BIT(TCCR1A,COM1B0);
	/*Set prescalar =1*/
	SET_BIT(TCCR1B,CS10);
	CLEAR_BIT(TCCR1B,CS11);
	CLEAR_BIT(TCCR1B,CS12);
	#endif
	
	#ifdef INVERTING_MODE
	SET_BIT(TCCR1A,COM1A1);
	SET_BIT(TCCR1A,COM1B1);
	SET_BIT(TCCR1A,COM1A0);
	SET_BIT(TCCR1A,COM1B0);
	SET_BIT(TCCR1B,CS10);
	CLEAR_BIT(TCCR1B,CS11);
	CLEAR_BIT(TCCR1B,CS12);
	#endif
	
	#endif
	
	
}


void Timer1_PWM(uint8 duty_cycle,uint32 frequency)
{
	uint16 Top_Value;
	uint16 Compare_Value;
	
	#ifdef FAST_PWM
	#ifdef NON_INVERTING_MODE
	Top_Value = (F_CPU/frequency) - ONE;
	Compare_Value = ((Top_Value+ONE)/PERCENTAGE)*(duty_cycle);
	/*Set OCR*/
	OCR1BH = Compare_Value >> SHIFT_EIGHT;
	OCR1BL = Compare_Value & LOW_MASK;
	/*Set Top value*/
	ICR1H = (Top_Value & HIGH_MASK) >> SHIFT_EIGHT;
	ICR1L = Top_Value & LOW_MASK;
	#endif
	
    #ifdef INVERTING_MODE
	Top_Value = (F_CPU/TWO*frequency);
	Compare_Value = (Top_Value/PERCENTAGE)*(PERCENTAGE-duty_cycle) ;
	/*Set OCR*/
	OCR1BH = Compare_Value >> SHIFT_EIGHT;
	OCR1BL = Compare_Value & LOW_MASK;
	/*Set Top value*/
	ICR1H = (Top_Value & HIGH_MASK) >> SHIFT_EIGHT;
	ICR1L = Top_Value & LOW_MASK;
	#endif
	
	#endif
	
	#ifdef PHASE_CORRECT_PWM
	#ifdef NON_INVERTING_MODE
	Top_Value = (F_CPU/(frequency)) - ONE;
	Compare_Value = ((Top_Value+1)/PERCENTAGE)*(duty_cycle);
	/*Set OCR*/
	OCR1BH = Compare_Value >> SHIFT_EIGHT;
	OCR1BL = Compare_Value & LOW_MASK;
	/*Set Top value*/
	ICR1H = (Top_Value & HIGH_MASK) >> SHIFT_EIGHT;
	ICR1L = Top_Value & LOW_MASK;
	#endif
	
	#ifdef INVERTING_MODE
	Top_Value = (F_CPU/(2*frequency)) - ONE;
	Compare_Value = (Top_Value/PERCENTAGE)*(PERCENTAGE-duty_cycle);
	/*Set OCR*/
	OCR1BH = Compare_Value >> SHIFT_EIGHT;
	OCR1BL = Compare_Value & LOW_MASK;
	/*Set Top value*/
	ICR1H = (Top_Value & HIGH_MASK) >> SHIFT_EIGHT;
	ICR1L = Top_Value & LOW_MASK;
	#endif
	#endif
}


