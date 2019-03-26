

/**
 * main.c
 */
#include "Includes/Std_Types.h"
#include "Includes/Dio_Reg.h"
#include "Includes/Dio_Internal.h"

#define SYSCTL_RCGC2_R (*((volatile unsigned long *)0x400FE108))
void main(void);
void Init_func(void);

void Dio_WriteChannel_Test(void);


void Dio_WriteChannel_Test_Valid(void);

void Dio_WriteChannel_Test_Invalid(void);



void main(void)
{

    Init_func();
    while(1)
   {
        /*
        if (!Dio_ReadChannel(41))
        {
            Dio_WriteChannel(38,1);
        }
        else
        {
            Dio_WriteChannel(38,0);
        }

*/
         Dio_WriteChannel_Test();
}
}



void Init_func(void)
{
    /*Activate clock for Port F*/
   SYSCTL_RCGC2_R |= 0x00000020;

   /*Activate PORTF Clock*/
  volatile unsigned long delay=SYSCTL_RCGC2_R;


   /*Disable Analog Function of PORTF*/
   PORTF->AMSEL = (uint32)0x00 ;
   /*Set Direction of PF1 , PF2 , PF3 output*/
   /*Set Direction of PF1 , PF2 , PF3 output , PF4 i/p */
   PORTF->DIR |= 0x0E ;
   /*Disable Alternate Function of PORTF*/
   PORTF->AFSEL = (uint32)0x00 ;
   /*Enable digital I/O on PF1 , PF2 , PF3 */
   PORTF->DEN =(uint32) 0xff ;
   /* Enable internal pull up */
    PORTF->PUR = 0x11;
    PORTF->DATA = 0x00;
}




/************************************************************************************
 * API Name: Dio_WriteChannel_Test
 * DEscription: call DIO_Write with valid and invalid channel ID

 ************************************************************************************/
void Dio_WriteChannel_Test(void)
{
    //Dio_WriteChannel_Test_Valid();
    Dio_WriteChannel_Test_Invalid();
}

/************************************************************************************
 * API Name: Dio_WriteChannel_Test_Valid
 * DEscription: sent a valid channel ID

 ************************************************************************************/
void Dio_WriteChannel_Test_Valid(void)
{
    /*Set led 1 to turn on the red light*/
    Dio_WriteChannel(38,1);
}

/************************************************************************************
 * API Name: Dio_WriteChannel_Test_Valid
 * DEscription: sent a invalid channel ID

 ************************************************************************************/
void Dio_WriteChannel_Test_Invalid(void)
{
    /*report to det which turn on white light*/
    Dio_WriteChannel(45,1);
}

