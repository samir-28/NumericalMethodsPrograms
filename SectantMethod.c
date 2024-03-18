#include <stdio.h>
#include <math.h>
#define e 0.001

float f(float x)
{
    float y;
    y = pow(x, 2) - 4 * x - 10;
    return y;
}
int main()
{
    float x1, x0, x2, fx2;
    int i = 0;
    printf("Enter the initial guesses X1 and X0 :\n");
    scanf("%f%f", &x0, &x1);
    do
    {
        x2 = x1 - ((f(x1) * (x1 - x0)) / (f(x1) - f(x0)));
        x0 = x1;
        x1 = x2;
        i++;
        printf("Iteration :%d", i);
        printf("\t Root(X2):%.5f", x2);
        printf("\t f(X2):%.5f", f(x2));
        printf("\n");

    } while (fabs(f(x2)) > e);
    printf("The approximate root of the equation is :%.5f", x2);
    return 0;
}