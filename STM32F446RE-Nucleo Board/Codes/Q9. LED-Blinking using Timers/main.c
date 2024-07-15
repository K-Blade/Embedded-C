#include <stdint.h>
#include "stm32f446xx.h"
#include <stdio.h>
#include <stddef.h>

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

void timer2_init(void){
	RCC->APB1ENR |=(1U<<0);
	TIM2->PSC = 160000-1;
	TIM2->ARR = 500-1;
	TIM2->CNT = 0;
	TIM2->CR1=(1U<<0);
}

void TIM2_IRQHandler(){
	TIM2->SR &= ~(1U<<0);
	for (uint32_t i=0; i<200000;i++);
}

void Timer2_delay(uint32_t delay){
	TIM2->PSC = (160000-1);
	TIM2->ARR = (500-1)*delay;
	TIM2->CNT = 0;
	TIM2->CR1 |= (1<<0);
	while(!(TIM2->SR&0x01));
	TIM2->SR &= ~(0x01);
}

void GPIO_init(){
	RCC->AHB1ENR |=RCC_AHB1ENR_GPIOAEN;
	GPIOA->MODER |=(1<<10);
	GPIOA->OTYPER &=~(1<<5);
	GPIOA->OSPEEDR |=(1<<10);
	GPIOA->PUPDR &=~(3<<10);
}

int main(void)
{
	GPIO_init();
	timer2_init();

	while(1){
		GPIOA->ODR ^=(1<<5);

		Timer2_delay(5);
	}
}
