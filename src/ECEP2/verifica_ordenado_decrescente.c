#include <stdio.h>
#include <stdlib.h>

int esta_ordenado_crescente(int *, int);
int esta_ordenado_decrescente(int *, int);
void print_vetor(int *, int);

int main()
{
    int tamanho, valor, *vetor;

    while (scanf("%d", &tamanho) != EOF)
    {
        vetor = (int *)malloc(sizeof(int) * tamanho);
        for (int i = 0; i < tamanho; i++)
        {
            scanf("%d ", &valor);
            vetor[i] = valor;
        }

        if (esta_ordenado_decrescente(vetor, tamanho))
            printf("S\n");
        else
            printf("N\n");
    }

    return 0;
}

int esta_ordenado_crescente(int *vetor, int tamanho)
{
    int ordenado = 1;

    for (int i = 0; i < tamanho - 1; i++)
    {
        if (vetor[i] > vetor[i + 1])
            ordenado = 0;
    }

    return ordenado;
}

int esta_ordenado_decrescente(int *vetor, int tamanho)
{
    int ordenado = 1;

    for (int i = 0; i < tamanho - 1; i++)
    {
        if (vetor[i] < vetor[i + 1])
            ordenado = 0;
    }

    return ordenado;
}

void print_vetor(int *vetor, int tamanho)
{
    printf("Tamanho: %d\n", tamanho);
    for (int i = 0; i < tamanho; i++)
    {
        printf("%d%c", vetor[i], i == tamanho - 1 ? '\n' : ' ');
    }
}