/*
 * CFile1.c
 *
 * Created: 02-Sep-26 8:06:34 PM
 *  Author: tarek
 */ 
#ifndef BIT_MATH_H
#define BIT_MATH_H

#define SET_BIT(REG,BIT)       (REG |= (1 << BIT))
#define CLR_BIT(REG,BIT)       (REG &= ~(1 << BIT))
#define GET_BIT(REG,BIT)       ((REG >> BIT) & 1)
#define TOG_BIT(REG,BIT)       (REG ^= (1 << BIT))

#endif