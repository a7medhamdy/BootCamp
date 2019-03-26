/*
 * Dio.c
 *
 *  Created on: Mar 24, 2019
 *      Author: AVE-LAP-039
 */

#include "Includes/Dio.h"

/*array of struct of DIO channels*/
extern const Dio_Cfg_S Dio_Channels[MAX_SIZE];
/*array of struct of DIO group channels*/
extern const Dio_ChannelGroupType Channel_Group[MAX_SIZE];

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
FUNC(Dio_LevelType,DIO_MEM_CLASS) Dio_ReadChannel(
VAR(Dio_ChannelType,AUTOMATIC) ChannelId)
{
    /*local variables*/
    uint8 Channel_Value, Read_Channel_Index = STD_LOW;
    /*check if valid channel ID*/
    if (ChannelId > MAX_CHANNEL_NUM)
    {
        /*Channel ID DET Report */
        Det_Error(0, 0, 0, DIO_E_PARAM_INVALID_CHANNEL_ID);
    }
    else
    {
        /*loop to the size of struct*/
        for (Read_Channel_Index = STD_LOW; Read_Channel_Index < MAX_SIZE;
                Read_Channel_Index++)
        {
            /*check the channel ID*/
            if (Dio_Channels[Read_Channel_Index].Ch_ID == ChannelId)
            {
                /*check if the pin is input*/
                if (Dio_Channels[Read_Channel_Index].Direction == IP)
                {
                    /*check the port*/
                    switch (Dio_Channels[Read_Channel_Index].Port)
                    {
                    case PORTA_NO:
                        /*Read the pin in port A and store in channel_value*/
                        Channel_Value = GET_BIT(
                                PORTA->DATA,
                                Dio_Channels[Read_Channel_Index].Pin_Num);
                        break;
                    case PORTB_NO:
                        /*Read the pin in port B and store in channel_value*/
                        Channel_Value = GET_BIT(
                                PORTB->DATA,
                                Dio_Channels[Read_Channel_Index].Pin_Num);
                        break;
                    case PORTC_NO:
                        /*Read the pin in port C and store in channel_value*/
                        Channel_Value = GET_BIT(
                                PORTC->DATA,
                                Dio_Channels[Read_Channel_Index].Pin_Num);
                        break;
                    case PORTD_NO:
                        /*Read the pin in port D and store in channel_value*/
                        Channel_Value = GET_BIT(
                                PORTD->DATA,
                                Dio_Channels[Read_Channel_Index].Pin_Num);
                        break;
                    case PORTE_NO:
                        /*Read the pin in port E and store in channel_value*/
                        Channel_Value = GET_BIT(
                                PORTE->DATA,
                                Dio_Channels[Read_Channel_Index].Pin_Num);
                        break;
                    case PORTF_NO:
                        /*Read the pin in port F and store in channel_value*/
                        Channel_Value = GET_BIT(
                                PORTF->DATA,
                                Dio_Channels[Read_Channel_Index].Pin_Num);
                        break;
                    default:
                        /*PORT ID error report*/
                        Det_Error(0, 0, 0, DIO_E_PARAM_INVALID_PORT_ID);
                        break;
                    }
                }
                else
                {
                    /*Ignore*/
                }

            }
            else
            {
                /*Channel Id Det Report*/
                if (Read_Channel_Index == (MAX_SIZE - 1))
                {
                    Det_Error(0, 0, 0, DIO_E_PARAM_INVALID_CHANNEL_ID);
                }
                else
                {
                    /*To do*/
                }

            }
        }

    }
    /*return pin value*/
    return Channel_Value;
}

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
FUNC(void,DIO_MEM_CLASS) Dio_WriteChannel(
        VAR(Dio_ChannelType,AUTOMATIC) ChannelId,
        VAR(Dio_LevelType,AUTOMATIC) Level)
{
    /*Local Variables*/
    uint8 Write_Channel_Index = STD_LOW;
    /*check if valid channel ID*/
    if (ChannelId > MAX_CHANNEL_NUM)
    {
        /*Channel ID DET Report */
        Det_Error(0, 0, 0, DIO_E_PARAM_INVALID_CHANNEL_ID);
    }
    else
    {
        /*loop to the size of array of structs*/
        for (Write_Channel_Index = STD_LOW; Write_Channel_Index < MAX_SIZE;
                Write_Channel_Index++)
        {
            /*check the Id if it is in array*/
            if (Dio_Channels[Write_Channel_Index].Ch_ID == ChannelId)
            {
                /*check the pin if output*/
                if (Dio_Channels[Write_Channel_Index].Direction == OP)
                {
                    /*check the port*/
                    switch (Dio_Channels[Write_Channel_Index].Port)
                    {
                    case PORTA_NO:
                        /*check the level*/
                        if (Level == STD_HIGH)
                        {
                            /*Write high to pin in port A*/
                            SET_BIT(PORTA->DATA,
                                    Dio_Channels[Write_Channel_Index].Pin_Num);
                        }

                        else if (Level == STD_LOW)
                        {
                            /*Write low to pin in port A*/
                            CLEAR_BIT(
                                    PORTA->DATA,
                                    Dio_Channels[Write_Channel_Index].Pin_Num);
                        }
                        else
                        {
                            /*to do*/
                        }
                        break;
                    case PORTB_NO:
                        /*check the level*/
                        if (Level == STD_HIGH)
                        {
                            /*Write high to pin in port B*/
                            SET_BIT(PORTB->DATA,
                                    Dio_Channels[Write_Channel_Index].Pin_Num);

                        }

                        else if (Level == STD_LOW)
                        {
                            /*Write low to pin in port B*/
                            CLEAR_BIT(
                                    PORTB->DATA,
                                    Dio_Channels[Write_Channel_Index].Pin_Num);
                        }
                        else
                        {
                            /*to do*/
                        }

                        break;
                    case PORTC_NO:
                        /*check the level*/
                        if (Level == STD_HIGH)
                        {
                            /*Write high to pin in port C*/
                            SET_BIT(PORTC->DATA,
                                    Dio_Channels[Write_Channel_Index].Pin_Num);
                        }

                        else if (Level == STD_LOW)
                        {
                            /*Write low to pin in port C*/
                            CLEAR_BIT(
                                    PORTC->DATA,
                                    Dio_Channels[Write_Channel_Index].Pin_Num);
                        }
                        else
                        {
                            /*Nothing to do*/
                        }

                        break;
                    case PORTD_NO:
                        /*check the level*/
                        if (Level == STD_HIGH)
                        {
                            /*Write high to pin in port D*/
                            SET_BIT(PORTD->DATA,
                                    Dio_Channels[Write_Channel_Index].Pin_Num);
                        }

                        else if (Level == STD_LOW)
                        {
                            /*Write low to pin in port D*/
                            CLEAR_BIT(
                                    PORTD->DATA,
                                    Dio_Channels[Write_Channel_Index].Pin_Num);
                        }
                        else
                        {
                            /*Nothing to do*/
                        }

                        break;
                    case PORTE_NO:
                        /*check the level*/
                        if (Level == STD_HIGH)
                        {
                            /*Write high to pin in port E*/
                            SET_BIT(PORTE->DATA,
                                    Dio_Channels[Write_Channel_Index].Pin_Num);

                        }

                        else if (Level == STD_LOW)
                        {
                            /*Write low to pin in port E*/
                            CLEAR_BIT(
                                    PORTE->DATA,
                                    Dio_Channels[Write_Channel_Index].Pin_Num);
                        }
                        else
                        {
                            /*Nothing to do*/
                        }
                        break;
                    case PORTF_NO:
                        /*check the level*/
                        if (Level == STD_HIGH)
                        {
                            /*Write high to pin in port F*/
                            SET_BIT(PORTF->DATA,
                                    Dio_Channels[Write_Channel_Index].Pin_Num);
                        }

                        else if (Level == STD_LOW)
                        {
                            /*Write high to pin in port F*/
                            CLEAR_BIT(
                                    PORTF->DATA,
                                    Dio_Channels[Write_Channel_Index].Pin_Num);
                        }
                        else
                        {
                            /*Nothing to do*/
                        }

                        break;
                    default:
                        /*Port ID error report*/
                        Det_Error(0, 0, 0, DIO_E_PARAM_INVALID_PORT_ID);
                        break;
                    }
                }
                else
                {
                    /*To do*/
                }
            }
            else
            {
                /*Channel Id Det Report*/
                if (Write_Channel_Index == MAX_SIZE)
                {
                    Det_Error(0, 0, 0, DIO_E_PARAM_INVALID_CHANNEL_ID);
                }
                else
                {
                    /*To do*/
                }
                /* DET Error */
            }
        }
    }

}

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
FUNC(Dio_PortLevelType,DIO_MEM_CLASS) Dio_ReadPort(
VAR(Dio_PortType,AUTOMATIC) PortId)
{

    /*local variables*/
    uint8 Port_Value, Read_Port_Index = STD_LOW;
    /*check if valid Port ID*/
    if (PortId > MAX_PORT_NUM)
    {
        /*Port ID DET Report */
        Det_Error(0, 0, 0, DIO_E_PARAM_INVALID_PORT_ID);
    }
    else
    {
        /*loop to the size of array of structs*/
        for (Read_Port_Index = STD_LOW; Read_Port_Index < MAX_SIZE;
                Read_Port_Index++)
        {
            /*check if the port is input*/
            if (Dio_Channels[Read_Port_Index].Direction == IP)
            {
                /*check the port ID is the input ID*/
                if (Dio_Channels[Read_Port_Index].Port == PortId)
                {
                    /*check the port*/
                    switch (PortId)
                    {
                    case PORTA_NO:
                        /*read port A*/
                        Port_Value = PORTA->DATA;
                        break;

                    case PORTB_NO:
                        /*read Port B*/
                        Port_Value = PORTB->DATA;
                        break;
                    case PORTC_NO:
                        /*read Port C*/
                        Port_Value = PORTC->DATA;
                        break;
                    case PORTD_NO:
                        /*read Port D*/
                        Port_Value = PORTD->DATA;
                        break;
                    case PORTE_NO:
                        /*read Port E*/
                        Port_Value = PORTE->DATA;
                        break;
                    case PORTF_NO:
                        /*read Port F*/
                        Port_Value = PORTF->DATA;
                        break;
                    default:
                        /*Port ID DET Report */
                        Det_Error(0, 0, 0, DIO_E_PARAM_INVALID_PORT_ID);
                        break;
                    }

                }
                else
                {
                    if (Read_Port_Index == MAX_SIZE)
                    {
                        /*Port ID DET Report */
                        Det_Error(0, 0, 0, DIO_E_PARAM_INVALID_PORT_ID);
                    }
                    else
                    {
                        /*Nothing to do*/
                    }
                }
            }
            else
            {
                /*To do*/
            }
        }

    }
    /*return the read board*/
    return Port_Value;
}

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
FUNC(void,DIO_MEM_CLASS) Dio_WritePort(
        VAR(Dio_PortType,AUTOMATIC) PortId,
        VAR(Dio_PortLevelType,AUTOMATIC) Level)
{
    /*local variables*/
    uint8 Write_Port_Index = STD_LOW;
    /*check if valid Port ID*/
    if (PortId > MAX_PORT_NUM)
    {
        /*Port ID DET Report */
        Det_Error(0, 0, 0, DIO_E_PARAM_INVALID_PORT_ID);
    }
    else
    {
        /*loop to the size of array of structs*/
        for (Write_Port_Index = STD_LOW; Write_Port_Index < MAX_SIZE;
                Write_Port_Index++)
        {
            /*check the port if output*/
            if (Dio_Channels[Write_Port_Index].Direction == OP)
            {
                /*check the given port if it is valid*/
                if (Dio_Channels[Write_Port_Index].Direction == PortId)
                {
                    /*specify the port*/
                    switch (PortId)
                    {
                    case PORTA_NO:
                        /*Read port A and store its value*/
                        PORTA->DATA = Level;
                        break;
                    case PORTB_NO:
                        /*Read port B and store its value*/
                        PORTB->DATA = Level;
                        break;
                    case PORTC_NO:
                        /*Read port C and store its value*/
                        PORTC->DATA = Level;
                        break;
                    case PORTD_NO:
                        /*Read port D and store its value*/
                        PORTD->DATA = Level;
                        break;
                    case PORTE_NO:
                        /*Read port E and store its value*/
                        PORTE->DATA = Level;
                        break;
                    case PORTF_NO:
                        /*Read port F and store its value*/
                        PORTF->DATA = Level;
                        break;
                    default:
                        /*Port ID DET Report */
                        Det_Error(0, 0, 0, DIO_E_PARAM_INVALID_PORT_ID);
                        break;
                    }
                }
                else
                {
                    if (Write_Port_Index == MAX_SIZE)
                    {
                        /*Port ID DET Report */
                        Det_Error(0, 0, 0, DIO_E_PARAM_INVALID_PORT_ID);
                    }
                    else
                    {
                        /*Nothing to do*/
                    }
                }
            }
            else
            {
                /* DET Error */
            }
        }
    }

}

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
FUNC(Dio_PortLevelType,DIO_MEM_CLASS) Dio_ReadChannelGroup(
P2CONST(Dio_ChannelGroupType,AUTOMATIC,PTR_FAR) ChannelGroupIdPtr )
{
    /*local variables*/
    uint8 Ch_Group = STD_LOW , Read_Group_Index = STD_LOW;
    if (!ChannelGroupIdPtr)
    {
        /*Port ID DET Report */
        Det_Error(0, 0, 0, DIO_E_PARAM_POINTER);
    }
    else
    {
        /*loop to the size of array of structs*/
        for(Read_Group_Index=STD_LOW; Read_Group_Index<MAX_SIZE; Read_Group_Index++)
        {
            /*check the port if it is valid*/
            if(Channel_Group[Read_Group_Index].port == ChannelGroupIdPtr->port)
            {
                /*specify the given group*/
                switch(Dio_Channels[Read_Group_Index].Port)
                {
                    case PORTA_NO :
                    /*read the desired group in Port A by masking its value with port then apply offset to read from LSB*/
                    Ch_Group = (PORTA->DATA & (ChannelGroupIdPtr->mask)) >> ChannelGroupIdPtr->offset;
                    break;

                    case PORTB_NO :
                    /*read the desired group in Port B by masking its value with port then apply offset to read from LSB*/
                    Ch_Group = (PORTB->DATA & (ChannelGroupIdPtr->mask)) >> ChannelGroupIdPtr->offset;
                    break;

                    case PORTC_NO :
                    /*read the desired group in Port C by masking its value with port then apply offset to read from LSB*/
                    Ch_Group = (PORTC->DATA & (ChannelGroupIdPtr->mask)) >> ChannelGroupIdPtr->offset;
                    break;

                    case PORTD_NO :
                    /*read the desired group in Port D by masking its value with port then apply offset to read from LSB*/
                    Ch_Group = (PORTD->DATA & (ChannelGroupIdPtr->mask)) >> ChannelGroupIdPtr->offset;
                    break;

                    case PORTE_NO :
                    /*read the desired group in Port E by masking its value with port then apply offset to read from LSB*/
                    Ch_Group = (PORTE->DATA & (ChannelGroupIdPtr->mask)) >> ChannelGroupIdPtr->offset;
                    break;

                    case PORTF_NO :
                    /*read the desired group in Port F by masking its value with port then apply offset to read from LSB*/
                    Ch_Group = (PORTF->DATA & (ChannelGroupIdPtr->mask)) >> ChannelGroupIdPtr->offset;
                    break;

                    default:
                    /*Port ID DET Report */
                    Det_Error(0, 0, 0, DIO_E_PARAM_INVALID_PORT_ID);
                    break;
                }
            }
            else
            {
                if (Read_Group_Index == MAX_SIZE)
                {
                    /*Port ID DET Report */
                    Det_Error(0, 0, 0, DIO_E_PARAM_INVALID_PORT_ID);
                }
                else
                {
                    /*Nothing to do*/
                }
            }
        }
    }

    /*return the value of the group*/
    return Ch_Group;
}

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
FUNC(void,DIO_MEM_CLASS) Dio_WriteChannelGroup(
P2CONST(Dio_ChannelGroupType,AUTOMATIC,PTR_FAR) ChannelGroupIdPtr, VAR(Dio_PortLevelType,AUTOMATIC) Level )
{
    if (!ChannelGroupIdPtr)
    {
        /*Port ID DET Report */
        Det_Error(0, 0, 0, DIO_E_PARAM_POINTER);
    }
    /*local variable*/
    uint8 Write_Group_Index = STD_LOW;
    /*loop to the size of the array of structs*/
    for(Write_Group_Index = STD_LOW; Write_Group_Index<MAX_SIZE; Write_Group_Index++)
    {
        /*check if the port is valid*/
        if(Channel_Group[Write_Group_Index].port == ChannelGroupIdPtr->port )
        {
            /*specify the port*/
            switch(Dio_Channels[Write_Group_Index].Port)
            {
                case PORTA_NO :
                /*Reset Port A*/
                PORTA->DATA &= ~(ChannelGroupIdPtr->mask);
                /*check if the level is high*/
                if(Level==STD_HIGH)
                {
                    /*write the value of mask to the group*/
                    PORTA->DATA |= (ChannelGroupIdPtr->mask);
                }
                else
                {
                    /*Nothing to do*/
                }
                break;

                case PORTB_NO :
                /*Reset Port B*/
                PORTB->DATA &= ~(ChannelGroupIdPtr->mask);
                /*check if the level is high*/
                if(Level==STD_HIGH)
                {
                    /*write the value of mask to the group*/
                    PORTB->DATA |= (ChannelGroupIdPtr->mask);
                }
                else
                {
                    /*Nothing to do*/
                }
                break;

                case PORTC_NO :
                /*Reset Port C*/
                PORTC->DATA &= ~(ChannelGroupIdPtr->mask);
                /*check if the level is high*/
                if(Level==STD_HIGH)
                {
                    /*write the value of mask to the group*/
                    PORTC->DATA |= (ChannelGroupIdPtr->mask);
                }
                else
                {
                    /*Nothing to do*/
                }
                break;

                case PORTD_NO :
                /*Reset Port D*/
                PORTD->DATA &= ~(ChannelGroupIdPtr->mask);
                /*check if the level is high*/
                if(Level==STD_HIGH)
                {
                    /*write the value of mask to the group*/
                    PORTD->DATA |= (ChannelGroupIdPtr->mask);
                }
                else
                {
                    /*Nothing to do*/
                }
                break;

                case PORTE_NO :
                /*Reset Port E*/
                PORTE->DATA &= ~(ChannelGroupIdPtr->mask);
                /*check if the level is high*/
                if(Level==STD_HIGH)
                {
                    /*write the value of mask to the group*/
                    PORTE->DATA |= (ChannelGroupIdPtr->mask);
                }
                else
                {
                    /*Nothing to do*/
                }
                break;

                case PORTF_NO :
                /*Reset Port F*/
                PORTF->DATA &= ~(ChannelGroupIdPtr->mask);
                /*check if the level is high*/
                if(Level==STD_HIGH)
                {
                    /*write the value of mask to the group*/
                    PORTF->DATA |= (ChannelGroupIdPtr->mask);
                }
                else
                {
                    /*Nothing to do*/
                }
                break;

                default :
                /*Port ID DET Report */
                Det_Error(0, 0, 0, DIO_E_PARAM_INVALID_PORT_ID);
                break;
            }
        }
        else
        {
            if (Write_Group_Index == MAX_SIZE)
            {
                /*Port ID DET Report */
                Det_Error(0, 0, 0, DIO_E_PARAM_INVALID_PORT_ID);
            }
            else
            {
                /*Nothing to do*/
            }
        }
    }
}

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
FUNC(void,DIO_MEM_CLASS) Dio_GetVersionInfo(
P2VAR(Std_VersionInfoType,AUTOMATIC,PTR_FAR) VersionInfo )
{
    VersionInfo->moduleID = STD_HIGH;
    VersionInfo->sw_major_version = STD_HIGH;
    VersionInfo->sw_minor_version = STD_HIGH;
    VersionInfo->sw_patch_version = STD_HIGH;
    VersionInfo->vendorID=(uint8)5;
}

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
FUNC(Dio_LevelType,DIO_MEM_CLASS) Dio_FlipChannel(
VAR(Dio_ChannelType,AUTOMATIC) ChannelId)
{
    /*Local Variables*/
    uint8 Flipp_Channel_Index = STD_LOW;
    uint8 Channel_Level = STD_LOW;
    /*check if valid channel ID*/
    if (ChannelId > MAX_CHANNEL_NUM)
    {
        /*Channel ID DET Report */
        Det_Error(0, 0, 0, DIO_E_PARAM_INVALID_CHANNEL_ID);
    }
    else
    {
        /*loop to the size of array of structs*/
        for (Flipp_Channel_Index = STD_LOW; Flipp_Channel_Index < MAX_SIZE;
                Flipp_Channel_Index++)
        {
            /*check the Id if it is in array*/
            if (Dio_Channels[Flipp_Channel_Index].Ch_ID == ChannelId)
            {
                /*check the pin if output*/
                if (Dio_Channels[Flipp_Channel_Index].Direction == OP)
                {
                    /*check the port*/
                    switch (Dio_Channels[Flipp_Channel_Index].Port)
                    {
                    case PORTA_NO:
                        /*check the level if Low*/
                        if (!GET_BIT(PORTA->DATA,
                                     Dio_Channels[Flipp_Channel_Index].Pin_Num))
                        {
                            /*set PIN*/
                            SET_BIT(PORTA->DATA,
                                    Dio_Channels[Flipp_Channel_Index].Pin_Num);
                            Channel_Level = STD_HIGH;
                        }
                        /*check the level if High*/
                        else if (GET_BIT(
                                PORTA->DATA,
                                Dio_Channels[Flipp_Channel_Index].Pin_Num))
                        {
                            /*Write low to pin in port A*/
                            CLEAR_BIT(
                                    PORTA->DATA,
                                    Dio_Channels[Flipp_Channel_Index].Pin_Num);
                            Channel_Level = STD_LOW;
                        }
                        else
                        {
                            /*to do*/
                        }
                        break;

                    case PORTB_NO:
                        /*check the level if Low*/
                        if (!GET_BIT(PORTB->DATA,
                                     Dio_Channels[Flipp_Channel_Index].Pin_Num))
                        {
                            /*set PIN*/
                            SET_BIT(PORTB->DATA,
                                    Dio_Channels[Flipp_Channel_Index].Pin_Num);
                            Channel_Level = STD_HIGH;
                        }
                        /*check the level if High*/
                        else if (GET_BIT(
                                PORTB->DATA,
                                Dio_Channels[Flipp_Channel_Index].Pin_Num))
                        {
                            /*Write low to pin in port B*/
                            CLEAR_BIT(
                                    PORTB->DATA,
                                    Dio_Channels[Flipp_Channel_Index].Pin_Num);
                            Channel_Level = STD_LOW;
                        }
                        else
                        {
                            /*to do*/
                        }
                        break;

                    case PORTC_NO:
                        /*check the level if Low*/
                        if (!GET_BIT(PORTC->DATA,
                                     Dio_Channels[Flipp_Channel_Index].Pin_Num))
                        {
                            /*set PIN*/
                            SET_BIT(PORTC->DATA,
                                    Dio_Channels[Flipp_Channel_Index].Pin_Num);
                            Channel_Level = STD_HIGH;
                        }
                        /*check the level if High*/
                        else if (GET_BIT(
                                PORTC->DATA,
                                Dio_Channels[Flipp_Channel_Index].Pin_Num))
                        {
                            /*Write low to pin in port C*/
                            CLEAR_BIT(
                                    PORTC->DATA,
                                    Dio_Channels[Flipp_Channel_Index].Pin_Num);
                            Channel_Level = STD_LOW;
                        }
                        else
                        {
                            /*to do*/
                        }
                        break;

                    case PORTD_NO:
                        /*check the level if Low*/
                        if (!GET_BIT(PORTD->DATA,
                                     Dio_Channels[Flipp_Channel_Index].Pin_Num))
                        {
                            /*set PIN*/
                            SET_BIT(PORTD->DATA,
                                    Dio_Channels[Flipp_Channel_Index].Pin_Num);
                            Channel_Level = STD_HIGH;
                        }
                        /*check the level if High*/
                        else if (GET_BIT(
                                PORTD->DATA,
                                Dio_Channels[Flipp_Channel_Index].Pin_Num))
                        {
                            /*Write low to pin in port D*/
                            CLEAR_BIT(
                                    PORTD->DATA,
                                    Dio_Channels[Flipp_Channel_Index].Pin_Num);
                            Channel_Level = STD_LOW;
                        }
                        else
                        {
                            /*to do*/
                        }
                        break;

                    case PORTE_NO:
                        /*check the level if Low*/
                        if (!GET_BIT(PORTE->DATA,
                                     Dio_Channels[Flipp_Channel_Index].Pin_Num))
                        {
                            /*set PIN*/
                            SET_BIT(PORTE->DATA,
                                    Dio_Channels[Flipp_Channel_Index].Pin_Num);
                            Channel_Level = STD_HIGH;
                        }
                        /*check the level if High*/
                        else if (GET_BIT(
                                PORTE->DATA,
                                Dio_Channels[Flipp_Channel_Index].Pin_Num))
                        {
                            /*Write low to pin in port E*/
                            CLEAR_BIT(
                                    PORTE->DATA,
                                    Dio_Channels[Flipp_Channel_Index].Pin_Num);
                            Channel_Level = STD_LOW;
                        }
                        else
                        {
                            /*to do*/
                        }
                        break;

                    case PORTF_NO:
                        /*check the level if Low*/
                        if (!GET_BIT(PORTF->DATA,
                                     Dio_Channels[Flipp_Channel_Index].Pin_Num))
                        {
                            /*set PIN*/
                            SET_BIT(PORTF->DATA,
                                    Dio_Channels[Flipp_Channel_Index].Pin_Num);
                            Channel_Level = STD_HIGH;
                        }
                        /*check the level if High*/
                        else if (GET_BIT(
                                PORTF->DATA,
                                Dio_Channels[Flipp_Channel_Index].Pin_Num))
                        {
                            /*Write low to pin in portB*/
                            CLEAR_BIT(
                                    PORTF->DATA,
                                    Dio_Channels[Flipp_Channel_Index].Pin_Num);
                            Channel_Level = STD_LOW;
                        }
                        else
                        {
                            /*to do*/
                        }
                        break;

                    default:
                        /*Port ID DET Report */
                                                Det_Error(0, 0, 0, DIO_E_PARAM_INVALID_PORT_ID);
                        break;
                    }
                }
                else
                {
                    /*To do*/
                }
            }
            else
            {
                /*Channel Id Det Report*/
                if (Flipp_Channel_Index == (MAX_SIZE - 1))
                {
                    Det_Error(0, 0, 0, DIO_E_PARAM_INVALID_CHANNEL_ID);
                }
                else
                {
                    /*To do*/
                }
            }

        }
    }

    /*return the last state*/
    return Channel_Level;

}
