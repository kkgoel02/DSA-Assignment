#include <iostream>
using namespace std;

// ======= DOUBLY LINKED LIST =======
struct DNode {
    int data;
    DNode* prev;
    DNode* next;
};

class DoublyLinkedList {
private:
    DNode* head;
public:
    DoublyLinkedList() : head(nullptr) {}

    void insertFirst(int val) {
        DNode* newNode = new DNode{val, nullptr, head};
        if (head) head->prev = newNode;
        head = newNode;
    }

    void insertLast(int val) {
        DNode* newNode = new DNode{val, nullptr, nullptr};
        if (!head) { head = newNode; return; }
        DNode* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = newNode;
        newNode->prev = temp;
    }

    void insertAfter(int key, int val) {
        DNode* temp = head;
        while (temp && temp->data != key) temp = temp->next;
        if (!temp) { cout << "Node not found!\n"; return; }
        DNode* newNode = new DNode{val, temp, temp->next};
        if (temp->next) temp->next->prev = newNode;
        temp->next = newNode;
    }

    void insertBefore(int key, int val) {
        DNode* temp = head;
        while (temp && temp->data != key) temp = temp->next;
        if (!temp) { cout << "Node not found!\n"; return; }
        DNode* newNode = new DNode{val, temp->prev, temp};
        if (temp->prev) temp->prev->next = newNode;
        else head = newNode;
        temp->prev = newNode;
    }

    void deleteNode(int key) {
        DNode* temp = head;
        while (temp && temp->data != key) temp = temp->next;
        if (!temp) { cout << "Node not found!\n"; return; }
        if (temp->prev) temp->prev->next = temp->next;
        else head = temp->next;
        if (temp->next) temp->next->prev = temp->prev;
        delete temp;
        cout << "Node deleted.\n";
    }

    bool search(int key) {
        DNode* temp = head;
        while (temp) {
            if (temp->data == key) return true;
            temp = temp->next;
        }
        return false;
    }

    void display() {
        DNode* temp = head;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

// ======= CIRCULAR LINKED LIST =======
struct CNode {
    int data;
    CNode* next;
};

class CircularLinkedList {
private:
    CNode* head;
public:
    CircularLinkedList() : head(nullptr) {}

    void insertFirst(int val) {
        CNode* newNode = new CNode{val, nullptr};
        if (!head) { head = newNode; head->next = head; return; }
        CNode* temp = head;
        while (temp->next != head) temp = temp->next;
        newNode->next = head;
        temp->next = newNode;
        head = newNode;
    }

    void insertLast(int val) {
        CNode* newNode = new CNode{val, nullptr};
        if (!head) { head = newNode; head->next = head; return; }
        CNode* temp = head;
        while (temp->next != head) temp = temp->next;
        temp->next = newNode;
        newNode->next = head;
    }

    void insertAfter(int key, int val) {
        if (!head) return;
        CNode* temp = head;
        do {
            if (temp->data == key) {
                CNode* newNode = new CNode{val, temp->next};
                temp->next = newNode;
                return;
            }
            temp = temp->next;
        } while (temp != head);
        cout << "Node not found!\n";
    }

    void deleteNode(int key) {
        if (!head) return;
        CNode *curr = head, *prev = nullptr;
        do {
            if (curr->data == key) {
                if (curr == head) {
                    CNode* last = head;
                    while (last->next != head) last = last->next;
                    if (head == head->next) { delete head; head = nullptr; return; }
                    last->next = head->next;
                    head = head->next;
                } else prev->next = curr->next;
                delete curr;
                cout << "Node deleted.\n";
                return;
            }
            prev = curr;
            curr = curr->next;
        } while (curr != head);
        cout << "Node not found!\n";
    }

    bool search(int key) {
        if (!head) return false;
        CNode* temp = head;
        do {
            if (temp->data == key) return true;
            temp = temp->next;
        } while (temp != head);
        return false;
    }

    void display() {
        if (!head) return;
        CNode* temp = head;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
        cout << endl;
    }
};

// ======= MAIN =======
int main() {
    DoublyLinkedList dll;
    CircularLinkedList cll;
    int choice, subchoice, val, key;

    while (true) {
        cout << "\nMenu:\n1. Doubly Linked List\n2. Circular Linked List\n3. Exit\nChoice: ";
        cin >> choice;
        if (choice == 3) break;

        if (choice == 1) {
            cout << "\n1.Insert First\n2.Insert Last\n3.Insert After\n4.Insert Before\n5.Delete\n6.Search\n7.Display\n";
            cout << "Enter: ";
            cin >> subchoice;
            switch (subchoice) {
                case 1: cout << "Value: "; cin >> val; dll.insertFirst(val); break;
                case 2: cout << "Value: "; cin >> val; dll.insertLast(val); break;
                case 3: cout << "After key and value: "; cin >> key >> val; dll.insertAfter(key,val); break;
                case 4: cout << "Before key and value: "; cin >> key >> val; dll.insertBefore(key,val); break;
                case 5: cout << "Delete key: "; cin >> key; dll.deleteNode(key); break;
                case 6: cout << "Search key: "; cin >> key; cout << (dll.search(key)?"Found\n":"Not Found\n"); break;
                case 7: dll.display(); break;
            }
        }
        else if (choice == 2) {
            cout << "\n1.Insert First\n2.Insert Last\n3.Insert After\n4.Delete\n5.Search\n6.Display\n";
            cout << "Enter: ";
            cin >> subchoice;
            switch (subchoice) {
                case 1: cout << "Value: "; cin >> val; cll.insertFirst(val); break;
                case 2: cout << "Value: "; cin >> val; cll.insertLast(val); break;
                case 3: cout << "After key and value: "; cin >> key >> val; cll.insertAfter(key,val); break;
                case 4: cout << "Delete key: "; cin >> key; cll.deleteNode(key); break;
                case 5: cout << "Search key: "; cin >> key; cout << (cll.search(key)?"Found\n":"Not Found\n"); break;
                case 6: cll.display(); break;
            }
        }
    }
}
