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
#include "LCD.h"
#include "keys.h"

u8 arr[10] =
{
	0x3F,   
	0x06,   
	0x5B,   
	0x4F,   
	0x66,   
	0x6D,   
	0x7D,   
	0x07,   
	0x7F,   
	0x6F    
};

int main(void)
{
	DIO_voidSetPortDirection(PORT_A, OUTPUT);

	KEYS_voidInit();

	while (1)
	{
		u8 key = KEYS_u8GetKey();

		if (key <= 9)
		{
			DIO_voidSetPortValue(PORT_A, arr[key]);
		}
		else if (key == 13)
		{
			/* ON/C = Reset */
			DIO_voidSetPortValue(PORT_A, 0x00);
		}
	}
}