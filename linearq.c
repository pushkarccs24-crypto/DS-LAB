#include <stdio.h>

#define MAX 5

int que[MAX];
int front = -1;
int rear = -1;


void insert(int item)
{
    if (rear == MAX - 1)
    {
        printf("Queue is full\n");
    }
    else
    {
        if (front == -1)
            front = 0;

        rear++;
        que[rear] = item;
        printf("Inserted %d\n", item);
    }
}


void pop()
{
    if (front == -1 || front > rear)
    {
        printf("Queue is empty\n");
    }
    else
    {
        printf("Popped element is %d\n", que[front]);
        front++;
    }
}


void display()
{
    if (front == -1 || front > rear)
    {
        printf("Queue is empty\n");
    }
    else
    {
        printf("Queue elements: ");
        for (int i = front; i <= rear; i++)
        {
            printf("%d ", que[i]);
        }
        printf("\n");
    }
}

int main()
{
    int n, item;

    printf("Enter the no of elements u want to insert: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        printf("Enter the element to be inserted: ");
        scanf("%d", &item);
        insert(item);
    }

    printf("\nQueue before popping\n");
    display();

    pop();

    printf("\nQueue after popping one element\n");
    display();

    return 0;
}
