/*
 * CFile1.c
 *
 * Created: 02-Sep-26 7:14:00 PM
 *  Author: tarek
 */ 
#define F_CPU 1000000
#include <stdio.h>
#include "Registers.h"
#include "Std_Types.h"
#include "Dio.h"
#include "Bit_Math.h"
#include "LCD.h"
#include "keys.h"
#include "calc.h"
#include "stepper.h"
#include <util/delay.h>


int main(void)
{
	Stepper_Init();

	while (1)
	{
		/* Rotate clockwise */
		Stepper_RotateCW(200);

		Stepper_Stop();

		_delay_ms(1000);

		/* Rotate counter-clockwise */
		Stepper_RotateCCW(200);

		Stepper_Stop();

		_delay_ms(1000);
	}
}