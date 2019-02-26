/*
 * DIO.c
 *
 * Created: 2/13/2019 2:56:43 PM
 *  Author: AVE-LAP-039
 */ 
#include "Types.h"
#include "BitwiseOperation.h"
#include "DIO_cfg.h"
#include "DIO.h"
#include "BitwiseOperation.h"

void DIO_WritePin(uint8 PinNum,uint8 PinValue)
{
	/*check PORTA PINS from pin0 to pin7 */
	if ((PinNum >=PIN0) && (PinNum <=PIN7))
	{
		if(PinValue )
			/*write 1 on pin*/
			 SET_BIT(PORTA,PinNum);
		else
			/*write 0 on pin*/
			CLEAR_BIT(PORTA,PinNum);
	}
	/*check PORTB PINS from pin8 to pin15 */
	else if ((PinNum >=PIN8) && (PinNum <=PIN15))
	{
		if(PinValue)
		/*write 1 on pin*/
		SET_BIT(PORTB,(PinNum-PIN8));
		else
		/*write 0 on pin*/
		CLEAR_BIT(PORTB,(PinNum-PIN8));
	}
	/*check PORTC PINS from pin16 to pin23 */
	else if ((PinNum >=PIN16) && (PinNum <=PIN23))
	{
		if(PinValue)
		/*write 1 on pin*/
		SET_BIT(PORTC,(PinNum-PIN16));
		else
		/*write 0 on pin*/
		CLEAR_BIT(PORTC,(PinNum-PIN16));
	}	
	/*check PORTD PINS from pin24 to pin31 */
	else if ((PinNum >=PIN24) && (PinNum <=PIN31))
	{
		if(PinValue)
		/*write 1 on pin*/
		SET_BIT(PORTD,(PinNum-PIN24));
		else
		/*write 0 on pin*/
		CLEAR_BIT(PORTD,(PinNum-PIN24));
	}
	else
	{
		
	}

}

uint8 DIO_ReadPin(uint8 PinNum)
{
	/*check PORTA PINS from pin0 to pin7 */
	if ((PinNum >=PIN0) && (PinNum <=PIN7) )
		/*Read PIN from PORTA*/
		return(GET_BIT(PINA,PinNum));
	/*check PORTB PINS from pin8 to pin15 */
	else if ((PinNum >=PIN8) && (PinNum <=PIN15) )
		/*Read PIN from PORTB*/
		return(GET_BIT(PINB,(PinNum-PIN8)));
	/*check PORTC PINS from pin16 to pin23 */
	else if ((PinNum >=PIN16) && (PinNum <=PIN23) )
		/*Read PIN from PORTC*/
		return(GET_BIT(PINC,(PinNum-PIN16)));
	/*check PORTD PINS from pin24 to pin31 */
	else if ((PinNum >=PIN24) && (PinNum <=PIN31) )
		/*Read PIN from PORTD*/
		return(GET_BIT(PIND,(PinNum-PIN24)));
	else
		return 0;
}


void DIO_SetPinDirection(uint8 PinNum,uint8 PinDirection)
{
	/*check PORTA PINa from pin0 to pin7 */
	if ((PinNum >=PIN0) && (PinNum <=PIN7))
	{
		if(PinDirection)
			/*SET PIN in PORTA as output*/
			SET_BIT(DDRA,PinNum);
		else
			/*SET PIN in PORTA as input*/
			CLEAR_BIT(DDRA,PinNum);
	}
	/*check PORTB PINa from pin8 to pin15 */
	else if ((PinNum >=PIN8) && (PinNum <=PIN15))
	{
		if(PinDirection)
		/*SET PIN in PORTB as output*/
		SET_BIT(DDRB,(PinNum-PIN8));
		else
		/*SET PIN in PORTB as input*/
		CLEAR_BIT(DDRB,(PinNum-PIN8));
	}
	/*check PORTA PINS from pin16 to pin23 */
	else if ((PinNum >=PIN16) && (PinNum <=PIN23))
	{
		if(PinDirection)
		/*SET PIN in PORTC as output*/
		SET_BIT(DDRC,(PinNum-PIN16));
		else
		/*SET PIN in PORTC as input*/
		CLEAR_BIT(DDRC,(PinNum-PIN16));
	}	
	/*check PORTA PINS from pin24 to pin31 */
	else if ((PinNum >=PIN24) && (PinNum <=PIN31))
	{
		if(PinDirection)
		/*SET PIN in PORTD as output*/
		SET_BIT(DDRD,(PinNum-PIN24));
		else
		/*SET PIN in PORTD as input*/
		CLEAR_BIT(DDRD,(PinNum-PIN24));
	}
	else
	{
		
	}	
}