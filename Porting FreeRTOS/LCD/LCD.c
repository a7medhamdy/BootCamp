#include "Includes/LCD.h"
#include "FreeRTOS.h"
#include "task.h"
#include "Includes/Button.h"

#define BIT_0                    ( 1 << 0 )
#define BIT_1                    ( 1 << 1 )
#define BUTTON_ONE_PRESSED       1
#define BUTTON_TWO_PRESSED       2
#define LCD_PERIODICITY          100
#define MAX                      255
#define LOW                      0
#define HIGH                     1
#define TWO                      2
#define EIGHT                    8
#define NINE                     9
#define TEN                      10
#define ELEVEN                   11
#define SIXTEEN                  16
#define HUNDRED                  100
#define LCD_FIRST_ROW                0x80
#define LCD_SECOND_ROW               0xC0


volatile uint8_t count1 = LOW;
volatile uint8_t count2 = LOW;

extern volatile uint8_t Button1Flag;
extern volatile uint8_t Button2Flag;
void LCD_init(void)
{
    /* Enable the GPIO port for LCD.                                */
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOA);
    /* Check if the peripheral access is enabled.                           */
    while (!SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOA))
        ;
    /* Enable the GPIO port for LCD.                                */
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOC);
    /* Check if the peripheral access is enabled.                           */
    while (!SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOC))
        ;
    /* Ports Directions                           */
    GPIOPinTypeGPIOOutput(GPIO_PORTA_BASE,
                          GPIO_PIN_2 | GPIO_PIN_3 | GPIO_PIN_4);
    GPIOPinTypeGPIOOutput(GPIO_PORTC_BASE,
                          GPIO_PIN_4 | GPIO_PIN_5 | GPIO_PIN_6 | GPIO_PIN_7);

    LCD_sendCommand(CMD_LCD4BIT33);
    vTaskDelay(2);
    LCD_sendCommand(CMD_LCD4BIT32);
    vTaskDelay(2);
    LCD_sendCommand(CMD_LCD_2_LINES_5X7);
    vTaskDelay(2);
    LCD_sendCommand(CMD_CURSOR_ON);
    vTaskDelay(2);
    LCD_sendCommand(CMD_RESET);
    vTaskDelay(2);
    LCD_sendCommand(CMD_SHIFT_DISPLAY_LEFT);
    vTaskDelay(2);
    LCD_sendCommand(0x80);
}

/*********************************************************************************
 *
 * Function: LCD_sendCommand
 *
 * @param: 
 input : cmd , the command given to the LCD
 * @return: void
 *
 * Description: function to send commands to the LCD
 *
 *
 ********************************************************************************/
void LCD_sendCommand(uint8_t cmd)
{

    /*    Write The MOST significant bits of the command in the 4 bits of the LCD	*/

//DIO_WritePin(LCD_D4,(Get_Bit(cmd,BIT4) >> BIT4));
    GPIOPinWrite(GPIO_PORTC_BASE, LCD_D4, (Get_Bit(cmd, BIT4)));
//DIO_WritePin(LCD_D5,(Get_Bit(cmd,BIT5) >> BIT5));
    GPIOPinWrite(GPIO_PORTC_BASE, LCD_D5, (Get_Bit(cmd, BIT5)));
//DIO_WritePin(LCD_D6,(Get_Bit(cmd,BIT6) >> BIT6));
    GPIOPinWrite(GPIO_PORTC_BASE, LCD_D6, (Get_Bit(cmd, BIT6)));
//DIO_WritePin(LCD_D7,(Get_Bit(cmd,BIT7) >> BIT7));
    GPIOPinWrite(GPIO_PORTC_BASE, LCD_D7, (Get_Bit(cmd, BIT7)));

//DIO_WritePin(LCD_RS,LOW);
    GPIOPinWrite(GPIO_PORTA_BASE, LCD_RS | LCD_RW | LCD_EN, 0 | 0 | LCD_EN);
    vTaskDelay(2);
//DIO_WritePin(LCD_EN,HIGH);
//vTaskDelay(2);
    GPIOPinWrite(GPIO_PORTA_BASE, LCD_EN, 0);
    vTaskDelay(2);

    /*    Write The LEAST significant bits of the command in the 4 bits of the LCD	*/
//DIO_WritePin(LCD_D4,(Get_Bit(cmd,BIT0) >> BIT0));
//DIO_WritePin(LCD_D5,(Get_Bit(cmd,BIT1) >> BIT1));
//DIO_WritePin(LCD_D6,(Get_Bit(cmd,BIT2) >> BIT2));
//DIO_WritePin(LCD_D7,(Get_Bit(cmd,BIT3) >> BIT3));
    GPIOPinWrite(GPIO_PORTC_BASE, LCD_D4, (Get_Bit(cmd,BIT0) << 4));
//DIO_WritePin(LCD_D5,(Get_Bit(cmd,BIT5) >> BIT5));
    GPIOPinWrite(GPIO_PORTC_BASE, LCD_D5, (Get_Bit(cmd,BIT1) << 4));
//DIO_WritePin(LCD_D6,(Get_Bit(cmd,BIT6) >> BIT6));
    GPIOPinWrite(GPIO_PORTC_BASE, LCD_D6, (Get_Bit(cmd,BIT2) << 4));
//DIO_WritePin(LCD_D7,(Get_Bit(cmd,BIT7) >> BIT7));
    GPIOPinWrite(GPIO_PORTC_BASE, LCD_D7, (Get_Bit(cmd,BIT3) << 4));

    GPIOPinWrite(GPIO_PORTA_BASE, LCD_EN, LCD_EN);
    vTaskDelay(2);
    GPIOPinWrite(GPIO_PORTA_BASE, LCD_EN, 0);
}

/*********************************************************************************
 *
 * Function: LCD_displayChar
 *
 * @param: 
 input : c , the character given to the LCD
 * @return: void
 *
 * Description: function to print a character on the LCD
 *
 *
 ********************************************************************************/
void LCD_displayChar(uint8_t c)
{

    /*    Write The MOST significant bits of the command in the 4 bits of the LCD	*/

    //DIO_WritePin(LCD_D4,(Get_Bit(cmd,BIT4) >> BIT4));
    GPIOPinWrite(GPIO_PORTC_BASE, LCD_D4, (Get_Bit(c, BIT4)));
    //DIO_WritePin(LCD_D5,(Get_Bit(cmd,BIT5) >> BIT5));
    GPIOPinWrite(GPIO_PORTC_BASE, LCD_D5, (Get_Bit(c, BIT5)));
    //DIO_WritePin(LCD_D6,(Get_Bit(cmd,BIT6) >> BIT6));
    GPIOPinWrite(GPIO_PORTC_BASE, LCD_D6, (Get_Bit(c, BIT6)));
    //DIO_WritePin(LCD_D7,(Get_Bit(cmd,BIT7) >> BIT7));
    GPIOPinWrite(GPIO_PORTC_BASE, LCD_D7, (Get_Bit(c, BIT7)));

    GPIOPinWrite(GPIO_PORTA_BASE, LCD_RS | LCD_RW | LCD_EN,
                 LCD_RS | 0 | LCD_EN);
//DIO_WritePin(LCD_RS,HIGH);
//DIO_WritePin(LCD_RW,LOW);
//DIO_WritePin(LCD_EN,HIGH);
    vTaskDelay(2);
    GPIOPinWrite(GPIO_PORTA_BASE, LCD_EN, 0);
//DIO_WritePin(LCD_EN,LOW);
    vTaskDelay(2);

    /*    Write The LEAST significant bits of the command in the 4 bits of the LCD	*/

    GPIOPinWrite(GPIO_PORTC_BASE, LCD_D4, (Get_Bit(c,BIT0) << 4));
//DIO_WritePin(LCD_D5,(Get_Bit(cmd,BIT5) >> BIT5));
    GPIOPinWrite(GPIO_PORTC_BASE, LCD_D5, (Get_Bit(c,BIT1) << 4));
//DIO_WritePin(LCD_D6,(Get_Bit(cmd,BIT6) >> BIT6));
    GPIOPinWrite(GPIO_PORTC_BASE, LCD_D6, (Get_Bit(c,BIT2) << 4));
//DIO_WritePin(LCD_D7,(Get_Bit(cmd,BIT7) >> BIT7));
    GPIOPinWrite(GPIO_PORTC_BASE, LCD_D7, (Get_Bit(c,BIT3) << 4));

    GPIOPinWrite(GPIO_PORTA_BASE, LCD_RS | LCD_RW | LCD_EN,
                 LCD_RS | 0 | LCD_EN);
    vTaskDelay(2);
    GPIOPinWrite(GPIO_PORTA_BASE, LCD_EN, 0);
}

void LCD_displayString(uint8_t* Str)
{
    uint8_t i = LOW;
    while (Str[i] != NULL_CHARACTER)
    {
        LCD_displayChar(Str[i]);
        i++;
    }
}

/************************************************************************/
/* Function: LCD Clear                                                  */
/* @param: void                                                         */
/* return: void                                                         */
/* Description: function clears LCD                                     */
/************************************************************************/
void LCD_Clear(void)
{
    LCD_sendCommand(LCD_CLEAR);
}

/************************************************************************/
/* Function: LCD_gotoRowColumn                                          */
/* @param: row, column                                                  */
/* return: void                                                         */
/* Description: function clears LCD                                     */
/************************************************************************/
void LCD_gotoRowColumn(uint8_t x, uint8_t y) //x:0~1, y:0~15
{
    uint8_t address = LOW;
    if (x == LOW)
        address = LCD_FIRST_ROW;
    else if (x == HIGH)
        address = LCD_SECOND_ROW;
    if (y <SIXTEEN)
        address += y;
    LCD_sendCommand(address);
}

/************************************************************************/
/* Function: LCDTask                                                */
/* @param: void pointer                                                 */
/* return: void                                                         */
/* Description: This task rece                                           */
/************************************************************************/
void LCDTask(void *pvParameters)
{
    uint8_t recv_data = LOW;

    while (1)
    {
        /*Check if there is data on the queue*/
        if (xQueueReceive(xQueu, &recv_data, TEN))
        {
            /*check the received data due to button one*/
            if (recv_data == BUTTON_ONE_PRESSED)
            {
                /*increment counter in LCD*/
                count1++;
                /*check if number two digits*/
                if (count1 >= TEN && count1 < HUNDRED)
                {
                    LCD_gotoRowColumn(LOW, LOW);
                    LCD_displayString("Count1: ");
                    /*go to digit one*/
                    LCD_gotoRowColumn(LOW, EIGHT);
                    /*extract digit one*/
                    LCD_displayChar((count1 / TEN) + '0');
                    /*go to digit two*/
                    LCD_gotoRowColumn(LOW, NINE);
                    /*extract digit two*/
                    LCD_displayChar((count1 % TEN) + '0');

                }
                /*check if number three digits*/
                else if (count1 >= HUNDRED)
                {
                    LCD_gotoRowColumn(LOW, LOW);
                    LCD_displayString("Count1: ");
                    /*go to digit one*/
                    LCD_gotoRowColumn(LOW, EIGHT);
                    /*extract digit one*/
                    LCD_displayChar((count1 / HUNDRED) + '0');
                    /*go to digit two*/
                    LCD_gotoRowColumn(LOW, NINE);
                    /*extract digit two*/
                    LCD_displayChar(((count1 / TEN) % TEN) + '0');
                    /*extract digit three*/
                    LCD_gotoRowColumn(LOW, TEN);
                    /*extract digit three*/
                    LCD_displayChar((count1 % TEN) + '0');
                }
                /*check if number one digit*/
                else if (count1 < TEN)
                {
                    LCD_gotoRowColumn(LOW, LOW);
                    LCD_displayString("Count1: ");
                    /*go to digit one*/
                    LCD_gotoRowColumn(LOW, EIGHT);
                    /*extract digit one*/
                    LCD_displayChar(count1 + '0');
                }
                /*check if count reaches 255*/
                if (count1 == MAX)
                {
                    /*initialize the count to zero again*/
                    count1 = LOW;
                }

            }
            else if (recv_data == BUTTON_TWO_PRESSED)
            {
                /*increment counter in LCD*/
                count2++;
                /*check if number two digits*/
                if (count2 >= TEN && count2 < HUNDRED)
                {
                    LCD_gotoRowColumn(HIGH, LOW);
                    LCD_displayString("Count2: ");
                    /*go to digit one*/
                    LCD_gotoRowColumn(HIGH, EIGHT);
                    /*extract digit one*/
                    LCD_displayChar((count2 / TEN) + '0');
                    /*go to digit two*/
                    LCD_gotoRowColumn(HIGH, NINE);
                    /*extract digit two*/
                    LCD_displayChar((count2 % TEN) + '0');

                }
                /*check if number three digits*/
                else if (count2 >= HUNDRED)
                {
                    LCD_gotoRowColumn(HIGH, LOW);
                    LCD_displayString("Count2: ");
                    /*go to digit one*/
                    LCD_gotoRowColumn(HIGH, EIGHT);
                    /*extract digit one*/
                    LCD_displayChar((count2 / HUNDRED) + '0');
                    /*go to digit two*/
                    LCD_gotoRowColumn(HIGH, NINE);
                    /*extract digit two*/
                    LCD_displayChar(((count2 / TEN) % TEN) + '0');
                    /*extract digit three*/
                    LCD_gotoRowColumn(HIGH, TEN);
                    /*extract digit three*/
                    LCD_displayChar((count2 % TEN) + '0');
                }
                /*check if number one digit*/
                else if (count2 < TEN)
                {
                    LCD_gotoRowColumn(HIGH, LOW);
                    LCD_displayString("Count2: ");
                    /*go to digit one*/
                    LCD_gotoRowColumn(HIGH, EIGHT);
                    /*extract digit one*/
                    LCD_displayChar(count2 + '0');
                }
                /*check if count reaches 255*/
                if (count2 == MAX)
                {
                    /*initialize the count to zero again*/
                    count2 = LOW;
                }
            }

        }
        else
        {

        }
        /*Set task periodicity*/
        vTaskDelay(LCD_PERIODICITY);

    }
}
