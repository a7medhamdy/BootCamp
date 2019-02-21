/*
 * LCD.h
 *
 * Created: 2/19/2019 11:20:36 AM
 *  Author: AVE-LAP-039
 */ 


#ifndef LCD_H_
#define LCD_H_



extern void LCD_init ();
extern void LCD_sendCommand (uint8 Command);
extern void LCD_displayChar (uint8 Data);
extern void LCD_displayString (ptr8 str);
extern void LCD_gotoRowColumn(uint8 row, uint8 col);
extern void LCD_displayStringRowColumn (uint8 row, uint8 col, ptr8 str);
extern void LCD_clear ();



#endif /* LCD_H_ */