#include <stdio.h>
#include "fila_prioridade.h"

int main() {
	FilaPrioridade fila;
    inicializarFilaPrioridade(&fila);

    enfileirarPrioridade(&fila, "Queda de arvore", 2);
    enfileirarPrioridade(&fila, "Acidente grave", 1);
    enfileirarPrioridade(&fila, "Falha em semaforo", 3);

    imprimirFila(&fila);

    desenfileirar(&fila);
    imprimirFila(&fila);

    liberarFila(&fila);
    return 0;
}
