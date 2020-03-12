#include <stdio.h>
#include <stdlib.h>

struct ListaEstatica
{
  int *itens;
  int tamanho, quantidade;
};

void criaLista(struct ListaEstatica *lista, int size);
void destroiLista(struct ListaEstatica lista);
int buscaLinear(struct ListaEstatica *, int valor);
void adiciona(struct ListaEstatica *, int valor);
void exclui(struct ListaEstatica *, int valor);
void ordena(struct ListaEstatica *);
void imprime(struct ListaEstatica);

int main()
{
  struct ListaEstatica lista;
  int size, count = 0;
  int valor;
  char operacao;

  scanf("%d", &size);
  criaLista(&lista, size);

  while (count < size && scanf("\n%c %d", &operacao, &valor))
  {
    if (operacao == 'I')
    {
      if (buscaLinear(&lista, valor) == -1)
        adiciona(&lista, valor);
    }
    else if (operacao == 'E')
    {
      if (buscaLinear(&lista, valor) != -1)
        exclui(&lista, valor);
    }

    count++;
  }

  ordena(&lista);
  imprime(lista);

  return 0;
}

void criaLista(struct ListaEstatica *lista, int size)
{
  lista->itens = (int *)malloc(sizeof(int) * size);
  lista->tamanho = size;
  lista->quantidade = 0;
}

void destroiLista(struct ListaEstatica lista)
{
  free(lista.itens);
}

int buscaLinear(struct ListaEstatica *lista, int valor)
{
  for (int i = 0; i < lista->tamanho; i++)
  {
    if (lista->itens[i] == valor)
      return i;
  }

  return -1;
}

void adiciona(struct ListaEstatica *lista, int valor)
{
  for (int i = 0; i < lista->tamanho; i++)
  {
    if (lista->itens[i] == 0)
    {
      lista->itens[i] = valor;
      lista->quantidade++;
      break;
    }
  }
}

void exclui(struct ListaEstatica *lista, int valor)
{
  for (int i = 0; i < lista->tamanho; i++)
  {
    if (lista->itens[i] == valor)
    {
      lista->itens[i] = 0;
      lista->quantidade--;
    }
  }
}

void ordena(struct ListaEstatica *lista)
{
  for (int i = 0; i < lista->tamanho; i++)
  {
    for (int j = 0; j < lista->tamanho - 1; j++)
    {
      if (lista->itens[j] > lista->itens[j + 1])
      {
        int aux = lista->itens[j];
        lista->itens[j] = lista->itens[j + 1];
        lista->itens[j + 1] = aux;
      }
    }
  }
}

void imprime(struct ListaEstatica lista)
{
  for (int i = 0; i < lista.tamanho; i++)
  {
    if (lista.itens[i] != 0)
      printf("%d\n", lista.itens[i]);
  }
}