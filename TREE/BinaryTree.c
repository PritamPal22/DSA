#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node* left;
    struct node* right;
};

struct node* createnode(int value) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = value;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

void inorder(struct node* root) {
    if(root != NULL) {
        inorder(root->left);
        printf("%d  ",root->data);
        inorder(root->right);
    }
}

void preorder(struct node* root) {
    if(root != NULL) {
        printf("%d  ",root->data);
        inorder(root->left);
        inorder(root->right);
    }
}

void postorder(struct node* root) {
    if(root != NULL) {
        inorder(root->left);
        inorder(root->right);
        printf("%d  ",root->data);
    }
}

int main() {
    struct node *root = NULL, *temp;
    int choice, value;
    do {
        printf("\n--- Binary Tree Menu ---\n");
        printf("1. Create Root\n");
        printf("2. Insert Left Child of Root\t3. Insert Right Child of Root\n");
        printf("4. Inorder Traversal\t5. Preorder Traversal\t6. Postorder Traversal\n");
        printf("7. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:
                if (root == NULL) {
                    printf("Enter root value: ");
                    scanf("%d", &value);
                    root = createNode(value);
                } else {
                    printf("Root already exists");
                }
                break;
            case 2:
                if (root != NULL) {
                    printf("Enter left child value: ");
                    scanf("%d", &value);
                    root->left = createNode(value);
                } else {
                    printf("Create root first");
                }
                break;
            case 3:
                if (root != NULL) {
                    printf("Enter right child value: ");
                    scanf("%d", &value);
                    root->right = createNode(value);
                } else {
                    printf("Create root first");
                }
                break;
            case 4:
                printf("Inorder Traversal: ");
                inorder(root);
                break;
            case 5:
                printf("Preorder Traversal: ");
                preorder(root);
                break;
            case 6:
                printf("Postorder Traversal: ");
                postorder(root);
                break;
            case 7:
                printf("Exiting program");
                break;
            default:
                printf("Invalid choice");
        }

    } while (choice != 7);

    return 0;
}