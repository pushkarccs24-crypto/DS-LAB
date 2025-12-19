#include <stdio.h>

#define MAXSIZE 5

int cque[MAXSIZE];
int front = -1;
int rear = -1;


void insert_cque(int item)
{
    if (front == (rear + 1) % MAXSIZE)
    {
        printf("Queue is full\n");
    }
    else if (front == -1)
    {
        front = 0;
        rear = 0;
        cque[rear] = item;
    }
    else
    {
        rear = (rear + 1) % MAXSIZE;
        cque[rear] = item;
    }
}


int delete_cque()
{
    int item;

    if (front == -1)
    {
        printf("Queue is empty\n");
        return -1;
    }

    item = cque[front];

    if (front == rear)
    {
        front = -1;
        rear = -1;
    }
    else
    {
        front = (front + 1) % MAXSIZE;
    }

    return item;
}


void display_cque()
{
    if (front == -1)
    {
        printf("Queue is empty\n");
    }
    else
    {
        int i = front;
        while (i != rear)
        {
            printf("%d ", cque[i]);
            i = (i + 1) % MAXSIZE;
        }
        printf("%d\n", cque[rear]);
    }
}

int main()
{
    int choice, item;

    while (1)
    {
        printf("\nEnter the operation to perform\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter an item: ");
            scanf("%d", &item);
            insert_cque(item);
            break;

        case 2:
            item = delete_cque();
            if (item != -1)
                printf("Deleted item: %d\n", item);
            break;

        case 3:
            display_cque();
            break;

        case 4:
            return 0;

        default:
            printf("Invalid choice, please enter a valid choice\n");
        }
    }
}
