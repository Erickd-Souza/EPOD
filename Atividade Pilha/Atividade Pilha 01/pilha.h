typedef struct no {
    int valor;
    struct no* proximo;
}No;

No* empilhar(No *pilha, int n);
No* desempilhar(No **pilha);
void imprimir(No *pilha);

