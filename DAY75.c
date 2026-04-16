#include <stdio.h>

int maxLen(int arr[], int n) {
    int sum = 0, max_len = 0;

    // Hash map using array (for simplicity)
    // Assume sum range is limited
    int hash[1000];
    for(int i = 0; i < 1000; i++) hash[i] = -2;

    for(int i = 0; i < n; i++) {
        sum += arr[i];

        if(sum == 0)
            max_len = i + 1;

        if(hash[sum + 500] != -2) {
            int prev_index = hash[sum + 500];
            if(i - prev_index > max_len)
                max_len = i - prev_index;
        } else {
            hash[sum + 500] = i;
        }
    }

    return max_len;
}

int main() {
    int arr[] = {15, -2, 2, -8, 1, 7, 10, 23};
    int n = sizeof(arr)/sizeof(arr[0]);

    printf("%d", maxLen(arr, n));
    return 0;
}
