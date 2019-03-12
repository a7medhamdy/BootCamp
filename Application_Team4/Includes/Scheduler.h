/*
 * Scheduler.h
 *
 *  Created on: Mar 12, 2019
 *      Author: AVE-LAP-039
 */

#ifndef INCLUDES_SCHEDULER_H_
#define INCLUDES_SCHEDULER_H_

/*Prototype of array of structure*/

#define MAX_TASK_NUMBER 4
typedef struct
{
    void(*ptr_func)(void); /*Pointer to function*/
    uint32 Task_Periodicity;    /*Task periodicity*/
    uint32 Remaining_Ticks;     /*Remaining Ticks*/
    uint8 Piriority;
}Tasks;

/*array of structures*/
Tasks Tasks_Arr[MAX_TASK_NUMBER];

/*Scheduler APIs*/
/********************** schedulerInit() *********************
*Parameters:
*           I/P: Tasks Number, Array of Periodicities
*           O/P: NOTHING
*           I/O: NOTHING
*Return: Nothing
*Description: This Function set the periodicity of each task
              and calculate the remaining ticks
**************************************************************/
extern void schedulerInit(uint32 Task_Num);


/******************** schedulerStart() ***********************
*Parameters:
*           I/P: NOTHING
*           O/P: NOTHING
*           I/O: NOTHING
*Return: Nothing
*Description: This Function Starts the OS scheduler
**************************************************************/
extern void schedulerStart();


/****************** scheduler_Add_Task() *********************
*Parameters:
*           I/P: Pointer to function
*           O/P: NOTHING
*           I/O: NOTHING
*Return: Nothing
*Description: This Function extend the array with the new task
**************************************************************/
extern uint8 scheduler_Add_Task(Tasks *S_ptr);


/********************* TTC_Scheduler() ************************
*Parameters:
*           I/P: NOTHING
*           O/P: NOTHING
*           I/O: NOTHING
*Return: Nothing
*Description: This Function has the Algorithm that choose which
              task to be executed
**************************************************************/
extern void TTC_Scheduler(void);


/*********************** set_flag () **************************
*Parameters:
*           I/P: NOTHING
*           O/P: NOTHING
*           I/O: NOTHING
*Return: Nothing
*Description: This Function Set flag to High When After
              ISR execution
**************************************************************/
extern void set_flag(void);


/*Constants*/
#define INITIAL 0
#define ZERO    0
#define ONE     1

/*States*/
#define TRUE  1
#define FALSE 0
#define HIGH  1
#define LOW   0



#endif /* INCLUDES_SCHEDULER_H_ */
