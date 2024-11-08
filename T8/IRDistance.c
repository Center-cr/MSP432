/*
 * IRDistance.c
 *
 *  Created on: 2022Äê12ÔÂ1ÈÕ
 *      Author: ZJH
 */




#include <stdint.h>
#include "../inc/ADC14.h"
#include "msp.h"

 int32_t z=1195172;
 int32_t e=1058;
int32_t LeftConvert(int32_t nl){
    int32_t dl;// returns left distance in mm
    dl=z/(nl-e);

    return dl; // replace this line
}

int32_t CenterConvert(int32_t nc){
    int32_t dc;
    dc=z/(nc-e);

  return dc; // replace this line
}

int32_t RightConvert(int32_t nr){
    int32_t dr;
    dr=z/(nr-e);
  return dr; // replace this line
}
