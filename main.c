#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Cliente.h"
#include "Produto.h"
#include "ListaCDescritor.h"
#include "ListaEncadeada.h"

int imprimirMenu()
{
   int i=0;    
    printf ("----------------MENU------------------\n");
    printf ("1 - Cadastrar novo cliente\n");
    printf ("2 - Remover cliente\n");
    printf ("3 - Imprimir clientes\n");
    printf ("4 - Cadastrar novo produto\n");
    printf ("5 - Remover produto\n");
    printf ("6 - Imprimir produtos\n");
    printf ("7 - Editar descrição de produtos\n");
    printf ("8 - Registrar venda de produto\n");
    printf ("9 - Sair\n");
    printf ("---------------------------------------\n");
    printf ("Escolha uma opção: ");
    scanf ("%d", &i);
    setbuf(stdin,NULL);
   return i;
}


int main() {
    
int idCliente = 0, idProduto = 0, opcao = 0, quantidadeProduto = 0, idProdutoBusca = 0;
char nome[50], nomeProduto[50], descProduto[100];    
int idClienteNovo = 0;
    
    NoLista* lista;
    criarLista(&lista);    
    Cliente* c;
    Descritor* listaDes = criarListaD();
    Produto* prod;

    FILE* arqSaidaCliente;
    FILE* arqEntradaCliente;
    arqEntradaCliente = fopen ("Cliente.cl", "rb");
    
    
    if (arqEntradaCliente != NULL)
    {
        lerArqCliente(&lista, arqEntradaCliente, &idClienteNovo);
    }
    
    idCliente = idClienteNovo;
    FILE* arqSaidaProduto;
    FILE* arqEntradaProduto;
    arqEntradaProduto = fopen ("Produto.pr", "rb");
    
    if (arqEntradaProduto != NULL)
    {
        lerArqProduto(listaDes, arqEntradaProduto, &idProduto);
    }
    
    opcao = imprimirMenu();
    
    while (opcao > 0 && opcao < 9)
    {   
        switch (opcao)
        {
            case 1:
               
                idCliente++;
                printf("Informe o nome do cliente %d: ", idCliente);
                scanf("%49[^\n]", nome);
                setbuf(stdin,NULL);
                c = criarCliente();
                if (c != NULL)
                {
                    editarCliente(c, idCliente, nome);
                    inserirClienteOrdenado(&lista, c);
                }
                else
                {
                    printf ("Não foi possivel criar o cliente.");
                }
                break;
            case 2:
                printf("Informe o nome do cliente a ser reovido: ");
                scanf("%49[^\n]", nome);
                setbuf(stdin,NULL);
                removerCliente (&lista, nome);
                break;
            case 3:
                imprimirListaCliente (&lista);
                break;
            case 4:
                idProduto++;
                prod = criarProduto();
                printf("Informe o nome do produto %d: ", idProduto);
                scanf("%49[^\n]", nomeProduto);
                setbuf(stdin,NULL);
                printf("Informe a descrição do produto %d: ", idProduto);
                scanf("%99[^\n]", descProduto);
                setbuf(stdin,NULL);
                printf("Informe a quantidade do produto %d: ", idProduto);
                scanf("%d", &quantidadeProduto);
                setbuf(stdin,NULL);        
                editarProduto(prod, idProduto, quantidadeProduto, nomeProduto, descProduto);
                inserirProdutoD(listaDes, prod);
                break;
            case 5:
                printf("Informe o ID do produto a ser removido: ");
                scanf("%d", &idProdutoBusca);
                setbuf(stdin,NULL); 
                removerProduto(listaDes, idProdutoBusca);
                break; 
            case 6:
                imprimeListaD(listaDes);
                break; 
            case 7:
                printf("Informe o ID do produto a ser editado: ");
                scanf("%d", &idProdutoBusca);
                setbuf(stdin,NULL); 
                printf("Informe a nova descrição do produto: ");
                scanf("%99[^\n]", descProduto);
                setbuf(stdin,NULL); 
                editarDescricaoP(listaDes, idProdutoBusca, descProduto);
                break; 
            case 8:
                printf("Informe o ID do produto que foi vendido: ");
                scanf("%d", &idProdutoBusca);
                setbuf(stdin,NULL); 
                printf("Digite a quantidade vendida do produto: ");
                scanf("%d", &quantidadeProduto);
                setbuf(stdin,NULL); 
                registrarVenda(listaDes, idProdutoBusca, quantidadeProduto);
                break; 
        }
        opcao = imprimirMenu();
    }
    
    arqSaidaCliente = fopen ("Cliente.cl", "wb");
    gravarArqCliente (&lista, arqSaidaCliente);
    
    arqSaidaProduto = fopen ("Produto.pr", "wb");
    gravarArqProduto (listaDes, arqSaidaProduto);
    
    liberarListaCliente(&lista);
    liberarDescritor(listaDes);
    
    fclose (arqEntradaCliente);
    fclose (arqEntradaProduto);
    fclose (arqSaidaCliente);
    fclose (arqSaidaProduto);
    return 0;
}