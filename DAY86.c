#include <stdio.h>

int integerSqrt(int n) {
    if (n == 0 || n == 1)
        return n;

    int left = 0, right = n, ans = 0;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        // Use long long to avoid overflow
        long long square = (long long)mid * mid;

        if (square == n) {
            return mid;
        } else if (square < n) {
            ans = mid;        // store possible answer
            left = mid + 1;   // search right half
        } else {
            right = mid - 1;  // search left half
        }
    }

    return ans;
}

int main() {
    int n;
    scanf("%d", &n);

    printf("%d\n", integerSqrt(n));

    return 0;
}
