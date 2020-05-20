#include <stdio.h>
#include <stdlib.h>

void merge_sort(int *, int, int);
void merge(int *, int, int, int);
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

    merge_sort(notas, 0, candidatos - 1);
    printf("%d\n", calcula_corte(notas, candidatos, vagas));

    return 0;
}

void merge(int *arr, int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void merge_sort(int *arr, int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;

        merge_sort(arr, l, m);
        merge_sort(arr, m + 1, r);

        merge(arr, l, m, r);
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
        printf("%d%c", vetor[i], i == tamanho - 1 ? '\n' : ' ');
    }
}