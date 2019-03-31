#include"Includes/LCD.h"


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
extern volatile uint8_t LCD_clear_flag = 0 ;
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
SysCtlDelay(16000);
//DIO_WritePin(LCD_EN,HIGH);
//SysCtlDelay(2*16000);
GPIOPinWrite(GPIO_PORTA_BASE,LCD_EN ,0);
SysCtlDelay(16000);

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
SysCtlDelay(16000);
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
//DIO_WritePin(LCD_RS,HIGH);
//DIO_WritePin(LCD_RW,LOW);
//DIO_WritePin(LCD_EN,HIGH);
    SysCtlDelay(16000);
    GPIOPinWrite(GPIO_PORTA_BASE,LCD_EN ,0);
//DIO_WritePin(LCD_EN,LOW);
SysCtlDelay(16000);

/*    Write The LEAST significant bits of the command in the 4 bits of the LCD  */

GPIOPinWrite(GPIO_PORTC_BASE,LCD_D4, (Get_Bit(c,BIT0) <<4));
//DIO_WritePin(LCD_D5,(Get_Bit(cmd,BIT5) >> BIT5));
GPIOPinWrite(GPIO_PORTC_BASE,LCD_D5, (Get_Bit(c,BIT1) <<4));
//DIO_WritePin(LCD_D6,(Get_Bit(cmd,BIT6) >> BIT6));
GPIOPinWrite(GPIO_PORTC_BASE,LCD_D6, (Get_Bit(c,BIT2) <<4));
//DIO_WritePin(LCD_D7,(Get_Bit(cmd,BIT7) >> BIT7));
GPIOPinWrite(GPIO_PORTC_BASE,LCD_D7, (Get_Bit(c,BIT3) <<4));



GPIOPinWrite(GPIO_PORTA_BASE,LCD_RS | LCD_RW |LCD_EN ,LCD_RS|0|LCD_EN);
    SysCtlDelay(16000);
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



void LCD_send_Task(void )
{
    static uint8_t i = 0;
    uint8_t* arr[10] ={"Ahmed","Hamdy","Abdelrhem","Abdelglel","Yassin","Mohsen","gazzar","Oraby","Tarek","Sobhy"} ;
    if (LCD_clear_flag==0)
    {
        LCD_Clear();
        LCD_clear_flag++;
    }
    else
    {
        LCD_displayString(arr[i]);
        i++;
        if(i==9)
        {
            i = 0;
        }
        LCD_clear_flag=0;
    }

}

#if 0
void button_RTOS(void * pvParameters){
while (1){

   while ( !GPIOPinRead(GPIO_PORTF_BASE,GPIO_PIN_4))
   {
       count++;


    vTaskDelay( 50 );

   }
if (count <10&&count>1){

            GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_1,0);
            GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_2,0);
            GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_3,0);
            del+=100;
count =0;
}

if (count >10){

    GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_1,GPIO_PIN_1);
count =0;
}

   vTaskDelay( 50 );
}
}
#endif

