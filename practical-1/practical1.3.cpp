#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main()
{
    string sentence;

    cout << "Enter a sentence: ";
    getline(cin, sentence);

    stringstream ss(sentence);
    string word, longest = "";

    while (ss >> word)
    {
        if (word.length() > longest.length())
        {
            longest = word;
        }
    }

    cout << "Longest Word: " << longest << endl;
    cout << "Number of Letters: " << longest.length() << endl;

    return 0;
}