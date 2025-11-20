// heapsort.cpp
#include <bits/stdc++.h>
using namespace std;

void heapify(vector<int>& a, int n, int i) {
    int largest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;
    if (l < n && a[l] > a[largest]) largest = l;
    if (r < n && a[r] > a[largest]) largest = r;
    if (largest != i) {
        swap(a[i], a[largest]);
        heapify(a, n, largest);
    }
}

void heapSortIncreasing(vector<int>& a) {
    int n = a.size();
    for (int i = n/2 - 1; i >= 0; --i) heapify(a, n, i);
    for (int i = n - 1; i >= 1; --i) {
        swap(a[0], a[i]);
        heapify(a, i, 0);
    }
}

void heapSortDecreasing(vector<int>& a) {
    // build min-heap and extract
    int n = a.size();
    // invert sign and use max-heap method, or implement min-heap
    // Implement min-heap variant
    auto minHeapify = [&](auto&& self, vector<int>& arr, int m, int i) -> void {
        int smallest = i;
        int l = 2*i + 1;
        int r = 2*i + 2;
        if (l < m && arr[l] < arr[smallest]) smallest = l;
        if (r < m && arr[r] < arr[smallest]) smallest = r;
        if (smallest != i) {
            swap(arr[i], arr[smallest]);
            self(self, arr, m, smallest);
        }
    };
    for (int i = n/2 - 1; i >= 0; --i) minHeapify(minHeapify, a, n, i);
    for (int i = n - 1; i >= 1; --i) {
        swap(a[0], a[i]);
        minHeapify(minHeapify, a, i, 0);
    }
    // after above, array is in decreasing order already
}

int main() {
    int n; cout << "Number of elements: "; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    cout << "Order: 1) Increasing  2) Decreasing\nChoice: ";
    int ch; cin >> ch;
    if (ch == 1) {
        heapSortIncreasing(a);
        cout << "Sorted (increasing): ";
    } else {
        heapSortDecreasing(a);
        cout << "Sorted (decreasing): ";
    }
    for (int x : a) cout << x << " ";
    cout << "\n";
    return 0;
}
