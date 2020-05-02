#include <stdio.h>
#include <stdlib.h>

struct node
{
    int valor;
    struct node *anterior, *proximo;
};

struct lista_duplamente_encadeada
{
    struct node *primeiro, *ultimo;
};

struct lista_duplamente_encadeada *criaLista();
struct node *criaNode(int);
void insere(struct lista_duplamente_encadeada *, int);
void exclui(struct lista_duplamente_encadeada *, int);
int busca(struct lista_duplamente_encadeada *, int);
void mostra(struct lista_duplamente_encadeada *);
void mostraReverse(struct lista_duplamente_encadeada *);

int main()
{
    char operacao;
    int valor;
    struct lista_duplamente_encadeada *lista = criaLista();

    while (scanf("\n%c", &operacao) != EOF)
    {
        if ('I' == operacao)
        {
            scanf("%d", &valor);

            if (!busca(lista, valor))
                insere(lista, valor);
        }
        else if ('E' == operacao)
        {
            scanf("%d", &valor);
            exclui(lista, valor);
        }
        else if ('M' == operacao)
        {
            mostra(lista);
        }
        else if ('R' == operacao)
        {
            mostraReverse(lista);
        }
    }

    return 0;
}

struct lista_duplamente_encadeada *criaLista()
{
    struct lista_duplamente_encadeada *l = (struct lista_duplamente_encadeada *)malloc(sizeof(struct lista_duplamente_encadeada));
    l->primeiro = NULL;
    l->ultimo = NULL;

    return l;
}

struct node *criaNode(int valor)
{
    struct node *n = (struct node *)malloc(sizeof(struct node));
    n->proximo = NULL;
    n->anterior = NULL;
    n->valor = valor;

    return n;
}

void insere(struct lista_duplamente_encadeada *lista, int novoValor)
{
    struct node *novoNode = criaNode(novoValor);
    struct node *nodeAtual = lista->primeiro;
    struct node *nodeAnterior = NULL;
    // struct node *nodeAux;

    if (NULL == nodeAtual)
    {
        // printf("linha 84\n");
        lista->primeiro = novoNode;
        lista->ultimo = novoNode;
        return;
    }

    while (NULL != nodeAtual && novoNode->valor >= nodeAtual->valor)
    {
        nodeAnterior = nodeAtual;
        nodeAtual = nodeAtual->proximo;
    }

    if (nodeAnterior == NULL)
    {
        // printf("linha 98\n");
        lista->primeiro = novoNode;
        novoNode->proximo = nodeAtual;
        nodeAtual->anterior = novoNode;
    }
    else if (nodeAtual == NULL)
    {
        // printf("linha 105\n");
        nodeAnterior->proximo = novoNode;
        novoNode->anterior = nodeAnterior;
        lista->ultimo = novoNode;
    }
    else
    {
        // printf("linha 112\n");
        nodeAnterior->proximo = novoNode;
        novoNode->anterior = nodeAnterior;
        novoNode->proximo = nodeAtual;
        nodeAtual->anterior = novoNode;
    }
}

void exclui(struct lista_duplamente_encadeada *lista, int valor)
{
    if (NULL == lista->primeiro)
    {
        //printf("linha 124");
        return;
    }

    struct node *nodeAtual = lista->primeiro;

    while (NULL != nodeAtual && valor != nodeAtual->valor)
    {
        nodeAtual = nodeAtual->proximo;
    }

    /*
    * exclui primeiro item
    * exclui item no meio
    * exclui item no começo
    */

    if (NULL != nodeAtual)
    {
        if (NULL == nodeAtual->anterior) //exclui o primeiro
        {
            lista->primeiro = nodeAtual->proximo;
        }
        else
        {
            nodeAtual->anterior->proximo = nodeAtual->proximo;
        }

        if (NULL == nodeAtual->proximo) //exclui o último
        {
            lista->ultimo = nodeAtual->anterior;
        }
        else
        {
            nodeAtual->proximo->anterior = nodeAtual->anterior;
        }
    }

    free(nodeAtual);
}

int busca(struct lista_duplamente_encadeada *lista, int valorBuscado)
{
    if (NULL == lista->primeiro)
        return 0;

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

void mostra(struct lista_duplamente_encadeada *lista)
{
    if (NULL != lista->primeiro)
    {
        struct node *nodeAtual = lista->primeiro;

        while (NULL != nodeAtual)
        {
            printf("%d ", nodeAtual->valor);
            nodeAtual = nodeAtual->proximo;
        }
    }
    printf("\n");
}

void mostraReverse(struct lista_duplamente_encadeada *lista)
{
    if (NULL != lista->primeiro)
    {
        struct node *nodeAtual = lista->ultimo;

        while (NULL != nodeAtual)
        {
            printf("%d ", nodeAtual->valor);
            nodeAtual = nodeAtual->anterior;
        }
    }
    printf("\n");
}
