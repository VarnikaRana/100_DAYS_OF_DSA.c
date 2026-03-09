#include <stdio.h>
#define MAX 100

int pq[MAX];
int size = 0;

// Insert element into priority queue
void insert(int value)
{
    int i;

    if(size == MAX)
    {
        printf("Priority Queue is Full\n");
        return;
    }

    // Insert element at correct position
    i = size - 1;
    while(i >= 0 && pq[i] > value)
    {
        pq[i + 1] = pq[i];
        i--;
    }

    pq[i + 1] = value;
    size++;

    printf("Inserted: %d\n", value);
}

// Delete highest priority element (smallest value)
void delete()
{
    if(size == 0)
    {
        printf("Priority Queue is Empty\n");
        return;
    }

    printf("Deleted element: %d\n", pq[0]);

    for(int i = 0; i < size - 1; i++)
    {
        pq[i] = pq[i + 1];
    }

    size--;
}

// Display elements
void display()
{
    if(size == 0)
    {
        printf("Priority Queue is Empty\n");
        return;
    }

    printf("Priority Queue elements:\n");
    for(int i = 0; i < size; i++)
    {
        printf("%d ", pq[i]);
    }
    printf("\n");
}

int main()
{
    insert(30);
    insert(10);
    insert(50);
    insert(20);

    display();

    delete();
    display();

    return 0;
}
