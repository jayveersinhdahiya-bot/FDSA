#include <iostream>
using namespace std;

class Node {
public:
    string song;
    Node* prev;
    Node* next;

    Node(string s) {
        song = s;
        prev = NULL;
        next = NULL;
    }
};

class Playlist {
    Node* head;
    Node* tail;

public:
    Playlist() {
        head = NULL;
        tail = NULL;
    }

    void addBeginning(string song) {
        Node* newNode = new Node(song);

        if (head == NULL) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    void addEnd(string song) {
        Node* newNode = new Node(song);

        if (head == NULL) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void insertAfter(string givenSong, string newSong) {
        Node* temp = head;

        while (temp != NULL && temp->song != givenSong) {
            temp = temp->next;
        }

        if (temp == NULL) {
            cout << "Song not found\n";
            return;
        }

        Node* newNode = new Node(newSong);

        newNode->next = temp->next;
        newNode->prev = temp;

        if (temp->next != NULL) {
            temp->next->prev = newNode;
        } else {
            tail = newNode;
        }

        temp->next = newNode;
    }

    void removeFirst() {
        if (head == NULL) {
            cout << "Playlist is empty\n";
            return;
        }

        Node* temp = head;
        head = head->next;

        if (head != NULL) {
            head->prev = NULL;
        } else {
            tail = NULL;
        }

        delete temp;
    }

    int count() {
        int c = 0;
        Node* temp = head;

        while (temp != NULL) {
            c++;
            temp = temp->next;
        }

        return c;
    }

    void display() {
        Node* temp = head;

        cout << "Playlist: ";

        while (temp != NULL) {
            cout << temp->song << " ";
            temp = temp->next;
        }

        cout << "\n";
        cout << "Count: " << count() << "\n";
    }
};

int main() {
    Playlist p;

    p.addBeginning("SongA");
    p.display();

    p.addEnd("SongB");
    p.display();

    p.addEnd("SongC");
    p.display();

    p.insertAfter("SongB", "SongX");
    p.display();

    p.removeFirst();
    p.display();

    p.insertAfter("ABC", "SongY");
    p.display();

    return 0;
}