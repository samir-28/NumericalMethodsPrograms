#include <stdio.h>
#include <math.h>
#define e 0.001
#define f(x) x *x - 2 * x - 3

float g(float x)
{
    float y;
    y = sqrt(2 * x + 3);
    return y;
}
float gd(float x)
{
    float y;
    y = 1 / sqrt(2 * x + 3);
    return y;
}
int main()
{
    float xo, x1, fx1;
    int i = 0;
    printf("Enter the initial guesses Xo :\n");
    scanf("%f", &xo);
    if (gd(xo) < 1)
    {
        do
        {
            x1 = g(xo);
            fx1 = f(x1);
            xo = x1;
            i++;
            printf("Iteration :%d", i);
            printf("\t Root(X1):%.5f", x1);
            printf("\t f(X1):%.5f", f(x1));
            printf("\n");

        } while (fabs(f(x1)) > e);
    }
    else
    {
    printf("The iterative formula for fixed-point method is wrong.");
    }
    printf("The approximate root of the equation is :%.5f", x1);
    return 0;
}