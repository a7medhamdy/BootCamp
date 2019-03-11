/*
 * UART.h
 *
 * Created: 2/27/2019 1:12:21 PM
 *  Author: Marwan
 */ 


#ifndef UART_H_
#define UART_H_
#include "Types.h"
#include "BitwiseOperation.h"
#include "Config_UART.h"
#include "Dio.h"


/**************************************************************************************************/
/*Name : UART_init																	               */
/*Parameters : 	void																		     */
/*Inputs : baud rate																			 */
/*Outputs:  N/A																					*/
/*Description:   UART Module initialization                                                      */
/**************************************************************************************************/
void UART_Init(void);

/**************************************************************************************************/
/*Name : UART_Transmit																	           */
/*Parameters : 	uint8 data																	     */
/*Inputs : data																					 */
/*Outputs:  N/A																					*/
/*Description:   Function that transmits data through UART                                         */
/**************************************************************************************************/

void UART_Transmit(uint8 Data);
/**************************************************************************************************/
/*Name : UART_Recieve																	           */
/*Parameters : 	uint8 data																	     */
/*Inputs : void																				 */
/*Outputs:  data																				*/
/*Description:   Function that Receives data through UART                                         */
/**************************************************************************************************/

uint8 UART_Recieve(void);


/**************************************************************************************************/
/*Name : UART_TransmitString																	     */
/*Parameters : 	uint8 data	, uint8 Size															 */
/*Inputs : data	, size																				*/
/*Outputs:  N/A																						*/
/*Description:   Function that transmits String data through UART                                  */
/**************************************************************************************************/

void UART_TransmitString(uint8* String);



/*Structure Type definition*/
typedef struct  {
	uint32 BaudRate ;
	uint8  No_StopBits ;
	uint8  ParityMode ;
	uint8  DataSize ;
	uint8  SpeedMode ;
}UART_Config_S ;




#endif /* UART_H_ */