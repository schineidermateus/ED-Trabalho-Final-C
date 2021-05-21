#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct cliente
{
    int id;
    char nome[70];
}Cliente;

int sizeCliente ()
{
    return (sizeof(Cliente));
}

int obterID(Cliente* c)
{
    return c->id;
}

char* obterNome(Cliente* c)
{
    return c->nome;
}

void editarID(Cliente* c, int id)
{
    c->id = id;
}

void editarNome(Cliente* c, char* nome)
{
    strcpy(c->nome, nome);
}


Cliente* criarCliente()
{
    Cliente* novo = (Cliente*)malloc(sizeof(Cliente));
    return novo;  
}

void editarCliente(Cliente* c, int id, char* nome)
{
    c->id = id;
    strcpy(c->nome, nome);
}

void imprimirCliente(Cliente* c)
{
    printf("%d: %s\n", c->id, c->nome);
}

void liberarCliente(Cliente* c)
{   
    free(c);
}

