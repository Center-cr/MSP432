


// Sever VCCMD=VREG jumper on Motor Driver and Power Distribution Board and connect VCCMD to 3.3V.
//   This makes P3.7 and P3.6 low power disables for motor drivers.  0 to sleep/stop.
// Sever nSLPL=nSLPR jumper.
//   This separates P3.7 and P3.6 allowing for independent control
// Left motor direction connected to P1.7 (J2.14)
// Left motor PWM connected to P2.7/TA0CCP4 (J4.40)
// Left motor enable connected to P3.7 (J4.31)
// Right motor direction connected to P1.6 (J2.15)
// Right motor PWM connected to P2.6/TA0CCP3 (J4.39)
// Right motor enable connected to P3.6 (J2.11)

#include "msp.h"
#include "..\inc\Clock.h"
#include "..\inc\SysTick.h"
#include "..\inc\LaunchPad.h"
#include "Motor.h"
#include <driverlib.h>

#define SW1       0x02                  // on the left side of the LaunchPad board
#define SW2       0x10                  // on the right side of the LaunchPad board
#define KEY1 BITBAND_PERI(P1IN, 1) //读取按键1
#define KEY2 BITBAND_PERI(P1IN, 4) //读取按键2

void Port1_Init(void){
    P1->SEL0 &= ~0x12;
    P1->SEL1 &= ~0x12;
    P1->DIR  &= ~0x12;                         // make P1.4 and P1.1 in, P1.0 output
    P1->REN |= 0x12;                         // enable pull resistors on P1.4 and P1.1
    P1->OUT |= 0x12;                         // P1.4 and P1.1 are pull-up
}
uint8_t Port1_Input(void){
  return (P1->IN&0x12);                   // read P1.4,P1.1 inputs
}
int count1=0;
int count2=0;
int main(void){ // Program12_4
      Clock_Init48MHz();
      LaunchPad_Init();   // built-in switches and LEDs 也许可以改成第一个实验的灯，但也不是很有必要
      Motor_Init();//电机驱动初始化
      Port1_Init();
      GPIO_clearInterruptFlag(GPIO_PORT_P1,GPIO_PIN1);
      GPIO_clearInterruptFlag(GPIO_PORT_P1,GPIO_PIN4);  //清除中断标志位

      GPIO_interruptEdgeSelect(GPIO_PORT_P1,GPIO_PIN1,GPIO_HIGH_TO_LOW_TRANSITION);
      GPIO_interruptEdgeSelect(GPIO_PORT_P1,GPIO_PIN4,GPIO_HIGH_TO_LOW_TRANSITION);//配置触发方式，下降沿触发

      GPIO_enableInterrupt(GPIO_PORT_P1,GPIO_PIN1);
      GPIO_enableInterrupt(GPIO_PORT_P1,GPIO_PIN4);//开启外部中断

      Interrupt_enableInterrupt(INT_PORT1);  //开启端口中断

      Interrupt_enableMaster();    //开启总中断
      int right=8000;
      int left=8000;
      while(1){
          switch(count1){
              case 0:
                  Motor_Forward(left,right);
                  Clock_Delay1ms(2000);
                  break;
              case 1:
                  Motor_Backward(left,right);
                  Clock_Delay1ms(2000);
                  break;
              case 2:
                  Motor_Left(left,right);
                  Clock_Delay1ms(2000);
                  break;
              case 3:
                  Motor_Right(left,right);
                  Clock_Delay1ms(2000);
                  break;
              default:
                  count1=0;
                  Motor_Forward(left,right);
                  Clock_Delay1ms(2000);
                  break;
              }
          switch(count2){
              case 0:
                  right=8000;
                  left=8000;
                  break;
              case 1:
                  right=6000;
                  left=6000;
                  break;
              case 2:
                  right=4000;
                  left=4000;
                  break;
              case 3:
                  right=0;
                  left=0;
                  break;
              default:
                  count2=0;
                  right=8000;
                  left=8000;
                  break;
              }
          }
}

void PORT1_IRQHandler(void) //中断服务函数
{
   uint16_t status3,i;
    status3 = GPIO_getEnabledInterruptStatus(GPIO_PORT_P1);//获取中断状态
    GPIO_clearInterruptFlag(GPIO_PORT_P1,status3);
    if(status3 & GPIO_PIN1)
    { for(i = 0; i<5000;i++);
        if(Port1_Input()==0x10)
          count1++;
        }

    if(status3 & GPIO_PIN4)
    { for(i = 0; i<5000;i++);
          if(Port1_Input()==0x02)
            count2++;
          }
}

