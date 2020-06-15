#include <stdio.h>
#include <stdlib.h>

struct node
{
    int valor;
    struct node *esquerda, *direita;
};

struct node *cria_node(int);
void insere(struct node **, struct node *);
int conta_folhas(struct node *);
int max(struct node *n);

int main()
{
    struct node *raiz = NULL;
    int valor, tamanho;

    scanf("%d", &tamanho);

    while (tamanho--)
    {
        scanf("%d", &valor);
        insere(&raiz, cria_node(valor));
    }

    valor = max(raiz);

    printf("%d\n", valor);

    // if (raiz != NULL)
    //     printf("%d\n", altura(raiz));
    // else
    //     printf("0\n");

    return 0;
}

struct node *cria_node(int novoValor)
{
    struct node *novoNode = (struct node *)malloc(sizeof(struct node));
    novoNode->valor = novoValor;

    novoNode->direita = NULL;
    novoNode->esquerda = NULL;

    return novoNode;
}

void insere(struct node **n, struct node *novoNode)
{
    if (*n == NULL)
    {
        *n = novoNode;
    }
    else
    {
        if ((*n)->valor > novoNode->valor)
            insere(&(*n)->esquerda, novoNode);
        else if ((*n)->valor <= novoNode->valor)
            insere(&(*n)->direita, novoNode);
    }
}

int max(struct node *n)
{
    if (n == NULL)
        return 2147483647;

    int res = n->valor;
    int lres = max(n->esquerda);
    int rres = max(n->direita);

    if (lres < res)
        res = lres;
    if (rres < res)
        res = rres;
    return res;

    // if (n->direita == NULL)
    //     return n->valor;
    // else
    //     return max(n->direita);
}