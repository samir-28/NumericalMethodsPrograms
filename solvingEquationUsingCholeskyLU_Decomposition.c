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

void solveLinearSystemCholesky(int n, float L[n][n], float b[n], float x[n]) {
    // Forward substitution for Ly = b
    for (int i = 0; i < n; i++) {
        float sum = 0;
        for (int j = 0; j < i; j++) {
            sum += L[i][j] * x[j];
        }
        x[i] = (b[i] - sum) / L[i][i];
    }

    // Backward substitution for L^T x = y
    for (int i = n - 1; i >= 0; i--) {
        float sum = 0;
        for (int j = i + 1; j < n; j++) {
            sum += L[j][i] * x[j];
        }
        x[i] = (x[i] - sum) / L[i][i];
    }
}

int main() {
    int n, i, j;
    printf("Enter the order of the matrix: ");
    scanf("%d", &n);

    float original_mat[n][n], L[n][n], b[n], x[n];

    printf("Enter the data inside the matrix below:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("A[%d][%d]: ", i + 1, j + 1);
            scanf("%f", &original_mat[i][j]);
        }
    }

    printf("\nEnter the elements of the RHS vector  :\n");
    for (i = 0; i < n; i++) {
        printf("b[%d]: ", i + 1);
        scanf("%f", &b[i]);
    }

    // Cholesky Decomposition
    choleskyDecomposition(n, original_mat, L);

    // Solve the system of linear equations
    solveLinearSystemCholesky(n, L, b, x);

    // Display the solution
    printf("\nThe solution of the given system is:\n");
    for (i = 0; i < n; i++) {
        printf("x[%d] = %.2f\n", i + 1, x[i]);
    }

    return 0;
}
