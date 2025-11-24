#ifndef _LED_H
#define _LED_H
#include "stm32f10x.h"

void LED_init(void);
void LED_ALL_OFF(void);
void scrolling_LEDS(int num);
	
#endif
