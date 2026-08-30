#include <iostream>
using namespace std;

// Recursive function returns the nth Fibonacci number
int fibonacci(int n)
{
    // Base cases
    if (n == 0)
    {
        return 0;
    }

    if (n == 1)
    {
        return 1;
    }

    // Recursive case
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main()
{
    int terms;

    cout << "Enter number of terms: ";
    cin >> terms;

    if (terms <= 0)
    {
        cout << "Invalid input.";
    }
    else
    {
        cout << "Fibonacci series: ";

        for (int i = 0; i < terms; i++)
        {
            cout << fibonacci(i) << " ";
        }
    }

    return 0;
}
