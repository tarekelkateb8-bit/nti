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

int main(void)
{
	LCD_init();

	GoToXY(0, 0);
	LCD_SendString((u8*)"Tarek");
	GoToXY(1, 3);
	LCD_voidWriteNumber(2006);

	while (1)
	{
	}

	return 0;
}