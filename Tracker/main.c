#include "msp.h"
#include "../inc/Clock.h"
#include "../inc/Motor.h"
#include <stdio.h>
//初始化P1相关的寄存器
void Port1_Init(void){
  P1->SEL0 = 0x00;
  P1->SEL1 = 0x00;                        // configure P1.4 and P1.1 as GPIO
  P1->DIR = ~0x12;                         // P1.4，P1.1作为输入
  P1->REN = 0x12;                         // 配置1.1,1.4为上拉电阻模式
  P1->OUT = 0x12;                         // P1.4 and P1.1 are pull-up
}
uint8_t Port1_Input(void){
  return (P1->IN&0x12);                   // 读取P1.4,P1.1的电平状态
}
void Port1_Output(uint8_t data){          // write all of P1.0 outputs
  P1->OUT = data;                         //输出P1.1,P1.4的电平
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
    uint32_t status1=0x12;         //记忆SW1,SW2的状态
    uint32_t count1=0;            //用于记录模式更换状态
    uint32_t count2=0;            //用于记录速度状态
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

                       status1=Port1_Input();  //读取sw1电平,已按则为0x00，未按0x02，status1==Port1_Input()
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
                       else if(!(status1 & 0x10))//读取sw2电平,已按则为0x00，未按0x10，status1==Port1_Input()
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
                   //count2计数改变频率，该switch几乎无延迟，在更换模式之前进行
                   switch(count2) {
                   case 0 :
                       left=8000;//因为sw1的开启也会使这段程序进行，所以直接赋值，不用left=left+2000
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
                   //每次改变速度后都会以当前模式试运行
                   //count1计数改变模式，按钮按下弹起后一秒再更换模式，为方便，模式运行三秒后小车停下。
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
