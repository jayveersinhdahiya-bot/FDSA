#include <iostream>
using namespace std;

class Node {
public:
    string page;
    Node* next;

    Node(string p) {
        page = p;
        next = NULL;
    }
};

class Browser {
    Node* top;

public:
    Browser() {
        top = NULL;
    }

    void visit(string page) {
        Node* newNode = new Node(page);

        newNode->next = top;
        top = newNode;

        cout << "Current page: " << top->page << "\n";
    }

    void back() {
        if (top == NULL) {
            cout << "Error: No history left\n";
            return;
        }

        Node* temp = top;
        top = top->next;

        delete temp;

        if (top == NULL)
            cout << "No page left\n";
        else
            cout << "Current page: " << top->page << "\n";
    }
};

int main() {
    Browser b;

    b.visit("Google");
    b.visit("YouTube");
    b.visit("CHARUSAT");
    b.visit("GitHub");

    b.back();
    b.back();
    b.back();
    b.back();
    b.back();

    return 0;
}