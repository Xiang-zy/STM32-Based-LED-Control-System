#ifndef _USART_H
#define _USART_H
#include "stm32f10x.h"

void Serial_Init(void);
void Serial_SendByte(uint16_t Byte);
void Serial_SendString(char *String);

#endif
