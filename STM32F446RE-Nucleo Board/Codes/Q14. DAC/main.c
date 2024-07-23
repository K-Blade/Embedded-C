#include <stdint.h>
#include "stm32f446xx.h"

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

int main(void)
{
    float val=0.0;
    uint32_t dac_value = 0x0;
    int32_t i = 0;

    
    RCC->AHB1ENR |= (1 << 0);

    GPIOA->MODER &= ~(3<<8);
    GPIOA->MODER |= (3<<8);

    RCC->APB1ENR |= (1 << 29);

    DAC->CR |= (1 << 0);
    DAC->CR &= ~(1 << 1);
    DAC->CR |= (1 << 2);
    DAC->CR |= (7 << 3);

    DAC->DHR12R1 = dac_value;
    DAC->SWTRIGR |= (1 << 0);


    	while (1)
    	{
    	 dac_value = val*(4095)/3.3;
    	 DAC->DHR12R1 = dac_value;
    	 DAC->SWTRIGR |= (1 << 0 );
    	 val += 0.5;
    	 for (i=0; i<5000000; i++);
    	 if (val>3) val=0.2;
    	}
        return 0;
    }
