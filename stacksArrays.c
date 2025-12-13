#include <stdio.h>

#define MAX 5

int arr[MAX];
int top = -1;


void push()
{
    int ele;
    if (top == MAX - 1)
    {
        printf("Stack Overflow\n");
    }
    else
    {
        printf("Enter the element to be pushed: ");
        scanf("%d", &ele);
        top++;
        arr[top] = ele;
        printf("Element pushed successfully\n");
    }
}


int pop()
{
    int item;
    if (top == -1)
    {
        printf("Stack Underflow\n");
        return -1;
    }
    else
    {
        item = arr[top];
        top--;
        printf("Element popped successfully\n");
        return item;
    }
}


void display()
{
    if (top == -1)
    {
        printf("Stack Underflow\n");
    }
    else
    {
        printf("Stack elements are:\n");
        for (int i = top; i >= 0; i--)
        {
            printf("%d\n", arr[i]);
        }
    }
}


int main()
{
    int choice;

    while (1)
    {
        printf("\nEnter your choice:");
        printf("\n1. Push");
        printf("\n2. Pop");
        printf("\n3. Display");
        printf("\n4. Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);

        if (choice == 1)
        {
            push();
        }
        else if (choice == 2)
        {
            int popped = pop();
            if (popped != -1)
            {
                printf("Popped element: %d\n", popped);
            }
        }
        else if (choice == 3)
        {
            display();
        }
        else
        {
            break;
        }
    }

    return 0;
}
