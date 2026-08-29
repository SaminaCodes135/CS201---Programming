#include <iostream>
using namespace std;

// Function receives two parameters and returns their sum
int add(int a, int b)
{
    return a + b;
}

int main()
{
    int x, y;

    cout << "Enter two numbers: ";
    cin >> x >> y;

    cout << "Sum = " << add(x, y);

    return 0;
}
