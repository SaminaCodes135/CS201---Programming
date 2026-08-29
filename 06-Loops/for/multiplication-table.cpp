#include <iostream>
using namespace std;

int main()
{
    int number;
    const int maxMultiplier = 12;

    cout << "Enter the number for which you want the table: ";
    cin >> number;

    // for loop repeats from 1 to 12
    for (int counter = 1; counter <= maxMultiplier; counter++)
    {
        cout << number << " x " << counter
             << " = " << number * counter << endl;
    }

    return 0;
}
