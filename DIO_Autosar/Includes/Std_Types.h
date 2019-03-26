/*
 * Std_Types.h
 *
 *  Created on: Mar 24, 2019
 *      Author: AVE-LAP-039
 */

#ifndef INCLUDES_STD_TYPES_H_
#define INCLUDES_STD_TYPES_H_


#include "Platform_Types.h"
#include "compiler.h"





/*Specifies [SWS_Std_00005] */
#define E_OK 0
#define E_NOT_OK 1

#define STD_LOW         0
#define STD_HIGH        1


/*Specifies [SWS_Std_00015]*/
typedef struct{
    uint16 vendorID;
    uint16 moduleID;
    uint8 sw_major_version;
    uint8 sw_minor_version;
    uint8 sw_patch_version;
}Std_VersionInfoType;



#endif /* INCLUDES_STD_TYPES_H_ */
