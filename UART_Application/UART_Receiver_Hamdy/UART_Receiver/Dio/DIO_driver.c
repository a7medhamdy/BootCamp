/*
 * DIO_driver.c
 *
 * Created: 2/13/2019 2:17:30 PM
 *  Author: AVE-LAP-023
 */ 

#include "../Includes/DIO_driver.h"


/********************************************************************************************************
* Function name :- DIO_WritePin                                                                         *
* function job :- write value in port if micro controller                                               *
* function arguments :- pin number and the value written to it                                          *
* function return :-            N/A                                                                     *
********************************************************************************************************/


void DIO_WritePin(uint8 PinNum,uint8 PinValue){
	/* according to pin number calculate the corresponding port to write in */
	if(PinNum >= PORTA_START && PinNum <=PORTA_END){
		switch(PinValue){
			case 1 : SET_BIT(PORTA,PinNum);
			break;
			case 0 : CLEAR_BIT(PORTA,PinNum);
			break;
			default :
			break ;
		}
	}
	else if(PinNum >= PORTB_START && PinNum <= PORTB_END){
		switch(PinValue){
			case 1 : SET_BIT(PORTB,(PinNum-PORTB_START));
			break;
			case 0 : CLEAR_BIT(PORTB,(PinNum-PORTB_START));
			break;
			default :
			break ;
		}
	}
	else if(PinNum >= PORTC_START && PinNum <= PORTC_END){
		switch(PinValue){
			case HIGH : SET_BIT(PORTC,(PinNum-PORTC_START));
			break;
			case LOW : CLEAR_BIT(PORTC,(PinNum-PORTC_START));
			break;
			default :
			break ;
		}
	}
	else if(PinNum >= PORTD_START && PinNum <= PORTD_END){
		switch(PinValue){
			case HIGH : SET_BIT(PORTD,(PinNum- PORTD_START));
			break;
			case LOW : CLEAR_BIT(PORTD,(PinNum-PORTD_START));
			break;
			default :
			break ;
		}
	}
}
/********************************************************************************************************
* Function name :- DIO_ReadPin                                                                          *
* function job :- Read value from pin of micro controller                                               *
* function arguments :- pin number                                                                      *
* function return :-            N/A                                                                     *
********************************************************************************************************/
uint8 DIO_ReadPin(uint8 PinNum){
	/* according to pin number calculate the corresponding port to read from */
	if(PinNum >=PORTA_START && PinNum <=PORTA_END){
		return (GET_BIT(PINA,PinNum));
	}
	else if(PinNum >=PORTB_START && PinNum <=PORTB_END){
		return (GET_BIT(PINB,(PinNum-PORTB_START)));
	}
	else if(PinNum >=PORTC_START && PinNum <=PORTC_END){
		return (GET_BIT(PINC,(PinNum-PORTC_START)));
	}
	else if(PinNum >=PORTD_START && PinNum <=PORTD_END){
		return (GET_BIT(PIND,(PinNum-PORTD_START)));
	}
	return FALSE;
}
/********************************************************************************************************
* Function name :- DIO_SetPinDirection                                                                  *
* function job :- determine direction of specified pin                                                  *
* function arguments :- pin number and desired direction (I/O)                                          *
* function return :-            N/A                                                                     *
*********************************************************************************************************/
void DIO_SetPinDirection(uint8 PinNum,uint8 PinDirection){
	/* according to pin number calculate the corresponding port to set its direction */
	if(PinNum >=PORTA_START && PinNum <=PORTA_END){
		switch(PinDirection){
			case HIGH : SET_BIT(DDRA,PinNum);
			break;
			case LOW : CLEAR_BIT(DDRA,PinNum);
			break;
			default :
			break ;
		}
	}
	else if(PinNum >=PORTB_START && PinNum <=PORTB_END){
		switch(PinDirection){
			case HIGH : SET_BIT(DDRB,(PinNum-PORTB_START));
			break;
			case LOW : CLEAR_BIT(DDRB,(PinNum-PORTB_START));
			break;
			default :
			break ;
		}
	}
	else if(PinNum >=PORTC_START && PinNum <=PORTC_END){
		switch(PinDirection){
			case HIGH : SET_BIT(DDRC,(PinNum-PORTC_START));
			break;
			case LOW : CLEAR_BIT(DDRC,(PinNum-PORTC_START));
			break;
			default :
			break ;
		}
	}
	else if(PinNum >=PORTD_START && PinNum <=PORTD_END){
		switch(PinDirection){
			case HIGH : SET_BIT(DDRD,(PinNum-PORTD_START));
			break;
			case LOW : CLEAR_BIT(DDRD,(PinNum-PORTD_START));
			break;
			default :
			break ;
		}
	}
}
/********************************************************************************************************
* Function name :- DIO_togglePin                                                                        *
* function job :- toggle desired pin                                                                    *
* function arguments :- pin number and the value written to it                                          *
* function return :-            N/A                                                                     *
*********************************************************************************************************/
void DIO_togglePin(uint8 PinNum){
	/* according to pin number calculate the corresponding port to toggle  */
	if(PinNum >= PORTA_START && PinNum <= PORTA_END){
		TOGGLE_BIT(PORTA,PinNum);
	}
	else if(PinNum >=PORTB_START && PinNum <=PORTB_END){
		TOGGLE_BIT(PORTB,(PinNum-PORTB_START));
	}
	else if(PinNum >= PORTC_START && PinNum <=PORTC_END){
		TOGGLE_BIT(PORTC,(PinNum-PORTC_START));
	}
	else if(PinNum >=PORTD_START && PinNum <=PORTD_END){
		TOGGLE_BIT(PIND,(PinNum-PORTD_START));
	}
}
