/*
 * Timer.h
 *
 * Created: 2/14/2019 9:32:08 AM
 *  Author: AVE-LAP-039
 */ 


#ifndef TIMER_H_
#define TIMER_H_

#include "Types.h"

#define TCCR0 (*(volatile ptr8)(0x53))
#define TCNT0 (*(volatile ptr8)(0x52))
#define OCR0  (*(volatile ptr8)(0x5c))
#define TIFR  (*(volatile ptr8)(0x58))





void timer_delay(uint32 n);

#endif /* TIMER_H_ */