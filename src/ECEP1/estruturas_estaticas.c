#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct lista_estatica
{
    int *itens;
    int tamanho, quantidade;
};

struct fila_estatica
{
    int *itens;
    int quantidade, tamanho;
};

struct pilha_estatica
{
    int *itens;
    int quantidade, tamanho;
};

struct fila_circular_estatica
{
    int *itens;
    int tamanho, quantidade, indiceInicio, indiceFim;
};

struct lista_estatica *cria_lista_estatica(int);
void insere_lista_estatica(struct lista_estatica *, int);
int exclui_lista_estatica(struct lista_estatica *, int);
int busca_lista_estatica(struct lista_estatica *, int);
void mostra_lista_estatica(struct lista_estatica *);

struct fila_estatica *cria_fila_estatica(int);
void enfileira_fila_estatica(struct fila_estatica *, int);
int desenfileira_fila_estatica(struct fila_estatica *);
void mostra_fila_estatica(struct fila_estatica *);

struct pilha_estatica *cria_pilha_estatica(int);
void empilha_pilha_estatica(struct pilha_estatica *, int);
int desempilha_pilha_estatica(struct pilha_estatica *);
void mostra_pilha_estatica(struct pilha_estatica *);

struct fila_circular_estatica *cria_fila_circular(int);
void enfileira_fila_circular(struct fila_circular_estatica *, int);
int desenfileira_fila_circular(struct fila_circular_estatica *);
void mostra_fila_circular(struct fila_circular_estatica *);

//NOMES: LES, FILA, PILHA ou CIRCULAR
int main()
{
    int numeroDeEstruturas, indice = 0, valor;
    char **estruturas, *nomeDaEstrutura, operacao;
    struct lista_estatica **listas;
    struct fila_estatica **filas;
    struct pilha_estatica **pilhas;
    struct fila_circular_estatica **filas_circulares;

    scanf("%d", &numeroDeEstruturas);

    estruturas = (char **)malloc(sizeof(char *) * numeroDeEstruturas);
    listas = (struct lista_estatica **)malloc(sizeof(struct lista_estatica) * numeroDeEstruturas);
    filas = (struct fila_estatica **)malloc(sizeof(struct fila_estatica) * numeroDeEstruturas);
    pilhas = (struct pilha_estatica **)malloc(sizeof(struct pilha_estatica) * numeroDeEstruturas);
    filas_circulares = (struct fila_circular_estatica **)malloc(sizeof(struct fila_circular_estatica) * numeroDeEstruturas);

    while (numeroDeEstruturas--)
    {
        estruturas[indice] = (char *)malloc(sizeof(char *) * 100000);
        scanf("%s %d", estruturas[indice], &valor);

        if (strcmp(estruturas[indice], "LES") == 0)
        {
            listas[indice] = cria_lista_estatica(valor);
        }
        else if (strcmp(estruturas[indice], "FILA") == 0)
        {
            filas[indice] = cria_fila_estatica(valor);
        }
        else if (strcmp(estruturas[indice], "PILHA") == 0)
        {
            pilhas[indice] = cria_pilha_estatica(valor);
        }
        else if (strcmp(estruturas[indice], "CIRCULAR") == 0)
        {
            filas_circulares[indice] = cria_fila_circular(valor);
        }

        indice++;
    }

    while (scanf("%d %c", &indice, &operacao) != EOF)
    {
        nomeDaEstrutura = estruturas[indice];
        if (strcmp(nomeDaEstrutura, "LES") == 0)
        {
            if (operacao == 'I')
            {
                scanf(" %d", &valor);
                if (!busca_lista_estatica(listas[indice], valor))
                    insere_lista_estatica(listas[indice], valor);
            }
            else if (operacao == 'R')
            {
                scanf(" %d", &valor);
                int excluido = exclui_lista_estatica(listas[indice], valor);
                if (excluido != -1)
                    printf("REMOVIDO: %d\n", excluido);
            }
            else if (operacao == 'M')
            {
                mostra_lista_estatica(listas[indice]);
            }
        }
        else if (strcmp(nomeDaEstrutura, "FILA") == 0)
        {
            if (operacao == 'I')
            {
                scanf(" %d", &valor);
                enfileira_fila_estatica(filas[indice], valor);
            }
            else if (operacao == 'R')
            {
                int desenfileirado = desenfileira_fila_estatica(filas[indice]);
                if (desenfileirado != -1)
                    printf("REMOVIDO: %d\n", desenfileirado);
            }
            else if (operacao == 'M')
            {
                mostra_fila_estatica(filas[indice]);
            }
        }
        else if (strcmp(nomeDaEstrutura, "PILHA") == 0)
        {
            if (operacao == 'I')
            {
                scanf(" %d", &valor);
                empilha_pilha_estatica(pilhas[indice], valor);
            }
            else if (operacao == 'R')
            {
                int desempilhado = desempilha_pilha_estatica(pilhas[indice]);
                if (desempilhado != -1)
                    printf("REMOVIDO: %d\n", desempilhado);
            }
            else if (operacao == 'M')
            {
                mostra_pilha_estatica(pilhas[indice]);
            }
        }
        else if (strcmp(nomeDaEstrutura, "CIRCULAR") == 0)
        {
            if (operacao == 'I')
            {
                scanf(" %d", &valor);
                enfileira_fila_circular(filas_circulares[indice], valor);
            }
            else if (operacao == 'R')
            {
                int desenfileirado = desenfileira_fila_circular(filas_circulares[indice]);
                if (desenfileirado != -1)
                    printf("REMOVIDO: %d\n", desenfileirado);
            }
            else if (operacao == 'M')
            {
                mostra_fila_circular(filas_circulares[indice]);
            }
        }
    }

    return 0;
}

/******************************Lista Estática******************************/

struct lista_estatica *cria_lista_estatica(int n)
{
    struct lista_estatica *lista = (struct lista_estatica *)malloc(sizeof(struct lista_estatica *));
    lista->itens = (int *)malloc(sizeof(int) * n);
    lista->quantidade = 0;
    lista->tamanho = n;
}

void insere_lista_estatica(struct lista_estatica *lista, int valor)
{
    int i = 0, posicaoEncontrada = 0;

    while (i < lista->quantidade && !posicaoEncontrada)
    {
        if (lista->itens[i] > valor)
            posicaoEncontrada = 1;
        else
            i++;
    }

    if (posicaoEncontrada)
    {
        for (int j = lista->quantidade; j > i; j--)
        {
            lista->itens[j] = lista->itens[j - 1];
        }
    }

    lista->itens[i] = valor;
    lista->quantidade++;
}

int exclui_lista_estatica(struct lista_estatica *lista, int valor)
{
    int i = 0, posicaoEncontrada = 0;

    while (i < lista->quantidade && !posicaoEncontrada)
    {
        if (lista->itens[i] == valor)
            posicaoEncontrada = 1;
        else
            i++;
    }

    if (posicaoEncontrada)
    {
        for (int j = i; j < lista->quantidade - 1; j++)
        {
            lista->itens[j] = lista->itens[j + 1];
        }

        lista->quantidade--;
        return valor;
    }
    else
        return -1;
}

int busca_lista_estatica(struct lista_estatica *lista, int valor)
{
    for (int i = 0; i < lista->quantidade; i++)
    {

        if (lista->itens[i] == valor)
        {
            return 1;
        }
    }

    return 0;
}

void mostra_lista_estatica(struct lista_estatica *lista)
{
    for (int i = 0; i < lista->quantidade && i < lista->tamanho; i++)
    {
        printf("%d%c", lista->itens[i], i == lista->quantidade - 1 || i == lista->tamanho - 1 ? '\n' : ' ');
    }
}

/**************************************************************************/

/******************************Fila Estática*******************************/

struct fila_estatica *cria_fila_estatica(int n)
{
    struct fila_estatica *f = (struct fila_estatica *)malloc(sizeof(struct fila_estatica));
    f->itens = (int *)malloc(sizeof(int) * n);
    f->tamanho = n;
    f->quantidade = 0;
}

void enfileira_fila_estatica(struct fila_estatica *fila, int valor)
{
    if (fila->quantidade >= fila->tamanho)
        return;

    fila->itens[fila->quantidade] = valor;
    fila->quantidade++;
}

int desenfileira_fila_estatica(struct fila_estatica *fila)
{
    if (fila->quantidade == 0)
        return -1;

    int desenfileirado = fila->itens[0];
    fila->quantidade--;

    for (int i = 0; i < fila->quantidade; i++)
    {
        fila->itens[i] = fila->itens[i + 1];
    }

    return desenfileirado;
}

void mostra_fila_estatica(struct fila_estatica *fila)
{
    for (int i = 0; i < fila->quantidade; i++)
    {
        printf("%d%c", fila->itens[i], i == fila->quantidade - 1 ? '\n' : ' ');
    }
}

/**************************************************************************/

/******************************Pilha Estática******************************/

struct pilha_estatica *cria_pilha_estatica(int n)
{
    struct pilha_estatica *p = (struct pilha_estatica *)malloc(sizeof(struct pilha_estatica));
    p->itens = (int *)malloc(sizeof(int) * n);
    p->tamanho = n;
    p->quantidade = 0;
}

void empilha_pilha_estatica(struct pilha_estatica *pilha, int valor)
{
    if (pilha->quantidade == pilha->tamanho)
        return;

    pilha->itens[pilha->quantidade] = valor;
    pilha->quantidade++;
}

int desempilha_pilha_estatica(struct pilha_estatica *pilha)
{
    if (pilha->quantidade == 0)
        return -1;

    pilha->quantidade--;
    int desempilhado = pilha->itens[pilha->quantidade];
}

void mostra_pilha_estatica(struct pilha_estatica *pilha)
{
    for (int i = 0; i < pilha->quantidade; i++)
    {
        printf("%d%c", pilha->itens[i], i == pilha->quantidade - 1 ? '\n' : ' ');
    }
}

/**************************************************************************/

/******************************Fila Circular*******************************/

struct fila_circular_estatica *cria_fila_circular(int tamanho)
{
    struct fila_circular_estatica *f = (struct fila_circular_estatica *)malloc(sizeof(struct fila_circular_estatica));

    f->itens = (int *)malloc(sizeof(int) * tamanho);
    f->indiceInicio = 0;
    f->indiceFim = 0;
    f->tamanho = tamanho;

    return f;
}

void enfileira_fila_circular(struct fila_circular_estatica *fila, int novoValor)
{
    int novoFim = (fila->indiceFim + 1) % fila->tamanho;
    if (novoFim != fila->indiceInicio)
    {
        fila->itens[fila->indiceFim] = novoValor;
        fila->indiceFim = novoFim;
    }
}

int desenfileira_fila_circular(struct fila_circular_estatica *fila)
{

    int desenfileirado = -1;

    if (fila->indiceFim != fila->indiceInicio)
    {
        desenfileirado = fila->itens[fila->indiceInicio];
        fila->indiceInicio = (fila->indiceInicio + 1) % fila->tamanho;
    }

    return desenfileirado;
}

void mostra_fila_circular(struct fila_circular_estatica *fila)
{
    int i = fila->indiceInicio;
    while (i != fila->indiceFim)
    {
        printf("%d", fila->itens[i]);

        i++;
        if (i == fila->tamanho)
            i = 0;

        printf("%c", i == fila->indiceFim ? '\n' : ' ');
    }
}

/**************************************************************************/