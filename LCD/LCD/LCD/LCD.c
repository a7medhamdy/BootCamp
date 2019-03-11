/*
 * LCD.c
 *
 * Created: 2/19/2019 11:20:04 AM
 *  Author: AVE-LAP-039
 */
#include "Types.h" 
#include "DIO.h"
#include "DIO_cfg.h"
#include "LCD.h"
#include "LCD_config.h"
#include "DIO.h"
#include <util/delay.h>

/*****************LCD_INIT()*******************
*Parameters:
*			I/P:
*			O/P:
*			I/O:
*Return:
*Description:
**********************************************/
extern void LCD_init ()
{
	#ifdef FOUR_BIT_MODE
	/* set direction */
	DIO_SetPinDirection(LCD_RS,HIGH);
	DIO_SetPinDirection(LCD_RW,HIGH);
	DIO_SetPinDirection(LCD_EN,HIGH);
	DIO_SetPinDirection(LCD_DATA_4,HIGH);
	DIO_SetPinDirection(LCD_DATA_5,HIGH);
	DIO_SetPinDirection(LCD_DATA_6,HIGH);
	DIO_SetPinDirection(LCD_DATA_7,HIGH);
	
	/* clear Enable */
	DIO_WritePin(LCD_EN,LOW);
	/* Wait After Power up*/
	_delay_ms(FIFTEEN_MS);
	
	/* Three Commands INIT*/
	LCD_sendCommand (INIT_CMD_ONE);
	LCD_sendCommand (INIT_CMD_TWO);
	LCD_sendCommand (INIT_CMD_THREE);
		
	/* On/OF Cursor */
	LCD_sendCommand (CURSOR_CMD_ON);
	/* Clear LCD */
	LCD_sendCommand (CLEAR_CMD_LCD);
	/* Entry Mode & Shift right */
	LCD_sendCommand (SHIFT_CURSOR_CMD);
	#elif EIGHT_BIT_MODE
	#endif
	
}

/*************LCD_sendCommand()***************
*Parameters:
*			I/P:
*			O/P:
*			I/O:
*Return:
*Description:
**********************************************/
void LCD_sendCommand (uint8 Command)
{
	#ifdef FOUR_BIT_MODE
	/* Rs = 0 */
	DIO_WritePin(LCD_RS,LOW);
	/* RW = 0 */
	DIO_WritePin(LCD_RW,LOW);
	/* Send High Nibble Command On Data Pins */
	DIO_WritePin(LCD_DATA_4,((Command & LCD_MASK_BIT_FOUR)>>(LCD_SHIFT_FOUR)));
	DIO_WritePin(LCD_DATA_5,((Command & LCD_MASK_BIT_FIVE)>>(LCD_SHIFT_FIVE)));
	DIO_WritePin(LCD_DATA_6,((Command & LCD_MASK_BIT_SIX)>>(LCD_SHIFT_SIX)));
	DIO_WritePin(LCD_DATA_7,((Command & LCD_MASK_BIT_SEVEN)>>(LCD_SHIFT_SEVEN)));
	
	/* EN = 1 */
	DIO_WritePin(LCD_EN,HIGH);
	/* delay 1 ms */
	_delay_ms(ONE_MS);
	/* EN = 0 */
	DIO_WritePin(LCD_EN,LOW);
	/* delay 1 ms */
	_delay_ms(ONE_MS);
	
	/* Send Low Nibble Command On Data Pins */
	DIO_WritePin(LCD_DATA_4,((Command & LCD_MASK_BIT_ZERO)>>(LCD_SHIFT_ZERO)));
	DIO_WritePin(LCD_DATA_5,((Command & LCD_MASK_BIT_ONE)>>(LCD_SHIFT_ONE)));
	DIO_WritePin(LCD_DATA_6,((Command & LCD_MASK_BIT_TWO)>>(LCD_SHIFT_TWO)));
	DIO_WritePin(LCD_DATA_7,((Command & LCD_MASK_BIT_THREE)>>(LCD_SHIFT_THREE)));
	
	/* EN = 1 */
	DIO_WritePin(LCD_EN,HIGH);
	/* delay 1 ms */
	_delay_ms(ONE_MS);
	/* EN = 0 */
	DIO_WritePin(LCD_EN,LOW);
	/* delay 1 ms */
	_delay_ms(ONE_MS);	
	#elif EIGHT_BIT_MODE
	#endif
	
}

/*************LCD_displayChar()***************
*Parameters:
*			I/P:
*			O/P:
*			I/O:
*Return:
*Description:
**********************************************/
void LCD_displayChar (uint8 Data)
{
	#ifdef FOUR_BIT_MODE
		/* Rs = 1 */
		DIO_WritePin(LCD_RS,HIGH);
		/* RW = 0 */
		DIO_WritePin(LCD_RW,LOW);
		
		LCD_PORT = (LCD_PORT & LOW_NIBBLE_MASK) | (Data & HIGH_NIBBLE_MASK);
		/* EN = 1 */
		DIO_WritePin(LCD_EN,HIGH);
		/* delay 1 ms */
		_delay_ms(ONE_MS);
		/* EN = 0 */
		DIO_WritePin(LCD_EN,LOW);
		/* delay 1 ms */
		_delay_ms(ONE_MS);
	
		/* Send Low Nibble Command On Data Pins */
		LCD_PORT = (LCD_PORT & LOW_NIBBLE_MASK) | (HIGH_NIBBLE_MASK & (Data<<4));
		/* EN = 1 */
		DIO_WritePin(LCD_EN,HIGH);
		/* delay 1 ms */
		_delay_ms(ONE_MS);
		/* EN = 0 */
		DIO_WritePin(LCD_EN,LOW);
		/* delay 1 ms */
		_delay_ms(ONE_MS);	
		#elif EIGHT_BIT_MODE
		#endif

}

/************LCD_displayString()**************
*Parameters:
*			I/P:
*			O/P:
*			I/O:
*Return:
*Description:
**********************************************/
void LCD_displayString(ptr8 str)
{
	uint8 i = LOW ;
	while(str[i]!= LOW)
	{
		LCD_displayChar(str[i]);
		i++;
	}
}

/************LCD_gotoRowColumn()**************
*Parameters:
*			I/P:
*			O/P:
*			I/O:
*Return:
*Description:
**********************************************/
void LCD_gotoRowColumn(uint8 row, uint8 col)
{
	switch (row)
	{
		case ROW_ONE:
			LCD_sendCommand(ROW_1_CMD+col);
			break;
		case ROW_TWO:
			LCD_sendCommand(ROW_2_CMD+col);
			break;
		default:
			break;
	}
}

/*******LCD_displayStringRowColumn()**********
*Parameters:
*			I/P:
*			O/P:
*			I/O:
*Return:
*Description:
**********************************************/
void LCD_displayStringRowColumn (uint8 row, uint8 col, ptr8 str)
{
		LCD_gotoRowColumn(row,col);
		LCD_displayString(str);
}

/****************LCD_clear()******************
*Parameters:
*			I/P:
*			O/P:
*			I/O:
*Return:
*Description:
**********************************************/
void LCD_clear ()
{
	LCD_sendCommand(CLEAR_CMD_LCD);
}