#include <stdlib.h>
#include <stdio.h>
#include <string.h>


typedef struct produto
{
    int id, quantidade;
    char nome[70];
    char descricao[140];
}Produto;

int sizeProduto ()
{
    return (sizeof(Produto));
}

int obterIDProduto(Produto* p)
{
    return p->id;
}

char* obterDescricaoProduto(Produto* p)
{
    return p->descricao;
}

int obterQuantidadeProduto(Produto* p)
{
    return p->quantidade;
}

char* obterNomeProduto(Produto* p)
{
    return p->nome;
}

void editarQuantidadeProduto(Produto* p, int quantidade)
{
    p->quantidade = p->quantidade - quantidade;
}

void editarDescricaoProduto(Produto* p, char* descricao)
{
    strcpy(p->descricao, descricao);
}

Produto* criarProduto ()
{
    Produto* novo = (Produto*)malloc(sizeof(Produto));
    return novo;
}

void editarProduto(Produto* p, int id, int quantidade, char* nome, char* descricao)
{
    p->id = id;
    p->quantidade = quantidade;
    strcpy(p->nome, nome);
    strcpy(p->descricao, descricao);
}

void imprimirProduto(Produto* p)
{
    printf("%d: %s - %s - Quantidade: %d\n", p->id, p->nome, p->descricao, p->quantidade);
}

void liberarProduto(Produto* p)
{
    free(p);
}