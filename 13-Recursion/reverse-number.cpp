#include <iostream>
using namespace std;

// Recursively prints the digits of a number in reverse order
void reverseNumber(int number)
{
    if (number == 0)
    {
        return;  // Base case
    }

    cout << number % 10;
    reverseNumber(number / 10);
}

int main()
{
    int number;

    cout << "Enter a positive integer: ";
    cin >> number;

    if (number <= 0)
    {
        cout << "Invalid input.";
    }
    else
    {
        cout << "Reversed number = ";
        reverseNumber(number);
    }

    return 0;
}
