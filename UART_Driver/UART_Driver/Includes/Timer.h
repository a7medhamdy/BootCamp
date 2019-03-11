#ifndef _TIMER_H_

#define _TIMER_H_
#include "Types.h"
#include "BitwiseOperation.h"
#include "Dio.h"
#include "MEM_MAP_REG.h"



#ifndef F_CPU
#define F_CPU 16000000UL
#endif

#define NULL 0
#define RESET 0x00
#define ONE_SEC   1000


typedef void (*callback_Type) (void);


/************************************************************************/
/* OS_Timer_init */
/* Parameters : Null */
/* I/p : uint8 Compare_Time */
/* O/p : void */
/* Return : void */
/* Initialize Timer Zero with CTC mode */
/************************************************************************/

extern void OS_Timer_init(uint8 Compare_Time); 


/************************************************************************/
/* SetCallBack */
/* Parameters : pointer to function */
/* I/p : void (*callback)(void) */
/* O/p : void */
/* Return : void */
/* Set the call back pointer to the function */
/************************************************************************/

void SetCallBack(void (*callback)(void));





#endif
