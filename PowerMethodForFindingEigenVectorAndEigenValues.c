#include <stdio.h>
#include <math.h>
#include<conio.h> 

int main() {
    int n,i,j;
    // Input order of the matrix
    printf("Enter the order of the square matrix: ");
    scanf("%d", &n);

    float error,k,a[10][10], x[10],nx[10],y[10],E[10];

    // Input the matrix
    printf("Enter the elements of the matrix:\n");
    for ( i = 0; i < n; i++) {
        for ( j = 0; j < n; j++) {
            printf("A[%d][%d]: ", i + 1, j + 1);
            scanf("%f", &a[i][j]);
        }
    }

    // Initial guess for eigenvector
    printf("Enter the initial guess for the eigenvector:\n");
    for (int i = 0; i < n; i++) {
        printf("v[%d]: ", i + 1);
        scanf("%f", &x[i]);
    }
    printf("Enter the accuracy limit:");
    scanf("%f",&error);
    while(1){
        for( i=0;i<n;i++)
            y[i]=a[i][0]*x[0]+a[i][1]*x[1]+a[i][2]*x[2];
            k=y[0];
            for( i=1;i<n;i++)
            if(k<y[i])
            k=y[i];
             for( i=0;i<n;i++)
             nx[i]=1/k*y[i];
              for( i=0;i<n;i++){
                E[i]=(nx[i]-x[i])/nx[i];
                if(E[i]>error)
                break;
              }
              if(i==n){
                printf("Largest Eigen Value is:%f \n",k);
                printf("Eigen Vector is:\n");
                 for( i=0;i<n;i++)
                 printf("%f\t",nx[i]);
                 break;
              }
                 else
                  for( i=0;i<n;i++)
                  x[i]=nx[i];

              }
              getch();
              return 0;

    }



