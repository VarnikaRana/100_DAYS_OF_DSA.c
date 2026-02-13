//Problem: You are given a rectangular matrix of integers.
// Starting from the outer boundary, traverse the matrix in a clockwise manner and continue moving inward layer by layer until all elements are visited

#include <stdio.h>

int main() {
    int r = 3, c = 3;

    int a[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int top = 0, bottom = r - 1;
    int left = 0, right = c - 1;

    while (top <= bottom && left <= right) {

        // left to right
        for (int i = left; i <= right; i++)
            printf("%d ", a[top][i]);
        top++;

        // top to bottom
        for (int i = top; i <= bottom; i++)
            printf("%d ", a[i][right]);
        right--;

        // right to left
        if (top <= bottom) {
            for (int i = right; i >= left; i--)
                printf("%d ", a[bottom][i]);
            bottom--;
        }

        // bottom to top
        if (left <= right) {
            for (int i = bottom; i >= top; i--)
                printf("%d ", a[i][left]);
            left++;
        }
    }

    return 0;
}
