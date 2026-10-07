#include <iostream>
using namespace std;

class Node {
public:
    string name;
    Node* next;

    Node(string n) {
        name = n;
        next = NULL;
    }
};

class SinglyCircular {
    Node* last;

public:
    SinglyCircular() {
        last = NULL;
    }

    void join(string name) {
        Node* newNode = new Node(name);

        if (last == NULL) {
            last = newNode;
            last->next = last;
        } else {
            newNode->next = last->next;
            last->next = newNode;
        }
    }

    void leave(string name) {
        if (last == NULL)
            return;

        Node* current = last->next;
        Node* previous = last;

        do {
            if (current->name == name) {

                if (current == last && current->next == last) {
                    last = NULL;
                } else {
                    previous->next = current->next;

                    if (current == last)
                        last = previous;
                }

                delete current;
                return;
            }

            previous = current;
            current = current->next;

        } while (current != last->next);

        cout << "Student not found\n";
    }

    void display() {
        if (last == NULL) {
            cout << "Circle is empty\n";
            return;
        }

        Node* temp = last->next;

        cout << "Circle: ";

        do {
            cout << temp->name << " ";
            temp = temp->next;
        } while (temp != last->next);

        cout << "\n";
    }
};

int main() {
    SinglyCircular c;

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