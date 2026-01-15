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

struct node* createnode(int key) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->key = key;
    return newnode;
}

void insert(int key) {
    struct node* newnode = createnode(key);
    int i = 0, index;

    while (i < SIZE) {
        index = (hash(newnode->key) + i * i) % SIZE;
        if (table[index] == EMPTY) {
            table[index] = newnode->key;
            return;
        }
        i++;
    }
    printf("Hash table full\n");
}

void search(int key) {
    int i = 0, index;

    while (i < SIZE) {
        index = (hash(key) + i * i) % SIZE;
        if (table[index] == EMPTY)
            break;
        if (table[index] == key) {
            printf("Key found\n");
            return;
        }
        i++;
    }
    printf("Key not found\n");
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