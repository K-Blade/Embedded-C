#include <stdint.h>
#include <stdio.h>
#define __IO volatile

#define RCC_BASE (0x40023800)
#define RCC_OFFSET (0x30)
#define RCC ((__IO uint32_t*)(RCC_BASE+RCC_OFFSET))

typedef struct{
	__IO uint32_t MODER;
	__IO uint32_t OTYPER;
	__IO uint32_t OSPEEDR;
	__IO uint32_t PUPDR;
	__IO uint32_t IDR;
	__IO uint32_t ODR;
	__IO uint32_t BSRR;
	__IO uint32_t LCKR;
	__IO uint32_t AFR[2];
}GPIO_TypeDef;

#define GPIOA_BASE (0x40020000)
#define GPIOA ((GPIO_TypeDef *)GPIOA_BASE)

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

void delay(int n){
	for(uint32_t i=0; i<n; i++);
}

int main(void)
{
	*RCC|=(1<<0)| (1<<2);

	GPIOA->MODER |=5;  //Port-A0 and A1 made output
	GPIOA->OTYPER &=~3;
	GPIOA->OSPEEDR |=5;
	GPIOA->PUPDR &=~15;

	printf("Hello World\n");

	for(;;){
		GPIOA->ODR |=1;
		delay(500000);
		GPIOA->ODR &=~1;
		delay(500000);
		GPIOA->ODR |=(1<<1);
		delay(500000);
		GPIOA->ODR &=~(1<<1);
		delay(500000);
	}
}
