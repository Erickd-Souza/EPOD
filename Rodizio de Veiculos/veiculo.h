#ifndef VEICULO_H
#define VEICULO_H

typedef struct no {
    char placa[10];
    char dia[15];
    char horario[30];
    struct no *proximo;
} No;

typedef struct{
	No *inicio;
	No *fim;
	int tam;
}Lista;

void criar_lista(Lista *lista);
void inserir_inicio(Lista *lista, char *placa, char *dia, char *horario);
void imprimir(Lista *lista);
void carregarVeiculos(Lista *lista, char *criterio);
void liberarMemoria(Lista *lista);

#endif 

