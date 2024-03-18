#include <stdio.h>
#include <math.h>
#define pi 3.1415
#define f(x) sin(x) + 1

int main()
{
    float angle, h, x, dx;
    printf("Enter the angle in degree:");
    scanf("%f", &angle);
    printf("Enter value of h:");
    scanf("%f", &h);
    x = (pi / 180) * angle;
    dx = (((f(x + h)) - (f(x-h))) / 2*h);
    printf("Value of derivative is:%.3f", dx);
    return 0;
}