// is_bst.cpp
#include <bits/stdc++.h>
using namespace std;
struct Node { int val; Node* left; Node* right; Node(int v): val(v), left(nullptr), right(nullptr) {} };

Node* buildFromLevelOrder() {
    int n; cout << "Enter number of entries in level-order (include -1 for nulls): "; cin >> n;
    if (n <= 0) return nullptr;
    vector<int> vals(n);
    for (int i = 0; i < n; ++i) cin >> vals[i];
    if (vals[0] == -1) return nullptr;
    Node* root = new Node(vals[0]);
    queue<Node*> q; q.push(root);
    int idx = 1;
    while (!q.empty() && idx < n) {
        Node* cur = q.front(); q.pop();
        if (idx < n && vals[idx] != -1) { cur->left = new Node(vals[idx]); q.push(cur->left); }
        idx++;
        if (idx < n && vals[idx] != -1) { cur->right = new Node(vals[idx]); q.push(cur->right); }
        idx++;
    }
    return root;
}

bool isBSTUtil(Node* node, long long minVal, long long maxVal) {
    if (!node) return true;
    if (node->val <= minVal || node->val >= maxVal) return false;
    return isBSTUtil(node->left, minVal, node->val) && isBSTUtil(node->right, node->val, maxVal);
}

bool isBST(Node* root) {
    return isBSTUtil(root, LLONG_MIN, LLONG_MAX);
}

int main() {
    Node* root = buildFromLevelOrder();
    cout << (isBST(root) ? "Tree IS a BST\n" : "Tree is NOT a BST\n");
    return 0;
}
