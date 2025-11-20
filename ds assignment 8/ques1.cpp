// tree_traversals.cpp
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;
    Node(int v): val(v), left(nullptr), right(nullptr) {}
};

// Build tree from level-order input using -1 as null placeholder
Node* buildFromLevelOrder() {
    int n;
    cout << "Enter number of entries in level-order (include -1 for nulls): ";
    cin >> n;
    if (n <= 0) return nullptr;
    vector<int> vals(n);
    for (int i = 0; i < n; ++i) cin >> vals[i];
    if (vals[0] == -1) return nullptr;
    Node* root = new Node(vals[0]);
    queue<Node*> q;
    q.push(root);
    int idx = 1;
    while (!q.empty() && idx < n) {
        Node* cur = q.front(); q.pop();
        if (idx < n && vals[idx] != -1) {
            cur->left = new Node(vals[idx]);
            q.push(cur->left);
        }
        idx++;
        if (idx < n && vals[idx] != -1) {
            cur->right = new Node(vals[idx]);
            q.push(cur->right);
        }
        idx++;
    }
    return root;
}

void preorder(Node* r) {
    if (!r) return;
    cout << r->val << " ";
    preorder(r->left);
    preorder(r->right);
}
void inorder(Node* r) {
    if (!r) return;
    inorder(r->left);
    cout << r->val << " ";
    inorder(r->right);
}
void postorder(Node* r) {
    if (!r) return;
    postorder(r->left);
    postorder(r->right);
    cout << r->val << " ";
}

int main() {
    Node* root = buildFromLevelOrder();
    cout << "Pre-order: ";
    preorder(root);
    cout << "\nIn-order: ";
    inorder(root);
    cout << "\nPost-order: ";
    postorder(root);
    cout << "\n";
    return 0;
}
