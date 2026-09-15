#include <iostream>
using namespace std;

int sumArray(int a[], int size)
{
    int sum = 0;

    // Add all array elements
    for (int i = 0; i < size; i++)
    {
        sum += a[i];
    }

    return sum;
}

int maxArray(int a[], int size)
{
    int maximum = a[0];

    // Find the largest element in the array
    for (int i = 1; i < size; i++)
    {
        if (a[i] > maximum)
            maximum = a[i];
    }

    return maximum;
}

int main()
{
    int numbers[5] = {12, 7, 25, 9, 18};

    cout << "Array: ";

    for (int i = 0; i < 5; i++)
    {
        cout << numbers[i] << " ";
    }

    cout << "\nSum = " << sumArray(numbers, 5);
    cout << "\nMaximum = " << maxArray(numbers, 5);

    return 0;
}
