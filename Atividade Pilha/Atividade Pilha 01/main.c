#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

int fatorial(int num){
	No *remover, *pilha = NULL;
	
	while(num>1){
		pilha = empilhar(pilha, num);
		num--;
	}

	imprimir(pilha);
	
	while(pilha){
		remover = desempilhar(&pilha);
		num = num * remover->valor;
		free(remover);		
	}
	
	return num;
}


int main() {
    int n;
    	printf("\n Digite Um Numero Inteiro: ");
    	scanf("%d",&n);
         
    if (n < 0) {
        printf(" Numero invalido!\n");
        return 1;
    }
    
    printf(" Fatorial de %d eh %d\n", n, fatorial(n));
    return 0;
}

