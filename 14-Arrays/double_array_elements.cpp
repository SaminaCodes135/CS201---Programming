#include <iostream>
using namespace std;

void doubleElements(int a[], int size)
{
    // Multiply each array element by 2
    for (int i = 0; i < size; i++)
    {
        a[i] = a[i] * 2;
    }
}

void displayArray(int a[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << a[i] << " ";
    }

    cout << endl;
}

int main()
{
    int a[5] = {2, 4, 6, 8, 10};

    cout << "Original array: ";
    displayArray(a, 5);

    doubleElements(a, 5);

    cout << "After doubling: ";
    displayArray(a, 5);

    return 0;
}
