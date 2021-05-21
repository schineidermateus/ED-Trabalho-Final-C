## Makefile ##

all: TrabalhoPratico

TrabalhoPratico: main.o ListaCDescritor.o Produto.o Cliente.o ListaEncadeada.o
	gcc main.o ListaCDescritor.o Produto.o Cliente.o ListaEncadeada.o -o TrabalhoPratico

ListaCDescritor.o: ListaCDescritor.c
	gcc -c -Wall ListaCDescritor.c

ListaEncadeada.o: ListaEncadeada.c
	gcc -c -Wall ListaEncadeada.c

Produto.o: Produto.c
	gcc -c -Wall Produto.c

Cliente.o: Cliente.c
	gcc -c -Wall Cliente.c

main.o: main.c
	gcc -c -Wall main.c