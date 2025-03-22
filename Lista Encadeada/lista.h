#ifndef LISTA.H
#define LISTA.H

typedef struct no{
	int valor;
	struct no *proximo;
}No;

void inserir_ordenado(No **lista, int num);
No* remover(No **lista, int num);
No* buscar(No **lista, int num);
void imprimir(No *no);
void imprimirEndereco(No *no);//
#endif
