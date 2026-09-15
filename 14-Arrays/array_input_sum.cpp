#include <iostream>
using namespace std;

void inputArray(int a[], int size)
{
    // Input elements into the array
    for (int i = 0; i < size; i++)
    {
        cin >> a[i];
    }
}

void displayArray(int a[], int size)
{
    // Display all array elements
    for (int i = 0; i < size; i++)
    {
        cout << a[i] << " ";
    }

    cout << endl;
}

int sumArray(int a[], int size)
{
    int sum = 0;

    // Calculate the total of all elements
    for (int i = 0; i < size; i++)
    {
        sum += a[i];
    }

    return sum;
}

int main()
{
    int numbers[5];

    cout << "Enter 5 numbers: ";
    inputArray(numbers, 5);

    cout << "Array: ";
    displayArray(numbers, 5);

    cout << "Sum = " << sumArray(numbers, 5) << endl;

    return 0;
}
