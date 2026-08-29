#include <iostream>
using namespace std;

int main()
{
    int number = 10;
    int *ptr = &number;

    // A pointer stores the memory address of another variable
    cout << "Value of number = " << number << endl;
    cout << "Address of number = " << &number << endl;
    cout << "Value stored in pointer = " << ptr << endl;
    cout << "Value accessed through pointer = " << *ptr << endl;

    return 0;
}
