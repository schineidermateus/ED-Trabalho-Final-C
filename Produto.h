#ifndef PRODUTO_H
#define PRODUTO_H

typedef struct produto Produto;

Produto* criarProduto ();
void liberarProduto (Produto* p);
int obterIDProduto(Produto* p);
char* obterDescricaoProduto(Produto* p);
int obterQuantidadeProduto(Produto* p);
char* obterNomeProduto(Produto* p);
void editarQuantidadeProduto(Produto* p, int quantidade);
void editarDescricaoProduto(Produto* p, char* descricao);
void editarProduto(Produto* p, int id, int quantidade, char* nome, char* descricao);
void imprimirProduto(Produto* p);
int sizeProduto ();


#endif /* PRODUTO_H */

