#include <iostream>
using namespace std;

int main()
{
    const int arraySize = 100;
    int A[arraySize];

    // Store values from 0 to 99 in the array
    for (int i = 0; i < arraySize; i++)
    {
        A[i] = i;
    }

    // Access and display the element at index 56
    cout << "A[56] = " << A[56] << endl;

    return 0;
}
