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
    struct node *p; 
    p= (struct node *)malloc(sizeof(struct node));
    p->info = item;
    if(start==NULL){
        p->next=NULL;
        start=p;
    }
    else{
        p->next = start;
        start = p;
    }
    return start;
}

struct node *insertsllend(struct node *start, int item) {
    struct node *p; 
    p= (struct node *)malloc(sizeof(struct node));
    p->info = item;
    if (start == NULL) {
        p->next = NULL;
        start = p;
    } else {
        struct node *temp = start;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = p;
        p->next=NULL;
    }
    return start;
}

struct node* insertAtPos(struct node* start, int item, int pos) {

    if (pos == 1) {
        return insertsllbeg(start, item);
    }

    struct node* temp = start;
    struct node* p = (struct node*)malloc(sizeof(struct node));
    p->info = item;

    for (int i = 1; i < pos - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Invalid position\n");
        return start;
    }

    if (temp->next == NULL) {
        return insertsllend(start, item);
    }

    p->next = temp->next;
    temp->next = p;
    return start;
}

struct node *deletesllbeg(struct node *start){
    struct node *temp;
    if(start==NULL) printf("Linked List is empty");
    else if(start->next==NULL){
        temp=start;
        printf("The deleted element is:%d",temp->info);
        start=NULL;
        free(temp);
    }
    else{
        temp=start;
        printf("The deleted element is:%d",temp->info);
        start=start->next;
        free(temp);

    }
    return start;
}


struct node *deletesllend(struct node *start){
    struct node *temp,*follow;
    if(start==NULL) printf("Linked List is empty");
    else if(start->next==NULL){
        temp=start;
        printf("The deleted element is:%d",temp->info);
        start=NULL;
        free(temp);
    }
    else{
        temp=start;
        while(temp->next!=NULL){
            follow=temp;
            temp=temp->next;
        }
        printf("The deleted element is:%d",temp->info);
        follow->next=NULL;
        free(temp);
    }
    return start;
}

struct node *deletesllmid(struct node *start,int elem){
    struct node *temp,*follow;
    if(start==NULL) printf("Linked List is empty");
    else if(start->info==elem){
        temp=start;
        printf("Deleted element is:%d",temp->info);
        start=temp->next;
        free(temp);
    }
    else{
        temp=start;
       while(temp != NULL && temp->info != elem){
            follow=temp;
            temp=temp->next;
        }
        if(temp==NULL) printf("Element does not exist");
        else{
            follow->next=temp->next;
            printf("Deleted element is:%d",temp->info);
            free(temp);
        }
    }
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
        printf("5. Delete at beginning\n");
        printf("6. Delete at end\n");
        printf("7.Delete the given element\n");
        printf("8. Display\n");
        printf("9. Exit\n");
        printf("Enter your choice:\n");
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
                start=deletesllbeg(start);
                break;
            case 6:
                start=deletesllend(start);
                break;
            case 7:
                printf("Enter item that you want to delete: ");
                scanf("%d", &item);
                start=deletesllmid(start,item);
                break;
            case 8:
                display(start);
                break;
            case 9:
                printf("Exiting...\n");
                exit(0);
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}
