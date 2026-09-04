#include <iostream>
using namespace std;

int main()
{
    int a[3] = {11, 5, 7};
    int b[3];

    // Copy each element from array a to array b
    for (int i = 0; i < 3; i++)
    {
        b[i] = a[i];
    }

    // Display the copied elements
    cout << "Elements of array b: ";

    for (int i = 0; i < 3; i++)
    {
        cout << b[i] << " ";
    }

    cout << endl;

    return 0;
}
