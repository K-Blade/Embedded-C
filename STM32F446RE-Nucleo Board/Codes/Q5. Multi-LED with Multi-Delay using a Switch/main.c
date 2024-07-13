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
#define GPIOA0 ((GPIO_TypeDef *)GPIOA_BASE)
#define GPIOA1 ((GPIO_TypeDef *)GPIOA_BASE)

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

void delay(int n){
	for(uint32_t i=0; i<n; i++);
}

int main(void)
{
	*RCC|=(1<<0)| (1<<2);

	GPIOA0->MODER |=1;  //Port-A0 made output
	GPIOA0->OTYPER &=~1;
	GPIOA0->OSPEEDR |=1;
	GPIOA0->PUPDR &=~3;

	GPIOA1->MODER |=(1<<2);  //Port-A1 made output
	GPIOA1->OTYPER &=~(1<<1);
	GPIOA1->OSPEEDR |=(1<<2);
	GPIOA1->PUPDR &=~(3<<2);

	printf("Hello World\n");

	for(;;){
		GPIOA0->ODR &=~(1<<5);
		delay(200000);
		GPIOA0->ODR |=(1<<5);
		delay(200000);
		GPIOA1->ODR &=~(1<<5);
		delay(500000);
		GPIOA1->ODR |=(1<<5);
		delay(500000);
	}
}
