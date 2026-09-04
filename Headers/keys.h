/*
 * keys.h
 *
 * Created: 04-Sep-26 9:52:08 AM
 *  Author: tarek
 */ 
#ifndef KEYS_H_
#define KEYS_H_

#include "Std_Types.h"
#include "Dio.h"

#define ROW0    PIN0
#define ROW1    PIN1
#define ROW2    PIN2
#define ROW3    PIN3

#define COL0    PIN4
#define COL1    PIN5
#define COL2    PIN6
#define COL3    PIN7

void KEYS_voidInit(void);
u8 KEYS_u8GetKey(void);

#endif
