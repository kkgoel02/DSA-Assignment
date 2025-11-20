#include <iostream>
using namespace std;

void improvedSelectionSort(int a[], int n) {
    int start = 0, end = n - 1;

    while (start < end) {
        int minIndex = start, maxIndex = start;

        for (int i = start; i <= end; i++) {
            if (a[i] < a[minIndex]) minIndex = i;
            if (a[i] > a[maxIndex]) maxIndex = i;
        }

        swap(a[start], a[minIndex]);

        if (maxIndex == start) 
            maxIndex = minIndex;

        swap(a[end], a[maxIndex]);

        start++;
        end--;
    }
}

int main() {
    int n;
    cout << "Enter size: ";
    cin >> n;

    int a[n];
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) cin >> a[i];

    improvedSelectionSort(a, n);

    cout << "Sorted Array: ";
    for (int i = 0; i < n; i++) cout << a[i] << " ";
    cout << "\n";

    return 0;
}
