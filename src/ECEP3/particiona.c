#include <stdlib.h>
#include <stdio.h>

int particiona(int *, int, int, int);
void mostra(int *, int);

int main()
{
    int tamanho, indice, i;
    scanf("%d\n", &tamanho);
    scanf("%d\n", &indice);

    int *vetor = (int *)malloc(tamanho * sizeof(int));

    for (i = 0; i < tamanho; i++)
    {
        scanf("%d", &vetor[i]);
    }

    int aux = vetor[indice];
    vetor[indice] = vetor[tamanho - 1];
    vetor[tamanho - 1] = aux;

    particiona(vetor, 0, tamanho - 1, vetor[indice]);
    mostra(vetor, tamanho);
}

int particiona(int *vetor, int esquerda, int direita, int pivo)
{
    int pivot = vetor[direita];
    int i = (esquerda - 1);
    int aux;

    for (int j = esquerda; j <= direita - 1; j++)
    {
        if (vetor[j] < pivot)
        {
            i++;
            aux = vetor[i];
            vetor[i] = vetor[j];
            vetor[j] = aux;
        }
    }

    aux = vetor[i + 1];
    vetor[i + 1] = vetor[direita];
    vetor[direita] = aux;

    return (i + 1);
}

void mostra(int *vector, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d\n", vector[i]);
    }
}