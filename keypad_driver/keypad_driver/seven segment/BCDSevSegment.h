/*
 * BCDSevSegment.h
 *
 * Created: 2/18/2019 12:47:24 PM
 *  Author: AVE-LAP-039
 */ 


#ifndef BCDSEVSEGMENT_H_
#define BCDSEVSEGMENT_H_
#include "BCDSevSegment_cfg.h"
#include "DIO.h"
#include "BitwiseOperation.h"
#include "Types.h"
#include "Timer.h"

extern void BCDSevegments_enable(uint8 segment_number);
extern void BCDSevegments_disable(uint8 segment_number);
extern void BCDSevegments_displayNo(uint8 Number);


#endif /* BCDSEVSEGMENT_H_ */