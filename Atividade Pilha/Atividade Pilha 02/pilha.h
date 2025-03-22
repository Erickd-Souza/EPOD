typedef struct no{
	float valor;
	struct no *proximo;
}No;

No* empilhar(No *pilha, float n);
No* desempilhar(No **pilha);
void imprimir(No *pilha);

