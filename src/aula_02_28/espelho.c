#include <stdio.h>

int main()
{
    int a, b, a1, a2, a3, a4, b1, b2, b3, b4;

    scanf("%d %d", &a, &b);

    a1 = a / 1000;
    a2 = (a % 1000) / 100;
    a3 = (a % 100) / 10;
    a4 = a % 10;

    b1 = b / 1000;
    b2 = (b % 1000) / 100;
    b3 = (b % 100) / 10;
    b4 = b % 10;

    if (a1 == b4 && a2 == b3 && a3 == b2 && a4 == b1)
        printf("espelho\n");
    else
        printf("nao espelho\n");

    return 0;
}