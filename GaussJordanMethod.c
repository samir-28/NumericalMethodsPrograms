#include <stdio.h>

int main() {
    int n, i, j, k;
    printf("Enter the order of the square matrix: ");
    scanf("%d", &n);

    float matrix[n][n + 1];

    // Input augmented matrix coefficients
    printf("Enter the elements of the augmented matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j <= n; j++) {
            printf("A[%d][%d]: ", i + 1, j + 1);
            scanf("%f", &matrix[i][j]);
        }
    }

    // Gauss-Jordan elimination
    for (i = 0; i < n; i++) {
        // Partial Pivoting
        for (j = i + 1; j < n; j++) {
            if (matrix[j][i] > matrix[i][i]) {
                for (k = 0; k <= n; k++) {
                    float temp = matrix[i][k];
                    matrix[i][k] = matrix[j][k];
                    matrix[j][k] = temp;
                }
            }
        }

        // Normalization
        float pivot = matrix[i][i];
        for (j = 0; j <= n; j++) {
            matrix[i][j] /= pivot;
        }

        // Elimination
        for (j = 0; j < n; j++) {
            if (j != i) {
                float factor = matrix[j][i];
                for (k = 0; k <= n; k++) {
                    matrix[j][k] -= factor * matrix[i][k];
                }
            }
        }
    }

    // Display the solution
    printf("\nThe solution of the given system is:\n");
    for (i = 0; i < n; i++) {
        printf("X%d = %.2f\n", i + 1, matrix[i][n]);
    }

    return 0;
}

  