// Compilação via terminal
// gcc Nome -o NomeExecutável
#include <stdio.h>

int main(){

	int qtd, soma = 0;

	printf("Quantos números você quer somar? ");
	fflush(stdout);
	scanf("%d", &qtd);

	for(int i = 0; i < qtd; i++){
		soma = soma + i * 2 + 3;
	}

	printf("A soma é %d.\n", soma);

	return 0;
}
