#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};


struct Node* newNode(int data) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}


struct Node* insert(struct Node* head, int data) {
    if (head == NULL)
        return newNode(data);

    struct Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode(data);
    return head;
}


struct Node* merge(struct Node* l1, struct Node* l2) {
    struct Node* result = NULL;

    if (l1 == NULL) return l2;
    if (l2 == NULL) return l1;

    if (l1->data < l2->data) {
        result = l1;
        result->next = merge(l1->next, l2);
    } else {
        result = l2;
        result->next = merge(l1, l2->next);
    }

    return result;
}

// Print list
void print(struct Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
}

int main() {
    int n, m, x;
    struct Node *l1 = NULL, *l2 = NULL;

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        l1 = insert(l1, x);
    }

    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &x);
        l2 = insert(l2, x);
    }

    struct Node* merged = merge(l1, l2);
    print(merged);

    return 0;
}