#include "../Includes/Dio.h"
#include "../Includes/BitwiseOperation.h"


/************************************************************************/
/* Name: DIO WritePin */
/* Parameters : Pin number,pin value */
/* I/p : uint8 PinNum,uint8 PinValue */
/* O/p : Null */
/* Return : void */
/* Write on the Pins */
/************************************************************************/

void DIO_WritePin(uint8 PinNum,uint8 PinValue)
{
	uint8 Pin=ZERO;
	
	if ((PinNum < EIGHT) && (PinNum > ZERO))
	{
		Pin=(PinNum % EIGHT);
		if(PinValue==LOW)
		{
			Clear_Bit(PORTA,Pin);
			
		}
		
		else 
		{
			Set_Bit(PORTA,Pin);
		}
	}
	
	
	else if ((PinNum < SIXTEEN) && (PinNum > EIGHT))
		{
			Pin=(PinNum % EIGHT);
			if(PinValue==LOW)
			{
				Clear_Bit(PORTB,Pin);
				
			}
			
			else
			{
				Set_Bit(PORTB,Pin);
			}
		}
	
	else if ((PinNum < TWENTYFOUR) && (PinNum > SIXTEEN))
		{
			Pin=(PinNum % EIGHT);
			if(PinValue==LOW)
			{
				Clear_Bit(PORTC,Pin);
				
			}
			
			else
			{
				Set_Bit(PORTC,Pin);
			}
		}
	
	
	else if ((PinNum < THIRTYTWO) && (PinNum > TWENTYFOUR))
		{
			Pin=(PinNum % EIGHT);
			if(PinValue==LOW)
			{
				Clear_Bit(PORTD,Pin);
				
			}
			
			else
			{
				Set_Bit(PORTD,Pin);
			}
		}
	
}

/************************************************************************/
/* Name: DIO_ReadPin */
/* Parameters : Pin number,pin value */
/* I/p : uint8 PinNum */
/* O/p : uint8 Result */
/* Return : uint8 Result */
/* Reads from the Pins */
/************************************************************************/

uint8 DIO_ReadPin(uint8 PinNum)
{
	uint8 Result=ZERO;
	uint8 Pin=ZERO;
	
	if ((PinNum < EIGHT) && (PinNum > ZERO))
	{
		Pin=(PinNum % EIGHT);
		Result=Get_Bit(PINA,Pin);
	}
			
	else if ((PinNum < SIXTEEN) && (PinNum > EIGHT))
	{
		Pin=(PinNum % EIGHT);
		Result=Get_Bit(PINB,Pin);
	}
	else if ((PinNum < TWENTYFOUR) && (PinNum > SIXTEEN))
	{
		Pin=(PinNum % EIGHT);
		Result=Get_Bit(PINC,Pin);
	}
	
	
	else if ((PinNum < THIRTYTWO) && (PinNum > TWENTYFOUR))
	{
		Pin=(PinNum % EIGHT);
		Result=Get_Bit(PIND,Pin);
	}
	
	return Result;
}

 /************************************************************************/
 /* Name: DIO_SetPinDirection */
 /* Parameters : Pin number,pin direction */
 /* I/p : uint8 PinNum, uint8 PinDirection */
 /* O/p : Null */
 /* Return : Void */
 /* Set the direction of the Pins */
 /************************************************************************/
void DIO_SetPinDirection(uint8 PinNum,uint8 PinDirection)
{
	uint8 Pin=ZERO;
	
	if ((PinNum < EIGHT) && (PinNum > ZERO))
	{
		Pin=(PinNum % EIGHT);
		if(PinDirection==INPUT)
		{
			Clear_Bit(DDRA,Pin);
			
		}
		
		else
		{
			Set_Bit(DDRA,Pin);
		}
	}
	
	
	else if ((PinNum < SIXTEEN) && (PinNum > EIGHT))
	{
		Pin=(PinNum % EIGHT);
		if(PinDirection==INPUT)
		{
			Clear_Bit(DDRB,Pin);
			
		}
		
		else
		{
			Set_Bit(DDRB,Pin);
		}
	}
	
	else if ((PinNum < TWENTYFOUR) && (PinNum > SIXTEEN))
	{
		Pin=(PinNum % EIGHT);
		if(PinDirection==INPUT)
		{
			Clear_Bit(DDRC,Pin);
			
		}
		
		else
		{
			Set_Bit(DDRC,Pin);
		}
	}
	
	
	else if ((PinNum < THIRTYTWO) && (PinNum > TWENTYFOUR))
	{
		Pin=(PinNum % EIGHT);
		if(PinDirection==INPUT)
		{
			Clear_Bit(DDRD,Pin);
			
		}
		
		else
		{
			Set_Bit(DDRD,Pin);
		}
	}
	
}

