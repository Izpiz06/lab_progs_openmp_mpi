#include <stdio.h>
#include <omp.h>

#define ROW 3
#define COL 3

int main() {
    int A[ROW][COL] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int B[ROW][COL] = {
        {9, 8, 7},
        {6, 5, 4},
        {3, 2, 1}
    };

    int C[ROW][COL];

    #pragma omp parallel for collapse(2)
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }

    printf("Resultant Matrix:\n");

    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }

    return 0;
}