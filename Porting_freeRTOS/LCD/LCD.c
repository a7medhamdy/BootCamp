#include"Includes/LCD.h"

#define LCD_DELAY        1000

#include <stdint.h>
#include <stdbool.h>
#include "FreeRTOS.h"
#include "task.h"
#include "driverlib/gpio.h"
#include "inc/hw_memmap.h"
#include "driverlib/sysctl.h"
#include "Includes/LCD_cfg.h"
#include "Includes/LCD.h"
#include "Includes/bitwise_operation.h"
#include <stdlib.h>
#include "event_groups.h"
#define BIT_0   ( 1 << 0 )
#define BIT_4   ( 1 << 4 )

extern EventGroupHandle_t xCreatedEventGroup_button;

volatile uint8_t LCD_clear_flag = 0;
static uint8_t Random_num(void);

/*********************************************************************************
 *
 * Function: LCD_init
 *
 * @param: void
 * @return: void
 *
 * Description: function to initialize the pins of the LCD as output and gives the LCD
 * its initial commands
 *
 ********************************************************************************/
void LCD_init(){
    /*
    DIO_SetPinDirection(LCD_RS,OUTPUT);
    DIO_SetPinDirection(LCD_RW,OUTPUT);
    DIO_SetPinDirection(LCD_EN,OUTPUT);
    DIO_SetPinDirection(LCD_D4,OUTPUT);
    DIO_SetPinDirection(LCD_D5,OUTPUT);
    DIO_SetPinDirection(LCD_D6,OUTPUT);
    DIO_SetPinDirection(LCD_D7,OUTPUT);
*/
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOA);
    while(!SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOA));
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOC);
    while(!SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOC));

    GPIOPinTypeGPIOOutput(GPIO_PORTA_BASE,GPIO_PIN_2 |GPIO_PIN_3|GPIO_PIN_4);
    GPIOPinTypeGPIOOutput(GPIO_PORTC_BASE,GPIO_PIN_4 |GPIO_PIN_5|GPIO_PIN_6 | GPIO_PIN_7);


    LCD_sendCommand(CMD_LCD4BIT33);
    SysCtlDelay(2*16000);
    LCD_sendCommand(CMD_LCD4BIT32);
    SysCtlDelay(2*16000);
    LCD_sendCommand(CMD_LCD_2_LINES_5X7);
    SysCtlDelay(2*16000);
    LCD_sendCommand(CMD_CURSOR_ON);
    SysCtlDelay(2*16000);
    LCD_sendCommand(CMD_RESET);
    SysCtlDelay(2*16000);
    LCD_sendCommand(CMD_SHIFT_DISPLAY_LEFT);
    SysCtlDelay(2*16000);
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
void LCD_sendCommand(uint8_t cmd){

    /*    Write The MOST significant bits of the command in the 4 bits of the LCD   */

    //DIO_WritePin(LCD_D4,(Get_Bit(cmd,BIT4) >> BIT4));
    GPIOPinWrite(GPIO_PORTC_BASE,LCD_D4, (Get_Bit(cmd,BIT4) ));
    //DIO_WritePin(LCD_D5,(Get_Bit(cmd,BIT5) >> BIT5));
    GPIOPinWrite(GPIO_PORTC_BASE,LCD_D5, (Get_Bit(cmd,BIT5) ));
    //DIO_WritePin(LCD_D6,(Get_Bit(cmd,BIT6) >> BIT6));
    GPIOPinWrite(GPIO_PORTC_BASE,LCD_D6, (Get_Bit(cmd,BIT6) ));
    //DIO_WritePin(LCD_D7,(Get_Bit(cmd,BIT7) >> BIT7));
    GPIOPinWrite(GPIO_PORTC_BASE,LCD_D7, (Get_Bit(cmd,BIT7) ));

    //DIO_WritePin(LCD_RS,LOW);
    GPIOPinWrite(GPIO_PORTA_BASE,LCD_RS | LCD_RW |LCD_EN ,0|0|LCD_EN);
    SysCtlDelay(2*16000);
    //DIO_WritePin(LCD_EN,HIGH);
    //SysCtlDelay(2*16000);
    GPIOPinWrite(GPIO_PORTA_BASE,LCD_EN ,0);
    SysCtlDelay(2*16000);

    /*    Write The LEAST significant bits of the command in the 4 bits of the LCD  */
    //DIO_WritePin(LCD_D4,(Get_Bit(cmd,BIT0) >> BIT0));
    //DIO_WritePin(LCD_D5,(Get_Bit(cmd,BIT1) >> BIT1));
    //DIO_WritePin(LCD_D6,(Get_Bit(cmd,BIT2) >> BIT2));
    //DIO_WritePin(LCD_D7,(Get_Bit(cmd,BIT3) >> BIT3));

    GPIOPinWrite(GPIO_PORTC_BASE,LCD_D4, (Get_Bit(cmd,BIT0) <<4));
    //DIO_WritePin(LCD_D5,(Get_Bit(cmd,BIT5) >> BIT5));
    GPIOPinWrite(GPIO_PORTC_BASE,LCD_D5, (Get_Bit(cmd,BIT1)  <<4));
    //DIO_WritePin(LCD_D6,(Get_Bit(cmd,BIT6) >> BIT6));
    GPIOPinWrite(GPIO_PORTC_BASE,LCD_D6, (Get_Bit(cmd,BIT2)  <<4));
    //DIO_WritePin(LCD_D7,(Get_Bit(cmd,BIT7) >> BIT7));
    GPIOPinWrite(GPIO_PORTC_BASE,LCD_D7, (Get_Bit(cmd,BIT3)  <<4));

    GPIOPinWrite(GPIO_PORTA_BASE,LCD_EN ,LCD_EN);
    SysCtlDelay(2*16000);
    GPIOPinWrite(GPIO_PORTA_BASE,LCD_EN ,0);
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
void LCD_displayChar(uint8_t c){

/*    Write The MOST significant bits of the command in the 4 bits of the LCD   */

    //DIO_WritePin(LCD_D4,(Get_Bit(cmd,BIT4) >> BIT4));
    GPIOPinWrite(GPIO_PORTC_BASE,LCD_D4, (Get_Bit(c,BIT4)));
    //DIO_WritePin(LCD_D5,(Get_Bit(cmd,BIT5) >> BIT5));
    GPIOPinWrite(GPIO_PORTC_BASE,LCD_D5, (Get_Bit(c,BIT5)));
    //DIO_WritePin(LCD_D6,(Get_Bit(cmd,BIT6) >> BIT6));
    GPIOPinWrite(GPIO_PORTC_BASE,LCD_D6, (Get_Bit(c,BIT6)));
    //DIO_WritePin(LCD_D7,(Get_Bit(cmd,BIT7) >> BIT7));
    GPIOPinWrite(GPIO_PORTC_BASE,LCD_D7, (Get_Bit(c,BIT7)));

    GPIOPinWrite(GPIO_PORTA_BASE,LCD_RS | LCD_RW |LCD_EN ,LCD_RS|0|LCD_EN);

    vTaskDelay(2);
    GPIOPinWrite(GPIO_PORTA_BASE,LCD_EN ,0);
    vTaskDelay(2);

    /*    Write The LEAST significant bits of the command in the 4 bits of the LCD  */

    GPIOPinWrite(GPIO_PORTC_BASE,LCD_D4, (Get_Bit(c,BIT0) <<4));
    //DIO_WritePin(LCD_D5,(Get_Bit(cmd,BIT5) >> BIT5));
    GPIOPinWrite(GPIO_PORTC_BASE,LCD_D5, (Get_Bit(c,BIT1) <<4));
    //DIO_WritePin(LCD_D6,(Get_Bit(cmd,BIT6) >> BIT6));
    GPIOPinWrite(GPIO_PORTC_BASE,LCD_D6, (Get_Bit(c,BIT2) <<4));
    //DIO_WritePin(LCD_D7,(Get_Bit(cmd,BIT7) >> BIT7));
    GPIOPinWrite(GPIO_PORTC_BASE,LCD_D7, (Get_Bit(c,BIT3) <<4));


    GPIOPinWrite(GPIO_PORTA_BASE,LCD_RS | LCD_RW |LCD_EN ,LCD_RS|0|LCD_EN);
    vTaskDelay(2);
    GPIOPinWrite(GPIO_PORTA_BASE,LCD_EN ,0);
}



void LCD_displayString(uint8_t* Str)
{
       uint8_t i = NUM_0;
       while(Str[i] != NULL_CHAR)
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



void LCD_Task(void *Pvparameter)
{

    EventBits_t uxBits;
    const TickType_t xTicksToWait = 100000 / portTICK_PERIOD_MS;

      /* Wait a maximum of 100ms for either bit 0 or bit 4 to be set within
      the event group.  Clear the bits before exiting. */
      uxBits = xEventGroupWaitBits(
                xCreatedEventGroup_button,   /* The event group being tested. */
                BIT_0 | BIT_4, /* The bits within the event group to wait for. */
                pdTRUE,        /* BIT_0 & BIT_4 should be cleared before returning. */
                pdFALSE,       /* Don't wait for both bits, either bit will do. */
                xTicksToWait );/* Wait a maximum of 100ms for either bit to be set. */

      if( ( uxBits & ( BIT_0 | BIT_4 ) ) == ( BIT_0 | BIT_4 ) )
      {
          /* xEventGroupWaitBits() returned because both bits were set. */
          LCD_Clear();
          LCD_displayString("2 But Pressed");

      }
      else if( ( uxBits & BIT_0 ) != 0 )
      {
          /* xEventGroupWaitBits() returned because just BIT_0 was set. */
          LCD_Clear();
          LCD_displayString("But 1 pressed");
      }
      else if( ( uxBits & BIT_4 ) != 0 )
      {
          /* xEventGroupWaitBits() returned because just BIT_4 was set. */
          LCD_Clear();
          LCD_displayString("But 2 pressed");
      }
      else
      {
          /* xEventGroupWaitBits() returned because xTicksToWait ticks passed
          without either BIT_0 or BIT_4 becoming set. */
          LCD_displayString("No But Pressed");
      }
}



static uint8_t Random_num(void)
{
   uint8_t rand1=0;
   rand1 = (rand()) % 10;
   return rand1;
}
