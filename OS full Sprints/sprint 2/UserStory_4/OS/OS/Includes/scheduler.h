/*
 * scheduler.h
 *
 * Created: 2/23/2019 3:55:03 PM
 *  Author: AVE-LAP-039
 */ 


#ifndef SCHEDULER_H_
#define SCHEDULER_H_

/*Prototype of array of structure*/

typedef struct
{
	void(*ptr_func)(void); /*Pointer to function*/
	uint32 Task_Periodicity;	/*Task periodicity*/
	uint32 Remaining_Ticks;		/*Remaining Ticks*/
	uint8 Piriority;
}Tasks;


/*array of structures*/
Tasks Tasks_Arr[MAX_TASK_NUMBER];

/*Scheduler APIs*/
extern void schedulerInit(uint32 Task_Num);
extern void schedulerStart();
extern uint8 scheduler_Add_Task(Tasks *S_ptr);
extern void TTC_Scheduler(void);
extern void set_flag(void);


/*Remove task if equal this priority*/
#define NOT_AVAILABLE_PRIORITY 100

/*Constants*/
#define INITIAL 0
#define ZERO	0
#define ONE		1

/*States*/
#define TRUE  1
#define FALSE 0
#define HIGH  1
#define LOW   0

#endif /* SCHEDULER_H_ */