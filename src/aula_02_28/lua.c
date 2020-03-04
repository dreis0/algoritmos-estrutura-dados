#include <stdio.h>

int main()
{
  int numTestes, noite1, noite2;

  scanf("%d", &numTestes);

  for (int i = 0; i < numTestes; i++)
  {
    scanf("%d %d", &noite1, &noite2);

    if (0 <= noite2 && noite2 <= 2)
      printf("Nova\n");
    else if (3 <= noite2 && noite2 <= 96)
      if (noite1 < noite2)
        printf("Crescente\n");
      else
        printf("Minguante\n");
    else
      printf("Cheia\n");
  }

  return 0;
}