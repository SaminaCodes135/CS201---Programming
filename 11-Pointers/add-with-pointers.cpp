#include <iostream>
using namespace std;

// Pointers allow the function to access values through their addresses
int add(int *a, int *b)
{
    return *a + *b;
}

int main()
{
    int first, second;

    cout << "Enter two numbers: ";
    cin >> first >> second;

    cout << "Sum = " << add(&first, &second);

    return 0;
}
