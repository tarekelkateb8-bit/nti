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
#include "calc.h"
int main(void)
{
	CALC_voidInit();

	while (1)
	{
		CALC_voidRun();
	}

	return 0;
}