#include <stdio.h>

int main() {
    int n, i, j;
    float xv, fx[10], x[10], v = 0, p, a[10];

    printf("Enter the number of points:");
    scanf("%d", &n);

    printf("Enter the value at which f(x) is to be found:");
    scanf("%f", &xv);

    for (i = 0; i < n; i++) {
        printf("Values of X and f(X) at i = %d\n", i);
        scanf("%f%f", &x[i], &fx[i]);
    }

    for (i = 0; i < n; i++)
        a[i] = fx[i];

    for (i = 0; i < n; i++) {
        for (j = n - 1; j > i; j--) {
            a[j] = (a[j] - a[j - 1]) / (x[j] - x[j - 1 - i]);
        }
    }

    v = 0;

    for (i = 0; i < n; i++) {
        p = 1.0;
        for (j = 0; j <= i - 1; j++) {
            p = p * (xv - x[j]);
        }
        v = v + a[i] * p;
    }

    printf("The Interpolated Value is: %f\n", v);

    return 0;
}
