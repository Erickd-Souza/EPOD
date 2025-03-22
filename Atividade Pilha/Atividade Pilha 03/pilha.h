typedef struct no{
    char valor;
    struct no *proximo;
} No;

No* empilhar(No *pilha, char c);
No* desempilhar(No **pilha);
void imprimir(No *pilha);
