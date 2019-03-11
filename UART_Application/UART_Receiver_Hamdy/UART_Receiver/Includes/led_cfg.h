/*
 * led_cfg.h
 *
 * Created: 3/11/2019 5:22:01 PM
 *  Author: AVE-LAP-023
 */ 


#ifndef LED_CFG_H_
#define LED_CFG_H_

/* enum that holds led status possible to be operated on leds */
typedef enum
{
	OFF  , ON  , TOGGLE 
	}STATUS;


#define led0 12     /* pin value of led0 on board */
#define led1 13       /* pin value of led1 on board */
#define led2 14          /* pin value of led2 on board */
#define led3 15        /* pin value of led3 on board */





#endif /* LED_CFG_H_ */