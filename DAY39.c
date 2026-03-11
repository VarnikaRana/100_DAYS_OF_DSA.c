#include <stdio.h>

#define MAX 100

int heap[MAX];
int size = 0;

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapifyUp(int index) {
    int parent = (index - 1) / 2;

    while (index > 0 && heap[parent] > heap[index]) {
        swap(&heap[parent], &heap[index]);
        index = parent;
        parent = (index - 1) / 2;
    }
}

void heapifyDown(int index) {
    int left = 2 * index + 1;
    int right = 2 * index + 2;
    int smallest = index;

    if (left < size && heap[left] < heap[smallest])
        smallest = left;

    if (right < size && heap[right] < heap[smallest])
        smallest = right;

    if (smallest != index) {
        swap(&heap[index], &heap[smallest]);
        heapifyDown(smallest);
    }
}

void insert(int value) {
    if (size == MAX) {
        printf("Heap Overflow\n");
        return;
    }

    heap[size] = value;
    heapifyUp(size);
    size++;
}

int deleteMin() {
    if (size == 0) {
        printf("Heap Underflow\n");
        return -1;
    }

    int root = heap[0];
    heap[0] = heap[size - 1];
    size--;

    heapifyDown(0);

    return root;
}

void display() {
    for (int i = 0; i < size; i++)
        printf("%d ", heap[i]);
    printf("\n");
}

int main() {
    insert(20);
    insert(5);
    insert(15);
    insert(22);
    insert(9);

    printf("Min Heap: ");
    display();

    printf("Deleted Min: %d\n", deleteMin());

    printf("Heap after deletion: ");
    display();

    return 0;
}
