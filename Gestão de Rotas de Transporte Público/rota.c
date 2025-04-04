#include<stdlib.h>
#include <stdio.h>
#include <string.h>
#include "rota.h"

No* criarNo(int id, char *nomeLinha, char *tipo, char *regiao){
	No* novo = (No*)malloc(sizeof(No));
    if (!novo) return NULL;

    novo->id = id;
    strcpy(novo->nomeLinha, nomeLinha);
    strcpy(novo->tipoTransporte, tipo);
    strcpy(novo->regiaoAtentida, regiao);
    novo->anterior = NULL;
    novo->proximo = NULL;

    return novo;
}
//-----------------------------------------------------------------------------------------------
void inserirNaListaDupla(No **lista, int id, char *nomeLinha, char *tipo, char *regiao){
   No* novo = criarNo(id, nomeLinha, tipo, regiao);
    if (!*lista) {
        *lista = novo;
        return;
    }

    No* atual = *lista;
    while (atual->proximo != NULL)
        atual = atual->proximo;

    atual->proximo = novo;
    novo->anterior = atual;	
}
//---------------------------------------------------------------------------------------------------------
void carregarRotasDeArquivo(No **lista, char *filtro){
	FILE* arquivo = fopen("rotas_de_transportes.txt", "r");
    if (!arquivo) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }
    int id;
    char linha[256];
    char nomeLinha[100], tipo[50], regiao[50];
    while (fgets(linha, sizeof(linha), arquivo)) {
        linha[strcspn(linha, "\n")] = '\0'; 
        if (sscanf(linha, "%d;%99[^;];%49[^;];%49[^\n]", &id, nomeLinha, tipo, regiao) == 4) {
            if (strcmp(tipo, filtro) == 0 || strcmp(regiao, filtro) == 0) {
                inserirNaListaDupla(lista, id, nomeLinha, tipo, regiao);
            }
        }
    }
    
    fclose(arquivo);
}
//--------------------------------------------------------------------------------------------------------
void exibirListaEmOrdem(No *lista){
	if (!lista) {
        printf("\n Nenhuma rota encontrada em ordem.\n");
        return;
    }

    printf("\n\t Rotas em ordem:");
    No* atual = lista;
    printf("\n\t+--------+------------------------------+----------------+--------------------+\n");
    while (atual != NULL) {
        printf("\t| ID: %.2d | Linha: %-21s | Tipo: %-5s\t | Regiao: %-10s |\n",
               atual->id, atual->nomeLinha, atual->tipoTransporte, atual->regiaoAtentida);
        atual = atual->proximo;
    }
	printf("\t+--------+------------------------------+----------------+--------------------+\n");	
}
//-------------------------------------------------------------------------------------------------------
void exibirListaEmOrdemInversa(No *lista){
	if (!lista) {
        printf(" Nenhuma rota encontrada inversa.\n");
        return;
    }

    No* atual = lista;
    while (atual->proximo != NULL)
        atual = atual->proximo;

    printf("\n\t Rotas em ordem inversa:");
    printf("\n\t+--------+------------------------------+----------------+--------------------+\n");
    while (atual != NULL) {
        printf("\t| ID: %.2d | Linha: %-21s | Tipo: %-5s\t | Regiao: %-10s |\n",
               atual->id, atual->nomeLinha, atual->tipoTransporte, atual->regiaoAtentida);
        atual = atual->anterior;
    }
    printf("\t+--------+------------------------------+----------------+--------------------+\n");
}
//-------------------------------------------------------------------------------------------------------
void liberarLista(No *lista){
	No* atual = lista;
    while (atual != NULL) {
        No* temp = atual;
        atual = atual->proximo;
        free(temp);
    }
}




