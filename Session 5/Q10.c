#include <stdio.h>

struct mydata{
	char c;
	int i;
	float f;
}st,*ptost;

void manipulate_struct(struct mydata *ptost){
	ptost->c='Z';
	ptost->i=58;
	ptost->f=58.58;
}

int main(){
	struct mydata st={'D',43,43.43};
	struct mydata *ptost;
	ptost=&st;
	printf("in main(): %c, %d, %0.2f\n", st.c,st.i,st.f);
	manipulate_struct(&st);
	printf("in main(): %c, %d, %0.2f\n", ptost->c,ptost->i,ptost->f);
}
