// Assignment 3 Q2.cpp
#include <iostream>
#include <stack>
#include <string>
using namespace std;

string reverseString(string str) {
    stack<char> s;
    for (char ch : str) s.push(ch);
    string rev = "";
    while (!s.empty()) {
        rev += s.top();
        s.pop();
    }
    return rev;
}

int main() {
    string input;
    cout << "Enter a string: ";
    cin >> input;
    cout << "Reversed string: " << reverseString(input) << endl;
    return 0;
}
