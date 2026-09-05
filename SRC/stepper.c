/*
 * stepper.c
 *
 * Created: 05-Sep-26 6:44:07 PM
 *  Author: tarek
 */ 
#define F_CPU 1000000UL

#include "stepper.h"
#include "DIO.h"
#include "Registers.h"
#include <util/delay.h>

#define STEPPER_PORT PORT_C

static u8 stepIndex = 0;

static const u8 stepSequence[4] =
{
	0b00001001,
	0b00000011,
	0b00000110,
	0b00001100
};

void Stepper_Init(void)
{
	DIO_voidSetPortDirection(STEPPER_PORT, OUTPUT);

	Stepper_Stop();

	stepIndex = 0;
}

void Stepper_StepCW(void)
{
	DIO_voidSetPortValue(STEPPER_PORT, stepSequence[stepIndex]);

	stepIndex++;

	if (stepIndex >= 4)
	{
		stepIndex = 0;
	}

	_delay_ms(50);
}

void Stepper_StepCCW(void)
{
	DIO_voidSetPortValue(STEPPER_PORT, stepSequence[stepIndex]);

	if (stepIndex == 0)
	{
		stepIndex = 3;
	}
	else
	{
		stepIndex--;
	}

	_delay_ms(50);
}

void Stepper_RotateCW(u16 steps)
{
	while (steps > 0)
	{
		Stepper_StepCW();
		steps--;
	}
}

void Stepper_RotateCCW(u16 steps)
{
	while (steps > 0)
	{
		Stepper_StepCCW();
		steps--;
	}
}

void Stepper_Stop(void)
{
	DIO_voidSetPortValue(STEPPER_PORT, 0x00);
}