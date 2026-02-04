//Problem: Given an array of n integers, reverse the array in-place using two-pointer approach.
#include <stdio.h>

void reverseArray(int arr[], int n)
{
    int left = 0, right = n - 1;
    int temp;

    while (left < right)
    {
        temp = arr[left];
        arr[left] = arr[right];
        arr[right] = temp;

        left++;
        right--;
    }
}

int main()
{
    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    reverseArray(arr, n);

    printf("Reversed array:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}
