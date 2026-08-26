#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = NULL;

// Insert at front
void insertFront(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = head;
    head = newNode;
}

// Insert at end
void insertEnd(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
}

// Insert at specific position
void insertPosition(int value, int position) {
    if (position == 1) {
        insertFront(value);
        return;
    }

    Node* temp = head;

    for (int i = 1; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        cout << "Invalid position!" << endl;
        return;
    }

    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = temp->next;
    temp->next = newNode;
}

// Display queue
void display() {
    Node* temp = head;

    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << endl;
}

int main() {
    int choice, value, position;

    while (true) {
        cout << "\n1. Critical Patient (Front)";
        cout << "\n2. Routine Patient (End)";
        cout << "\n3. Insert at Position";
        cout << "\n4. Display";
        cout << "\n5. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter patient token: ";
            cin >> value;
            insertFront(value);
            display();
        }
        else if (choice == 2) {
            cout << "Enter patient token: ";
            cin >> value;
            insertEnd(value);
            display();
        }
        else if (choice == 3) {
            cout << "Enter patient token: ";
            cin >> value;
            cout << "Enter position: ";
            cin >> position;
            insertPosition(value, position);
            display();
        }
        else if (choice == 4) {
            display();
        }
        else if (choice == 5) {
            break;
        }
        else {
            cout << "Invalid choice!" << endl;
        }
    }

    return 0;
}