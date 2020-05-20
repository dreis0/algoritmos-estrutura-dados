#include <stdio.h>
#include <stdlib.h>

int insertion_sort(int *, int);

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

    int numeroDeOperacoes = insertion_sort(vetor, tamanho);
    printf("%d\n", numeroDeOperacoes);

    return 0;
}

int insertion_sort(int *vetor, int tamanho)
{
    int i, j, atual, numeroDeOperacaoes = 0;

    for (i = 1; i < tamanho; i++)
    {
        atual = vetor[i];
        j = i - 1;

        while (j >= 0 && atual < vetor[j])
        {
            numeroDeOperacaoes++;
            vetor[j + 1] = vetor[j];
            j--;
        }

        vetor[j + 1] = atual;
    }

    return numeroDeOperacaoes;
}
