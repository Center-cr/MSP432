/*
 * ADC14.C
 *
 *  Created on: 2022年12月1日
 *      Author: ZJH
 */



#include <stdint.h>
#include "msp.h"
#include "../inc/ADC14.h"
void ADC0_InitSWTriggerCh17_12_16(void){ //初始化P9.0  A17  右边测距  P9.1  A16   左边测距 4.1  A12   中间测距

    ADC14->CTL0 &= ~0x00000002;      // 2) ADC14ENC = 0 to allow programming
      while(ADC14->CTL0&0x00010000){}; // 3) wait for BUSY to be zero
      ADC14->CTL0 = 0x04223390;        // 4) single, SMCLK, on, disabled, /1, 32 SHM
      ADC14->CTL1 = 0x00000030;
      ADC14->MCTL[0] = 0x00000011;
      ADC14->MCTL[1] = 0x0000000c;
      ADC14->MCTL[2] = 0x00000090;
      ADC14->IER0=0;
      ADC14->IER1=0;
      P9->SEL1 |=0x03;
      P9->SEL0 |=0x03;
      P4->SEL0 |=0x02;
      P4->SEL1 |=0x02;
      ADC14->CTL0 |=0x00000002;
}

void ADC_In17_12_16(uint32_t *ch17, uint32_t *ch12, uint32_t *ch16){
    while(ADC14->CTL0&0x00010000){}; // 1) wait for BUSY to be zero
      ADC14->CTL0 |= 0x00000001;       // 2) start single conversion
      while((ADC14->IFGR0&0x04) == 0){};                               // 3) wait for ADC14IFG3

      *ch17 = ADC14->MEM[0];
      *ch12 = ADC14->MEM[1];
      *ch16 = ADC14->MEM[2];
}

