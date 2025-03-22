#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

No* empilhar(No *pilha, float n){
	No *novo = malloc(sizeof(No));
	
	if(novo){
		novo->valor = n;
		novo->proximo = pilha;
		return novo;
	}else{
		printf("\nerro ao alocar a memoria. \n");
	}
	return pilha;
}

No* desempilhar(No **pilha){
	No *remover = NULL;
	if(*pilha){
		remover = *pilha;
		*pilha = remover->proximo;
	}else{
		printf("\nA pilha esta vazia.\n");
	}
	return remover;
}

void imprimir(No *pilha){
	while(pilha){
		printf(" [%d]\n", pilha->valor);
		pilha = pilha->proximo;
	}
	printf("\n");
}

