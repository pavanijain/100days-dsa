#include <stdio.h>
#include <stdlib.h>
#define MAX 100  

typedef struct {
    int arr[MAX];
    int front;
    int rear;
    int size;
} Deque;


void initDeque(Deque *dq) {
    dq->front = -1;
    dq->rear = -1;
    dq->size = 0;
}


int empty(Deque *dq) {
    return dq->size == 0;
}


int size(Deque *dq) {
    return dq->size;
}

// Push at front
void push_front(Deque *dq, int value) {
    if (dq->size == MAX) {
        printf("Deque is full!\n");
        return;
    }
    if (dq->front == -1) { // first element
        dq->front = dq->rear = 0;
    } else {
        dq->front = (dq->front - 1 + MAX) % MAX;
    }
    dq->arr[dq->front] = value;
    dq->size++;
}

// Push at back
void push_back(Deque *dq, int value) {
    if (dq->size == MAX) {
        printf("Deque is full!\n");
        return;
    }
    if (dq->rear == -1) { // first element
        dq->front = dq->rear = 0;
    } else {
        dq->rear = (dq->rear + 1) % MAX;
    }
    dq->arr[dq->rear] = value;
    dq->size++;
}

// Pop from front
void pop_front(Deque *dq) {
    if (empty(dq)) {
        printf("Deque is empty!\n");
        return;
    }
    printf("Removed %d from front\n", dq->arr[dq->front]);
    dq->front = (dq->front + 1) % MAX;
    dq->size--;
    if (dq->size == 0) dq->front = dq->rear = -1;
}

// Pop from back
void pop_back(Deque *dq) {
    if (empty(dq)) {
        printf("Deque is empty!\n");
        return;
    }
    printf("Removed %d from back\n", dq->arr[dq->rear]);
    dq->rear = (dq->rear - 1 + MAX) % MAX;
    dq->size--;
    if (dq->size == 0) dq->front = dq->rear = -1;
}

// Get front element
int front(Deque *dq) {
    if (empty(dq)) {
        printf("Deque is empty!\n");
        return -1;
    }
    return dq->arr[dq->front];
}

// Get back element
int back(Deque *dq) {
    if (empty(dq)) {
        printf("Deque is empty!\n");
        return -1;
    }
    return dq->arr[dq->rear];
}

// Display deque
void display(Deque *dq) {
    if (empty(dq)) {
        printf("Deque is empty!\n");
        return;
    }
    printf("Deque: ");
    int i = dq->front;
    for (int count = 0; count < dq->size; count++) {
        printf("%d ", dq->arr[i]);
        i = (i + 1) % MAX;
    }
    printf("\n");
}

int main() {
    Deque dq;
    initDeque(&dq);

    push_back(&dq, 10);
    push_front(&dq, 20);
    push_back(&dq, 30);
    display(&dq);

    printf("Front: %d\n", front(&dq));
    printf("Back: %d\n", back(&dq));

    pop_front(&dq);
    pop_back(&dq);
    display(&dq);

    printf("Size: %d\n", size(&dq));
    return 0;
}