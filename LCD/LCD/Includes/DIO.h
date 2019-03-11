/*
 * DIO.h
 *
 * Created: 2/13/2019 2:40:37 PM
 *  Author: AVE-LAP-039
 */ 


#ifndef DIO_H_
#define DIO_H_

extern void DIO_WritePin(uint8 PinNum,uint8 PinValue);
extern uint8 DIO_ReadPin(uint8 PinNum);
extern void DIO_SetPinDirection(uint8 PinNum,uint8 PinDirection);


#endif /* DIO_H_ */