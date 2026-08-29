#include <iostream>
using namespace std;

// Function returns the square of a number
int square(int number)
{
    return number * number;
}

int main()
{
    int number;

    cout << "Enter a number: ";
    cin >> number;

    cout << "Square = " << square(number);

    return 0;
}
