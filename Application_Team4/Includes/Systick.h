/*
 * Systick.h
 *
 *  Created on: Mar 12, 2019
 *      Author: Ahmed Hamdy
 */

#ifndef SYSTICK_SYSTICK_H_
#define SYSTICK_SYSTICK_H_

#include <stdint.h>
/************************************************************************/
/* Function: SysTick_INIT                                               */
/* @param: Tick                                                         */
/* return: void                                                         */
/* Description: function Initialize Systick                             */
/************************************************************************/
void SysTick_INIT(uint32_t Tick);

/************************************************************************/
/* Function: IntMasterEnable                                            */
/* @param: void                                                         */
/* return: void                                                         */
/* Description: function Enable Master Interrupt                        */
/************************************************************************/
void IntMasterEnable(void);

/************************************************************************/
/* Function: SysTickIntEnable                                           */
/* @param: void                                                         */
/* return: void                                                         */
/* Description: function Enable SysTick Interrupt                       */
/************************************************************************/
void SysTickIntEnable(void);

/************************************************************************/
/* Function: SysTickEnable                                              */
/* @param: void                                                         */
/* return: void                                                         */
/* Description: function Enable SysTick                                 */
/************************************************************************/
void SysTickEnable(void);

/************************************************************************/
/* Function: set_call_back                                              */
/* @param: void                                                         */
/* return: void                                                         */
/* Description: This function sets call back pointer to function        */
/*              to equal the input pointer to function                  */
/************************************************************************/
void set_call_back(void(*ptr)(void));


#endif /* SYSTICK_SYSTICK_H_ */

