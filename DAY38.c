#include<stdio.h>
#define MAX 5

int deque[MAX];
int front = -1, rear = -1;

void insertFront(int x)
{
    if(front == 0 && rear == MAX-1)
        printf("Deque Overflow\n");

    else if(front == -1)
    {
        front = rear = 0;
        deque[front] = x;
    }

    else if(front == 0)
    {
        front = MAX-1;
        deque[front] = x;
    }

    else
    {
        front--;
        deque[front] = x;
    }
}

void insertRear(int x)
{
    if(front == 0 && rear == MAX-1)
        printf("Deque Overflow\n");

    else if(front == -1)
    {
        front = rear = 0;
        deque[rear] = x;
    }

    else if(rear == MAX-1)
    {
        rear = 0;
        deque[rear] = x;
    }

    else
    {
        rear++;
        deque[rear] = x;
    }
}

void deleteFront()
{
    if(front == -1)
        printf("Deque Underflow\n");

    else if(front == rear)
        front = rear = -1;

    else if(front == MAX-1)
        front = 0;

    else
        front++;
}

void deleteRear()
{
    if(front == -1)
        printf("Deque Underflow\n");

    else if(front == rear)
        front = rear = -1;

    else if(rear == 0)
        rear = MAX-1;

    else
        rear--;
}

void display()
{
    int i = front;

    if(front == -1)
        printf("Deque is empty\n");

    else
    {
        printf("Deque elements:\n");

        while(i != rear)
        {
            printf("%d ", deque[i]);
            i = (i+1)%MAX;
        }

        printf("%d", deque[rear]);
    }
}

int main()
{
    insertRear(10);
    insertRear(20);
    insertFront(5);
    insertRear(30);

    display();

    deleteFront();
    deleteRear();

    printf("\nAfter deletion:\n");
    display();

    return 0;
}
