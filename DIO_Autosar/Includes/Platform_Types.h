/*
 * Platform_Types.h
 *
 *  Created on: Mar 24, 2019
 *      Author: Ahmed Hamdy
 */

#ifndef INCLUDES_PLATFORM_TYPES_H_
#define INCLUDES_PLATFORM_TYPES_H_


/*satisfies [SWS_Platform_00026]*/
#define FALSE 0
#define TRUE  1

/*satisfies [SWS_Platform_00013]*/
typedef unsigned char uint8;

/*satisfies [SWS_Platform_00016]*/
typedef signed char sint8;

/*satisfies [SWS_Platform_00014]*/
typedef unsigned short uint16;

/*satisfies [SWS_Platform_00017]*/
typedef signed short sint16;

/*satisfies [SWS_Platform_00015]*/
typedef unsigned long uint32;

/*satisfies [SWS_Platform_00018]*/
typedef signed long sint32;

/*satisfies [SWS_Platform_00066]*/
typedef unsigned long long uint64;

/*satisfies [SWS_Platform_00067]*/
typedef signed long long sint64;

/*satisfies [SWS_Platform_00020]*/
typedef unsigned char uint8_least;

/*satisfies [SWS_Platform_00023]*/
typedef signed char sint8_least;

/*satisfies [SWS_Platform_00021]*/
typedef unsigned short uint16_least;

/*satisfies [SWS_Platform_00024]*/
typedef signed short sint16_least;

/*satisfies [SWS_Platform_00022]*/
typedef unsigned long uint32_least;

/*satisfies [SWS_Platform_00025]*/
typedef signed long sint32_least;

/*satisfies [SWS_Platform_00041]*/
typedef float float32;

/*satisfies [SWS_Platform_00042]*/
typedef double float64;

/************************General Type Definitions************************/
#define CPU_TYPE_8 8
#define CPU_TYPE_16 16
#define CPU_TYPE_32 32
#define CPU_TYPE_64 64
#define MSB_FIRST 0
#define LSB_FIRST 1
#define HIGH_BYTE_FIRST 0
#define LOW_BYTE_FIRST 1
/***************************Symbols **********************************/
#define CPU_TYPE CPU_TYPE_16
#define CPU_BIT_ORDER LSB_FIRST
#define CPU_BYTE_ORDER HIGH_BYTE_FIRST


#endif /* INCLUDES_PLATFORM_TYPES_H_ */





