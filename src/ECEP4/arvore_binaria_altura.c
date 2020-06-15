#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    int valor;
    struct node *esquerda, *direita;
};

struct node *cria_node(int);
void insere(struct node **, struct node *);
int altura(struct node *);

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

    printf("%d\n", altura(raiz));

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

int altura(struct node *node)
{
    if (node == NULL)
        return 0;
    else if (node->direita == NULL && node->esquerda == NULL)
        return 0;
    else
    {
        int lDepth = altura(node->esquerda);
        int rDepth = altura(node->direita);

        if (lDepth > rDepth)
            return (lDepth + 1);
        else
            return (rDepth + 1);
    }
}
