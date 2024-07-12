#include <stdio.h>
#include <stdlib.h>

struct node {
    int no;
    struct node *next;
};

typedef struct node *NODE;

NODE getnode(void) {
    NODE x;
    x = (NODE)malloc(sizeof(struct node));
    return x;
}

NODE insert_front(NODE first, int item) {
    NODE temp = getnode();
    temp->no = item;
    temp->next = first;
    first = temp;
    return first;
}

NODE insert_rear(NODE first, int item) {
    NODE temp = getnode();
    temp->no = item;
    temp->next = NULL;

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

NODE del_front(NODE first) {
    if (first == NULL) {
        printf("List is empty.\n");
    } else {
        NODE temp = first;
        first = first->next;
        printf("Deleted node: %d\n", temp->no);
        free(temp);
    }
    return first;
}

NODE del_rear(NODE first) {
    if (first == NULL) {
        printf("List is empty.\n");
    } else if (first->next == NULL) {
        printf("Deleted node %d\n", first->no);
        free(first);
        first = NULL;
    } else {
        NODE prev = NULL, cur = first;
        while (cur->next != NULL) {
            prev = cur;
            cur = cur->next;
        }
        printf("Deleted node: %d\n", cur->no);
        free(cur);
        prev->next = NULL;
    }
    return first;
}

void display(NODE first) {
    if (first == NULL) {
        printf("List is empty.\n");
        return;
    }
    NODE cur = first;
    while (cur != NULL) {
        printf("%d -> ", cur->no);
        cur = cur->next;
    }
    printf("NULL\n");
}

void display_reverse(NODE first) {
	int i;
    if (first == NULL) {
        printf("List is empty.\n");
        return;
    }
    NODE cur = first;
    int length = 0;
    while (cur != NULL) {
        length++;
        cur = cur->next;
    }
    int *arr = (int *)malloc(length * sizeof(int));
    cur = first;
    for (i = 0; i < length; i++) {
        arr[i] = cur->no;
        cur = cur->next;
    }

    for (i = length - 1; i >= 0; i--) {
        printf("%d <- ", arr[i]);
    }
    printf("NULL\n");
    
    free(arr);
}

void display_recursive(NODE first) {
    if (first == NULL) {
        printf("NULL\n");
    } else {
        printf("%d -> ", first->no);
        display_recursive(first->next);
    }
}

void display_recursive_reverse(NODE current) {
    if (current == NULL) {
        return;
    }
    display_recursive_reverse(current->next);
    printf("<- %d ", current->no);
}

NODE insert_at_position(NODE first, int position, int item) {
    int i;
    NODE temp = getnode();
    temp->no = item;

    if (position == 1) {
        temp->next = first;
        first = temp;
        return first;
    }

    NODE cur = first;
    for (i = 1; cur != NULL && i < position - 1; i++) {
        cur = cur->next;
    }

    if (cur == NULL) {
        printf("Position out of bounds.\n");
        free(temp);
    } else {
        temp->next = cur->next;
        cur->next = temp;
    }

    return first;
}

NODE delete_at_position(NODE first, int position) {
    int i;
    if (first == NULL) {
        printf("List is empty.\n");
        return first;
    }

    NODE temp;
    if (position == 1) {
        temp = first;
        first = first->next;
        printf("Deleted node: %d\n", temp->no);
        free(temp);
        return first;
    }

    NODE cur = first;
    for (i = 1; cur != NULL && i < position - 1; i++) {
        cur = cur->next;
    }

    if (cur == NULL || cur->next == NULL) {
        printf("Position out of bounds.\n");
    } else {
        temp = cur->next;
        cur->next = cur->next->next;
        printf("Deleted node: %d\n", temp->no);
        free(temp);
    }

    return first;
}

int main() {
    NODE first = NULL;
    int choice, item, position;

    while (1) {
        printf("\n1. Insert Front\n2. Insert Rear\n3. Delete Front\n4. Delete Rear\n5. Display\n6. Display Reverse\n7. Display (Recursive)\n8. Display Reverse (Recursive)\n9. Insert at Position\n10. Delete at Position\n11. Exit\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter item to insert at front: ");
                scanf("%d", &item);
                first = insert_front(first, item);
                break;
            case 2:
                printf("Enter item to insert at rear: ");
                scanf("%d", &item);
                first = insert_rear(first, item);
                break;
            case 3:
                first = del_front(first);
                break;
            case 4:
                first = del_rear(first);
                break;
            case 5:
                printf("Linked List: ");
                display(first);
                break;
            case 6:
                printf("Reverse Linked List: ");
                display_reverse(first);
                break;
            case 7:
                printf("Linked List (Recursive): ");
                display_recursive(first);
                break;
            case 8:
                printf("Reverse Linked List (Recursive): ");
                display_recursive_reverse(first);
                printf("NULL\n");
                break;
            case 9:
                printf("Enter position to insert: ");
                scanf("%d", &position);
                printf("Enter item to insert: ");
                scanf("%d", &item);
                first = insert_at_position(first, position, item);
                break;
            case 10:
                printf("Enter position to delete: ");
                scanf("%d", &position);
                first = delete_at_position(first, position);
                break;
            case 11:
                exit(0);
            default:
                printf("Invalid choice, please try again.\n");
        }
    }

    return 0;
}
