/*
 * CFile1.c
 *
 * Created: 02-Sep-26 7:12:34 PM
 *  Author: tarek
 */ 
#ifndef DIO_H
#define DIO_H
#include "Std_Types.h"
#include "Registers.h"
#include "Bit_Math.h"
#include "Std_Types.h"

#define INPUT   0
#define OUTPUT  1

#define PORT_A  0
#define PORT_B  1
#define PORT_C  2
#define PORT_D  3

#define PIN0    0
#define PIN1    1
#define PIN2    2
#define PIN3    3
#define PIN4    4
#define PIN5    5
#define PIN6    6
#define PIN7    7

#define LOW     0
#define HIGH    1

void DIO_voidSetPinDirection(u8 PortId, u8 PinId, u8 Direction);
void DIO_voidSetPinValue(u8 PortId, u8 PinId, u8 Value);
u8 DIO_u8GetPinValue(u8 PortId, u8 PinId);

void DIO_voidSetPortDirection(u8 PortId, u8 Direction);
void DIO_voidSetPortValue(u8 PortId, u8 Value);

#endif