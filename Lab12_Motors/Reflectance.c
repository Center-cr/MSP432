#include <stdint.h>
#include "msp432.h"
#include "Clock.h"
void Reflectance_Init(void) {//初始化
    P7->SEL0 &= ~0xFF;
    P7->SEL1 &= ~0xFF;
    P7->DIR &= ~0xFF;
    P5->SEL0 &= ~0x08;
    P5->SEL1 &= ~0x08;
    P5->DIR |= 0x08;
}
uint8_t Reflectance_Read(uint32_t time) {
    uint8_t result;
    P5->OUT |= 0x08;      // turn on 8 IR LEDs
    P7->DIR = 0xFF;       // make P7.7-P7.0 out
    P7->OUT = 0xFF;       // 1111 1111
    Clock_Delay1us(10);
    P7->DIR = 0x00;     // make P7.7-P7.0 in
    Clock_Delay1us(time);
    result = (P7->IN & 0xFF); // convert input to digital
    P5->OUT &= ~0x08;     // turn off 8 IR LEDs
    Clock_Delay1ms(10);
    return result;
}
int32_t Reflectance_Position(uint8_t data) {//计算位置
    int32_t z, e = 0, f = 0;
    int i;
    int b[8];  //b存储8个传感器的值
    int W[8] = { 332,237,142,47,-47,-142,-237,-332 };
    for (i = 0; i < 8; i++)
    {
        b[i] = data % 2;
        data = data / 2;
    }
    for (i = 0; i < 8; i++)
    {
        e = e + (b[i] * W[i]);
        f = f + b[i];

    }
    z = e / f;
    return z;
}
