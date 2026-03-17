#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node* next;
};


struct Queue {
    struct Node *front, *rear;
};


struct StackNode {
    int data;
    struct StackNode* next;
};


void initQueue(struct Queue* q) {
    q->front = q->rear = NULL;
}

// Enqueue operation
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
    if (q->front == NULL)
        return -1;

    struct Node* temp = q->front;
    int value = temp->data;
    q->front = q->front->next;

    if (q->front == NULL)
        q->rear = NULL;

    free(temp);
    return value;
}

// Push onto stack
void push(struct StackNode** top, int value) {
    struct StackNode* temp = (struct StackNode*)malloc(sizeof(struct StackNode));
    temp->data = value;
    temp->next = *top;
    *top = temp;
}

// Pop from stack
int pop(struct StackNode** top) {
    if (*top == NULL)
        return -1;

    struct StackNode* temp = *top;
    int value = temp->data;
    *top = (*top)->next;
    free(temp);
    return value;
}

int main() {
    int N;
    scanf("%d", &N);

    struct Queue q;
    initQueue(&q);


    for (int i = 0; i < N; i++) {
        int x;
        scanf("%d", &x);
        enqueue(&q, x);
    }

    
    struct StackNode* stack = NULL;

   
    while (q.front != NULL) {
        int val = dequeue(&q);
        push(&stack, val);
    }

   
    while (stack != NULL) {
        int val = pop(&stack);
        enqueue(&q, val);
    }


    while (q.front != NULL) {
        printf("%d ", dequeue(&q));
    }
    printf("\n");

    return 0;
}