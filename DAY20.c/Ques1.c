//Problem: Given an array of integers, count the number of subarrays whose sum is equal to zero.

#include <stdio.h>
#include <stdlib.h>

int countZeroSumSubarrays(int arr[], int n) {
    int count = 0;
    int sum = 0;

    int freq[1000] = {0};

    freq[0] = 1; 

    for (int i = 0; i < n; i++) {
        sum += arr[i];

        count += freq[sum];

        freq[sum]++;
    }

    return count;
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

    int result = countZeroSumSubarrays(arr, n);

    printf("Number of subarrays with sum = 0: %d\n", result);

    return 0;
}
