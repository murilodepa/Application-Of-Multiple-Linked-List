/* DESCRIÇÃO DO PROGRAMA: Código do programa de uma aplicação de lista ligada envolvendo compra,
   pagamentos e impressoes de uma loja qualquer, mostrando o salfo devedor do cliente.


            PONTIFÍCIA UNIVERSIDADE CATÓLICA DE CAMPINAS
            NOME DO ALUNO: MURILO DE PAULA ARAUJO
            RA: 17747775
            PROFESSORA: ANGELA DE MENDONÇA ENGELBRECHT
            CURSO: ENGENHARIA DE COMPUTAÇÃO     PERÍODO: 3º SEMESTRE
            DISCIPLINA CURRICULAR: ESTRUTURA E RECUPERAÇÃO DE DADOS A

                    TRABALHO PARA APLICAÇÃO DE LISTAS LIGADA - Lista Ligada
*/

//################################# BIBLIOTECAS #################################
#include <stdio.h>  // "Cabeçalho Padrão de (Entrada/Saída)"
#include <stdlib.h> // "Cabeçalho da Biblioteca de Propósito Geral Padrão"
#include <conio.h>  // "Usada para a função getch()
#include <string.h> // String para copiar uma frase em outra e comparaçôes de texto
//###############################################################################

//################ DECLARAÇÃO DAS STRUCTs UTILIZADAS NO PROJETO #################

//##################### Struct termo 2 para lista de produtos ###################
struct termo2
{
    char produto[100];
    float preco;
};

typedef struct termo2 elemento2;

struct no2
{
    elemento2 info;
    struct no2* link;
};

typedef struct no2 no2;
//###############################################################################

//##################### Struct termo 1 para lista de clientes ###################
struct termo1  // Declarando a variável termo do tipo struct
{
    char nome[100];
    char end[100];
    float saldo;
};

typedef struct termo1 elemento1;

struct no1
{
    elemento1 info;
    struct no1* linkClientes;
    struct no2* linkProximo;
    struct no2* linkUltimo;
};

typedef struct no1 no1;
//###############################################################################


//################## PROTÓTIPO DAS FUNÇÕES UTILIZADAS NA MAIN ###################

// MENU PARA ESCOLHER ENTRE: COMPRAS / PAGAMENTO / IMPRESSÇAO / SAIR
int Menu();

// MENU PARA ESCOLHER ENTRE: LISTA DE TODOS OS CLIENTES / CONSULTAR APENAS UM CLIENTE
int SubMenu();

// REALIZAR COMPRAS DE DETERMINADOS PRODUTOS
void Compras (no1 **);

// REALIZAR PAGAMENTO DO SEUS DIVIDENDOS
void Pagamento (no1 **);

// REALIZAR A IMPRESSAO DOS DADOS UM CLIENTE ESPECÍFICO
void Impressao(no1 *);
//###############################################################################

//#################################### MAIN #####################################
int main()
{
    no1 *ListaCliente;

    ListaCliente = NULL;

    while(1)
    {
        switch(Menu())
        {
        case 1:
            printf("\n\n OPCAO COMPRAS!\n\n\n");
            Compras (&ListaCliente);
            break;

        case 2:
            printf("\n\n OPCAO PAGAMENTO!\n\n\n");
            Pagamento(&ListaCliente);
            break;

        case 3:
            printf("%s", ListaCliente->info.nome);
            printf("\n\n OPCAO IMPRESSAO\n\n\n");
            Impressao(ListaCliente);
            break;

        case 4:
            printf("\n\n OPCAO SAIR!\n\n\n");
            return 0;
            break;

        default:
            printf("OPCAO INVALIDA");
            break;
        }
    }
    return 0;
}
//###############################################################################

//###############################################################################
int Menu()
{
    char Opcao;

    do
    {
        printf("\n\n  1. COMPRAS");
        printf("\n  2. PAGAMENTO");
        printf("\n  3. IMPRESSAO");
        printf("\n  4. SAIR");
        printf("\n     OPCAO: ");

        Opcao=getch();
        fflush(stdin);
        Opcao=(Opcao-48);
    }
    while(Opcao > 4 || Opcao < 1);

    return Opcao;
}
//###############################################################################

//###############################################################################
int SubMenu()
{
    char Opcao;

    do
    {
        printf("\n\n 1. LISTA DE TODOS OS CLIENTES");
        printf("\n 2. CONSULTAR APENAS UM CLIENTE");
        printf("\n OPCAO: ");

        Opcao=getch();
        fflush(stdin);
        Opcao=(Opcao-48);
    }
    while(Opcao > 2 || Opcao < 1);

    return Opcao;
}
//###############################################################################

//###############################################################################
void Compras (no1 **P1)
{
    no1 *P2, *novo_Clientes;
    no2 *novo_Produto, *r;
    int retorno, x;
    char Nome[100];

    retorno = 1;

    P2= NULL;

    P2 = *P1;

    fflush(stdin);
    printf(" DIGITE O NOME DO CLIENTE: ");
    gets(Nome);
    fflush(stdin);

    x=0;

    while(x==0 && P2!=NULL)
    {
        retorno = stricmp(Nome, P2->info.nome);

        if(retorno!=0)
        {
            P2=P2->linkClientes;
        }
        else
        {
            x=1;
        }
    }
    if(x!=1)
    {
        novo_Produto = (no2*) malloc(sizeof(no2));
        novo_Produto->link=NULL;

        novo_Clientes = (no1*) malloc(sizeof(no1));

        novo_Clientes->linkClientes=NULL;
        novo_Clientes->linkProximo=NULL;
        novo_Clientes->linkUltimo=NULL;

        fflush(stdin);
        printf(" DIGITE O NOME DO PRODUTO: ");
        gets(novo_Produto->info.produto);
        fflush(stdin);

        fflush(stdin);
        printf(" DIGITE O VALOR DO PRODUTO: ");
        scanf("%f", &(novo_Produto->info.preco));
        fflush(stdin);

        novo_Clientes->info.saldo = novo_Produto->info.preco;

        fflush(stdin);
        printf(" DIGITE O ENDERECO DO CLIENTE: ");
        gets(novo_Clientes->info.end);
        fflush(stdin);

        strcpy(novo_Clientes->info.nome, Nome);

        if(P2==*P1)
        {
            (*P1)=novo_Clientes;
            (*P1)->linkProximo=novo_Produto;
            (*P1)->linkUltimo=novo_Produto;
        }

        else
        {
            P2->linkClientes=novo_Clientes;
            r=P2->linkUltimo;
            r->link=novo_Produto;
            P2->linkUltimo=novo_Produto;
        }
    }
    else
    {
        novo_Produto = (no2*) malloc(sizeof(no2));
        novo_Produto->link=NULL;

        fflush(stdin);
        printf(" DIGITE O NOME DO PRODUTO: ");
        gets(novo_Produto->info.produto);
        fflush(stdin);

        fflush(stdin);
        printf(" DIGITE O VALOR DO PRODUTO: ");
        scanf("%f", &(novo_Produto->info.preco));

        P2->info.saldo=(P2->info.saldo+novo_Produto->info.preco);

        if(P2->linkProximo == NULL && P2->linkUltimo == NULL)
        {
            P2->linkProximo = novo_Produto;
            P2->linkUltimo = novo_Produto;
        }

        else
        {
            r=P2->linkUltimo;
            r->link=novo_Produto;
            P2->linkUltimo=novo_Produto;
        }
    }
}
//###############################################################################

//###############################################################################
void Pagamento (no1 **P1)
{
    no1 *P2;
    no2 *novo_Produtos, *r, *ant;
    char Nome_Cliente[100], Nome_Produto[100];
    int retorno, x=0;

    retorno = 1;

    P2= NULL;
    P2=*P1;

    printf(" DIGITE O NOME DO CLIENTE: ");
    gets(Nome_Cliente);
    fflush(stdin);

    printf(" DIGITE O NOME DO PRODUTO QUE DESEJA PAGAR: ");
    gets(Nome_Produto);
    fflush(stdin);
    x=0;

    while(P2!=NULL && x!=1)
    {
        retorno = stricmp(Nome_Cliente, P2->info.nome);
        if(retorno!=0)
        {
            P2=P2->linkClientes;
        }
        else
        {
            if(P2->linkProximo==NULL)
            {
                printf("\n ESTE CLIENTE NAO TEM NENHUM PRODUTO PENDENTE!");
                return;
            }
            else
            {
                r=P2->linkProximo;
                ant = NULL;
                x=0;

                while(x!=1)
                {
                    retorno = stricmp(Nome_Produto, r->info.produto);
                    if(retorno!=0 && r->link!=NULL)
                    {
                        ant=r;
                        r=r->link;
                    }
                    else
                    {
                        x=1;
                        P2->info.saldo=(P2->info.saldo - r->info.preco);
                        if(ant!= NULL)
                            ant->link = r->link;
                        free(r);

                        if(r->link == NULL)
                        {
                            if(ant==NULL)
                                P2->linkUltimo=ant;
                            else
                                P2->linkUltimo=ant->link;

                        }
                    }
                }
                if(x==0)
                {
                    printf(" O CLIENTE JA TINHA QUITADO A DIVIDA OU NAO ESTA CADASTRADO NO SISTEMA");
                    x=1;
                }
            }
        }
    }
}
//###############################################################################

//###############################################################################
void Impressao(no1* P1)
{
    int Retorno;
    no2 *r=NULL;
    char Nome[100];
    int x;
    Retorno = 1;

    switch(SubMenu())
    {
    case 1:
        while(P1!=NULL)
        {
            printf("\n\n NOME DO CLIENTE: %-40s", P1->info.nome);
            printf("\n ENDERECO DO CLIENTE: %-40s", P1->info.end);
            printf("\n SALDO DEVEDOR DO CLIENTE: %.2f", P1->info.saldo);
            printf("\n\n");

            P1=P1->linkClientes;
        }
        break;

    case 2:
        printf("\n DIGITE O NOME DO CLIENTE QUE DESEJA CONSULTAR: ");
        gets(Nome);

        x=0;

        while(P1!=NULL && x!=1)
        {
            Retorno = stricmp(Nome, P1->info.nome);

            if(Retorno != 0)
            {
                P1=P1->linkClientes;
            }
            else
            {
                x=1;
                r=P1->linkProximo;

                printf("\n\n NOME DO CLIENTE: %-40s", P1->info.nome);
                printf("\n ENDERECO DO CLIENTE: %-40s", P1->info.end);
                printf("\n SALDO DEVEDOR DO CLIENTE: %.2f", P1->info.saldo);
                printf("\n PRODUTOS PENDENTES DE PAGAMENTOS: ");

                while(r!=NULL)
                {
                    printf(" %s. ", r->info.produto);
                    r=r->link;
                }
                printf("\n\n");
            }
        }
        break;
    }
}
//###############################################################################
