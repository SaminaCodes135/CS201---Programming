#include <iostream>
using namespace std;

int main()
{
    int numbers[5] = {5, 2, 8, 1, 3};

    // Find the smallest element and place it at the current position
    for (int i = 0; i < 4; i++)
    {
        int minIndex = i;

        for (int j = i + 1; j < 5; j++)
        {
            if (numbers[j] < numbers[minIndex])
                minIndex = j;
        }

        int temp = numbers[i];
        numbers[i] = numbers[minIndex];
        numbers[minIndex] = temp;
    }

    cout << "Sorted array: ";

    for (int i = 0; i < 5; i++)
    {
        cout << numbers[i] << " ";
    }

    return 0;
}
