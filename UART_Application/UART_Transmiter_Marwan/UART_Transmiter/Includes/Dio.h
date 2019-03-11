#ifndef _DIO_H_
#define _DIO_H_
#include "Types.h"
#include "MEM_MAP_REG.h"




/************************************************************************/
/* Name: DIO WritePin */
/* Parameters : Pin number,pin value */
/* I/p : uint8 PinNum,uint8 PinValue */
/* O/p : Null */
/* Return : void */
/* Write on the Pins */
/************************************************************************/


 extern void DIO_WritePin(uint8 PinNum,uint8 PinValue);
 
 /************************************************************************/
 /* Name: DIO_ReadPin */
 /* Parameters : Pin number,pin value */
 /* I/p : uint8 PinNum */
 /* O/p : uint8 Result */
 /* Return : uint8 Result */
 /* Reads from the Pins */
 /************************************************************************/

 
 extern uint8 DIO_ReadPin(uint8 PinNum);
 
 
 
 /************************************************************************/
 /* Name: DIO_SetPinDirection */
 /* Parameters : Pin number,pin direction */
 /* I/p : uint8 PinNum, uint8 PinDirection */
 /* O/p : Null */
 /* Return : Void */
 /* Set the direction of the Pins */
 /************************************************************************/


 extern void DIO_SetPinDirection(uint8 PinNum,uint8 PinDirection);




#define OUTPUT 1
#define INPUT 0
#define HIGH 1
#define LOW 0
#define PRESSED 1
#define NOTPRESSED 0

#define BUTTON1 PIN10
#define BUTTON0 PIN20

#define  ZERO 0
#define  ONE 1
#define  TWO 2
#define THREE 3
#define FOUR 4
#define FIVE 5
#define  SIX 6
#define SEVEN 7
#define EIGHT 8
#define NINE 9
#define TEN 10
#define SIXTEEN 16
#define TWENTYFOUR 24
#define THIRTYTWO 32  
#define  TRUE 1
#define FALSE 0


#endif
