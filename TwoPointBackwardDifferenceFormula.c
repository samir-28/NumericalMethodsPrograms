#include <stdio.h>
#include <math.h>
#define f(x) x*x

int main()
{
    float  h, x, dx;
    printf("Enter the value at which derivative is required:");
    scanf("%f", &x);
    printf("Enter value of h:");
    scanf("%f", &h);
    dx = ((f(x))-(f(x - h))) / h;
    printf("Value of derivative is:%.3f", dx);
    return 0;
}