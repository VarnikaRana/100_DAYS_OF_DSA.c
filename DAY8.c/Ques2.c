//Given an integer n, return true if it is a power of two. Otherwise, return false.
//An integer n is a power of two, if there exists an integer x such that n == 2x.
#include <stdio.h>
#include <stdbool.h>

bool isPowerOfTwo(int n)
{
    if (n > 0 && (n & (n - 1)) == 0)
        return true;
    else
        return false;
}

int main()
{
    int n;
    printf("Enter an integer: ");
    scanf("%d", &n);

    if (isPowerOfTwo(n))
        printf("%d is a power of two.\n", n);
    else
        printf("%d is NOT a power of two.\n", n);

    return 0;
}
