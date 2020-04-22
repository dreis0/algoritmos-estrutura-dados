#include <stdio.h>
#include <stdlib.h>

struct Lista
{
    int *itens;
    int quantidade, tamanho;
};

void criaLista(struct Lista *, int);
int busca(struct Lista, int);
void inserir(struct Lista *, int);
void excluir(struct Lista *, int);
void mostrar(struct Lista);

int main(void)
{
    struct Lista l;
    int chave, q;
    char op;

    scanf("%d", &q);
    criaLista(&l, q + 1);

    while (q--)
    {
        scanf("\n%c %d", &op, &chave);
        if (op == 'I')
        {
            if (!busca(l, chave))
            {
                inserir(&l, chave);
            }
        }
        else if (op == 'E')
        {
            if (busca(l, chave))
            {
                excluir(&l, chave);
            }
        }
    }
    mostrar(l);
    free(l.itens);
    return 0;
}

void criaLista(struct Lista *l, int n)
{
    l->itens = (int *)malloc(n * sizeof(int));
    l->quantidade = 0;
    l->tamanho = n;
}

void inserir(struct Lista *lista, int chave)
{
    int i = 0, achei = 0, j;

    while (i < lista->quantidade && !achei)
    {
        if (lista->itens[i] > chave)
        {
            achei = 1;
        }
        else
        {
            i++;
        }
    }
    if (achei)
    {
        for (j = lista->quantidade; j > i; j--)
        {
            lista->itens[j] = lista->itens[j - 1];
        }
    }
    lista->itens[i] = chave;
    lista->quantidade++;
}

void excluir(struct Lista *lista, int chave)
{
    int i = 0, achei = 0, j;

    while (i < lista->quantidade && !achei)
    {
        if (lista->itens[i] == chave)
        {
            achei = 1;
        }
        else
        {
            i++;
        }
    }
    if (achei)
    {
        for (j = i; j < lista->quantidade - 1; j++)
        {
            lista->itens[j] = lista->itens[j + 1];
        }
        lista->quantidade--;
    }
}

int busca(struct Lista lista, int chave)
{
    int esq = 0, dir = lista.quantidade - 1, meio;
    while (esq <= dir)
    {
        meio = (esq + dir) / 2;
        if (lista.itens[meio] == chave)
        {
            return 1;
        }
        else if (lista.itens[meio] > chave)
        {
            dir = meio - 1;
        }
        else
        {
            esq = meio + 1;
        }
    }
    return 0;
}

void mostrar(struct Lista lista)
{
    int i;
    for (i = 0; i < lista.quantidade; i++)
    {
        printf("%d\n", lista.itens[i]);
    }
}