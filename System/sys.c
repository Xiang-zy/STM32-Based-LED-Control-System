#include "sys.h"

void RCC_Configuration(void)
	{
	RCC_DeInit();// 把RCC外设初始化成复位状态
	RCC_HSEConfig(RCC_HSE_ON);//使能HSE,8M

	// 等待 HSE 启动稳定,只有 HSE 稳定之后则继续往下执行
	if (RCC_WaitForHSEStartUp() == SUCCESS) {
		RCC_PLLConfig(RCC_PLLSource_HSE_Div1,RCC_PLLMul_9);// 设置PLL时钟,72M
		RCC_PLLCmd(ENABLE);// 开启PLL

		// 等待 PLL稳定
		while (RCC_GetFlagStatus(RCC_FLAG_PLLRDY) == RESET) {
		}
		// 当PLL稳定之后，把PLL时钟切换为系统时钟SYSCLK
		RCC_SYSCLKConfig(RCC_SYSCLKSource_PLLCLK);
		
		RCC_HCLKConfig(RCC_SYSCLK_Div1);// AHB预分频因子,72M
		RCC_PCLK2Config(RCC_HCLK_Div1);// APB2预分频因子,72M
		RCC_PCLK1Config(RCC_HCLK_Div2);// APB1预分频因子,36M
			
	}
	else ;
}

void Systick_Configuration(void)
{
		SysTick_CLKSourceConfig(SysTick_CLKSource_HCLK);
		SysTick_Config(SystemCoreClock/8);
}

