#include "led.h"


void LED_init(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0|GPIO_Pin_1|GPIO_Pin_2|GPIO_Pin_3|GPIO_Pin_4|GPIO_Pin_5|GPIO_Pin_6|GPIO_Pin_7;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure);
}

void LED_ALL_OFF(void)
{
		GPIO_SetBits(GPIOA, GPIO_Pin_0);
		GPIO_SetBits(GPIOA, GPIO_Pin_1);
		GPIO_SetBits(GPIOA, GPIO_Pin_2);
		GPIO_SetBits(GPIOA, GPIO_Pin_3);
		GPIO_SetBits(GPIOA, GPIO_Pin_4);
		GPIO_SetBits(GPIOA, GPIO_Pin_5);
		GPIO_SetBits(GPIOA, GPIO_Pin_6);
		GPIO_SetBits(GPIOA, GPIO_Pin_7);
}

void scrolling_LEDS(int num)
{
	switch(num){
		case 0: GPIO_ResetBits(GPIOA, GPIO_Pin_0);break;
		case 1 :GPIO_ResetBits(GPIOA, GPIO_Pin_1);break;
		case 2 :GPIO_ResetBits(GPIOA, GPIO_Pin_2);break;
		case 3 :GPIO_ResetBits(GPIOA, GPIO_Pin_3);break;
		case 4 :GPIO_ResetBits(GPIOA, GPIO_Pin_4);break;
		case 5 :GPIO_ResetBits(GPIOA, GPIO_Pin_5);break;
		case 6 :GPIO_ResetBits(GPIOA, GPIO_Pin_6);break;
		case 7 :GPIO_ResetBits(GPIOA, GPIO_Pin_7);break;
	}
}
	
