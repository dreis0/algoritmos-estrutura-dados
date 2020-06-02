#include <stdio.h>
#include <stdlib.h>

int *merge(int *, int, int *, int);
void mostra(int *, int);

int main()
{
    int q1 = 0, q2 = 0;
    int *vetor1, *vetor2;

    scanf("%d%d", &q1, &q2);

    vetor1 = (int *)malloc(q1 * sizeof(int));
    vetor2 = (int *)malloc(q2 * sizeof(int));

    for (int i = 0; i < q1; i++)
    {
        scanf("%d", &vetor1[i]);
    }

    for (int i = 0; i < q2; i++)
    {
        scanf("%d", &vetor2[i]);
    }

    int *resultado = merge(vetor1, q1, vetor2, q2);
    mostra(resultado, q1 + q2);

    return 0;
}

int *merge(int *vetor1, int n1, int *vetor2, int n2)
{
    int i, j, k;
    int *vetor = (int *)malloc((n1 + n2) * sizeof(int));

    i = 0;
    j = 0;
    k = 0;

    while (i < n1 && j < n2)
    {
        if (vetor1[i] <= vetor2[j])
        {
            vetor[k] = vetor1[i];
            i++;
        }
        else
        {
            vetor[k] = vetor2[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        vetor[k] = vetor1[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        vetor[k] = vetor2[j];
        j++;
        k++;
    }

    return vetor;
}

void mostra(int *v, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d\n", v[i]);
    }
}