#include <iostream>
using namespace std;

struct Node {
    char data;
    Node* next;
    Node* prev;
};

bool isPalindrome(Node* head) {
    if (!head) return true;
    Node* left = head;
    Node* right = head;
    while (right->next) right = right->next;
    while (left != right && right->next != left) {
        if (left->data != right->data)
            return false;
        left = left->next;
        right = right->prev;
    }
    return true;
}

int main() {
    Node* a = new Node{'r',nullptr,nullptr};
    Node* b = new Node{'a',nullptr,a};
    Node* c = new Node{'d',nullptr,b};
    Node* d = new Node{'a',nullptr,c};
    Node* e = new Node{'r',nullptr,d};
    a->next = b; b->next = c; c->next = d; d->next = e;

    cout << (isPalindrome(a) ? "True" : "False") << endl;
}
