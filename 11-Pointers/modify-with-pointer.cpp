#include <iostream>
using namespace std;

int main()
{
    int number = 10;
    int *ptr = &number;

    // Dereferencing allows us to modify the original variable
    *ptr = 50;

    cout << "Number = " << number << endl;
    cout << "Value through pointer = " << *ptr << endl;

    return 0;
}
