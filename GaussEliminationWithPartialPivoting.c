#include <stdio.h>
#include <math.h>

void swapRows(int n, float matrix[][n + 1], int row1, int row2) {
    for (int i = 0; i <= n; i++) {
        float temp = matrix[row1][i];
        matrix[row1][i] = matrix[row2][i];
        matrix[row2][i] = temp;
    }
}

void gaussianElimination(int n, float matrix[][n + 1]) {
    int i, j, k;
    float pivot, factor;

    // Forward elimination with partial pivoting
    for (i = 0; i < n - 1; i++) {
        int maxRowIndex = i;

        for (j = i + 1; j < n; j++) {
            if (fabs(matrix[j][i]) > fabs(matrix[maxRowIndex][i])) {
                maxRowIndex = j;
            }
        }

        if (maxRowIndex != i) {
            // Swap rows to get the maximum element as pivot
            swapRows(n, matrix, i, maxRowIndex);
        }

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
    printf("Solution After solving the matrix:\n");
    for (i = 0; i < n; i++) {
        printf("x%d = %.2f\n", i + 1, solution[i]);
    }
}

int main() {
    int n, i, j;

    printf("Enter the number of variables in matrix  : ");
    scanf("%d", &n);

    float matrix[n][n + 1];

    printf("Enter the augmented matrix coefficients:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j <= n; j++) {
            printf("matrix[%d][%d]: ", i + 1, j + 1);
            scanf("%f", &matrix[i][j]);
        }
    }

    gaussianElimination(n, matrix);

    return 0;
}
