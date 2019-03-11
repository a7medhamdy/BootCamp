/*
 * UART.c
 *
 * Created: 2/27/2019 1:12:07 PM
 *  Author: Marwan
 */

#include "../Includes/UART.h" 

/**************************************************************************************************/
/*Name : UART_init																	               */
/*Parameters : 	void																		     */
/*Inputs : baud rate																			 */
/*Outputs:  N/A																					*/	
/*Description:   UART Module initialization                                                      */
/**************************************************************************************************/
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


/**************************************************************************************************/
/*Name : UART_Transmit																	           */
/*Parameters : 	uint8 data																	     */
/*Inputs : data																					 */
/*Outputs:  N/A																					*/
/*Description:   Function that transmits data through UART                                         */
/**************************************************************************************************/

void UART_Transmit(uint8 data)
{
	/*wait till the flag is set*/
	while(!Get_Bit(UCSRA,UDRE));
	
	/*store the data in the UDR register*/
	UDR=data;
}


/**************************************************************************************************/
/*Name : UART_Recieve																	           */
/*Parameters : 																	     */
/*Inputs : void																				 */
/*Outputs:  data																				*/
/*Description:   Function that Receives character data through UART                                         */
/**************************************************************************************************/

uint8 UART_Recieve(void)
{
	/*wait till the flag is set*/
	while ( !(UCSRA & (1<<RXC)) );
	/* Get and return received data from buffer */
	return UDR;

	
}

/**************************************************************************************************/
/*Name : UART_TransmitString																	           */
/*Parameters : 	uint8* String																     */
/*Inputs : String																				 */
/*Outputs:  N/A																					*/
/*Description:   Function that transmits String data through UART                                         */
/**************************************************************************************************/
void UART_TransmitString(uint8* String )
{
	while(*String != Null)
	{
		UART_Transmit(*String);
		String++;
	}

}