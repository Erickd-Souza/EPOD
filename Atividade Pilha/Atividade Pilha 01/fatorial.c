#include "fatorial.h"

int fatorial(int n) {
	int i;
    Pilha s;
    initStack(&s);
    
    for (i = n; i > 0; i--) {
        empilhar(&s, i);
    }
    
    int result = 1;
    while (!isEmpty(&s)) {
        result *= desempilhar(&s);
    }
    
    return result;
}
