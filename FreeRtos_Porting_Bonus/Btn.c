/*
 * PushBtn.c
 *
 *  Created on: Mar 13, 2019
 *      Author: AVE-LAP-062
 */

#include "Btn.h"
#include "inc/hw_memmap.h"
#include "inc/hw_types.h"
#include "inc/hw_gpio.h"

/*******************************************************************/
/* Btns_Init                                                       */
/* Parameters : N/A                                                */
/* I/p : N/A                                                       */
/* O/p : N/A                                                       */
/* Return : void                                                   */
/* Function that init btns                                         */
/*******************************************************************/
void Btns_Init(void)
{
    /* Set Btn1 peripheral clock (PORT B) */
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);
    while(!SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOF));

    /* Set Btns pins to I/P */
    GPIOPinTypeGPIOInput(PUSHBTN1PORT, PUSHBTN1PIN);
    GPIOPinTypeGPIOInput(PUSHBTN2PORT, PUSHBTN2PIN);

    /* Unlcok PF0 */
    HWREG(GPIO_PORTF_BASE+GPIO_O_LOCK) = GPIO_LOCK_KEY;
    HWREG(GPIO_PORTF_BASE+GPIO_O_CR) |= 0x01;

    /*Enable Internal PullUps */
    GPIOPadConfigSet(PUSHBTN1PORT,PUSHBTN1PIN,GPIO_STRENGTH_2MA,GPIO_PIN_TYPE_STD_WPU);
    GPIOPadConfigSet(PUSHBTN2PORT,PUSHBTN2PIN,GPIO_STRENGTH_2MA,GPIO_PIN_TYPE_STD_WPU);


}

/*******************************************************************/
/* Btn1_Read                                                       */
/* Parameters : N/A                                                */
/* I/p : N/A                                                       */
/* O/p : N/A                                                       */
/* Return : uint32                                                 */
/* Function that return btn1 state                                 */
/*******************************************************************/
uint32_t Btn1_Read(void)
{
    uint32_t BtnState = 0 ;
    BtnState = GPIOPinRead(PUSHBTN1PORT,PUSHBTN1PIN);
    if (!BtnState)
        BtnState = BTN1_ON ;
    else if(BtnState)
        BtnState = BTN1_OFF ;
    else{}
    return BtnState ;
}

/*******************************************************************/
/* Btn2_Read                                                       */
/* Parameters : N/A                                                */
/* I/p : N/A                                                       */
/* O/p : N/A                                                       */
/* Return : uint32                                                 */
/* Function that return btn2 state                                 */
/*******************************************************************/
uint32_t Btn2_Read(void)
{
    uint32_t BtnState = 0 ;
    BtnState = GPIOPinRead(PUSHBTN2PORT,PUSHBTN2PIN);
    if (!BtnState)
        BtnState = BTN2_ON ;
    else if(BtnState)
        BtnState = BTN2_OFF ;
    else{}
    return BtnState ;
}
