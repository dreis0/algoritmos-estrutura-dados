#include <stdio.h>

/*
3584
65465
11111
1278
10
666
337
1000
*/
int main()
{
    long long int n;
    int digitos, aux;

    while (scanf("%lld\n", &n) != EOF)
    {
        digitos = 0;
        aux = 1;

        while (n >= aux)
        {
            if ((n / aux) % 2 == 0)
                digitos++;
            aux *= 10;
        }

        printf("%d\n", digitos);
    }

    return 0;
}