#include <bits/stdc++.h>
using namespace std;

void dijkstra(int n, vector<vector<pair<int,int>>> &adj, int src) {
    vector<int> dist(n+1, INT_MAX);
    dist[src] = 0;

    // Min-heap: (distance, node)
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0, src});

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();

        if (d > dist[u]) continue; // skip outdated entry

        for (auto [v, w] : adj[u]) {
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }

    // Print distances (1-indexed vertices in input)
    for (int i = 1; i <= n; i++) {
        if (dist[i] == INT_MAX) cout << -1 << " ";
        else cout << dist[i] << " ";
    }
    cout << "\n";
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<pair<int,int>>> adj(n+1);

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w}); // remove if graph is directed
    }

    int src;
    cin >> src;

    dijkstra(n, adj, src);

    return 0;
}
