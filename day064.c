#include <stdio.h>
#include <stdlib.h>

#define MAX 100

void bfs(int n, int adj[n][n], int s) {
    int visited[n];
    for (int i = 0; i < n; i++) visited[i] = 0;

    int queue[MAX], front = 0, rear = 0;

    visited[s] = 1;
    queue[rear++] = s;

    while (front < rear) {
        int node = queue[front++];
        printf("%d ", node);

        for (int j = 0; j < n; j++) {
            if (adj[node][j] == 1 && !visited[j]) {
                visited[j] = 1;
                queue[rear++] = j;
            }
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);

    int adj[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]); // adjacency matrix input
        }
    }

    int s;
    scanf("%d", &s);

    bfs(n, adj, s);
    return 0;
}