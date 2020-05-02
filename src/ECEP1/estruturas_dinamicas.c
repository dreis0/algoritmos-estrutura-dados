#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    int valor;
    struct node *proximo;
};

struct lista_encadeada
{
    struct node *primeiro;
};

struct item_fila
{
    int valor;
    struct item_fila *proximo;
};

struct fila_dinamica
{
    struct item_fila *primeiro;
};

struct item_pilha
{
    int valor;
    struct item_pilha *proximo;
};

struct pilha_dinamica
{
    struct item_pilha *base;
};

struct lista_encadeada *cria_lista_encadeada();
struct node *cria_node(int valor);
void insere_lista_encadeada(struct lista_encadeada *, int);
int exclui_lista_encadeada(struct lista_encadeada *, int);
int busca_lista_encadeada(struct lista_encadeada *, int);
void mostra_lista_encadeada(struct lista_encadeada *);

struct fila_dinamica *cria_fila_dinamica();
struct item_fila *cria_item_fila(int);
void enfileira_fila_dinamica(struct fila_dinamica *, int);
int desenfileira_fila_dinamica(struct fila_dinamica *);
void mostra_fila_dinamica(struct fila_dinamica *);

struct pilha_dinamica *cria_pilha_dinamica();
struct item_pilha *cria_item_pilha(int);
void empilha_pilha_dinamica(struct pilha_dinamica *, int);
int desempilha_pilha_dinamica(struct pilha_dinamica *);
void mostra_pilha_dinamica(struct pilha_dinamica *);

int main()
{
    int numeroDeEstruturas, indice = 0, valor;
    char **estruturas, *nomeDaEstrutura, operacao;
    struct lista_encadeada **listas;
    struct fila_dinamica **filas;
    struct pilha_dinamica **pilhas;

    scanf("%d", &numeroDeEstruturas);

    estruturas = (char **)malloc(sizeof(char *) * numeroDeEstruturas);
    listas = (struct lista_encadeada **)malloc(sizeof(struct lista_encadeada) * numeroDeEstruturas);
    filas = (struct fila_dinamica **)malloc(sizeof(struct fila_dinamica) * numeroDeEstruturas);
    pilhas = (struct pilha_dinamica **)malloc(sizeof(struct pilha_dinamica) * numeroDeEstruturas);

    while (numeroDeEstruturas--)
    {
        estruturas[indice] = (char *)malloc(sizeof(char *) * 10);
        scanf("%s", estruturas[indice]);

        if (strcmp(estruturas[indice], "LDE") == 0)
        {
            listas[indice] = cria_lista_encadeada();
        }
        else if (strcmp(estruturas[indice], "FILA") == 0)
        {
            filas[indice] = cria_fila_dinamica();
        }
        else if (strcmp(estruturas[indice], "PILHA") == 0)
        {
            pilhas[indice] = cria_pilha_dinamica();
        }

        indice++;
    }

    while (scanf("%d %c", &indice, &operacao) != EOF)
    {
        nomeDaEstrutura = estruturas[indice];

        if (strcmp(nomeDaEstrutura, "LDE") == 0)
        {
            if (operacao == 'I')
            {
                scanf(" %d", &valor);
                if (!busca_lista_encadeada(listas[indice], valor))
                    insere_lista_encadeada(listas[indice], valor);
            }
            else if (operacao == 'R')
            {
                scanf(" %d", &valor);
                int excluido = exclui_lista_encadeada(listas[indice], valor);
                if (excluido != -1)
                    printf("REMOVIDO: %d\n", excluido);
            }
            else if (operacao == 'M')
            {
                mostra_lista_encadeada(listas[indice]);
            }
        }
        else if (strcmp(nomeDaEstrutura, "FILA") == 0)
        {
            if (operacao == 'I')
            {
                scanf(" %d", &valor);
                enfileira_fila_dinamica(filas[indice], valor);
            }
            else if (operacao == 'R')
            {
                int desenfileirado = desenfileira_fila_dinamica(filas[indice]);
                if (desenfileirado != -1)
                    printf("REMOVIDO: %d\n", desenfileirado);
            }
            else if (operacao == 'M')
            {
                mostra_fila_dinamica(filas[indice]);
            }
        }
        else if (strcmp(nomeDaEstrutura, "PILHA") == 0)
        {
            if (operacao == 'I')
            {
                scanf(" %d", &valor);
                empilha_pilha_dinamica(pilhas[indice], valor);
            }
            else if (operacao == 'R')
            {
                int desempilhado = desempilha_pilha_dinamica(pilhas[indice]);
                if (desempilhado != -1)
                    printf("REMOVIDO: %d\n", desempilhado);
            }
            else if (operacao == 'M')
            {
                mostra_pilha_dinamica(pilhas[indice]);
            }
        }
    }

    return 0;
}

/******************************Lista Encadeada******************************/

struct lista_encadeada *cria_lista_encadeada()
{
    struct lista_encadeada *l = (struct lista_encadeada *)malloc(sizeof(struct lista_encadeada));
    if (l != NULL)
        l->primeiro = NULL;

    return l;
}

struct node *cria_node(int valor)
{
    struct node *n = (struct node *)malloc(sizeof(struct node));
    n->valor = valor;
    n->proximo = NULL;

    return n;
}

void insere_lista_encadeada(struct lista_encadeada *lista, int valor)
{
    struct node *anterior = NULL;
    struct node *nodeAtual = lista->primeiro;
    struct node *novoNode = cria_node(valor);

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

int exclui_lista_encadeada(struct lista_encadeada *lista, int valor)
{
    struct node *anterior = NULL;
    struct node *nodeAtual = lista->primeiro;
    int valorRemovido = -1;

    while (NULL != nodeAtual && nodeAtual->valor != valor)
    {
        anterior = nodeAtual;
        nodeAtual = nodeAtual->proximo;
    }

    if (NULL != nodeAtual)
    {
        valorRemovido = nodeAtual->valor;
        if (anterior == NULL)
            lista->primeiro = nodeAtual->proximo;
        else
            anterior->proximo = nodeAtual->proximo;

        free(nodeAtual);
    }

    return valorRemovido;
}

int busca_lista_encadeada(struct lista_encadeada *lista, int valorBuscado)
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

void mostra_lista_encadeada(struct lista_encadeada *lista)
{
    struct node *nodeAtual = lista->primeiro;

    while (nodeAtual != NULL)
    {
        printf("%d%c", nodeAtual->valor, nodeAtual->proximo == NULL ? '\n' : ' ');
        nodeAtual = nodeAtual->proximo;
    }
}

/**************************************************************************/

/******************************Fila Dinâmica*******************************/

struct fila_dinamica *cria_fila_dinamica()
{
    struct fila_dinamica *f = (struct fila_dinamica *)malloc(sizeof(struct fila_dinamica));
    f->primeiro = NULL;

    return f;
}

struct item_fila *cria_item_fila(int valor)
{
    struct item_fila *item = (struct item_fila *)malloc(sizeof(struct item_fila));
    item->proximo = NULL;
    item->valor = valor;

    return item;
}

void enfileira_fila_dinamica(struct fila_dinamica *fila, int novoValor)
{
    struct item_fila *anterior = NULL;
    struct item_fila *itemAtual = fila->primeiro;
    struct item_fila *novoItem = cria_item_fila(novoValor);

    while (itemAtual != NULL)
    {
        anterior = itemAtual;
        itemAtual = itemAtual->proximo;
    }

    if (anterior == NULL)
    {
        fila->primeiro = novoItem;
    }
    else
    {
        anterior->proximo = novoItem;
    }
}

int desenfileira_fila_dinamica(struct fila_dinamica *fila)
{
    int desenfileirado = -1;
    struct item_fila *auxItem = fila->primeiro;

    if (auxItem != NULL)
    {
        desenfileirado = auxItem->valor;
        auxItem = fila->primeiro;
        fila->primeiro = fila->primeiro->proximo;
        free(auxItem);
    }

    return desenfileirado;
}

void mostra_fila_dinamica(struct fila_dinamica *fila)
{
    if (fila->primeiro == NULL)
        return;

    struct item_fila *itemAtual = fila->primeiro;
    while (itemAtual != NULL)
    {
        printf("%d%c", itemAtual->valor, itemAtual->proximo == NULL ? '\n' : ' ');
        itemAtual = itemAtual->proximo;
    }
}

/**************************************************************************/

/******************************Pilha Dinâmica******************************/

struct pilha_dinamica *cria_pilha_dinamica()
{
    struct pilha_dinamica *p = (struct pilha_dinamica *)malloc(sizeof(struct pilha_dinamica));
    p->base = NULL;

    return p;
}

struct item_pilha *cria_item_pilha(int valor)
{
    struct item_pilha *item = (struct item_pilha *)malloc(sizeof(struct item_pilha));
    item->valor = valor;
    item->proximo = NULL;
}

void empilha_pilha_dinamica(struct pilha_dinamica *pilha, int novoValor)
{
    struct item_pilha *novoItem = cria_item_pilha(novoValor);
    if (pilha->base == NULL)
    {
        pilha->base = novoItem;
    }
    else
    {
        struct item_pilha *itemAtual = pilha->base;
        while (itemAtual->proximo != NULL)
        {
            itemAtual = itemAtual->proximo;
        }

        itemAtual->proximo = novoItem;
    }
}

int desempilha_pilha_dinamica(struct pilha_dinamica *pilha)
{
    struct item_pilha *anterior = NULL;
    struct item_pilha *itemAtual = pilha->base;
    int desempilhado = -1;

    if (itemAtual != NULL)
    {
        while (itemAtual->proximo != NULL)
        {
            anterior = itemAtual;
            itemAtual = itemAtual->proximo;
        }

        if (anterior != NULL)
        {
            desempilhado = itemAtual->valor;
            anterior->proximo = NULL;
            free(itemAtual);
        }
    }

    return desempilhado;
}

void mostra_pilha_dinamica(struct pilha_dinamica *pilha)
{
    struct item_pilha *itemAtual = pilha->base;

    while (itemAtual != NULL)
    {
        printf("%d%c", itemAtual->valor, itemAtual->proximo == NULL ? '\n' : ' ');
        itemAtual = itemAtual->proximo;
    }
}
