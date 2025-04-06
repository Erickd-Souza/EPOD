#include <stdio.h>
#include <string.h>
#include "veiculo.h"

int main() {
	int opcao, filtroPorDia;
    Lista lista;
    char criterio[50], diaBusca[15];
    criar_lista(&lista);
    do{
    	system("cls");
	    printf(" Sistema de Rodizio de Veiculos\n");
	    printf(" Digite o criterio de busca (dia da semana ou final da placa): ");
	    printf("\n [0] Sair");
	    printf("\n [1] Dia da Semana");
	    printf("\n [2] Buscar Por Placa de Veiculo");
	    printf("\n Escolha uma Opcao: ");
	    scanf("%d", &opcao);
	    
	    switch(opcao){
	    	case 0:
	    		printf("\n Saindo do Programa...");
	    		return 0;
	    	case 1:
		    	printf("\n Dia da Semana escolhido como Criterio.");
		    	printf("\n [1] Segunda-feira");
		    	printf("\n [2] Terca-feira");
		    	printf("\n [3] Quarta-feira");
		    	printf("\n [4] Quinta-feira");
		    	printf("\n [5] Sexta-feira");
		    	printf("\n Escolha um dia da semana: ");
		    	scanf("%d", &filtroPorDia);
		    	if(filtroPorDia == 1){
		    		strcpy(diaBusca, "Segunda-feira");
		    		carregarVeiculos(&lista, diaBusca);
		    	}else if(filtroPorDia == 2){
		    		strcpy(diaBusca, "Terca-feira");
		    		carregarVeiculos(&lista, diaBusca);
				}else if(filtroPorDia == 3){
					strcpy(diaBusca, "Quarta-feira");
		    		carregarVeiculos(&lista, diaBusca);
				}else if(filtroPorDia == 4){
					strcpy(diaBusca, "Quinta-feira");
		    		carregarVeiculos(&lista, diaBusca);
				}else if(filtroPorDia == 5){
					strcpy(diaBusca, "Sexta-feira");
		    		carregarVeiculos(&lista, diaBusca);
				}
	    	break;		
	    	case 2:
		    	printf("\n Busca por Placa escolhido como Criterio.");
		    	printf("\n Digite a placa do carro:");
		    	fflush(stdin);
		    	fgets(criterio, sizeof(criterio), stdin);
		    	criterio[strcspn(criterio, "\n")] = '\0';
		    	carregarVeiculos(&lista, criterio);
			break;
			default:
				printf("Opcao invalida!!!");	
		}
	    printf("\n Veiculos encontrados:\n");
	    imprimir(&lista);
	    
	    liberarMemoria(&lista);
        printf(" Memoria liberada.\n");
	    fflush(stdin);
	    printf("\n\n Pressione o Enter para Continuar");
	    getchar();
   }while(opcao != 0);
}

