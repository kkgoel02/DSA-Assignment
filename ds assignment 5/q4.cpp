#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void insert(Node*& head, int val) {
    Node* temp = new Node{val, nullptr};
    if (!head) { head = temp; return; }
    Node* t = head;
    while (t->next) t = t->next;
    t->next = temp;
}

void reverse(Node*& head) {
    Node* prev = nullptr;
    Node* curr = head;
    while (curr) {
        Node* next = curr->next;
        curr->next = prev;  
        prev = curr;
        curr = next;
    }
    head = prev;
}

void display(Node* head) {
    while (head) { cout << head->data; if (head->next) cout << "->"; head = head->next; }
    cout << "->NULL" << endl;
}

int main() {
    Node* head = nullptr;
    int n,val;
    cin >> n;
    for(int i=0;i<n;i++){ cin>>val; insert(head,val); }
    reverse(head);
    display(head);
    return 0;
}
