#include <stdint.h>
#include "msp.h"
#include "../inc/ADC14.h"
void ADC0_InitSWTriggerCh17_12_16(void) { //初始化
    ADC14->CTL0 &= ~0x00000002;      // 2) ADC14ENC = 0 to allow programming
    while (ADC14->CTL0 & 0x00010000) {}; // 3) wait for BUSY to be zero
    ADC14->CTL0 = 0x04223390;        // 4) single, SMCLK, on, disabled, /1, 32 SHM
    ADC14->CTL1 = 0x00000030;
    ADC14->MCTL[0] = 0x00000011;
    ADC14->MCTL[1] = 0x0000000c;
    ADC14->MCTL[2] = 0x00000090;
    ADC14->IER0 = 0;
    ADC14->IER1 = 0;
    P9->SEL1 |= 0x03;
    P9->SEL0 |= 0x03;
    P4->SEL0 |= 0x02;
    P4->SEL1 |= 0x02;
    ADC14->CTL0 |= 0x00000002;
}
void ADC_In17_12_16(uint32_t* ch17, uint32_t* ch12, uint32_t* ch16) {
    while (ADC14->CTL0 & 0x00010000) {}; // 1) wait for BUSY to be zero
    ADC14->CTL0 |= 0x00000001;       // 2) start single conversion
    while ((ADC14->IFGR0 & 0x04) == 0) {};                               // 3) wait for ADC14IFG3

    *ch17 = ADC14->MEM[0];
    *ch12 = ADC14->MEM[1];
    *ch16 = ADC14->MEM[2];
}




/*设n为14位ADC的采样值（从0到16383），且D为距离，单位是mm。二者之间存在如下的非线性转换关系：D = 1195172 / (N - 1058)
得到准确的距离之后，我们就可以通过测量得到的距离值来判断小车的运行状态。*/


int32_t z = 1195172;
int32_t e = 1058;
int32_t LeftConvert(int32_t nl) {
    int32_t dl;// returns left distance in mm
    dl = z / (nl - e);

    return dl; // replace this line
}

int32_t CenterConvert(int32_t nc) {
    int32_t dc;
    dc = z / (nc - e);

    return dc; // replace this line
}

int32_t RightConvert(int32_t nr) {
    int32_t dr;
    dr = z / (nr - e);
    return dr; // replace this line
}
