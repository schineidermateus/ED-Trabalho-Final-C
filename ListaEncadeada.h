#ifndef LISTAENCADEADA_H
#define LISTAENCADEADA_H


typedef struct noLista NoLista;
void criarLista (NoLista** l);
int estaVazia (NoLista** l);
void liberarListaCliente(NoLista** l);
void inserirClienteOrdenado(NoLista** l, Cliente* c);
void imprimirListaCliente (NoLista **l);
void removerCliente(NoLista** l, char* nome);
void lerArqCliente (NoLista** l, FILE* arq, int* idCliente);
void gravarArqCliente (NoLista** l, FILE* arq);

#endif /* LISTAENCADEADA_H */

