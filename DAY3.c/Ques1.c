/* Problem: Implement linear search to find key k in an array. Count and display the number of comparisons performed. */

#include <stdio.h>

int main() {
    int n, k, i;
    int count = 0;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter %d elements:\n", n);
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter key to search: ");
    scanf("%d", &k);

    for(i = 0; i < n; i++) {
        count++;                
        if(arr[i] == k) {
            printf("Key found at position %d\n", i + 1);
            break;
        }
    }

    if(i == n) {
        printf("Key not found\n");
    }

    printf("Number of comparisons = %d\n", count);

    return 0;
}
