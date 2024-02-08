#include <stdio.h>

// Function to calculate the index for lower triangular matrix in row-major order
int rowMajorIndex(int i, int j) {
    return i * (i - 1) / 2 + j - 1;
}

// Function to calculate the index for lower triangular matrix in column-major order
int colMajorIndex(int i, int j) {
    return 3 * (j - 1) - ((j - 2) * (j - 1)) / 2 + i - j;
}

int main() {
    int matrix[3][3];
    int lowerTriangular[6]; // 3 * (3 + 1) / 2 = 6

    // Input: Taking 9 elements for a 3x3 matrix
    printf("Enter 9 elements for a 3x3 matrix:\n");
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            scanf("%d", &matrix[i][j]);

    // Creating lower triangular matrix
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (i >= j)
                lowerTriangular[rowMajorIndex(i, j)] = matrix[i][j];

    // Printing lower triangular matrix in row-major form
    printf("\nLower Triangular Matrix in Row-Major Form:\n");
    for (int i = 0; i < 6; i++)
        printf("%d ", lowerTriangular[i]);
    printf("\n");

    // Printing lower triangular matrix in column-major form
    printf("\nLower Triangular Matrix in Column-Major Form:\n");
    for (int j = 0; j < 3; j++)
        for (int i = j; i < 3; i++)
            printf("%d ", lowerTriangular[colMajorIndex(i, j)]);
    printf("\n");

    return 0;
}
