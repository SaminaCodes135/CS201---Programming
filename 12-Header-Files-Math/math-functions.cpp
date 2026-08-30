#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    double number;

    cout << "Enter a non-negative number: ";
    cin >> number;

    // sqrt() requires a non-negative value for a real result
    if (number < 0)
    {
        cout << "Invalid input. Square root requires a non-negative number.";
    }
    else
    {
        // <cmath> provides mathematical functions such as sqrt() and pow()
        cout << "Square root = " << sqrt(number) << endl;
        cout << "Square = " << pow(number, 2) << endl;
    }

    return 0;
}
