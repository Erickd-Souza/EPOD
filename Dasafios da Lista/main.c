#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "pontos_coleta.h"

main(void) {
    setlocale(LC_ALL, "");
    char filtro[50];
    int opcao;
    do{
    	system("cls");
    	printf("\t\t+-------------------------------------------------+");
		printf("\n\t\t| MENU DE OPERAÇÃO                                |");
	    printf("\n\t\t| 0 - Sair                                        |");
		printf("\n\t\t| 1 - Plastico                                    |");
		printf("\n\t\t| 2 - Eletronicos                                 |");
		printf("\n\t\t| 3 - Vidro                                       |");
		printf("\n\t\t| Digite o tipo de material que deseja buscar:    |");
		printf("\n\t\t+-------------------------------------------------+ ");
		printf("\n\t\t  Selecione uma Opção: ");
		scanf("%d", &opcao);
		
		switch(opcao){
			case 0:
				printf("\n Programa finalizado");
				return 0;
			case 1:
				strcpy(filtro, "Plastico");
			break;
			case 2:
				strcpy(filtro, "Eletronicos");
			break;
			case 3:
				strcpy(filtro, "Vidro");
			break;
			default:
				printf(" Opção Inválida!!!");
				
		}
		
		
		No* lista =  abrirArquivo(filtro);
	    if(opcao == 1 || opcao == 2 || opcao == 3){
	    	imprimir_lista(lista);
		}
	    liberar_lista(lista);
	    fflush(stdin);
	    printf("\n\n Pressione o Enter para Continuar");
	    getchar();
    }while(opcao != 0);
}
