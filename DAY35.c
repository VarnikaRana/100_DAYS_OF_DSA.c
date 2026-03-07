#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *front = NULL;
struct node *rear = NULL;

// Enqueue operation
void enqueue(int value)
{
    struct node *temp;
    temp = (struct node*)malloc(sizeof(struct node));

    if(temp == NULL)
    {
        printf("Memory allocation failed\n");
        return;
    }

    temp->data = value;
    temp->next = NULL;

    if(rear == NULL)
    {
        front = rear = temp;
    }
    else
    {
        rear->next = temp;
        rear = temp;
    }
}

// Dequeue operation
void dequeue()
{
    struct node *temp;

    if(front == NULL)
    {
        printf("Queue Underflow\n");
        return;
    }

    temp = front;
    printf("Deleted element: %d\n", front->data);

    front = front->next;

    if(front == NULL)
        rear = NULL;

    free(temp);
}

// Display queue elements
void display()
{
    struct node *temp;

    if(front == NULL)
    {
        printf("Queue is empty\n");
        return;
    }

    temp = front;
    printf("Queue elements: ");

    while(temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    printf("\n");
}
