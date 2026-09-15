#include <iostream>
using namespace std;

// Input elements into the array
void inputArray(int arr[], int size)
{
    cout << "Enter " << size << " elements:" << endl;

    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
}

// Display array elements
void displayArray(int arr[], int size)
{
    cout << "Array: ";

    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;
}

// Calculate the sum of array elements
int sumArray(int arr[], int size)
{
    int sum = 0;

    for (int i = 0; i < size; i++)
    {
        sum += arr[i];
    }

    return sum;
}

// Find the maximum element
int maxArray(int arr[], int size)
{
    int maximum = arr[0];

    for (int i = 1; i < size; i++)
    {
        if (arr[i] > maximum)
        {
            maximum = arr[i];
        }
    }

    return maximum;
}

int main()
{
    const int size = 5;
    int numbers[size];

    inputArray(numbers, size);
    displayArray(numbers, size);

    cout << "Sum = " << sumArray(numbers, size) << endl;
    cout << "Maximum = " << maxArray(numbers, size) << endl;

    return 0;
}
