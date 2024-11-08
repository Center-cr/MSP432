#include <stdint.h>
#include "msp.h"
void Bump_Init(void) {//��ʼ�� �����ʵ��Ķ˿����ţ���������Ҫ�����ڲ����衣 1110 1101
    P4->SEL0 &= ~0xED;
    P4->SEL1 &= ~0xED;
    P4->DIR &= ~0xED;
    P4->REN |= 0xED;
    P4->OUT |= 0xED;
}
// Read current state of 6 switches
// Returns a 6-bit positive logic result (0 to 63)
// bit 5 Bump5
// bit 4 Bump4
// bit 3 Bump3
// bit 2 Bump2
// bit 1 Bump1
// bit 0 Bump0
uint8_t Bump_Read(void) {  //��ȡ���ز�����һ�� 8 λ���   ���������������������ײʱ������ֵ3�����м�����������������ײʱ������ֵ2��
                             //���ұ�����������������ײʱ������ֵ1����������ײʱ������ֵ0�����ɷ���ֵ�Ĵ�С���������п���С�����˶�
    uint8_t bumpfigure;
    uint8_t num = 0;
    bumpfigure = ((P4->IN) & 0xED); //1110 1101
    switch (bumpfigure)
    {
    case 0xEC:      //1110 1100
        num = 1; break;
    case 0xE9:     //1110 1001
        num = 1; break;
    case 0xE5:
        num = 2; break;
    case 0xC5:
        num = 2; break;
    case 0xCD:
        num = 2; break;
    case 0xAD:
        num = 3; break;
    case 0x6D:
        num = 3; break;
    } }


