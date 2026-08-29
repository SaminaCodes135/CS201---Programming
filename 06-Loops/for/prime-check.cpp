#include <iostream>
using namespace std;

int main()
{
    int number;
    bool isPrime = true;

    cout << "Enter a positive integer: ";
    cin >> number;

    if (number < 2)
    {
        isPrime = false;
    }
    else
    {
        // Check whether number has any divisor other than 1 and itself
        for (int counter = 2; counter < number; counter++)
        {
            if (number % counter == 0)
            {
                isPrime = false;
                break;
            }
        }
    }

    if (isPrime)
    {
        cout << "Number is Prime";
    }
    else
    {
        cout << "Number is Not Prime";
    }

    return 0;
}
