/*
 * Dio_Lcfg.c
 *
 *  Created on: Mar 25, 2019
 *      Author: AVE-LAP-039
 */



#include "Includes/Dio.h"
#include "Includes/Dio_Internal.h"
#include "Includes/Dio_Cfg.h"

/*array of structs of channels*/
const Dio_Cfg_S Dio_Channels[MAX_SIZE] = {{PF_1,1,PORTF_NO,OP},{PF_4,4,PORTF_NO,IP}};
/*array of structs of channel groups*/
const Dio_ChannelGroupType Channel_Group[MAX_SIZE] = {{0x0E,0,PORTF_NO},{0xBB,0,PORTF_NO}};
