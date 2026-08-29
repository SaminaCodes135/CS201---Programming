#include <iostream>
using namespace std;

void showNumber()
{
    int number = 20;

    // Local variable: accessible only inside this function
    cout << "Inside function: " << number << endl;
}

int main()
{
    int number = 10;

    cout << "Inside main: " << number << endl;

    showNumber();

    return 0;
}
