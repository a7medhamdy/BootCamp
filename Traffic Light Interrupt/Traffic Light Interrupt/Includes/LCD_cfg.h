/*
 * LCD_config.h
 *
 * Created: 2/19/2019 12:17:19 PM
 *  Author: AVE-LAP-039
 */ 


#ifndef LCD_CONFIG_H_
#define LCD_CONFIG_H_
/*Set Chip Frequency*/
#define F_CPU 16000000L

/* Set LCD MODE */
#define FOUR_BIT_MODE

#define HIGH 1
#define LOW  0

/* Number of Shifts */
#define LCD_SHIFT_ZERO 0
#define LCD_SHIFT_ONE 1
#define LCD_SHIFT_TWO 2
#define LCD_SHIFT_THREE 3
#define LCD_SHIFT_FOUR 4
#define LCD_SHIFT_FIVE 5
#define LCD_SHIFT_SIX 6
#define LCD_SHIFT_SEVEN 7

/* MASK BITS */
#define LCD_MASK_BIT_ZERO  0b00000001
#define LCD_MASK_BIT_ONE   0b00000010
#define LCD_MASK_BIT_TWO   0b00000100
#define LCD_MASK_BIT_THREE 0b00001000
#define LCD_MASK_BIT_FOUR  0b00010000
#define LCD_MASK_BIT_FIVE  0b00100000
#define LCD_MASK_BIT_SIX   0b01000000
#define LCD_MASK_BIT_SEVEN 0b10000000

/* LCD PINS */
#define LCD_RS 1
#define LCD_RW 2
#define LCD_EN 3
#define LCD_DATA_4 4
#define LCD_DATA_5 5
#define LCD_DATA_6 6
#define LCD_DATA_7 7

/* LCD PORT Masking */
#define LCD_PORT PORTA
#define HIGH_NIBBLE_MASK 0xf0
#define LOW_NIBBLE_MASK  0x0f
#define LOW2HIHGH_NIBBLE 4

/* Delays */
#define ONE_MS  1
#define FIFTEEN_MS 15

/* Init Commands */
#define INIT_CMD_ONE 0x33
#define INIT_CMD_TWO 0x32
#define INIT_CMD_THREE 0x28


/*Cursor ON*/
#define CURSOR_CMD_ON  0x0E
/* clear */
#define CLEAR_CMD_LCD 0x01
/* CUrsor Shift */
#define SHIFT_CURSOR_CMD 0x06

/* ROWS Implementation */
#define ROW_ONE 1
#define ROW_TWO 2
#define ROW_1_CMD 0x80
#define ROW_2_CMD 0xC0

#endif /* LCD_CONFIG_H_ */