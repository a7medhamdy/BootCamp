/*
 * DIO_cfg.h
 *
 * Created: 2/19/2019 5:04:08 PM
 *  Author: AVE-LAP-039
 */ 


#ifndef DIO_CFG_H_
#define DIO_CFG_H_


/* AVR PINS */

/*PORTA*/
#define PIN0 0
#define PIN1 1
#define PIN2 2
#define PIN3 3
#define PIN4 4
#define PIN5 5
#define PIN6 6
#define PIN7 7

/*PORTB*/
#define PIN8  8
#define PIN9  9
#define PIN10 10
#define PIN11 11
#define PIN12 12
#define PIN13 13
#define PIN14 14
#define PIN15 15

/*PORTA*/
#define PIN16 16
#define PIN17 17
#define PIN18 18
#define PIN19 19
#define PIN20 20
#define PIN21 21
#define PIN22 22
#define PIN23 23

/*PORTA*/
#define PIN24 24
#define PIN25 25
#define PIN26 26
#define PIN27 27
#define PIN28 28
#define PIN29 29
#define PIN30 30
#define PIN31 31




/*REGISTER MAPPING */
/*PORTA*/
#define PORTA (*(volatile ptr8)(0x3B))
#define DDRA  (*(volatile ptr8)(0x3A))
#define PINA  (*(volatile ptr8)(0x39))
/*PORTB*/
#define PORTB (*(volatile ptr8)(0x38))
#define DDRB  (*(volatile ptr8)(0x37))
#define PINB  (*(volatile ptr8)(0x36))
/*PORTC*/
#define PORTC (*(volatile ptr8)(0x35))
#define DDRC  (*(volatile ptr8)(0x34))
#define PINC  (*(volatile ptr8)(0x33))
/*PORTD*/
#define PORTD (*(volatile ptr8)(0x32))
#define DDRD  (*(volatile ptr8)(0x31))
#define PIND  (*(volatile ptr8)(0x30))


#endif /* DIO_CFG_H_ */