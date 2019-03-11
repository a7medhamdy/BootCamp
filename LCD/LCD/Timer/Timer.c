/*
 * Timer.c
 *
 * Created: 2/14/2019 9:31:54 AM
 *  Author: AVE-LAP-039
 */ 
#include "Timer.h"

void timer_delay(uint32 n)
{

	while (n>0)
	{
		TCCR0 = 0x0B;
		TCNT0 = 0;
		OCR0 =249;
		while ((TIFR & 0x02)==0);
		TCCR0=0;
		TIFR=0x02;
		n--;
	}
	

	
}