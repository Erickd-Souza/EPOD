#ifndef FILA_H
#define FILA_H

typedef struct{
	char nome[50];
	char destino[50];
}Passageiro;

typedef struct No{
	Passageiro dado;
	struct No *proximo;
}No; 

typedef struct {
	No *frente;
	No *traseira;
}Fila;

void inicializarFila(Fila *fila);
void enfileirar(Fila *fila, char nome[], char destino[]);
void desenfileirar(Fila *fila);
void imprimirFila(Fila *fila);
void liberarFila(Fila *fila);

#endif
