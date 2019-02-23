/*
 * scheduler.h
 *
 * Created: 2/23/2019 3:55:03 PM
 *  Author: AVE-LAP-039
 */ 


#ifndef SCHEDULER_H_
#define SCHEDULER_H_


/*Scheduler APIs*/
extern void schedulerInit_AndStart();
extern void TTC_Scheduler(void);
extern void set_flag(void);

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