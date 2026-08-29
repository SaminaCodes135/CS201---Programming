#include <iostream>
using namespace std;

int main()
{
    int number;

    cout << "Enter a number: ";
    cin >> number;

    // Check whether the number is positive, negative, or zero
    if (number > 0)
    {
        cout << "Positive";
    }
    else if (number < 0)
    {
        cout << "Negative";
    }
    else
    {
        cout << "Zero";
    }

    return 0;
}
