#include <stdio.h>

int main()
{
  int numJogos, golsMandanteTime1, golsMandanteTime2, golsVisitanteTime1, golsVisitanteTime2, golsTime1, golsTime2;

  scanf("%d", &numJogos);

  for (int i = 0; i < numJogos; i++)
  {
    scanf("%d x %d", &golsMandanteTime1, &golsVisitanteTime2);
    scanf("%d x %d", &golsMandanteTime2, &golsVisitanteTime1);

    golsTime1 = golsMandanteTime1 + golsVisitanteTime1;
    golsTime2 = golsMandanteTime2 + golsVisitanteTime2;

    if (golsTime1 > golsTime2)
      printf("Time 1\n");
    else if (golsTime1 < golsTime2)
      printf("Time 2\n");
    else if (golsVisitanteTime1 > golsVisitanteTime2)
      printf("Time 1\n");
    else if (golsVisitanteTime1 < golsVisitanteTime2)
      printf("Time 2\n");
    else
      printf("Penaltis\n");
  }

  return 0;
}