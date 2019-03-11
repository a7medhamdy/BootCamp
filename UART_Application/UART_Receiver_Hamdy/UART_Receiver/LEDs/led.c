/*
 * led.c
 *
 * Created: 3/11/2019 5:03:03 PM
 *  Author: AVE-LAP-023
 */ 

#include "DIO_driver.h"
#include "led.h"
#include "led_cfg.h"

/**************************************************************************************************/
/*Function Name :- LedInit                                                                        */
/*Function job   :-initialize to led pin to be output                                             */
/*Function inputs :- N/A                                                                          */
/*Function outputs :- N/A                                                                         */
/**************************************************************************************************/
void LedInit(uint8 pin_num)
{
	/* set direction of desired led to be output */
	DIO_SetPinDirection(pin_num,HIGH);
	
}

/**************************************************************************************************/
/*Function Name :- LedState                                                                       */
/*Function job   :- operate led as required if on, off or toggle                                  */
/*Function inputs :-led number and required status                                                */
/*Function outputs :- N/A                                                                         */
/**************************************************************************************************/
void LedState(uint8 pin_num, STATUS t)
{
	/* switch on led's status to apply action on led */
switch(t)
{
	/* write zero to led */
	case OFF :
	DIO_WritePin(pin_num,OFF);
	break;
	/*write one to led pin */
	case ON :
	DIO_WritePin(pin_num,ON);
	break;
	/* toggle led pin by call toggling pin */
	case TOGGLE :
	DIO_togglePin(pin_num);
}

} /* end of function */
