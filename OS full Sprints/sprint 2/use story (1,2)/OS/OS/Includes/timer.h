/*
 * timer.h
 *
 * Created: 2/23/2019 4:33:34 PM
 *  Author: AVE-LAP-039
 */ 


#ifndef TIMER_H_
#define TIMER_H_

/*The OS Tic Interval*/
#define OS_TICK_INTERVAL_MSEC 1



/*APIs*/
void timer_init();
void set_call_back(void(*ptr)(void));


#endif /* TIMER_H_ */