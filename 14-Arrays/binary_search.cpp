#include <iostream>
using namespace std;

int binarySearch(int a[], int size, int target)
{
    int low = 0;
    int high = size - 1;

    // Binary search works on a sorted array by repeatedly dividing the search range
    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (a[mid] == target)
            return mid;
        else if (a[mid] < target)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return -1;
}

int main()
{
    int a[7] = {2, 4, 6, 8, 10, 12, 14};
    int target;

    cout << "Enter value to search: ";
    cin >> target;

    int index = binarySearch(a, 7, target);

    if (index != -1)
        cout << "Value found at index " << index << "." << endl;
    else
        cout << "Value not found." << endl;

    return 0;
}
