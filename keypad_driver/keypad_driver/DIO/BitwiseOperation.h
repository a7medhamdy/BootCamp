/*
 * BitwiseOperation.h
 *
 * Created: 2/13/2019 11:38:21 AM
 *  Author: AVE-LAP-039
 */ 


#ifndef BITWISEOPERATION_H_
#define BITWISEOPERATION_H_

#include"Types.h"

#define Set_Bit(Register,Bit)		(Register = (uint8)Register |((uint8)1<<Bit))
#define Clear_Bit(Register,Bit)		(Register = (uint8)Register &(~((uint8)1<<Bit)))
#define Get_Bit(Register,Bit)		((Register&((uint8)1<<Bit))>>Bit)
#define Toggle_Bit(Register,Bit)	(Register = (uint8)Register ^ ((uint8)1<<Bit))




#endif /* BITWISEOPERATION_H_ */