#include <stdio.h>

#define BOARD1

int main(){
	printf("Starting Program....\n");
	
	#ifdef BOARD1
		printf("Board1 is defined.\n");
		#undef BOARD1
	#else
		printf("Board1 is Undefined.\n");
	#endif
	
	#ifdef BOARD1
		printf("Board1 hasn't been Undefined.\n");
	#else
		printf("Board1 has been Undefined.\n");
	#endif
}
