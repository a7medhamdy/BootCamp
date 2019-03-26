/*
 * Dio_Internal.h
 *
 *  Created on: Mar 25, 2019
 *      Author: AVE-LAP-062
 */

#ifndef DIO_DIO_INTERNAL_H_
#define DIO_DIO_INTERNAL_H_

#include "Includes/Platform_Types.h"
#include "Includes/Std_Types.h"
#include "Includes/Dio.h"

/*Ports Mapping*/
#define PORTA_NO 0
#define PORTB_NO 1
#define PORTC_NO 2
#define PORTD_NO 3
#define PORTE_NO 4
#define PORTF_NO 5

/*Pins Mapping*/
#define PF_0 37
#define PF_1 38
#define PF_2 39
#define PF_3 40
#define PF_4 41

/*IDs Mapping*/
#define MAX_CHANNEL_NUM 42
#define MAX_PORT_NUM    5

/*Level Mapping*/
#define IP 0
#define OP 1

/*struct of channel*/
typedef struct
{
    uint8 Ch_ID   ;
    uint8 Pin_Num      ;
    uint8 Port         ;
    uint8 Direction    ;
}Dio_Cfg_S;


#endif /* DIO_DIO_INTERNAL_H_ */
