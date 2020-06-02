#include <stdio.h>
#include <stdlib.h>

int main()
{
    int tamanho, *vetor, valor, aux = 0;

    scanf("%d", &tamanho);
    vetor = (int *)malloc(tamanho * sizeof(int));

    for (int i = 0; i < tamanho; i++)
    {
        scanf("%d", &vetor[i]);
    }

    scanf("%d", &valor);

    for (int i = 0; i < tamanho; i++)
    {
        if (vetor[i] < valor)
            aux++;
    }

    printf("%d\n", aux);

    return 0;
}