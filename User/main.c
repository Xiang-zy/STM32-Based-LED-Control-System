#include "stm32f10x.h"                  // Device header
#include "sys.h"
#include "usart.h"
#include "adc.h"
#include "LED.h"
#include "KEY.h"
#include "PWM.h"
#include <stdio.h>


u16 time_led = 0;
u16 time_adc = 0;

int main(void){	
	int LED_num = 0;
	uint16_t ADC_Value = 0;
	float voltage = 0;
	char buffer[10];
	extern u8 KEY_CHG ;
		
	RCC_Configuration();
	Systick_Configuration();
	Serial_Init();
	adc_init();
	LED_init();
	LED_ALL_OFF();
	KEY_init();
	PWM_Init(4072,17);
	
	
	while (1) {
		if (KEY_CHG == 0){
			if (time_led >= 2 ){
				LED_ALL_OFF();
				LED_num ++;
				if(LED_num>7)
					LED_num = 0;	
				time_led = 0;
			}
		}
		else {
			if (time_led >= 2 ){
				LED_ALL_OFF();
				LED_num --;
				if(LED_num<0)
					LED_num = 7;	
				time_led = 0;
			}
		}
		scrolling_LEDS(LED_num);
		
		ADC_Value = AD_GetValue();
		if(time_adc >= 8){
			voltage = ADC_Value * 3.3 / 4096.0;
			snprintf(buffer, sizeof(buffer), "%.2f", voltage);  // 将电压值格式化为字符串，保留两位小数
			Serial_SendString("The voltage is:");
			Serial_SendString(buffer);
			Serial_SendString("V\r\n");
			time_adc = 0;
		}
		PWM_SetCompare4(ADC_Value);
	}
}
