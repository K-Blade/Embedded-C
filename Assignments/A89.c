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

NODE insert_at_pos(NODE first, int position, int item) {
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

NODE delete_at_pos(NODE first, int position) {
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

NODE sorted_lists(NODE a, NODE b) {
    if (a == NULL) return b;
    if (b == NULL) return a;

    NODE result = NULL;
    if (a->no <= b->no) {
        result = a;
        result->next = sorted_lists(a->next, b);
    } else {
        result = b;
        result->next = sorted_lists(a, b->next);
    }
    return result;
}

void split_list(NODE source, NODE *front_ref, NODE *back_ref) {
    NODE fast;
    NODE slow;
    slow = source;
    fast = source->next;

    while (fast != NULL) {
        fast = fast->next;
        if (fast != NULL) {
            slow = slow->next;
            fast = fast->next;
        }
    }

    *front_ref = source;
    *back_ref = slow->next;
    slow->next = NULL;
}

NODE sort(NODE head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }

    NODE a;
    NODE b;

    split_list(head, &a, &b);

    a = sort(a);
    b = sort(b);

    return sorted_lists(a, b);
}

int main() {
    NODE first = NULL;
    int choice, item, position;

    while (1) {
        printf("\n1. Insert at Position\n2. Delete at Position\n3. Display\n4. Sort\n5. Exit\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter position to insert: ");
                scanf("%d", &position);
                printf("Enter item to insert: ");
                scanf("%d", &item);
                first = insert_at_pos(first, position, item);
                break;
            case 2:
                printf("Enter position to delete: ");
                scanf("%d", &position);
                first = delete_at_pos(first, position);
                break;
            case 3:
                printf("Linked List: ");
                display(first);
                break;
            case 4:
                first = sort(first);
                printf("Sorted Linked List: ");
                display(first);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice, please try again.\n");
        }
    }

    return 0;
}

