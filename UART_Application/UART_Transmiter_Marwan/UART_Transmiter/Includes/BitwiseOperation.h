#ifndef _BITWISEOPERATIONS_H_
#define _BITWISEOPERATIONS_H_

#define Set_Bit(Register,Bit)  Register =(uint8) Register | (1<<Bit)
#define Clear_Bit(Register,Bit)  Register=(uint8) Register & ~(1<<Bit)
#define Toggle_Bit(Register,Bit)  Register=(uint8) Register ^ (1<<Bit)
#define Get_Bit(Register,Bit)   (Register= ((uint8) Register & (1<<Bit)))




#endif