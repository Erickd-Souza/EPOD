#ifndef NO
#define NO

typedef struct no{
    int id;
    char nomeLinha[100];
    char tipoTransporte[200];
    char regiaoAtentida[150];
	struct no *proximo;
	struct no *anterior;
}No;

No* criarNo(int id, char *nomeLinha, char *tipo, char *regiao);
void inserirNaListaDupla(No **lista, int id, char *nomeLinha, char *tipo, char *regiao);
void carregarRotasDeArquivo(No **lista, char *filtro);
void exibirListaEmOrdem(No* lista);
void exibirListaEmOrdemInversa(No* lista);
void liberarLista(No* lista);

#endif

