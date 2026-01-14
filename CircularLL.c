#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
};
void Traversal(struct node* head) {
    struct node* ptr = head;
    do{
        printf("%d-->",ptr->data);
        ptr = ptr->next;
    } while(ptr != head);
}

struct node* InsertAtBegining(struct node* head, int data) {
    struct node * ptr = (struct node*)malloc(sizeof(struct node));
    ptr->data = data;
    struct node * p = head->next;
    while(p->next != head) {
        p=p->next;
    }
    p->next = ptr;
    ptr->next = head;
    head = ptr;
    return head;
}

struct node* insertAtIndex(struct node* head, int data,int index) {
    struct node * ptr = (struct node*)malloc(sizeof(struct node));
    ptr->data = data;
    ptr->next = NULL;
    struct node * p = head;
    int i = 0;
    while(i != index-1) {
        p = p->next;
        i++;
    }
    ptr->next =p->next;
    p->next = ptr;
    
    return head;
}

struct node* insertAtEnd(struct node* head, int data) {
    struct node * ptr = (struct node*)malloc(sizeof(struct node));
    ptr->data = data;
    ptr->next = NULL;
    struct node * p = head;
    while(p->next != head) {
        p = p->next;
    }
    p->next = ptr;
    ptr->next = head;
    // head = ptr;
    return head;
}
struct node* deleteAtBeginning(struct node* head) {
    if(head == NULL) {
        printf("\nList is empty!");
        return NULL;
    }

    struct node* p = head;
    struct node* ptr = head;

    // move ptr to last node
    while(ptr->next != head) {
        ptr = ptr->next;
    }

    head = head->next;
    ptr->next = head;
    free(p);

    return head;
}

struct node* deleteAtIndex(struct node* head, int index) {
    if(index == 1) {
        return deleteAtBeginning(head);
    }

    struct node* p = head;
    struct node* q = head->next;
    int i = 1;

    while(i < index-1 && q->next != head) {
        p = p->next;
        q = q->next;
        i++;
    }

    p->next = q->next;
    free(q);

    return head;
}

struct node* deleteAtEnd(struct node* head) {
    if(head == NULL) {
        printf("\nList is empty!");
        return NULL;
    }

    struct node* p = head;
    struct node* q = head->next;

    while(q->next != head) {
        p = p->next;
        q = q->next;
    }

    p->next = head;
    free(q);

    return head;
}

int main() {
    struct node *head = malloc(sizeof(struct node));
    struct node *second = malloc(sizeof(struct node));
    struct node *third = malloc(sizeof(struct node));
    struct node *fourth = malloc(sizeof(struct node));
    struct node *fifth = malloc(sizeof(struct node));
    struct node *sixth = malloc(sizeof(struct node));

    
    // next 1st and 2nd node
    head->data = 1;
    head->next = second;

    // next 2nd and 3rd node
    second->data = 2;
    second->next = third;

    // next 3rd and 4th
    third->data = 3;
    third->next = fourth;

    // next 3rd and 4th
    fourth->data = 4;
    fourth->next = fifth;

    // next 3rd and 4th
    fifth->data = 5;
    fifth->next = sixth;

    // next 4th and Null
    sixth->data = 6;
    sixth->next = head;

    printf("Before Insertion operation.\n");
    Traversal(head);
    printf("\nAfter Begining Insertion operation.\n");
    head = InsertAtBegining(head,62);
    Traversal(head);
    printf("\nAfter Begining+AnyPosition Insertion operation.\n");
    head = insertAtIndex(head,54,3);
    Traversal(head);
    printf("\nAfter Begining+AnyPosition+End Insertion operation.\n");
    head = insertAtEnd(head,56);
    Traversal(head);

    return 0;
}