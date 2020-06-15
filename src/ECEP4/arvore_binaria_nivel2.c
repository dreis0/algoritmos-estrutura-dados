#include <string.h>
#include <stdlib.h>
#include <stdio.h>

struct node
{
    int valor;
    struct node *esquerda, *direita;
};

struct node *cria_node(int);
void insere(struct node **, struct node *);
void mostra_niveis(struct node *, int);
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

    valor = altura(raiz);

    for (int i = 0; i <= valor; i++)
    {
        mostra_niveis(raiz, i);
    }

    return 0;
}

void mostra_niveis(struct node *node, int level)
{
    if (node == NULL)
        return;

    if (level == 0)
        printf("%d\n", node->valor);

    else
    {
        mostra_niveis(node->esquerda, level - 1);
        mostra_niveis(node->direita, level - 1);
    }
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
        *n = novoNode;
    else
    {
        if ((*n)->valor > novoNode->valor)
            insere(&(*n)->esquerda, novoNode);
        else if ((*n)->valor < novoNode->valor)
            insere(&(*n)->direita, novoNode);
    }
}

int altura(struct node *n)
{
    if (n == NULL || (n->direita == NULL && n->esquerda == NULL))
        return 0;

    int esquerda = altura(n->esquerda);
    int direita = altura(n->direita);

    if (esquerda > direita)
        return (esquerda + 1);
    else
        return (direita + 1);
}