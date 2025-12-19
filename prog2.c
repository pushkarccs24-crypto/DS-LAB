#include <stdio.h>

#define SIZE 5

int top = -1;
int maxsize = SIZE;
int arr[SIZE];
int stack[SIZE];


void push(int arr[])
{
    if (top == maxsize - 1)
    {
        printf("Stack overflow\n");
    }
    else
    {
        for (int i = 0; i < maxsize; i++)
        {
            top++;
            stack[top] = arr[i];
            printf("Element pushed successfully\n");
        }
    }
}


int pop()
{
    if (top == -1)
    {
        printf("Stack underflow\n");
        return -1;
    }
    else
    {
        return stack[top--];
    }
}

int main()
{
    printf("Enter the elements into the array\n");

    for (int i = 0; i < maxsize; i++)
    {
        printf("Enter element: ");
        scanf("%d", &arr[i]);
    }

    push(arr);

  
    for (int i = 0; i < maxsize; i++)
    {
        arr[i] = pop();
    }

    printf("Reversed array\n");
    for (int i = 0; i < maxsize; i++)
    {
        printf("%d\n", arr[i]);
    }

    return 0;
}
