/*
 * UART_cfg.h
 *
 * Created: 2/27/2019 1:56:35 PM
 *  Author: Marwan
 */ 


#ifndef UART_CFG_H_
#define UART_CFG_H_

/*Set frequency of MC*/
#define F_CPU 16000000UL

#define BAUDRATE	 9600
#define NO_STOPBITS  1
#define PARITYMODE	 0
#define DATASIZE	 8
#define SPEEDMODE	 1

/*Register addresses*/
#define UBRRH   (*(volatile ptr8)(0x40))
#define UCSRC   (*(volatile ptr8)(0x40))
#define UDR     (*(volatile ptr8)(0x2C))
#define UCSRA   (*(volatile ptr8)(0x2B))
#define UCSRB   (*(volatile ptr8)(0x2A))
#define UBRRL   (*(volatile ptr8)(0x29))

/*Register PINs*/
/* UCSRA */
#define RXC     7
#define TXC     6
#define UDRE    5
#define FE      4
#define DOR     3
#define PE      2
#define U2X     1
#define MPCM    0

/* UCSRB */
#define RXCIE   7
#define TXCIE   6
#define UDRIE   5
#define RXEN    4
#define TXEN    3
#define UCSZ2   2
#define RXB8    1
#define TXB8    0

/* UCSRC */
#define URSEL   7
#define UMSEL   6
#define UPM1    5
#define UPM0    4
#define USBS    3
#define UCSZ1   2
#define UCSZ0   1
#define UCPOL   0

/*Numbers*/
#define ZERO	0
#define ONE     1
#define TWO	2
#define FIVE	5
#define SIX	6
#define SEVEN	7
#define EIGHT	8
#define NINE	9
#define SIXTEEN 16

/*States*/
#define TRUE  1
#define FALSE 0
#define Null '\0'

#endif /* UART_CFG_H_ */