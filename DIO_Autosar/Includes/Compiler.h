/******************************************************************************
*
* Module: common platform
*
* File Name: Compiler.h
*
* Description:
*
* Author: AVE LAP 023
*
*******************************************************************************/

#ifndef INCLUDES_COMPILER_H_
#define INCLUDES_COMPILER_H_


#include "Includes/Compiler_Cfg.h"

#define AUTOMATIC
#define STATIC static
#define PTR_FAR


/*Satisfies [SWS_COMPILER_00001]*/
#define FUNC(returnType, memclass)                        returnType

/*Satisfies [SWS_COMPILER_00001]*/
#define VAR(varType, memclass)                            varType

/*Satisfies [SWS_COMPILER_00039]*/
#define P2FUNC(returnType, memclass, funcname)            returnType (* funcname)

/*Satisfies [SWS_COMPILER_00023]*/
#define CONST(consttype, memclass)                        const consttype

/*Satisfies [SWS_COMPILER_00013]*/
#define P2CONST(ptrType, memclass, ptrclass)              const ptrType *

/*Satisfies [SWS_COMPILER_00006]*/
#define P2VAR(ptrType, memclass, ptrclass)                ptrType * const

/*Satisfies [SWS_COMPILER_00031]*/
#define CONSTP2VAR(ptrType, memclass, ptrclass)           ptrType *

/*Satisfies [SWS_COMPILER_00032]*/
#define CONSTP2CONST(ptrType, memclass, ptrclass)         const ptrType * const


#endif /* INCLUDES_COMPILER_H_ */
