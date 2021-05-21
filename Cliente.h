#ifndef CLIENTE_H
#define CLIENTE_H

typedef struct cliente Cliente;

int obterID(Cliente* c);
char* obterNome(Cliente* c);
void editarID(Cliente* c, int id);
void editarNome(Cliente* c, char* nome);
Cliente* criarCliente();
void liberarCliente(Cliente* c);
void editarCliente(Cliente* c, int id, char* nome);
void imprimirCliente(Cliente* c);
int sizeCliente ();

#endif /* CLIENTE_H */

