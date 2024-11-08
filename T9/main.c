#include <stdio.h>
#include <stdint.h>
#include "msp.h"
#include "../inc/Clock.h"
#include "../inc/CortexM.h"
#include "../inc/LaunchPad.h"
#include "../inc/Motor.h"
#include "../inc/BumpInt.h"
#include "../inc/TExaS.h"
#include "../inc/TimerA1.h"
#include "../inc/FlashProgram.h"
#include "..\inc\MotorSimple.h"
#include "..\inc\bump.h"
#include "..\inc\SysTick.h"
#include "..\inc\Bump.h"
#include"..\inc\PWM.h"
#include "..\inc\SysTick.h"
#include "../inc/UART0.h"
#include"..\inc\Reflectance.h"
#include "..\inc\ADC14.h"
#include "..\inc\IRDistance.h"
#include "..\inc\LPF.h"
#include "..\inc\TimerA0.h"

#include <stdio.h>
#include "msp.h"
#include "../inc/Clock.h"
#include "../inc/UART0.h"
#include "../inc/Reflectance.h"
#include "../inc/PWM.h"
#include "../inc/Motor.h"
#include "../inc/JN_LCD.h"
void reflactance(void);
 uint8_t  CollisionData=0;
 uint32_t Right,Center,Left; // distance in mm
 volatile uint32_t nr,nc,nl; // filtered ADC sample
 uint32_t raw17,raw12,raw16;
 void TimedPause(uint32_t time){


   Clock_Delay1ms(time);          // 小车停止
   Motor_Stop();
 }

   void loop(void)//采样2ms一次，32ms一个周期
   {
       int i;
       int z=16;
       uint32_t sum1=0,sum2=0,sum3=0;
       for(i=0;i<z;i++)
       {
           ADC_In17_12_16(&raw17,&raw12,&raw16);
           sum1=raw17+sum1;
           sum2=raw12+sum2;
           sum3=raw16+sum3;
           Clock_Delay1ms(2);
       }
        nr=sum1/z;
        nc=sum2/z;
        nl=sum3/z;
   }

void HandleCollision(uint8_t bumpSensor)//碰撞低电平有效
{
             uint8_t numflag = 0;
              numflag = Bump_Read();
              if(numflag == 1){
                 TimedPause(200);
                  Motor_Backward(8000,8000);
               TimedPause(500);
                     Motor_Left(5000,5000);
               TimedPause(150);//delay
                       P2->OUT|=0x07;     //    all LEDs
                       Motor_Forward(5000,5000);
               TimedPause(1500);//delay
                       P2->OUT &=~0x07;     //    all LEDs
                        Motor_Right(5000,5000);
                 TimedPause(800);//delay
                Motor_Forward(5000,5000);
                              P2->OUT|=0x06;
             TimedPause(2500);//delay
                          P2->OUT &=~0x07;
              }
              else if(numflag == 3){
                  TimedPause(200);
                            Motor_Backward(8000,8000);
                         TimedPause(500);
                               Motor_Left(5000,5000);
                         TimedPause(800);//delay
                                 P2->OUT|=0x07;     //    all LEDs
                                 Motor_Forward(5000,5000);
                         TimedPause(1500);//delay
                                 P2->OUT &=~0x07;     //    all LEDs
                                  Motor_Right(5000,5000);
                           TimedPause(150);//delay
                          Motor_Forward(5000,5000);
                                   P2->OUT|=0x06;
                       TimedPause(2500);//delay
                                   P2->OUT &=~0x07;
              }
              else if(numflag == 2){
                  TimedPause(200);
                              Motor_Backward(8000,8000);
                              TimedPause(500);
                              Motor_Left(5000,5000);
                              TimedPause(300);//delay
                              P2->OUT|=0x07;     //    all LEDs
                              Motor_Forward(5000,5000);
                              TimedPause(1500);//delay
                              P2->OUT &=~0x07;     //    all LEDs
                              Motor_Right(5000,5000);
                              TimedPause(600);//delay
                              Motor_Forward(5000,5000);
                              P2->OUT|=0x06;
                              TimedPause(2500);//delay
                              P2->OUT &=~0x07;
              }
              else
                  Motor_Backward(8000,8000);
}
void IRrun(uint16_t nr,uint16_t nc,uint16_t nl )
{
            Right = RightConvert(nr);
            Center = CenterConvert(nc);
            Left = LeftConvert(nl);
            if(Center <= 100){
                TimedPause(200);
                                              Motor_Backward(8000,8000);
                                              TimedPause(500);
                                              Motor_Left(5000,5000);
                                              TimedPause(300);//delay
                                              P2->OUT|=0x07;     //    all LEDs
                                              Motor_Forward(5000,5000);
                                              TimedPause(2000);//delay
                                              P2->OUT &=~0x07;     //    all LEDs
                                              Motor_Right(5000,5000);
                                              TimedPause(500);//delay
                                              Motor_Forward(5000,5000);
                                              P2->OUT|=0x06;
                                              TimedPause(2500);//delay
                                              P2->OUT &=~0x07;
            }

//            else if(Left <= 100){
//                TimedPause(200);
//                                            Motor_Backward(8000,8000);
//                                         TimedPause(500);
//                                               Motor_Left(5000,5000);
//                                         TimedPause(800);//delay
//                                                 P2->OUT|=0x07;     //    all LEDs
//                                                 Motor_Forward(5000,5000);
//                                         TimedPause(1500);//delay
//                                                 P2->OUT &=~0x07;     //    all LEDs
//                                                  Motor_Right(5000,5000);
//                                           TimedPause(150);//delay
//                                          Motor_Forward(5000,5000);
//                                                   P2->OUT|=0x06;
//                                       TimedPause(2500);//delay
//                                                   P2->OUT &=~0x07;
//               }
//            else if(Right <= 100){
//                TimedPause(200);
//                                 Motor_Backward(8000,8000);
//                              TimedPause(500);
//                                    Motor_Left(5000,5000);
//                              TimedPause(150);//delay
//                                      P2->OUT|=0x07;     //    all LEDs
//                                      Motor_Forward(5000,5000);
//                              TimedPause(1500);//delay
//                                      P2->OUT &=~0x07;     //    all LEDs
//                                       Motor_Right(5000,5000);
//                                TimedPause(800);//delay
//                               Motor_Forward(5000,5000);
//                                             P2->OUT|=0x06;
//                            TimedPause(2500);//delay
//                                         P2->OUT &=~0x07;
//               }
            else{
                reflactance();
//                P2->OUT&=~0x07;
//                P2->OUT|=0x04;     //    all LEDs
            }

}


void Port1_Init(void){
  P1->SEL0 = 0x00;
  P1->SEL1 = 0x00;                        // configure P1.4 and P1.1 as GPIO
  P1->DIR = ~0x12;                         // P1.4，P1.1作为输入
  P1->REN = 0x12;                         // 配置1.1,1.4为上拉电阻模式
  P1->OUT = 0x12;                         // P1.4 and P1.1 are pull-up
  P1->IES |= 0x12;  // falling edge event
  P1->IFG &= ~0x12; // clear flags (reduce possibility of extra interrupt)
  P1->IE |= 0x12;   // arm interrupt on P4.0/2/3/5/6/7
  NVIC->IP[8] = (NVIC->IP[8]&0x00FFFFFF)|0x60000000; //35号IQ对应 第8号IP 的高8位
  NVIC->ISER[1] |=0x0000008;        // NVI的35号IQ，ISER[0]没用到
}
uint8_t Port1_Input(void){
  return (P1->IN&0x12);                   // 读取P1.4,P1.1的电平状态
}
void Port1_Output(uint8_t data){          // write all of P1.0 outputs
  P1->OUT = data;                         //输出P1.1,P1.4的电平
}
uint8_t Data;
int32_t position;
uint8_t flag=1;

void reflactance(void){

        Data = Reflectance_Read(1000);
        if(Data==0){
    //                        Motor_Stop();
    //                       TimedPause(30);
                           Motor_Backward(3000,3000);
                           P2->OUT&=~0x07;
                           P2->OUT|=0x02;

                           TimedPause(900);
                           P2->OUT&=~0x07;
            }

//        if(Data==0){
////                        Motor_Stop();
////                       TimedPause(30);
//                       while(flag)
//                       {
//                       Data = Reflectance_Read(1000);
//                       if(Data==0){
//                       Motor_Backward(3000,3000);
//                       P2->OUT&=~0x07;
//                       P2->OUT|=0x02;
//                       TimedPause(30);
//                       flag=1;
//                       }
//                       else if(Data==0Xd8)
//                       {
//                           Motor_Right(4000,4000);
//                            P2->OUT&=~0x07;
//                            P2->OUT|=0x04;
//                            TimedPause(2000);
//                            flag=0;
//                       }
//                      else if(Data==0X1B)
//                      {
//                          Motor_Left(4000,4000);
//                          P2->OUT&=~0x07;
//                          P2->OUT|=0x04;
//                         TimedPause(2000);
//                         flag=0;
//                      }
//
//                   }
//        }
        if((Data==0Xd8)||(Data==0Xc8)||(Data==0X6c)||(Data==0X68)||(Data==0X98)||(Data==0X88)){
                        Motor_Right(4000,4000);
                        P2->OUT&=~0x07;
                         P2->OUT|=0x04;
                          TimedPause(1000);

        }
        else if((Data==0X1b)||(Data==0X13)||(Data==0X12)||(Data==0X36)||(Data==0X33)||(Data==0X19)){
                         Motor_Left(4000,4000);
                         P2->OUT&=~0x07;
                          P2->OUT|=0x05;
                           TimedPause(1000);

         }
//        if(Data==0x1b||Data==0x3b)
//        {
//            Motor_Right(4000,4000);
//
//
//            P2->OUT&=~0x07;
//             P2->OUT|=0x04;
//              TimedPause(2000);
//        }
//        else if(Data==0x0b||Data==0x2b)
//        {
//            Motor_Right(4000,4000);
//
//
//            P2->OUT&=~0x07;
//             P2->OUT|=0x04;
//              TimedPause(2000);
//        }
//        else if(Data==0x07||Data==0x27)
//           {
//               Motor_Right(4000,4000);
//
//
//               P2->OUT&=~0x07;
//                P2->OUT|=0x04;
//                 TimedPause(2000);
//           }
//        else if(Data==0x03||Data==0x23)
//                {
//                    Motor_Right(4000,4000);
//
//
//                    P2->OUT&=~0x07;
//                     P2->OUT|=0x04;
//                      TimedPause(2000);
//                }
//        else if(Data==0x0D||Data==0x2D)
//             {
//                 Motor_Right(4000,4000);
//
//
//                 P2->OUT&=~0x07;
//                  P2->OUT|=0x04;
//                   TimedPause(2000);
//             }
        position = Reflectance_Position(Data);
//        if(Data==0xFF)
//        {
//            Motor_Forward(7000,7000);
//            Clock_Delay1ms(1000);
//            Motor_Stop();
//            Clock_Delay1ms(1000);
//
//
//        }
        if((position<=-50)&&(position>=-141)){//右转情况1
//            Motor_Stop();
//                              TimedPause(10);
                              Motor_Forward(7000,2000);
                              P2->OUT&=~0x07;     //    all LEDs
                              P2->OUT|=0x07;     //    all LEDs
                              TimedPause(100);
         }

         else if((position>=50)&&(position<=141)){//左转情况1
//                  Motor_Stop();
//                  TimedPause(10);
                  Motor_Forward(2000,7000);
                  P2->OUT&=~0x07;     //    all LEDs
                  P2->OUT|=0x06;     //    all LEDs
                  TimedPause(200);
                      }
         else if(position>141){//左转情况2
             Motor_Stop();
             TimedPause(30);
             Motor_Left(4000,4000);
             P2->OUT&=~0x07;     //    all LEDs
             P2->OUT|=0x06;     //    all LEDs
             TimedPause(200);

         }
         else if(position<-141){//右转情况2
//                     Motor_Stop();
//                     TimedPause(10);
                     Motor_Right(4000,4000);
                     P2->OUT&=~0x07;     //    all LEDs
                     P2->OUT|=0x07;     //    all LEDs
                     TimedPause(200);
                 }
//         else if(position==0){//右转情况2
//        //                     Motor_Stop();
//        //                     TimedPause(10);
//                             Motor_Right(2000,2000);
//                             TimedPause(100);
//                         }
              else {//不偏离规矩则前进
                  Motor_Forward(7000,7000);
                  P2->OUT&=~0x07;     //    all LEDs
                  P2->OUT|=0x03;     //    all LEDs
//                      Motor_Stop();
              }

}

uint8_t t=0;
void main()
{

    Clock_Init48MHz();
    LaunchPad_Init();
    ADC0_InitSWTriggerCh17_12_16();
    Port1_Init();
    BumpInt_Init(&HandleCollision);
    Motor_Init();
//    PWM_Init34(15000, 10000, 10000);
    Motor_Stop();
    UART0_Initprintf();
    EnableInterrupts();
    Reflectance_Init();
//    while(LaunchPad_Input()==0);  // wait for touch

//while(t=0x01)
//{
//    Clock_Delay1ms(500);
//    printf("%02x\n",t);}
while(1)
{
    switch(t){

    case 0x01:
        while(t==0x01){
            loop();
            IRrun(nr,nc,nl);
        }


    case 0x02:
        while(t==0x02)
        {
           reflactance();
        }
    }


}











         }
         void PORT1_IRQHandler()
         {
             P1->IFG &= ~0x12; // clear flags (reduce possibility of extra interrupt)
             Motor_Stop();
             t = LaunchPad_Input();
             P2->OUT&=~0x07;     //    all LEDs
             P2->OUT|=0x04;     //    all LEDs
             Clock_Delay1ms(500);
             P2->OUT&=~0x07;     //    all LEDs
             P2->OUT|=0x04;     //    all LEDs
             Clock_Delay1ms(500);
             P2->OUT&=~0x07;     //    all LEDs




//             switch(t){
//
//             case 0x01:
//             while(t==0x01)
//             {
//                 P1->IFG &= ~0x12; // clear flags (reduce possibility of extra interrupt)
//                 loop();
//                 IRrun(nr,nc,nl);
//
//
//             }
//             case 0x02:
//               while(t==0x02){
//                   P1->IFG &= ~0x12; // clear flags (reduce possibility of extra interrupt)
//                reflactance();
//
//
//            }







         }
//    while(1)
//     {                 // switches are negative logic on P1.1 and P1.4
//
//         IRrun(nr,nc,nl);
//        Data = Reflectance_Read(1000);
//                printf("%02x\n",Data);
//                Clock_Delay1ms(10);
////            reflactance();
//   }





