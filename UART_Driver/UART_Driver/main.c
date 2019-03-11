/*
 * UARTTEST.c
 *
 * Created: 3/2/2019 5:44:17 PM
 * Author : AVE-LAP-071
 */ 

#include "Types.h"
#include "BitwiseOperation.h"
#include "UART.h"
#include "config_UART.h"

int main(void)
{
	/*Initialize UART*/
	UART_Init();
	uint8 character=ZERO;
	while (1)
	{
		/*wait until receive and Store the value  in UDR*/
			character = UART_Recieve();
			/*Transmit the Received data again*/
			UART_Transmit(character);
	}
}

