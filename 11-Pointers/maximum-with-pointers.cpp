#include <iostream>
using namespace std;

// Compares two values accessed through pointers
int maximum(int *a, int *b)
{
    if (*a > *b)
    {
        return *a;
    }

    return *b;
}

int main()
{
    int first, second;

    cout << "Enter two numbers: ";
    cin >> first >> second;

    cout << "Maximum = " << maximum(&first, &second);

    return 0;
}
