#include <iostream>
using namespace std;

// Call by value: the function receives a copy of the argument
void changeValue(int x)
{
    x = 100;

    cout << "Inside function: x = " << x << endl;
}

int main()
{
    int number = 10;

    cout << "Before function call: number = " << number << endl;

    changeValue(number);

    // Original variable remains unchanged
    cout << "After function call: number = " << number << endl;

    return 0;
}
