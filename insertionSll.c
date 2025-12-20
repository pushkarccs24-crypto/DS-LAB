#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct node {
    int info;
    struct node *next;
};

struct node *createsll() {
    struct node *start = NULL, *p;
    int item;

    printf("Enter elements (-999 to stop): ");
    scanf("%d", &item);

    while (item != -999) {
        p = (struct node *)malloc(sizeof(struct node));
        p->info = item;
        p->next = start;
        start = p;

        scanf("%d", &item);
    }
    return start;
}

struct node *insertsllbeg(struct node *start, int item) {
    struct node *p = (struct node *)malloc(sizeof(struct node));
    p->info = item;
    p->next = start;
    start = p;
    return start;
}

struct node *insertsllend(struct node *start, int item) {
    struct node *p = (struct node *)malloc(sizeof(struct node));
    p->info = item;
    p->next = NULL;

    if (start == NULL) {
        start = p;
    } else {
        struct node *temp = start;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = p;
    }
    return start;
}

struct node* insertAtPos(struct node* start, int item, int pos) {

    if (pos == 1) {
        return insertsllbeg(start, item);
    }

    struct node* temp = start;
    int i;

    for (i = 1; i < pos - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    // if temp becomes NULL → invalid position
    if (temp == NULL) {
        printf("Invalid position\n");
        return start;
    }

    // if inserting after the last node → use your insert-at-end
    if (temp->next == NULL) {
        return insertsllend(start, item);
    }

    // normal middle insertion
    struct node* p = (struct node*)malloc(sizeof(struct node));
    p->info = item;

    p->next = temp->next;
    temp->next = p;

    return start;
}


void display(struct node *start) {
    if (start == NULL) {
        printf("\nList is empty.\n");
        return;
    }

    printf("\nLinked List elements:\n");
    struct node *temp = start;
    while(temp != NULL) {
        printf("%d ", temp->info);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct node *start = NULL;
    int choice, item,pos;
    while (1) {
        printf("\n-------- Linked Lists--------\n");
        printf("1. Create SLL\n");
        printf("2. Insert at beginning\n");
        printf("3. Insert at end\n");
        printf("4.Insert at any position\n");
        printf("5. Display\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                start = createsll();
                break;

            case 2:
                printf("Enter item: ");
                scanf("%d", &item);
                start = insertsllbeg(start, item);
                break;

            case 3:
                printf("Enter item: ");
                scanf("%d", &item);
                start = insertsllend(start, item);
                break;

           case 4:
                printf("Enter item: ");
                scanf("%d", &item);
                printf("Enter position: ");
                scanf("%d", &pos);
                start = insertAtPos(start, item, pos);
                break;
            case 5:
                display(start);
                break;

            case 6:
                printf("Exiting...\n");
                exit(0);

            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}
