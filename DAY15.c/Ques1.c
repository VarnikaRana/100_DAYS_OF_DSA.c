//Problem: Given a matrix, calculate the sum of its primary diagonal elements.
//The primary diagonal consists of elements where row index equals column index.

#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);   // size of square matrix

    int matrix[n][n];

    // Input matrix
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    int sum = 0;

    // Sum of primary diagonal
    for(int i = 0; i < n; i++) {
        sum += matrix[i][i];
    }

    printf("%d", sum);

    return 0;
}
