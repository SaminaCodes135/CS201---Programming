#include <iostream>
using namespace std;

// Recursive function calculates x raised to a non-negative power
double power(double x, int exponent)
{
    // Base case: any number raised to 0 is 1
    if (exponent == 0)
    {
        return 1;
    }

    // Recursive case
    return x * power(x, exponent - 1);
}

int main()
{
    double number;
    int exponent;

    cout << "Enter the number: ";
    cin >> number;

    cout << "Enter a non-negative exponent: ";
    cin >> exponent;

    if (exponent < 0)
    {
        cout << "Invalid exponent.";
    }
    else
    {
        cout << "Result = " << power(number, exponent);
    }

    return 0;
}
