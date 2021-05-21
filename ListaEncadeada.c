#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Cliente.h"



typedef struct noLista
{
    Cliente* info; 
    struct noLista* prox;
}NoLista;

void criarLista(NoLista** l)
{
    *l = NULL;
}

int estaVaziaC(NoLista** l)
{
    return (*l == NULL);
}

void liberarListaCliente(NoLista** l)
{
    NoLista* p, *temp;
    for(p = *l; p != NULL; p = temp)
    {
        temp = p->prox;
        liberarCliente(p->info);
        free (p);
    }
    *l = NULL;
}

void inserirClienteOrdenado(NoLista** l, Cliente* c)
{
 NoLista* p, *ant = NULL;

    for(p = *l; p != NULL && (strcmp(obterNome(p->info),obterNome(c))) < 0; p = p->prox)
    {    
       ant = p;
    }
    NoLista* novo = (NoLista*) malloc(sizeof(NoLista));
    novo->info = c;

    if(ant == NULL)
    {
       novo->prox = *l;
       *l = novo;
    }
    else
    {
       novo->prox = p;
       ant->prox = novo;
    }
}

void imprimirListaCliente(NoLista ** l)
{   
    if (!estaVaziaC(l))
    {
        NoLista *p;
        for (p = *l; p != NULL; p = p->prox)
        {    
          imprimirCliente(p->info);
        }    
    }
    else
    {
        printf ("Lista vazia.");
    }
}


void removerCliente(NoLista** l, char* nome)
{
 NoLista* p, *ant = NULL;

    for(p = *l; p != NULL && (strcmp(obterNome(p->info),nome)) != 0; p = p->prox)
    {    
       ant = p;
    }
 
    if(p == NULL)
    {
        printf ("Cliente não encontrado.\n");
    }
    else 
    {
        if (ant == NULL)
        {
            *l = p->prox;
        }    
        else
        {
            ant->prox = p->prox;
        }
        printf ("O cliente %s foi removido.\n", nome);
        liberarCliente(p->info);
        free (p);
    }
}

void lerArqCliente(NoLista** l, FILE* arq, int* idCliente)
{   
    int idClienteAuxi = 0;
    Cliente *auxi, *novo;
    auxi = criarCliente();
    
    while (fread(auxi, sizeCliente(), 1, arq))
    {
        novo = criarCliente();
        memcpy (novo, auxi, sizeCliente());
        idClienteAuxi = obterID(novo);
        
        if (idClienteAuxi > (*idCliente))
        {
            (*idCliente) = idClienteAuxi;
        }
        
        inserirClienteOrdenado(l, novo);
    }
    liberarCliente(auxi);
}

void gravarArqCliente(NoLista** l, FILE* arq)
{ 
    if (!estaVaziaC(l))
    {
        NoLista *p;
        for (p = *l; p != NULL; p = p->prox)
        {    
            fwrite (p->info, sizeCliente(), 1, arq);
        }    
    }
}