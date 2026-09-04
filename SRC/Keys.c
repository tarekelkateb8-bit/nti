/*
 * Keys.c
 *
 * Created: 04-Sep-26 9:53:37 AM
 *  Author: tarek
 */ 
#include "keys.h"

void KEYS_voidInit(void)
{
	
	DIO_voidSetPinDirection(PORT_B, ROW0, OUTPUT);
	DIO_voidSetPinDirection(PORT_B, ROW1, OUTPUT);
	DIO_voidSetPinDirection(PORT_B, ROW2, OUTPUT);
	DIO_voidSetPinDirection(PORT_B, ROW3, OUTPUT);

	DIO_voidSetPinDirection(PORT_B, COL0, INPUT);
	DIO_voidSetPinDirection(PORT_B, COL1, INPUT);
	DIO_voidSetPinDirection(PORT_B, COL2, INPUT);
	DIO_voidSetPinDirection(PORT_B, COL3, INPUT);

	DIO_voidSetPinValue(PORT_B, COL0, HIGH);
	DIO_voidSetPinValue(PORT_B, COL1, HIGH);
	DIO_voidSetPinValue(PORT_B, COL2, HIGH);
	DIO_voidSetPinValue(PORT_B, COL3, HIGH);

	DIO_voidSetPinValue(PORT_B, ROW0, HIGH);
	DIO_voidSetPinValue(PORT_B, ROW1, HIGH);
	DIO_voidSetPinValue(PORT_B, ROW2, HIGH);
	DIO_voidSetPinValue(PORT_B, ROW3, HIGH);
	
}

u8 KEYS_u8GetKey(void)
{
	u8 key = 255;

	u8 keys[4][4] =
	{
		{7, 8, 9, 10},
		{4, 5, 6, 11},
		{1, 2, 3, 12},
		{13, 0, 14, 15}
	};

	u8 rows[4] = {ROW0, ROW1, ROW2, ROW3};
	u8 cols[4] = {COL0, COL1, COL2, COL3};

	for (u8 i = 0; i < 4; i++)
	{
		DIO_voidSetPinValue(PORT_B, rows[i], LOW);

		for (u8 j = 0; j < 4; j++)
		{
			if (DIO_u8GetPinValue(PORT_B, cols[j]) == LOW)
			{
				key = keys[i][j];

				while (DIO_u8GetPinValue(PORT_B, cols[j]) == LOW);

				DIO_voidSetPinValue(PORT_B, rows[i], HIGH);

				return key;
			}
		}

		DIO_voidSetPinValue(PORT_B, rows[i], HIGH);
	}

	return key;
}