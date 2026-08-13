#include <iostream>
#include <string>
using namespace std;

int iterativeSearch(string plates[], int size, string target)
{
    for (int i = 0; i < size; i++)
    {
        if (plates[i] == target)
        {
            return i;
        }
    }
    return -1;
}

int recursiveSearch(string plates[], int size, string target, int index)
{
    if (index >= size)
    {
        return -1;
    }

    if (plates[index] == target)
    {
        return index;
    }

    return recursiveSearch(plates, size, target, index + 1);
}

int main()
{
    int n;

    cout << "Enter number of license plates: ";
    cin >> n;

    string plates[n];

    cout << "Enter license plates:" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> plates[i];
    }

    string target;
    cout << "Enter target license plate: ";
    cin >> target;

    int iterativeResult = iterativeSearch(plates, n, target);
    int recursiveResult = recursiveSearch(plates, n, target, 0);

    if (iterativeResult != -1)
        cout << "\nIterative Search: Found at position " << iterativeResult + 1 << endl;
    else
        cout << "\nIterative Search: Target not found." << endl;

    if (recursiveResult != -1)
        cout << "Recursive Search: Found at position " << recursiveResult + 1 << endl;
    else
        cout << "Recursive Search: Target not found." << endl;

    return 0;
}