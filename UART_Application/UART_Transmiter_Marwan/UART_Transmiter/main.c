/*
 * UARTTEST.c
 *
 * Created: 3/2/2019 5:44:17 PM
 * Author : Marwan
 */ 


#include "Includes/UART.h"
#include "Includes/Config_UART.h"
#include "util/delay.h"
int main(void)
{
	
UART_Init();  /* Initialize The UART */


/* Set Button0 & Button1 Input */
DIO_SetPinDirection(BUTTON1,INPUT);
DIO_SetPinDirection(BUTTON0,INPUT);



	while (1)
	{
		
/* Check if button 0 Pressed */
	if((~DIO_ReadPin(BUTTON1)) && DIO_ReadPin( BUTTON0) )
		{
			UART_Transmit('A');
			_delay_ms(250);
		}
/* Check if button 1 Pressed */		
		else if((~DIO_ReadPin(BUTTON0)) && DIO_ReadPin( BUTTON1) )
		{
			UART_Transmit('B');
			_delay_ms(250);
		}
			
	}
}

