#include <stdint.h>
#include "msp.h"
#include "Bump.h"
#include "Clock.h"
#include "..\inc\SysTick.h"
#include "..\inc\CortexM.h"
#include "..\inc\LaunchPad.h"
#include "..\inc\Motor.h"
#include "..\inc\PWM.h"
#include "..\inc\Reflectance.h"
#include "..\inc\ADC14.h"
#include "..\inc\IRDistance.h"
#include "..\inc\LPF.h"
#include "..\inc\TimerA0.h"
#include <stdint.h>
#include "msp.h"
#include "Bump.h"
#include "Clock.h"
#include "..\inc\SysTick.h"
#include "..\inc\CortexM.h"
#include "..\inc\LaunchPad.h"
#include "..\inc\Motor.h"
#include "..\inc\PWM.h"
#include "..\inc\Reflectance.h"
#include "..\inc\ADC14.h"
#include "..\inc\IRDistance.h"
#include "..\inc\LPF.h"
#include "..\inc\TimerA0.h"



void TimedPause(uint32_t time) {
    Clock_Delay1ms(time);
    Motor_Stop();
}


uint8_t Data;
int32_t position;
void reflactance(void) {  //寻迹

    Data = Reflectance_Read(1000);  //读取传感器数据
    position = Reflectance_Position(Data); //计算偏离

    if ((position <= -50) && (position >= -250)) {//右转情况1
        Motor_Stop();
        TimedPause(200);
        Motor_Forward(7000, 2000);
        TimedPause(100);
    }

    else if ((position >= 50) && (position <= 250)) {//左转情况1
        Motor_Stop();
        TimedPause(200);
        Motor_Forward(2000, 7000);
        TimedPause(100);
    }
    else if (position > 250) {//左转情况2
        Motor_Stop();
        TimedPause(200);
        Motor_Left(4000, 4000);
        TimedPause(300);
    }
    else if (position < -250) {//右转情况2
        Motor_Stop();
        TimedPause(200);
        Motor_Right(4000, 4000);
        TimedPause(300);
    }
    else {//不偏离规矩则前进
        Motor_Forward(4000, 4000);

    }

}



uint32_t Right, Center, Left; // distance in mm

void IRrun(uint16_t nr, uint16_t nc, uint16_t nl)
{
    Right = RightConvert(nr);  //距离
    Center = CenterConvert(nc);
    Left = LeftConvert(nl);
    if (Center <= 100) {
        TimedPause(100);
        Motor_Backward(4000, 4000);
        TimedPause(200);
        Motor_Right(5000, 4000);
        TimedPause(700);
    }
    else if (Left <= 100) {
        Motor_Right(4000, 4000);
        TimedPause(500);
    }
    else if (Right <= 100) {

        Motor_Left(4000, 4000);

        TimedPause(500);
    }
    else {
        Motor_Forward(4000, 4000);
    }

}
void bumprun(void) {    //碰撞

    uint8_t numflag = 0;
    numflag = Bump_Read();
    if (numflag == 1) {
        TimedPause(200);
        Motor_Backward(4000, 4000);
        TimedPause(500);
        Motor_Left(4000, 6000);
        TimedPause(500);//delay
    }
    else if (numflag == 3) {
        TimedPause(200);
        Motor_Backward(4000, 4000);
        TimedPause(500);
        Motor_Right(4000, 6000);
        TimedPause(500);// delay
    }
    else if (numflag == 2) {
        TimedPause(200);
        Motor_Backward(4000, 4000);
        TimedPause(500);// delay
        Motor_Right(4000, 6000);
        TimedPause(700);//delay
    }
    else if (numflag == 0)
        Motor_Forward(4000, 4000);

}
volatile uint32_t nr, nc, nl;
uint32_t raw17, raw12, raw16;
void loop(void)//采样2ms一次，32ms一个周期，由于红外测距传感器的测量值不太稳定，
               //以一次测量的结果来判别控制小车的运行偶然性太大，所以我以1ms为一个测量周期，
               //取16个周期的平均值作为输出的ADC的采样值，即loop函数。这样使控制系统更加稳定、更加准确
{
    int i;
    int z = 16;
    uint32_t sum1 = 0, sum2 = 0, sum3 = 0;
    for (i = 0; i < z; i++)
    {
        ADC_In17_12_16(&raw17, &raw12, &raw16);
        sum1 = raw17 + sum1;
        sum2 = raw12 + sum2;
        sum3 = raw16 + sum3;
        Clock_Delay1ms(2);
    }
    nr = sum1 / z;
    nc = sum2 / z;
    nl = sum3 / z;
}

int main(void) {
    uint8_t t;
    Clock_Init48MHz();
    LaunchPad_Init();                    //???
    ADC0_InitSWTriggerCh17_12_16();  //红外测距初始化
    Bump_Init();      // 防碰撞初始化（开关）

    Motor_Init();     // 电机运动
    PWM_Init34(15000, 10000, 10000);  //pwm模块
    Reflectance_Init();   //寻迹初始化
    while (LaunchPad_Input() == 0);  // wait for touch   launchpad？
    t = LaunchPad_Input();
    switch (t) {

    case 0x01:
        while (1)
        {                 // switches are negative logic on P1.1 and P1.4
            loop();
            IRrun(nr, nc, nl);    //红外避障
            bumprun();
        }
        break;
    case 0x02:
        while (1) {
            reflactance();   //寻迹 （红外反射）
            bumprun();
        }
        break;
    }
}
