//Problem: Write a program to find the maximum and minimum values present in a given array of integers.

#include <stdio.h>

int main() {
    int n, i;
    int arr[100];
    int min, max;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    min = arr[0];
    max = arr[0];

    for(i = 1; i < n; i++) {
        if(arr[i] < min)
            min = arr[i];
        if(arr[i] > max)
            max = arr[i];
    }

    printf("Minimum value = %d\n", min);
    printf("Maximum value = %d\n", max);

    return 0;
}
