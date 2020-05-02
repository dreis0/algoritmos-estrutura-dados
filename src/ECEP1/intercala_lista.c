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
struct listaEncadeada *mergeLists(struct listaEncadeada *, struct listaEncadeada *);

int main()
{
    struct listaEncadeada *lista1 = criaLista();
    struct listaEncadeada *lista2 = criaLista();
    struct node *nodeAtual;
    int numeroDeOperacoes, tamanho, valor;

    scanf("%d", &numeroDeOperacoes);

    while (numeroDeOperacoes--)
    {
        lista1 = criaLista();
        lista2 = criaLista();

        scanf("%d", &tamanho);

        while (tamanho--)
        {
            if (tamanho)
                scanf("%d ", &valor);
            else
                scanf("%d", &valor);

            insere(lista1, valor);
        }

        scanf("%d", &tamanho);

        while (tamanho--)
        {
            if (tamanho)
                scanf("%d ", &valor);
            else
                scanf("%d", &valor);

            insere(lista2, valor);
        }

        mostra(mergeLists(lista1, lista2));
    }

    return 0;
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
        anterior = nodeAtual;
        nodeAtual = nodeAtual->proximo;
    }

    if (anterior == NULL)
    {
        lista->primeiro = novoNode;
    }
    else
    {
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

struct listaEncadeada *mergeLists(struct listaEncadeada *lista1, struct listaEncadeada *lista2)
{
    struct listaEncadeada *lista = criaLista();
    struct node *nodeAtual = lista1->primeiro;

    while (nodeAtual != NULL)
    {
        insere(lista, nodeAtual->valor);
        nodeAtual = nodeAtual->proximo;
    }

    nodeAtual = lista2->primeiro;

    while (nodeAtual != NULL)
    {
        insere(lista, nodeAtual->valor);
        nodeAtual = nodeAtual->proximo;
    }

    return lista;
}