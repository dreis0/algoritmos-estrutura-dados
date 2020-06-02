#include <stdio.h>
#include <stdlib.h>

void merge(int *, int, int, int);
void merge_sort(int *, int, int, int);
void mostra(int *, int);

int main()
{
    int n, *vetor;
    scanf("%d", &n);

    vetor = (int *)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &vetor[i]);
    }

    mostra(vetor, n);
    merge_sort(vetor, 0, n - 1, n);
    mostra(vetor, n);

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

void merge_sort(int *arr, int l, int r, int n)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;

        merge_sort(arr, l, m, n);
        merge_sort(arr, m + 1, r, n);

        mostra(arr, n);
        merge(arr, l, m, r);
    }
}

void mostra(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d%c", arr[i], i == n - 1 ? '\n' : ' ');
    }
}