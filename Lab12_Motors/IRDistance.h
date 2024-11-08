/*
 * IRDistance.h
 *
 *  Created on: 2022Äê12ÔÂ1ÈÕ
 *      Author: 1
 */

#ifndef IRDISTANCE_H_
#define IRDISTANCE_H_


void ADC0_InitSWTriggerCh17_12_16(void);

void ADC_In17_12_16(uint32_t* ch17, uint32_t* ch12, uint32_t* ch16);

int32_t LeftConvert(int32_t nl);

int32_t CenterConvert(int32_t nc);

int32_t RightConvert(int32_t nr);
#endif /* IRDISTANCE_H_ */
