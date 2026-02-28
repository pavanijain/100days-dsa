#include <stdio.h>
#include <stdlib.h>

typedef struct circularlist {
    int data;
    struct circularlist *nxt;
} node;

int main() {

    node *head = NULL, *temp = NULL, *newnode = NULL;
    int n, i, value;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    if(n <= 0) {
        printf("Invalid number of nodes");
        return 0;
    }

    for(i = 1; i <= n; i++) {

        newnode = (node*)malloc(sizeof(node));

        printf("Enter data for node %d: ", i);
        scanf("%d", &value);

        newnode->data = value;
        newnode->nxt = NULL;

        if(head == NULL) {
            head = newnode;
            temp = newnode;
        }
        else {
            temp->nxt = newnode;
            temp = newnode;
        }
    }


    temp->nxt = head;

   
    node *a = head;

    printf("Circular linked list is:\n");

    do {
        printf("%d -> ", a->data);
        a = a->nxt;
    } while(a != head);

    printf("(back to head)\n");

    return 0;
}