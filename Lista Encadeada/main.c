#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int main(void) {
    int opcao, valor;
    No *lista = NULL, *busca, *remove;
	
	do{
		printf("\n 0 - Sair");
		printf("\n 1 - Inserir Ordenado");
		printf("\n 2 - Remover");
		printf("\n 3 - Buscar");
		printf("\n 4 - Imprimir");
		printf("\n 5 - Imprimir endereco de Memoria");
		printf("\n Digite uma Opcao: ");
		scanf("%d", &opcao);
	
		switch(opcao){
		    case 1:
		    	printf(" Valor: ");
				scanf("%d", &valor);
				inserir_ordenado(&lista, valor);
				break;
		    case 2:
		        printf("\n Qual o valor que deseja remover: ");
		        scanf("%d", &valor);
		        remove = remover(&lista, valor);
		        if(remove){
		        	printf("\n Elemento Removido: %d", remove->valor);
			       free(remove);
				}else
					printf("\n Elemento nao encontrado!!!");
				break;
		    case 3:
				printf("\n Buscando Valor");
				printf("\n Qual valor deseja encontrar: ");
				scanf("%d", &valor);
				busca = buscar(&lista, valor);
				break;
			case 4:
				imprimir(lista);
				break;
			case 5:
				imprimirEndereco(lista);
				break;
			default:
				if (opcao != 0)
					printf("Opcao invalida.\n");
		}
	} while (opcao != 0);	
}

