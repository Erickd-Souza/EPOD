#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

void inserir_ordenado(No **lista, int num){
	No *aux, *novo = malloc(sizeof(No));
	
	if(novo){
		novo->valor = num;
	
	    if(*lista == NULL){
	    	novo->proximo = NULL;
	    	*lista = novo;
		}else if(novo->valor < (*lista)->valor){
			novo->proximo = *lista;
			*lista = novo;
			
		}else{
			aux = *lista;
			while(aux->proximo && novo->valor > aux->proximo->valor)
				aux = aux->proximo;
			novo->proximo = aux->proximo;
			aux->proximo = novo;
		}
	printf("\n Endereco do novo no: %p", novo);
    printf("\n Conteudo do novo no - Valor: %d, Proximo: %p\n", novo->valor, novo->proximo);	
	}else
		printf("Erro ao alocar memoria.\n");
}
//------------------------------------------------------------------------------
No* remover(No **lista, int num){
	No *aux, *remove = NULL;
	
	if(*lista){
		if((*lista)->valor == num){
			remove = *lista;
			*lista =  remove->proximo;
		}else{
			aux = *lista;
			while(aux->proximo && aux->proximo->valor != num)
				aux = aux->proximo;
			if(aux->proximo){
				remove = aux->proximo;
				aux->proximo = remove->proximo;
			}
		}
	}
	return remove;
}

//-----------------------------------------------------------
No* buscar(No **lista, int num){
	No *aux, *no = NULL;
	
	aux = *lista;
	while(aux && aux->valor != num)
		aux = aux->proximo;
	if(aux)
		no = aux;
	return no;
}
//-----------------------------------------------------------
void imprimir(No *no){
	printf("\n Lista: ");
	while(no){
		printf("[%d] ", no->valor);
		no = no->proximo;
	}
	printf("\n");
}
//-----------------------------------------------------------
void imprimirEndereco(No *no){
	printf("\n Lista enderecos: ");
	while(no){
		printf("\n [%d]-[%p] -> proximo [%p]",no->valor, &no->valor,no->proximo);
		no = no->proximo;
	}
	printf("\n");
}




