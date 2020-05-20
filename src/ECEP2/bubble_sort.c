#include <stdio.h>
#include <stdlib.h>

int bubble_sort(int *, int);
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

    printf("Trocas: %d\n", bubble_sort(vetor, tamanho));

    print_vetor(vetor, tamanho);
    return 0;
}

int bubble_sort(int *vetor, int tamanho)
{
    int numeroDeTrocas = 0;

    for (int i = 0; i < tamanho - 1; i++)
    {
        for (int j = 0; j < tamanho - 1 - i; j++)
        {
            if (vetor[j] > vetor[j + 1])
            {
                int aux = vetor[j + 1];
                vetor[j + 1] = vetor[j];
                vetor[j] = aux;

                numeroDeTrocas++;
                print_vetor(vetor, tamanho);
            }
        }
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
