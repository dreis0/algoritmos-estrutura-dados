#include <stdio.h>

int main()
{
    int senha, milhar = 0, centena = 0, dezena = 0, unidade = 0;
    scanf("%d", &senha);

    milhar = senha / 1000;
    centena = (senha % 1000) / 100;
    dezena = (senha % 100) / 10;
    unidade = senha % 10;

    if (milhar != 0 && centena != 0 && dezena != 0 && unidade != 0)
        printf("SIM\n");
    else
        printf("NAO\n");

    return 0;
}