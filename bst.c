#include <stdio.h>
#include <stdlib.h>

// Definition of BST node
struct node {
    int data;
    struct node *left;
    struct node *right;
};

// Function to create a new node
struct node* createNode(int item) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = item;
    temp->left = temp->right = NULL;
    return temp;
}

// Function to insert an element into BST
struct node* insert(struct node* root, int item) {
    if (root == NULL)
        return createNode(item);

    if (item < root->data)
        root->left = insert(root->left, item);
    else if (item > root->data)
        root->right = insert(root->right, item);

    return root;
}

// Inorder Traversal
void inorder(struct node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

// Preorder Traversal
void preorder(struct node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

// Postorder Traversal
void postorder(struct node* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

int main() {
    struct node* root = NULL;
    int n, item, choice;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &item);
        root = insert(root, item);
    }

    do {
        printf("\nMenu:\n");
        printf("1. Inorder Traversal\n");
        printf("2. Preorder Traversal\n");
        printf("3. Postorder Traversal\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Inorder Traversal: ");
                inorder(root);
                printf("\n");
                break;

            case 2:
                printf("Preorder Traversal: ");
                preorder(root);
                printf("\n");
                break;

            case 3:
                printf("Postorder Traversal: ");
                postorder(root);
                printf("\n");
                break;

            case 4:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice\n");
        }
    } while (choice != 4);

    return 0;
}
