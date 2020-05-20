#include <stdio.h>
#include <stdlib.h>

void insertion_sort(int *, int);
int calcula_corte(int *, int, int);
void print_vetor(int *, int);

int main()
{
    int candidatos, vagas, *notas;
    unsigned int valor;

    scanf("%d %d\n", &candidatos, &vagas);
    notas = (int *)malloc(sizeof(int) * candidatos);

    for (int i = 0; i < candidatos; i++)
    {
        scanf("%d", &valor);
        notas[i] = valor;
    }

    insertion_sort(notas, candidatos);
    printf("%d\n", calcula_corte(notas, candidatos, vagas));

    return 0;
}

void insertion_sort(int *vetor, int tamanho)
{
    int i, j;
    int atual;

    for (i = 1; i < tamanho; i++)
    {
        atual = vetor[i];
        j = i - 1;

        while (j >= 0 && atual < vetor[j])
        {
            vetor[j + 1] = vetor[j];
            j--;
        }

        vetor[j + 1] = atual;
    }
}

int calcula_corte(int *notas, int qtdNotas, int vagas)
{
    int acc = 0;
    for (int i = qtdNotas - 1; i >= qtdNotas - vagas; i--)
    {
        acc += notas[i];
    }

    return acc / vagas;
}

void print_vetor(int *vetor, int tamanho)
{
    for (int i = 0; i < tamanho; i++)
    {
        printf("%.d%c", vetor[i], i == tamanho - 1 ? '\n' : ' ');
    }
}