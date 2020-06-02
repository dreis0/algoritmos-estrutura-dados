#include <stdio.h>
#include <stdlib.h>

void troca(int *a, int *b);
void corrige_heap(int arr[], int n, int i);
void heap_sort(int arr[], int n);
void mostra(int arr[], int n);

int main()
{
    int *vetor;
    int tamanho;

    scanf("%d\n", &tamanho);
    vetor = (int *)malloc(tamanho * sizeof(int));

    for (int i = 0; i < tamanho; i++)
    {
        scanf("%d", &vetor[i]);
    }

    mostra(vetor, tamanho);
    heap_sort(vetor, tamanho);
    mostra(vetor, tamanho);
}

void corrige_heap(int *vetor, int n, int i)
{
    int maior = i;
    int esquerda = 2 * i + 1;
    int direita = 2 * i + 2;

    if (esquerda < n && vetor[esquerda] > vetor[maior])
        maior = esquerda;

    if (direita < n && vetor[direita] > vetor[maior])
        maior = direita;

    if (maior != i)
    {
        troca(&vetor[i], &vetor[maior]);
        corrige_heap(vetor, n, maior);
    }
}

void troca(int *a, int *b)
{
    int aux = *a;
    *a = *b;
    *b = aux;
}

void mostra(int *vetor, int tamanho)
{
    for (int i = 0; i < tamanho; ++i)
    {
        printf("%d%c", vetor[i], i < tamanho - 1 ? ' ' : '\n');
    }
}

void heap_sort(int *vetor, int tamanho)
{
    for (int i = tamanho / 2 - 1; i >= 0; i--)
    {
        corrige_heap(vetor, tamanho, i);
    }

    mostra(vetor, tamanho);

    for (int i = tamanho - 1; i >= 0; i--)
    {
        troca(&vetor[0], &vetor[i]);
        corrige_heap(vetor, i, 0);
        mostra(vetor, i);
    }
}
