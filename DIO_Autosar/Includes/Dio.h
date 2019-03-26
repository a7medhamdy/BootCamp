/*
 * Dio.h
 *
 *  Created on: Mar 24, 2019
 *      Author: AVE-LAP-039
 */

#ifndef INCLUDES_DIO_H_
#define INCLUDES_DIO_H_

#include "Includes/Std_Types.h"
#include "Includes/Dio_Internal.h"
#include "Includes/Dio_Cfg.h"
#include "Includes/Dio_Reg.h"
#include "Includes/BitwiseOperations.h"
#include "Includes/Det.h"

/*specifies [SWS_Dio_00182]*/
typedef uint8 Dio_ChannelType;

/*specifies [SWS_Dio_00183]*/
typedef uint8 Dio_PortType;

/*specifies [SWS_Dio_00186]*/
typedef uint8 Dio_PortLevelType;

/*Specifies [SWS_Std_00007]*/
typedef uint8 Dio_LevelType;

/*specifies [SWS_Dio_00183]*/
typedef uint8 DioPortOffset;
typedef uint8 DioPortMask;
typedef struct
{
    DioPortMask mask;
    DioPortOffset offset;
    Dio_PortType port;
} Dio_ChannelGroupType;


/************************************************************************************
 * Service Name: Dio_ReadChannel
 * Satisfies [SWS_Dio_00133]
 * Sync/Async: Synchronous
 * Reentrancy: Reentrant
 * Parameters (in): ChannelId - ID of DIO channel.
 *                  Level - Value to be written.
 * Parameters (I/O): None
 * Parameters (out): None
 * Return value:     Dio_LevelType
 * Description:  Function to return level of channel.
 ************************************************************************************/
extern FUNC(Dio_LevelType,DIO_MEM_CLASS) Dio_ReadChannel(
        VAR(Dio_ChannelType,AUTOMATIC) ChannelId);

/************************************************************************************
 * Service Name: Dio_WriteChannel
 * Satisfies [SWS_Dio_00134]
 * Sync/Async: Synchronous
 * Reentrancy: Reentrant
 * Parameters (in): ChannelId - ID of DIO channel.
 *                  Level - Value to be written.
 * Parameters (I/O): None
 * Parameters (out): None
 * Return value:     None
 * Description:  Function to set a level of a channel.
 ************************************************************************************/
extern FUNC(void,DIO_MEM_CLASS) Dio_WriteChannel(
        VAR(Dio_ChannelType,AUTOMATIC) ChannelId,
        VAR(Dio_LevelType,AUTOMATIC) Level);

/************************************************************************************
 * Service Name: Dio_ReadPort
 * Satisfies [SWS_Dio_00135]
 * Sync/Async: Synchronous
 * Reentrancy: Reentrant
 * Parameters (in): PortId - ID of DIO port..
 * Parameters (I/O): None
 * Parameters (out): None
 * Return value: Dio_PortLevelType
 * Description:  Function to read a level of a port.
 ************************************************************************************/
extern FUNC(Dio_PortLevelType,DIO_MEM_CLASS) Dio_ReadPort(
        VAR(Dio_PortType,AUTOMATIC) PortId);

/************************************************************************************
 * Service Name: Dio_WritePort
 * Satisfies [SWS_Dio_00136]
 * Sync/Async: Synchronous
 * Reentrancy: Reentrant
 * Parameters (in): PortId - ID of DIO port.
 *                  Level - Value to be written.
 * Parameters (I/O): None
 * Parameters (out): None
 * Return value: Dio_PortLevelType
 * Description:  Function to set a level of a port.
 ************************************************************************************/
extern FUNC(void,DIO_MEM_CLASS) Dio_WritePort(
        VAR(Dio_PortType,AUTOMATIC) PortId,
        VAR(Dio_PortLevelType,AUTOMATIC) Level);

/************************************************************************************
 * Service Name: Dio_ReadChannelGroup
 * Satisfies [SWS_Dio_00137]
 * Sync/Async: Synchronous
 * Reentrancy: Reentrant
 * Parameters (in): ChannelGroupIdPtr - const pointer to channel group
 * Parameters (I/O): None
 * Parameters (out): None
 * Return value: Dio_PortLevelType
 * Description:  Function to read a level of a channel group.
 ************************************************************************************/
extern FUNC(Dio_PortLevelType,DIO_MEM_CLASS) Dio_ReadChannelGroup(
        P2CONST(Dio_ChannelGroupType,AUTOMATIC,PTR_FAR) ChannelGroupIdPtr );

/************************************************************************************
 * Service Name: Dio_WriteChannelGroup
 * Satisfies [SWS_Dio_00138]
 * Sync/Async: Synchronous
 * Reentrancy: Reentrant
 * Parameters (in): ChannelGroupIdPtr - pointer to channel group.
 *                  Level - Value to be written.
 * Parameters (I/O): None
 * Parameters (out): None
 * Return value: None
 * Description: Function to set a level of a channel group.
 ************************************************************************************/
extern FUNC(void,DIO_MEM_CLASS) Dio_WriteChannelGroup(
        P2CONST(Dio_ChannelGroupType,AUTOMATIC,PTR_FAR) ChannelGroupIdPtr, VAR(Dio_PortLevelType,AUTOMATIC) Level );

/************************************************************************************
 * Service Name: Dio_GetVersionInfo
 * Satisfies [SWS_Dio_00139]
 * Sync/Async: Synchronous
 * Reentrancy: Reentrant
 * Parameters (in): None
 * Parameters (inout): None
 * Parameters (out): VersionInfo - Pointer to where to store the version information of this module.
 * Return value: None
 * Description: Function to get the version information of this module.
 ************************************************************************************/
extern FUNC(void,DIO_MEM_CLASS) Dio_GetVersionInfo(
        P2VAR(Std_VersionInfoType,AUTOMATIC,PTR_FAR) VersionInfo );

/************************************************************************************
 * Service Name: Dio_FlipChannel
 * Satisfies [SWS_Dio_00190]
 * Sync/Async: Synchronous
 * Reentrancy: Reentrant
 * Parameters (in): ChannelId - ID of DIO channel.
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: Dio_LevelType
 * Description: Function to flip the level of a channel and return the level of the channel after flip.
 ************************************************************************************/
extern FUNC(Dio_LevelType,DIO_MEM_CLASS) Dio_FlipChannel(
        VAR(Dio_ChannelType,AUTOMATIC) ChannelId);


#endif /* INCLUDES_DIO_H_ */
