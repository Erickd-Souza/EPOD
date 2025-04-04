#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "rota.h"

int main(void) {
	int opcao, tipoTransporte, regiao;
	char escolha[100];
	No *lista = NULL;
	
	printf("\n [1] Qual o tipo de Transporte ");
	printf("\n [2] Qual Regiao Desejada");
	printf("\n Selecione uma Opcao:  ");
	scanf("%d", &opcao);
	
	if(opcao == 1){
		printf("\n Selecione qual Trasporte:");
		printf("\n [1] Onibus");
		printf("\n [2] Metro");
		printf("\n Selecione uma Opcao:  ");
		scanf("%d", &tipoTransporte);
		if(tipoTransporte == 1){
			strcpy(escolha, "Onibus");
		}else if(tipoTransporte == 2){
			strcpy(escolha, "Metro");
		}else{
			printf("\n Opcao invalida!!!");
		}
	}else if(opcao == 2){
		printf("\n [1] Centro");
		printf("\n [2] Zona Norte");
		printf("\n [3] Zona Oeste");
		printf("\n [4] Zona Sul");
		printf("\n Digite o Nome da Regiao:");
		scanf("%d", &regiao);
		
		if(regiao == 1){
			strcpy(escolha, "Centro");
		}else if(regiao == 2){
			strcpy(escolha, "Zona Norte");
		}else if(regiao == 3){
			strcpy(escolha, "Zona Oeste");
		}else if(regiao == 4){
			strcpy(escolha, "Zona Sul");
		}else{
			printf("\n Opcao invalida!!!");
		}
		escolha[strcspn(escolha, "\n")] = '\0';
	}else{
		printf(" Opcao invalida!!!");
	}
	carregarRotasDeArquivo(&lista, escolha);
	exibirListaEmOrdem(lista);
    exibirListaEmOrdemInversa(lista);
    liberarLista(lista);
	return 0;
}

