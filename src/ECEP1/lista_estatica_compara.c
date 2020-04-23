#include <stdio.h>
#include <stdlib.h>

struct Lista
{
    int *itens;
    int quantidade, tamanho;
};

void criaLista(struct Lista *, int);
int busca(struct Lista, int);
void insere(struct Lista *, int);
void exclui(struct Lista *, int);
void mostra(struct Lista);
int listaEstaContidaEmLista(struct Lista *, struct Lista *);

int main(void)
{
    struct Lista l1, l2;
    int operacoesL1, operacoesL2, x;
    char op;

    scanf("%d %d", &operacoesL1, &operacoesL2);
    criaLista(&l1, operacoesL1);
    criaLista(&l2, operacoesL2);

    while (operacoesL1--)
    {
        scanf("\n%c %d", &op, &x);
        if (op == 'I')
        {
            if (!busca(l1, x))
            {
                insere(&l1, x);
            }
        }
        else if (op == 'E')
        {
            if (busca(l1, x))
            {
                exclui(&l1, x);
            }
        }
    }

    while (operacoesL2--)
    {
        scanf("\n%c %d", &op, &x);
        if (op == 'I')
        {
            if (!busca(l2, x))
            {
                insere(&l2, x);
            }
        }
        else if (op == 'E')
        {
            if (busca(l2, x))
            {
                exclui(&l2, x);
            }
        }
    }

    if (listaEstaContidaEmLista(&l1, &l2) != 0)
        printf("SIM\n");
    else
        printf("NAO\n");

    free(l1.itens);
    free(l2.itens);
    return 0;
}

void criaLista(struct Lista *l, int n)
{
    l->itens = (int *)malloc(n * sizeof(int));
    l->quantidade = 0;
    l->tamanho = n;
}

void insere(struct Lista *lista, int chave)
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

void exclui(struct Lista *lista, int chave)
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

void mostra(struct Lista lista)
{
    int i;
    for (i = 0; i < lista.quantidade; i++)
    {
        printf("%d\n", lista.itens[i]);
    }
}

int listaEstaContidaEmLista(struct Lista *l1, struct Lista *l2)
{
    int valorEncontrado = 1, estaContido = 1;
    for (int i = 0; i < l1->quantidade; i++)
    {
        valorEncontrado = busca(*l2, l1->itens[i]);

        if (valorEncontrado == 0)
            estaContido = 0;
    }

    return estaContido;
}