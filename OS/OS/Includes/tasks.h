/*
 * tasks.h
 *
 * Created: 2/23/2019 3:55:40 PM
 *  Author: AVE-LAP-039
 */ 


#ifndef TASKS_H_
#define TASKS_H_

/* Set Number of tasks */
#define TASKS_NUMBER 4

/* Define Leds Pins */
#define LED0 12
#define LED1 13
#define LED2 14
#define LED3 15

/*states*/
#define HIGH 1
#define LOW  0

/*Prototypes of different tasks*/
extern void Led0_Task();
extern void Led1_Task();
extern void Led2_Task();
extern void Led3_Task();



#endif /* TASKS_H_ */