#include <iostream>
using namespace std;

struct DNode { int data; DNode* next; DNode* prev; };
struct CNode { int data; CNode* next; };

int sizeDoubly(DNode* head) {
    int count = 0;
    while (head) { count++; head = head->next; }
    return count;
}

int sizeCircular(CNode* head) {
    if (!head) return 0;
    int count = 0;
    CNode* temp = head;
    do {
        count++;
        temp = temp->next;
    } while (temp != head);
    return count;
}

int main() {
    // Doubly linked list
    DNode* d1 = new DNode{10,nullptr,nullptr};
    DNode* d2 = new DNode{20,nullptr,d1};
    DNode* d3 = new DNode{30,nullptr,d2};
    d1->next = d2; d2->next = d3;
    cout << "Size of Doubly Linked List: " << sizeDoubly(d1) << endl;

    // Circular linked list
    CNode* c1 = new CNode{5,nullptr};
    CNode* c2 = new CNode{15,nullptr};
    CNode* c3 = new CNode{25,nullptr};
    c1->next = c2; c2->next = c3; c3->next = c1;
    cout << "Size of Circular Linked List: " << sizeCircular(c1) << endl;
}
