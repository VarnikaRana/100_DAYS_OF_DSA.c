/*Write a C program to read an array of integers from the user and a target integer value. The program should find and display the indices of the two different elements in the array whose sum is equal to the given target value.
You may assume that:
The array contains exactly one such pair.
The same element should not be used twice.
Indices should be displayed using 0-based indexing. */

#include <stdio.h>

int main() {
    int n, target;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int nums[n];

    printf("Enter %d integers:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }

    printf("Enter target value: ");
    scanf("%d", &target);

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (nums[i] + nums[j] == target) {
                printf("Indices: %d and %d\n", i, j);
                return 0;
            }
        }
    }

    return 0;
}
