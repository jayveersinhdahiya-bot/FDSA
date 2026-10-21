#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> table[10];
    int n, id;

    cout << "Enter number of books: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Enter book code: ";
        cin >> id;

        int index = id % 10;
        table[index].push_back(id);
    }

    cout << "\nHash Table:\n";

    for (int i = 0; i < 10; i++) {
        cout << i << " : ";

        for (int book : table[i])
            cout << book << " ";

        cout << "\n";
    }

    return 0;
}