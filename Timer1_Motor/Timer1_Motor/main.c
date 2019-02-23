/*
 * Timer1_Motor.c
 *
 * Created: 2/21/2019 12:44:06 PM
 * Author : AVE-LAP-039
 */ 

#include "Types.h"
#include "Timer1.h"
#include "DIO.h"
#include "BitwiseOperation.h"


int main(void)
{
	Timer1_Init();
	
	Timer1_PWM(50,300);
	
   
}

