#include <iostream>
using namespace std;

// Recursive function calls itself with a smaller value
long long factorial(int n)
{
    // Base case stops the recursion
    if (n <= 1)
    {
        return 1;
    }

    // Recursive case
    return n * factorial(n - 1);
}

int main()
{
    int number;

    cout << "Enter a non-negative integer: ";
    cin >> number;

    if (number < 0)
    {
        cout << "Invalid input.";
    }
    else
    {
        cout << "Factorial = " << factorial(number);
    }

    return 0;
}
