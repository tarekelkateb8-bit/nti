#include "calc.h"
#include "LCD.h"
#include "keys.h"

#define KEY_DIV     10
#define KEY_MUL     11
#define KEY_SUB     12
#define KEY_CLEAR   13
#define KEY_EQUAL   14
#define KEY_ADD     15

#define MAX_TOKENS  20

static s32 numbers[MAX_TOKENS];
static u8 operators[MAX_TOKENS];

static s32 currentNumber = 0;
static u8 numberEntered = 0;
static u8 operatorCount = 0;
static u8 numberCount = 0;
static u8 resultDisplayed = 0;

static void CALC_voidClear(void)
{
	u8 i;

	currentNumber = 0;
	numberEntered = 0;
	operatorCount = 0;
	numberCount = 0;
	resultDisplayed = 0;

	for (i = 0; i < MAX_TOKENS; i++)
	{
		numbers[i] = 0;
		operators[i] = 255;
	}

	LCD_SendCommand(0x01);
}

static void CALC_voidStoreNumber(void)
{
	if (numberEntered)
	{
		if (numberCount < MAX_TOKENS)
		{
			numbers[numberCount] = currentNumber;
			numberCount++;
		}

		currentNumber = 0;
		numberEntered = 0;
	}
}

static s32 CALC_s32Calculate(void)
{
	u8 i;
	s32 temp[MAX_TOKENS];
	s32 result;

	for (i = 0; i < numberCount; i++)
	{
		temp[i] = numbers[i];
	}

	for (i = 0; i < operatorCount; i++)
	{
		if (operators[i] == KEY_MUL)
		{
			temp[i] = temp[i] * temp[i + 1];

			for (u8 j = i + 1; j < numberCount - 1; j++)
			{
				temp[j] = temp[j + 1];
			}

			for (u8 j = i; j < operatorCount - 1; j++)
			{
				operators[j] = operators[j + 1];
			}

			numberCount--;
			operatorCount--;
			i--;
		}
		else if (operators[i] == KEY_DIV)
		{
			if (temp[i + 1] == 0)
			{
				LCD_SendCommand(0x01);
				LCD_SendString((u8*)"Error");
				resultDisplayed = 1;
				return 0;
			}

			temp[i] = temp[i] / temp[i + 1];

			for (u8 j = i + 1; j < numberCount - 1; j++)
			{
				temp[j] = temp[j + 1];
			}

			for (u8 j = i; j < operatorCount - 1; j++)
			{
				operators[j] = operators[j + 1];
			}

			numberCount--;
			operatorCount--;
			i--;
		}
	}

	result = temp[0];

	for (i = 0; i < operatorCount; i++)
	{
		if (operators[i] == KEY_ADD)
		{
			result += temp[i + 1];
		}
		else if (operators[i] == KEY_SUB)
		{
			result -= temp[i + 1];
		}
	}

	return result;
}

void CALC_voidInit(void)
{
	LCD_init();
	KEYS_voidInit();
	CALC_voidClear();
}

void CALC_voidRun(void)
{
	u8 key;
	s32 result;

	key = KEYS_u8GetKey();

	if (key == 255)
	{
		return;
	}

	if (key == KEY_CLEAR)
	{
		CALC_voidClear();
		return;
	}

	if (key <= 9)
	{
		if (resultDisplayed)
		{
			CALC_voidClear();
		}

		currentNumber = (currentNumber * 10) + key;
		numberEntered = 1;

		LCD_sendChar(key + '0');

		return;
	}

	if ((key == KEY_ADD) ||
	(key == KEY_SUB) ||
	(key == KEY_MUL) ||
	(key == KEY_DIV))
	{
		if (numberEntered)
		{
			CALC_voidStoreNumber();

			if (operatorCount < MAX_TOKENS)
			{
				operators[operatorCount] = key;
				operatorCount++;
			}

			if (key == KEY_ADD)
			{
				LCD_sendChar('+');
			}
			else if (key == KEY_SUB)
			{
				LCD_sendChar('-');
			}
			else if (key == KEY_MUL)
			{
				LCD_sendChar('*');
			}
			else if (key == KEY_DIV)
			{
				LCD_sendChar('/');
			}
		}

		return;
	}

	if (key == KEY_EQUAL)
	{
		CALC_voidStoreNumber();

		if (numberCount == 0)
		{
			return;
		}

		result = CALC_s32Calculate();

		GoToXY(1, 0);
		LCD_SendString((u8*)"-->");
		LCD_voidWriteNumber(result);

		currentNumber = result;
		numberEntered = 1;
		resultDisplayed = 1;

		operatorCount = 0;
		numberCount = 1;
		numbers[0] = result;

		return;
	
	}
}