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
void insereNoComeco(struct listaEncadeada *, int);
void insereNoFim(struct listaEncadeada *, int);
void exclui(struct listaEncadeada *, int);
int busca(struct listaEncadeada *, int);
void mostra(struct listaEncadeada *);
void printReverseList(struct listaEncadeada *);

int main()
{
    struct listaEncadeada *lista;
    int operacoes, tamanho, valor;
    scanf("%d", &operacoes);

    while (operacoes--)
    {
        scanf("%d", &tamanho);
        lista = criaLista();
        while (tamanho--)
        {
            if (tamanho)
                scanf("%d ", &valor);
            else
                scanf("%d", &valor);

            insereNoFim(lista, valor);
        }

        printReverseList(lista);
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

void insereNoComeco(struct listaEncadeada *lista, int valor)
{
    struct node *novoNode = criaNode(valor);
    novoNode->proximo = lista->primeiro;
    lista->primeiro = novoNode;
}

void insereNoFim(struct listaEncadeada *lista, int valor)
{
    struct node *novoNode = criaNode(valor);
    struct node *nodeAtual = lista->primeiro;

    if (NULL == nodeAtual)
    {
        lista->primeiro = novoNode;
        return;
    }

    while (NULL != nodeAtual->proximo)
    {
        nodeAtual = nodeAtual->proximo;
    }

    nodeAtual->proximo = novoNode;
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
        printf("%d\n", nodeAtual->valor);
        nodeAtual = nodeAtual->proximo;
    }
}

void printReverseList(struct listaEncadeada *lista)
{
    struct listaEncadeada *listaRevertida = criaLista();
    struct node *nodeAtual = lista->primeiro;

    while (nodeAtual != NULL)
    {
        insereNoComeco(listaRevertida, nodeAtual->valor);
        nodeAtual = nodeAtual->proximo;
    }

    mostra(listaRevertida);
}