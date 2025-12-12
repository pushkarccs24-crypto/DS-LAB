#include <stdio.h>
#include <stdlib.h>

struct node {
    int info;
    struct node *link;
};

/* ---------------- STACK ---------------- */

struct node *top = NULL;

void push(int x) {
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    if (temp == NULL) {
        printf("Stack Overflow\n");
        return;
    }
    temp->info = x;
    temp->link = top;
    top = temp;
}

int pop() {
    if (top == NULL) {
        printf("Stack Underflow\n");
        return -1;
    }
    struct node *temp = top;
    int x = temp->info;
    top = top->link;
    free(temp);
    return x;
}

void displayStack() {
    struct node *p = top;
    if (p == NULL) {
        printf("Stack Empty\n");
        return;
    }

    printf("Stack: ");
    while (p != NULL) {
        printf("%d ", p->info);
        p = p->link;
    }
    printf("\n");
}

/* ---------------- QUEUE ---------------- */

struct node *front = NULL;
struct node *rear = NULL;

void enqueue(int x) {
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    if (temp == NULL) {
        printf("Queue Overflow\n");
        return;
    }

    temp->info = x;
    temp->link = NULL;

    if (front == NULL)
        front = rear = temp;
    else {
        rear->link = temp;
        rear = temp;
    }
}

int dequeue() {
    if (front == NULL) {
        printf("Queue Underflow\n");
        return -1;
    }

    struct node *temp = front;
    int x = temp->info;

    front = front->link;
    if (front == NULL)
        rear = NULL;

    free(temp);
    return x;
}

void displayQueue() {
    struct node *p = front;
    if (p == NULL) {
        printf("Queue Empty\n");
        return;
    }

    printf("Queue: ");
    while (p != NULL) {
        printf("%d ", p->info);
        p = p->link;
    }
    printf("\n");
}

/* ---------------- MAIN MENU ---------------- */

int main() {
    int choice, subchoice, x;

    while (1) {
        printf("\n----- MAIN MENU -----\n");
        printf("1. Stack Operations\n");
        printf("2. Queue Operations\n");
        printf("3. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {

        case 1:
            while (1) {
                printf("\n--- STACK MENU ---\n");
                printf("1. Push\n");
                printf("2. Pop\n");
                printf("3. Display\n");
                printf("4. Back to Main Menu\n");
                printf("Enter choice: ");
                scanf("%d", &subchoice);

                if (subchoice == 1) {
                    printf("Enter value: ");
                    scanf("%d", &x);
                    push(x);
                }
                else if (subchoice == 2) {
                    int val = pop();
                    if (val != -1)
                        printf("Popped: %d\n", val);
                }
                else if (subchoice == 3) {
                    displayStack();
                }
                else if (subchoice == 4) {
                    break;
                }
                else {
                    printf("Invalid Choice\n");
                }
            }
            break;

        case 2:
            while (1) {
                printf("\n--- QUEUE MENU ---\n");
                printf("1. Enqueue\n");
                printf("2. Dequeue\n");
                printf("3. Display\n");
                printf("4. Back to Main Menu\n");
                printf("Enter choice: ");
                scanf("%d", &subchoice);

                if (subchoice == 1) {
                    printf("Enter value: ");
                    scanf("%d", &x);
                    enqueue(x);
                }
                else if (subchoice == 2) {
                    int val = dequeue();
                    if (val != -1)
                        printf("Dequeued: %d\n", val);
                }
                else if (subchoice == 3) {
                    displayQueue();
                }
                else if (subchoice == 4) {
                    break;
                }
                else {
                    printf("Invalid Choice\n");
                }
            }
            break;

        case 3:
            exit(0);

        default:
            printf("Invalid Choice\n");
        }
    }

    return 0;
}
