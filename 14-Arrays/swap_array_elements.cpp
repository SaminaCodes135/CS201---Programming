#include <iostream>
using namespace std;

int main()
{
    int numbers[5] = {10, 20, 30, 40, 50};

    cout << "Original array: ";

    for (int i = 0; i < 5; i++)
    {
        cout << numbers[i] << " ";
    }

    // Swap the first and last elements
    int temp = numbers[0];
    numbers[0] = numbers[4];
    numbers[4] = temp;

    cout << "\nAfter swapping first and last elements: ";

    for (int i = 0; i < 5; i++)
    {
        cout << numbers[i] << " ";
    }

    return 0;
}
