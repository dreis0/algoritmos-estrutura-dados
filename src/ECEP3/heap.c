#include <stdio.h>
#include <stdlib.h>
#define INT_MAX 2147483647

struct min_heap
{
    int *itens, tamanho, tamanhoMaximo;
};

struct min_heap *cria(int n);
void corrige_heap_descendo(struct min_heap *, int);
void insere(struct min_heap *, int);
void exclui(struct min_heap *, int);
void mostra_minimo(int *, int);
void mostra(struct min_heap *);

int main()
{
    int numeroDeOperacoes, operacao, valor;
    struct min_heap *heap;

    scanf("%d\n", &numeroDeOperacoes);
    heap = cria(numeroDeOperacoes);

    while (numeroDeOperacoes--)
    {
        scanf("%d", &operacao);

        if (operacao == 1)
        {
            scanf("%d", &valor);
            insere(heap, valor);
        }
        else if (operacao == 2)
        {
            scanf("%d", &valor);
            exclui(heap, valor);
        }
        else
        {
            mostra_minimo(heap->itens, heap->tamanho);
        }
    }

    return 0;
}

struct min_heap *cria(int n)
{
    struct min_heap *heap = (struct min_heap *)malloc(sizeof(struct min_heap));
    heap->itens = (int *)malloc(n * sizeof(int));
    heap->tamanho = 0;
    heap->tamanhoMaximo = n;

    return heap;
}

void corrige_heap_descendo(struct min_heap *heap, int x)
{
    int maior = x, esquerda = 2 * x + 1, direita = 2 * x + 2, n = heap->tamanho;

    if (esquerda < n && heap->itens[esquerda] <= heap->itens[maior])
    {
        maior = esquerda;
    }
    if (direita < n && heap->itens[direita] <= heap->itens[maior])
    {
        maior = direita;
    }

    if (maior != x)
    {
        int aux = heap->itens[x];
        heap->itens[x] = heap->itens[maior];
        heap->itens[maior] = aux;

        corrige_heap_descendo(heap, maior);
    }
}

void insere(struct min_heap *heap, int novoValor)
{
    heap->itens[heap->tamanho] = novoValor;
    heap->tamanho++;

    for (int i = (heap->tamanho / 2) - 1; i >= 0; i--)
    {
        corrige_heap_descendo(heap, i);
    }
}

void exclui(struct min_heap *heap, int valor)
{
    int removido = 0;
    for (int i = 0; i < heap->tamanho && !removido; i++)
    {
        if (heap->itens[i] == valor)
        {
            heap->itens[i] = INT_MAX;
            removido = 1;
        }
    }

    for (int i = (heap->tamanho / 2) - 1; i >= 0; i--)
    {
        corrige_heap_descendo(heap, i);
    }
    heap->tamanho--;
}

void mostra_minimo(int *vetor, int n)
{
    printf("%d\n", vetor[0]);
}

void mostra(struct min_heap *heap)
{
    for (int i = 0; i < heap->tamanho; i++)
    {
        printf("%d%c", heap->itens[i], i == heap->tamanho - 1 ? '\n' : ' ');
    }
}