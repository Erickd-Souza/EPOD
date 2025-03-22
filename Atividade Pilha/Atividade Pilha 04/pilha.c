#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

No* empilhar(No *pilha, float num){
	No *novo = malloc(sizeof(No));
	
	if(novo){
		novo->valor = num;
		novo->proximo = pilha;
		return novo;
	}else{
        printf("\n erro ao alocar a memoria. \n");
    }
    return pilha;
}

No* desempilhar(No **pilha){
    No *remover = NULL;
    if(*pilha){
        remover = *pilha;
        *pilha = remover->proximo;
    }else{
        printf("\n A pilha esta vazia.\n");
    }
    return remover;
}

void imprimir(No *pilha){
	if (!pilha) {
        printf("A pilha esta vazia.\n");
        return;
    }
	
    while(pilha){
        printf(" %.2f\n", pilha->valor);
        pilha = pilha->proximo;
    }
    printf("\n");
}

