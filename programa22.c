#include <stdio.h>

int main(){

	int n;
	int* p;

	 printf("Informe um número: ");
	 fflush(stdout);
	 scanf("%d", &n);

	 p = &n;

	 printf("O número informado foi %d.\n", n);
	 printf("Endereço de memória: %p.\n", &n);
	 printf("Endereço do ponteiro: %p.\n", p);

	return 0;
}
