#include <stdio.h>
#include <stdlib.h>

void insertion_sort(int *, int);
void print_vetor(int *, int);
void print_vetor_parcial(int *, int, int);

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

    insertion_sort(vetor, tamanho);

    return 0;
}

void insertion_sort(int *vetor, int tamanho)
{
    int i, j, atual;

    for (i = 1; i < tamanho; i++)
    {
        printf("Sublista Ordenada: ");
        print_vetor(vetor, i);

        printf("Sublista Desordenada: ");
        print_vetor_parcial(vetor, i, tamanho);

        atual = vetor[i];
        j = i - 1;

        while (j >= 0 && atual < vetor[j])
        {
            vetor[j + 1] = vetor[j];
            j--;
        }

        vetor[j + 1] = atual;
    }

    printf("Sublista Ordenada: ");
    print_vetor(vetor, i);

    printf("Sublista Desordenada:");
    if (i != tamanho)
    {
        printf(" ");
        print_vetor_parcial(vetor, i, tamanho);
    }
    else
        printf("\n");
}

void print_vetor(int *vetor, int tamanho)
{
    for (int i = 0; i < tamanho; i++)
    {
        printf("%d%c", vetor[i], i == tamanho - 1 ? '\n' : ' ');
    }
}

void print_vetor_parcial(int *vetor, int inicio, int fim)
{
    for (int i = inicio; i < fim; i++)
    {
        printf("%d%c", vetor[i], i == fim - 1 ? '\n' : ' ');
    }
}
