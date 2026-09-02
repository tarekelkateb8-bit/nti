#include "Dio.h"
void DIO_voidSetPinDirection(u8 PortId, u8 PinId, u8 Direction)
{
	switch (PortId)
	{
		case PORT_A:
		if (Direction == OUTPUT)
		SET_BIT(DDRA, PinId);
		else
		CLR_BIT(DDRA, PinId);
		break;

		case PORT_B:
		if (Direction == OUTPUT)
		SET_BIT(DDRB, PinId);
		else
		CLR_BIT(DDRB, PinId);
		break;

		case PORT_C:
		if (Direction == OUTPUT)
		SET_BIT(DDRC, PinId);
		else
		CLR_BIT(DDRC, PinId);
		break;

		case PORT_D:
		if (Direction == OUTPUT)
		SET_BIT(DDRD, PinId);
		else
		CLR_BIT(DDRD, PinId);
		break;
	}
}


void DIO_voidSetPinValue(u8 PortId, u8 PinId, u8 Value)
{
	switch (PortId)
	{
		case PORT_A:
		if (Value == HIGH)
		SET_BIT(PORTA, PinId);
		else
		CLR_BIT(PORTA, PinId);
		break;

		case PORT_B:
		if (Value == HIGH)
		SET_BIT(PORTB, PinId);
		else
		CLR_BIT(PORTB, PinId);
		break;

		case PORT_C:
		if (Value == HIGH)
		SET_BIT(PORTC, PinId);
		else
		CLR_BIT(PORTC, PinId);
		break;

		case PORT_D:
		if (Value == HIGH)
		SET_BIT(PORTD, PinId);
		else
		CLR_BIT(PORTD, PinId);
		break;
	}
}


u8 DIO_u8GetPinValue(u8 PortId, u8 PinId)
{
	u8 Local_u8Value = 0;

	switch (PortId)
	{
		case PORT_A:
		Local_u8Value = GET_BIT(PINA, PinId);
		break;

		case PORT_B:
		Local_u8Value = GET_BIT(PINB, PinId);
		break;

		case PORT_C:
		Local_u8Value = GET_BIT(PINC, PinId);
		break;

		case PORT_D:
		Local_u8Value = GET_BIT(PIND, PinId);
		break;
	}

	return Local_u8Value;
}


void DIO_voidSetPortDirection(u8 PortId, u8 Direction)
{
	switch (PortId)
	{
		case PORT_A:
		if (Direction == OUTPUT)
		DDRA = 0b11111111;
		else
		DDRA = 0x00;
		break;

		case PORT_B:
		if (Direction == OUTPUT)
		DDRB = 0b11111111;
		else
		DDRB = 0b00000000;
		break;

		case PORT_C:
		if (Direction == OUTPUT)
		DDRC = 0b11111111;
		else
		DDRC = 0b00000000;
		break;

		case PORT_D:
		if (Direction == OUTPUT)
		DDRD = 0b11111111;
		else
		DDRD = 0b00000000;
		break;
	}
}


void DIO_voidSetPortValue(u8 PortId, u8 Value)
{
	switch (PortId)
	{
		case PORT_A:
		PORTA = Value;
		break;

		case PORT_B:
		PORTB = Value;
		break;

		case PORT_C:
		PORTC = Value;
		break;

		case PORT_D:
		PORTD = Value;
		break;
	}
}