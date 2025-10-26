#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class CircularList {
    Node* head;
public:
    CircularList() : head(nullptr) {}

    void insert(int val) {
        Node* newNode = new Node{val, nullptr};
        if (!head) {
            head = newNode;
            head->next = head;
            return;
        }
        Node* temp = head;
        while (temp->next != head) temp = temp->next;
        temp->next = newNode;
        newNode->next = head;
    }

    void display() {
        if (!head) return;
        Node* temp = head;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
        cout << head->data << endl; // repeat head value
    }
};

int main() {
    CircularList cl;
    cl.insert(20);
    cl.insert(100);
    cl.insert(40);
    cl.insert(80);
    cl.insert(60);

    cout << "Output: ";
    cl.display();
}
