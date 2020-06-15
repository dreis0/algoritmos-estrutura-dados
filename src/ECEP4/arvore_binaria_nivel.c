#include <string.h>
#include <stdlib.h>
#include <stdio.h>

struct node
{
    int value;
    struct node *left, *right;
};

struct node *cria_node(int);
void insere(struct node **, struct node *);
void mostra_por_nivel(struct node *, int);

int main()
{
    struct node *root = NULL;
    int value, tamanho, nivel;

    scanf("%d", &tamanho);

    while (tamanho--)
    {
        scanf("%d", &value);
        insere(&root, cria_node(value));
    }

    scanf("%d", &nivel);

    mostra_por_nivel(root, nivel);

    return 0;
}

struct node *cria_node(int novoValor)
{
    struct node *novoNode = (struct node *)malloc(sizeof(struct node));

    novoNode->value = novoValor;
    novoNode->right = NULL;
    novoNode->left = NULL;

    return novoNode;
}

void insere(struct node **n, struct node *novoNode)
{
    if (*n == NULL)
        *n = novoNode;
    else
    {
        if ((*n)->value > novoNode->value)
            insere(&(*n)->left, novoNode);
        else if ((*n)->value < novoNode->value)
            insere(&(*n)->right, novoNode);
    }
}

void mostra_por_nivel(struct node *node, int level)
{
    if (node != NULL)
    {
        if (level == 0)
            printf("%d\n", node->value);

        else
        {
            mostra_por_nivel(node->left, level - 1);
            mostra_por_nivel(node->right, level - 1);
        }
    }
}
