#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fila.h"

void inicializarFila(Fila *fila) {
    fila->frente = fila->traseira = NULL;
}
//------------------------------------------------------------------------
void enfileirar(Fila *fila, char nome[], char destino[]) {
    No *novo = (No *)malloc(sizeof(No));
    if (!novo) {
        printf("Erro ao alocar memoria!\n");
        return;
    }
    strcpy(novo->dado.nome, nome);
    strcpy(novo->dado.destino, destino);
    novo->proximo = NULL;

    if (fila->traseira == NULL) {
        fila->frente = fila->traseira = novo;
    } else {
        fila->traseira->proximo = novo;
        fila->traseira = novo;
    }
}
//------------------------------------------------------------------------
void desenfileirar(Fila *fila) {
    if (fila->frente == NULL) {
        printf("Fila vazia!\n");
        return;
    }
    
    No *aux = fila->frente;
    fila->frente = fila->frente->proximo;
    
    if (fila->frente == NULL) {
        fila->traseira = NULL;
    }
    printf("\n Passageiro removido: %s -> %s", aux->dado.nome, aux->dado.destino);
    free(aux);
}
//-----------------------------------------------------------------------
void imprimirFila(Fila *fila) {
    No *atual = fila->frente;
    if (atual == NULL) {
        printf("Fila vazia!\n");
        return;
    }
    printf("\n+------------------------------------------------+");
    printf("\n| Passageiros na fila:");
    while (atual) {
        printf("\n| -> %s -> %s", atual->dado.nome, atual->dado.destino);
        atual = atual->proximo;
    }
    printf("\n+------------------------------------------------+");
}
//-----------------------------------------------------------------------
void liberarFila(Fila *fila) {
    while (fila->frente) {
        desenfileirar(fila);
    }
}
