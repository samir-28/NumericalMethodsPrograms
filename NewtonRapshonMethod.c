#include <stdio.h>
#include <Math.h>
#define E 0.001
#define f(x) x *x + x - 2
#define g(x) 2 * x + 1 

/* float f(float x){
     float y;
     y=2*pow(x,2)+4*x-2;
     return y;
}
float fd(float x){
     float y;
     y=4*x+4;
     return y;
}
 */

int main()
{
    float Xo, Xi, fXi, fx, gx;
    int i = 0;
    printf("Enter the value of initial guess Xo:");
    scanf("%f", &Xo);

    do
    {
        fx = f(Xo);
        gx = g(Xo);
        Xi = Xo - (fx/gx);
        fXi=f(Xi);
        Xo = Xi;

        i++;

        printf("Iteration :%d", i);
        printf("\t Root(Xi):%.5f", Xi);
        printf("\t f(Xi):%.5f", fXi);
        printf("\n");

    } while (fabs(fXi) > E);

    printf("The approximate root of the equation is :%.5f", Xi);
}
