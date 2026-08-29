#include <iostream>
using namespace std;

// Call by reference: x refers to the original variable
void changeValue(int &x)
{
    x = 100;
}

int main()
{
    int number = 10;

    cout << "Before function call: number = " << number << endl;

    changeValue(number);

    // Original variable is changed
    cout << "After function call: number = " << number << endl;

    return 0;
}
