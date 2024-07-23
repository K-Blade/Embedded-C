#include <stdint.h>

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

uint32_t *AHB1ENR = (uint32_t*) 0x40023830;

uint32_t *DMA2_S0CR = (uint32_t*)0x40026410;
uint32_t *DMA2_S0NDTR = (uint32_t*)0x40026414;
uint32_t *DMA2_S0PAR = (uint32_t*)0x40026418;
uint32_t *DMA2_S0M0AR = (uint32_t*)0x4002641C;

void DMA2_init();
void DMA2_Start();

char source[8]="HELOYES";
char dest[8];
char dest1[4];

int main(void)
{
    DMA2_init();
    DMA2_Start();
    while(1)
    {
    }
}

void DMA2_init()
{
	*AHB1ENR |= (1<<22);
	*DMA2_S0CR |= (2<<6);
	*DMA2_S0CR &= ~(1<<25);
	*DMA2_S0CR |= (0<<16);
	*DMA2_S0CR |= (1<<10);
	*DMA2_S0CR &= ~(1<<13);
	*DMA2_S0CR |= (1<<9);
	*DMA2_S0CR &= ~(1<<11);
}

void DMA2_Start()
{
	*DMA2_S0NDTR = 8;
	*DMA2_S0M0AR = (uint32_t) &dest;
	*DMA2_S0PAR = (uint32_t) &source;
	*DMA2_S0CR |= (1<<0);
}
