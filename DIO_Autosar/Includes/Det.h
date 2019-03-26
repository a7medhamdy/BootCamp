/*
 * Det.h
 *
 *  Created on: Mar 24, 2019
 *      Author: Ahmed Hamdy
 */

#ifndef INCLUDES_DET_H_
#define INCLUDES_DET_H_

#include "Includes/Std_Types.h"

/*Errors ID*/
#define DIO_E_PARAM_INVALID_CHANNEL_ID  0x0Au
#define DIO_E_PARAM_INVALID_PORT_ID     0x14u
#define DIO_E_PARAM_INVALID_GROUP       0x1Fu
#define DIO_E_PARAM_POINTER             0x20u

/************************************************************************************
 * Service Name: Det_ReportError
 * Sync/Async: Synchronous
 * Reentrancy: Reentrant
 * Parameters (in): ModuleId ,InstanceId , ApiId , ErrorId
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: Std_ReturnType
 * Description: Function to report errors.
 * [SWS_Dio_00140]
 ************************************************************************************/
extern FUNC(uint8,memclass) Det_Error(
        VAR(uint16,memclass) ModuleId, VAR(uint8,memclass) InstanceId,
        VAR(uint8,memclass) ApiId, VAR(uint8,memclass) ErrorId);

#endif /* INCLUDES_DET_H_ */

