//Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.
 //Note that you must do this in-place without making a copy of the array

#include <stdio.h>

int main() {
    int n, i, j = 0;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int nums[n];

    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }

    for (i = 0; i < n; i++) {
        if (nums[i] != 0) {
            nums[j] = nums[i];
            j++;
        }
    }

    while (j < n) {
        nums[j] = 0;
        j++;
    }

    printf("Array after moving zeros to the end:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", nums[i]);
    }

    return 0;
}
