#include <stdio.h>
#include <stdlib.h>

struct min_heap
{
    int *itens, tamanho;
};

struct min_heap *cria(int n);
void corrige_heap_descendo(struct min_heap *, int);
void mostra(int *, int);

int main()
{
    int tamanho;
    struct min_heap *heap;
    scanf("%d\n", &tamanho);

    do
    {
        heap = cria(tamanho);
        for (int i = 0; i < tamanho; i++)
        {
            scanf("%d", &heap->itens[i]);
        }

        for (int i = (heap->tamanho / 2) - 1; i >= 0; i--)
        {
            corrige_heap_descendo(heap, i);
        }
        mostra(heap->itens, heap->tamanho);

        scanf("%d", &tamanho);
    } while (tamanho);

    return 0;
}

struct min_heap *cria(int n)
{
    struct min_heap *heap = (struct min_heap *)malloc(sizeof(struct min_heap));
    heap->itens = (int *)malloc(n * sizeof(int));
    heap->tamanho = n;

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

void mostra(int *vetor, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d%c", vetor[i], i == n - 1 ? '\n' : ' ');
    }
}