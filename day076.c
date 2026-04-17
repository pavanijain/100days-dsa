#include <stdlib.h>
#include <string.h>

/**
 * Definition for a Node.
 */
struct Node {
    int val;
    int numNeighbors;
    struct Node** neighbors;
};

// Mapping array
struct Node* visited[101];

// DFS function
struct Node* dfs(struct Node* node) {
    if (node == NULL) return NULL;

    // If already cloned
    if (visited[node->val] != NULL) {
        return visited[node->val];
    }

    // Create clone node
    struct Node* clone = (struct Node*)malloc(sizeof(struct Node));
    clone->val = node->val;
    clone->numNeighbors = node->numNeighbors;
    clone->neighbors = (struct Node**)malloc(sizeof(struct Node*) * node->numNeighbors);

    // Store in visited
    visited[node->val] = clone;

    // Clone neighbors
    for (int i = 0; i < node->numNeighbors; i++) {
        clone->neighbors[i] = dfs(node->neighbors[i]);
    }

    return clone;
}

// Main function
struct Node *cloneGraph(struct Node *s) {
    if (s == NULL) return NULL;

    // Initialize visited array
    memset(visited, 0, sizeof(visited));

    return dfs(s);
}