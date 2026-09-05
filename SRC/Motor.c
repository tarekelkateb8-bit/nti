/*
 * Motor.c
 *
 * Created: 05-Sep-26 9:28:49 PM
 *  Author: tarek
 */ 
#include "Motor.h"
#include "Dio.h"

#define MOTOR_PORT  PORT_C
#define MOTOR_PIN   PIN0

void DC_MOTOR_Init(void)
{
	DIO_voidSetPinDirection(MOTOR_PORT, MOTOR_PIN, OUTPUT);
	DC_MOTOR_Stop();
}

void DC_MOTOR_Start(void)
{
	DIO_voidSetPinValue(MOTOR_PORT, MOTOR_PIN, HIGH);
}

void DC_MOTOR_Stop(void)
{
	DIO_voidSetPinValue(MOTOR_PORT, MOTOR_PIN, LOW);
}