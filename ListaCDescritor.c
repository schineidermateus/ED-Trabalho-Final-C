#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Produto.h"

typedef struct nolistaD
{
    Produto* info;
    struct nolistaD* prox;
} NoListaD;

typedef struct descritor
{
    struct nolistaD* prim;
    int n;
    struct nolistaD* ult;
} Descritor;

Descritor* criarListaD()
{
    Descritor* novo = (Descritor*) malloc(sizeof(Descritor));
    novo->n = 0;
    novo->prim = novo->ult = NULL;
    
    return novo;
}

int estaVaziaD(Descritor* d)
{
    return (d->n == 0);
}

void liberarDescritor(Descritor* d)
{
    NoListaD* p, *temp;
    
    for(p = d->prim; p != NULL; p = temp)
    {
        temp = p->prox;
        liberarProduto(p->info);
        free(p);
    }
    free(d);
}             
               
void imprimeListaD(Descritor* d)
{
    if (!estaVaziaD(d))
    {
        NoListaD *p;
        for (p = d->prim; p != NULL; p = p->prox)
        {
            imprimirProduto(p->info);
        }
        printf("\n");
    }
    else
    {
        printf ("ID não encontrado.\n");
    }
}

void inserirProdutoD(Descritor* d, Produto* p)
{
    NoListaD* novo = (NoListaD*) malloc(sizeof(NoListaD));
    
    if (novo != NULL) 
    {
        novo->info = p;   
        novo->prox = NULL;
            if (!estaVaziaD(d))
            {
              d->ult->prox = novo;
            } 
            else
            {    
              d->prim = novo;
            }
        d->ult = novo;
        d->n++;
    }
    else
    {    
        printf ("Não foi possivel alocar espaço na memória.");
    }
}

NoListaD* buscarIDProduto(Descritor* d, int id)
{
    NoListaD* p;
    
    for(p = d->prim; p != NULL && obterIDProduto(p->info) <= id; p = p->prox)
    {
        if (obterIDProduto(p->info) == id)
        {
            break;
        }
    }
    return p;
}      

void editarDescricaoP(Descritor* d, int id, char* descricao)
{
    NoListaD* noBusca = buscarIDProduto(d, id);
     
    if (noBusca != NULL)
    {
        editarDescricaoProduto(noBusca->info, descricao);
    }
    else
    {
        printf ("ID inválido.\n");
    }        
            
}

void registrarVenda(Descritor* d, int id, int quantidadeVendida)
{
    NoListaD* noBusca = buscarIDProduto(d, id);
     
    if (noBusca != NULL)
    {
        editarQuantidadeProduto(noBusca->info, quantidadeVendida);
        printf ("Produto com o estoque atualizado:\n");
        imprimirProduto(noBusca->info);
    }
    else
    {
        printf ("ID inválido.\n");
    }        
            
}

void removerProduto(Descritor* d, int id)
{

    NoListaD* p, *ant = NULL, *noBusca = buscarIDProduto(d, id);

    if (noBusca == NULL)
    {
        printf ("Produto não encontrado.\n");
    }    
    else
    {    
        for (p = d->prim; obterIDProduto(p->info) != id; p = p->prox)
        {
            ant = p;
        }      
        if (ant == NULL)
        {

            d->prim = p->prox;

            if (d->prim == NULL)
            {
                d->ult = NULL;
            }
        }    
        else 
        {
            ant->prox = p->prox;

            if (p->prox == NULL)
            {
                d->ult = ant;
            }
        }
        printf ("Produto removido com sucesso.\n");  
        liberarProduto(p->info);
        free (p);
        d->n--;
    }
}   

void lerArqProduto (Descritor* d, FILE* arq, int* idProduto)
{   
    Produto *auxi, *novo;
    auxi = criarProduto();
    
    while (fread(auxi, sizeProduto(), 1, arq))
    {
        novo = criarProduto();
        memcpy (novo, auxi, sizeProduto());
        (*idProduto) = obterIDProduto(novo);
        inserirProdutoD(d, novo); 
    }
    liberarProduto(auxi);
}

void gravarArqProduto(Descritor* d, FILE* arq)
{ 
     if (!estaVaziaD(d))
    {
        NoListaD *p;
        for (p = d->prim; p != NULL; p = p->prox)
        {
            fwrite (p->info, sizeProduto(), 1, arq);
        }
    }
}