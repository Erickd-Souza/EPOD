typedef struct no {
    char valor[6];
    struct no *proximo;
} No;

No* empilhar(No *pilha, const char *numero_onibus);
No* desempilhar(No **pilha);
void imprimir(No *pilha);

