/*
 * UART.c
 *
 * Created: 2/27/2019 1:12:07 PM
 *  Author: AVE-LAP-039
 */
#include "Types.h"
#include "BitwiseOperation.h"
#include "UART.h"
#include "Config_UART.h" 

/********************** UART_Init() *************************
*Parameters:
*			I/P: NOTHING
*			O/P: NOTHING
*			I/O: NOTHING
*Return: Nothing
*Description: Function to initialize the UART Protocol
**************************************************************/
void UART_Init()
{
	uint16 UBRR;
	/*Define structure members*/
	 UART_Config_S UART_Struct={BAUDRATE,NO_STOPBITS,PARITYMODE,DATASIZE,SPEEDMODE};
	
	/*Define Stop Bits*/
	switch(UART_Struct.No_StopBits)
	{
		case ONE:
				/*set 1 stop bit*/
			
				break;
		case TWO:
				/*set 2 stop bits*/
				UCSRC|= ONE<<USBS;
				break;
		default:
				break;
				
	}
	
	/*Define Parity Mode*/
	switch(UART_Struct.ParityMode)
	{
	
		case 1:
				/*Set Even Parity*/
				UCSRC|= ONE<<UPM1;
				break;
		case 2:
				/*Set Odd Parity*/
				UCSRC|= ONE<<UPM0;
				UCSRC|= ONE<<UPM1;
				break;
		default:
				break;
	}
	
	/*Define Data Size*/
	switch(UART_Struct.DataSize)
	{
		case FIVE:
				 /*Set 5 bit data*/
				 UCSRC|= ZERO<<UCSZ0;
				 UCSRC|= ZERO<<UCSZ1;
				 UCSRC|= ZERO<<UCSZ2;
				 break;
		case SIX:
				/*Set 6 bit data*/
				UCSRC|= ONE<<UCSZ0;
				UCSRC|= ZERO<<UCSZ1;
				UCSRC|= ZERO<<UCSZ2;
				break;
		case SEVEN:
				/*Set 7 bit data*/
				UCSRC|= ZERO<<UCSZ0;
				UCSRC|= ONE<<UCSZ1;
				UCSRC|= ZERO<<UCSZ2;
				break;
		case EIGHT:
				/*Set 8 bit data*/
				UCSRC|= (ONE<<URSEL) |(ONE<<UCSZ0) | (ONE << UCSZ1) ;
			
			
				break;			
		case NINE:
				/*Set 9 bit data*/
				UCSRC|= ONE<<UCSZ0;
				UCSRC|= ONE<<UCSZ1;
				UCSRB|= ONE<<UCSZ2;
				break;
		default:
				break;
	}
	/*Define Speed Mode*/
	switch(UART_Struct.SpeedMode)
	{
		case ONE:
				/*Set Normal Speed Mode*/
				UBRR = ((F_CPU/16)/(UART_Struct.BaudRate)) - ONE;
				/*Set Baud Rate*/
				UBRRH = UBRR>>EIGHT ;
				UBRRL = UBRR;
				/*Enable UART Transmitter and Receiver*/
				UCSRB |= (TRUE<<RXEN)|(TRUE<<TXEN);
				
				break;
		case TWO:
				/*Set Double Speed Mode*/
				UCSRA|= (ONE<<U2X);
				UBRR = ((F_CPU/EIGHT )/( UART_Struct.BaudRate)) - ONE;
				/*Set Baud Rate*/
				UBRRH = UBRR>>EIGHT ;
				UBRRL = UBRR;
				/*Enable UART Transmitter and Receiver*/
				UCSRB |= (TRUE<<RXEN)|(TRUE<<TXEN);
				break;
		default:
				break;
	}
	
	

	
	
}


/*************** UART_Transmit(uint8 data)() *****************
*Parameters:
*			I/P: data
*			O/P: NOTHING
*			I/O: NOTHING
*Return: Nothing
*Description: Function to Transmit character
**************************************************************/

void UART_Transmit(uint8 data)
{
	/*Wait till the transmitting ended*/
	while(!GET_BIT(UCSRA,UDRE));
	/*write data into UDR register*/
	UDR=data;
}


/****************** UART_Recieve(uint8 data)******************
*Parameters:
*			I/P: NOTHING
*			O/P: UDR
*			I/O: NOTHING
*Return: Nothing
*Description: Function to Receive character
**************************************************************/

uint8 UART_Recieve(void)
{
	/*wait till receiving ended*/
	while ( !(UCSRA & (ONE<<RXC)) );
	/* Get and return received data from buffer */
	return UDR;

	
}

/*************UART_TransmitString(uint8* String )**************
*Parameters:
*			I/P: uint8* String
*			O/P: NOTHING
*			I/O: NOTHING
*Return: Nothing
*Description: Function to send string
**************************************************************/

void UART_TransmitString(uint8* String )
{
	/*wait till transmitting string is ended*/
	while(*String != Null)
	{
		/*transmit character*/
		UART_Transmit(*String);
		String++;
	}

}