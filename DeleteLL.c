#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node * next;
};

struct node* DeleteFromBegining(struct node *head) {
    struct node* ptr = head;
    head = head->next;
    free(ptr);
    return head;
}

struct node* DeleteFromAnyPosition(struct node *head, int index) {
    struct node *p= head;
    int i=0;
    while(i != index-1) {
        p = p->next;
        i++;
    }
    struct node* q = p->next;
    p->next = q->next;
    free(q);
    return head;
}

struct node* DeleteFromEnd(struct node *head) {
    struct node* p = head;
    struct node* q = head->next;
    while(q->next != NULL) {
        p = p->next;
        q = q->next;
    }
    p->next = NULL;
    free(q);
    return head;
}

void Display(struct node *head) {
    while(head != NULL) {
        printf("%d-->",head->data);
        head=head->next;
    }
}

struct node* insertAtIndex(struct node* head, int data,int index) {

}


int main() {
    struct node *head = malloc(sizeof(struct node));
    struct node *second = malloc(sizeof(struct node));
    struct node *third = malloc(sizeof(struct node));
    struct node *fourth = malloc(sizeof(struct node));
    struct node *fifth = malloc(sizeof(struct node));
    struct node *sixth = malloc(sizeof(struct node));

    
    // next 1st and 2nd node
    head->data = 7;
    head->next = second;

    // next 2nd and 3rd node
    second->data = 2;
    second->next = third;

    // next 3rd and 4th
    third->data = 22;
    third->next = fourth;

    // next 3rd and 4th
    fourth->data = 69;
    fourth->next = fifth;

    // next 3rd and 4th
    fifth->data = 54;
    fifth->next = sixth;

    // next 4th and Null
    sixth->data = 32;
    sixth->next = NULL;
    
    printf("Before Deletion operation.\n");
    Display(head);
    printf("\nAfter Begining Deletion operation.\n");
    head = DeleteFromBegining(head);
    Display(head);
    printf("\nAfter Begining+AnyPosition Deletion operation.\n");
    head = DeleteFromAnyPosition(head,2);
    Display(head);
    printf("\nAfter Begining+AnyPosition+End Deletion operation.\n");
    head = DeleteFromEnd(head);
    Display(head);

    return 0;
}