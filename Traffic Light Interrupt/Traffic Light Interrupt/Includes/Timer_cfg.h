/*
 * Timer_Confg.h
 *
 * Created: 2/21/2019 12:53:10 AM
 *  Author: AVE-LAP-039
 */ 


#ifndef TIMER_CONFG_H_
#define TIMER_CONFG_H_


#define TIMER_TCCR0 (*(volatile ptr8)(0x53))
#define TIMER_TCNT0 (*(volatile ptr8)(0x52))
#define TIMER_OCR0  (*(volatile ptr8)(0x5c))
#define TIMER_TIFR  (*(volatile ptr8)(0x58))
#define TIMER_TIMSK (*(volatile ptr8)(0x59))

/*TIMSK*/
#define OCIE2   7
#define TOIE2   6
#define TICIE1  5
#define OCIE1A  4
#define OCIE1B  3
#define TOIE1   2
#define OCIE0   1
#define TOIE0   0



/*Timer initialization*/
#define TIMER_CONTROL_VALUE 0x0B
#define TIMER_TCNT_VALUE 0
#define TIMER_OCR_VALUE 249

/*Timer Mask*/
#define TIMER_MASK 0x02

/*Numbers*/
#define ZERO   0
#define SEVEN  7

/*LEDS*/
#define LED_ONE		13
#define LED_TWO		14
#define LED_THREE	15

/*Buttons*/
#define BUTTON1 10

/*States*/
#define Ready	1
#define GO		2
#define STOP	3
#define EXT_INT 4

/*delay*/
#define ONE_MS 1000

#endif /* TIMER_CONFG_H_ */