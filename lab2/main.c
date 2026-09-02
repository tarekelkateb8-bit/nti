/*
 * CFile1.c
 *
 * Created: 02-Sep-26 7:14:00 PM
 *  Author: tarek
 */ 
#include <stdio.h>
#include "Registers.h"
#include "Std_Types.h"
#include "Dio.h"
#include "Bit_Math.h"

int main()
{
	
	DIO_voidSetPortDirection(PORT_A, INPUT);

	
	DIO_voidSetPinDirection(PORT_C, PIN0, OUTPUT);
	DIO_voidSetPinDirection(PORT_C, PIN1, OUTPUT);
	DIO_voidSetPinDirection(PORT_C, PIN2, OUTPUT);

	DIO_voidSetPinValue(PORT_A, PIN0, HIGH);
	DIO_voidSetPinValue(PORT_A, PIN1, HIGH);
	DIO_voidSetPinValue(PORT_A, PIN2, HIGH);
	DIO_voidSetPinValue(PORT_A, PIN7, HIGH);

	DIO_voidSetPinValue(PORT_C, PIN0, LOW);
	DIO_voidSetPinValue(PORT_C, PIN1, LOW);
	DIO_voidSetPinValue(PORT_C, PIN2, LOW);

	while (1)
	{
		
		if (DIO_u8GetPinValue(PORT_A, PIN7) == LOW)
		{
			DIO_voidSetPinValue(PORT_C, PIN0, HIGH);
			DIO_voidSetPinValue(PORT_C, PIN1, HIGH);
			DIO_voidSetPinValue(PORT_C, PIN2, HIGH);
		}
		else
		{
			
			if (DIO_u8GetPinValue(PORT_A, PIN0) == LOW)
			DIO_voidSetPinValue(PORT_C, PIN0, HIGH);
			else
			DIO_voidSetPinValue(PORT_C, PIN0, LOW);

			
			if (DIO_u8GetPinValue(PORT_A, PIN1) == LOW)
			DIO_voidSetPinValue(PORT_C, PIN1, HIGH);
			else
			DIO_voidSetPinValue(PORT_C, PIN1, LOW);

			
			if (DIO_u8GetPinValue(PORT_A, PIN2) == LOW)
			DIO_voidSetPinValue(PORT_C, PIN2, HIGH);
			else
			DIO_voidSetPinValue(PORT_C, PIN2, LOW);
		}
	}

	return 0;
}