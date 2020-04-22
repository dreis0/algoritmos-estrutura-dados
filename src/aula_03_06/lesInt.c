#include <stdio.h>
#include <stdlib.h>

struct ListaFloat
{
  int *itens;
  int tamanho, quantidade;
};

void criaLista(struct ListaFloat *, int);
void insere(struct ListaFloat *, int);
void exclui(struct ListaFloat *, int);
int buscaLinear(struct ListaFloat *, int);
void mostra(struct ListaFloat *);

int main()
{
  struct ListaFloat lista;
  int n, valor;
  char operacao;

  scanf("%d", &n);
  criaLista(&lista, n);

  while (scanf("\n%c", &operacao) != EOF)
  {
    if (operacao == 'I')
    {
      scanf(" %d", &valor);
      if (!buscaLinear(&lista, valor))
        insere(&lista, valor);
    }
    else if (operacao == 'R')
    {
      scanf(" %d", &valor);
      exclui(&lista, valor);
    }
    else if (operacao == 'B')
    {
      scanf(" %d", &valor);

      if (buscaLinear(&lista, valor))
      {
        printf("SIM\n");
      }
      else
      {
        printf("NAO\n");
      }
    }
    else if (operacao == 'M')
    {
      mostra(&lista);
    }
  }
  free(lista.itens);
  return 0;
}

void criaLista(struct ListaFloat *lista, int n)
{
  lista->itens = (int *)malloc(sizeof(int) * n);
  lista->quantidade = 0;
  lista->tamanho = n;
}

void insere(struct ListaFloat *lista, int valor)
{
  int i = 0, posicaoEncontrada = 0;

  while (i < lista->quantidade && !posicaoEncontrada)
  {
    if (lista->itens[i] > valor)
      posicaoEncontrada = 1;
    else
      i++;
  }

  if (posicaoEncontrada)
  {
    for (int j = lista->quantidade; j > i; j--)
    {
      lista->itens[j] = lista->itens[j - 1];
    }
  }

  lista->itens[i] = valor;
  lista->quantidade++;
}

void exclui(struct ListaFloat *lista, int valor)
{
  int i = 0, posicaoEncontrada = 0;

  while (i < lista->quantidade && !posicaoEncontrada)
  {
    if (lista->itens[i] == valor)
      posicaoEncontrada = 1;
    else
      i++;
  }

  if (posicaoEncontrada)
  {
    for (int j = i; j < lista->quantidade - 1; j++)
    {
      lista->itens[j] = lista->itens[j + 1];
    }

    lista->quantidade--;
  }
}

int buscaLinear(struct ListaFloat *lista, int valor)
{
  for (int i = 0; i < lista->quantidade; i++)
  {

    if (lista->itens[i] == valor)
    {
      return 1;
    }
  }

  return 0;
}

void mostra(struct ListaFloat *lista)
{
  for (int i = 0; i < lista->quantidade && i < lista->tamanho; i++)
  {
    printf("%d%c", lista->itens[i], i == lista->quantidade - 1 || i == lista->tamanho - 1 ? '\n' : ' ');
  }
}
