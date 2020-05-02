#include <stdio.h>
#include <stdlib.h>

struct fila_circular_estatica
{
    int *itens;
    int tamanho, quantidade, indiceInicio, indiceFim;
};

struct fila_circular_estatica *cria_fila(int);
void enfileria(struct fila_circular_estatica *, int);
int desenfileira(struct fila_circular_estatica *);

int main()
{
    char operacao;
    int valor, tamanho, desenfileriado;

    scanf("%d", &tamanho);
    struct fila_circular_estatica *fila = cria_fila(tamanho);

    while (scanf("\n%c", &operacao) != EOF)
    {
        if (operacao == 'E')
        {
            scanf(" %d", &valor);
            enfileria(fila, valor);
        }
        else if (operacao == 'D')
        {
            desenfileriado = desenfileira(fila);
            if (desenfileriado != -1)
                printf("%d\n", desenfileriado);
        }
    }

    return 0;
}

struct fila_circular_estatica *cria_fila(int tamanho)
{
    struct fila_circular_estatica *f = (struct fila_circular_estatica *)malloc(sizeof(struct fila_circular_estatica));

    f->itens = (int *)malloc(sizeof(int) * tamanho);
    f->indiceInicio = 0;
    f->indiceFim = 0;
    f->tamanho = tamanho;

    return f;
}

void enfileria(struct fila_circular_estatica *fila, int novoValor)
{
    int novoFim = (fila->indiceFim + 1) % fila->tamanho;
    if (novoFim != fila->indiceInicio)
    {
        fila->itens[fila->indiceFim] = novoValor;
        fila->indiceFim = novoFim;
    }
}

int desenfileira(struct fila_circular_estatica *fila)
{

    int desenfileirado = -1;

    if (fila->indiceFim != fila->indiceInicio)
    {
        desenfileirado = fila->itens[fila->indiceInicio];
        fila->indiceInicio = (fila->indiceInicio + 1) % fila->tamanho;
    }

    return desenfileirado;
}