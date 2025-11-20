// priority_queue_using_heap.cpp
#include <bits/stdc++.h>
using namespace std;

struct MaxPQ {
    vector<int> heap;
    void push(int x) {
        heap.push_back(x);
        int i = heap.size()-1;
        while (i > 0) {
            int p = (i-1)/2;
            if (heap[p] >= heap[i]) break;
            swap(heap[p], heap[i]);
            i = p;
        }
    }
    int top() { return heap.empty() ? INT_MIN : heap[0]; }
    void pop() {
        if (heap.empty()) return;
        heap[0] = heap.back(); heap.pop_back();
        int n = heap.size(), i = 0;
        while (true) {
            int l = 2*i+1, r = 2*i+2, largest = i;
            if (l < n && heap[l] > heap[largest]) largest = l;
            if (r < n && heap[r] > heap[largest]) largest = r;
            if (largest == i) break;
            swap(heap[i], heap[largest]);
            i = largest;
        }
    }
    bool empty() { return heap.empty(); }
};

struct MinPQ {
    vector<int> heap;
    void push(int x) {
        heap.push_back(x);
        int i = heap.size()-1;
        while (i > 0) {
            int p = (i-1)/2;
            if (heap[p] <= heap[i]) break;
            swap(heap[p], heap[i]);
            i = p;
        }
    }
    int top() { return heap.empty() ? INT_MAX : heap[0]; }
    void pop() {
        if (heap.empty()) return;
        heap[0] = heap.back(); heap.pop_back();
        int n = heap.size(), i = 0;
        while (true) {
            int l = 2*i+1, r = 2*i+2, smallest = i;
            if (l < n && heap[l] < heap[smallest]) smallest = l;
            if (r < n && heap[r] < heap[smallest]) smallest = r;
            if (smallest == i) break;
            swap(heap[i], heap[smallest]);
            i = smallest;
        }
    }
    bool empty() { return heap.empty(); }
};

int main() {
    MaxPQ maxq;
    MinPQ minq;
    while (true) {
        cout << "\nMenu:\n1. Push into MaxPQ\n2. Pop from MaxPQ\n3. Top MaxPQ\n4. Push into MinPQ\n5. Pop from MinPQ\n6. Top MinPQ\n7. Exit\nChoice: ";
        int ch; cin >> ch;
        if (ch == 7) break;
        if (ch == 1) { int v; cout<<"Value: "; cin>>v; maxq.push(v); }
        else if (ch == 2) { if (maxq.empty()) cout<<"MaxPQ empty\n"; else { cout<<"Popped "<<maxq.top()<<"\n"; maxq.pop(); } }
        else if (ch == 3) { if (maxq.empty()) cout<<"MaxPQ empty\n"; else cout<<"Top: "<<maxq.top()<<"\n"; }
        else if (ch == 4) { int v; cout<<"Value: "; cin>>v; minq.push(v); }
        else if (ch == 5) { if (minq.empty()) cout<<"MinPQ empty\n"; else { cout<<"Popped "<<minq.top()<<"\n"; minq.pop(); } }
        else if (ch == 6) { if (minq.empty()) cout<<"MinPQ empty\n"; else cout<<"Top: "<<minq.top()<<"\n"; }
        else cout << "Invalid\n";
    }
    return 0;
}
