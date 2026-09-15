#include <iostream>
using namespace std;

int main()
{
    int age;
    char name[100];

    cout << "Enter your age: ";
    cin >> age;

    // Remove the leftover newline before using getline()
    cin.ignore();

    cout << "Enter your full name: ";
    cin.getline(name, 100);

    cout << "\nAge: " << age << endl;
    cout << "Full Name: " << name << endl;

    return 0;
}
