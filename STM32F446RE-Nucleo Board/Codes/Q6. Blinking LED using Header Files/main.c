#include <stdint.h>
#include "stm32f446xx.h"
#include <stdio.h>
#include <stddef.h>

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

void delay(){
	for(uint32_t i=0; i<500000; i++);
}

int main(void)
{
	RCC->AHB1ENR |=(1<<0);
	GPIOA->MODER |=(1<<10);  //Port-A5 made output
	GPIOA->OTYPER &=~(1<<5);
	GPIOA->OSPEEDR |=(1<<10);
	GPIOA->PUPDR &=~(3<<10);
    /* Loop forever */
	printf("Hello World\n");
	for(;;){
		GPIOA->ODR |=(1<<5);
		delay();
		GPIOA->ODR &=~(1<<5);
		delay();
	}
}
