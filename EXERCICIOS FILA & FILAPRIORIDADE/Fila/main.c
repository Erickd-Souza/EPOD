#include <stdio.h>
#include "fila.h"

int main() {
    Fila fila;
    inicializarFila(&fila);

    enfileirar(&fila, "Ana", "Centro");
    enfileirar(&fila, "Carlos", "Bairro X");
    enfileirar(&fila, "Maria", "Bairro Y");

    imprimirFila(&fila);

    desenfileirar(&fila);
    imprimirFila(&fila);

    liberarFila(&fila);
    return 0;
}

