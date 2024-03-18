#include <stdio.h>
#include<math.h>

int main() {
    int n, i, j;
    float a=0,b=0, fx[10], x[10],sx=0,slgy=0,sxy=0,sx2=0,r;

    printf("Enter the number of points:");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Values of X and f(X) at i = %d\n", i);
        scanf("%f%f", &x[i], &fx[i]);
    }
     for (i = 0; i < n; i++){
        sx=sx+x[i];
        slgy=slgy+log(fx[i]);
        sxy=sxy+x[i]*log(fx[i]);
        sx2=sx2+x[i]*x[i];
     }
     b=((n*sxy)-(sx*slgy))/((n*sx2)-(sx*sx));
     r=(slgy/n)-b*(sx/n);
     a=exp(r);
     printf("Fitted Line is:y=%.2fe^%.2fx",a,b);
     return 0;
}