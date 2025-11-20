#include <bits/stdc++.h>
using namespace std;

// ------------------ DSU for Kruskal ------------------
struct DSU {
    vector<int> parent, rankv;
    DSU(int n) {
        parent.resize(n);
        rankv.assign(n, 0);
        for (int i = 0; i < n; i++) parent[i] = i;
    }
    int findp(int x) {
        if (parent[x] == x) return x;
        return parent[x] = findp(parent[x]);
    }
    void unite(int a, int b) {
        a = findp(a); b = findp(b);
        if (a != b) {
            if (rankv[a] < rankv[b]) swap(a, b);
            parent[b] = a;
            if (rankv[a] == rankv[b]) rankv[a]++;
        }
    }
};

// ------------------ KRUSKAL ------------------
void kruskal(int n, vector<tuple<int,int,int>> &edges) {
    sort(edges.begin(), edges.end()); 
    DSU d(n);
    int total = 0;

    cout << "Kruskal MST edges:\n";

    for (auto &t : edges) {
        int w, u, v;
        tie(w, u, v) = t;
        if (d.findp(u) != d.findp(v)) {
            d.unite(u, v);
            total += w;
            cout << u << " - " << v << " (w=" << w << ")\n";
        }
    }

    cout << "Total Weight = " << total << "\n";
}

// ------------------ PRIM ------------------
void prim(int n, vector<vector<pair<int,int>>> &adj) {
    vector<int> key(n, 1e9), parent(n, -1), inMST(n, 0);
    key[0] = 0;

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0, 0});

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        inMST[u] = 1;

        for (auto &p : adj[u]) {
            int v = p.first, w = p.second;
            if (!inMST[v] && w < key[v]) {
                key[v] = w;
                parent[v] = u;
                pq.push({key[v], v});
            }
        }
    }

    int total = 0;
    cout << "Prim MST edges:\n";
    for (int i = 1; i < n; i++) {
        cout << parent[i] << " - " << i << " (w=" << key[i] << ")\n";
        total += key[i];
    }
    cout << "Total Weight = " << total << "\n";
}

int main() {
    int n, e;
    cout << "Enter number of vertices: ";
    cin >> n;
    cout << "Enter number of edges: ";
    cin >> e;

    vector<tuple<int,int,int>> edges;
    vector<vector<pair<int,int>>> adj(n);

    cout << "Enter edges (u v w):\n";
    for (int i = 0; i < e; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({w, u, v});
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    while (true) {
        cout << "\nMENU:\n1. Kruskal MST\n2. Prim MST\n3. Exit\nChoice: ";
        int ch; cin >> ch;

        if (ch == 1) kruskal(n, edges);
        else if (ch == 2) prim(n, adj);
        else break;
    }

    return 0;
}
