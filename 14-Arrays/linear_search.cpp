#include <iostream>
using namespace std;

int main()
{
    int numbers[100];
    int searchValue;
    bool found = false;

    // Store values from 0 to 49 in the array
    for (int i = 0; i < 50; i++)
    {
        numbers[i] = i;
    }

    cout << "Enter a positive integer to search: ";
    cin >> searchValue;

    // Search for the value in the array
    for (int i = 0; i < 50; i++)
    {
        if (searchValue == numbers[i])
        {
            found = true;

            cout << searchValue
                 << " is found at index " << i << endl;

            break;
        }
    }

    // Display message if the value was not found
    if (!found)
    {
        cout << searchValue
             << " is not found in the array" << endl;
    }

    return 0;
}
