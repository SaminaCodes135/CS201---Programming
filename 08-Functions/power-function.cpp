#include <iostream>
using namespace std;

// Calculates x raised to an integer power
double raiseToPower(double x, int power)
{
    double result = 1.0;

    if (power > 0)
    {
        for (int i = 1; i <= power; i++)
        {
            result *= x;
        }
    }
    else if (power < 0)
    {
        for (int i = 1; i <= -power; i++)
        {
            result *= x;
        }

        result = 1.0 / result;
    }

    // power == 0 returns 1
    return result;
}

int main()
{
    double x;
    int power;

    cout << "Enter the number: ";
    cin >> x;

    cout << "Enter the power: ";
    cin >> power;

    cout << "Result = " << raiseToPower(x, power);

    return 0;
}
