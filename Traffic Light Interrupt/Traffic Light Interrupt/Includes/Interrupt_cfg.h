/*
 * Interrupt_cfg.h
 *
 * Created: 2/21/2019 1:13:02 AM
 *  Author: AVE-LAP-039
 */ 


#ifndef INTERRUPT_CFG_H_
#define INTERRUPT_CFG_H_


#define SREG_INTERRUPT   (*(volatile ptr8)(0x5f))
#define GICR_INTERRUPT	 (*(volatile ptr8)(0x5B))
#define MCUCSR_INTERRUPT (*(volatile ptr8)(0x54))



/* GICR */
#define INT1    7
#define INT0    6
#define INT2    5
#define IVSEL   1
#define IVCE    0

/* MCUCSR */
#define ISC2    6



/**/
#define HIGH 1
#define LOW  0

/*Number for flags*/
#define ZERO  0
#define ONE   1
#define TWO   2
#define THREE 3
#define FOUR  4

#endif /* INTERRUPT_CFG_H_ */