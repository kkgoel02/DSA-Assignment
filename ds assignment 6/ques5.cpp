#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

bool isCircular(Node* head) {
    if (!head) return false;
    Node* temp = head->next;
    while (temp && temp != head)
        temp = temp->next;
    return (temp == head);
}

int main() {
    Node* a = new Node{2,nullptr};
    Node* b = new Node{4,nullptr};
    Node* c = new Node{6,nullptr};
    Node* d = new Node{7,nullptr};
    Node* e = new Node{5,nullptr};
    a->next = b; b->next = c; c->next = d; d->next = e; e->next = a; // make circular

    cout << (isCircular(a) ? "True" : "False") << endl;
}
