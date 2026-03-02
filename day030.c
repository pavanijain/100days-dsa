#include <stdio.h>
#include <stdlib.h>


struct Node {
    int coeff;
    int exp;
    struct Node* next;
};

struct Node* createNode(int c, int e) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->coeff = c;
    newNode->exp = e;
    newNode->next = NULL;
    return newNode;
}


void insert(struct Node** head, int c, int e) {
    struct Node* temp = createNode(c, e);

    if (*head == NULL) {
        *head = temp;
        return;
    }

    struct Node* p = *head;
    while (p->next != NULL)
        p = p->next;

    p->next = temp;
}

// Print polynomial
void printPolynomial(struct Node* head) {
    while (head != NULL) {
        if (head->exp == 0)
            printf("%d", head->coeff);
        else if (head->exp == 1)
            printf("%dx", head->coeff);
        else
            printf("%dx^%d", head->coeff, head->exp);

        if (head->next != NULL)
            printf(" + ");

        head = head->next;
    }
}

int main() {
    int n, c, e;
    struct Node* poly = NULL;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d %d", &c, &e);
        insert(&poly, c, e);
    }

    printPolynomial(poly);

    return 0;
}