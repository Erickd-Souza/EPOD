#ifndef FILA_PRIORIDADE_H
#define FILA_PRIORIDADE_H

typedef struct {
	char descricao[100];
	int prioridade;
}Chamado;

typedef struct No{
	Chamado dado;
	struct No *proximo;
}No;

typedef struct{
	No *frente;
}FilaPrioridade;

void inicializarFilaPrioridade(FilaPrioridade *fila);
void enfileirarPrioridade(FilaPrioridade *fila, char descricao[], int prioridade);
void desenfileirar(FilaPrioridade *fila);
void imprimirFila(FilaPrioridade *fila);
void liberarFila(FilaPrioridade *fila);
#endif
