#include <stdio.h>
#include <stdlib.h>

void insertion_sort_outra_ordenacao(int *, int);
void print_vetor(int *, int);
void print_vetor_parcial(int *, int, int);
int as_outra_ordenacao(int);
int as_outra_ordenacao_base(int);
int obtem_num_na_casa_decimal(int, int);

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

    insertion_sort_outra_ordenacao(vetor, tamanho);
    print_vetor(vetor, tamanho);

    return 0;
}

void insertion_sort_outra_ordenacao(int *vetor, int tamanho)
{
    int i, j, atual;

    for (i = 1; i < tamanho; i++)
    {
        atual = vetor[i];
        j = i - 1;

        while (j >= 0 && as_outra_ordenacao(atual) < as_outra_ordenacao(vetor[j]))
        {
            vetor[j + 1] = vetor[j];
            j--;
        }

        vetor[j + 1] = atual;
    }
}

int as_outra_ordenacao(int numero)
{
    int casaDecimal = 1, multiplicador = 1, resultado = 0, aux;

    while (numero * 10 > multiplicador)
    {
        aux = as_outra_ordenacao_base(obtem_num_na_casa_decimal(numero, casaDecimal));
        resultado += aux * multiplicador;

        casaDecimal++;
        multiplicador *= 10;
    }

    return resultado;
}

int as_outra_ordenacao_base(int n)
{
    int retorno = 0;
    switch (n)
    {
    case 0:
        retorno = 0;
        break;
    case 5:
        retorno = 1;
        break;
    case 6:
        retorno = 2;
        break;
    case 4:
        retorno = 3;
        break;
    case 8:
        retorno = 4;
        break;
    case 9:
        retorno = 5;
        break;
    case 7:
        retorno = 6;
        break;
    case 3:
        retorno = 7;
        break;
    case 1:
        retorno = 8;
        break;
    case 2:
        retorno = 9;
        break;
    }

    return retorno;
}

int obtem_num_na_casa_decimal(int numero, int casaDecimal)
{
    int modulo = 1, divisor = 1;

    for (int i = 0; i < casaDecimal; i++)
        modulo *= 10;

    for (int i = 1; i < casaDecimal; i++)
        divisor *= 10;

    return (numero % modulo) / divisor;
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
