#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

int forma_par(char p, char q){
	switch(p){
		case ')':
			if(q == '('){
				return 1;
			}else return 0;
		break;
		case ']':
			if(q == '['){
				return 1;
			}else return 0;
		break;
		case '}':
			if(q == '{'){
				return 1;
			}else return 0;
		break;
		default:
			return 1;
		break;
	}
}

int identifica_formacao(char x[]){
	int i = 0;
	No *remover, *pilha=NULL;
	remover->valor = 'a';
	
	while(x[i]!='\0'){
		if (x[i] == '(' || x[i] == '[' || x[i] == '{') {
            pilha = empilhar(pilha, x[i]);
            imprimir(pilha);
        }else if(x[i] == ')' || x[i] == ']' || x[i] == '}'){
			remover = desempilhar(&pilha);
			
        	
        	if(remover==NULL || forma_par(x[i], remover->valor)==0){
        		printf("\n Expressao mal formada.\n");
        		return 1;
			}
			free(remover);
		}
		i++;
	}
	imprimir(pilha);
	if(pilha){
		printf("\n Expressao mal formada.\n");
		return 1;
	}else{
		printf("\n Expressao bem formada.\n");
		return 0;
	}
}

int main(void) {
    char exp[100];
    
    printf("\nDigite a expressao matematica: ");
    scanf("%99[^\n]", exp);
    
    printf("\n A expressao: %s\n", exp, identifica_formacao(exp));
    
    return 0;
}

