#include <iostream>
using namespace std;

class Stack {
    int arr[100];
    int top;
    int capacity;

public:
    Stack(int n) {
        capacity = n;
        top = -1;
    }

    void push(int tray) {
        if (top == capacity - 1) {
            cout << "Error: Stack is full\n";
            return;
        }

        top++;
        arr[top] = tray;

        cout << "Placed tray: " << tray << "\n";
        cout << "Top tray: " << arr[top] << "\n";
    }

    void pop() {
        if (top == -1) {
            cout << "Error: Stack is empty\n";
            return;
        }

        cout << "Taken tray: " << arr[top] << "\n";
        top--;

        if (top == -1)
            cout << "Top tray: None\n";
        else
            cout << "Top tray: " << arr[top] << "\n";
    }
};

int main() {
    Stack s(3);

    s.push(101);
    s.push(102);
    s.push(103);
    s.push(104);

    s.pop();
    s.pop();
    s.pop();
    s.pop();

    return 0;
}