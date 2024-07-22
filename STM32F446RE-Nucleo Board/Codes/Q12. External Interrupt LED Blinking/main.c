#include <stdint.h>
#include <stdio.h>
#include "stm32f446xx.h"
#include <stddef.h>

void LED_init(){
	RCC->AHB1ENR |=RCC_AHB1ENR_GPIOAEN;
	GPIOA->MODER |=(1<<10);
	GPIOA->OTYPER &=~(1<<5);
	GPIOA->OSPEEDR |=(1<<10);
	GPIOA->PUPDR &=~(3<<10);
}

void button_interrupt_init(){
	 RCC->AHB1ENR |= RCC_AHB1ENR_GPIOCEN;
	 RCC->APB2ENR |= RCC_APB2ENR_SYSCFGEN;

	 __disable_irq();

	 SYSCFG->EXTICR[3] |= (2<<4);
	 EXTI->FTSR |= (1<<13);
	 EXTI->IMR |=(1<<13);

	 NVIC_EnableIRQ(EXTI15_10_IRQn);

	 __enable_irq();

}

void EXTI15_10_IRQHandler(){
	if (EXTI->PR & (1<<13)){
		EXTI->PR |= (1<<13);
		GPIOA->ODR ^=(1<<5);
		printf("In Handler");
	}
}

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

int main(void)
{
	LED_init();
	button_interrupt_init();
	printf("im in main\n");
	while(1){
		printf("in while\n");
	    for(uint32_t i=0;i<=0xffffff;i++);
	}
}
