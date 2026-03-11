#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

int heap[MAX];
int heapSize = 0;

// Swap helper
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Heapify up (for insert)
void heapifyUp(int index) {
    while (index > 0) {
        int parent = (index - 1) / 2;
        if (heap[parent] > heap[index]) {
            swap(&heap[parent], &heap[index]);
            index = parent;
        } else break;
    }
}

// Heapify down (for extractMin)
void heapifyDown(int index) {
    int left, right, smallest;
    while (1) {
        left = 2 * index + 1;
        right = 2 * index + 2;
        smallest = index;

        if (left < heapSize && heap[left] < heap[smallest])
            smallest = left;
        if (right < heapSize && heap[right] < heap[smallest])
            smallest = right;

        if (smallest != index) {
            swap(&heap[index], &heap[smallest]);
            index = smallest;
        } else break;
    }
}

// Insert operation
void insert(int x) {
    if (heapSize == MAX) {
        printf("-1\n"); // heap full
        return;
    }
    heap[heapSize] = x;
    heapifyUp(heapSize);
    heapSize++;
}

// Peek operation
void peek() {
    if (heapSize == 0) {
        printf("-1\n");
    } else {
        printf("%d\n", heap[0]);
    }
}

// ExtractMin operation
void extractMin() {
    if (heapSize == 0) {
        printf("-1\n");
        return;
    }
    printf("%d\n", heap[0]);
    heap[0] = heap[heapSize - 1];
    heapSize--;
    heapifyDown(0);
}

int main() {
    int N;
    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        char op[20];
        scanf("%s", op);

        if (strcmp(op, "insert") == 0) {
            int x;
            scanf("%d", &x);
            insert(x);
        } else if (strcmp(op, "peek") == 0) {
            peek();
        } else if (strcmp(op, "extractMin") == 0) {
            extractMin();
        }
    }
    return 0;
}