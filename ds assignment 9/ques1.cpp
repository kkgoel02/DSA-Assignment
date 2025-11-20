#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, e;
    cout << "Enter number of vertices: ";
    cin >> n;
    cout << "Enter number of edges: ";
    cin >> e;

    vector<vector<int>> adj(n);

    cout << "Enter edges (u v):\n";
    for (int i = 0; i < e; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int start;
    cout << "Enter starting vertex for BFS: ";
    cin >> start;

    vector<int> vis(n, 0);
    queue<int> q;

    vis[start] = 1;
    q.push(start);

    cout << "BFS Traversal: ";
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        cout << x << " ";
        for (int nxt : adj[x]) {
            if (!vis[nxt]) {
                vis[nxt] = 1;
                q.push(nxt);
            }
        }
    }
    cout << endl;
    return 0;
}
