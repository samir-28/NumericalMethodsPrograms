#include <stdio.h>

int main() {
    int n, count = 0, i, j, k;
    printf("Enter the order of square matrix: ");
    scanf("%d", &n);

    float matrix[n][2 * n], temp, root[n];
    
    // Input matrix
    printf("Enter the elements of the matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("A[%d][%d]: ", i + 1, j + 1);
            scanf("%f", &matrix[i][j]);
        }
    }

    // Augmented matrix initialization with identity matrix
    for (i = 0; i < n; i++) {
        for (j = n; j < 2 * n; j++) {
            if (j - i == n) {
                matrix[i][j] = 1;
            } else {
                matrix[i][j] = 0;
            }
        }
    }

    // Display the input matrix
    printf("\nThe input matrix is:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%.2f\t", matrix[i][j]);
        }
        printf("\n");
    }

    // Gauss-Jordan elimination
    for (i = 0; i < n; i++) {
        // Partial Pivoting
        for (j = i + 1; j < n; j++) {
            if (matrix[j][i] > matrix[i][i]) {
                for (k = 0; k < 2 * n; k++) {
                    float temp = matrix[i][k];
                    matrix[i][k] = matrix[j][k];
                    matrix[j][k] = temp;
                }
            }
        }

        // Normalization
        float pivot = matrix[i][i];
        for (j = 0; j < 2 * n; j++) {
            matrix[i][j] /= pivot;
        }

        // Elimination
        for (j = 0; j < n; j++) {
            if (j != i) {
                float factor = matrix[j][i];
                for (k = 0; k < 2 * n; k++) {
                    matrix[j][k] -= factor * matrix[i][k];
                }
            }
        }
    }

    // Display the inverse matrix
    printf("\nThe inverse matrix is:\n");
    for (i = 0; i < n; i++) {
        for (j = n; j < 2 * n; j++) {
            printf("%.2f\t", matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}
