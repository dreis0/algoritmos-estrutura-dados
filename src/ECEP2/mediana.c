#include <stdio.h>
#include <stdlib.h>

void insertion_sort(float *, int);
float calcula_mediana(float *, int);

int main()
{
    int tamanho;
    float mediana, valor, *vetor;

    scanf("%d\n", &tamanho);
    vetor = (float *)malloc(sizeof(float) * tamanho);

    for (int i = 0; i < tamanho; i++)
    {
        scanf("%f", &valor);
        vetor[i] = valor;
    }

    insertion_sort(vetor, tamanho);
    mediana = calcula_mediana(vetor, tamanho);
    printf("%.2f\n", mediana);

    return 0;
}

void insertion_sort(float *vetor, int tamanho)
{
    int i, j;
    float atual;
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

float calcula_mediana(float *vetor, int tamanho)
{
    float mediana;
    if (tamanho % 2 == 1)
    {
        mediana = vetor[tamanho / 2];
    }
    else
    {
        mediana = (vetor[(tamanho / 2) - 1] + vetor[tamanho / 2]) / 2;
    }

    return mediana;
}
