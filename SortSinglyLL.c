#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};
struct node* head = NULL;

struct node* createNode(int value) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = value;
    newnode->next = newnode;
    return newnode;
}

void insertAtBeginning(int value) {
    struct node* newnode = createNode(value);

    if (head == NULL) {
        head = newnode;
        return;
    }

    struct node* temp = head;
    while (temp->next != head)
        temp = temp->next;

    temp->next = newnode;
    newnode->next = head;
    head = newnode;
}

/* ---------- Split Circular List ---------- */
void splitList(struct node* head, struct node** head1, struct node** head2) {
    struct node *slow = head, *fast = head;

    while (fast->next != head && fast->next->next != head) {
        fast = fast->next->next;
        slow = slow->next;
    }

    *head1 = head;
    *head2 = slow->next;

    slow->next = *head1;

    struct node* temp = *head2;
    while (temp->next != head)
        temp = temp->next;
    temp->next = *head2;
}

/* ---------- Merge Two Sorted Linear Lists ---------- */
struct node* merge(struct node* a, struct node* b) {
    if (!a) return b;
    if (!b) return a;

    struct node* result;
    if (a->data <= b->data) {
        result = a;
        result->next = merge(a->next, b);
    } else {
        result = b;
        result->next = merge(a, b->next);
    }
    return result;
}

/* ---------- Convert Circular → Linear ---------- */
void makeLinear(struct node* head) {
    struct node* temp = head;
    while (temp->next != head)
        temp = temp->next;
    temp->next = NULL;
}

/* ---------- Convert Linear → Circular ---------- */
struct node* makeCircular(struct node* head) {
    struct node* temp = head;
    while (temp->next)
        temp = temp->next;
    temp->next = head;
    return head;
}

/* ---------- Merge Sort ---------- */
struct node* mergeSort(struct node* head) {
    if (!head || !head->next)
        return head;

    struct node *head1, *head2;

    splitList(head, &head1, &head2);

    makeLinear(head1);
    makeLinear(head2);

    head1 = mergeSort(head1);
    head2 = mergeSort(head2);

    struct node* merged = merge(head1, head2);
    return makeCircular(merged);
}

/* ---------- Sort Linked List ---------- */
void SortLL() {
    if (head == NULL || head->next == head)
        return;

    head = mergeSort(head);
}

void Traversal() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct node* temp = head;
    printf("Linked List: ");

    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);

    printf("(HEAD)\n");
}

int main() {
    int value, n;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    printf("Enter the values:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        insertAtBeginning(value);
    }

    printf("\nBefore Sorting:\n");
    Traversal();

    SortLL();

    printf("\nAfter Sorting:\n");
    Traversal();

    return 0;
}