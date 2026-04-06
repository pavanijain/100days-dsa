#include <stdio.h>
#include <stdbool.h>

#define MAX 100

int graph[MAX][MAX];
bool visited[MAX];

// DFS function to detect cycle
bool dfs(int node, int parent, int vertices) {
    visited[node] = true;

    for (int i = 0; i < vertices; i++) {
        if (graph[node][i]) {  // if edge exists
            if (!visited[i]) {
                if (dfs(i, node, vertices))
                    return true;
            }
            else if (i != parent) {
                return true; // cycle found
            }
        }
    }
    return false;
}

int main() {
    int vertices, edges;
    int u, v;

    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &vertices, &edges);

    // Initialize graph and visited array
    for (int i = 0; i < vertices; i++) {
        visited[i] = false;
        for (int j = 0; j < vertices; j++) {
            graph[i][j] = 0;
        }
    }

    printf("Enter edges (u v):\n");
    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &u, &v);
        graph[u][v] = 1;
        graph[v][u] = 1; // undirected graph
    }

    bool hasCycle = false;

    for (int i = 0; i < vertices; i++) {
        if (!visited[i]) {
            if (dfs(i, -1, vertices)) {
                hasCycle = true;
                break;
            }
        }
    }

    if (hasCycle)
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}