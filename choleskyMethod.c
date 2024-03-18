#include <stdio.h>
#include <math.h>

void choleskyDecomposition(int n, float A[n][n], float L[n][n]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            float sum = 0;
            if (i == j) {
                for (int k = 0; k < j; k++) {
                    sum += pow(L[j][k], 2);
                }
                L[j][j] = sqrt(A[j][j] - sum);
            } else {
                for (int k = 0; k < j; k++) {
                    sum += (L[i][k] * L[j][k]);
                }
                L[i][j] = (A[i][j] - sum) / L[j][j];
            }
        }
    }
}

int main() {
    int n, i, j;

    // Input order of the matrix
    printf("Enter the order of the matrix: ");
    scanf("%d", &n);

    float original_mat[n][n], L[n][n];

    // Input matrix
    printf("Enter the elements of the matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("A[%d][%d]: ", i + 1, j + 1);
            scanf("%f", &original_mat[i][j]);
        }
    }

    // Display original matrix
    printf("\nOriginal matrix is:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%.2f\t", original_mat[i][j]);
        }
        printf("\n");
    }

    // Cholesky Decomposition
    choleskyDecomposition(n, original_mat, L);

    // Display Cholesky Decomposition Matrix (Lower Triangular)
    printf("\n(L-Matrix):\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%.2f\t", L[i][j]);
        }
        printf("\n");
    }

    // Display the transpose of Cholesky Decomposition Matrix (Upper Triangular)
    printf("\n(U-Matrix):\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%.2f\t", L[j][i]);  // Transpose
        }
        printf("\n");
    }

    return 0;
}
