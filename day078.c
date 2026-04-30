#include <bits/stdc++.h>
using namespace std;

int primMST(int n, vector<vector<pair<int,int>>> &adj) {
    vector<int> key(n+1, INT_MAX);   // min edge weight to connect
    vector<bool> inMST(n+1, false);  // track included vertices
    key[1] = 0;                      // start from vertex 1

    // Min-heap: (weight, vertex)
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0, 1});

    int totalWeight = 0;

    while (!pq.empty()) {
        int u = pq.top().second;
        int w = pq.top().first;
        pq.pop();

        if (inMST[u]) continue; // already included
        inMST[u] = true;
        totalWeight += w;

        for (auto [v, wt] : adj[u]) {
            if (!inMST[v] && wt < key[v]) {
                key[v] = wt;
                pq.push({key[v], v});
            }
        }
    }

    return totalWeight;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<pair<int,int>>> adj(n+1);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w}); // undirected
    }

    cout << primMST(n, adj) << "\n";
    return 0;
}
