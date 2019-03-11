/*
 * DIO.c
 *
 * Created: 2/13/2019 2:56:43 PM
 *  Author: AVE-LAP-039
 */ 
#include "DIO.h"
#include "BitwiseOperation.h"

void DIO_WritePin(uint8 PinNum,uint8 PinValue)
{
	if ((PinNum >=0) && (PinNum <=7))
	{
		if(PinValue )
			Set_Bit(PORTA,PinNum);
		else
			Clear_Bit(PORTA,PinNum);
	}
	else if ((PinNum >=8) && (PinNum <=15))
	{
		if(PinValue)
		Set_Bit(PORTB,(PinNum-8));
		else
		Clear_Bit(PORTB,(PinNum-8));
	}
	else if ((PinNum >=16) && (PinNum <=23))
	{
		if(PinValue)
		Set_Bit(PORTC,(PinNum-16));
		else
		Clear_Bit(PORTC,(PinNum-16));
	}	
	else if ((PinNum >=24) && (PinNum <=31))
	{
		if(PinValue)
		Set_Bit(PORTD,(PinNum-24));
		else
		Clear_Bit(PORTD,(PinNum-24));
	}
	else
	{
		
	}

}

uint8 DIO_ReadPin(uint8 PinNum)
{
	if ((PinNum >=0) && (PinNum <=7) )
		return(Get_Bit(PINA,PinNum));
	else if ((PinNum >=8) && (PinNum <=15) )
		return(Get_Bit(PINB,(PinNum-8)));
	else if ((PinNum >=16) && (PinNum <=23) )
		return(Get_Bit(PINC,(PinNum-16)));
	else if ((PinNum >=24) && (PinNum <=31) )
		return(Get_Bit(PIND,(PinNum-24)));
	else
		return 0;
}


void DIO_SetPinDirection(uint8 PinNum,uint8 PinDirection)
{
	if ((PinNum >=0) && (PinNum <=7))
	{
		if(PinDirection)
			Set_Bit(DDRA,PinNum);
		else
			Clear_Bit(DDRA,PinNum);
	}
	else if ((PinNum >=8) && (PinNum <=15))
	{
		if(PinDirection)
		Set_Bit(DDRB,(PinNum-8));
		else
		Clear_Bit(DDRB,(PinNum-8));
	}
	else if ((PinNum >=16) && (PinNum <=23))
	{
		if(PinDirection)
		Set_Bit(DDRC,(PinNum-16));
		else
		Clear_Bit(DDRC,(PinNum-16));
	}	
	else if ((PinNum >=24) && (PinNum <=31))
	{
		if(PinDirection)
		Set_Bit(DDRD,(PinNum-24));
		else
		Clear_Bit(DDRD,(PinNum-24));
	}
	else
	{
		
	}	
}

