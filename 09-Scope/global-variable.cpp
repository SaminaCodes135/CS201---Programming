#include <iostream>
using namespace std;

int number = 10;  // Global variable: accessible throughout the file

void showNumber()
{
    cout << "Inside function: " << number << endl;
}

int main()
{
    cout << "Inside main: " << number << endl;

    number = 20;

    showNumber();

    return 0;
}
