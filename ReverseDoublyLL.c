#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node * prev;
    struct node * next;
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


void ReverseLL() {
    if(head == NULL) return;

    struct node* current = head;
    struct node* temp = NULL;

    while (current != NULL) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;

        current = current->prev;
    }

    if (temp != NULL)
        head = temp->prev;
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
    int n,value;
    printf("How many nodes do you want? ");
    scanf("%d", &n);
    printf("Enter %d values:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        insertAtBegining(value);
    }
    ForwardTraversal();
    BackwardTraversal();
    printf("-------The reverse of the Link List is-------\n");
    ReverseLL();
    ForwardTraversal();
    BackwardTraversal();

    return 0;
}