#include <iostream>
using namespace std;

// References allow the function to modify the original variables
void swapNumbers(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

int main()
{
    int first, second;

    cout << "Enter two numbers: ";
    cin >> first >> second;

    cout << "Before swap: " << first << " " << second << endl;

    swapNumbers(first, second);

    cout << "After swap: " << first << " " << second << endl;

    return 0;
}
