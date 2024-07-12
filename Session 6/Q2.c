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

void display(NODE first) {
    NODE x = first;
    while (x != NULL) {
        printf("%d -> ", x->no);
        x = x->next;
    }
    printf("NULL\n");
}

NODE insert_rear(NODE first, int item)
{
  NODE temp=getnode();
  NODE cur=first;
  temp->no=item;
  for(;cur->next!=NULL;cur=cur->next);
  cur->next=temp;
  temp->next=NULL;
  return first;
}

NODE del_front(NODE first)
{
  NODE temp=first;
  first=first->next;
  printf("Deleted node %d",temp->no);
  free(temp);
  return first;
}

int main() {
    NODE first = NULL;
    first = insert_front(first, 12);
    first = insert_front(first, 13);
    first = insert_front(first, 14);
    first = insert_front(first, 15);
    first = insert_front(first, 16);
    first = insert_rear(first, 150);
    display(first);
    first = del_front(first);
    printf("\n");
    display(first);

    return 0;
}
