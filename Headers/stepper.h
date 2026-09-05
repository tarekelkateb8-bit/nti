/*
 * stepper.h
 *
 * Created: 05-Sep-26 6:43:26 PM
 *  Author: tarek
 */ 
#ifndef STEPPER_H_
#define STEPPER_H_

#include "STD_TYPES.h"

void Stepper_Init(void);

void Stepper_StepCW(void);
void Stepper_StepCCW(void);

void Stepper_RotateCW(u16 steps);
void Stepper_RotateCCW(u16 steps);

void Stepper_Stop(void);

#endif