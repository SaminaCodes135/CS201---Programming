#include <iostream>
using namespace std;

// Fill the array with values based on their index
void fillArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        arr[i] = i;
    }
}

// Display array elements
void displayArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;
}

int main()
{
    const int size = 10;
    int numbers[size];

    fillArray(numbers, size);

    cout << "Array elements: ";
    displayArray(numbers, size);

    return 0;
}
