#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class SinglyLinkedList {
    Node* head;
public:
    SinglyLinkedList() { head = nullptr; }

    void insertAtBeginning(int val) {
        Node* temp = new Node{val, head};
        head = temp;
    }

    void insertAtEnd(int val) {
        Node* temp = new Node{val, nullptr};
        if (!head) { head = temp; return; }
        Node* t = head;
        while (t->next) t = t->next;
        t->next = temp;
    }

    void insertBefore(int key, int val) {
        if (!head) return;
        if (head->data == key) { insertAtBeginning(val); return; }
        Node* t = head;
        while (t->next && t->next->data != key) t = t->next;
        if (t->next) {
            Node* temp = new Node{val, t->next};
            t->next = temp;
        }
    }

    void insertAfter(int key, int val) {
        Node* t = head;
        while (t && t->data != key) t = t->next;
        if (t) {
            Node* temp = new Node{val, t->next};
            t->next = temp;
        }
    }

    void deleteBeginning() {
        if (!head) return;
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    void deleteEnd() {
        if (!head) return;
        if (!head->next) { delete head; head = nullptr; return; }
        Node* t = head;
        while (t->next->next) t = t->next;
        delete t->next;
        t->next = nullptr;
    }

    void deleteNode(int key) {
        if (!head) return;
        if (head->data == key) { deleteBeginning(); return; }
        Node* t = head;
        while (t->next && t->next->data != key) t = t->next;
        if (t->next) {
            Node* del = t->next;
            t->next = t->next->next;
            delete del;
        }
    }

    void search(int key) {
        int pos = 1;
        Node* t = head;
        while (t) {
            if (t->data == key) { cout << "Found at position " << pos << endl; return; }
            pos++;
            t = t->next;
        }
        cout << "Not Found\n";
    }

    void display() {
        Node* t = head;
        while (t) { cout << t->data << " "; t = t->next; }
        cout << endl;
    }
};

int main() {
    SinglyLinkedList s;
    int ch, val, key;
    do {
        cout << "\n1.InsertBeg 2.InsertEnd 3.InsertBefore 4.InsertAfter 5.DeleteBeg 6.DeleteEnd 7.DeleteNode 8.Search 9.Display 10.Exit\n";
        cin >> ch;
        switch(ch) {
            case 1: cin >> val; s.insertAtBeginning(val); break;
            case 2: cin >> val; s.insertAtEnd(val); break;
            case 3: cin >> key >> val; s.insertBefore(key,val); break;
            case 4: cin >> key >> val; s.insertAfter(key,val); break;
            case 5: s.deleteBeginning(); break;
            case 6: s.deleteEnd(); break;
            case 7: cin >> key; s.deleteNode(key); break;
            case 8: cin >> key; s.search(key); break;
            case 9: s.display(); break;
        }
    } while(ch!=10);
    return 0;
}
