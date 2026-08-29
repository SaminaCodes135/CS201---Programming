#include <iostream>
using namespace std;

int main()
{
    int a, b, c;

    cout << "Enter three numbers: ";
    cin >> a >> b >> c;

    // Compare the numbers using relational operators
    if (a > b && a > c)
    {
        cout << "Largest number = " << a;
    }
    else if (b > a && b > c)
    {
        cout << "Largest number = " << b;
    }
    else
    {
        cout << "Largest number = " << c;
    }

    return 0;
}
