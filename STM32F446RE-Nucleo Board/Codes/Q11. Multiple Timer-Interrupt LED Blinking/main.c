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
    // Enable TIM2 interrupt
    TIM2->DIER |= (1 << 0);
    // Enable TIM2 interrupt in NVIC
    NVIC_EnableIRQ(TIM2_IRQn);
    TIM2->CR1 |= (1 << 0);
}

void timer5_init(void){
	RCC->APB1ENR |=(1U<<3);
	TIM5->PSC = 80000-1;
	TIM5->ARR = 500-1;
	TIM5->CNT = 0;
	TIM5->CR1=(1U<<0);
    // Enable TIM5 interrupt
    TIM5->DIER |= (1 << 0);
    // Enable TIM5 interrupt in NVIC
    NVIC_EnableIRQ(TIM5_IRQn);
    TIM5->CR1 |= (1 << 0);
}

// Timer2 interrupt handler
void TIM2_IRQHandler(void) {
    // Clear update interrupt flag
	printf("IN TIM2_IRQHandler\n");
    TIM2->SR &= ~(1U << 0);
    GPIOA->ODR ^=(1U<<5);
}

// Timer2 interrupt handler
void TIM5_IRQHandler(void) {
    // Clear update interrupt flag
	printf("IN TIM5_IRQHandler\n");
    TIM5->SR &= ~(1U << 0);
    GPIOA->ODR ^=(1U<<0);
}

void GPIO_init(){
	RCC->AHB1ENR |=RCC_AHB1ENR_GPIOAEN;
	GPIOA->MODER |=((1<<10)|1);
	GPIOA->OTYPER &=~((1<<5)|1);
	GPIOA->OSPEEDR |=((1<<10)|1);
	GPIOA->PUPDR &=~((3<<10)|3);
}

int main(void)
{
	GPIO_init();
	timer2_init();
	timer5_init();

	while(1){
		printf("IN Main\n");
		for(uint32_t i=0; i<1000000; i++);
	}
}
