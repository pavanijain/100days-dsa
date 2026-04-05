#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Create a new node
struct Node* newNode(int val) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = val;
    node->left = node->right = NULL;
    return node;
}

// Search for index of value in inorder array
int search(int inorder[], int start, int end, int value) {
    for (int i = start; i <= end; i++) {
        if (inorder[i] == value) return i;
    }
    return -1;
}

// Recursive function to build tree
struct Node* buildTree(int inorder[], int postorder[], int start, int end, int* postIndex) {
    if (start > end) return NULL;

    // Current node from postorder (root is at end)
    int curr = postorder[*postIndex];
    (*postIndex)--;
    struct Node* node = newNode(curr);

    // If leaf node
    if (start == end) return node;

    // Find position in inorder
    int pos = search(inorder, start, end, curr);

    // Build right subtree first (because postorder is left-right-root)
    node->right = buildTree(inorder, postorder, pos + 1, end, postIndex);
    node->left = buildTree(inorder, postorder, start, pos - 1, postIndex);

    return node;
}

// Preorder traversal
void preorder(struct Node* root) {
    if (root == NULL) return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

int main() {
    int N;
    scanf("%d", &N);

    int inorder[N], postorder[N];
    for (int i = 0; i < N; i++) scanf("%d", &inorder[i]);
    for (int i = 0; i < N; i++) scanf("%d", &postorder[i]);

    int postIndex = N - 1;
    struct Node* root = buildTree(inorder, postorder, 0, N - 1, &postIndex);

    preorder(root);
    return 0;
}