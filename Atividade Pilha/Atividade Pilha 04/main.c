#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

float calcular_media(No *pilha) {
    float soma = 0;
    int contador = 0;
    No *temp = pilha;

    // Soma os valores da pilha e conta o n?mero de elementos
    while (temp) {
        soma += temp->valor;
        contador++;
        temp = temp->proximo;
    }

    if (contador > 0) {
        return soma / contador;  
    } else {
        return 0;  
    }
}


void exibir_media(No *pilha) {
    float media = calcular_media(pilha);

    if (media > 0) {
        printf("\n Media de consumo de agua: %.2f metros cubicos\n", media);
    } else {
        printf("\n Nenhuma medicao registrada para calcular a media.\n");
    }
}


void exibir_pilha(No *pilha) {
    if (pilha == NULL) {
        printf("\n A pilha esta vazia.\n");
    } else {
        printf("\n Conteudo da pilha de medicoes:\n");
        imprimir(pilha);
    }
}

int main() {
    No *pilha = NULL;
    int opcao;
    float valor;

    do {
        printf("\n Escolha uma opcao:\n");
        printf(" 1 - Registrar medicao de consumo de Agua\n");
        printf(" 2 - Calcular e exibir media de consumo\n");
        printf(" 3 - Imprimir medicoes armazenadas\n");
        printf(" 4 - Limpar Tela\n");
        printf(" 5 - Sair\n");
        printf(" Opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("\n Digite o valor da medicao de consumo de agua (em metros cubicos)\n Obs: utilize virgula para decimais: ");
                scanf("%f", &valor);
                pilha = empilhar(pilha, valor);
                break;

            case 2:
                exibir_media(pilha);  
                break;

            case 3:
                exibir_pilha(pilha);  
                break;
                
            case 4:
            	system("cls");
            	break;

            case 5:
                printf("\n Saindo do programa...\n");
                break;
    
            default:
                printf("Opcao invalida.\n");
                break;
        }
    } while (opcao != 5);

    return 0;
}


