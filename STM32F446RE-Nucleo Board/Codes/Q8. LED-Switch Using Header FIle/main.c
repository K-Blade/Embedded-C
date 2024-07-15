#include <stdint.h>
#include "stm32f446xx.h"
#include <stdio.h>
#include <stddef.h>

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

void delay(){
	for(uint32_t i=0; i<1000000; i++);
}

int main(void)
{
	RCC->AHB1ENR |=RCC_AHB1ENR_GPIOAEN | RCC_AHB1ENR_GPIOCEN;  //Enabling GPIOA and GPIOC
	GPIOA->MODER |=(1<<10);  //Port-A5 made output
	GPIOA->OTYPER &=~(1<<5);
	GPIOA->OSPEEDR |=(1<<10);
	GPIOA->PUPDR &=~(3<<10);

	GPIOC->MODER &=~(3<<27);  //Port-C13 made input
	GPIOC->OSPEEDR |=(1<<26);
	GPIOC->PUPDR |=(1<<26);
    /* Loop forever */
	printf("Hello World\n");
	for(;;){
		if((GPIOC->IDR)&(1<<13)){
			printf("Button Not Pressed\n");
			GPIOA->ODR &=~(1<<5);
		}else{
			printf("Button Pressed\n");
			GPIOA->ODR |=(1<<5);
		}
	}
}
