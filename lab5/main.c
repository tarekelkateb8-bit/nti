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
#include "Dio.h"
#include "Motor.h"
#include "Dio.h"
#include "Motor.h"

int main(void)
{
	DIO_voidSetPinDirection(PORT_B, PIN0, INPUT);
	DIO_voidSetPinValue(PORT_B, PIN0, HIGH);

	DC_MOTOR_Init();

	while (1)
	{
		if (DIO_u8GetPinValue(PORT_B, PIN0) == HIGH)
		{
			DC_MOTOR_Start();
		}
		else
		{
			DC_MOTOR_Stop();
		}
	}
}