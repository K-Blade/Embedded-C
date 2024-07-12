#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertNode(struct Node** first, int data) {
    struct Node* newNode = createNode(data);
    if (*first == NULL) {
        *first = newNode;
        return;
    }
    struct Node* temp = *first;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void removeDuplicates(struct Node* first) {
    if (first == NULL) return;

    struct Node* current = first;
    struct Node* prev = NULL;
    struct Node* temp;
    struct Node* duplicates;

    while (current != NULL && current->next != NULL) {
        prev = current;
        temp = current->next;

        while (temp != NULL) {
            if (current->data == temp->data) {
                duplicates = temp;
                prev->next = temp->next;
                free(duplicates);
                temp = prev->next;
            } else {
                prev = temp;
                temp = temp->next;
            }
        }
        current = current->next;
    }
}

void printList(struct Node* first) {
    struct Node* temp = first;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* first = NULL;

    insertNode(&first, 10);
    insertNode(&first, 12);
    insertNode(&first, 11);
    insertNode(&first, 11);
    insertNode(&first, 12);
    insertNode(&first, 11);
    insertNode(&first, 10);

    printf("Before removing duplicates:\n");
    printList(first);

    removeDuplicates(first);

    printf("After removing duplicates:\n");
    printList(first);

    return 0;
}

