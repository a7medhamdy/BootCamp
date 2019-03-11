/*
 * Keypad.h
 *
 * Created: 2/18/2019 2:55:48 PM
 *  Author: AVE-LAP-039
 */ 


#ifndef KEYPAD_H_
#define KEYPAD_H_
#include "DIO.h"
#include "Keypad_cfg.h"






extern void Keypad_init();
extern uint8 Keypad_getPressedKey();

#endif /* KEYPAD_H_ */