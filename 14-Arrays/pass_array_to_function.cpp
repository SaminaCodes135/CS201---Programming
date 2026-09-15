#include <iostream>
using namespace std;

void printArray(int arr[], int size)
{
    // Access and display array elements through the function
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
}

int main()
{
    int numbers[5] = {10, 20, 30, 40, 50};

    cout << "Array elements: ";
    printArray(numbers, 5);

    return 0;
}
