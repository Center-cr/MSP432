/*
 * Reflectance.h
 *
 *  Created on: 2022��12��1��
 *      Author: 1
 */

#ifndef REFLECTANCE_H_
#define REFLECTANCE_H_

void Reflectance_Init(void);

uint8_t Reflectance_Read(uint32_t time);

int32_t Reflectance_Position(uint8_t data);
