#include <stdio.h>
#include <stdlib.h>

int selection_sort(int *, int);
void print_vetor(int *, int);

int main()
{
    int tamanho, valor, *vetor;

    scanf("%d\n", &tamanho);
    vetor = (int *)malloc(sizeof(int) * tamanho);

    for (int i = 0; i < tamanho; i++)
    {
        scanf("%d", &valor);
        vetor[i] = valor;
    }

    print_vetor(vetor, tamanho);
    int numeroDeTrocas = selection_sort(vetor, tamanho);
    print_vetor(vetor, tamanho);
    printf("%d\n", numeroDeTrocas);

    return 0;
}

int selection_sort(int *vetor, int tamanho)
{
    int numeroDeTrocas = 0, indiceMenorEncontrado;

    for (int i = 0; i < tamanho - 1; i++)
    {
        indiceMenorEncontrado = i;
        for (int j = i; j < tamanho; j++)
        {
            if (vetor[j] < vetor[indiceMenorEncontrado])
            {
                indiceMenorEncontrado = j;
                numeroDeTrocas++;
            }
        }

        int aux = vetor[i];
        vetor[i] = vetor[indiceMenorEncontrado];
        vetor[indiceMenorEncontrado] = aux;
        print_vetor(vetor, tamanho);
    }

    return numeroDeTrocas;
}

void print_vetor(int *vetor, int tamanho)
{
    for (int i = 0; i < tamanho; i++)
    {
        printf("%d%c", vetor[i], i == tamanho - 1 ? '\n' : ' ');
    }
}
