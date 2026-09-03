/*
 * LCD.h
 *
 * Created: 03-Sep-26 6:33:26 PM
 *  Author: tarek
 */ 
#ifndef LCD_H_
#define LCD_H_
#include "Dio.h"
#include "Registers.h"
#include "Bit_Math.h"
#include "Std_Types.h"

void LCD_init(void);
void LCD_sendChar(u8 Data);
void LCD_SendCommand(u8 command);
void LCD_SendString(u8 *str);

void GoToXY(u8 x,u8 y);

void LCD_voidWriteNumber(s32 num);

#endif