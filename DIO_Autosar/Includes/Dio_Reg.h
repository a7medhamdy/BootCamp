/*
 * Reg.h
 *
 *  Created on: Mar 24, 2019
 *      Author: AVE-LAP-039
 */

#ifndef INCLUDES_DIO_REG_H_
#define INCLUDES_DIO_REG_H_



#define     __I     volatile const       /* Defines 'read only' permissions */
#define     __O     volatile             /* Defines 'write only' permissions */
#define     __IO    volatile             /* Defines 'read / write' permissions */




typedef struct
{ /*DIO Structure*/
    __I uint32 RESERVED0[255];
    __IO uint32 DATA;                     /*DIO Data*/
    __IO uint32 DIR;                      /*DIO Direction*/
    __IO uint32 IS;                       /*DIO Interrupt Sense*/
    __IO uint32 IBE;                      /*DIO Interrupt Both Edges*/
    __IO uint32 IEV;                      /*DIO Interrupt Event*/
    __IO uint32 IM;                       /*DIO Interrupt Mask*/
    __IO uint32 RIS;                      /*DIO Raw Interrupt Status*/
    __IO uint32 MIS;                      /*DIO Masked Interrupt Status*/
    __O uint32 ICR;                       /*DIO Interrupt Clear*/
    __IO uint32 AFSEL;                    /*DIO Alternate Function Select*/
    __I uint32 RESERVED1[55];
    __IO uint32 DR2R;                     /*DIO 2-mA Drive Select*/
    __IO uint32 DR4R;                     /*DIO 4-mA Drive Select*/
    __IO uint32 DR8R;                     /*DIO 8-mA Drive Select*/
    __IO uint32 ODR;                      /*DIO Open Drain Select*/
    __IO uint32 PUR;                      /*DIO Pull-Up Select*/
    __IO uint32 PDR;                      /*DIO Pull-Down Select*/
    __IO uint32 SLR;                      /*DIO Slew Rate Control Select*/
    __IO uint32 DEN;                      /*DIO Digital Enable*/
    __IO uint32 LOCK;                     /*DIO Lock*/
    __I uint32 CR;                        /*DIO Commit*/
    __IO uint32 AMSEL;                    /*DIO Analog Mode Select*/
    __IO uint32 PCTL;                     /*DIO Port Control*/
    __IO uint32 ADCCTL;                   /*DIO ADC Control*/
    __IO uint32 DMACTL;                   /*DIO DMA Control*/
} DIO_Type;


/*Base Addresses of Ports*/
#define PORTA ((DIO_Type*)0x40004000)
#define PORTB ((DIO_Type*)0x40005000)
#define PORTC ((DIO_Type*)0x40006000)
#define PORTD ((DIO_Type*)0x40007000)
#define PORTE ((DIO_Type*)0x40024000)
#define PORTF ((DIO_Type*)0x40025000)



#endif /* INCLUDES_DIO_REG_H_ */
