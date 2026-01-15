#include<stdio.h>
#include<stdlib.h>

#define SIZE 97

struct node {
    int data;
    struct node* next;
};

struct node* table[SIZE];

int hash(int key) {
    return key % SIZE;
}

struct node* createNode(int key) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = key;
    newnode->next = NULL;
    return newnode;
}

void insert(int key) {
    int index = hash(key);
    struct node* newnode = createNode(key);
    newnode->next = table[index];
    table[index] = newnode;
}

void search(int key) {
    int index = hash(key);
    struct node* temp = table[index];
    while(temp) {
        if(temp-> data == key) {
            printf("Key found in index %d\n",index);
            return;
        }
        temp = temp->next;
    }
    printf("Key not Found.\n");
}

void display() {
    for(int i=0;i<SIZE;i++) {
        printf("%d\t");
        struct node* temp = table[i];
        while(temp) {
            printf("%d ->", temp->data);
        }
        printf("NULL\n");
    }
}

int main() {
    int choice, key;

    for (int i = 0; i < SIZE; i++)
        table[i] = NULL;
    while (1) {
        printf("\n1.Insert 2.Search 3.Display 4.Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter key: ");
                scanf("%d", &key);
                insert(key);
                break;
            case 2:
                printf("Enter key: ");
                scanf("%d", &key);
                search(key);
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
        }
    }
}