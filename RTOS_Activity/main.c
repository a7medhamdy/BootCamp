

/**
 * main.c
 */
#include "Includes/LEDs.h"
#include "Includes/LCD.h"
#include "Includes/Buzzer.h"
#include "Includes/SysTick.h"

volatile uint8_t LED1_flag = 0;
volatile uint8_t LED2_flag = 0;
volatile uint8_t LED3_flag = 0;
volatile uint8_t LCD_flag =  0;


void main(void)
{
    LEDs_init();
    LCD_init();
    Buzzer_init();

    while(1)
    {
        Buzzer_sound();
        if(LED1_flag==10)
        {
            LED1_flag=0;
            LED1_Toggle();

        }

        if(LED2_flag==20)
        {
            LED2_Toggle();
            LED2_flag=0;
        }
        if(LED3_flag==100)
        {
            LED3_Toggle();
            LCD_send_Task();
            LCD_flag = 0 ;
            LED3_flag=0;
        }
    }
}


