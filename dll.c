#include <stdio.h>
#include <stdlib.h>

struct node
{
    int item;
    struct node *prev;
    struct node *next;
};

struct node *start = NULL;

struct node* newNode(int value)
{
    struct node *p = (struct node*)malloc(sizeof(struct node));
    p->item = value;
    p->prev = NULL;
    p->next = NULL;
    return p;
}

void createList()
{
    int n, i, value;
    struct node *p, *pnew;
    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {   printf("Enter value:");
        scanf("%d", &value);
        pnew = newNode(value);

        if(start == NULL)
            start = pnew;
        else
        {
            p = start;
            while(p->next != NULL)
                p = p->next;
            p->next = pnew;
            pnew->prev = p;
        }
    }
}

void insertLeft(int key, int value)
{
    struct node *p = start;
    struct node *pnew;

    while(p != NULL && p->item != key)
        p = p->next;

    if(p == NULL)
        return;

    pnew = newNode(value);
    pnew->next = p;
    pnew->prev = p->prev;

    if(p->prev != NULL)
        p->prev->next = pnew;
    else
        start = pnew;

    p->prev = pnew;
}

void deleteNode(int value)
{
    struct node *p = start;

    while(p != NULL && p->item != value)
        p = p->next;

    if(p == NULL)
        return;

    if(p->prev != NULL)
        p->prev->next = p->next;
    else
        start = p->next;

    if(p->next != NULL)
        p->next->prev = p->prev;

    free(p);
}

void display()
{
    struct node *p = start;
    while(p != NULL)
    {
        printf("%d ", p->item);
        p = p->next;
    }
    printf("\n");
}

int main()
{
    int ch, key, value;

    while(1)
    {   printf("Enter choice:1.Create\n2.Insert at left\n3.Delete\n4.Display\n");
        scanf("%d", &ch);

        if(ch == 1)
            createList();
        else if(ch == 2)
        {   printf("Enter the element to search and value to insert");
            scanf("%d%d", &key, &value);
            insertLeft(key, value);
        }
        else if(ch == 3)
        {   printf("Enter the value to delete");
            scanf("%d", &value);
            deleteNode(value);
        }
        else if(ch == 4)
            display();
        else
            break;
    }
    return 0;
}
