#include <iostream>
using namespace std;

int main()
{
    int sum = 0;
    int number = 1;
    int upperLimit;

    cout << "Enter the upper limit: ";
    cin >> upperLimit;

    while (number <= upperLimit)
    {
        // A number is even when its remainder after division by 2 is 0
        if (number % 2 == 0)
        {
            sum += number;
        }

        number++;
    }

    cout << "Sum of even numbers from 1 to "
         << upperLimit << " = " << sum;

    return 0;
}
