#include <stdio.h>
#include <stdlib.h>

struct node {
    int info;
    struct node *next;
};

//Create a sll
struct node *createsll() {
    struct node *start = NULL, *p,*last;
    int item;
    printf("Enter elements (-999 to stop): ");
    scanf("%d", &item);
    while (item != -999) {
        p = (struct node *)malloc(sizeof(struct node));
        p->info = item;
       if(start==NULL){
        p->next=NULL;
        start=p;
        last=p;
       }
       else{
        p->next=NULL;
        last->next=p;
        last=p;
       }
    scanf("%d", &item);
    }
    return start;
}

// Reversing a sll
struct node *reversesll(struct node *start){
    struct node *temp,*cur;
    cur=NULL;
    while(start!=NULL) {
        temp=start->next;
        start->next=cur;
        cur=start;
        start=temp;
    }
    return cur;
};


// Sort a SLL

struct node *sortsll(struct node *start){
    int t;
    struct node *temp,*cur;
    for(temp=start;temp->next!=NULL;temp=temp->next){
        for(cur=temp->next;cur!=NULL;cur=cur->next){
            if(cur->info<temp->info){
                t=cur->info;
                cur->info=temp->info;
                temp->info=t;
            }
        }
    }
    return start;
};

// Concanetation of SLL

struct node *concanetatesll(struct node *start1,struct node *start2){
    struct node *temp;
    if(start1==NULL){
        printf("First List is empty");
        return start2;
    }
    else if(start2==NULL){
        printf("Second List is empty");
        return start1;
    }
    else{
        temp=start1;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=start2;
        return start1;
    }
};

// Display a sll

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
    struct node *start1 = NULL,*start2=NULL;
    int choice;
    while (1) {
        printf("\n-------- Linked Lists Applications--------\n");
        printf("1. Create SLL\n");
        printf("2. Reverse a Sll\n");
        printf("3. Sort a sll\n");
        printf("4.Concanetate\n");
        printf("5. Display\n");
        printf("6. Exit\n");
        printf("Enter your choice:\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                start1 = createsll();
                start2=createsll();
                break;
            case 2:
                start1=reversesll(start1);
                break;
            case 3:
                start1=sortsll(start1);
                break;
           case 4:
                start1=concanetatesll(start1,start2);
                break;
            case 5:
                display(start1);
                break;
            case 6:
                printf("Exiting...\n");
                exit(0);
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}
