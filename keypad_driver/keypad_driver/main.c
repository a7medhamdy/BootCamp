/*
 * keypad_driver.c
 *
 * Created: 2/18/2019 11:56:18 AM
 * Author : AVE-LAP-039
 */ 
#include "Types.h"
#include "BitwiseOperation.h"
#include "Keypad_cfg.h"
#include "Keypad.h"
#include "BCDSevSegment_cfg.h"
#include "BCDSevSegment.h"

#include "DIO.h"
#include "Timer.h"



int main(void)
{
	DDRB = 0xff;
	DDRD = 0xff;

	Keypad_init();
	uint8 key;
	
    /* Replace with your application code */
    while (1) 
    {
		
		
		key=Keypad_getPressedKey();
		BCDSevegments_enable(1);
		if(key!= 0)
		{
			BCDSevegments_displayNo(key);
		}
		

			
    }
}

