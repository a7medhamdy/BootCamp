/*
 * led.h
 *
 * Created: 3/11/2019 5:03:22 PM
 *  Author: AVE-LAP-023
 */ 


#ifndef LED_H_
#define LED_H_

#include "../Includes/Types.h"
#include "../Includes/led_cfg.h"

/**************************************************************************************************/
/*Function Name :- LedInit                                                                        */
/*Function job   :-initialize to led pin to be output                                             */
/*Function inputs :- N/A                                                                          */
/*Function outputs :- N/A                                                                         */
/**************************************************************************************************/
void LedInit(uint8 pin_num);


/**************************************************************************************************/
/*Function Name :- LedState                                                                       */
/*Function job   :- operate led as required if on, off or toggle                                  */
/*Function inputs :-led number and required status                                                */
/*Function outputs :- N/A                                                                         */
/**************************************************************************************************/
void LedState(uint8 pin_num, STATUS t);


#endif /* LED_H_ */