#include <stdio.h>

int main()
{
  int n, inputV;

  while (scanf("%d %d", &n, &inputV) && n != 0 && inputV != 0)
  {
    int ponto = 0;
    int flag = 0;

    for (int i = inputV; i > 0; i--) //i =3
    {
      ponto = 0;
      for (int j = i; j > 0; j--) //j =3
      {
        for (int k = j; k > 0; k--) //k = 3
        {
          ponto += j;

          // printf("%d\n", ponto);

          if (ponto == n)
            flag = 1;
        }
      }
    }

    if (flag)
      printf("possivel\n");
    else
      printf("impossivel\n");
  }

  return 0;
}