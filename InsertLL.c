#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node * next;
};

void Traversal(struct node* ptr) {
    while(ptr != NULL) {
        printf("%d-->",ptr->data);
        ptr = ptr->next;
    }
    printf("NULL\n");
}

struct node* insertAtBegining(struct node* head, int data) {
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->next = head;
    ptr->data = data;
    return ptr;
}

struct node* insertAtIndex(struct node* head, int data,int index) {
    struct node* ptr = (struct node *)malloc(sizeof(struct node));
    struct node *p= head;
    int i=0;
    while(i != index-1) {
        p = p->next;
        i++;
    }
    ptr->data = data;
    ptr->next = p->next;
    p->next = ptr;

    return head;
}

struct node* insertAtEnd(struct node* head, int data){
    struct node* ptr = (struct node *)malloc(sizeof(struct node));
    struct node *p= head;
    ptr->data = data;
    while(p->next != NULL) {
        p = p->next;
    }
    p->next = ptr;  
    ptr->next = NULL;
    return head;
}

struct node* Delete(struct node* head) {
    struct node* temp = head;
    while(temp != NULL) {
        temp = temp->next;
        free(head);
        head = temp;
    }
    return head;
}

int main() {
    struct node *head = malloc(sizeof(struct node));
    struct node *second = malloc(sizeof(struct node));
    struct node *third = malloc(sizeof(struct node));
    struct node *fourth = malloc(sizeof(struct node));
    
    // next 1st and 2nd node
    head->data = 7;
    head->next = second;

    // next 2nd and 3rd node
    second->data = 2;
    second->next = third;

    // next 3rd and 4th
    third->data = 22;
    third->next = fourth;

    // next 4th and Null
    fourth->data = 89;
    fourth->next = NULL;

    head = insertAtBegining(head,76);
    head = insertAtIndex(head,45,2);
    head = insertAtEnd(head, 64);
    Traversal(head);

    printf("\nAfter delete whole LinkList THe LinkList is: ");
    head = Delete(head);
    Traversal(head);

    return 0;
}