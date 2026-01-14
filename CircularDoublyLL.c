#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node* prev;
    struct node* next;
};

struct node* head = NULL;

struct node* createnode(int value) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = value;
    newnode->next = newnode;
    newnode->prev = newnode;
    return newnode;
}

void insertAtBegining(int value) {
    struct node* newnode = createnode(value);

    if (head == NULL) {
        head = newnode;
        return;
    }

    struct node* last = head->prev;

    newnode->next = head;
    newnode->prev = last;
    last->next = newnode;
    head->prev = newnode;

    head = newnode;
}

void insertAtEnd(int value) {
    if (head == NULL) {
        insertAtBegining(value);
        return;
    }

    struct node* newnode = createnode(value);
    struct node* last = head->prev;

    newnode->next = head;
    newnode->prev = last;
    last->next = newnode;
    head->prev = newnode;
}

void insertAtAnyPosition(int value, int index) {
    if (index <= 1) {
        insertAtBegining(value);
        return;
    }

    struct node* newnode = createnode(value);
    struct node* curr = head;
    int i = 1;

    while (i < index - 1 && curr->next != head) {
        curr = curr->next;
        i++;
    }

    newnode->next = curr->next;
    newnode->prev = curr;
    curr->next->prev = newnode;
    curr->next = newnode;
}

void deleteAtBeginning() {
    if (head == NULL) {
        printf("List is Empty.\n");
        return;
    }

    if (head->next == head) {  
        free(head);
        head = NULL;
        return;
    }

    struct node* temp = head;
    struct node* last = head->prev;

    head = head->next;
    head->prev = last;
    last->next = head;

    free(temp);
}

void deleteAtEnd() {
    if (head == NULL) {
        printf("List is Empty.\n");
        return;
    }

    if (head->next == head) {
        free(head);
        head = NULL;
        return;
    }

    struct node* last = head->prev;
    struct node* secondLast = last->prev;

    secondLast->next = head;
    head->prev = secondLast;

    free(last);
}

void deleteAtAnyPosition(int index) {
    if (index <= 1) {
        deleteAtBeginning();
        return;
    }

    if (head == NULL) {
        printf("List is Empty.\n");
        return;
    }

    struct node* curr = head;
    int i = 1;

    while (i < index && curr->next != head) {
        curr = curr->next;
        i++;
    }

    curr->prev->next = curr->next;
    curr->next->prev = curr->prev;

    if (curr == head)
        head = curr->next;

    free(curr);
}

void ForwardTraversal() {
    if (head == NULL) {
        printf("\nList is empty.\n");
        return;
    }

    struct node* curr = head;
    printf("\n----- Forward Traversal -----\n");

    do {
        printf("%d\t", curr->data);
        curr = curr->next;
    } while (curr != head);
}

void BackwardTraversal() {
    if (head == NULL) return;

    struct node* curr = head->prev;

    printf("\n----- Backward Traversal -----\n");
    do {
        printf("%d\t", curr->data);
        curr = curr->prev;
    } while (curr != head->prev);
    printf("\n");
}

int main() {
    int choice, value, index;

    printf("---------- Doubly Circular Linked List MENU ----------\n");
    printf("1. Insert At Beginning\n2. Insert At End\n3. Insert At Position\n4. Delete At Beginning\n5. Delete At End\n6. Delete At Position\n7. EXIT\n");

    while (1) {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                insertAtBegining(value);
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
                scanf("%d", &index);
                insertAtAnyPosition(value, index);
                break;
            case 4:
                deleteAtBeginning();
                break;
            case 5:
                deleteAtEnd();
                break;
            case 6:
                printf("Enter position: ");
                scanf("%d", &index);
                deleteAtAnyPosition(index);
                break;
            case 7:
                exit(0);
            default:
                printf("Invalid Input.\n");
        }

        ForwardTraversal();
        BackwardTraversal();
    }

    return 0;
}
