/*
 * SysTick.h
 *
 *  Created on: Mar 13, 2019
 *      Author: AVE-LAP-039
 */

#ifndef INCLUDES_SYSTICK_H_
#define INCLUDES_SYSTICK_H_

void SysTick_Delay(uint32_t delay);

#define MS_1            16000
#define SYSTICK_CTRL    5
#define SYSTICK_SHIFT   (1<<16)


#endif /* INCLUDES_SYSTICK_H_ */
