/*
 * Button.h
 *
 *  Created on: Mar 13, 2019
 *      Author: AVE-LAP-071
 */
#include <stdint.h>
#include <stdbool.h>
#include "inc/hw_memmap.h"
#include "driverlib/debug.h"
#include "driverlib/gpio.h"
#include "driverlib/sysctl.h"
#include "event_groups.h"
#include "queue.h"
#ifndef INCLUDES_BUTTON_H_
#define INCLUDES_BUTTON_H_

/************************************************************************/
/* Function: Button_Init                                                */
/* @param: void                                                         */
/* return: void                                                         */
/* Description: This function initialize buttons pins                   */
/************************************************************************/
extern void Button_Init (void);

/************************************************************************/
/* Function: Button1_read                                               */
/* @param: void                                                         */
/* return: uint32                                                       */
/* Description: This function read the value of button one              */
/*              and return its status                                   */
/************************************************************************/
extern uint32_t Button1_read(void);

/************************************************************************/
/* Function: Button2_read                                               */
/* @param: void                                                         */
/* return: uint32                                                       */
/* Description: This function read the value of button two              */
/*              and return its status                                   */
/************************************************************************/
extern uint32_t Button2_read(void);

/************************************************************************/
/* Function: Button1Task                                                */
/* @param: void pointer                                                 */
/* return: void                                                         */
/* Description: This task read the status of button one and             */
/*              check the debouncing, If it is pressed send message     */
/*              on the queue                                            */
/************************************************************************/
extern void Button1Task (void *pvParameters);

/************************************************************************/
/* Function: Button2Task                                                */
/* @param: void pointer                                                 */
/* return: void                                                         */
/* Description: This task read the status of button two and             */
/*              check the debouncing, If it is pressed send message     */
/*              on the queue                                            */
/************************************************************************/
extern void Button2Task (void *pvParameters);

extern QueueHandle_t xQueu;

#endif /* INCLUDES_BUTTON_H_ */
