#include <iostream>
using namespace std;

int main()
{
    char first[100];
    char second[100];
    bool same = true;

    cout << "Enter first string: ";
    cin.getline(first, 100);

    cout << "Enter second string: ";
    cin.getline(second, 100);

    // Compare characters until a difference or the end of both strings
    for (int i = 0; first[i] != '\0' || second[i] != '\0'; i++)
    {
        if (first[i] != second[i])
        {
            same = false;
            break;
        }
    }

    if (same)
        cout << "Both strings are equal." << endl;
    else
        cout << "Strings are different." << endl;

    return 0;
}
