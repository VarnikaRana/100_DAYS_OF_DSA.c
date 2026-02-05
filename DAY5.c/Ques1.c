//Problem: A system receives two separate logs of user arrival times from two different servers.
// Each log is already sorted in ascending order. Your task is to create a single 
// chronological log that preserves the correct order of arrivals.

#include <stdio.h>

void mergeLogs(int log1[], int n1, int log2[], int n2, int merged[]) {
    int i = 0, j = 0, k = 0;

    while (i < n1 && j < n2) {
        if (log1[i] <= log2[j]) {
            merged[k++] = log1[i++];
        } else {
            merged[k++] = log2[j++];
        }
    }

    while (i < n1) {
        merged[k++] = log1[i++];
    }

    while (j < n2) {
        merged[k++] = log2[j++];
    }
}

int main() {
    int n1, n2;

    printf("Enter number of entries in first log: ");
    scanf("%d", &n1);

    int log1[n1];
    printf("Enter %d sorted arrival times:\n", n1);
    for (int i = 0; i < n1; i++) {
        scanf("%d", &log1[i]);
    }

    printf("Enter number of entries in second log: ");
    scanf("%d", &n2);

    int log2[n2];
    printf("Enter %d sorted arrival times:\n", n2);
    for (int i = 0; i < n2; i++) {
        scanf("%d", &log2[i]);
    }

    int merged[n1 + n2];

    mergeLogs(log1, n1, log2, n2, merged);

    printf("Merged chronological log:\n");
    for (int i = 0; i < n1 + n2; i++) {
        printf("%d ", merged[i]);
    }

    return 0;
}

