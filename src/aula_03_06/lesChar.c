#include <stdio.h>
#include <stdlib.h>

struct ListaChar
{
  char *itens;
  int tamanho, quantidade;
};

void criaLista(struct ListaChar *, int);
void insere(struct ListaChar *, char);
void exclui(struct ListaChar *, char);
int buscaLinear(struct ListaChar *, char);
void mostra(struct ListaChar *);

int main()
{
  struct ListaChar lista;
  int n;
  char operacao, caracter;

  scanf("%d", &n);
  criaLista(&lista, n);

  while (scanf("\n%c", &operacao) != EOF)
  {
    if (operacao == 'I')
    {
      scanf(" %c", &caracter);
      if (!buscaLinear(&lista, caracter))
        insere(&lista, caracter);
    }
    else if (operacao == 'R')
    {
      scanf(" %c", &caracter);
      exclui(&lista, caracter);
    }
    else if (operacao == 'B')
    {
      scanf(" %c", &caracter);

      if (buscaLinear(&lista, caracter))
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

  return 0;
}

void criaLista(struct ListaChar *lista, int n)
{
  lista->itens = (char *)malloc(sizeof(char) * n);
  lista->quantidade = 0;
  lista->tamanho = n;
}

void insere(struct ListaChar *lista, char c)
{
  int i = 0, posicaoEncontrada = 0;

  while (i < lista->quantidade && !posicaoEncontrada)
  {
    if (lista->itens[i] > c)
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

  lista->itens[i] = c;
  lista->quantidade++;
}

void exclui(struct ListaChar *lista, char c)
{
  int i = 0, posicaoEncontrada = 0;

  while (i < lista->quantidade && !posicaoEncontrada)
  {
    if (lista->itens[i] == c)
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

int buscaLinear(struct ListaChar *lista, char c)
{
  for (int i = 0; i < lista->quantidade; i++)
  {

    if (lista->itens[i] == c)
    {
      return 1;
    }
  }

  return 0;
}

void mostra(struct ListaChar *lista)
{
  for (int i = 0; i < lista->quantidade; i++)
  {

    printf("%c%c", lista->itens[i], i == lista->quantidade - 1 ? '\n' : ' ');
  }
}
