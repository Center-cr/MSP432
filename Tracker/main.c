#include "msp.h"
#include "../inc/Clock.h"
#include "../inc/Motor.h"
#include <stdio.h>
//��ʼ��P1��صļĴ���
void Port1_Init(void){
  P1->SEL0 = 0x00;
  P1->SEL1 = 0x00;                        // configure P1.4 and P1.1 as GPIO
  P1->DIR = ~0x12;                         // P1.4��P1.1��Ϊ����
  P1->REN = 0x12;                         // ����1.1,1.4Ϊ��������ģʽ
  P1->OUT = 0x12;                         // P1.4 and P1.1 are pull-up
}
uint8_t Port1_Input(void){
  return (P1->IN&0x12);                   // ��ȡP1.4,P1.1�ĵ�ƽ״̬
}
void Port1_Output(uint8_t data){          // write all of P1.0 outputs
  P1->OUT = data;                         //���P1.1,P1.4�ĵ�ƽ
}

/**
 * main.c
 */
void main(void)
{
    Clock_Init48MHz();
    Motor_Init();
    int right=8000;
    int left=8000;
    uint32_t status1=0x12;         //����SW1,SW2��״̬
    uint32_t count1=0;            //���ڼ�¼ģʽ����״̬
    uint32_t count2=0;            //���ڼ�¼�ٶ�״̬
    uint32_t Flag1=1;
    uint32_t Flag2=1;
    Port1_Init();
    Motor_Stop();
    while(1)
     {


                    Flag1=1;
                    Flag2=1;
                   while(Flag1)
                   {

                       status1=Port1_Input();  //��ȡsw1��ƽ,�Ѱ���Ϊ0x00��δ��0x02��status1==Port1_Input()
                       if(!(status1 & 0x02))
                       {

                           while(Flag2)
                           {

                               status1=Port1_Input();
                               if((status1 & 0x02))
                               {
                                   count1++;
                                   Flag2=0;Flag1=0;
                               }
                           }
                       }
                       else if(!(status1 & 0x10))//��ȡsw2��ƽ,�Ѱ���Ϊ0x00��δ��0x10��status1==Port1_Input()
                               {
                               while(Flag2)
                              {
                                status1=Port1_Input();
                                if((status1 & 0x10))
                                {
                                    count2++;
                                    Flag2=0;Flag1=0;
                                 }

                           }
                       }
                   }
                   //count2�����ı�Ƶ�ʣ���switch�������ӳ٣��ڸ���ģʽ֮ǰ����
                   switch(count2) {
                   case 0 :
                       left=8000;//��Ϊsw1�Ŀ���Ҳ��ʹ��γ�����У�����ֱ�Ӹ�ֵ������left=left+2000
                       right=8000;
                       break;
                   case 1 :
                       left=10000;
                       right=10000;
                       break;
                   case 2 :
                       left=12000;
                       right=12000;
                       break;
                   case 3 :
                        left=14000;
                        right=14000;
                        break;
                   case 4 :
                       left=8000;
                       right=8000;
                       count2=0;
                       break;
                   }
                   //ÿ�θı��ٶȺ󶼻��Ե�ǰģʽ������
                   //count1�����ı�ģʽ����ť���µ����һ���ٸ���ģʽ��Ϊ���㣬ģʽ���������С��ͣ�¡�
                   switch(count1)
                   {
                   case 0:
                            Clock_Delay1ms(1000);
                            Motor_Stop();
                            break;
                   case 1:
                            Clock_Delay1ms(1000);
                            Motor_Forward(left,right);
                            Clock_Delay1ms(3000);
                            Motor_Stop();
                            break;
                   case 2:
                            Clock_Delay1ms(1000);
                            Motor_Backward(left,right);
                            Clock_Delay1ms(3000);
                            Motor_Stop();
                            break;
                   case 3:
                            Clock_Delay1ms(1000);
                            Motor_Left(left,right);
                            Clock_Delay1ms(3000);
                            Motor_Stop();
                            break;
                   case 4:
                            Clock_Delay1ms(1000);
                            Motor_Right(left,right);
                            Clock_Delay1ms(3000);
                            Motor_Stop();
                            break;
                   case 5:
                            count1=0;
                            break;
                                  }
}
}
