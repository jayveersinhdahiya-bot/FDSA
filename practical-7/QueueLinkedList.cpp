#include <iostream>
using namespace std;

class Node {
public:
    string patient;
    Node* next;

    Node(string p) {
        patient = p;
        next = NULL;
    }
};

class Queue {
    Node* front;
    Node* rear;

public:
    Queue() {
        front = NULL;
        rear = NULL;
    }

    void arrive(string patient) {
        Node* newNode = new Node(patient);

        if (rear == NULL) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }

        cout << "Front patient: " << front->patient << "\n";
    }

    void attend() {
        if (front == NULL) {
            cout << "Error: No patients waiting\n";
            return;
        }

        cout << "Attended patient: " << front->patient << "\n";

        Node* temp = front;
        front = front->next;

        delete temp;

        if (front == NULL) {
            rear = NULL;
            cout << "Front patient: None\n";
        } else {
            cout << "Front patient: " << front->patient << "\n";
        }
    }
};

int main() {
    Queue q;

    q.arrive("Patient A");
    q.arrive("Patient B");
    q.arrive("Patient C");

    q.attend();
    q.attend();

    q.arrive("Patient D");

    q.attend();
    q.attend();

    q.attend();

    return 0;
}