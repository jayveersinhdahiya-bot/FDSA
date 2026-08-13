#include <iostream>
using namespace std;

int main()
{
    int n;

    cout << "Enter the size of array: ";
    if (!(cin >> n) || n <= 0) {
        cerr << "Invalid array size\n";
        return 1;
    }

    int *arr = new int[n];

    cout << "Enter the array elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "Enter number of rotations: ";
    int h;
    cin >> h;

    h = h % n;

    cout << "Rotated array: ";

    for (int i = h; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    for (int i = 0; i < h; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}