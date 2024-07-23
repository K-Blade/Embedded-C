#include <stdint.h>
#include "stm32f446xx.h"
#include <stddef.h>

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

void SysClockConfig (void)
{
	#define PLL_M 	4
	#define PLL_N 	180
	#define PLL_P 	0

	RCC->CR |= RCC_CR_HSEON;
	while (!(RCC->CR & RCC_CR_HSERDY));

	RCC->APB1ENR |= RCC_APB1ENR_PWREN;
	PWR->CR |= PWR_CR_VOS;

	FLASH->ACR = FLASH_ACR_ICEN | FLASH_ACR_DCEN | FLASH_ACR_PRFTEN | FLASH_ACR_LATENCY_5WS;

	RCC->CFGR |= RCC_CFGR_HPRE_DIV1;
	RCC->CFGR |= RCC_CFGR_PPRE1_DIV4;
	RCC->CFGR |= RCC_CFGR_PPRE2_DIV2;

	RCC->PLLCFGR = (PLL_M <<0) | (PLL_N << 6) | (PLL_P <<16) | (RCC_PLLCFGR_PLLSRC_HSE);

	RCC->CR |= RCC_CR_PLLON;
	while (!(RCC->CR & RCC_CR_PLLRDY));

	RCC->CFGR |= RCC_CFGR_SW_PLL;
	while ((RCC->CFGR & RCC_CFGR_SWS) != RCC_CFGR_SWS_PLL);
}

void UART2_SendChar(char ch)
{
	USART2->DR=ch;
	while(!(USART2->SR &(1<<6)));
	return;
}

void UART2_SendString(char *string)
{
	while(*string !='\0')
	{
		UART2_SendChar(*string);
		string++;
	}
}

void USART2_config(void)
{
	RCC->AHB1ENR |=(1<<2);
	RCC->AHB1ENR |=(1<<0);
	RCC->APB1ENR |=(1<<17);

	GPIOC->MODER &=~(3<<27);
	GPIOC->OSPEEDR |=(3<<26);

	GPIOA->MODER |= (2<<4);
	GPIOA->MODER |= (2<<6);

	GPIOA->OSPEEDR |=(3<<4);
	GPIOA->OSPEEDR |=(3<<6);

	GPIOA->AFR[0] |=(7<<8);
	GPIOA->AFR[0] |=(7<<12);

	USART2->CR1 = 0x00;
	USART2->CR1 |=(1<<13);
	USART2->CR1 &=~(1<<12);
	USART2->BRR |= (1<<0);
	USART2->BRR |= (24<<4);
	USART2->CR1 |= (1<<2);
	USART2->CR1 |= (1<<3);
}

uint8_t UART_getchar(){
	while (!(USART2->SR & (1<<5)));
	return USART2->DR;
}

int btn_pressed()
{
	return (!(GPIOC->IDR &(1<<13)));
}

int main(void)
{
	int i=0;
	char pwd[9];
	SysClockConfig();
	USART2_config();

	UART2_SendString("\n\rEnter Password: \n");

	for(i=0;i<8;i++){
		pwd[i] = UART_getchar();
	}
	pwd[i]='\0';

	UART2_SendString(pwd);

}
