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
int exclui_da_arvore(struct node **, int);
struct node *exclui_node(struct node **);
void mostra_pre_order(struct node *);
void mostra_in_order(struct node *);
void mostra_post_order(struct node *);

int main()
{
    struct node *raiz = NULL;
    char *op;
    int valor;

    op = (char *)malloc(sizeof(char) * 15);

    while (scanf("%s", op) != EOF)
    {
        if (strcmp("insert", op) == 0)
        {
            scanf("%d", &valor);
            insere(&raiz, cria_node(valor));
        }
        else if (strcmp("delete", op) == 0)
        {
            scanf("%d", &valor);
            if (exclui_da_arvore(&raiz, valor))
                printf("%d\n", valor);
        }
        else if (strcmp("pre-order", op) == 0)
        {
            mostra_pre_order(raiz);
            if (raiz != NULL)
                printf("\n");
        }

        else if (strcmp("in-order", op) == 0)
        {
            mostra_in_order(raiz);
            if (raiz != NULL)
                printf("\n");
        }

        else if (strcmp("post-order", op) == 0)
        {
            mostra_post_order(raiz);
            if (raiz != NULL)
                printf("\n");
        }
    }

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
        if ((*n)->valor <= novoNode->valor)
            insere(&(*n)->esquerda, novoNode);
        else
            insere(&(*n)->direita, novoNode);
    }
}

int exclui_da_arvore(struct node **n, int valor)
{
    if (*n == NULL)
        return 0;
    else
    {
        struct node *anterior = NULL;
        struct node *atual = *n;

        while (atual != NULL)
        {
            if (atual->valor == valor)
            {
                if (atual == *n)
                    *n = exclui_node(&atual);
                else if (anterior->esquerda == atual)
                    anterior->esquerda = exclui_node(&atual);
                else
                    anterior->direita = exclui_node(&atual);

                return 1;
            }

            anterior = atual;
            if (valor <= atual->valor)
                atual = atual->direita;
            else
                atual = atual->esquerda;
        }
    }

    return 0;
}

struct node *exclui_node(struct node **n)
{
    // printf("%d\n", (*n)->valor);
    struct node *n1, *n2;

    if ((*n)->esquerda == NULL)
    {
        n2 = (*n)->direita;
        free(*n);
    }
    else
    {
        n1 = *n;
        n2 = (*n)->esquerda;

        while (n2->direita != NULL)
        {
            n1 = n2;
            n2 = n2->direita;
        }

        if (n1 != *n)
        {
            n1->direita = n2->esquerda;
            n2->esquerda = (*n)->esquerda;
        }

        n2->direita = (*n)->direita;
        free(*n);
    }

    return n2;
}

void mostra_pre_order(struct node *n)
{
    if (n == NULL)
        return;

    printf("%d ", n->valor);

    if (n->direita != NULL)
        mostra_pre_order(n->direita);

    if (n->esquerda != NULL)
        mostra_pre_order(n->esquerda);
}

void mostra_in_order(struct node *n)
{
    if (n == NULL)
        return;

    if (n->direita != NULL)
        mostra_in_order(n->direita);

    printf("%d ", n->valor);

    if (n->esquerda != NULL)
        mostra_in_order(n->esquerda);
}

void mostra_post_order(struct node *n)
{
    if (n == NULL)
        return;

    if (n->direita != NULL)
        mostra_post_order(n->direita);
    if (n->esquerda != NULL)
        mostra_post_order(n->esquerda);

    printf("%d ", n->valor);
}