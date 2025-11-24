#ifndef _ADC_H
#define _ADC_H
#include "stm32f10x.h"

void adc_init(void);
uint16_t AD_GetValue(void);

#endif
