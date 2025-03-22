#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "pilha.h"

// Função para verificar se o caractere é um operador
int eh_operador(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

// Função para aplicar a operação matemática
float operacao(float a, float b, char operador) {
    switch(operador) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
        default: return 0;
    }
}

// Função para resolver a expressão pós-fixa
float resolver_expressao(char x[]) {
    char *pt;
    float num;
    No *n1, *n2, *pilha = NULL;

    pt = strtok(x, " ");
    while (pt) {
        if (eh_operador(pt[0])) {
            // Se for um operador, desempilhar dois valores e aplicar a operação
            n1 = desempilhar(&pilha);
            n2 = desempilhar(&pilha);
            if (n1 && n2) {
                num = operacao(n2->valor, n1->valor, pt[0]);
                pilha = empilhar(pilha, num);
                free(n1);
                free(n2);
            } else {
                printf("\nErro na pilha: número insuficiente de operandos.\n");
                return 0;
            }
        } else {
            // Caso seja um número, empilhar
            num = atof(pt);  // Convertendo a string para float
            pilha = empilhar(pilha, num);
        }
        pt = strtok(NULL, " ");  // Avançar para o próximo token
    }

    // O resultado final está no topo da pilha
    if (pilha) {
        num = pilha->valor;
        No* topo = desempilhar(&pilha);
        free(topo);
    } else {
        printf("\nErro: pilha vazia ao tentar calcular o resultado.\n");
        return 0;
    }

    return num;
}

int main(void) {
    char exp[100],num1[100],num2[100],expr[100];
    
    
    printf(" Digite o primeiro numero: ");
    scanf("%s",num1);
    strcpy(exp,num1);
    strcat(exp, " ");
    
	printf(" Digite o segundo numero: ");
    scanf("%s",num2);
    strcat(exp,num2);
    strcat(exp, " ");
   
    printf(" Digite a expresso: ");
    scanf("%s",expr);
    strcat(exp,expr);
    
    scanf("%99[^\n]", exp);
    
    float resultado = resolver_expressao(exp);
    if (resultado) {
        printf("\n Resultado de '%s' eh: %.2f\n", exp, resultado);
    } else {
        printf("\n Erro ao calcular a expressão.\n");
    }
    
    return 0;
}
