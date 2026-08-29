#include <iostream>
using namespace std;

int main()
{
    int age;

    cout << "Enter your age: ";
    cin >> age;

    if (age < 0)
    {
        cout << "Invalid age";
    }
    else
    {
        cout << "Your age is: " << age;
    }

    return 0;
}
