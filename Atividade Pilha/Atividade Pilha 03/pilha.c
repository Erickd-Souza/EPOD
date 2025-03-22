#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

No* empilhar(No *pilha, char c){
    No *novo = malloc(sizeof(No));
    
    if(novo){
        novo->valor = c;
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
        printf("%c\n", pilha->valor);
        pilha = pilha->proximo;
    }
    printf("\n");
}

