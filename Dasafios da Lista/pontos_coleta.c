#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pontos_coleta.h"

//funções

//----------------------------------------------
No* abrirArquivo(char filtro[]){
	FILE *fp = fopen("pontos_de_descartes.txt", "r");
	if(!fp){
		printf("Erro ao abrir o arquivo");
	}
	
	No* lista = criarLista();
	char linha[256];
    int id;
    char tipo[50], endereco[100];
    while (fgets(linha, sizeof(linha), fp)) {
    //	printf("Lendo arquivo: %s\n", linha);
        if (sscanf(linha, "%d;%49[^;];%99[^\n]", &id, tipo, endereco) == 3) {
            if (strcmp(tipo, filtro) == 0) { 
                lista = inserirLista(lista, id, tipo, endereco);
            }
        }
    }

    fclose(fp);
    return lista;
}
//----------------------------------------------
No* criarLista(){
	return NULL;
}
//-----------------------------------------------
No* inserirLista(No* lista, int id, char tipo[], char endereco[]){
	No* novo = malloc(sizeof(No));
	if(novo){
		novo->id = id;
    	strcpy(novo->tipo, tipo);
    	strcpy(novo->endereco, endereco);
    	novo->proximo = lista; 
    return novo;		
	}else
		printf("\n Erro ao alocar Memoria!");
}
//-----------------------------------------------
void imprimir_lista(No* lista){
	if(lista == NULL){
		printf("\n Pontos de coleta não encontrado!");
		//return;
	}
	
	printf("\n Pontos de Coletas:");
	    printf("\n    --------------------------------------------------------------------------------------------------");
	while(lista != NULL){
	    printf("\n -> | ID [%02d] <-> Tipo: %s  <-> Endereço: %s",lista->id,lista->tipo, lista->endereco);
	    printf("\n    --------------------------------------------------------------------------------------------------");
		lista = lista->proximo;
	}	
}
//--------------------------------------------------
void liberar_lista(No* lista){
	No* aux;
	while(lista != NULL){
		aux = lista;
		lista = lista->proximo;
		free(aux);
	}
}






