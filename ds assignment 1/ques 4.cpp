#include <iostream>
using namespace std;

void reverseArray() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;
    int arr[100];
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    for (int i = 0; i < n / 2; i++) {
        int temp = arr[i];
        arr[i] = arr[n - 1 - i];
        arr[n - 1 - i] = temp;
    }

    cout << "Reversed array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}


void matrixMultiplication() {
    int r1, c1, r2, c2;
    cout << "Enter rows & cols of Matrix A: ";
    cin >> r1 >> c1;
    cout << "Enter rows & cols of Matrix B: ";
    cin >> r2 >> c2;

    if (c1 != r2) {
        cout << "Matrix multiplication not possible!\n";
        return;
    }

    int A[10][10], B[10][10], C[10][10] = {0};

    cout << "Enter Matrix A:\n";
    for (int i = 0; i < r1; i++)
        for (int j = 0; j < c1; j++)
            cin >> A[i][j];

    cout << "Enter Matrix B:\n";
    for (int i = 0; i < r2; i++)
        for (int j = 0; j < c2; j++)
            cin >> B[i][j];

    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            C[i][j] = 0;
            for (int k = 0; k < c1; k++)
                C[i][j] += A[i][k] * B[k][j];
        }
    }

    cout << "Result Matrix:\n";
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++)
            cout << C[i][j] << " ";
        cout << endl;
    }
}


void transposeMatrix() {
    int r, c;
    cout << "Enter rows & cols of Matrix: ";
    cin >> r >> c;

    int A[10][10];
    cout << "Enter Matrix:\n";
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            cin >> A[i][j];

    cout << "Transpose:\n";
    for (int i = 0; i < c; i++) {
        for (int j = 0; j < r; j++)
            cout << A[j][i] << " ";
        cout << endl;
    }
}

int main() {
    int choice = 0;
    while (choice != 4) {
        cout << "\n---Q4 MENU---\n";
        cout << "1. Reverse Array\n";
        cout << "2. Matrix Multiplication\n";
        cout << "3. Transpose of Matrix\n";
        cout << "4. EXIT\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: reverseArray(); break;
            case 2: matrixMultiplication(); break;
            case 3: transposeMatrix(); break;
            case 4: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice!\n";
        }
    }
    return 0;
}
