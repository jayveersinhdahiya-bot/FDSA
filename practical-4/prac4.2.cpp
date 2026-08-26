#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = NULL;

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

void deleteValue(int value) {
    if (head == NULL) {
        cout << "Queue is empty!" << endl;
        return;
    }

    if (head->data == value) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }

    Node* temp = head;

    while (temp->next != NULL && temp->next->data != value) {
        temp = temp->next;
    }

    if (temp->next == NULL) {
        cout << "Token not found!" << endl;
        return;
    }

    Node* del = temp->next;
    temp->next = del->next;
    delete del;
}

void display() {
    Node* temp = head;

    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << endl;
}

void reversePrint(Node* temp) {
    if (temp == NULL)
        return;

    reversePrint(temp->next);
    cout << temp->data << " ";
}

int main() {
    int choice, value;

    insertEnd(101);
    insertEnd(102);
    insertEnd(103);
    insertEnd(104);

    while (true) {
        cout << "\n1. Delete Patient";
        cout << "\n2. Forward Display";
        cout << "\n3. Reverse Display";
        cout << "\n4. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter token to delete: ";
            cin >> value;
            deleteValue(value);
            display();
        }
        else if (choice == 2) {
            display();
        }
        else if (choice == 3) {
            reversePrint(head);
            cout << endl;
        }
        else if (choice == 4) {
            break;
        }
        else {
            cout << "Invalid choice!" << endl;
        }
    }

    return 0;
}