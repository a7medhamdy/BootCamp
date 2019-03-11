/*
 * LCD.c
 *
 * Created: 2/19/2019 11:16:25 AM
 * Author : AVE-LAP-039
 */ 

#include "Types.h"
#include "LCD.h"
#include "LCD_config.h"
#include <util/delay.h>
int main(void)
{
	
	LCD_init();
	LCD_clear();
	//
    while (1) 
    {
		LCD_displayStringRowColumn(2,2,"mi5aaaa");
    }
}

