/*
 * UARTTEST.c
 *
 * Created: 3/2/2019 5:44:17 PM
 * Author : AVE-LAP-071
 */ 

#include "Types.h"
#include "BitwiseOperation.h"
#include "UART.h"
#include "Config_UART.h"
#include "Includes/led.h"

int main(void)
{
	/*Set direction of led_1*/
	LedInit(led1);
	/*Set direction of led_2*/
	LedInit(led2);
	/*Initialize UART*/
	UART_Init();
	/*Variable to store the received data from UART*/
	uint8 RX = 0;
	
	while (1)
	{
		/*wait till receiving*/
		RX = UART_Recieve();
		/*Check which led to be toggle depending on which switch was pressed*/
		switch(RX)
		{
			case 'A':
				/*Toggle LED_1*/
				LedState(led1, TOGGLE);
				LedState(led2, OFF);
				break;
			case 'B':
			/*Toggle LED_2*/
				LedState(led2, TOGGLE);
				LedState(led1, OFF);
				break;
			default:
				break;
		}
	}
}

