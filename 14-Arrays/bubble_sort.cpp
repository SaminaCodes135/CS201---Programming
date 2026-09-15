#include <iostream>
using namespace std;

int main()
{
    int a[5] = {5, 2, 8, 1, 3};

    // Compare adjacent elements and swap them if they are in the wrong order
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4 - i; j++)
        {
            if (a[j] > a[j + 1])
            {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }

    cout << "Sorted array: ";

    for (int i = 0; i < 5; i++)
    {
        cout << a[i] << " ";
    }

    return 0;
}
