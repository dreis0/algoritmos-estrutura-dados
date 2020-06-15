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
        return 0;

    int atual = n->valor;

    int esquerda = max(n->esquerda);
    int direita = max(n->direita);

    if (esquerda > atual)
        atual = esquerda;
    if (direita > atual)
        atual = direita;

    return atual;
}