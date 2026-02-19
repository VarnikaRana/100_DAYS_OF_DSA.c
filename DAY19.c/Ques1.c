//Problem: Given an array of integers, find two elements whose sum is closest to zero.

#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int n;

    printf("Enter size of array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d elements:\n", n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Sort the array
    qsort(arr, n, sizeof(int), compare);

    int left = 0, right = n - 1;
    int min_sum = arr[left] + arr[right];
    int x = arr[left], y = arr[right];

    while (left < right) {
        int sum = arr[left] + arr[right];

        if (abs(sum) < abs(min_sum)) {
            min_sum = sum;
            x = arr[left];
            y = arr[right];
        }

        if (sum < 0)
            left++;
        else
            right--;
    }

    printf("The two elements whose sum is closest to zero are: %d and %d\n", x, y);
    printf("Their sum is: %d\n", min_sum);

    return 0;
}
