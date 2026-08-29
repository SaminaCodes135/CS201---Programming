#include <iostream>
using namespace std;

int main()
{
    int a, b, c, x, y;

    cout << "Enter a, b, c and x: ";
    cin >> a >> b >> c >> x;

    // Calculate y using the quadratic expression
    y = a * x * x + b * x + c;

    cout << "y = " << y << '\n';

    return 0;
}
