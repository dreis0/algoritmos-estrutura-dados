#include <stdio.h>
#include <stdlib.h>

void mostra(int *, int);
int partition(int *, int, int, int);
void quick_sort(int *, int, int, int);

int main()
{
    int tamanho, *vetor;

    scanf("%d\n", &tamanho);

    vetor = (int *)malloc(tamanho * sizeof(int));

    for (int i = 0; i < tamanho; i++)
    {
        scanf("%d", &vetor[i]);
    }

    mostra(vetor, tamanho);

    quick_sort(vetor, 0, tamanho - 1, tamanho);

    mostra(vetor, tamanho);
}

int partition(int *vetor, int esquerda, int direita, int tamanho)
{
    int pivot = vetor[direita], aux;
    int i = (esquerda - 1);

    for (int j = esquerda; j <= direita - 1; j++)
    {
        if (vetor[j] <= pivot)
        {
            i++;
            aux = vetor[i];
            vetor[i] = vetor[j];
            vetor[j] = aux;

            mostra(vetor, tamanho);
        }
    }

    aux = vetor[i + 1];
    vetor[i + 1] = vetor[direita];
    vetor[direita] = aux;

    mostra(vetor, tamanho);

    return (i + 1);
}

void quick_sort(int *vetor, int esquerda, int direita, int tamanho)
{
    if (esquerda < direita)
    {
        int pivot = partition(vetor, esquerda, direita, tamanho);

        quick_sort(vetor, esquerda, pivot - 1, tamanho);
        quick_sort(vetor, pivot + 1, direita, tamanho);
    }
}

void mostra(int vector[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d%c", vector[i], i < size - 1 ? ' ' : '\n');
    }
}