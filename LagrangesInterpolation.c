#include <stdio.h>
#include <math.h>

int main()
{
    int n, i, j;
    float x, l, finalValue, ax[10], fx[10], L[10];
    printf("Enter the number of points:");
    scanf("%d", &n);
    printf("Enter the value of x at which f(x) is calculated:");
    scanf("%f", &x);

    for (i = 1; i <= n; i++)
    {
        printf("Values of X and f(X) at i =%d \n", i);
        scanf("%f%f", &ax[i], &fx[i]);
    }

    for (i = 1; i <= n; i++)
    {
        l = 1.0;
        for (j = 1; j <= n; j++)
        {
            if (j != i)
            {
                l = l * ((x - ax[j]) / (ax[i] - ax[j]));
            }
            L[i] = l;
        }
    }
    for (i = 1; i <= n; i++)
    {
        finalValue = finalValue + fx[i] * L[i];
    }
    printf("The Interpolated Value is:%f ", finalValue);
    return 0;
}