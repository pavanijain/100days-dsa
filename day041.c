#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct Node {
    int data;
    struct Node* next;
};


struct Queue {
    struct Node *front, *rear;
};


void initQueue(struct Queue* q) {
    q->front = q->rear = NULL;
}


void enqueue(struct Queue* q, int value) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = value;
    temp->next = NULL;

    if (q->rear == NULL) {
        q->front = q->rear = temp;
        return;
    }
    q->rear->next = temp;
    q->rear = temp;
}

// Dequeue operation
int dequeue(struct Queue* q) {
    if (q->front == NULL) {
        return -1; // Empty queue
    }

    struct Node* temp = q->front;
    int value = temp->data;
    q->front = q->front->next;

    if (q->front == NULL)
        q->rear = NULL;

    free(temp);
    return value;
}

int main() {
    int N;
    scanf("%d", &N);

    struct Queue q;
    initQueue(&q);

    for (int i = 0; i < N; i++) {
        char op[10];
        scanf("%s", op);

        if (strcmp(op, "ENQUEUE") == 0) {
            int x;
            scanf("%d", &x);
            enqueue(&q, x);
        } else if (strcmp(op, "DEQUEUE") == 0) {
            int val = dequeue(&q);
            printf("%d\n", val);
        }
    }

    return 0;
}