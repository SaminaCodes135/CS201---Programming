#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    double number;

    cout << "Enter a number: ";
    cin >> number;

    // <cmath> provides mathematical functions such as sqrt() and pow()
    cout << "Square root = " << sqrt(number) << endl;
    cout << "Square = " << pow(number, 2) << endl;

    return 0;
}
