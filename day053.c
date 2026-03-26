#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};


struct Node* newNode(int val) {
    if (val == -1) return NULL;
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = val;
    node->left = node->right = NULL;
    return node;
}


struct Node* buildTree(int arr[], int n) {
    if (n == 0) return NULL;
    struct Node* nodes[n];
    for (int i = 0; i < n; i++) {
        nodes[i] = newNode(arr[i]);
    }
    for (int i = 0; i < n; i++) {
        if (nodes[i] != NULL) {
            int leftIndex = 2 * i + 1;
            int rightIndex = 2 * i + 2;
            if (leftIndex < n) nodes[i]->left = nodes[leftIndex];
            if (rightIndex < n) nodes[i]->right = nodes[rightIndex];
        }
    }
    return nodes[0];
}

// Structure for queue (BFS)
struct QNode {
    struct Node* node;
    int hd; // horizontal distance
    struct QNode* next;
};

struct QNode* newQNode(struct Node* node, int hd) {
    struct QNode* q = (struct QNode*)malloc(sizeof(struct QNode));
    q->node = node;
    q->hd = hd;
    q->next = NULL;
    return q;
}

// Simple queue implementation
struct Queue {
    struct QNode* front;
    struct QNode* rear;
};

void enqueue(struct Queue* q, struct Node* node, int hd) {
    struct QNode* temp = newQNode(node, hd);
    if (q->rear == NULL) {
        q->front = q->rear = temp;
        return;
    }
    q->rear->next = temp;
    q->rear = temp;
}

struct QNode* dequeue(struct Queue* q) {
    if (q->front == NULL) return NULL;
    struct QNode* temp = q->front;
    q->front = q->front->next;
    if (q->front == NULL) q->rear = NULL;
    return temp;
}

int isEmpty(struct Queue* q) {
    return q->front == NULL;
}

// Map structure for storing vertical order
struct MapNode {
    int hd;
    int values[100];
    int count;
    struct MapNode* next;
};

struct MapNode* findOrCreate(struct MapNode** head, int hd) {
    struct MapNode* temp = *head;
    while (temp) {
        if (temp->hd == hd) return temp;
        temp = temp->next;
    }
    struct MapNode* newNode = (struct MapNode*)malloc(sizeof(struct MapNode));
    newNode->hd = hd;
    newNode->count = 0;
    newNode->next = *head;
    *head = newNode;
    return newNode;
}

// Print vertical order
void verticalOrder(struct Node* root) {
    if (root == NULL) return;

    struct Queue q = {NULL, NULL};
    enqueue(&q, root, 0);

    struct MapNode* map = NULL;

    int minHD = 0, maxHD = 0;

    while (!isEmpty(&q)) {
        struct QNode* temp = dequeue(&q);
        struct Node* node = temp->node;
        int hd = temp->hd;
        free(temp);

        struct MapNode* m = findOrCreate(&map, hd);
        m->values[m->count++] = node->data;

        if (node->left) {
            enqueue(&q, node->left, hd - 1);
            if (hd - 1 < minHD) minHD = hd - 1;
        }
        if (node->right) {
            enqueue(&q, node->right, hd + 1);
            if (hd + 1 > maxHD) maxHD = hd + 1;
        }
    }

    // Print from minHD to maxHD
    for (int hd = minHD; hd <= maxHD; hd++) {
        struct MapNode* temp = map;
        while (temp) {
            if (temp->hd == hd) {
               