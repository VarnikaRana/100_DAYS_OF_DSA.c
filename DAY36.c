#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *front = NULL;
struct node *rear = NULL;

/* Enqueue operation */
void enqueue(int value)
{
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->data = value;

    if(front == NULL)
    {
        front = rear = temp;
        rear->next = front;
    }
    else
    {
        rear->next = temp;
        rear = temp;
        rear->next = front;
    }
}

/* Dequeue operation */
void dequeue()
{
    struct node *temp;

    if(front == NULL)
    {
        printf("Queue Underflow\n");
        return;
    }

    if(front == rear)
    {
        temp = front;
        printf("Deleted element: %d\n", temp->data);
        front = rear = NULL;
        free(temp);
    }
    else
    {
        temp = front;
        printf("Deleted element: %d\n", temp->data);
        front = front->next;
        rear->next = front;
        free(temp);
    }
}

/* Display elements */
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

    do
    {
        printf("%d ", temp->data);
        temp = temp->next;
    } while(temp != front);

    printf("\n");
}

/* Main function */
int main()
{
    int choice, value;

    while(1)
    {
        printf("\n--- Circular Queue Menu ---\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                enqueue(value);
                break;

            case 2:
                dequeue();
                break;

            case 3:
                display();
                break;

            case 4:
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
