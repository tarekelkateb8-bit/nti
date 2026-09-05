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
	
	DIO_voidSetPinDirection(PORT_A, PIN0, INPUT);
	DIO_voidSetPinValue(PORT_A, PIN0, HIGH);
	DIO_voidSetPinDirection(PORT_C, PIN0, OUTPUT);
	DIO_voidSetPinDirection(PORT_C, PIN1, OUTPUT);
	DIO_voidSetPinDirection(PORT_C, PIN2, OUTPUT);
	DIO_voidSetPinDirection(PORT_C, PIN3, OUTPUT);

	while (1)
	{
		if (DIO_u8GetPinValue(PORT_A, PIN0) == HIGH)
		{
			DIO_voidSetPinValue(PORT_C, PIN0, HIGH);  
			DIO_voidSetPinValue(PORT_C, PIN3, HIGH);  
			DIO_voidSetPinValue(PORT_C, PIN1, LOW);   
			DIO_voidSetPinValue(PORT_C, PIN2, LOW);   
		}
		else
		{
			
			DIO_voidSetPinValue(PORT_C, PIN0, LOW);
			DIO_voidSetPinValue(PORT_C, PIN1, LOW);
			DIO_voidSetPinValue(PORT_C, PIN2, LOW);
			DIO_voidSetPinValue(PORT_C, PIN3, LOW);
		}
	}
}