#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilha.h"

No* empilhar(No *pilha, const char *numero_onibus) {
    No *novo = (No*) malloc(sizeof(No));
    
    if (novo) {
        strncpy(novo->valor, numero_onibus, 6);  
        novo->valor[5] = '\0';  
        novo->proximo = pilha;
        return novo;
    } else {
        printf("\nErro ao alocar memoria.\n");
    }
    return pilha;
}

No* desempilhar(No **pilha) {
    No *remover = NULL;
    if (*pilha) {
        remover = *pilha;
        *pilha = remover->proximo;
        free(remover);
		return *pilha; 
    } else {
        printf("\nA pilha est? vazia.\n");
		return NULL;
    }
    
}

void imprimir(No *pilha) {
    if (!pilha) {
        printf(" A pilha esta vazia.\n");
        return;
    }
    
    printf(" Ordem de saida dos onibus:\n");
    while (pilha) {
        printf(" %s\n", pilha->valor);
        pilha = pilha->proximo;
    }
    printf("\n");
}


