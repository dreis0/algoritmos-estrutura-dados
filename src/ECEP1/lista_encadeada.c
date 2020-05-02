#include <stdio.h>
#include <stdlib.h>

struct node
{
    int valor;
    struct node *proximo;
};

struct listaEncadeada
{
    struct node *primeiro;
};

struct listaEncadeada *criaLista();
struct node *criaNode(int valor);
void insere(struct listaEncadeada *, int);
void exclui(struct listaEncadeada *, int);
int busca(struct listaEncadeada *, int);
void mostra(struct listaEncadeada *);

int main()
{
    struct listaEncadeada *lista;
    char operacao;
    int valor;

    lista = criaLista();

    while (scanf("\n%c", &operacao) != EOF)
    {
        if (operacao == 'I')
        {
            scanf("%d", &valor);

            if (!busca(lista, valor))
                insere(lista, valor);
        }
        if (operacao == 'R')
        {
            scanf("%d", &valor);
            exclui(lista, valor);
        }
        if (operacao == 'B')
        {
            scanf("%d", &valor);
            if (busca(lista, valor))
                printf("SIM\n");
            else
                printf("NAO\n");
        }
        if (operacao == 'L')
        {
            mostra(lista);
        }
    }
}

struct listaEncadeada *criaLista()
{
    struct listaEncadeada *l = (struct listaEncadeada *)malloc(sizeof(struct listaEncadeada));
    if (l != NULL)
        l->primeiro = NULL;

    return l;
}

struct node *criaNode(int valor)
{
    struct node *n = (struct node *)malloc(sizeof(struct node));
    n->valor = valor;
    n->proximo = NULL;

    return n;
}

void insere(struct listaEncadeada *lista, int valor)
{
    struct node *anterior = NULL;
    struct node *nodeAtual = lista->primeiro;
    struct node *novoNode = criaNode(valor);

    while (NULL != nodeAtual && novoNode->valor >= nodeAtual->valor)
    {
        //printf("entrou no while\n");
        anterior = nodeAtual;
        nodeAtual = nodeAtual->proximo;
    }

    if (anterior == NULL)
    {
        //printf("primeiro if\n");
        lista->primeiro = novoNode;
    }
    else
    {
        //printf("segundo if\n");
        anterior->proximo = novoNode;
    }
    novoNode->proximo = nodeAtual;
}

void exclui(struct listaEncadeada *lista, int valor)
{
    struct node *anterior = NULL;
    struct node *nodeAtual = lista->primeiro;

    while (NULL != nodeAtual && nodeAtual->valor != valor)
    {
        anterior = nodeAtual;
        nodeAtual = nodeAtual->proximo;
    }

    if (NULL != nodeAtual)
    {
        if (anterior == NULL)
            lista->primeiro = nodeAtual->proximo;
        else
            anterior->proximo = nodeAtual->proximo;
    }
}

int busca(struct listaEncadeada *lista, int valorBuscado)
{
    int encontrado = 0;
    struct node *nodeAtual = lista->primeiro;

    while (NULL != nodeAtual)
    {
        if (nodeAtual->valor == valorBuscado)
            encontrado = 1;

        nodeAtual = nodeAtual->proximo;
    }

    return encontrado;
}

void mostra(struct listaEncadeada *lista)
{
    struct node *nodeAtual = lista->primeiro;

    while (nodeAtual != NULL)
    {
        printf("%d%c", nodeAtual->valor, nodeAtual->proximo == NULL ? '\n' : ' ');
        nodeAtual = nodeAtual->proximo;
    }
}