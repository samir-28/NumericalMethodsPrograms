#include <stdio.h>
#include <math.h>
#define f(x) sqrt(1 + x * x)

int main()
{
    float a, h, k, x0, xn, fx0, fxn, term, v;
    printf("Enter Lower and Upper Limit:\n");
    scanf("%f%f", &x0, &xn);
    printf("Enter number of segments:");
    scanf("%f", &k);
    h = (xn - x0) / k;
    fx0 = f(x0);
    fxn = f(xn);
    term = (fx0 + fxn);
    for (int i = 1; i <= k - 1; i++)
    {
        a = x0 + i * h;
        term = term + 2 * (f(a));
    }
    v = h / 2 * term;
    printf("Value of Integration is:%.3f", v);
    return 0;
}