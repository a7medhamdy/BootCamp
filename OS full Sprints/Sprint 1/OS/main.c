/*
 * OS.c
 *
 * Created: 2/23/2019 3:35:18 PM
 * Author : AVE-LAP-039
 */ 

#include <avr/io.h>
#include "Types.h"
#include "DIO.h"
#include "scheduler.h"
#include "timer.h"
#include "tasks.h"


#include "BitwiseOperation.h"

int main(void)
{
	/*Port initialization*/
	DIO_SetPinDirection(LED0,HIGH);
	DIO_SetPinDirection(LED1,HIGH);
	DIO_SetPinDirection(LED2,HIGH);
	DIO_SetPinDirection(LED3,HIGH);
    /*call secheduler*/
	schedulerInit_AndStart();
}

