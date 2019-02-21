/*
 * BitwiseOperation.h
 *
 * Created: 2/13/2019 11:38:21 AM
 *  Author: AVE-LAP-039
 */ 


#ifndef BITWISEOPERATION_H_
#define BITWISEOPERATION_H_


/* Write 1 ON PIN */
#define SET_BIT(Register,Bit)		(Register = (uint8)Register |((uint8)1<<Bit))

/* write 0 ON PIN */
#define CLEAR_BIT(Register,Bit)		(Register = (uint8)Register &(~((uint8)1<<Bit)))

/* Read PIN */
#define GET_BIT(Register,Bit)		((Register&((uint8)1<<Bit))>>Bit)

/* TOGGLE PIN */
#define TOGGLE_BIT(Register,Bit)	(Register = (uint8)Register ^ ((uint8)1<<Bit))




#endif /* BITWISEOPERATION_H_ */