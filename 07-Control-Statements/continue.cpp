#include <iostream>
using namespace std;

int main()
{
    // continue skips the current iteration
    for (int i = 1; i <= 10; i++)
    {
        if (i % 2 == 0)
        {
            continue;
        }

        cout << i << endl;
    }

    return 0;
}
