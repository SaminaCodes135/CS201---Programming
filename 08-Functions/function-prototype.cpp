#include <iostream>
using namespace std;

// Function prototype tells the compiler about the function
int add(int, int);

int main()
{
    cout << "Sum = " << add(5, 3);

    return 0;
}

// Function definition
int add(int a, int b)
{
    return a + b;
}
