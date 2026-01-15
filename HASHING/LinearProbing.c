#include<stdio.h>
#include<stdlib.h>

#define SIZE 97
#define EMPTY -1

struct node {
    int key;
};

int table[SIZE];

int hash(int key) {
    return key % SIZE;
}

struct node* createNode(int key) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->key = key;
    return newnode;
}

void insert(int key) {
    struct node* newnode = createNode(key);
    int index = hash(newnode->key);
    while(table[index] != EMPTY) 
        index =(index+1) % SIZE;
    table[index] = newnode->key;
}

void search(int key) {
    int index = hash(key), start = index;
    while(table[index] != EMPTY) {
        if(table[index] == key) {
            printf("Key Found\n");
            return;
        }
        index = (index+1) % SIZE;
        if(index == start) break;;
    }
    printf("Key not Found\n");
}

void display() {
    printf("\nHash Table:\n");
    for (int i = 0; i < SIZE; i++) {
        if (table[i] == EMPTY)
            printf("%d : EMPTY\n", i);
        else
            printf("%d : %d\n", i, table[i]);
    }
}

int main() {
    int choice, key;

    for (int i = 0; i < SIZE; i++)
        table[i] = EMPTY;

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
                return 0;
        }
    }
}