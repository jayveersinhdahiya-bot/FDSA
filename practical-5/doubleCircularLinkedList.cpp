#include <iostream>
using namespace std;

class Node {
public:
    string name;
    Node* prev;
    Node* next;

    Node(string n) {
        name = n;
        prev = NULL;
        next = NULL;
    }
};

class DoublyCircular {
    Node* head;

public:
    DoublyCircular() {
        head = NULL;
    }

    void join(string name) {
        Node* newNode = new Node(name);

        if (head == NULL) {
            head = newNode;
            newNode->next = newNode;
            newNode->prev = newNode;
        } else {
            Node* last = head->prev;

            newNode->next = head;
            newNode->prev = last;

            last->next = newNode;
            head->prev = newNode;
        }
    }

    void leave(string name) {
        if (head == NULL)
            return;

        Node* temp = head;

        do {
            if (temp->name == name) {

                if (temp->next == temp) {
                    head = NULL;
                } else {
                    temp->prev->next = temp->next;
                    temp->next->prev = temp->prev;

                    if (temp == head)
                        head = temp->next;
                }

                delete temp;
                return;
            }

            temp = temp->next;

        } while (temp != head);

        cout << "Student not found\n";
    }

    void display() {
        if (head == NULL) {
            cout << "Circle is empty\n";
            return;
        }

        Node* temp = head;

        cout << "Circle: ";

        do {
            cout << temp->name << " ";
            temp = temp->next;
        } while (temp != head);

        cout << "\n";
    }
};

int main() {
    DoublyCircular c;

    c.join("A");
    c.display();

    c.join("B");
    c.display();

    c.join("C");
    c.display();

    c.leave("B");
    c.display();

    c.leave("A");
    c.display();

    c.join("D");
    c.display();

    return 0;
}