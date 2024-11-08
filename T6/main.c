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
 uint8_t  CollisionData=0;
 uint32_t Right,Center,Left; // distance in mm
 volatile uint32_t nr,nc,nl; // filtered ADC sample
 uint32_t raw17,raw12,raw16;
 void TimedPause(uint32_t time){


   Clock_Delay1ms(time);          // С��ֹͣ
   Motor_Stop();
 }

   void loop(void)//����2msһ�Σ�32msһ������
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

void HandleCollision(uint8_t bumpSensor)//��ײ�͵�ƽ��Ч
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
                Motor_Backward(8000, 8000);
                P2->OUT&=~0x07;
                P2->OUT|=~0x05;
                Clock_Delay1ms(500);
                Motor_Left(8000, 8000);
                Clock_Delay1ms(350);
            }

            else if(Left <= 100){
                Motor_Backward(8000, 8000);
                P2->OUT&=~0x07;
                P2->OUT|=0x06;
                Clock_Delay1ms(500);
                Motor_Left(8000, 8000);
                Clock_Delay1ms(120);
               }
            else if(Right <= 100){
               Motor_Backward(8000, 8000);
               P2->OUT&=~0x07;
               P2->OUT|=0x07;
               Clock_Delay1ms(500);
               Motor_Left(8000, 8000);
               Clock_Delay1ms(480);
               }
            else{
                Motor_Forward(4000, 4000);
                P2->OUT&=~0x07;
                P2->OUT|=0x04;     //    all LEDs
            }

}


void Port1_Init(void){
  P1->SEL0 = 0x00;
  P1->SEL1 = 0x00;                        // configure P1.4 and P1.1 as GPIO
  P1->DIR = ~0x12;                         // P1.4��P1.1��Ϊ����
  P1->REN = 0x12;                         // ����1.1,1.4Ϊ��������ģʽ
  P1->OUT = 0x12;                         // P1.4 and P1.1 are pull-up
  P1->IES |= 0x12;  // falling edge event
  P1->IFG &= ~0x12; // clear flags (reduce possibility of extra interrupt)
  P1->IE |= 0x12;   // arm interrupt on P4.0/2/3/5/6/7
  NVIC->IP[8] = (NVIC->IP[8]&0x00FFFFFF)|0x60000000; //35��IQ��Ӧ ��8��IP �ĸ�8λ
  NVIC->ISER[1] |=0x0000008;        // NVI��35��IQ��ISER[0]û�õ�
}
uint8_t Port1_Input(void){
  return (P1->IN&0x12);                   // ��ȡP1.4,P1.1�ĵ�ƽ״̬
}
void Port1_Output(uint8_t data){          // write all of P1.0 outputs
  P1->OUT = data;                         //���P1.1,P1.4�ĵ�ƽ
}
uint8_t Data;
int32_t position;

void reflactance(void){

        Data = Reflectance_Read(1000);
        if(Data==0){
//                        Motor_Stop();
//                       TimedPause(30);
                       Motor_Backward(3000,3000);
                       P2->OUT&=~0x07;
                       P2->OUT|=0x02;

                       TimedPause(100);
                       P2->OUT&=~0x07;
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
        if((position<=-50)&&(position>=-141)){//��ת���1
//            Motor_Stop();
//                              TimedPause(10);
                              Motor_Forward(7000,2000);
                              P2->OUT&=~0x07;     //    all LEDs
                              P2->OUT|=0x07;     //    all LEDs
                              TimedPause(100);
         }

         else if((position>=50)&&(position<=141)){//��ת���1
//                  Motor_Stop();
//                  TimedPause(10);
                  Motor_Forward(2000,7000);
                  P2->OUT&=~0x07;     //    all LEDs
                  P2->OUT|=0x06;     //    all LEDs
                  TimedPause(200);
                      }
         else if(position>141){//��ת���2
             Motor_Stop();
             TimedPause(30);
             Motor_Left(4000,4000);
             P2->OUT&=~0x07;     //    all LEDs
             P2->OUT|=0x06;     //    all LEDs
             TimedPause(200);

         }
         else if(position<-141){//��ת���2
//                     Motor_Stop();
//                     TimedPause(10);
                     Motor_Right(4000,4000);
                     P2->OUT&=~0x07;     //    all LEDs
                     P2->OUT|=0x07;     //    all LEDs
                     TimedPause(200);
                 }
//         else if(position==0){//��ת���2
//        //                     Motor_Stop();
//        //                     TimedPause(10);
//                             Motor_Right(2000,2000);
//                             TimedPause(100);
//                         }
              else {//��ƫ������ǰ��
                  Motor_Forward(3000,3000);
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





