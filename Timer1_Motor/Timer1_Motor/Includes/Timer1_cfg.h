/*
 * Timer1.h
 *
 * Created: 2/21/2019 12:44:34 PM
 *  Author: AVE-LAP-039
 */ 


#ifndef TIMER1_H_
#define TIMER1_H_

/*set pre-defines*/
#define F_CPU 16000000UL
#define FAST_PWM
#define INVERTING_MODE



/*Timer1 Registers Address*/
#define TCCR1A (*(volatile ptr8)(0x4F))
#define TCCR1B (*(volatile ptr8)(0x4E))
#define TCNT1H (*(volatile ptr8)(0x4D))
#define TCNT1L (*(volatile ptr8)(0x4C))
#define OCR1AH (*(volatile ptr8)(0x4B))
#define OCR1AL (*(volatile ptr8)(0x4A))
#define OCR1BH (*(volatile ptr8)(0x49))
#define OCR1BL (*(volatile ptr8)(0x48))
#define ICR1H  (*(volatile ptr8)(0x47))
#define ICR1L  (*(volatile ptr8)(0x46))

/*Timer1 Registers Pins*/

/* TCCR1A */
#define COM1A1  7
#define COM1A0  6
#define COM1B1  5
#define COM1B0  4
#define FOC1A   3
#define FOC1B   2
#define WGM11   1
#define WGM10   0

/* TCCR1B */
#define ICNC1   7
#define ICES1   6
#define WGM13   4
#define WGM12   3
#define CS12    2
#define CS11    1
#define CS10    0

/*Motor Pins*/
/*Enable*/
#define OC1B 28
#define OC1A 29
/*Direction*/
#define DIR_1A 26
#define DIR_1B 27

#define DIR_2A 30
#define DIR_2B 31

/*states*/
#define HIGH 1
#define LOW  0

/*Numbers*/
#define ONE 1
#define TWO 2
#define PERCENTAGE 100
/*Mask*/
#define HIGH_MASK 0xff00
#define LOW_MASK  0x00ff

/*Shifts*/
#define SHIFT_EIGHT 8


#endif /* TIMER1_H_ */