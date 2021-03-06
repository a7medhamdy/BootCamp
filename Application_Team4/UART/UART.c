

#include "../Includes/UART.h"
#include "Includes/types.h"
#include "Includes/scheduler.h"
#include "Includes/TM4C123GH6PM.h"

uint8 uart_transmit_fifnish = 0;
/***********************************************************************/
/* Function name :- UART_init
 * Function job :- initialize uart
 * Function inputs :- N/A
 * Function outputs :- N/A
/**********************************************************************/
void UART0_init(void)
{
    /* enable uart peripheral */
    SysCtlPeripheralEnable(SYSCTL_PERIPH_UART0);
          /* wait for uart module to be ready */
      while(!SysCtlPeripheralReady(SYSCTL_PERIPH_UART0))
         {
         }
      /* enable uart pins on porta */

      SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOA);

          /* wait for port A to be enabled */
      while(!SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOA))
        {
        }
            /* set PA0 and PA1 to be uart pins */
             GPIOPinConfigure(GPIO_PA0_U0RX);
             GPIOPinConfigure(GPIO_PA1_U0TX);
             GPIOPinTypeUART(GPIO_PORTA_BASE, GPIO_PIN_0 | GPIO_PIN_1);

/* Initialize the UART. Set the baud rate, number of data bits, turn off
 parity, number of stop bits, and stick mode. The UART is enabled by the

 */
      UARTConfigSetExpClk(UART0_BASE, SysCtlClockGet(), 9600,
      (UART_CONFIG_WLEN_8 | UART_CONFIG_STOP_ONE |  UART_CONFIG_PAR_NONE));


}

/**************************************************************************************************/
/*Function Name :- UART_TransmittStart                                                            */
/*Function job   :- sending byte bu uart                                                          */
/*Function inputs :- sending character                                                            */
/*Function outputs :- N/A                                                                         */
/**************************************************************************************************/
void UART0_TransmitStart(uint8 data)
{
    /* sending data by uart with out waiting for it */
    UARTCharPutNonBlocking(UART0_BASE,data);
}

/**************************************************************************************************/
/*Function Name :- UART0_TransmitCheck                                                            */
/*Function job   :- sending byte bu uart                                                          */
/*Function inputs :- sending character                                                            */
/*Function outputs :- N/A                                                                         */
/**************************************************************************************************/
void UART0_TransmitCheck(void){
    /* waith until data sent */
    if(!UARTBusy(UART0_BASE)){
        uart_transmit_fifnish = 1;
    }
}


/**************************************************************************************************/
/*Function Name :- UART_receive                                                               */
/*Function job   :-receiving byte by uart                                                         */
/*Function inputs :- N/A                                                                          */
/*Function outputs :-byte received                                                               */
/**************************************************************************************************/

uint8 UART0_receive(void)
{
    /* loop until register has data */
    while(!UARTCharsAvail(UART0_BASE))
    {
    }
   /* return recieved value */
  return  UARTCharGetNonBlocking(UART0_BASE);

}
