#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "veiculo.h"

void criar_lista(Lista *lista){
	lista->inicio = NULL;
	lista->fim = NULL;
	lista->tam = 0;
}
//----------------------------------------------------------------------------------
void inserir_inicio(Lista *lista, char *placa, char *dia, char *horario){
	No *novo = malloc(sizeof(No));
	if(novo){
		strcpy(novo->placa, placa);
		strcpy(novo->dia, dia);
		strcpy(novo->horario, horario);
		novo->proximo = lista->inicio;
		lista->inicio = novo;
		if(lista->fim == NULL)
			lista->fim = novo;
		lista->fim->proximo = lista->inicio;
		lista->tam++;
	}else{
		printf("Erro ao alocar memoria.");
	}
}
//----------------------------------------------------------------------------------
void imprimir(Lista *lista){
	No *no = lista->inicio;
	 if (lista->inicio == NULL) {
        printf("Nenhum veiculo encontrado.\n");
        return;
    }
	printf("\n O tamanho da Lista de Veiculo eh: %d\n", lista->tam);
	if(no){
		do {
        	printf(" | Placa: %-10s | Dia: %-13s | Horario: %-15s|\n", no->placa, no->dia, no->horario);
        	no = no->proximo;
    	} while (no != lista->inicio);
	}
	printf("\n\n");
}
//------------------------------------------------------------------------------------
// Função para carregar veículos a partir de um arquivo
void carregarVeiculos(Lista *lista,  char *criterio) {
    FILE* arquivo = fopen("rodizio_de_veiculos.txt", "r");
    if (!arquivo) {
        printf("Erro ao abrir o arquivo!\n");
        return;
    }
    
    char linha[100];
    while (fgets(linha, sizeof(linha), arquivo)) {
        char placa[10], dia[15], horario[30];
        sscanf(linha, "%7[^;];%14[^;];%29[^\n]", placa, dia, horario);
        
        if (strcmp(placa, criterio) == 0 || strcmp(dia, criterio) == 0) {
           inserir_inicio(lista, placa, dia, horario);
        }
    }
    
    fclose(arquivo);
}
//---------------------------------------------------------------------------------------
void liberarMemoria(Lista *lista) {
    if (lista->inicio == NULL) 
	   return;
    
    No *atual = lista->inicio;
    No *proximo;
    do {
        proximo = atual->proximo;
        free(atual);
        atual = proximo;
    } while (atual != lista->inicio);
    lista->inicio = NULL;
	lista->fim = NULL;
	lista->tam = 0;
}

