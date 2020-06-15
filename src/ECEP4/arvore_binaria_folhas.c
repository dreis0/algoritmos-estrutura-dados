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

    valor = conta_folhas(raiz);

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
        if ((*n)->valor == novoNode->valor)
            return;
        if ((*n)->valor > novoNode->valor)
            insere(&(*n)->esquerda, novoNode);
        else
            insere(&(*n)->direita, novoNode);
    }
}

int conta_folhas(struct node *n)
{
    if (n == NULL)
        return 0;
    if (n->esquerda == NULL && n->direita == NULL)
        return 1;
    else
        return conta_folhas(n->esquerda) +
               conta_folhas(n->direita);
}