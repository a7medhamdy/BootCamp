/*
 * Traffic Light Interrupt.c
 *
 * Created: 2/21/2019 12:50:28 AM
 * Author : AVE-LAP-039
 */ 

#include <avr/io.h>


#include "Types.h"
#include "BitwiseOperation.h"
#include "Timer_cfg.h"
#include "Timer.h"
#include "Interrupt_cfg.h"
#include "avr/interrupt.h"
#include "DIO.h"


volatile uint8 flag=ZERO;

int main(void)
{
	/*SET LEDS direction as output*/
	DIO_SetPinDirection(LED_ONE,HIGH);
	DIO_SetPinDirection(LED_TWO,HIGH);
	DIO_SetPinDirection(LED_THREE,HIGH);
	
	/*SET Buttons direction as input*/
	DIO_SetPinDirection(BUTTON1,LOW);
	
	/*Initalize timer*/
	Timer_Init();

    while (1) 
    {
		/*Enable Global Interrupt*/
		Enable_Global_Interrupt();
		
		/*Go To Ready State*/
		if (flag == Ready)
		{
			DIO_WritePin(LED_THREE,HIGH);
			DIO_WritePin(LED_TWO,LOW);
			DIO_WritePin(LED_ONE,LOW);
		}
		
		/*Go To GO State*/
		else if(flag == GO)
		{
			DIO_WritePin(LED_THREE,LOW);
			DIO_WritePin(LED_TWO,LOW);
			DIO_WritePin(LED_ONE,HIGH);
		}
		
		/*Go To Stop State*/
		else if(flag == STOP)
		{
			DIO_WritePin(LED_THREE,LOW);
			DIO_WritePin(LED_TWO,HIGH);
			DIO_WritePin(LED_ONE,LOW);
			flag = LOW;
		}
		
		/*Go To Stop State if Button is pressed*/
		else if(flag == EXT_INT)
		{
			DIO_WritePin(LED_THREE,HIGH);
			DIO_WritePin(LED_TWO,LOW);
			DIO_WritePin(LED_ONE,LOW);
			flag = LOW;
		}
	}
}

