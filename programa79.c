#include <stdio.h>
#include <stdlib.h>

// Linked list

struct st_no{
	int valor;
	struct st_no *prox;
};

typedef struct st_no no;

int vazia(no *le){
	if(le -> prox == NULL){
		return 1;
	}else{
		return 0;
	}
}

void inicia(no *le){
	le -> prox = NULL;
}

void libera(no *le){
	if(!vazia(le)){
		no *proxNo, *atual;
		atual = le -> prox;
		while(atual != NULL){
			proxNo = atual -> prox;
			free(atual);
			atual = proxNo;
		}
	}
}

void exibe(no *le){
	if(vazia(le)){
		printf("A lista está vazia.\n");
		return;
	}
	no *tmp;
	tmp = le -> prox;

	while(tmp != NULL){
		printf("%d ", tmp -> valor);
		tmp = tmp -> prox;
	}
	printf("\n\n");
}

void insereInicio(no *le){
	no *novo = (no*)malloc(sizeof(no));
	if(!novo){
		printf("Sem memória disponível.\n");
		exit(1);
	}
	printf("Informe o valor:");
	fflush(stdout);
	scanf("%d", &novo -> valor);

	no *oldHead = le -> prox;

	le -> prox = novo;
	novo -> prox = oldHead;
}

void insereFim(no *le){
	no *novo = (no*)malloc(sizeof(no));
	if(!novo){
		printf("Sem memória disponível!\n");
		exit(1);
	}
	printf("Informe o valor: ");
	fflush(stdout);
	scanf("%d", &novo -> valor);
	novo -> prox = NULL;

	if(vazia(le)){
		le -> prox = novo;
	}else{
		no *tmp = le -> prox;

		while(tmp -> prox != NULL){
			tmp = tmp -> prox;
		}
		tmp -> prox = novo;
	}
}

void opcao(no *le, int op){
	switch(op){
		case 0:
			libera(le);
			break;
		case 1:
			exibe(le);
			break;
		case 2:
			insereInicio(le);
			break;
		case 3:
			insereFim(le);
			break;
		case 4:
			inicia(le);
			break;
		default:
			printf("Opção inválida!\n\n");
	}
}

int menu(){
	int opt;

	printf("Escolha a opção: \n");
	printf("[0] - Sair\n");
	printf("[1] - Exibir\n");
	printf("[2] - Adicionar nó no início\n");
	printf("[3] - Adicionar nó no fim\n");
	printf("[4] - Zerar lista\n");
	printf("Opção: ");
	fflush(stdout);
	scanf("%d", &opt);

	return opt;
}

int main(){
	no *le = (no*)malloc(sizeof(no));

	if(!le){
		printf("Sem memória disponível.\n");
		exit(1);
	}
	inicia(le);
	int opt;

	do{
		opt = menu();
		opcao(le, opt);
	}while(opt);
	free(le);

	return 0;
}
