#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node* head = NULL;

struct node* createNode(int value) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    if(newnode == NULL) {
        printf("No Memory Allocation!\n");
        exit(1);
    }
    newnode->data = value;
    newnode->next = NULL;
    return newnode;
}

void insertBegin(int value) {
    struct node* newnode = createNode(value);
    newnode->next = head;
    head = newnode;
}

void insertAtEnd(int value) {
    struct node* newnode = createNode(value);
    struct node* temp;

    if(head == NULL) {
        head = newnode;
        return;
    }
    temp = head;
    while(temp->next != NULL) temp = temp->next;

    temp->next = newnode;
}

void insetAtPosition(int value, int pos) {
    struct node *newnode = createNode(value);
    if(pos <= 1) {
        insertBegin(value);
        return;
    }
    struct node* temp = head;
    for(int i=0;i<pos-1 && temp != NULL;i++) {
        temp = temp->next;
    }
    if(temp == NULL) {
        printf("Invalid Position!!\n");
        free(newnode);
    } else {
        newnode->next = temp->next;
        temp->next = newnode;
    }
}

void deleteBegin() {
    struct node* temp = head;
    if(head == NULL) {
        printf("The Link List is Empty!!\n");
        return;
    }
    temp = head;
    head = head->next;
    free(temp);
}

void deleteEnd() {
    struct node* temp = head;
    if(head == NULL) {
        printf("Link List is Empty!!\n");
        return;
    }
    if(head->next == NULL) {
        free(head);
        head = NULL;
        return;
    }
    while(temp->next->next != NULL) temp = temp->next;
    free(temp->next);
    temp->next = NULL;
}

void deletePosition(int pos) {
    struct node* prev;
    struct node* temp = head;
    if(head == NULL || pos < 1) {
        printf("Invalid Operation!!\n");
        return;
    }
    if(pos == 1) {
        deleteBegin();
        return;
    }

    for(int i=0;i<pos && temp != NULL;i++) {
        prev = temp;
        temp = temp->next;
    }
    if(temp == NULL) {
        printf("Invalid Position!!\n");
    } else {
        prev->next = temp->next;
        free(temp);
    }
}

void searchElement(int key) {
    struct node* temp = head;
    int pos = 1;
    while(temp != NULL) {
        if(temp->data == key) {
            printf("Element Found at Position: %d\n",pos);
            return;
        }
        temp = temp->next;
        pos++;
    }
    printf("Element Not Found\n");
}

int countNodes() {
    int count = 0;
    struct node* temp = head;
    while(temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

void display() {
    struct node* temp = head;
    printf("------------LINK LIST------------\n");
    while(temp != NULL) {
        printf("%d --> ",temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    int choice,value,key,pos;
    while (1) {
        printf("\n=================================== Singly Linked List ===================================\n");
        printf("1. Insert at Beginning\t2. Insert at End\n");
        printf("3. Insert at Specific Position\t4. Delete from Beginning\t5. Delete from End\n");
        printf("6. Delete from Specific Position\t7. Search Element\t8. Count Nodes\t9. Exit\n");
        printf("==========================================================================================\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                insertBegin(value);
                break;

            case 2:
                printf("Enter value: ");
                scanf("%d", &value);
                insertAtEnd(value);
                break;

            case 3:
                printf("Enter value: ");
                scanf("%d", &value);
                printf("Enter position: ");
                scanf("%d", &pos);
                insetAtPosition(value, pos);
                break;

            case 4:
                deleteBegin();
                break;

            case 5:
                deleteEnd();
                break;

            case 6:
                printf("Enter position: ");
                scanf("%d", &pos);
                deletePosition(pos);
                break;

            case 7:
                printf("Enter element to search: ");
                scanf("%d", &key);
                searchElement(key);
                break;

            case 8:
                printf("Total nodes = %d\n", countNodes());
                break;

            case 9:
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
        display();
    }

    return 0;
}