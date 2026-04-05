#include <stdio.h>
#include <stdlib.h>

// Define structure for tree node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* newNode(int val) {
    if (val == -1) return NULL; // -1 indicates NULL
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = val;
    node->left = node->right = NULL;
    return node;
}

// Build tree from level-order input
struct Node* buildTree(int arr[], int n) {
    if (n == 0) return NULL;
    struct Node* root = newNode(arr[0]);
    struct Node** queue = (struct Node**)malloc(n * sizeof(struct Node*));
    int front = 0, rear = 0;
    queue[rear++] = root;

    int i = 1;
    while (i < n) {
        struct Node* curr = queue[front++];
        if (curr != NULL) {
            // Left child
            curr->left = newNode(arr[i++]);
            queue[rear++] = curr->left;

            if (i < n) {
                // Right child
                curr->right = newNode(arr[i++]);
                queue[rear++] = curr->right;
            }
        }
    }
    free(queue);
    return root;
}

// Mirror the tree recursively
void mirror(struct Node* root) {
    if (root == NULL) return;
    // Swap left and right
    struct Node* temp = root->left;
    root->left = root->right;
    root->right = temp;

    mirror(root->left);
    mirror(root->right);
}

// Inorder traversal
void inorder(struct Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

int main() {
    int N;
    scanf("%d", &N);
    int arr[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }

    struct Node* root = buildTree(arr, N);
    mirror(root);
    inorder(root);
    return 0;
}