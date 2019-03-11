/*
 * Keypad.c
 *
 * Created: 2/18/2019 2:56:04 PM
 *  Author: AVE-LAP-039
 */ 
#include "Types.h"
#include "BitwiseOperation.h"
#include "Keypad_cfg.h"
#include "Keypad.h"
#include "BCDSevSegment_cfg.h"
#include "BCDSevSegment.h"
#include "DIO.h"
#include "Timer.h"

void Keypad_init()
{
	DIO_SetPinDirection(column1_pin,HIGH);
	DIO_SetPinDirection(column2_pin,HIGH); 
	DIO_SetPinDirection(column3_pin,HIGH);  	
	DIO_WritePin(row1_pin,HIGH);
	DIO_WritePin(row2_pin,HIGH);
	DIO_WritePin(row3_pin,HIGH);
		
}



uint8 Keypad_getPressedKey()
{
		uint8 res;
		//check col 1
		PORTC|=ONE<<column2;
		PORTC|=ONE<<column3;
		PORTC &=~(ONE<<column1);
		if (!DIO_ReadPin(row1_pin) )
		{
			res = ONE;
			return res;
		}
		
		else if (!DIO_ReadPin(row2_pin) )
		{
			res = FOUR;
			return res;
		}
		else if (!DIO_ReadPin(row3_pin) )
		{
			res = SEVEN;
			return res;
		}
		else
		{
			res = ZERO;
		}
		
		//col 2
		PORTC|=ONE<<column1;
		PORTC|=ONE<<column3;
		PORTC &=~(ONE<<column2);

		if (!DIO_ReadPin(row1_pin) )
		{
			res = TWO;
			return res;
		}
		
		else if (!DIO_ReadPin(row2_pin) )
		{
			res = FIVE;

			return res;
		}
		else if (!DIO_ReadPin(row3_pin) )
		{
			res = EIGHT;
			return res;
		}
		else
		{
			res = ZERO;
		}
		PORTC|=ONE<<column1;
		PORTC|=ONE<<column2;
		PORTC &=~(ONE<<column3);
		if (!DIO_ReadPin(row1_pin) )
		{
			res = THREE;
			return res;
		}
		
		else if (!DIO_ReadPin(row2_pin) )
		{
			res = SIX;
			return res;
		}
		else if (!DIO_ReadPin(row3_pin) )
		{
			res = NINE;
			return res;
		}
		else
		{
			res = ZERO;
		}
		return res;
		
}