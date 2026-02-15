//Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.
//You must do it in place.

#include <stdio.h>

int main() {
    int m, n;
    scanf("%d %d", &m, &n);

    int matrix[m][n];

    // Input matrix
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    int row[m], col[n];

    // Initialize markers
    for(int i = 0; i < m; i++) row[i] = 0;
    for(int j = 0; j < n; j++) col[j] = 0;

    // Step 1: Mark rows and columns that contain 0
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(matrix[i][j] == 0) {
                row[i] = 1;
                col[j] = 1;
            }
        }
    }

    // Step 2: Set marked rows and columns to 0
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(row[i] == 1 || col[j] == 1) {
                matrix[i][j] = 0;
            }
        }
    }

    // Print result
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}
