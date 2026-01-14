#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *link;
};

void Traversal(struct node* ptr) {
    // Traversal
    while(ptr != NULL) {
        printf("%d-->",ptr->data);
        ptr = ptr->link;
    }
}

int main() {
    struct node *head = malloc(sizeof(struct node));
    struct node *second = malloc(sizeof(struct node));
    struct node *third = malloc(sizeof(struct node));
    
    // link 1st and 2nd node
    head->data = 7;
    head->link = second;

    // link 2nd and 3rd node
    second->data = 2;
    second->link = third;

    // link 3rd and Null
    third->data = 22;
    third->link = NULL;

    Traversal(head);
    return 0;
}