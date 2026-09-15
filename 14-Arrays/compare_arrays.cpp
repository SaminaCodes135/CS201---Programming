#include <iostream>
using namespace std;

int main()
{
    int first[5];
    int second[5];
    bool same = true;

    cout << "Enter 5 elements for the first array: ";
    for (int i = 0; i < 5; i++)
    {
        cin >> first[i];
    }

    cout << "Enter 5 elements for the second array: ";
    for (int i = 0; i < 5; i++)
    {
        cin >> second[i];
    }

    // Compare corresponding elements of both arrays
    for (int i = 0; i < 5; i++)
    {
        if (first[i] != second[i])
        {
            same = false;
            break;
        }
    }

    if (same)
        cout << "Both arrays are equal." << endl;
    else
        cout << "Arrays are different." << endl;

    return 0;
}
