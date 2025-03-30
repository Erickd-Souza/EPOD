#ifndef PONTOS_COLETA_H
#define PONTOS_COLETA_H

typedef struct no{
	int id;
	char tipo[50];
	char endereco[200];
	struct no *proximo;
}No;

No* abrirArquivo(char filtro[]);
No* criarLista();
No* inserirLista(No* lista, int id, char tipo[], char endereco[]);
void imprimir_lista(No* lista);
void liberar_lista(No* lista);

#endif
