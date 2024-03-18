#include <stdio.h>

int fact(int n) {
    if (n == 0 || n == 1)
        return 1;
    else
        return (n * fact(n - 1));
}

int main() {
    int n, i, j;
    float xv, fx[10], x[10], h, u, v = 0, p, a[10];

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
        for (j = 0; j < n - i - 1; j++) {
            a[j] = a[j + 1] - a[j];
        }
    }

    h = x[1] - x[0];
    u = (xv - x[n - 1]) / h;
    p = 1.0;

    v = a[n - 1];

    for (i = 1; i < n; i++) {
        p = 1;
        for (j = 0; j < i; j++) {
            p = p * (u + j);
        }
        v = v + (a[n - 1 - i] * p) / fact(i);
    }

    printf("The Interpolated Value is: %f\n", v);

    return 0;
}
 