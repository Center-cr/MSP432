// Lab06_GPIOmain.c
// Runs on MSP432
// Solution to GPIO lab
// Daniel and Jonathan Valvano
// May 21, 2017
// Provide test main program for QTR-8RC reflectance sensor array
// Pololu part number 961.

/* This example accompanies the books
   "Embedded Systems: Introduction to the MSP432 Microcontroller",
       ISBN: 978-1512185676, Jonathan Valvano, copyright (c) 2017
   "Embedded Systems: Real-Time Interfacing to the MSP432 Microcontroller",
       ISBN: 978-1514676585, Jonathan Valvano, copyright (c) 2017
   "Embedded Systems: Real-Time Operating Systems for ARM Cortex-M Microcontrollers",
       ISBN: 978-1466468863, , Jonathan Valvano, copyright (c) 2017
 For more information about my classes, my research, and my books, see
 http://users.ece.utexas.edu/~valvano/

Simplified BSD License (FreeBSD License)
Copyright (c) 2017, Jonathan Valvano, All rights reserved.

Redistribution and use in source and binary forms, with or without modification,
are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright notice,
   this list of conditions and the following disclaimer.
2. Redistributions in binary form must reproduce the above copyright notice,
   this list of conditions and the following disclaimer in the documentation
   and/or other materials provided with the distribution.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE
USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

The views and conclusions contained in the software and documentation are
those of the authors and should not be interpreted as representing official
policies, either expressed or implied, of the FreeBSD Project.
*/

// reflectance LED illuminate connected to P5.3
// reflectance sensor 1 connected to P7.0 (robot's right, robot off road to left)
// reflectance sensor 2 connected to P7.1
// reflectance sensor 3 connected to P7.2
// reflectance sensor 4 connected to P7.3 center
// reflectance sensor 5 connected to P7.4 center
// reflectance sensor 6 connected to P7.5
// reflectance sensor 7 connected to P7.6
// reflectance sensor 8 connected to P7.7 (robot's left, robot off road to right)

#include "stdint.h"
#include "msp.h"
#include "Reflectance.h"
#include "Clock.h"
#include "TExaS.h"
#include "Motor.h"
#include "xunji.h"
#include "UART0.h"
#include <stdio.h>
#include "CortexM.h"
uint8_t Data; // QTR-8RC
volatile uint32_t FallingEdges1;
volatile uint32_t FallingEdges4;
void Eight_xunji(void){
while(1){
  Data = Reflectance_Read(500); // your measurement
  printf("Data=%02x\n",Data);
  xunji(Data);
 }
}
void EdgeTrigger_Init(void){
  FallingEdges1 = FallingEdges4 = 0;  // initialize counters
  P1->SEL0 &= ~0x12;
  P1->SEL1 &= ~0x12;                 // configure P1.4 and P1.1 as GPIO
  P1->DIR &= ~0x12;                  // make P1.4 and P1.1 in (built-in Button 1 and Button 2)
  P1->REN |= 0x12;                   // enable pull resistors on P1.4 and P1.1
  P1->OUT |= 0x12;                   // P1.4 and P1.1 are pull-up
  P1->IES |= 0x12;                   // P1.4 and P1.1 are falling edge event
  P1->IFG &= ~0x12;                  // clear flag4 and flag1 (reduce possibility of extra interrupt)
  P1->IE |= 0x12;                    // arm interrupt on P1.4 and P1.1
  NVIC->IP[8] = (NVIC->IP[8]&0x00FFFFFF)|0x40000000; // priority 2
  NVIC->ISER[1] = 0x00000008;        // enable interrupt 35 in NVIC
}

// Uses P1IV to solve critical section/race
void PORT1_IRQHandler(void){ uint8_t status;
//  P1->OUT ^= 0x01;                 // toggle LED1
 // P1->OUT ^= 0x01;                 // toggle LED1
  status = P1IV;  // 2*(n+1) where n is highest priority
// if P1.1, returns 0x04 and clears flag1
// if P1.4, returns 0x0A and clears flag4
  if(status == 0x04){
    P2->OUT &= ~0x07;
    P1->OUT ^= 0x01;// toggle Red RGB LED
    Eight_xunji();
    FallingEdges1 = FallingEdges1 + 1;
    status = P1IV;
  }
  if(status == 0x0A){
    FallingEdges4 = FallingEdges4 + 1;
    P1->OUT &= ~0x01;
    P2->OUT ^= 0x04; // toggle blue RGB LED
  }
}
  int main(void){
    Clock_Init48MHz();
    Reflectance_Init();// your initialization
    Motor_Init();
    UART0_Initprintf();
    EdgeTrigger_Init();              // initialize P1.4 and P1.1 interrupts
    // initialize P1.0 and make it output (P1.0 built-in LED1)
    P1->SEL0 &= ~0x01;
    P1->SEL1 &= ~0x01;                 // configure built-in LED1 as GPIO
    P1->DIR |= 0x01;                   // make built-in LED1 out
    P1->OUT &= ~0x01;                  // LED1 = off
    // initialize P2.2-P2.0 and make them outputs (P2.2-P2.0 built-in RGB LEDs)
    P2->SEL0 &= ~0x07;
    P2->SEL1 &= ~0x07;                 // configure built-in RGB LEDs as GPIO
    P2->DS |= 0x07;                    // make built-in RGB LEDs high drive strength
    P2->DIR |= 0x07;                   // make built-in RGB LEDs out
    P2->OUT &= ~0x07;                  // RGB = off
    EnableInterrupts();                // clear the I bit
    while(1){
    WaitForInterrupt();
    }
}



