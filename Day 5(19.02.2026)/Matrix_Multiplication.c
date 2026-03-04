#include <stdio.h>

int main() {
    int A[2][2] = {{1, 2}, {3, 4}};
    int B[2][2] = {{5, 6}, {7, 8}};
    int C[2][2];

    printf("Matrix A:\n");
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++)
            printf("%d ", A[i][j]);
        printf("\n");
    }

    printf("\nMatrix B:\n");
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++)
            printf("%d ", B[i][j]);
        printf("\n");
    }

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            C[i][j] = 0;
            for (int k = 0; k < 2; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    printf("\nResult Matrix (C = A × B):\n");
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++)
            printf("%d ", C[i][j]);
        printf("\n");
    }

    return 0;
}


/*
OUTPUT:

Matrix A:
1 2 
3 4 

Matrix B:
5 6 
7 8 

Result Matrix (C = A × B):
19 22 
43 50 
*/