#include <stdio.h>
#include <stdlib.h>

#define SIZE 97
#define EMPTY -1

struct Node {
    int key;
};

int table[SIZE];

int h1(int key) {
    return key % SIZE;
}

int h2(int key) {
    return 7 - (key % 7);
}

struct Node* createNode(int key) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->key = key;
    return node;
}

void insert(int key) {
    struct Node* node = createNode(key);
    int index = h1(node->key);
    int step = h2(node->key);

    while (table[index] != EMPTY)
        index = (index + step) % SIZE;

    table[index] = node->key;
}

void search(int key) {
    int index = h1(key);
    int step = h2(key);

    while (table[index] != EMPTY) {
        if (table[index] == key) {
            printf("Key found\n");
            return;
        }
        index = (index + step) % SIZE;
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