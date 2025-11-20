#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<int> vis;

void dfs(int u) {
    vis[u] = 1;
    cout << u << " ";
    for (int v : adj[u]) {
        if (!vis[v]) dfs(v);
    }
}

int main() {
    int n, e;
    cout << "Enter number of vertices: ";
    cin >> n;
    cout << "Enter number of edges: ";
    cin >> e;

    adj.assign(n, {});
    vis.assign(n, 0);

    cout << "Enter edges (u v):\n";
    for (int i = 0; i < e; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int start;
    cout << "Enter starting vertex for DFS: ";
    cin >> start;

    cout << "DFS Traversal: ";
    dfs(start);

    cout << endl;
    return 0;
}
