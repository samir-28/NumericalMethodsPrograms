#include <stdio.h>

void gaussianElimination(int n, float matrix[][n + 1]) {
    int i, j, k;
    float pivot, factor;

    // Forward elimination
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            pivot = matrix[j][i] / matrix[i][i];

            for (k = i; k <= n; k++) {
                matrix[j][k] -= pivot * matrix[i][k];
            }
        }
    }

    // Backward substitution
    float solution[n];
    for (i = n - 1; i >= 0; i--) {
        solution[i] = matrix[i][n];

        for (j = i + 1; j < n; j++) {
            solution[i] -= matrix[i][j] * solution[j];
        }

        solution[i] /= matrix[i][i];
    }

    // Display the solution
    printf("Solutions after Solving the matrix:\n");
    for (i = 0; i < n; i++) {
        printf("x%d = %.2f\n", i + 1, solution[i]);
    }
}

int main() {
    int n, i, j;

    printf("Enter the number of variables in the matrix: ");
    scanf("%d", &n);

    float matrix[n][n + 1];

    printf("Enter the augmented matrix coefficients:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j <= n; j++) {
            printf("matrix[%d][%d]:", i + 1, j + 1);
            scanf("%f", &matrix[i][j]);
        }
    }

    gaussianElimination(n, matrix);

    return 0;
}
