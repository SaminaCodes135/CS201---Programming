#include <iostream>
using namespace std;

int main()
{
    int numbers[5];

    cout << "Enter 5 numbers: ";

    // Store 5 values in the array
    for (int i = 0; i < 5; i++)
    {
        cin >> numbers[i];
    }

    cout << "Numbers entered: ";

    // Access each array element using its index
    for (int i = 0; i < 5; i++)
    {
        cout << numbers[i] << " ";
    }

    return 0;
}
