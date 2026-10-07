#include <iostream>
using namespace std;

class Queue {
    int arr[100];
    int front;
    int rear;
    int capacity;
    int count;

public:
    Queue(int n) {
        capacity = n;
        front = 0;
        rear = -1;
        count = 0;
    }

    void join(int token) {
        if (count == capacity) {
            cout << "Error: Queue is full\n";
            return;
        }

        rear = (rear + 1) % capacity;
        arr[rear] = token;
        count++;

        if (count == 0)
            cout << "Front token: None\n";
        else
            cout << "Front token: " << arr[front] << "\n";
    }

    void serve() {
        if (count == 0) {
            cout << "Error: Queue is empty\n";
            return;
        }

        cout << "Served token: " << arr[front] << "\n";

        front = (front + 1) % capacity;
        count--;

        if (count == 0)
            cout << "Front token: None\n";
        else
            cout << "Front token: " << arr[front] << "\n";
    }
};

int main() {
    Queue q(3);

    q.join(101);
    q.join(102);
    q.join(103);

    q.join(104);

    q.serve();
    q.serve();

    q.join(104);
    q.join(105);

    q.serve();
    q.serve();
    q.serve();

    q.serve();

    return 0;
}