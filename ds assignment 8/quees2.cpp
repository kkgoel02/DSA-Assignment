// bst_search_minmax_successor_predecessor.cpp
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;
    Node(int v): val(v), left(nullptr), right(nullptr) {}
};

Node* insertBST(Node* root, int x) {
    if (!root) return new Node(x);
    if (x < root->val) root->left = insertBST(root->left, x);
    else if (x > root->val) root->right = insertBST(root->right, x);
    return root;
}

Node* buildBST() {
    int n; cout << "Number of elements to insert: "; cin >> n;
    Node* root = nullptr;
    for (int i = 0; i < n; ++i){ int v; cin >> v; root = insertBST(root, v); }
    return root;
}

// Recursive search
Node* searchRec(Node* root, int key) {
    if (!root || root->val == key) return root;
    if (key < root->val) return searchRec(root->left, key);
    else return searchRec(root->right, key);
}

// Iterative search
Node* searchIter(Node* root, int key) {
    while (root) {
        if (root->val == key) return root;
        root = (key < root->val) ? root->left : root->right;
    }
    return nullptr;
}

Node* findMin(Node* root) {
    if (!root) return nullptr;
    while (root->left) root = root->left;
    return root;
}
Node* findMax(Node* root) {
    if (!root) return nullptr;
    while (root->right) root = root->right;
    return root;
}

// successor: if node->right exists -> min(node->right)
// otherwise -> travel from root and keep candidate
Node* inorderSuccessor(Node* root, Node* node) {
    if (!node) return nullptr;
    if (node->right) return findMin(node->right);
    Node* succ = nullptr;
    Node* cur = root;
    while (cur) {
        if (node->val < cur->val) { succ = cur; cur = cur->left; }
        else if (node->val > cur->val) cur = cur->right;
        else break;
    }
    return succ;
}

// predecessor: if node->left exists -> max(node->left)
// otherwise -> travel from root and keep candidate
Node* inorderPredecessor(Node* root, Node* node) {
    if (!node) return nullptr;
    if (node->left) return findMax(node->left);
    Node* pred = nullptr;
    Node* cur = root;
    while (cur) {
        if (node->val > cur->val) { pred = cur; cur = cur->right; }
        else if (node->val < cur->val) cur = cur->left;
        else break;
    }
    return pred;
}

// Inorder print
void inorder(Node* r) {
    if (!r) return;
    inorder(r->left);
    cout << r->val << " ";
    inorder(r->right);
}

int main() {
    Node* root = buildBST();
    cout << "BST inorder: "; inorder(root); cout << "\n";

    while (true) {
        cout << "\nMenu:\n1. Recursive Search\n2. Iterative Search\n3. Minimum\n4. Maximum\n5. In-order Successor\n6. In-order Predecessor\n7. Exit\nChoice: ";
        int ch; cin >> ch;
        if (ch == 7) break;
        if (ch == 1) {
            int k; cout << "Key: "; cin >> k;
            Node* r = searchRec(root, k);
            cout << (r ? "Found\n" : "Not found\n");
        } else if (ch == 2) {
            int k; cout << "Key: "; cin >> k;
            Node* r = searchIter(root, k);
            cout << (r ? "Found\n" : "Not found\n");
        } else if (ch == 3) {
            Node* m = findMin(root);
            cout << (m ? to_string(m->val) : string("Tree empty")) << "\n";
        } else if (ch == 4) {
            Node* m = findMax(root);
            cout << (m ? to_string(m->val) : string("Tree empty")) << "\n";
        } else if (ch == 5) {
            int k; cout << "Node value: "; cin >> k;
            Node* node = searchIter(root, k);
            if (!node) { cout << "Node not found\n"; continue; }
            Node* s = inorderSuccessor(root, node);
            cout << (s ? to_string(s->val) : string("No successor")) << "\n";
        } else if (ch == 6) {
            int k; cout << "Node value: "; cin >> k;
            Node* node = searchIter(root, k);
            if (!node) { cout << "Node not found\n"; continue; }
            Node* p = inorderPredecessor(root, node);
            cout << (p ? to_string(p->val) : string("No predecessor")) << "\n";
        } else cout << "Invalid\n";
    }
    return 0;
}
