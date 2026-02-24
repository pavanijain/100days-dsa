#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

int main() {
    int n, key, i, value;

    struct Node *head = NULL;
    struct Node *temp = NULL;
    struct Node *newnode = NULL;

    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        scanf("%d", &value);

        newnode = (struct Node*)malloc(sizeof(struct Node));
        newnode->data = value;
        newnode->next = NULL;

        if(head == NULL) {
            head = newnode;
            temp = newnode;
        } else {
            temp->next = newnode;
            temp = newnode;
        }
    }

    scanf("%d", &key);

    struct Node *curr = head;
    struct Node *prev = NULL;

    while(curr != NULL) {
        if(curr->data == key) {

            if(prev == NULL) {
                head = curr->next;
            } else {
                prev->next = curr->next;
            }

            free(curr);
            break;
        }

        prev = curr;
        curr = curr->next;
    }

    temp = head;
    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    return 0;
}