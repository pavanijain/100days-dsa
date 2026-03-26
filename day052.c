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

// Find LCA
struct Node* findLCA(struct Node* root, int n1, int n2) {
    if (root == NULL) return NULL;
    if (root->data == n1 || root->data == n2) return root;

    struct Node* leftLCA = findLCA(root->left, n1, n2);
    struct Node* rightLCA = findLCA(root->right, n1, n2);

    if (leftLCA && rightLCA) return root;
    return (leftLCA != NULL) ? leftLCA : rightLCA;
}

int main() {
    int N;
    scanf("%d", &N);

    int arr[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }

    int n1, n2;
    scanf("%d %d", &n1, &n2);

    struct Node* root = buildTree(arr, N);
    struct Node* lca = findLCA(root, n1, n2);

    if (lca != NULL)
        printf("%d\n", lca->data);
    else
        printf("-1\n"); // if LCA not found
    return 0;
}