#include<stdio.h>
#include<stdlib.h>

int size;
int *linearTable, *quadTable, *doubleTable;

struct node {
    int data;
    struct node* next; 
};
struct node **chainTable;

int hash(int key) {
    return key % size;
}

int hash2(int key) {
    return 1 + (key % (size - 1));
}

void initTables() {
    linearTable = (int*)malloc(size * sizeof(int));
    quadTable = (int*)malloc(size * sizeof(int));
    doubleTable = (int*)malloc(size * sizeof(int));
    chainTable = (struct node**)malloc(size * sizeof(struct node*));

    for(int i=0;i<size;i++) {
        linearTable[i] = -1;
        quadTable[i] = -1;
        doubleTable[i] = -1;
        chainTable[i] = NULL;
    }
}

//LINEAR PROBING
void linearInsert(int key) {
    int index = hash(key);
    for(int i=0;i<size;i++) {
        int newIndex = (index + i) % size;
        if(linearTable[newIndex] == -1) {
            linearTable[newIndex] = key;
            return;
        }
        printf("Linear Table is Full\n");
    }
}

//QUADRATIC PROBING
void quadraticIndex(int key) {
    int index = hash(key);
    for(int i = 0; i < size; i++) {
        int newIndex = (index + i*i) % size;
        if(quadTable[newIndex] == -1) {
            quadTable[newIndex] = key;
            return;
        }
    }
    printf("Quadratic Table is Full\n");
}

//DOUBLE PROBING
void doubleIndex(int key) {
    int index = hash(key);
    int step = hash2(key);
    for(int i = 0; i < size; i++) {
        int newIndex = (index + i * step) % size;
        if(doubleTable[newIndex] == -1) {
            doubleTable[newIndex] = key;
            return;
        }
    }
    printf("Double hashing table is full\n");
}

//SEPERATE CHAINING
void chainInsert(int key) {
    int index = hash(key);
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = key;
    newnode->next = chainTable[index];
    chainTable[index] = newnode;
}

//DISPLAY
void displayLinear() {
    printf("\nLinear Probing Table:\n");
    for(int i = 0; i < size; i++)
        printf("%d : %d\n", i, linearTable[i]);
}

void displayQuadratic() {
    printf("\nQuadratic Probing Table:\n");
    for(int i = 0; i < size; i++)
        printf("%d : %d\n", i, quadTable[i]);
}

void displayDouble() {
    printf("\nDouble Hashing Table:\n");
    for(int i = 0; i < size; i++)
        printf("%d : %d\n", i, doubleTable[i]);
}

void displayChaining() {
    printf("\nSeparate Chaining Table:\n");
    for(int i = 0; i < size; i++) {
        printf("%d :", i);
        struct node* temp = chainTable[i];
        while(temp != NULL) {
            printf(" %d ->", temp->data);
            temp = temp->next;
        }
        printf(" NULL\n");
    }
}

int main() {
    int choice,key;
    printf("Enter hash table size: ");
    scanf("%d",&size);
    initTables();
        printf("1. Insert (Linear Probing)\t2. Insert (Quadratic Probing)\t3. Insert (Double Hashing)\t4. Insert (Separate Chaining)\t5. Display All Tables\t6. Exit\n");
    while(1) {
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter key: ");
                scanf("%d", &key);
                linearInsert(key);
                displayLinear();
                break;

            case 2:
                printf("Enter key: ");
                scanf("%d", &key);
                quadraticIndex(key);
                displayQuadratic();
                break;

            case 3:
                printf("Enter key: ");
                scanf("%d", &key);
                doubleIndex(key);
                displayDouble();
                break;

            case 4:
                printf("Enter key: ");
                scanf("%d", &key);
                chainInsert(key);
                displayChaining();
                break;

            case 5:
                displayLinear();
                displayQuadratic();
                displayDouble();
                displayChaining();
                break;

            case 6:
                exit(0);

            default:
                printf("Invalid choice!! Enter a valid one!!\n");
        }
    }
    return 0;
}