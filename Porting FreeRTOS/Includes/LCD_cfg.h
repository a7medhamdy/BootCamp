#ifndef LCD_CFG_H_
#define LCD_CFG_H_

#include "stdint.h"

#define LCD_RS GPIO_PIN_2
#define LCD_RW GPIO_PIN_3
#define LCD_EN GPIO_PIN_4

#define LCD_PORT PortA
#define LCD_D4 GPIO_PIN_4
#define LCD_D5 GPIO_PIN_5
#define LCD_D6 GPIO_PIN_6
#define LCD_D7 GPIO_PIN_7

#define LCD_Operation_BIT_NUMBER 4 
#define Mask_LowerByte 0x0F
#define Mask_UpperByte 0xF0

#define CMD_RESET 0x01
#define CMD_LCD4BIT33 0x33
#define CMD_LCD4BIT32 0x32
#define CMD_LCD_2_LINES_5X7 0x28
#define CMD_CURSOR_ON 0x0E
#define CMD_SHIFT_DISPLAY_LEFT 0x06
#define CMD_SHIFT_CURSOR_RIGHT 0x14
#define CMD_SHIFT_CURSOR_LEFT 0x10
#define CMD_INCREMENT_CURSOR 0x06
#define CMD_DECREMENT_CURSOR 0x04
#define CMD_CURSOR_TO_LINE1 0x80
#define CMD_CURSOR_TO_LINE2 0xC0
#define CMD_FIRST_ALLOWED_ADDRESS_IN_CGRAM 0x40
#define CMD_END_ALLOWED_ADDRESS_IN_CGRAM 0x80
#define LCD_CLEAR   0x01 /* clear screen */
#define NULL_CHARACTER '\0' 

#define TWO_MS 2

#define FIRST_ROW 1
#define SECOND_ROW 2

#endif /* LCD_CFG_H_ */
