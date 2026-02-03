/* You are given an array arr[] of size n - 1 that contains distinct integers in the range from 1 to n (inclusive). 
This array represents a permutation of the integers from 1 to n with one element missing.
 Your task is to identify and return the missing element. */


#include <stdio.h>

int missingNum(int arr[], int n) {
    int xorAll = 0;

    for (int i = 0; i < n; i++) {
        xorAll ^= arr[i];
    }

    for (int i = 1; i <= n + 1; i++) {
        xorAll ^= i;
    }

    return xorAll;
}

int main() {
    int n;
    int arr[1000];

    printf("Enter number of elements (n): ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int result = missingNum(arr, n);

    printf("Missing number is: %d\n", result);

    return 0;
}
