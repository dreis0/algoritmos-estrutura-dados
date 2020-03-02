#include <stdio.h>
#include <math.h>

int main()
{
    double a, b, c, delta, r1, r2;

    scanf("%lf %lf %lf", &a, &b, &c);

    delta = sqrt(b * b - 4 * a * c);

    if (delta >= 0)
    {
        r1 = (-b + delta) / (2 * a);
        r2 = (-b - delta) / (2 * a);

        if (delta == 0)
            printf("%0.4lf\n", r1);
        else
            printf("%0.4lf %0.4lf\n", r1, r2);
    }
    else
        printf("nao ha raiz real\n");

    return 0;
}
