/*
 * Leds.h
 *
 *  Created on: Mar 13, 2019
 *      Author: AVE-LAP-062
 */

#ifndef INCLUDES_LEDS_H_
#define INCLUDES_LEDS_H_

#include <stdint.h>
#include <stdbool.h>
#include "inc/hw_memmap.h"
#include "driverlib/debug.h"
#include "driverlib/gpio.h"
#include "driverlib/sysctl.h"

#define LED1PORT GPIO_PORTF_BASE

#define LED1PIN GPIO_PIN_1

extern void Leds_Init(void);
extern void Led1_Switch(uint32_t Mode);

#define LED1_HIGH GPIO_PIN_1
#define LED1_LOW 0

#define LED1_ON LED1_HIGH
#define LED1_OFF LED1_LOW


#endif /* INCLUDES_LEDS_H_ */
