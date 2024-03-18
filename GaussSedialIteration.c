#include <stdio.h>
#include <math.h>

#define f1(x, y, z) (11 + 2 * y - 1 * z) / 6
#define f2(x, y, z) (5+ 2* x - 2 * z) / 7
#define f3(x, y, z) (1 + 1 * x + 2 * y) / 5

double absolute(double e1, double e2) {
    return fabs(e1 - e2);
}

int main() {
    double error;
    printf("Enter the allowed error: ");
    scanf("%lf", &error);

    double x0 = 0, y0 = 0, z0 = 0, e1, e2, e3, x1, y1, z1;
    int count = 1;

    do {
        x1 = f1(x0, y0, z0);
        y1 = f2(x1, y0, z0);
        z1 = f3(x1, y1, z0);

        e1 = absolute(x1, x0);
        e2 = absolute(y1, y0);
        e3 = absolute(z1, z0);

        count++;

        x0 = x1;
        y0 = y1;
        z0 = z1;

        printf("%d\t%.3f\t%.3f\t%.3f\n", count, x1, y1, z1);

    } while (e1 > error && e2 > error && e3 > error);

    printf("x = %.3f, y = %.3f, z = %.3f\n", x0, y0, z0);

    return 0;
}
