/*
 * LED.h
 *
 * Created: 2/25/2019 11:59:26 AM
 *  Author: AVE-LAP-071
 */ 

#include "../Includes/BitwiseOperation.h"
#include "../Includes/Dio.h"
#include "../Includes/MEM_MAP_REG.h"
#include "../Includes/Types.h"
#define F_CPU 16000000UL
#include "util/delay.h"

#ifndef LED_H_
#define LED_H_





typedef enum 
{
	OFF,
	ON,
	TOGGLE,
}STATUS;

#define LED0 PIN12
#define LED1 PIN13
#define LED2 PIN14
#define LED3 PIN15
#define off 0
#define on 1
#define toggle 2



void LedInit (uint8 Pin_num);
void LedState (uint8 Pin_num, STATUS t);
#endif /* LED_H_ */