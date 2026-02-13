//Given an m x n matrix, return all elements of the matrix in spiral order.

#include <stdio.h>
#include <stdlib.h>

int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize) {
    int top = 0, bottom = matrixSize - 1;
    int left = 0, right = matrixColSize[0] - 1;

    int total = matrixSize * matrixColSize[0];
    int *result = (int*)malloc(sizeof(int) * total);
    int index = 0;

    while(top <= bottom && left <= right) {

        for(int i = left; i <= right; i++)
            result[index++] = matrix[top][i];
        top++;

        for(int i = top; i <= bottom; i++)
            result[index++] = matrix[i][right];
        right--;

        if(top <= bottom) {
            for(int i = right; i >= left; i--)
                result[index++] = matrix[bottom][i];
            bottom--;
        }

        if(left <= right) {
            for(int i = bottom; i >= top; i--)
                result[index++] = matrix[i][left];
            left++;
        }
    }

    *returnSize = index;
    return result;
}

int main() {
    int rows, cols;
    printf("Enter number of rows and columns: ");
    scanf("%d %d", &rows, &cols);

    int **matrix = (int**)malloc(rows * sizeof(int*));
    for(int i = 0; i < rows; i++)
        matrix[i] = (int*)malloc(cols * sizeof(int));

    printf("Enter matrix elements:\n");
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    int returnSize;
    int colSize = cols;

    int *result = spiralOrder(matrix, rows, &colSize, &returnSize);

    printf("Spiral Order: ");
    for(int i = 0; i < returnSize; i++)
        printf("%d ", result[i]);

    // free memory
    free(result);
    for(int i = 0; i < rows; i++)
        free(matrix[i]);
    free(matrix);

    return 0;
}
