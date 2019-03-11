/*
 * DIO.h
 *
 * Created: 2/13/2019 2:40:37 PM
 *  Author: AVE-LAP-039
 */ 


#ifndef DIO_H_
#define DIO_H_
#include "Types.h"

#define PORTA (*(volatile ptr8)(0x3B))
#define DDRA  (*(volatile ptr8)(0x3A))
#define PINA  (*(volatile ptr8)(0x39))

#define PORTB (*(volatile ptr8)(0x38))
#define DDRB  (*(volatile ptr8)(0x37))
#define PINB  (*(volatile ptr8)(0x36))

#define PORTC (*(volatile ptr8)(0x35))
#define DDRC  (*(volatile ptr8)(0x34))
#define PINC  (*(volatile ptr8)(0x33))

#define PORTD (*(volatile ptr8)(0x32))
#define DDRD  (*(volatile ptr8)(0x31))
#define PIND  (*(volatile ptr8)(0x30))

extern void DIO_WritePin(uint8 PinNum,uint8 PinValue);
extern uint8 DIO_ReadPin(uint8 PinNum);
extern void DIO_SetPinDirection(uint8 PinNum,uint8 PinDirection);


#endif /* DIO_H_ */