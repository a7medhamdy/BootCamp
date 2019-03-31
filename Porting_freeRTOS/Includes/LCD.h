#ifndef LCD_H_
#define LCD_H_

#include "LCD_cfg.h"
#include "inc/hw_types.h"
#include "driverlib/debug.h"
#include "driverlib/fpu.h"
#include "driverlib/gpio.h"
#include "driverlib/pin_map.h"
#include "driverlib/rom.h"
#include "driverlib/sysctl.h"
#include "driverlib/uart.h"
#include "utils/uartstdio.h"
#include <stdint.h>
#include <stdbool.h>
#include "inc/hw_memmap.h"
#include "driverlib/ssi.h"
#include "bitwise_operation.h"
#include <stdlib.h>

uint8_t Random_num(void);
void LCD_init(void);
void LCD_sendCommand(uint8_t cmd);
void LCD_displayChar(uint8_t c);
void LCD_displayString(uint8_t* Str);
void LCD_displayStringRowColumn(uint8_t ROW, uint8_t COL, uint8_t* Str);
/************************************************************************/
/* Function: LCD Clear                                                  */
/* @param: void                                                         */
/* return: void                                                         */
/* Description: function clears LCD                                     */
/************************************************************************/
void LCD_Clear(void);
void LCD_gotoRowColumn(uint8_t ROW,uint8_t COL);
void LCD_AllowSpecialCharacters(void);

#define BYTE 8
#define BYTE_minus1 7
#define BIT0 0
#define BIT1 1
#define BIT2 2
#define BIT3 3
#define BIT4 4
#define BIT5 5
#define BIT6 6
#define BIT7 7

#define NULL_CHAR               '\0'
#define NUM_0                     0

#define NUMBER4_ToShiftToUpperBits 4


#endif /* LCD_H_ */
