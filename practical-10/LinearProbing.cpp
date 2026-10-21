#include <iostream>
using namespace std;

int main() {
    int table[10];

    for (int i = 0; i < 10; i++)
        table[i] = -1;

    int n, id;
    cout << "Enter number of vehicles: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Enter registration number: ";
        cin >> id;

        int index = id % 10;
        int start = index;

        while (table[index] != -1) {
            index = (index + 1) % 10;

            if (index == start) {
                cout << "Parking full\n";
                break;
            }
        }

        if (table[index] == -1)
            table[index] = id;
    }

    cout << "\nParking slots:\n";

    for (int i = 0; i < 10; i++)
        cout << i << " : " << table[i] << "\n";

    return 0;
}