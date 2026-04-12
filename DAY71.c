#include <stdio.h>
#include <string.h>

#define EMPTY -1
#define MAX 100

int table[MAX];

// Initialize hash table
void init(int m) {
    for (int i = 0; i < m; i++)
        table[i] = EMPTY;
}

// Insert using quadratic probing
void insert(int key, int m) {
    int i = 0;
    int index;

    while (i < m) {
        index = (key % m + i * i) % m;

        if (table[index] == EMPTY) {
            table[index] = key;
            return;
        }
        i++;
    }

    printf("Hash table is full\n");
}

// Search using quadratic probing
int search(int key, int m) {
    int i = 0;
    int index;

    while (i < m) {
        index = (key % m + i * i) % m;

        if (table[index] == key)
            return 1;

        if (table[index] == EMPTY)
            return 0;

        i++;
    }

    return 0;
}

int main() {
    int m, q;
    char operation[10];
    int key;

    // Input size of table
    scanf("%d", &m);

    // Number of operations
    scanf("%d", &q);

    init(m);

    for (int i = 0; i < q; i++) {
        scanf("%s %d", operation, &key);

        if (strcmp(operation, "INSERT") == 0) {
            insert(key, m);
        } 
        else if (strcmp(operation, "SEARCH") == 0) {
            if (search(key, m))
                printf("FOUND\n");
            else
                printf("NOT FOUND\n");
        }
    }

    return 0;
}
