#include <iostream>
using namespace std;

// Places the pivot in its correct position
int partition(int a[], int low, int high)
{
    int pivot = a[high];
    int i = low - 1;

    // Move elements smaller than the pivot to the left
    for (int j = low; j < high; j++)
    {
        if (a[j] < pivot)
        {
            i++;

            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }

    // Place the pivot between the two partitions
    int temp = a[i + 1];
    a[i + 1] = a[high];
    a[high] = temp;

    return i + 1;
}

// Recursively sorts the two partitions
void quickSort(int a[], int low, int high)
{
    if (low < high)
    {
        int pivotIndex = partition(a, low, high);

        quickSort(a, low, pivotIndex - 1);
        quickSort(a, pivotIndex + 1, high);
    }
}

int main()
{
    int a[6] = {8, 3, 1, 7, 0, 10};
    int size = 6;

    quickSort(a, 0, size - 1);

    cout << "Sorted array: ";

    for (int i = 0; i < size; i++)
    {
        cout << a[i] << " ";
    }

    return 0;
}
