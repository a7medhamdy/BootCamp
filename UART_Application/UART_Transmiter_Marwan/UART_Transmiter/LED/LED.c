/*
 * LED.c
 *
 * Created: 2/25/2019 11:59:13 AM
 *  Author: AVE-LAP-071
 */ 

#include "LED.h"

/**************************************************************************************************/
/*Function Name :- LedInit                                                                        */
/*Function job   :-initialize to led pin to be output                                             */
/*Function inputs :- N/A                                                                          */
/*Function outputs :- N/A                                                                         */
/**************************************************************************************************/
void LedInit (uint8 Pin_num)
{
	DIO_SetPinDirection(Pin_num,OUTPUT);
}


/**************************************************************************************************/
/*Function Name :- LedState                                                                       */
/*Function job   :- operate led as required if on, off or toggle                                  */
/*Function inputs :-led number and required status                                                */
/*Function outputs :- N/A                                                                         */
/**************************************************************************************************/
void LedState (uint8 Pin_num, STATUS t)
{
	switch (t)
	{
		case off: DIO_WritePin(Pin_num,LOW); break;
		case on:	DIO_WritePin(Pin_num,HIGH); break;
		case toggle: {
			if (LOW==DIO_ReadPin(Pin_num))
			{
				DIO_WritePin(Pin_num,HIGH);
			}
			
			else
			{
				DIO_WritePin(Pin_num,LOW);
			}
			break;
		}
		default:
		break;
	}
	
}




