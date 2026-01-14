#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node* createnode(int value) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = value;
    newnode->next = NULL;
    return newnode;
}

void insertEnd(struct node** head,int value) {
    struct node* newnode = createnode(value);

    if(*head == NULL) {
        *head = newnode;
        return ;
    }
    struct node* temp = *head;
    while(temp->next!=NULL)
        temp = temp->next;
    temp->next = newnode;
}

void Display(struct node* head) {
    if(head == NULL) {
        printf("The list is empty!!");
        return ;
    }
    struct node* temp = head;
    while(temp != NULL) {
        printf("%d-->",temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

struct node* Reverse(struct node* head) {
    struct node* prev = NULL;
    struct node* next1 = NULL;
    while(head!=NULL) {
        next1 = head->next;
        head->next = prev;
        prev = head;
        head = next1;
    }
    head = prev;
    return head;
}


int main() {
    struct node* head = NULL;
    int n, value;

    printf("How many nodes do you want? ");
    scanf("%d", &n);

    printf("Enter %d values:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        insertEnd(&head, value);
    }

    printf("\nOriginal Linked List:\n");
    Display(head);

    head = Reverse(head);

    printf("\nReversed Linked List:\n");
    Display(head);

    return 0;
}