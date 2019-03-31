/*
 * Manager.c
 *
 *  Created on: Mar 20, 2019
 *      Author: Ahmed Hamdy
 */


#include <stdint.h>
#define ULTRASONIC_FACTOR   2.55535
#define FIVE_SHIFT          5
#define DATA_MASK           0x1F

/************************************************************************/
/* Function: LCD get_distance                                           */
/* @param: Duty Cycle                                                   */
/* return: Distance                                                     */
/* Description: function takes the duty cycle and calculate             */
/*              the distance based on the ultrasonic equation           */
/************************************************************************/
uint8_t get_distance(uint8_t duty)
{
    uint8_t distance =  ULTRASONIC_FACTOR * duty ;
    return distance;
}

/************************************************************************/
/* Function: AlignData                                                  */
/* @param: command, distance                                            */
/* return: concatenated data                                            */
/* Description: function takes the distance and the command             */
/*              and concatenate them together in data and return it     */
/************************************************************************/
uint8_t AlignData_send(uint8_t command,uint8_t distance)
{
    uint8_t data = (command << FIVE_SHIFT) | distance;
    return data;
}


/************************************************************************/
/* Function: Analysis_Data                                              */
/* @param: data                                                         */
/* return: command, distance                                            */
/* Description: function takes the data and divided it into command     */
/*              distance                                                */
/************************************************************************/
uint8_t AlignData_recv(uint8_t data)
{
    uint8_t command  = data >> FIVE_SHIFT;
    uint8_t distance = data & DATA_MASK;
}

