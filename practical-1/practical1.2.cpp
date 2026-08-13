#include <iostream>
using namespace std;

int main()
{
    int n;

    cout << "Enter number of book IDs: ";
    cin >> n;

    int book[n];

    cout << "Enter Book IDs:" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> book[i];
    }

    cout << "Repeated Book IDs and Borrow Count:" << endl;

    for (int i = 0; i < n; i++)
    {
        int count = 0;

        for (int j = 0; j < n; j++)
        {
            if (book[i] == book[j])
            {
                count++;
            }
        }

        int k;
        for (k = 0; k < i; k++)
        {
            if (book[i] == book[k])
            {
                break;
            }
        }

        if (k == i && count > 1)
        {
            cout << book[i] << " borrowed " << count << " times" << endl;
        }
    }

    return 0;
}