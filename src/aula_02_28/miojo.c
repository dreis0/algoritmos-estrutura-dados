#include <stdio.h>

void swap(int *a, int *b)
{
  int aux = *a;
  *a = *b;
  *b = aux;
}

int main()
{
  int T, A, B, tempo = 0, i = 1, j = 1, aux = 0;

  scanf("%d %d %d", &T, &A, &B);

  if (A < B)
    swap(&A, &B);

  //T = 14 | A = 22 | B = 15
  for (i = 1; tempo == 0; i++)
  {
    for (j = i; j > 0; j--)
    {
      if (A * i - B * j == T)
        tempo = A * i;
      else if (A * j - B * i == T)
        tempo = A * j;
      else if (B * i - A * j == T)
        tempo = B * i;
      else if (B * j - A * i == T)
        tempo = B * j;
    }
  }

  printf("%d\n", tempo);

  return 0;
}