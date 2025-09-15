#include <iostream>
#define MAX 5
using namespace std;

class CircularQueue {
    int arr[MAX];
    int front, rear;
public:
    CircularQueue() { front = rear = -1; }

    bool isEmpty() { return front == -1; }
    bool isFull() { return (rear + 1) % MAX == front; }

    void enqueue(int val) {
        if (isFull()) {
            cout << "Queue is Full\n"; return;
        }
        if (isEmpty()) front = rear = 0;
        else rear = (rear + 1) % MAX;
        arr[rear] = val;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is Empty\n"; return;
        }
        cout << "Dequeued: " << arr[front] << endl;
        if (front == rear) front = rear = -1;
        else front = (front + 1) % MAX;
    }

    void display() {
        if (isEmpty()) { cout << "Queue is Empty\n"; return; }
        cout << "Circular Queue: ";
        int i = front;
        while (true) {
            cout << arr[i] << " ";
            if (i == rear) break;
            i = (i + 1) % MAX;
        }
        cout << endl;
    }

    void peek() {
        if (isEmpty()) cout << "Queue is Empty\n";
        else cout << "Front Element: " << arr[front] << endl;
    }
};

int main() {
    CircularQueue q;
    int choice, value;
    do {
        cout << "\n1. Enqueue\n2. Dequeue\n3. Display\n4. Peek\n5. Exit\nEnter choice: ";
        cin >> choice;
        switch (choice) {
            case 1: cout << "Enter value: "; cin >> value; q.enqueue(value); break;
            case 2: q.dequeue(); break;
            case 3: q.display(); break;
            case 4: q.peek(); break;
            case 5: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice\n";
        }
    } while (choice != 5);
    return 0;
}
