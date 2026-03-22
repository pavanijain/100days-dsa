#include <stdio.h>
#include <stdlib.h>


struct Node {
    int val;
    struct Node* left;
    struct Node* right;
};


struct Node* createNode(int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->val = val;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Insert into BST
struct Node* insert(struct Node* root, int val) {
    if (root == NULL) return createNode(val);

    if (val < root->val)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);

    return root;
}

// BST Search function
struct Node* searchBST(struct Node* root, int val) {
    if (root == NULL || root->val == val)
        return root;

    if (val < root->val)
        return searchBST(root->left, val);

    return searchBST(root->right, val);
}

// Inorder traversal (to print subtree)
void inorder(struct Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    printf("%d ", root->val);
    inorder(root->right);
}

// Driver code
int main() {
    struct Node* root = NULL;

    // Example BST
    int arr[] = {4, 2, 7, 1, 3};
    int n = 5;

    for (int i = 0; i < n; i++) {
        root = insert(root, arr[i]);
    }

    int val = 2;

    struct Node* result = searchBST(root, val);

    if (result != NULL) {
        printf("Subtree Inorder: ");
        inorder(result);
    } else {
        printf("Value not found");
    }

    return 0;
}