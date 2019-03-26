/******************************************************************************
 *
 * Module: Det
 *
 * File Name: Det.c
 *
 * Description:  Det stores the development errors reported by  modules.
 *
 * Author: Ahmed Hamdy
 ******************************************************************************/

#include "Includes/Det.h"
#include "Includes/BitwiseOperations.h"
#include "Includes/Dio_Reg.h"

#define LED_1 1
#define LED_2 2
#define LED_3 3

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
FUNC(uint8,memclass) Det_Error(
VAR(uint16,memclass) ModuleId,
                                        VAR(uint8,memclass) InstanceId,
                                        VAR(uint8,memclass) ApiId,
                                        VAR(uint8,memclass) ErrorId)
{
    uint8 Not_OK = STD_HIGH;
    /* Check type of error*/
    switch (ErrorId)
    {
    /* check if the channel ID is invalid*/
    case DIO_E_PARAM_INVALID_CHANNEL_ID:
        SET_BIT(PORTF->DATA, LED_1);
        SET_BIT(PORTF->DATA, LED_2);
        SET_BIT(PORTF->DATA, LED_3);
        break;

        /* check if the Port is invalid*/
    case DIO_E_PARAM_INVALID_PORT_ID:
        SET_BIT(PORTF->DATA, LED_2);
        break;

        /* check if the group is invalid*/
    case DIO_E_PARAM_INVALID_GROUP:
        SET_BIT(PORTF->DATA, LED_3);
        break;
        /* check if the pointer if it is null*/
    case DIO_E_PARAM_POINTER:
        SET_BIT(PORTF->DATA, LED_1);
        break;

    default:
        /*To do*/
        break;
    }
    return Not_OK;
}
