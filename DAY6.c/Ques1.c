// Problem: Given a sorted array of n integers, remove duplicates in-place. Print only unique elements in order.

#include <stdio.h>

int main() {
    int n, i, j;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter %d sorted elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    if (n == 0) {
        printf("Array is empty.\n");
        return 0;
    }

    j = 0;   

    for (i = 1; i < n; i++) {
        if (arr[i] != arr[j]) {
            j++;
            arr[j] = arr[i];
        }
    }

    printf("Array after removing duplicates:\n");
    for (i = 0; i <= j; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}

