#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fila_prioridade.h"

void inicializarFilaPrioridade(FilaPrioridade *fila){
	fila->frente = NULL;
}
//---------------------------------------------------------------
void enfileirarPrioridade(FilaPrioridade *fila, char descricao[], int prioridade){
	No *novo = malloc(sizeof(No));
	if(!novo){
		printf("Erro ao alocar memoria!");
		return;
	}
	strcpy(novo->dado.descricao, descricao);
	novo->dado.prioridade = prioridade;
	novo->proximo = NULL;
	
	if (fila->frente == NULL || prioridade < fila->frente->dado.prioridade) {
        novo->proximo = fila->frente;
        fila->frente = novo;
    } else {
        No *atual = fila->frente;
        while (atual->proximo && atual->proximo->dado.prioridade <= prioridade) {
            atual = atual->proximo;
        }
        novo->proximo = atual->proximo;
        atual->proximo = novo;
    }
    
}
//---------------------------------------------------------------
void desenfileirar(FilaPrioridade *fila) {
    if (fila->frente == NULL) {
        printf("Fila vazia!\n");
        return;
    }

    No *temp = fila->frente;
    fila->frente = fila->frente->proximo;

    printf("\n Chamado removido: %s (Prioridade %d)", temp->dado.descricao, temp->dado.prioridade);
    free(temp);
}
//-----------------------------------------------------------------
void imprimirFila(FilaPrioridade *fila) {
    No *atual = fila->frente;
    if (atual == NULL) {
        printf("Fila vazia!\n");
        return;
    }
    printf("\n+------------------------------------------------+");
    printf("\n| Chamados na fila:");
    while (atual) {
        printf("\n| -> %s (Prioridade %d)", atual->dado.descricao, atual->dado.prioridade);
        atual = atual->proximo;
    }
     printf("\n+------------------------------------------------+");
}
//----------------------------------------------------------------
void liberarFila(FilaPrioridade *fila) {
    while (fila->frente) {
        desenfileirar(fila);
    }
}


