#include <iostream>
using namespace std;

int main()
{
    // break immediately terminates the loop
    for (int i = 1; i <= 10; i++)
    {
        if (i == 6)
        {
            break;
        }

        cout << i << endl;
    }

    return 0;
}
