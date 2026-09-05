#include <iostream>
using namespace std;

int main()
{
    const int arraySize = 10;
    int numbers[arraySize];
    int sumOfSquares = 0;

    // Input 10 integers into the array
    cout << "Enter " << arraySize << " integers:" << endl;

    for (int i = 0; i < arraySize; i++)
    {
        cin >> numbers[i];
    }

    // Calculate the sum of the squares of all elements
    for (int i = 0; i < arraySize; i++)
    {
        sumOfSquares += numbers[i] * numbers[i];
    }

    cout << "Sum of squares = " << sumOfSquares << endl;

    return 0;
}
