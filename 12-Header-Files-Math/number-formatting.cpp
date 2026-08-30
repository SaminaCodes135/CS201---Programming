#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    double number;

    cout << "Enter a decimal number: ";
    cin >> number;

    // fixed keeps the number in decimal notation
    // setprecision(2) displays exactly 2 digits after the decimal point
    cout << fixed << setprecision(2);
    cout << "Formatted number = " << number << endl;

    return 0;
}
