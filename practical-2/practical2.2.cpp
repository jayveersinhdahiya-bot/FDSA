#include <iostream>
using namespace std;

int iterativeBinarySearch(int arr[], int n, int target) {
    int low = 0;
    int high = n - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == target)
            return mid;

        if (arr[mid] < target)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return -1;
}

int recursiveBinarySearch(int arr[], int low, int high, int target) {
    if (low > high)
        return -1;

    int mid = low + (high - low) / 2;

    if (arr[mid] == target)
        return mid;

    if (arr[mid] < target)
        return recursiveBinarySearch(arr, mid + 1, high, target);
    else
        return recursiveBinarySearch(arr, low, mid - 1, target);
}

int main() {
    int n, target;

    cout << "Enter number of book codes: ";
    cin >> n;

    int arr[100];

    cout << "Enter sorted book codes: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Enter target book code: ";
    cin >> target;

    int iterativeResult = iterativeBinarySearch(arr, n, target);
    int recursiveResult = recursiveBinarySearch(arr, 0, n - 1, target);

    cout << "\nIterative Binary Search Position: ";
    
    if (iterativeResult != -1)
        cout << iterativeResult + 1 << endl;
    else
        cout << "Not Found" << endl;

    cout << "Recursive Binary Search Position: ";

    if (recursiveResult != -1)
        cout << recursiveResult + 1 << endl;
    else
        cout << "Not Found" << endl;

    return 0;
}