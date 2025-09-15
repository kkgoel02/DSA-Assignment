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

void countAndDelete(Node*& head, int key) {
    int count = 0;
    while (head && head->data == key) {
        Node* temp = head;
        head = head->next;
        delete temp;
        count++;
    }
    Node* t = head;
    while (t && t->next) {
        if (t->next->data == key) {
            Node* del = t->next;
            t->next = t->next->next;
            delete del;
            count++;
        } else t = t->next;
    }
    cout << "Count: " << count << endl;
}

void display(Node* head) {
    while (head) { cout << head->data; if (head->next) cout << "->"; head = head->next; }
    cout << endl;
}

int main() {
    Node* head = nullptr;
    int n,val,key;
    cin >> n;
    for(int i=0;i<n;i++){ cin>>val; insert(head,val); }
    cin >> key;
    countAndDelete(head,key);
    display(head);
    return 0;
}
