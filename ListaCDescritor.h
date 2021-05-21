#ifndef LISTACDESCRITOR_H
#define LISTACDESCRITOR_H


typedef struct nolistaD NoListaD;
typedef struct descritor Descritor;
Descritor* criarListaD();
int estaVaziaD(Descritor* d);
void liberarDescritor(Descritor* d);
void imprimeListaD(Descritor * d);
void inserirProdutoD(Descritor* d, Produto* p);
NoListaD* buscarIDProduto(Descritor* d, int id);
void registrarVenda(Descritor* d, int id, int quantidade);
void editarDescricaoP(Descritor* d, int id, char* descricao);
void removerProduto(Descritor* d, int id);
void lerArqProduto (Descritor* d, FILE* arq, int* idProduto);
void gravarArqProduto(Descritor* d, FILE* arq);

#endif /* LISTACDESCRITOR_H */

