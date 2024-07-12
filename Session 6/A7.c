#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

typedef struct Node* NODE;

NODE createNode(int data) {
    NODE newNode = (NODE)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

NODE insert(NODE first, int item) {
    NODE temp = createNode(item);
    if (first == NULL) {
        first = temp;
    } else {
        NODE cur = first;
        while (cur->next != NULL) {
            cur = cur->next;
        }
        cur->next = temp;
    }
    return first;
}

void display_SLL(NODE first) {
    if (first == NULL) return;

    NODE temp = first;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void convert_CLL(NODE first) {
    if (first == NULL) return;

    NODE temp = first;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = first;
}

void display_CLL(NODE first) {
    if (first == NULL) return;

    NODE temp = first;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != first);
    printf("\n");
}

int main() {
    NODE first = NULL;

    first = insert(first, 1);
    first = insert(first, 2);
    first = insert(first, 3);
    first = insert(first, 4);
    first = insert(first, 5);

    printf("Singly Linked List:\n");
    display_SLL(first);

    convert_CLL(first);

    printf("Circular Linked List:\n");
    display_CLL(first);

    return 0;
}

