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
    newnode->next = NULL;
    newnode->prev = NULL;
    return newnode;
}

void insertAtBegining(int value) {
    struct node* newnode = createnode(value);
    if(head == NULL) {
        head = newnode;
        return;
    }
    newnode->next = head;
    head->prev = newnode;
    head = newnode;
}

void insertAtEnd(int value) {
    struct node* newnode = createnode(value);
    if(head == NULL) {
        head = newnode;
        return;
    }
    struct node* curr = head;
    while(curr->next != NULL) 
        curr = curr->next;
    
    curr->next = newnode;
    newnode->prev = curr;
}

void insertAtAnyPosition(int value, int index) {
    if (index <= 1) {
        insertAtBegining(value);
        return;
    }

    struct node* newnode = createnode(value);
    struct node* curr = head;
    int i = 1;

    while (curr != NULL && i < index - 1) {
        curr = curr->next;
        i++;
    }

    if (curr == NULL) {
        printf("Invalid index! Inserting at end.\n");
        insertAtEnd(value);
        return;
    }

    newnode->next = curr->next;
    newnode->prev = curr;

    if (curr->next != NULL)
        curr->next->prev = newnode;

    curr->next = newnode;
}

void deleteAtBeginning() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct node* temp = head;
    head = head->next;
    if (head != NULL)
        head->prev = NULL;
    free(temp);
}

void deleteAtEnd() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct node* curr = head;
    while (curr->next != NULL)
        curr = curr->next;

    if (curr->prev != NULL)
        curr->prev->next = NULL;
    else
        head = NULL;

    free(curr);
}

void deleteAtAnyPosition(int index) {
    if (index <= 1) {
        deleteAtBeginning();
        return;
    }

    struct node* curr = head;
    int i = 1;

    while (curr != NULL && i < index) {
        curr = curr->next;
        i++;
    }

    if (curr == NULL) {
        printf("Invalid index!\n");
        return;
    }

    if (curr->prev != NULL)
        curr->prev->next = curr->next;

    if (curr->next != NULL)
        curr->next->prev = curr->prev;

    free(curr);
}

void ForwardTraversal() {
    struct node* curr = head;
    printf("-------Forward Traversal-------\n");
    while(curr != NULL) {
        printf("%d\t",curr->data);
        curr = curr->next;
    }
}


void BackwardTraversal() {
    if (head == NULL) return;

    struct node* curr = head;

    while (curr->next != NULL)
        curr = curr->next;

    printf("\n------ Backward Traversal ------\n");
    while (curr != NULL) {
        printf("%d\t ", curr->data);
        curr = curr->prev;
    }
    printf("\n");
}

int main() {
    int choice,value,index;
    
    printf("----------Doubly Link List MENU----------\n");
        printf("1. Insert At Begining\n2. Insert At End\n3. Insert At any Position\n4. Delete At Begining\n5. Delete At End\n6. Delete At any Position\n7. EXIT\n");
    while(1) {
        printf("Enetr your choice: ");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            printf("Enter the value");
            scanf("%d",&value);
            insertAtBegining(value);
            break;
        case 2:
            printf("Enter the value: ");
            scanf("%d",&value);
            insertAtEnd(value);
            break;
        case 3:
            printf("Enter the value: ");
            scanf("%d",&value);
            printf("Enetr the Index: ");
            scanf("%d",&index);
            insertAtAnyPosition(value,index);
            break;
        case 4:
            deleteAtBeginning();
            break;
        case 5:
            deleteAtEnd();
            break;
        case 6:
            printf("Enter index(position): ");
            scanf("%d", &index);
            deleteAtAnyPosition(index);
            break;
        case 7:
            exit(0);
        default:
            printf("Invallid Input Enetr a valid one!!");
        }
        ForwardTraversal();
        BackwardTraversal();
    }
    return 0;
}