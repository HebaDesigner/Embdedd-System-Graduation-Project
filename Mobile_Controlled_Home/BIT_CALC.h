/*
 *  BIT_CALC.h
 *  Created on: May 6, 2023
 *  Author: Heba Atef Ahmed
 */
#include"STD_TYPES.h"

#ifndef BIT_CALC_H_
#define BIT_CALC_H_
#define SET_BIT(VAR,BitNo)    (VAR) |=  (1 << (BitNo))
#define CLR_BIT(VAR,BitNo)    (VAR) &= (~(1 << (BitNo)))
#define TOG_BIT(VAR,BitNo)    (VAR) ^=  (1 << (BitNo))
#define GET_BIT(VAR,BitNo)    (((VAR) >> (BitNo)) & (1))
#define ASSIGN_Bit(VAR,BitNo,value) do{if(value==1) SET_BIT(VAR,BitNo); else CLR_BIT(VAR,BitNo);}while(0)

#endif /* BIT_CALC_H_ */
