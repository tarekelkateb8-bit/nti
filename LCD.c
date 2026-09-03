/*
 * LCD.c
 *
 * Created: 03-Sep-26 6:35:26 PM
 * Author: tarek
 */

#include "LCD.h"
#include "Registers.h"
#include <util/delay.h>
#define F_CPU 1000000UL
void LCD_init(void)
{
	DIO_voidSetPortDirection(PORT_C, OUTPUT);
	DIO_voidSetPortDirection(PORT_D, OUTPUT);

	_delay_ms(20);

	LCD_SendCommand(0x38);
	_delay_ms(5);

	LCD_SendCommand(0x0C);
	_delay_ms(5);

	LCD_SendCommand(0x01);
	_delay_ms(5);

	LCD_SendCommand(0x06);
	_delay_ms(5);

	_delay_ms(5);
}
void LCD_SendCommand(u8 command)
{
	DIO_voidSetPinValue(PORT_D, PIN0, LOW);   // RS = 0
	DIO_voidSetPinValue(PORT_D, PIN1, LOW);   // RW = 0

	DIO_voidSetPortValue(PORT_C, command);

	DIO_voidSetPinValue(PORT_D, PIN2, HIGH);  // E = 1
	_delay_ms(1);
	DIO_voidSetPinValue(PORT_D, PIN2, LOW);   // E = 0

	_delay_ms(2);
}

void LCD_sendChar(u8 Data)
{
	DIO_voidSetPinValue(PORT_D, PIN0, HIGH);  // RS = 1
	DIO_voidSetPinValue(PORT_D, PIN1, LOW);   // RW = 0

	DIO_voidSetPortValue(PORT_C, Data);

	DIO_voidSetPinValue(PORT_D, PIN2, HIGH);  // E = 1
	_delay_ms(1);
	DIO_voidSetPinValue(PORT_D, PIN2, LOW);   // E = 0

	_delay_ms(1);
}

void LCD_SendString(u8 *str)
{
	while (*str != '\0')
	{
		LCD_sendChar(*str);
		str++;
	}
}

void GoToXY(u8 x, u8 y)
{
	u8 address;

	if (x == 0)
	{
		address = y;
	}
	else
	{
		address = 0x40 + y;
	}

	LCD_SendCommand(0x80 + address);
}

void LCD_voidWriteNumber(s32 num)
{
	u8 arr[10];
	u8 i = 0;

	if (num == 0)
	{
		LCD_sendChar('0');
		return;
	}

	if (num < 0)
	{
		LCD_sendChar('-');
		num = -num;
	}

	while (num > 0)
	{
		arr[i] = (num % 10) + '0';
		num = num / 10;
		i++;
	}

	while (i > 0)
	{
		i--;
		LCD_sendChar(arr[i]);
	}
}