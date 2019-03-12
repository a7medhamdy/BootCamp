/*
 * Tasks.h
 *
 *  Created on: Mar 12, 2019
 *      Author: Ahmed Hamdy
 */

#ifndef INCLUDES_TASKS_H_
#define INCLUDES_TASKS_H_


/*Constants*/
/*PORTF*/
#define PORTF_ENABLE         0x20
#define PORTF_LEDS_DIR       0x0E
#define PORTF_LEDS_DEN       0x0E
#define TOGGLE_LED           0x0E
/*********************** UArt_Check_Task() *************************
*Parameters:
*           I/P: NOTHING
*           O/P: NOTHING
*           I/O: NOTHING
*Return: Nothing
*Description: Function to check UART send is done
**************************************************************/
void UArt_Check_Task(void);
/******************** Debouncing_Task() ***********************
*Parameters:
*           I/P: NOTHING
*           O/P: NOTHING
*           I/O: NOTHING
*Return: Nothing
*Description: Function to check for debouncing
**************************************************************/
void Debouncing_Task(void);

/*********************** K2S_Task() *************************
*Parameters:
*           I/P: NOTHING
*           O/P: NOTHING
*           I/O: NOTHING
*Return: Nothing
*Description: Function to get keypad value and send it by UART
**************************************************************/
void K2S_Task(void);




#endif /* INCLUDES_TASKS_H_ */
