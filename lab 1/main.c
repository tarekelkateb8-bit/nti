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
int main()
{
	 DDRA=0b00000010;
	  PORTA = 0b00000001;
	 while (1){
		 if (GET_BIT(PINA,0)==0){
		 PORTA=0b00000011;}
	else {PORTA=0b00000001;}
	 
}
return 0;
}