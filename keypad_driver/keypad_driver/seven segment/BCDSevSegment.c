/*
 * BCDSevSegment.c
 *
 * Created: 2/18/2019 12:46:52 PM
 *  Author: AVE-LAP-039
 */ 
#include "Types.h"
#include "BitwiseOperation.h"
#include "Keypad_cfg.h"
#include "Keypad.h"
#include "BCDSevSegment_cfg.h"
#include "BCDSevSegment.h"
#include "DIO.h"
#include "Timer.h"





#define DP_SEG 28
void BCDSevegments_enable(uint8 segment_number)
{
	switch(segment_number)
	{
		case ONE:
			PORTD |= SHIFT_ONE<<SegmentA_E;
			break;
		case TWO:
			PORTD |= SHIFT_ONE<<SegmentB_E;
			break;
		case THREE:
			PORTD |= SHIFT_ONE<<SegmentC_E;	
			break;
		case FOUR:
			PORTD |= SHIFT_ONE<<SegmentD_E;	
			break;
		default:
			break;
							
	}
}

void BCDSevegments_disable(uint8 segment_number)
{
	
		switch(segment_number)
		{
			case ONE:
				PORTD &= ~(ONE<<SegmentA_E);
				break;
			case TWO:
				PORTD &= ~(ONE<<SegmentB_E);
				break;
			case THREE:
				PORTD &= ~(ONE<<SegmentC_E);
				break;
			case FOUR:
				PORTD &= ~(ONE<<SegmentD_E);
				break;
			default:
				break;
			
		}
	
}
void BCDSevegments_displayNo(uint8 Number)
{
	if (Number>=ZERO && Number<=NINE)
		PORTB=(Number & LOW_NIBBLE_MASK)|(PORTB & HIGH_NIBBLE_MASK);
	
}