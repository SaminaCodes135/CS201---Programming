#include <iostream>
using namespace std;

int main()
{
    int sum = 0;
    int number = 1;
    int upperLimit;

    cout << "Enter the upper limit: ";
    cin >> upperLimit;

    // Add each integer from 1 to the upper limit
    while (number <= upperLimit)
    {
        sum = sum + number;
        number++;
    }

    cout << "Sum of first " << upperLimit << " integers = " << sum;

    return 0;
}
