#include <iostream>
using namespace std;

int main()
{
    int number;
    int digit;

    cout << "Enter a 4-digit integer: ";
    cin >> number;

    // Integer division removes digits from the right
    digit = number / 1000;
    cout << "Thousands digit = " << digit << '\n';

    number = number % 1000;

    digit = number / 100;
    cout << "Hundreds digit = " << digit << '\n';

    number = number % 100;

    digit = number / 10;
    cout << "Tens digit = " << digit << '\n';

    digit = number % 10;
    cout << "Ones digit = " << digit << '\n';

    return 0;
}
