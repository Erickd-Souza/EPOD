#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

int main() {
    No *pilha = NULL;
    int opcao;
    char numero_onibus[6];

    do {
        printf("\n Escolha uma opcao:\n");
        printf(" 1 - Registrar chegada de onibus\n");
        printf(" 2 - Registrar saida de onibus\n");
        printf(" 3 - Exibir ordem de saida dos onibus\n");
        printf(" 4 - Sair\n");
        printf(" Opcao: ");
        
        if (scanf("%d", &opcao) != 1) {
            printf(" Entrada invalida. Por favor, tente novamente.\n");
            while (getchar() != '\n'); // Limpar o buffer de entrada
            continue;
        }

        switch (opcao) {
            case 1:
                printf(" Digite o numero do onibus (exemplo: AB123): ");
                if (scanf("%s", numero_onibus) != 1) {
                    printf(" Entrada invalida. Por favor, insira o numero do onibus corretamente.\n");
                    while (getchar() != '\n'); // Limpar o buffer de entrada
                    continue;
                }
                pilha = empilhar(pilha, numero_onibus);
                printf("\n Onibus %s chegou e foi registrado no terminal.\n", numero_onibus);
                break;

            case 2:
                if (pilha != NULL) {
                    printf(" Onibus %s saiu do terminal.\n", pilha->valor);
                    pilha = desempilhar(&pilha);
                } else {
                    printf(" Nenhum onibus para sair do terminal.\n");
                }
                break;

            case 3:
                imprimir(pilha);
                break;

            case 4:
                printf(" Saindo do programa...\n");
                break;

            default:
                printf(" Opcao invalida.\n");
                break;
        }
    } while (opcao != 4);

    return 0;
}


