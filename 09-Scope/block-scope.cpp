#include <iostream>
using namespace std;

int main()
{
    int number = 10;

    {
        int number = 20;

        // This number belongs only to this block
        cout << "Inside block: " << number << endl;
    }

    // Outside the block, the outer variable is accessible
    cout << "Outside block: " << number << endl;

    return 0;
}
