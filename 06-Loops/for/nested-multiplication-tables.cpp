#include <iostream>
using namespace std;

int main()
{
    // Outer loop controls the table number
    for (int number = 1; number <= 11; number++)
    {
        // Inner loop controls the multiplier
        for (int counter = 1; counter <= 10; counter++)
        {
            cout << number << " x " << counter
                 << " = " << number * counter << endl;
        }

        cout << endl;
    }

    return 0;
}
