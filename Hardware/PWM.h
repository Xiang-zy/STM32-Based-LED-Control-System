#ifndef _PWM_H
#define _PWM_H
#include "stm32f10x.h"

void PWM_Init(u16 arr,u16 psc);
void PWM_SetCompare4(uint16_t Compare);

#endif
