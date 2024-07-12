#include <stdio.h>

struct mydata{
	char c;
	int i;
	float f;
}st,*ptos;

int main(){
	struct mydata md={'M',58,58.8};
	ptos=&md;
	printf("%c\n%d\n%f\n\n", ptos->c, ptos->i, ptos->f);
	printf("%c\n%d\n%f\n\n", (*ptos).c,  (*ptos).i,  (*ptos).f);
}
