// bst_insert_delete_depth.cpp
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
    // duplicates ignored
    return root;
}

Node* findMin(Node* root) {
    while (root && root->left) root = root->left;
    return root;
}

Node* deleteNode(Node* root, int key) {
    if (!root) return nullptr;
    if (key < root->val) root->left = deleteNode(root->left, key);
    else if (key > root->val) root->right = deleteNode(root->right, key);
    else {
        // found
        if (!root->left) {
            Node* r = root->right;
            delete root;
            return r;
        } else if (!root->right) {
            Node* l = root->left;
            delete root;
            return l;
        } else {
            Node* succ = findMin(root->right);
            root->val = succ->val;
            root->right = deleteNode(root->right, succ->val);
        }
    }
    return root;
}

int maxDepth(Node* root) {
    if (!root) return 0;
    return 1 + max(maxDepth(root->left), maxDepth(root->right));
}
int minDepth(Node* root) {
    if (!root) return 0;
    if (!root->left && !root->right) return 1;
    if (!root->left) return 1 + minDepth(root->right);
    if (!root->right) return 1 + minDepth(root->left);
    return 1 + min(minDepth(root->left), minDepth(root->right));
}

void inorder(Node* r) {
    if (!r) return;
    inorder(r->left);
    cout << r->val << " ";
    inorder(r->right);
}

int main() {
    Node* root = nullptr;
    while (true) {
        cout << "\nMenu:\n1. Insert\n2. Delete\n3. Inorder Print\n4. Max Depth\n5. Min Depth\n6. Exit\nChoice: ";
        int ch; cin >> ch;
        if (ch == 6) break;
        if (ch == 1) {
            int x; cout << "Value: "; cin >> x;
            root = insertBST(root, x);
        } else if (ch == 2) {
            int x; cout << "Value to delete: "; cin >> x;
            root = deleteNode(root, x);
        } else if (ch == 3) {
            cout << "Inorder: "; inorder(root); cout << "\n";
        } else if (ch == 4) {
            cout << "Max depth: " << maxDepth(root) << "\n";
        } else if (ch == 5) {
            cout << "Min depth: " << minDepth(root) << "\n";
        } else cout << "Invalid\n";
    }
    return 0;
}
